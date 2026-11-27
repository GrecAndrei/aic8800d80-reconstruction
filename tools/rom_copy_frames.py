#!/usr/bin/env python3
"""rom_copy_frames.py — materialize boot-ROM copy frames as one byte block.

Machine evidence: the calibration/SMC readers copy a fixed external block into
the base of the hardware stack frame through boot-ROM vector 0x1d8, then read
fields at byte offsets inside that same copied block:

  72-byte CALI block (fmacfw_h 0x114af0 is the example):
    copy dst sp+0x00, length 0x48; magic sp+0x00; flags sp+0x04;
    segments at sp+0x10/0x14/0x20/0x34/0x3c/0x40/0x44.

  320-byte WIFI block (fmacfw_h 0x114c3c):
    copy dst sp+0x00, length 0x140; magic sp+0x00; flags sp+0x04;
    segments at sp+0x14/0x124/0x128/0x130/0x134/0x136.

The composed Hex-Rays frame instead passes a small first member (`v9[4]`, 16
bytes, or `v8`, 4 bytes) as the destination of a 72/320-byte copy and relies on
overlap with later struct members. In C those later members are distinct
objects, so GCC is free to scalarize/reorder the frame. In the linked
fmacfw_h reconstruction the 72-byte copy started at sp+44 of an 84-byte frame
and ran into the saved-register area; the 320-byte body optimized away every
post-magic field read. This rule rewrites exactly the machine-identified
reader bodies so the escaping destination is a byte array covering the whole
copy, unioned with the packed field view. GCC then keeps the copy contiguous
(the 72-byte form again compiles to `sub sp,#0x4c; mov r2,sp`).

Address-keyed and idempotent; --check reports pending rewrites.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
MARKER_RE = re.compile(r"(?m)^// (\w+) @ 0x([0-9a-fA-F]+)\s*$")
FRAME_RE = re.compile(
    r"  struct __attribute__\(\(packed\)\) \{ .*?\n  \} _frame;\n",
    re.DOTALL,
)

# Every machine-identified reader clone. The inverse writeback readers in
# lmac_rf (0x11441c/0x1146e4) are intentionally not in this table: they use a
# different copy/commit contract and are not the SMC return-value family.
TARGETS = {
    "fmacfw_u02": {0x114C30: "small", 0x114D7C: "large"},
    "fmacfw_h_u02": {0x114AF0: "small", 0x114C3C: "large"},
    "fmacfwbt_u02": {0x11526C: "small", 0x1153B8: "large"},
    "lmacfw_rf_u02": {0x114318: "small", 0x1145F4: "large"},
}

SMALL_FRAME = """  union {
    uint8_t _rom_block[72];
    struct __attribute__((packed)) {
      uint32_t v9[2];       // +0x00 magic, +0x04 flags
      uint8_t _rom_pad1[8]; // +0x08..+0x0f unused
      uint8_t v10[4];       // +0x10
      uint8_t v11[12];      // +0x14
      uint8_t v12[20];      // +0x20
      uint8_t v13[4];       // +0x34
      uint8_t _rom_pad2[4]; // +0x38..+0x3b unused
      uint8_t v14[4];       // +0x3c
      uint8_t v15[4];       // +0x40
      uint8_t v16[4];       // +0x44
    } f;
  } _frame;
"""

LARGE_FRAME_TMPL = """  union {
    uint8_t _rom_block[320];
    struct __attribute__((packed)) {
      int v8;               // +0x00 magic
      int v9;               // +0x04 flags
      char _pad2[12];       // +0x08..+0x13 unused
      {t} v10[272];         // +0x14 (first 6 bytes are the bit-2 payload)
      {t} v11[2];           // +0x124
      uint8_t _rom_pad3[2]; // +0x126..+0x127 unused
      {t} v12[8];           // +0x128
      {t} v13[4];           // +0x130
      {t} v14[2];           // +0x134
      {t} {last}[10];       // +0x136
    } f;
  } _frame;
