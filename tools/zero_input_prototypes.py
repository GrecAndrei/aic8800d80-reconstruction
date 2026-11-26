#!/usr/bin/env python3
"""zero_input_prototypes.py — correct machine-proven zero-input prototypes.

Hex-Rays sometimes invents unused ``a1/a2`` parameters. That is not cosmetic:
callers then use zero-argument function-pointer casts even though the original
machine function genuinely ignores the argument registers.

Machine evidence for lmacfw_rf ``process_event`` (analysis 0x112d84 /
hardware 0x132d84): the entry immediately loads global state, overwrites r0
before any use, and never consumes input r0/r1. Its internal list_count call
sets only r0; list_count itself consumes only r0. Therefore process_event is
a zero-input function and its call sites can be direct zero-argument calls.

Address/name keyed and idempotent; --check reports pending rewrites.
"""
import argparse
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TARGETS = {
    "lmacfw_rf_u02": {
        "addr": 0x112D84,
        "name": "process_event",
        "replacements": [
            ("int process_event(int a1, int a2) {", "int process_event() {"),
            ("int process_event(int a1, int a2);", "int process_event();"),
            ("((int (*)())list_count)((void *)(uintptr_t)(off_112E1C), a2)",
             "list_count((volatile uint32_t **)(uintptr_t)off_112E1C)"),
            ("((int (*)())process_event)()", "process_event()"),
        ],
    }
}


def transform_text(text: str, replacements: list[tuple[str, str]]) -> tuple[str, int]:
    n = 0
    for old, new in replacements:
        count = text.count(old)
        if count:
            text = text.replace(old, new)
            n += count
    return text, n


def image_files(short: str) -> list[Path]:
    root = REPO / "src" / short
    files = [root / "main.c"]
    files.extend(sorted((root / "modules").glob("mod*.c")))
    return [p for p in files if p.exists()]


def apply_image(short: str, spec: dict, check: bool) -> tuple[int, bool]:
    target_seen = False
    total = 0
    needle = f"// {spec['name']} @ 0x{spec['addr']:x}"
    for path in image_files(short):
        text = path.read_text(errors="replace")
        if needle in text:
            target_seen = True
        out, n = transform_text(text, spec["replacements"])
        total += n
        if n and not check:
            path.write_text(out)
    return total, target_seen


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    rc = 0
    for short, spec in TARGETS.items():
        n, seen = apply_image(short, spec, args.check)
        print(f"[zero_input_prototypes] {short}: {n} rewrite(s) "
              f"{'pending' if args.check else 'applied/fixed-point'}")
        if not seen:
            print(f"[zero_input_prototypes] ERROR: target missing at {spec['addr']:#x}", file=sys.stderr)
            rc = 1
        elif n and args.check:
            rc = 1
    return rc


if __name__ == "__main__":
    sys.exit(main())
