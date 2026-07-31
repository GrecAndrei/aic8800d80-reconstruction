#!/usr/bin/env python3
"""Smoke-test every truth-lane function from the v12 final file in Unicorn.

For each truth-lane target that has a real-pseudo body, this:
  1. Extracts the function body from the final C file (with #include <stdbool.h>
     and stripped `int fn(...);` decls that break strict clang).
  2. Discovers every `sub_XXXXXX` call inside the body.
  3. Emits macro stubs `#define sub_XXXXXX(...) 0` so the call compiles and
     returns 0 (a no-op helper).
  4. Runs `unicorn_smoke.py` against the body with --mmio-autopage.
  5. Records a JSONL row with status, instruction count, MMIO read/write count,
     termination reason, and the unique MMIO addresses touched.

Output:
  - JSONL per-target rows at <out>/smoke_outcomes.jsonl
  - Markdown summary at <out>/smoke_summary.md
  - PASS/REVIEW/FAIL per target based on:
      PASS   = returned naturally with > 0 MMIO writes
      REVIEW = capped or faulted (didn't finish)
      FAIL   = compile error or no body
"""
from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
import tempfile
from datetime import datetime, timezone
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
SRC = REPO / "src"
SMOKE = REPO / "tools" / "unicorn_smoke.py"


def extract_body(text: str, fn: str) -> str | None:
    pat = re.compile(r"^void " + re.escape(fn) + r"\(void\) \{", re.MULTILINE)
    m = pat.search(text)
    if not m:
        return None
    start = m.start()
    depth = 0
    i = m.end() - 1
    while i < len(text):
        c = text[i]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return text[start : i + 1]
        i += 1
    return None


def extract_body_by_addr(text: str, addr: str) -> str | None:
    """Extract the body of the function whose composed marker line is
    `// NAME @ 0xADDR` (unified-series src/<img>/main.c layout)."""
    if not addr:
        return None
    try:
        want = int(addr, 16)
    except ValueError:
        return None
    want_variants = {want}
    if want < 0x100000:
        want_variants.add(want + 0x100000)
    for m in re.finditer(r"^// \w+ @ (0x[0-9a-fA-F]+)$", text, re.M):
        if int(m.group(1), 16) not in want_variants:
            continue
        k = m.end()
        while k < len(text) and text[k] != "{":
            k += 1
        if k >= len(text):
            return None
        depth = 0
        i = k
        while i < len(text):
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1
                if depth == 0:
                    return text[m.start() : i + 1]
            i += 1
        return None
    return None


def find_sub_calls(body: str) -> list[str]:
    return sorted(set(re.findall(r"sub_[0-9A-Fa-f]+", body)))


def make_source(body: str) -> str:
    body = re.sub(r"^int [A-Za-z_][A-Za-z0-9_]*\(\.\.\.\);\s*$", "", body, flags=re.MULTILINE)
    return "#include <stdint.h>\n#include <stdbool.h>\n\n" + body + "\n"


def make_src_source(body: str, main_text: str, skip_names: set[str]) -> str:
    """Unified-series source: real headers + the main.c preamble (data segment
    and heal-generated decls) + the single target body."""
    first = re.search(r"^// \w+ @ 0x[0-9a-fA-F]+$", main_text, re.M)
    pre = main_text[: first.start()] if first else ""
    pre = re.sub(r'^\s*#\s*include\s*[<"][^>"]+[>"]\s*$', "", pre, flags=re.M)
    for n in sorted(skip_names):
        pre = re.sub(rf"^.*\b{re.escape(n)}\s*\([^;]*\);$", "", pre, flags=re.M)
    hdrs = [
        "#include <stdint.h>",
        "#include <stdbool.h>",
        "#include <stdarg.h>",
        f'#include "{SRC / "include" / "aic8800d80_types.h"}"',
        f'#include "{SRC / "include" / "aic8800d80_structs.h"}"',
        f'#include "{SRC / "include" / "aic8800d80_mmio.h"}"',
    ]
    return "\n".join(hdrs) + "\n\n" + pre + "\n" + body + "\n"


def is_realpseudocode_body(body: str) -> bool:
    """True if the body is a real-pseudo body (transpiled IDA pseudocode),
    False if it's a template/motif body or empty."""
    if "reconstructed_micro_flow: yes" in body:
        return True
    return False