"""


def function_span(text: str, addr: int) -> tuple[int, int] | None:
    starts = [(int(m.group(2), 16), m.start()) for m in MARKER_RE.finditer(text)]
    starts.sort()
    for i, (a, pos) in enumerate(starts):
        if a == addr:
            return pos, starts[i + 1][1] if i + 1 < len(starts) else len(text)
    return None


def large_frame(frame_decl: str) -> str | None:
    tm = re.search(r"\b(uint8_t|char)\s+v10\[272\]", frame_decl)
    lm = re.search(r"\b(uint8_t|char)\s+(\w+)\[14\]", frame_decl)
    if not tm or not lm or tm.group(1) != lm.group(1):
        return None
    return LARGE_FRAME_TMPL.replace("{t}", tm.group(1)).replace("{last}", lm.group(2))


def transform_body(body: str, kind: str) -> tuple[str, int]:
    if "_rom_block" in body:
        return body, 0
    fm = FRAME_RE.search(body)
    if fm is None:
        return body, -1
    if kind == "small":
        required = ("uint32_t v9[4]", "v10[4]", "v11[12]", "v12[20]",
                    "v13[8]", "v14[4]", "v15[4]", "v16[8]")
        if not all(x in fm.group(0) for x in required):
            return body, -1
        replacement = SMALL_FRAME
        copy_old = ", 72, _frame.v9);"
        copy_new = ", 72, _frame._rom_block);"
    else:
        required = ("int v8", "int v9", "v10[272]", "v11[4]", "v12[8]",
                    "v13[4]", "v14[2]", "[14]")
        if not all(x in fm.group(0) for x in required):
            return body, -1
        replacement = large_frame(fm.group(0))
        if replacement is None:
            return body, -1
        copy_old = ", 320, &_frame.v8);"
        copy_new = ", 320, _frame._rom_block);"
    if copy_old not in body:
        return body, -1

    out = body[:fm.start()] + replacement + body[fm.end():]
    out = out.replace(copy_old, copy_new, 1)
    # Every remaining field use is a view into the copied block. The copy
    # destination itself was handled above and must stay the byte-block member.
    out = re.sub(r"\b_frame\.(?!_rom_block)", "_frame.f.", out)
    return out, 1


def apply_image(text: str, table: dict[int, str]) -> tuple[str, int, list[str]]:
    errors: list[str] = []
    count = 0
    for addr, kind in sorted(table.items(), reverse=True):
        span = function_span(text, addr)
        if span is None:
            errors.append(f"missing function at {addr:#x}")
            continue
        body = text[span[0]:span[1]]
        out, n = transform_body(body, kind)
        if n < 0:
            errors.append(f"frame pattern not found at {addr:#x}")
            continue
        if n:
            text = text[:span[0]] + out + text[span[1]:]
            count += n
    return text, count, errors


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    rc = 0
    for img, table in TARGETS.items():
        imgroot = REPO / "src" / img
        main_path = imgroot / "main.c"
        main_text = main_path.read_text(errors="replace")
        if any(function_span(main_text, addr) is not None for addr in table):
            paths = [main_path]
        else:
            paths = sorted((imgroot / "modules").glob("mod*.c"))
        count = 0
        errors = []
        seen = set()
        for path in paths:
            if not path.exists():
                continue
            text = path.read_text(errors="replace")
            subset = {addr: kind for addr, kind in table.items()
                      if function_span(text, addr) is not None}
            if not subset:
                continue
            seen.update(subset)
            out, n, errs = apply_image(text, subset)
            count += n
            errors.extend(errs)
            if n and not args.check:
                path.write_text(out)
        for addr in sorted(set(table) - seen):
            errors.append(f"missing function at {addr:#x}")
        print(f"[rom_copy_frames] {img}: {count} ROM-copy frame rewrite(s) "
              f"{'pending' if args.check else 'applied'}")
        for e in errors:
            print(f"[rom_copy_frames] ERROR: {img}: {e}", file=sys.stderr)
            rc = 1
        if count and args.check:
            rc = 1
    return rc


if __name__ == "__main__":
    sys.exit(main())
