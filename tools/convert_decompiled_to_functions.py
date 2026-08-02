#!/usr/bin/env python3
"""Convert a Hex-Rays decompiled function file into the src/<img>/functions/ format.

The per-function files in ``src/<img>/functions/`` (the compose input) differ
from the raw decompiled tree ``harness_v19/decompiled/<img>/`` by:
  1. a fixed header block (stdint/stddef/stdarg/inttypes includes + the byte
     macros LOBYTE/HIBYTE/LOWORD/HIWORD/LODWORD/HIDWORD),
  2. ``extern`` declarations for every data symbol the body references,
  3. Hex-Rays MSVC types rewritten to C99 (width-based, unsigned — matching
     the existing files: ``_BYTE``→uint8_t, ``_DWORD``→uint32_t, ``__int64``
     →uint64_t, ``bool``→int, ``__fastcall`` dropped, ...),
  4. the ``// NAME @ 0xADDR, size N bytes`` marker line.

Deterministic, no LLM. Usage:
  convert_decompiled_to_functions.py <decompiled.c> <out_dir> [name]

Writes <out_dir>/<addr>_<name>.c with the marker name = <name> (default: the
original sub_ name from the source marker). Only data symbols are emitted as
externs (no function forward decls — compose emits those).
"""
import re
import sys
from pathlib import Path

HEADER = """#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

"""

# Ordered so longer/prefix types win over shorter (e.g. unsigned __int8 before
# __int8). All width-based -> unsigned C99, matching the existing tree.
TYPE_RE = [
    (re.compile(r"\bunsigned\s+__int8\b"), "uint8_t"),
    (re.compile(r"\bunsigned\s+__int16\b"), "uint16_t"),
    (re.compile(r"\bunsigned\s+__int32\b"), "uint32_t"),
    (re.compile(r"\bunsigned\s+__int64\b"), "uint64_t"),
    (re.compile(r"\bsigned\s+__int64\b"), "int64_t"),
    (re.compile(r"\bsigned\s+__int32\b"), "int32_t"),
    (re.compile(r"\bsigned\s+__int16\b"), "int16_t"),
    (re.compile(r"\bsigned\s+__int8\b"), "int8_t"),
    (re.compile(r"\b__int64\b"), "uint64_t"),
    (re.compile(r"\b__int32\b"), "uint32_t"),
    (re.compile(r"\b__int16\b"), "uint16_t"),
    (re.compile(r"\b__int8\b"), "uint8_t"),
    (re.compile(r"\b_QWORD\b"), "uint64_t"),
    (re.compile(r"\b_DWORD\b"), "uint32_t"),
    (re.compile(r"\b_WORD\b"), "uint16_t"),
    (re.compile(r"\b_BYTE\b"), "uint8_t"),
    (re.compile(r"\bbool\b"), "int"),
]

MARKER_RE = re.compile(r"^// (\w+) @ (0x[0-9a-fA-F]+), size (\d+) bytes")
DATA_SYM_RE = re.compile(r"\b(dword|word|byte|unk|off|qword|algn|flt|dbl|jpt|loc)_([0-9A-Fa-f]{4,8})\b")
# Hex-Rays 2D data-symbol subscript SYM[i][k] — the scalar-subscript heal only
# rewrites the first [i], leaving a double subscript. Byte-deref the element.
TWO_D_SUB = re.compile(
    r"\b(off_|dword_|word_|byte_|unk_|qword_|algn_|flt_|dbl_|jpt_|loc_)[0-9A-Fa-f]{4,8}"
    r"\[[^\[\]]+\]\[[^\[\]]+\]")
DATA_KIND_TYPE = {
    "dword": "uint32_t", "off": "uint32_t", "unk": "uint32_t", "algn": "uint32_t",
    "qword": "uint64_t", "jpt": "uint32_t", "loc": "uint32_t",
    "word": "uint16_t", "byte": "uint8_t",
    "flt": "float", "dbl": "double",
}


def convert_to_c99(text: str) -> str:
    for rx, rep in TYPE_RE:
        text = rx.sub(rep, text)
    text = re.sub(r"\b__fastcall\b", "", text)
    text = re.sub(r"\b__noreturn\b", "", text)
    # JUMPOUT(<hw-base literal>) -> analysis space (the header stub ignores the
    # arg, but the literal must stay consistent with the 0x100000-space tree).
    def jout(m):
        v = int(m.group(1), 16)
        if 0x100000 <= v < 0x200000:
            v -= 0x20000
        return f"JUMPOUT(0x{v:X})"
    text = re.sub(r"\bJUMPOUT\(0x([0-9A-Fa-f]+)\)", jout, text)
    # MSVC __asm { MSR.W MSP, R0 } -> GCC inline asm (the register globals
    # _R0/_R2/etc. live in aic8800d80_types.h).
    text = re.sub(r"__asm\s*\{\s*MSR\.W\s+MSP,\s*([A-Za-z_]\w*)\s*\}",
                  r'__asm volatile("msr msp, %0" : : "r"(\1) : "memory");', text)
    # 2D data-symbol subscript -> byte deref of the element (the heal's
    # scalar-subscript rewrite leaves the second [k] dangling otherwise).
    def two_d(m):
        # SYM[expr][k] -> ((uint8_t *)(uintptr_t)SYM[expr] + (k))
        tok = m.group(0)
        sym = re.match(r"(off_|dword_|word_|byte_|unk_|qword_|algn_|flt_|dbl_|jpt_|loc_)[0-9A-Fa-f]{4,8}", tok)
        sym_s = sym.group(0)
        rest = tok[len(sym_s):]
        i, k = rest[1:-1].split("][", 1)
        return f"((uint8_t *)(uintptr_t){sym_s}[{i}] + ({k}))"
    text = TWO_D_SUB.sub(two_d, text)
    return text


def build(src_text: str, out_dir: Path, name: str | None = None) -> Path | None:
    m = MARKER_RE.search(src_text)
    if not m:
        return None
    orig_name, addr_hex, size = m.group(1), m.group(2), m.group(3)
    if name is None:
        name = orig_name
    # Strip the decompiled marker line + any trailing Doc line.
    lines = src_text.splitlines()
    i = 0
    while i < len(lines) and (lines[i].startswith("//") or not lines[i].strip()):
        i += 1
    body = "\n".join(lines[i:]).strip()
    body = convert_to_c99(body)
    # Data symbols referenced by the body -> extern decls (unique, address order).
    syms = {}
    for kind, val in DATA_SYM_RE.findall(body):
        v = int(val, 16)
        if kind == "loc" or v < 0x100000:
            continue  # code-label #define lives in data.c; sub-0x100000 are not data syms
        syms.setdefault(f"{kind}_{val}", DATA_KIND_TYPE.get(kind, "uint32_t"))
    externs = "".join(f"extern {t} {s};\n" for s, t in sorted(syms.items()))
    out = HEADER
    if externs:
        out += "\n" + externs + "\n"
    out += f"// {name} @ {addr_hex}, size {size} bytes\n"
    out += body + "\n"
    addr = int(addr_hex, 16)
    out_path = out_dir / f"{addr:x}_{name}.c"
    out_path.write_text(out)
    return out_path


if __name__ == "__main__":
    src_path, out_dir_arg = Path(sys.argv[1]), Path(sys.argv[2])
    name = sys.argv[3] if len(sys.argv) > 3 else None
    out_dir_arg.mkdir(parents=True, exist_ok=True)
    p = build(src_path.read_text(), out_dir_arg, name)
    print(f"wrote {p}" if p else "no marker found")
