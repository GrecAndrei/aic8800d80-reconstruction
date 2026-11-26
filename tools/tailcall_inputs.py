#!/usr/bin/env python3
"""tailcall_inputs.py — restore machine-proven inputs to tail-called targets.

Two lmac sites are byte-level certain:

* capability_dispatch (0x117db4 / hardware 0x137db4) loads `[r0,#0x48]` and,
  when nonzero, tail-branches to bt_link_rx_check without changing r0. The
  input object is therefore forwarded unchanged.
* rx_irq_handler_1 (0x11de50 / hardware 0x13de50) executes
  `sub.w r0, r4, #12` before its tail branch to patch_trampoline; r4 is the
  incoming a1. The trampoline itself is a pure `b.w mac_ll_scheduler`, so the
  computed message pointer must be explicit.

Hex-Rays emitted both as zero-argument function-pointer casts. Address-keyed
and idempotent; --check reports pending rewrites.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TARGETS = {
    "lmacfw_rf_u02": [
        {
            "addr": 0x117DB4,
            "old": "return ((int (*)())bt_link_rx_check)();",
            "new": "return bt_link_rx_check(result);",
        },
        {
            "addr": 0x11DE50,
            "old": "return (volatile uint32_t *)((int (*)())patch_trampoline)();",
            "new": "return (volatile uint32_t *)patch_trampoline(a1 - 12);",
        },
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
    paths = [root / "main.c"] + sorted((root / "modules").glob("mod*.c"))
    for path in paths:
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
                print(f"[tailcall_inputs] ERROR: pattern missing at {spec['addr']:#x}", file=sys.stderr)
                rc = 1
            elif n and args.check:
                rc = 1
        print(f"[tailcall_inputs] {short}: {total} tail-input rewrite(s) "
              f"{'pending' if args.check else 'applied/fixed-point'}")
    return rc


if __name__ == "__main__":
    sys.exit(main())
