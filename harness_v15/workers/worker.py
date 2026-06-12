#!/usr/bin/env python3
"""Worker: process a single task via multi-turn tool-calling.

Steps:
  1. Read task JSON
  2. Pre-gather context (r2 disasm, xrefs, behavioral trace, composed file)
  3. Initialize conversation: system prompt + user prompt with context
  4. Loop: send to model, parse response
     - If model returns tool_calls: execute each, append results, continue
     - If model returns final C body: extract, save, verify, done
     - If max iterations reached: use last assistant message
  5. Run verifier
  6. Write result.json
"""
import argparse
import json
import re
import subprocess
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(REPO / "harness_v15"))

from load_balancer import LoadBalancer, strip_think_tags  # noqa: E402
from verifier.verify import verify, build_symbol_set, r2_disasm  # noqa: E402
from workers.tools import TOOL_DEFS, execute_tool  # noqa: E402
from workers.telemetry import Telemetry, count_message_chars, extract_thinking_chars  # noqa: E402
from pathlib import Path as _Path  # noqa: E402
_composed_dir = REPO / "extraction_out/reconstruction/mega7/composed"
def find_composed_path(image: str) -> _Path:
    base = image.replace(".bin", "_bin")
    return _composed_dir / f"{base}.reconstructed.c"

PROMPT_PATH = REPO / "harness_v15" / "prompts" / "decompile_system.md"


PROMPT_TASK_TEMPLATE = """
# Task

- **Function name**: {function}
- **Address (file offset)**: {address_hex}
- **Runtime address**: {runtime_address_hex}
- **Image**: {image}
- **Tier**: {tier}

# Metadata

- **Behavior role**: {behavior_role}
- **Phenotype**: {phenotype}
- **Motif family**: {motif_family}
- **Priority class**: {priority_class}

# Disassembly (your source of truth)

```
{disasm}
```

# Cross-references TO this function

Other functions that call this one (from r2 axt):

```
{xrefs_to}
```

# Cross-references FROM this function (BL targets)

Functions called by this one, with their addresses (file offset = runtime - 0x120000):

```
{callees_info}
```

# Behavioral trace (if any)

Recorded MMIO accesses when this function executed under Unicorn:

```
{behavioral_trace}
```

# All available symbols in this image (composed file)

These function names are defined somewhere in `{image}`'s composed C file.
You may call any of them **only if the disasm shows a `bl`/`blx` to a function with that name**.

```
{symbols}
```

# Tools available

You have:
- `python_exec(code)` — run Python
- `r2_cmd(cmd)` — run r2 on the binary
- `read_bytes(offset, length)` — read binary bytes
- `get_composed_fn(name)` — get composed body of a function
- `find_symbols(regex)` — find symbols matching a pattern

Use them to inspect the disasm, validate your C, look up callees, etc.

# Output

When done, output ONLY the C function definition. No markdown, no commentary, no preamble.

Begin. Read the disassembly. Reason. Then output the C.
"""


def build_initial_user_prompt(task: dict, disasm: str, symbol_set: set[str],
                              xrefs_to: str, callees_info: str,
                              behavioral_trace: str) -> str:
    symbols = sorted(symbol_set)
    return PROMPT_TASK_TEMPLATE.format(
        function=task["function"],
        address_hex=task["address_hex"],
        runtime_address_hex=task["runtime_address_hex"],
        image=task["image"],
        tier=task["tier"],
        behavior_role=task.get("behavior_role", ""),
        phenotype=task.get("phenotype", ""),
        motif_family=task.get("motif_family", ""),
        priority_class=task.get("priority_class", ""),
        disasm=disasm,
        xrefs_to=xrefs_to or "[no xrefs found]",
        callees_info=callees_info or "[no BL targets found in this function]",
        behavioral_trace=behavioral_trace or "[no behavioral trace available]",
        symbols="\n".join(symbols) if symbols else "[no symbols]",
    )


