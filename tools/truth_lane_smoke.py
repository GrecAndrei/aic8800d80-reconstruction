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
      REVIEW = capped, motif, or returned without a peripheral write
      FAIL   = harness error, execution fault, missing symbol or no body
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
        # static inline helpers in aic8800d80_types.h — must NOT be stubbed
        # (a stub #define would expand inside the header and break it)
        "COERCE_FLOAT", "COERCE_UINT32", "COERCE_INT32", "MEMD", "JUMPOUT",
        "bswap32", "abs16", "abs32", "__rev", "__rev16", "__usat", "__clz",
        "__ROR4__", "_byteswap_ushort", "SHIBYTE", "SLOBYTE", "SHIDWORD",
        "WORD1", "WORD2", "BYTE1", "BYTE2", "BYTE3", "BYTE4", "vld1_u32",
        "vcvts_n_s32_f32", "vcvts_n_f32_u32", "__get_FPSCR", "__set_FPSCR",
        "__noreturn", "__pld", "__dsb", "__isb", "__wfi", "__mcr", "__mrc",
        # Common GCC / clang builtins that look like calls
        "__builtin_expect", "__builtin_trap", "__builtin_unreachable",
        # GNU keywords: `struct __attribute__((packed))`, `f() __asm__("label")`
        "__attribute__", "__asm__", "__asm",
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


ORIG_BASELINE = REPO / "metadata" / "truth_lane_orig_depth0.json"


def load_orig_baseline(path: Path) -> dict[tuple[str, str], dict]:
    """Depth-0 peripheral footprint of the original bodies (emulator `verify`)."""
    if not path.is_file():
        return {}
    return {(r["image"], r["address"]): r for r in json.loads(path.read_text())}


def smoke_verdict(status: str, returncode: int, writes: int, is_real: bool,
                  periph_addrs: list[str] | None = None, orig: dict | None = None) -> tuple[str, str]:
    """Return (verdict, basis).

    A write-free return is only a PASS when the original binary's own body
    (depth 0, callees excluded, as the smoke stubs them) also returned without
    a peripheral write, touched the same peripheral registers, and none of its
    callees wrote a peripheral either. That is a footprint match on one default-state path, not behavioral equivalence.
    """
    if status == "capped" and returncode == 4:
        return "REVIEW", "instruction_cap"
    if returncode != 0 or status != "returned":
        return "FAIL", "did_not_return"
    if not is_real:
        return "REVIEW", "not_a_real_body"
    if writes > 0:
        if orig is not None and not orig["self_periph_write_addrs"]:
            return "REVIEW", "write_absent_from_original_body"
        return "PASS", "peripheral_write"
    if orig is None:
        return "REVIEW", "no_peripheral_write"
    if orig["termination"] != "returned" or orig["self_periph_write_addrs"]:
        return "REVIEW", "original_body_writes_peripheral"
    if sorted(periph_addrs or []) != sorted(orig["self_periph_addrs"]):
        return "REVIEW", "peripheral_footprint_differs"
    if orig.get("callee_periph_write"):
        # The original's peripheral writes on this path come from callees the
        # smoke stubs, so this check cannot observe the target's hardware effect.
        return "REVIEW", "original_writes_peripheral_only_in_callees"
    return "PASS", "original_writes_no_peripheral"


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
    ap.add_argument("--orig-baseline", type=Path, default=ORIG_BASELINE,
                    help="Original depth-0 peripheral footprint from `aic8800d80_emulator.py verify` "
                         "(orig_depth0_baseline.json); a missing file disables the write-free PASS")
    args = ap.parse_args()
    orig_baseline = load_orig_baseline(args.orig_baseline)

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
        args.targets = (REPO / "metadata/truth_lane_targets.json" if args.src else
                        REPO / "extraction_out/reconstruction/truth_lane_state/truth_lane_targets.json")
    if not args.targets.is_file():
        ap.error(f"targets not found: {args.targets}; specify a manifest with --targets")
    targets = json.loads(args.targets.read_text())
    if not isinstance(targets, list) or not targets:
        ap.error(f"expected a non-empty target list in {args.targets}")

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
        periph_addrs = j.get("mmio_unique_addrs", [])  # unicorn_smoke records peripheral addresses only
        verdict, basis = smoke_verdict(status, proc.returncode, writes, is_real, periph_addrs,
                                       orig_baseline.get((tgt.get("image"), tgt.get("address"))))
        rows.append({
            "function": fn,
            "image": tgt.get("image"),
            "address": tgt.get("address"),
            "motif": tgt.get("motif"),
            "body_kind": "real_pseudo" if is_real else "motif",
            "status": status,
            "verdict": verdict,
            "verdict_basis": basis,
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
        f.write("| function | image | addr | motif | body | status | insns | reads | writes | verdict | basis |\n")
        f.write("|----------|-------|------|-------|------|--------|------:|------:|-------:|:-------:|-------|\n")
        for r in rows:
            f.write(f"| {r['function']} | {r.get('image','')} | {r.get('address','')} | "
                    f"{r.get('motif','')} | {r.get('body_kind','')} | {r['status']} | "
                    f"{r.get('instructions','')} | {r.get('mmio_read_count','')} | "
                    f"{r.get('mmio_write_count','')} | **{r['verdict']}** | {r.get('verdict_basis','')} |\n")

    print(f"[truth_lane_smoke] PASS={pass_n} REVIEW={review_n} FAIL={fail_n} total={len(rows)}")
    print(f"[truth_lane_smoke] wrote {jsonl_path}")
    print(f"[truth_lane_smoke] wrote {summary_path}")
    return 0 if fail_n == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