def find_function_calls(body: str, self_name: str) -> list[str]:
    """Find every function call (name followed by `(`) in the body, excluding
    the function being tested itself and C keywords, type names, and macros."""
    # Names that look like calls but are actually keywords / types / macros
    non_calls = {
        "if", "while", "for", "switch", "return", "sizeof", "typeof", "do",
        # C type names
        "int", "char", "short", "long", "float", "double", "void",
        "uint8_t", "uint16_t", "uint32_t", "uint64_t",
        "int8_t", "int16_t", "int32_t", "int64_t",
        "bool", "size_t", "uintptr_t", "intptr_t",
        # IDA byte/word extraction macros
        "LOBYTE", "HIBYTE", "LOWORD", "HIWORD",
        "LODWORD", "HIDWORD", "BYTE0", "BYTE1", "BYTE2", "BYTE3",
        "WORD0", "WORD1",
        # ARM intrinsics (already #defined inside the body)
        "__get_CPSR", "__disable_irq", "__enable_irq", "__set_CPSR",
        # Common GCC / clang builtins that look like calls
        "__builtin_expect", "__builtin_trap", "__builtin_unreachable",
        # `macros` is sometimes a stray identifier from header copy-paste
        "macros",
    }
    calls = set()
    for m in re.finditer(r"\b([a-zA-Z_][a-zA-Z0-9_]*)\s*\(", body):
        n = m.group(1)
        if n == self_name or n in non_calls:
            continue
        calls.add(n)
    return sorted(calls)