def gather_context(task: dict) -> dict:
    """Pre-gather dynamic context for the task. Returns dict with disasm, xrefs, callees, etc."""
    binary = REPO / task["binary"]
    runtime_addr = int(task["runtime_address_hex"], 16)
    fn_name = task["function"]

    # 1. Disasm of target
    disasm = r2_disasm(binary, runtime_addr)

    # 2. xrefs TO this function (other functions calling it)
    xrefs_to = ""
    try:
        out = subprocess.run(
            ["r2", "-q", "-A", "-a", "arm", "-b", "16", "-m", "0x120000",
             "-c", f"axt @ 0x{runtime_addr:x}", str(binary)],
            capture_output=True, text=True, timeout=30,
        )
        xrefs_to = re.sub(r"\x1b\[[0-9;]*m", "", (out.stdout or "") + (out.stderr or ""))
    except Exception:
        pass

    # 3. Find BL targets in target's disasm and gather their disasm
    bl_targets = set()
    for line in disasm.splitlines():
        m = re.search(r"\b(?:bl|blx)\s+(?:0x([0-9a-fA-F]+)|(\w+))", line, re.IGNORECASE)
        if m:
            if m.group(1):
                bl_targets.add(int(m.group(1), 16))

    callees_info_lines = []
    for tgt in sorted(bl_targets):
        # tgt is runtime addr, subtract base to get file offset
        file_off = tgt - 0x120000
        callees_info_lines.append(f"  - 0x{tgt:x} (file offset 0x{file_off:x}):")
        sub_disasm = r2_disasm(binary, tgt)
        if sub_disasm:
            for line in sub_disasm.splitlines()[:15]:
                callees_info_lines.append(f"      {line}")
    callees_info = "\n".join(callees_info_lines)

    # 4. Behavioral trace (try common locations)
    behavioral_trace = ""
    img_underscore = task["image"].replace(".bin", "_bin")
    for path in [
        REPO / f"extraction_out/reconstruction/mega7/behavioral/traces/{task['function']}.txt",
        REPO / f"extraction_out/reconstruction/mega7/behavioral/{img_underscore}/{task['function']}.trace",
    ]:
        if path.exists():
            behavioral_trace = path.read_text(errors="replace")[:8000]
            break

    # 5. Symbol set
    symbol_set = build_symbol_set(task["image"])

    return {
        "disasm": disasm,
        "xrefs_to": xrefs_to,
        "callees_info": callees_info,
        "behavioral_trace": behavioral_trace,
        "symbol_set": symbol_set,
        "binary": binary,
    }


def extract_c_function(text: str, fn_name: str) -> str | None:
    """Extract a C function definition from the model's response.

    Accepts any return type: void, uint32_t, int, etc.
    """
    text = re.sub(r"```(?:c|cpp)?\n?", "", text)
    text = text.replace("```", "")
    # Match any return type: void, uint8_t, int, etc., or `static` qualifier
    pat = re.compile(
        rf"(?:^|\n)\s*(?:static\s+)?(?:void|uint(?:8|16|32|64)_t|int|unsigned\s+int|static\s+inline)\s+{re.escape(fn_name)}\s*\([^)]*\)\s*\{{",
        re.MULTILINE,
    )
    m = pat.search(text)
    if not m:
        return None
    start = m.end() - 1
    depth = 0
    pos = start
    while pos < len(text):
        if text[pos] == "{":
            depth += 1
        elif text[pos] == "}":
            depth -= 1
            if depth == 0:
                return text[m.start():pos + 1].strip()
        pos += 1
    return None


def call_model_with_tools(ks, messages, tools, timeout: float = 86400.0):
    """Call the model API with messages + tool definitions. Returns (ok, response_obj, error)."""
    import urllib.request
    import urllib.error
    base = ks.provider["base_url"].rstrip("/")
    url = f"{base}/chat/completions"
    payload = {
        "model": ks.provider["model"],
        "max_tokens": 131072,
        "temperature": 0.0,
        "messages": messages,
        "tools": tools,
    }
    data = json.dumps(payload).encode("utf-8")
    req = urllib.request.Request(
        url, data=data,
        headers={"Content-Type": "application/json", "Authorization": f"Bearer {ks.provider['api_key']}"},
        method="POST",
    )
    try:
        with urllib.request.urlopen(req, timeout=timeout) as resp:
            body = resp.read().decode("utf-8")
    except urllib.error.HTTPError as e:
        return False, None, f"http_error: {e.code} {e.reason}"
    except Exception as e:
        return False, None, f"network_error: {type(e).__name__}: {e}"
    try:
        obj = json.loads(body)
    except json.JSONDecodeError:
        return False, None, f"bad_json: {body[:200]}"
    if "error" in obj:
        return False, None, f"api_error: {obj['error']}"
    return True, obj, ""


