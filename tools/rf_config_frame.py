#!/usr/bin/env python3
"""rf_config_frame.py — materialize rf_config_load's raw 64-byte stack frame.

Machine evidence (lmacfw_rf 0x126764): the original allocates exactly
``sub sp,#0x40``, copies the 12-word notch table to sp+0x10..sp+0x3f, and
uses a table base at sp+0x40 purely as address arithmetic:

  type 0: sp+0x10 + 8*(a1-1)  (first three table pairs)
  type 1: sp+0x20 + 8*a1      (second three table pairs)

Hex-Rays instead invents a 16-byte ``vars0[2]`` object AT sp+0x40 (one byte
past the end of the real frame) and reaches backward out of it into the
table. That is out-of-object pointer arithmetic even for valid a1=1..3, so a
correct compiler may scalarize/re-layout the frame. The measured boot_neg
failure was the concrete instance: a spill of a1 landed where the original
still had dead zeroed scratch, changing one RF MMIO value from 0 to
0xffffffff.

Repair: make the whole hardware frame one 64-byte object (unioned with the
named field view) and perform the two dynamic table reads by word index into
that object. All pointer arithmetic for valid inputs is then inside one
object, and the negative-index boot probe reads the same leading scratch
bytes the original machine code reads.

Address-keyed and idempotent; --check reports pending rewrites.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TARGET = ("lmacfw_rf_u02", 0x126764)
MARKER_RE = re.compile(r"(?m)^// (\w+) @ 0x([0-9a-fA-F]+)\s*$")
DONE_RE = re.compile(r"_rf_words\[16\]")

OLD_FRAME = """  struct __attribute__((packed)) { uint64_t result; // [sp+8h] [bp-38h] BYREF
  int v23; // [sp+10h] [bp-30h]
  int v24; // [sp+14h] [bp-2Ch]
  int v25; // [sp+18h] [bp-28h]
  int v26; // [sp+1Ch] [bp-24h]
  int v27; // [sp+20h] [bp-20h]
  int v28; // [sp+24h] [bp-1Ch]
  int v29; // [sp+28h] [bp-18h]
  int v30; // [sp+2Ch] [bp-14h]
  int v31; // [sp+30h] [bp-10h]
  int v32; // [sp+34h] [bp-Ch]
  int v33; // [sp+38h] [bp-8h]
  int v34; // [sp+3Ch] [bp-4h]
  uint64_t vars0[2]; // [sp+40h] [bp+0h] BYREF
  } _frame;
"""

NEW_FRAME = """  union {
    uint64_t _rf_align;
    uint32_t _rf_words[16];
    struct __attribute__((packed)) {
      char _rf_pad0[8];   // sp+0x00..sp+0x07: raw scratch before result
      uint64_t result;    // sp+0x08
      int v23;            // sp+0x10
      int v24;            // sp+0x14
      int v25;            // sp+0x18
      int v26;            // sp+0x1c
      int v27;            // sp+0x20
      int v28;            // sp+0x24
      int v29;            // sp+0x28
      int v30;            // sp+0x2c
      int v31;            // sp+0x30
      int v32;            // sp+0x34
      int v33;            // sp+0x38
      int v34;            // sp+0x3c
    } f;
  } _frame;
"""

FIELD_RE = re.compile(r"\b_frame\.(result|v(?:23|24|25|26|27|28|29|30|31|32|33|34))\b")

OLD_TYPE0_READS = """    *v20 = *((volatile uint32_t *)v21 - 12);
    v17 = *((volatile uint32_t *)v21 - 11);
"""
NEW_TYPE0_READS = """    *v20 = _frame._rf_words[(0x10 + 8 * (a1 - 1)) / 4];
    v17 = _frame._rf_words[(0x14 + 8 * (a1 - 1)) / 4];
"""

OLD_TYPE1 = """    v16 = &_frame.vars0[a1];
    *v14 = *((volatile uint32_t *)v16 - 8);
    v17 = *((volatile uint32_t *)v16 - 7);
"""
NEW_TYPE1 = """    *v14 = _frame._rf_words[(0x20 + 8 * a1) / 4];
    v17 = _frame._rf_words[(0x24 + 8 * a1) / 4];
"""


def function_span(text: str, addr: int) -> tuple[int, int] | None:
    starts = [(int(m.group(2), 16), m.start()) for m in MARKER_RE.finditer(text)]
    starts.sort()
    for i, (a, pos) in enumerate(starts):
        if a == addr:
            return pos, starts[i + 1][1] if i + 1 < len(starts) else len(text)
    return None


def transform_body(body: str) -> tuple[str, int]:
    if DONE_RE.search(body):
        return body, 0
    if (OLD_FRAME not in body or "    v21 = &_frame.vars0[a1 - 1];\n" not in body
            or OLD_TYPE0_READS not in body or OLD_TYPE1 not in body):
        return body, -1
    out = body.replace(OLD_FRAME, NEW_FRAME, 1)
    out = FIELD_RE.sub(r"_frame.f.\1", out)
    out = out.replace("    v21 = &_frame.vars0[a1 - 1];\n", "", 1)
    out = out.replace(OLD_TYPE0_READS, NEW_TYPE0_READS, 1)
    out = out.replace(OLD_TYPE1, NEW_TYPE1, 1)
    out = out.replace("  volatile uint64_t *v16; // r5\n", "", 1)
    out = out.replace("  volatile uint64_t *v21; // r5\n", "", 1)
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


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    short, addr = TARGET
    path = REPO / "src" / short / "main.c"
    text = path.read_text(errors="replace")
    n = 0
    target_seen = False
    if '#include "modules/' not in text:
        out, n = apply_image(text, addr)
        target_seen = function_span(text, addr) is not None
        if n > 0 and not args.check:
            path.write_text(out)
    else:
        # In the tracked tree the monolith has been de-monolithized. The chain
        # itself applies this rule before that split, but --check/manual runs
        # must still inspect the module that physically carries the function.
        for module in sorted((path.parent / "modules").glob("mod*.c")):
            mt = module.read_text(errors="replace")
            if function_span(mt, addr) is None:
                continue
            target_seen = True
            out, n = apply_image(mt, addr)
            if n > 0 and not args.check:
                module.write_text(out)
            break
    print(f"[rf_config_frame] {short}: {n} raw-frame rewrite(s) "
          f"{'pending' if args.check else 'applied/fixed-point'}")
    if n < 0 or not target_seen:
        print(f"[rf_config_frame] ERROR: frame pattern not found at {addr:#x}", file=sys.stderr)
        return 1
    if n and args.check:
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
