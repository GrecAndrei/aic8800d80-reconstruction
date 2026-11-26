#!/usr/bin/env python3
"""timer_target_forward.py — restore the timer object argument forwarded in r0.

Machine truth (lmacfw_rf): task_queue_handler_a/b/c load the timer object
pointer into r0 immediately before calling timer_is_past:

  ldr r0, [r4, #0xc]
  cbz r0, skip
  bl timer_is_past

Hex-Rays keeps that value in ``result`` but emits the callee through a
zero-arg cast. The repair forwards the machine-proven argument. Address-keyed
and idempotent; --check reports pending rewrites.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TARGETS = {"lmacfw_rf_u02": [0x116CDC, 0x116D98, 0x116E24]}
MARKER_RE = re.compile(r"(?m)^// (\w+) @ 0x([0-9a-fA-F]+)\s*$")
OLD = "result = ((int (*)())timer_is_past)();"
NEW = "result = timer_is_past(result);"


def function_span(text: str, addr: int) -> tuple[int, int] | None:
    starts = [(int(m.group(2), 16), m.start()) for m in MARKER_RE.finditer(text)]
    starts.sort()
    for i, (a, pos) in enumerate(starts):
        if a == addr:
            return pos, starts[i + 1][1] if i + 1 < len(starts) else len(text)
    return None


def transform_body(body: str) -> tuple[str, int]:
    if OLD not in body:
        return (body, 0) if NEW in body else (body, -1)
    return body.replace(OLD, NEW, 1), 1


def apply_one(short: str, addr: int, check: bool) -> tuple[int, bool]:
    path = REPO / "src" / short / "main.c"
    text = path.read_text(errors="replace")
    target_seen = False
    n = 0
    search_roots = [path]
    if '#include "modules/' in text:
        search_roots = sorted((path.parent / "modules").glob("mod*.c"))
    for p in search_roots:
        t = p.read_text(errors="replace")
        span = function_span(t, addr)
        if span is None:
            continue
        target_seen = True
        body = t[span[0]:span[1]]
        out, n = transform_body(body)
        if n > 0 and not check:
            p.write_text(t[:span[0]] + out + t[span[1]:])
        break
    return n, target_seen


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    rc = 0
    for short, addrs in TARGETS.items():
        ntotal = 0
        for addr in addrs:
            n, seen = apply_one(short, addr, args.check)
            ntotal += max(n, 0)
            if n < 0 or not seen:
                print(f"[timer_target_forward] ERROR: pattern missing at {addr:#x}", file=sys.stderr)
                rc = 1
            elif n and args.check:
                rc = 1
        print(f"[timer_target_forward] {short}: {ntotal} forwarding rewrite(s) "
              f"{'pending' if args.check else 'applied/fixed-point'}")
    return rc


if __name__ == "__main__":
    sys.exit(main())
