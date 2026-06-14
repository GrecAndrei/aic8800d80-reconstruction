#!/usr/bin/env python3
"""v17 truth-lane deep pass.

For the 25 truth-lane functions (the most important firmware functions),
do a deep tool-use LLM investigation:
1. Get disasm
2. Get behavioral trace
3. Get all callers and callees
4. Get neighboring functions
5. Have LLM write a detailed report:
   - Real function name
   - Parameter types and purpose
   - Subsystem
   - 3-5 line description of behavior
   - 1-paragraph explanation of how it fits in the broader system
   - Estimated complexity
   - Hardware interfaces (MMIO addresses used)

Output: harness_v17/truth_lane/{fn}.json
"""
import json, sys, time
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor, as_completed

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "harness_v17"))
import tools as v17tools
from oracle import call_api, call_tool, TOOL_SCHEMA, validate_no_invented_addresses

OUT_DIR = REPO / "harness_v17/truth_lane"
OUT_DIR.mkdir(parents=True, exist_ok=True)

# Truth lane targets from v15
TRUTH_LANE = [
    "clock_calc", "feature_guard_sdio", "rf_hw_timer_init", "rf_timer_toggle_update",
    "crypto_hw_enable", "crypto_key_load", "crypto_hw_disable",
    "log_system_init_mode2", "rf_reg_write_wait", "rf_state_check",
    "rf_mem_write", "rf_bus_write2", "rf_bus_mark", "rf_level_apply",
    "rf_cmd_dispatch", "rf_mem_read", "rf_bus_setup", "rf_bus_reset",
    "rf_bus_reset2", "rf_bus_write", "rf_stream_start", "rf_stream_start2",
    "rf_msg_handler", "rf_msg_process_body", "rf_status_poll",
]


def deep_investigate(fn, images):
    """Deep tool-use investigation of a truth-lane function across all images."""
    # Collect all available info across images
    contexts = []
    for img in images:
        # Find the file with this function
        for f in (REPO / "harness_v17/names").glob(f"{fn}__{img}.json"):
            try:
                d = json.load(open(f))
                if d.get('status') == 'ok':
                    contexts.append((img, d))
            except Exception:
                pass
    if not contexts:
        return None, "no_contexts"
    # Build prompt
    ctx_str = ""
    for img, d in contexts:
        ctx_str += f"\n--- {img} (addr={d.get('addr', '?')}) ---\n"
        ctx_str += f"  current name: {d.get('name', fn)}\n"
        ctx_str += f"  docstring: {d.get('docstring', '(none)')}\n"
        ctx_str += f"  subsystem: {d.get('subsystem', 'unknown')}\n"

    system = """You are reverse-engineering one of the most important functions in the AIC8800D80 WiFi firmware. You have a deep tool set to investigate.

Your output is a detailed reverse-engineering report in JSON:
{
  "name": "definitive_snake_case_name",
  "purpose": "1-paragraph: what this function does, why it matters, what subsystem it belongs to",
  "parameters": [{"type": "type", "name": "param_name", "purpose": "1-line"}],
  "return_value": {"type": "type", "meaning": "1-line"},
  "subsystem": "rf|mac|tx|rx|ke|scan|bt|patch|ipc|mmio|util|unknown",
  "side_effects": ["list of hardware accesses (MMIO addresses)"],
  "key_callees": ["function names this calls that matter"],
  "key_callers": ["functions that call this"],
  "complexity": "low|medium|high",
  "lines_of_c": N,
  "summary": "1-sentence tagline"
}

CRITICAL RULES:
1. You may NOT compute addresses in your head. Use tools.
2. Make at least 5 tool calls: disasm_at the function, read_dword at literal pool entries, behavioral_at, find_callers, find_callees, register_at on any MMIO addresses you see.
3. Use the address-safety validator: every MMIO address you mention MUST come from a tool result.
4. If a parameter is unnamed, propose a name based on its usage.
5. Be specific about hardware: cite register addresses with their page/section."""
    user = f"""Function: {fn}

Found in: {[c[0] for c in contexts]}

Context per image:{ctx_str}

Investigate deeply with tools. Output the JSON report."""

    messages = [
        {"role": "system", "content": system},
        {"role": "user", "content": user},
    ]
    try:
        msg, tool_calls = call_api(messages, TOOL_SCHEMA, max_tokens=3000, max_tool_rounds=10)
    except Exception as e:
        return None, f"err:{e}"
    content = (msg.get('content') or '').strip()
    if not content:
        return None, "no_content"
    is_valid, invented = validate_no_invented_addresses(content, tool_calls, user)
    if not is_valid:
        return None, f"invented:{','.join(invented[:3])}"
    # Parse JSON
    start = content.find('{')
    if start < 0: return None, "no_json"
    depth, end = 0, -1
    for i in range(start, len(content)):
        if content[i] == '{': depth += 1
        elif content[i] == '}':
            depth -= 1
            if depth == 0:
                end = i + 1
                break
    if end < 0: return None, "no_json"
    try:
        return json.loads(content[start:end]), "ok"
    except Exception as e:
        return None, f"json_err:{e}"


def main():
    images = ["fmacfw_8800d80_h_u02_bin", "fmacfw_8800d80_u02_bin",
              "fmacfwbt_8800d80_u02_bin", "lmacfw_rf_8800d80_u02_bin"]
    t0 = time.time()
    done = 0
    ok = 0
    with ThreadPoolExecutor(max_workers=4) as ex:
        futures = {ex.submit(deep_investigate, fn, images): fn for fn in TRUTH_LANE}
        for f in as_completed(futures):
            fn = futures[f]
            result, status = f.result()
            done += 1
            if result:
                out_path = OUT_DIR / f"{fn}.json"
                out_path.write_text(json.dumps({
                    'function': fn,
                    'report': result,
                }, indent=2))
                ok += 1
                print(f"  {fn:30s} ok name={result.get('name', '?')} sub={result.get('subsystem', '?')}", file=sys.stderr)
            else:
                print(f"  {fn:30s} {status}", file=sys.stderr)
    print(f"\nDONE: {done} in {time.time()-t0:.1f}s ok={ok}", file=sys.stderr)


if __name__ == "__main__":
    main()
