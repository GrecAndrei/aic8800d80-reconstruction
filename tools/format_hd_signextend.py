#!/usr/bin/env python3
"""format_hd_signextend.py — restore the sign extension of %hd/%hi conversion.

Machine evidence (all four images): the signed short-decimal conversion arm of
the shared formatter core loads the variadic word and sign-extends it:

    fmacfw_u02 0x12e912:  ldr r1, [fp], #4
    fmacfw_u02 0x12e916:  sxth r1, r1            ; sign-extend low 16 bits

The Hex-Rays decompile instead emits `(uint16_t)` zero extension, so the
reconstruction prints 65534 where the original prints -2 (confirmed by
controlled differential execution: original [-2] vs reconstruction [65534],
and 0x8000 -> -32768 vs 32768). The repair rewrites exactly the signed-label
sequence inside the four machine-identified formatter functions:

    LABEL_x:
        vNN = *a5++;
        vMM = (uint16_t)vNN;

to use `(int16_t)`, which reproduces sxth bit-for-bit: negatives then carry
bit 31, the existing `& 0x80000000` sign test engages, and the magnitude path
is unchanged. The unsigned `%hu/%hx` arms use a different inline sequence
(inside the `v7 != 100` block, followed by a switch) and are never matched,
because the pattern requires a label directly above the argument load.

Formatter functions (machine-identified shared vsnprintf core):
  fmacfw_u02 0x12e11c, fmacfw_h_u02 0x12dfdc,
  fmacfwbt_u02 0x12e344, lmacfw_rf_u02 0x11ebb4.

Idempotent; --check reports pending rewrites.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent

FORMATTERS = {
    "fmacfw_h_u02": 0x12DFDC,
    "fmacfw_u02": 0x12E11C,
    "fmacfwbt_u02": 0x12E344,
    "lmacfw_rf_u02": 0x11EBB4,
}

MARKER_RE = re.compile(r"(?m)^// (\w+) @ 0x([0-9a-fA-F]+)")
# The signed conversion arm: a label immediately above the variadic load,
# then the zero-extending cast on the very next line.
SIGNED_ARM_RE = re.compile(
    r"(?m)^(LABEL_\d+:\n[ \t]+(v\d+) = \*a5\+\+;\n[ \t]+(v\d+) = )\(uint16_t\)(\2;)")
# Fixed-point witness: the same arm already rewritten to the sign-extending cast.
SIGNED_ARM_DONE_RE = re.compile(
    r"(?m)^LABEL_\d+:\n[ \t]+v\d+ = \*a5\+\+;\n[ \t]+v\d+ = \(int16_t\)v\d+;")


def apply_image(text: str, addr: int) -> tuple[str, int]:
    m = MARKER_RE.search(text)
    starts = [(int(a, 16), mm.start()) for mm in MARKER_RE.finditer(text) for a in [mm.group(2)]]
    starts.sort()
    span = None
    for i, (a, pos) in enumerate(starts):
        if a == addr:
            end = starts[i + 1][1] if i + 1 < len(starts) else len(text)
            span = (pos, end)
            break
    if span is None:
        return text, 0
    body = text[span[0]:span[1]]
    out, n = SIGNED_ARM_RE.subn(r"\g<1>(int16_t)\g<4>", body)
    if not n:
        if SIGNED_ARM_DONE_RE.search(body):
            return text, 0            # already at the fixed point
        return text, -1               # arm genuinely missing: structure changed
    return text[:span[0]] + out + text[span[1]:], n


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    rc = 0
    for short, addr in FORMATTERS.items():
        path = REPO / "src" / short / "main.c"
        text = path.read_text(errors="replace")
        out, n = apply_image(text, addr)
        if n >= 0:
            print(f"[format_hd_signextend] {short}: {n} signed-arm rewrite(s) "
                  f"{'pending' if args.check else 'applied'}")
        if n < 0:
            print(f"[format_hd_signextend] ERROR: {short} formatter arm not found at {addr:#x}",
                  file=sys.stderr)
            rc = 1
        elif n and args.check:
            rc = 1
        elif n and not args.check:
            path.write_text(out)
    return rc


if __name__ == "__main__":
    sys.exit(main())
