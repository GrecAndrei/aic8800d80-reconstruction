#!/usr/bin/env python3
"""format_scratch_frame.py — merge the formatter scratch frame into one array object.

Machine evidence (write-traced, fmacfw_u02 `%u` arg 0xffff8000): the original
formatter generates conversion digits backward from `sp+0x50` into the raw
stack scratch below it (sp+0x45..sp+0x4f for decimal, down to sp+0x31 for
binary), and the `%A`/`%M`/`%c` conversions use the forward part of the same
contiguous region sp+0x10..sp+0x53. Nothing else in the original frame
overlaps that region, so the original is correct.

The Hex-Rays decompile models the frame as a packed struct whose scratch area
is split into separate small objects:

    char v80;          // [sp+10h]
    char v81;          // [sp+11h]
    char _pad6[1];
    char v82;          // [sp+13h]
    char _pad7[60];
    uint8_t v83[4];    // [sp+50h]  <- backward digit-write anchor

The generated code then walks pointers ACROSS these object boundaries:
`*--v30` starting at `_frame.v83` writes below the 4-byte array, and the
%A/%M loops write forward out of the 1-byte v80/v82 scalars. That is
out-of-object pointer arithmetic in C, so the compiler is free to split the
struct (SROA) and place spill slots where the original kept dead scratch.
Machine-verified consequence in the linked reconstruction: the decimal loop
writes digits at sp+27..sp+18, then the spill `str r0, [sp, #20]` of the
loop-exit pointer overwrites output positions 2..5 with a stack pointer
(`%u` 0xffff8000 -> `42<sp>4528` instead of `4294934528`), and in the signed
case the spill slot overlaps the sign/digit bytes so the reloaded emission
pointer itself is corrupted (`%d` -> empty output). Whether a given compile
exposes the defect is frame-layout luck: the same source compiles to a
108-byte frame without harmful overlap under some flag sets and to a
36-byte frame with the overlap under others. The defect is therefore the
decompile frame model, not any particular optimizer flag.

Repair: merge the whole scratch span sp+0x10..sp+0x53 into one array object
`char v80_scratch[68]` and rewrite every reference to the original fields
with the same relative offset, so all generation/emission pointer arithmetic
stays inside one object — defined behavior that every correct compilation
must preserve, matching the original byte-for-byte. Offset map:
v80 -> [0], v81 -> [1], _pad6 -> [2], v82 -> [3], v83 -> [64] (sp+0x50).

Worst-case bounds inside the 68-byte object (all verified against the
original machine code): decimal 10 digits + sign reaches offset 64-11=53-1..,
binary 32 digits reaches 64-32=32, `%A` with the 21-byte width clamp writes
forward from offset 3 at most 62 bytes. All in bounds.

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

OLD_DECL = (
    "  char v80; // [sp+10h] [bp-44h] BYREF\n"
    "  char v81; // [sp+11h] [bp-43h]\n"
    "  char _pad6[1]; char v82; // [sp+13h] [bp-41h] BYREF\n"
    "  char _pad7[60]; uint8_t v83[4]; // [sp+50h] [bp-4h] BYREF\n"
)
NEW_DECL = (
    "  char v80_scratch[68]; // [sp+10h] [bp-44h] BYREF — merged scratch: the original uses\n"
    "  // sp+0x10..sp+0x53 as ONE raw stack region (digit generation grows backward from\n"
    "  // sp+0x50, %A/%M grow forward from sp+0x10/0x13); merged into one object so the\n"
    "  // cross-field pointer arithmetic stays in bounds under any correct compilation.\n"
    "  // offsets: v80=[0] v81=[1] pad=[2] v82=[3] v83 anchor=[64]\n"
)

# reference rewrites, longest first; \b prevents matching inside v80_scratch.
REWRITES = [
    (re.compile(r"&_frame\.v83\b"), "(&_frame.v80_scratch[64])"),
    (re.compile(r"&_frame\.v82\b"), "(&_frame.v80_scratch[3])"),
    (re.compile(r"&_frame\.v81\b"), "(&_frame.v80_scratch[1])"),
    (re.compile(r"&_frame\.v80\b"), "(&_frame.v80_scratch[0])"),
    (re.compile(r"(?<![&\w])_frame\.v83\b"), "(&_frame.v80_scratch[64])"),
    (re.compile(r"(?<![&\w])_frame\.v82\b"), "_frame.v80_scratch[3]"),
    (re.compile(r"(?<![&\w])_frame\.v81\b"), "_frame.v80_scratch[1]"),
    (re.compile(r"(?<![&\w])_frame\.v80\b"), "_frame.v80_scratch[0]"),
]
DONE_RE = re.compile(r"v80_scratch\[68\]")


def apply_image(text: str, addr: int) -> tuple[str, int]:
    starts = [(int(m.group(2), 16), m.start()) for m in MARKER_RE.finditer(text)]
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
    if DONE_RE.search(body):
        return text, 0                       # already at the fixed point
    if OLD_DECL not in body:
        return text, -1                      # frame struct genuinely different
    out = body.replace(OLD_DECL, NEW_DECL, 1)
    n = 1
    for rx, rep in REWRITES:
        out, k = rx.subn(rep, out)
        n += k
    return text[:span[0]] + out + text[span[1]:], n


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--src", default="", help="override src root (testing)")
    args = ap.parse_args()
    rc = 0
    root = Path(args.src) if args.src else REPO / "src"
    for short, addr in FORMATTERS.items():
        path = root / short / "main.c"
        text = path.read_text(errors="replace")
        out, n = apply_image(text, addr)
        if n >= 0:
            print(f"[format_scratch_frame] {short}: {n} rewrite(s) "
                  f"{'pending' if args.check else 'applied/fixed-point'}")
        if n < 0:
            print(f"[format_scratch_frame] ERROR: {short} formatter frame not matched at {addr:#x}",
                  file=sys.stderr)
            rc = 1
        elif n and args.check:
            rc = 1
        elif n and not args.check:
            path.write_text(out)
    return rc


if __name__ == "__main__":
    sys.exit(main())