def run(task_path: Path, out_dir: Path, config_path: Path,
        max_iterations: int = 64, max_retries: int = 2) -> int:
    task = json.loads(task_path.read_text())
    fn_name = task["function"]
    out_dir.mkdir(parents=True, exist_ok=True)

    print(f"[worker] {task_path.stem}: gathering context", flush=True)
    ctx = gather_context(task)
    (out_dir / "disasm.txt").write_text(ctx["disasm"] or "")
    (out_dir / "xrefs_to.txt").write_text(ctx["xrefs_to"] or "")
    (out_dir / "callees_info.txt").write_text(ctx["callees_info"] or "")
    (out_dir / "symbols.txt").write_text("\n".join(sorted(ctx["symbol_set"])))
    if ctx["behavioral_trace"]:
        (out_dir / "behavioral_trace.txt").write_text(ctx["behavioral_trace"])

    if not ctx["disasm"]:
        result = {"ok": False, "reason": "r2_failed"}
        (out_dir / "result.json").write_text(json.dumps(result, indent=2))
        telemetry = Telemetry(task["task_id"], out_dir)
        telemetry.finish(ok=False, reason="r2_failed", synth_chars=0)
        return 1

    system_prompt = PROMPT_PATH.read_text()
    user_prompt = build_initial_user_prompt(
        task, ctx["disasm"], ctx["symbol_set"],
        ctx["xrefs_to"], ctx["callees_info"], ctx["behavioral_trace"],
    )

    # Save initial prompt for debugging
    (out_dir / "initial_prompt.txt").write_text(system_prompt + "\n\n" + user_prompt)

    composed_path = find_composed_path(task["image"])
    binary = ctx["binary"]

    messages = [
        {"role": "system", "content": system_prompt},
        {"role": "user", "content": user_prompt},
    ]

    lb = LoadBalancer(config_path)
    telemetry = Telemetry(task["task_id"], out_dir)
    synth_body = None
    last_assistant_text = None
    tool_iterations = 0
    api_errors = []

    for it in range(max_iterations):
        ks = lb.acquire()
        if not ks:
            time.sleep(2)
            continue
        t_iter_start = time.time()
        # No timeout. Let the server take as long as it needs.
        ok, response, err = call_model_with_tools(ks, messages, TOOL_DEFS)
        if not ok:
            api_errors.append(err)
            print(f"[worker] {task_path.stem}: API error iter {it}: {err}", flush=True)
            if "rate_limited" in err:
                lb.report_rate_limit(ks)
            else:
                lb.report_failure(ks)
            continue
        lb.report_success(ks)

        if not isinstance(response, dict):
            print(f"[worker] {task_path.stem}: response not a dict", flush=True)
            continue
        choices = response.get("choices") or []
        if not choices:
            print(f"[worker] {task_path.stem}: no choices", flush=True)
            continue
        choice = choices[0]
        if not isinstance(choice, dict):
            print(f"[worker] {task_path.stem}: choice not a dict", flush=True)
            continue
        msg = choice.get("message")
        if not isinstance(msg, dict):
            msg = {}

        # Track usage/tokens from response
        usage = response.get("usage") or {}
        prompt_tokens_details = usage.get("prompt_tokens_details") or {}
        cached_tokens = prompt_tokens_details.get("cached_tokens", 0)
        finish_reason = choice.get("finish_reason", "")

        # Save the full assistant message (with raw thinking)
        tool_calls = msg.get("tool_calls") or []
        raw_text = msg.get("content") or ""
        text_content = strip_think_tags(raw_text) if raw_text else ""
        thinking_chars = extract_thinking_chars(raw_text) if raw_text else 0

        telemetry.record_iteration(
            iter_idx=it,
            prompt_tokens=usage.get("prompt_tokens", 0),
            completion_tokens=usage.get("completion_tokens", 0),
            total_tokens=usage.get("total_tokens", 0),
            tool_calls_count=len(tool_calls),
            key_name=ks.provider["name"],
            latency_seconds=time.time() - t_iter_start,
            context_chars=count_message_chars(messages),
            finished=finish_reason or ("tool_calls" if tool_calls else "final"),
            thinking_chars=thinking_chars,
            content_chars=len(text_content),
            cached_tokens=cached_tokens,
        )

        if text_content:
            last_assistant_text = text_content

        # Append assistant message to conversation (preserve tool_calls for context)
        if tool_calls:
            messages.append({
                "role": "assistant",
                "content": text_content if text_content else None,
                "tool_calls": [dict(tc) for tc in tool_calls],  # type: ignore
            })
        elif text_content:
            messages.append({"role": "assistant", "content": text_content})

        # If model wants to use tools
        if tool_calls:
            tool_iterations += 1
            print(f"[worker] {task_path.stem}: iter {it}, {len(tool_calls)} tool call(s)", flush=True)
            for tc in tool_calls:
                fn_name_called = tc.get("function", {}).get("name", "")
                fn_args = tc.get("function", {}).get("arguments", "")
                tc_id = tc.get("id", "")
                print(f"[worker]   tool: {fn_name_called}({fn_args[:80]})", flush=True)
                t_tool_start = time.time()
                result_str = execute_tool(fn_name_called, fn_args, binary=binary, composed_path=composed_path)
                tool_latency = time.time() - t_tool_start
                print(f"[worker]   -> {result_str[:100]}", flush=True)
                try:
                    parsed_args = json.loads(fn_args) if fn_args else {}
                except json.JSONDecodeError:
                    parsed_args = {}
                telemetry.record_tool(
                    name=fn_name_called,
                    args_chars=len(fn_args),
                    result_chars=len(result_str),
                    latency=tool_latency,
                )
                messages.append({
                    "role": "tool",
                    "tool_call_id": tc_id,
                    "content": result_str,
                })
            # NO force-finalize. Let the model decide when to produce the final answer.
            continue  # loop back to model

        # No tool calls — model returned final answer (or some text)
        # Try to extract C function from text_content
        if text_content:
            synth_body = extract_c_function(text_content, fn_name)
            if synth_body:
                (out_dir / "synth.c").write_text(synth_body)
                print(f"[worker] {task_path.stem}: extracted C ({len(synth_body)} chars) on iter {it}", flush=True)
                break
            else:
                # Save raw text for debugging
                (out_dir / "final_response.txt").write_text(text_content)
                print(f"[worker] {task_path.stem}: no C function in final text, iter {it}", flush=True)
                # If we're at max iterations, fall through
                if it == max_iterations - 1:
                    break
                # Otherwise, ask model to try again
                messages.append({
                    "role": "user",
                    "content": "Please output the C function definition for this task. Just the function, no commentary.",
                })
        else:
            # Empty response, weird
            print(f"[worker] {task_path.stem}: empty response iter {it}", flush=True)
            if it == max_iterations - 1:
                break

    # Save the full conversation log (raw, including thinking)
    (out_dir / "conversation_raw.json").write_text(json.dumps(messages, indent=2))

    # Save stripped conversation (no thinking, easier to read)
    stripped = []
    for m in messages:
        if m.get("content") and isinstance(m["content"], str):
            sm = dict(m)
            sm["content"] = strip_think_tags(sm["content"])
            stripped.append(sm)
        else:
            stripped.append(m)
    (out_dir / "conversation.json").write_text(json.dumps(stripped, indent=2))

    if not synth_body:
        total_cost = sum(r.cost_usd for r in telemetry.iterations)
        telemetry.finish(False, "no_c_function_extracted", 0)
        result = {
            "ok": False,
            "reason": f"no_c_function_extracted after {max_iterations} iters (api_errors={len(api_errors)}, tool_iters={tool_iterations})",
            "last_text": (last_assistant_text or "")[:500],
        }

    if not synth_body:
        result = {
            "ok": False,
            "reason": f"no_c_function_extracted after {max_iterations} iters (api_errors={len(api_errors)}, tool_iters={tool_iterations})",
            "last_text": (last_assistant_text or "")[:500],
        }
        (out_dir / "result.json").write_text(json.dumps(result, indent=2))
        telemetry.finish(ok=False, reason="no_c_function_extracted", synth_chars=0)
        return 1

    # Verify
    verify_result = verify(task, synth_body)
    verify_result["task_id"] = task["task_id"]
    verify_result["tool_iterations"] = tool_iterations
    (out_dir / "verify.json").write_text(json.dumps(verify_result, indent=2))

    # Compute totals for finishing
    total_cost = sum(r.cost_usd for r in telemetry.iterations)
    total_tokens = sum(r.total_tokens for r in telemetry.iterations)

    # Tell telemetry we're done
    telemetry.finish(
        ok=verify_result["ok"],
        reason=verify_result.get("reason", ""),
        synth_chars=len(synth_body) if synth_body else 0,
    )

    final = {
        "task_id": task["task_id"],
        "function": fn_name,
        "image": task["image"],
        "synth_path": str(out_dir / "synth.c"),
        "tool_iterations": tool_iterations,
        "total_tokens": total_tokens,
        "cost_usd": round(total_cost, 4),
        "verify": verify_result,
    }
    (out_dir / "result.json").write_text(json.dumps(final, indent=2))
    print(json.dumps({
        "task_id": task["task_id"],
        "ok": verify_result["ok"],
        "reason": verify_result.get("reason", ""),
        "tool_iters": tool_iterations,
        "total_tokens": total_tokens,
        "cost_usd": round(total_cost, 4),
    }), flush=True)
    return 0 if verify_result["ok"] else 1


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--task", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--config", required=True)
    ap.add_argument("--max-iterations", type=int, default=64)
    ap.add_argument("--max-retries", type=int, default=2)
    args = ap.parse_args()
    return run(Path(args.task), Path(args.out), Path(args.config),
               args.max_iterations, args.max_retries)


if __name__ == "__main__":
    raise SystemExit(main())