def parse_last_json(out: str) -> dict | None:
    blocks: list[str] = []
    depth = 0
    start = -1
    for i, c in enumerate(out):
        if c == "{":
            if depth == 0:
                start = i
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0 and start != -1:
                blocks.append(out[start : i + 1])
                start = -1
    if not blocks:
        return None
    try:
        return json.loads(blocks[-1])
    except json.JSONDecodeError:
        return None


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--final", type=Path, action="append", default=[],
                    help="Final C file (repeatable, one per image; required)")
    ap.add_argument("--final-dir", type=Path, default=None,
                    help="Directory containing all final *.reconstructed.c files (alternative to --final)")
    ap.add_argument("--targets", type=Path, default=None,
                    help="JSON file with target list (default: truth_lane_targets.json)")
    ap.add_argument("--out", required=True, type=Path, help="Output directory")
    ap.add_argument("--max-insns", type=int, default=10000)
    ap.add_argument("--label", default="v12_smoke")
    ap.add_argument("--src", action="store_true",
                    help="Run against unified-series src/<img>_u02/main.c bodies (match by address marker)")
    args = ap.parse_args()

    if args.src:
        final_by_image = {
            k: SRC / f"{k}_u02" / "main.c"
            for k in ("fmacfw", "fmacfw_h", "fmacfwbt", "lmacfw_rf")
            if (SRC / f"{k}_u02" / "main.c").exists()
        }
    else:
        if not args.final and not args.final_dir:
            ap.error("must provide --final (repeatable) or --final-dir")
        if not args.final and args.final_dir:
            args.final = sorted(args.final_dir.glob("*.reconstructed.c"))

        # Map each final file to its image identifier (extracted from filename).
        final_by_image: dict[str, Path] = {}
        for f in args.final:
            # e.g. lmacfw_rf_8800d80_u02_bin.reconstructed.c -> lmacfw_rf
            stem = f.stem.replace(".reconstructed", "").replace("_bin", "")
            # strip the trailing _8800d80_u02
            stem = re.sub(r"_8800d80_u02$", "", stem)
            final_by_image[stem] = f

    final_text_by_image: dict[str, str] = {
        img: p.read_text(errors="replace") for img, p in final_by_image.items()
    }

    args.out.mkdir(parents=True, exist_ok=True)
    if args.targets is None:
        args.targets = REPO / "extraction_out/reconstruction/truth_lane_state/truth_lane_targets.json"
    targets = json.loads(args.targets.read_text())

    bodies_dir = args.out / "bodies"
    bodies_dir.mkdir(exist_ok=True)
    jsonl_path = args.out / "smoke_outcomes.jsonl"
    summary_path = args.out / "smoke_summary.md"

    rows: list[dict] = []
    for tgt in targets:
        fn = tgt["function"]
        tgt_image = tgt.get("image", "")
        # Pick the right final file for this target's image.
        # target's image is e.g. fmacfw_8800d80_h_u02.bin; we want fmacfw_h.
        if args.src:
            m2 = re.match(r"^(fmacfw)_8800d80(_h)?_u02(?:\.bin)?$", tgt_image)
            if m2:
                image_key = m2.group(1) + (m2.group(2) or "")
            else:
                m2 = re.match(r"^(fmacfwbt|lmacfw_rf)", tgt_image)
                image_key = m2.group(1) if m2 else ""
        else:
            image_key = tgt_image.replace(".bin", "").replace("_8800d80_u02", "")
        text = final_text_by_image.get(image_key)
        if text is None:
            rows.append({"function": fn, "image": tgt_image, "address": tgt.get("address"),
                         "status": "no_final_file", "verdict": "FAIL",
                         "note": f"no final file for image {image_key!r}"})
            continue
        if args.src:
            body = extract_body_by_addr(text, tgt.get("address", ""))
            if body is None:
                rows.append({"function": fn, "image": tgt_image, "address": tgt.get("address"),
                             "status": "no_body", "verdict": "FAIL",
                             "note": f"no body at address {tgt.get('address')!r} in src/{image_key}_u02/main.c"})
                continue
            is_real = True
            mm = re.match(r"^// (\w+) @ ", body)
            run_fn = mm.group(1) if mm else fn
            subs = find_function_calls(body, run_fn)
            skip = set(subs) | {fn, run_fn}
            body_file = bodies_dir / f"{fn}__{image_key}.c"
            body_file.write_text(make_src_source(body, text, skip))
        else:
            body = extract_body(text, fn)
            if body is None:
                rows.append({"function": fn, "image": tgt_image, "address": tgt.get("address"),
                             "status": "no_body", "verdict": "FAIL",
                             "note": f"function definition not found in {image_key!r} final file"})
                continue
            is_real = is_realpseudocode_body(body)
            subs = find_function_calls(body, fn)
            run_fn = fn
            body_file = bodies_dir / f"{fn}__{image_key}.c"
            body_file.write_text(make_source(body))
        cmd = [
            sys.executable, str(SMOKE),
            str(body_file), run_fn,
            "--image", tgt_image,
            "--address", tgt.get("address", ""),
            "--mmio-autopage",
            "--max-insns", str(args.max_insns),
            "--state-profile", "rich",
            "--record-outcome", str(args.out / "smoke_outcomes_raw.jsonl"),
        ]
        for s in subs:
            cmd.extend(["--stub-fn", s])
        proc = subprocess.run(cmd, capture_output=True, text=True, cwd=REPO)
        j = parse_last_json(proc.stdout)
        if j is None:
            rows.append({"function": fn, "image": tgt_image, "address": tgt.get("address"),
                         "body_kind": "real_pseudo" if is_real else "motif",
                         "status": "compile_error", "verdict": "FAIL",
                         "stderr": proc.stderr[-500:] if proc.stderr else ""})
            continue
        status = j.get("status")
        insns = j.get("instructions", 0)
        writes = j.get("mmio_write_count", 0)
        reads = j.get("mmio_read_count", 0)
        term = j.get("termination_reason", "")
        # Verdict: real-pseudo + returned + wrote MMIO = PASS
        #          motif body returning = REVIEW (template, not real hardware)
        #          capped = REVIEW (didn't finish)
        #          fault / compile_error = FAIL
        if status == "returned" and writes > 0 and is_real:
            verdict = "PASS"
        elif status == "returned" and writes > 0 and not is_real:
            verdict = "REVIEW"
        elif status == "returned":
            verdict = "REVIEW"
        elif status == "capped":
            verdict = "REVIEW"
        elif status == "fault":
            verdict = "FAIL"
        else:
            verdict = "REVIEW"
        rows.append({
            "function": fn,
            "image": tgt.get("image"),
            "address": tgt.get("address"),
            "motif": tgt.get("motif"),
            "body_kind": "real_pseudo" if is_real else "motif",
            "status": status,
            "verdict": verdict,
            "instructions": insns,
            "mmio_read_count": reads,
            "mmio_write_count": writes,
            "mmio_unique_addrs": j.get("mmio_unique_addrs", []),
            "termination_reason": term,
            "helper_count": len(subs),
        })

    with jsonl_path.open("w", encoding="utf-8") as f:
        for r in rows:
            r["generated_at"] = datetime.now(timezone.utc).isoformat()
            r["label"] = args.label
            f.write(json.dumps(r, sort_keys=True) + "\n")

    pass_n = sum(1 for r in rows if r["verdict"] == "PASS")
    review_n = sum(1 for r in rows if r["verdict"] == "REVIEW")
    fail_n = sum(1 for r in rows if r["verdict"] == "FAIL")
    real_n = sum(1 for r in rows if r.get("body_kind") == "real_pseudo")
    with summary_path.open("w", encoding="utf-8") as f:
        f.write(f"# Truth Lane Smoke Summary ({args.label})\n\n")
        f.write(f"PASS={pass_n} REVIEW={review_n} FAIL={fail_n} total={len(rows)} "
                f"(real_pseudo bodies: {real_n})\n\n")
        f.write("| function | image | addr | motif | body | status | insns | reads | writes | verdict |\n")
        f.write("|----------|-------|------|-------|------|--------|------:|------:|-------:|:-------:|\n")
        for r in rows:
            f.write(f"| {r['function']} | {r.get('image','')} | {r.get('address','')} | "
                    f"{r.get('motif','')} | {r.get('body_kind','')} | {r['status']} | "
                    f"{r.get('instructions','')} | {r.get('mmio_read_count','')} | "
                    f"{r.get('mmio_write_count','')} | **{r['verdict']}** |\n")

    print(f"[truth_lane_smoke] PASS={pass_n} REVIEW={review_n} FAIL={fail_n} total={len(rows)}")
    print(f"[truth_lane_smoke] wrote {jsonl_path}")
    print(f"[truth_lane_smoke] wrote {summary_path}")
    return 0 if fail_n == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
