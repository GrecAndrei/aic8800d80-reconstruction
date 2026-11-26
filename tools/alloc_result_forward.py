#!/usr/bin/env python3
"""alloc_result_forward.py — forward allocator results proven in machine code.

Machine truth for lmacfw_rf ``rf_lmac_init_n114`` (analysis 0x110114 /
hardware 0x130114): each loop iteration calls ``list_iterate(v3,0x6b8)`` and
immediately moves the returned object from r0 to r1 before calling
``check_kernel_state`` with r0=v4. Hex-Rays discarded the list_iterate result
and emitted the second call through an under-arity cast. Restore the exact
forwarding chain. Address-keyed and idempotent.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TARGETS = {
    "lmacfw_rf_u02": [
        {
            "addr": 0x110114,
            "old": "      list_iterate(v3, 0x6B8u);\n      result = ((int (*)())check_kernel_state)(v4);",
            "new": "      result = check_kernel_state(v4, list_iterate(v3, 0x6B8u));",
        }
    ]
}
MARKER_RE = re.compile(r"(?m)^// (\w+) @ 0x([0-9a-fA-F]+)\s*$")


def function_span(text: str, addr: int) -> tuple[int, int] | None:
    starts = [(int(m.group(2), 16), m.start()) for m in MARKER_RE.finditer(text)]
    starts.sort()
    for i, (a, pos) in enumerate(starts):
        if a == addr:
            return pos, starts[i + 1][1] if i + 1 < len(starts) else len(text)
    return None


def transform_body(body: str, old: str, new: str) -> tuple[str, int]:
    if old not in body:
        return (body, 0) if new in body else (body, -1)
    return body.replace(old, new, 1), 1


def apply_target(short: str, spec: dict, check: bool) -> tuple[int, bool]:
    root = REPO / "src" / short
    for path in [root / "main.c"] + sorted((root / "modules").glob("mod*.c")):
        if not path.exists():
            continue
        text = path.read_text(errors="replace")
        span = function_span(text, spec["addr"])
        if span is None:
            continue
        body = text[span[0]:span[1]]
        out, n = transform_body(body, spec["old"], spec["new"])
        if n > 0 and not check:
            path.write_text(text[:span[0]] + out + text[span[1]:])
        return n, True
    return 0, False


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    rc = 0
    for short, specs in TARGETS.items():
        total = 0
        for spec in specs:
            n, seen = apply_target(short, spec, args.check)
            total += max(n, 0)
            if n < 0 or not seen:
                print(f"[alloc_result_forward] ERROR: pattern missing at {spec['addr']:#x}", file=sys.stderr)
                rc = 1
            elif n and args.check:
                rc = 1
        print(f"[alloc_result_forward] {short}: {total} forwarding rewrite(s) "
              f"{'pending' if args.check else 'applied/fixed-point'}")
    return rc


if __name__ == "__main__":
    sys.exit(main())
