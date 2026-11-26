#!/usr/bin/env python3
"""mrs_ipsr.py — distinguish machine-proven MRS IPSR reads from PRIMASK.

Hex-Rays prints both ``mrs r6, IPSR`` and ``mrs rN, PRIMASK`` as
``__get_CPSR()``. That distinction is behavioral: the logging/formatter
functions below execute in thread mode, where IPSR is zero even while
PRIMASK is nonzero inside a critical section. Treating the IPSR read as the
reconstruction's PRIMASK shadow suppresses the final UART-ready write
(0x40035040=1) after a log line.

Machine evidence:
  fmacfw_h   0x10d6c8+8   f3ef 8605   mrs r6, IPSR
  fmacfw     0x10d808+8   f3ef 8605   mrs r6, IPSR
  fmacfwbt   0x10d660+8   f3ef 8605   mrs r6, IPSR

Address-keyed and idempotent; --check reports pending rewrites.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TARGETS = {
    "fmacfw_h_u02": 0x10D6C8,
    "fmacfw_u02": 0x10D808,
    "fmacfwbt_u02": 0x10D660,
}
MARKER_RE = re.compile(r"(?m)^// (\w+) @ 0x([0-9a-fA-F]+)\s*$")
CPSR_RE = re.compile(r"\bCPSR\b")


def function_span(text: str, addr: int) -> tuple[int, int] | None:
    starts = [(int(m.group(2), 16), m.start()) for m in MARKER_RE.finditer(text)]
    starts.sort()
    for i, (a, pos) in enumerate(starts):
        if a == addr:
            return pos, starts[i + 1][1] if i + 1 < len(starts) else len(text)
    return None


def transform_body(body: str) -> tuple[str, int]:
    if "__get_IPSR()" in body:
        return (body, 0) if "unsigned int IPSR; // r6" in body else (body, -1)
    if "unsigned int CPSR; // r6" not in body or "CPSR = __get_CPSR();" not in body:
        return body, -1
    out = CPSR_RE.sub("IPSR", body)
    out = out.replace("IPSR = __get_CPSR();", "IPSR = __get_IPSR();", 1)
    return out, 1


def apply_image(text: str, addr: int) -> tuple[str, int]:
    span = function_span(text, addr)
    if span is None:
        return text, -1
    body = text[span[0]:span[1]]
    out, n = transform_body(body)
    if n > 0:
        text = text[:span[0]] + out + text[span[1]:]
    return text, n


def apply_one(short: str, addr: int, check: bool) -> tuple[int, bool]:
    path = REPO / "src" / short / "main.c"
    text = path.read_text(errors="replace")
    target_seen = False
    n = 0
    if '#include "modules/' not in text:
        target_seen = function_span(text, addr) is not None
        out, n = apply_image(text, addr)
        if n > 0 and not check:
            path.write_text(out)
    else:
        for module in sorted((path.parent / "modules").glob("mod*.c")):
            mt = module.read_text(errors="replace")
            if function_span(mt, addr) is None:
                continue
            target_seen = True
            out, n = apply_image(mt, addr)
            if n > 0 and not check:
                module.write_text(out)
            break
    return n, target_seen


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    rc = 0
    total = 0
    for short, addr in TARGETS.items():
        n, seen = apply_one(short, addr, args.check)
        total += max(n, 0)
        print(f"[mrs_ipsr] {short}: {n} IPSR rewrite(s) "
              f"{'pending' if args.check else 'applied/fixed-point'}")
        if n < 0 or not seen:
            print(f"[mrs_ipsr] ERROR: pattern not found at {addr:#x} in {short}", file=sys.stderr)
            rc = 1
        elif n and args.check:
            rc = 1
    return rc


if __name__ == "__main__":
    sys.exit(main())
