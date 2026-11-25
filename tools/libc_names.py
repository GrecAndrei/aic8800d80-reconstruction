#!/usr/bin/env python3
"""libc_names.py — machine-verified ownership of libc symbol names.

The LLM naming pass shifted several library routine names by one slot:
word-scan `strchr` bodies are named `memset`, `memcmp` bodies are named
`memcpy`, `strlen`/`strncasecmp` bodies are named `memmove_N`/`memset_N`,
and genuinely firmware-internal routines (MMIO/descriptor locks, TLV
scanners, table transforms) carry exact libc names like `memcpy`/`memmove`.

That is not a cosmetic problem. Even in freestanding mode the compiler must
be able to emit calls to memset/memcpy/memmove/memcmp for structure copies
and loop idioms, and those calls bind to whatever object owns the symbol.
In three of four images the `memset` symbol was owned by a strchr body, so
any compiler-emitted fill corrupted memory instead of filling it.

Every rename here is machine-verified (capstone disassembly of the original
bytes; see docs/LIBC_NAMES.md for the evidence table). Functions whose true
semantics are unknown firmware-internal logic are reverted to their neutral
`sub_<addr>` name rather than given another invented meaning.

Runs after libmatch apply (the libmatch asm labels are independent of the C
symbol names). Idempotent; --check reports pending renames.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent

IMAGES = {
    "fmacfw_h_u02": "fmacfw_8800d80_h_u02",
    "fmacfw_u02": "fmacfw_8800d80_u02",
    "fmacfwbt_u02": "fmacfwbt_8800d80_u02",
    "lmacfw_rf_u02": "lmacfw_rf_8800d80_u02",
}

# (image, analysis address) -> correct name, machine-verified.
# Evidence summary (capstone disassembly of original firmware bytes):
#   0x100200 all images: byte-identical splat-fill memset, 160 bytes.
#   strchr copies (206 bytes, byte-identical across images): ands r1,#0xff,
#     splat + simultaneous NUL/c word detection with 0x01010101/0x80808080.
#   memcmp copies (96 bytes): word-wise compare, byte tail returns first diff.
#   memmove copies (216 bytes): overlap test + backwards destructive path.
#   strlen copies (220 bytes): ldrd/uadd8/sel zero-lane scan, rev/clz count.
#   strncasecmp copies: ctype table + 0x20 case folding, bounded loop.
#   bt 0x14380c / rf 0x1282e8: byte-identical to the h/u 308-byte memcpy.
#   rf 0x103d60: hardware sequence generator, not libc rand.
RENAMES = {
    ("fmacfw_h_u02", 0x100200): "memset",
    ("fmacfw_h_u02", 0x143878): "strchr",
    ("fmacfw_h_u02", 0x143630): "memcpy",
    ("fmacfw_h_u02", 0x11101C): "sub_11101c",
    ("fmacfw_h_u02", 0x143C3C): "strcpy",
    ("fmacfw_h_u02", 0x143764): "memmove",
    ("fmacfw_h_u02", 0x110EDC): "sub_110edc",

    ("fmacfw_u02", 0x143D7C): "strcpy",
    ("fmacfw_u02", 0x143E40): "strlen",
    ("fmacfw_u02", 0x1439B8): "strchr",
    ("fmacfw_u02", 0x143F1C): "strncasecmp",
    ("fmacfw_u02", 0x10957C): "sub_10957c",

    ("fmacfwbt_u02", 0x100200): "memset",
    ("fmacfwbt_u02", 0x102D10): "sub_102d10",
    ("fmacfwbt_u02", 0x1437AC): "memcmp",
    ("fmacfwbt_u02", 0x14380C): "memcpy",
    ("fmacfwbt_u02", 0x143E1C): "strcpy",
    ("fmacfwbt_u02", 0x1007A4): "sub_1007a4",
    ("fmacfwbt_u02", 0x1096D0): "sub_1096d0",
    ("fmacfwbt_u02", 0x12DD88): "sub_12dd88",
    ("fmacfwbt_u02", 0x12DE48): "sub_12de48",
    ("fmacfwbt_u02", 0x143940): "memmove",
    ("fmacfwbt_u02", 0x143F00): "strlen",
    ("fmacfwbt_u02", 0x143A54): "strchr",
    ("fmacfwbt_u02", 0x143FDC): "strncasecmp",
    ("fmacfwbt_u02", 0x1093D4): "sub_1093d4",

    ("lmacfw_rf_u02", 0x100200): "memset",
    ("lmacfw_rf_u02", 0x128288): "memcmp",
    ("lmacfw_rf_u02", 0x1282E8): "memcpy",
    ("lmacfw_rf_u02", 0x12841C): "strchr",
    ("lmacfw_rf_u02", 0x103D60): "sub_103d60",
}

MARKER_RE = re.compile(r"(?m)^// (\w+) @ 0x([0-9a-fA-F]+)")


SEGMENT_RE = re.compile(
    r"(?P<block>/\*.*?\*/)"           # block comments: never touched
    r"|(?P<marker>^// \w+ @ 0x[0-9a-fA-F]+[^\n]*$)"  # unit marker: rename the name token
    r"|(?P<line>//[^\n]*)"             # other line comments: never touched
    r"|(?P<str>\"(?:[^\"\\\\]|\\.)*\")"         # string literals: never touched
    , re.S | re.M)


def rename_in_text(text: str, mapping: dict[str, str]) -> tuple[str, int]:
    """Single-pass word-boundary rename of call sites, declarations, definitions
    and unit-marker names. Single pass so chained renames (memcpy -> sub_X,
    memcpy_aligned -> memcpy) never double-apply. Comments (other than the
    marker name), strings and libmatch documentation are never rewritten."""
    if not mapping:
        return text, 0
    pat = re.compile(r"\b(" + "|".join(re.escape(k) for k in sorted(mapping, key=len, reverse=True)) + r")\b")
    count = 0

    def sub(m: re.Match) -> str:
        nonlocal count
        count += 1
        return mapping[m.group(1)]

    out: list[str] = []
    pos = 0
    for m in SEGMENT_RE.finditer(text):
        if m.start() > pos:
            out.append(pat.sub(sub, text[pos:m.start()]))
        seg = m.group(0)
        if m.group("marker") is not None:
            out.append(pat.sub(sub, seg))
        else:
            out.append(seg)
        pos = m.end()
    out.append(pat.sub(sub, text[pos:]))
    return "".join(out), count


def apply_image(text: str, short: str) -> tuple[str, int, list[str]]:
    rows = {int(a, 16): n for n, a in MARKER_RE.findall(text)}
    names = {}
    for a, n in rows.items():
        names.setdefault(n, set()).add(a)
    mapping: dict[str, str] = {}
    problems: list[str] = []
    for (img, addr), new in sorted(RENAMES.items()):
        if img != short:
            continue
        old = rows.get(addr)
        if old is None:
            problems.append(f"{short} {addr:#x}: no composed function at address")
            continue
        if old == new:
            continue
        mapping[old] = new
    # collision check: a target name still owned by an address that is not
    # itself being renamed away is a hard error
    for old, new in sorted(mapping.items()):
        owners = {a for a, n in rows.items() if n == new}
        colliding = {a for a in owners if rows.get(a) not in mapping}
        if colliding:
            problems.append(f"{short}: target name {new} already owned by "
                            + ",".join(f"{a:#x}" for a in sorted(colliding)))
    if problems:
        return text, 0, problems
    out, n = rename_in_text(text, mapping)
    return out, n, []


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    rc = 0
    for short in IMAGES:
        path = REPO / "src" / short / "main.c"
        text = path.read_text(errors="replace")
        out, n, problems = apply_image(text, short)
        if problems:
            for p in problems:
                print(f"[libc_names] ERROR {p}", file=sys.stderr)
            rc = 1
            continue
        print(f"[libc_names] {short}: {n} name references {'pending' if args.check else 'rewritten'}")
        if n and args.check:
            rc = 1
        elif n and not args.check:
            path.write_text(out)
    return rc


if __name__ == "__main__":
    sys.exit(main())
