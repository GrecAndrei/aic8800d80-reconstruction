#!/usr/bin/env python3
"""stack_frames.py — keep stack locals at the offsets the binary gives them.

Hex-Rays prints every stack local with its frame slot (`// [sp+68h] [bp-4h]`)
and sometimes splits one on-stack table into separate locals, then reaches
them through the address of a neighbour: `&v59[4 * v26]` minus 26 words reads
`v33..v58`, and `while ( v7 != &v11 )` ends where the byte array before `v11`
ends. That only works if the compiler lays the locals out as the original
frame did, which it does not.

For a function with at least one address-taken (`BYREF`) stack local, this
rule turns the run of stack-local declarations into one packed struct `_frame`
whose members sit at their printed `sp` offsets (gaps padded), and rewrites
the uses to `_frame.<name>`. Line count is unchanged. A function is left alone
when a slot's type has no known size, slots overlap, or the stack locals are
not one consecutive run. Idempotent; `--check` exits 1 if anything is pending.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMAGES = ("fmacfw_u02", "fmacfw_h_u02", "fmacfwbt_u02", "lmacfw_rf_u02")
MARKER = re.compile(r"^// \S+ @ 0x[0-9a-fA-F]+\s*$")
SLOT = re.compile(r"^  (?P<decl>[^;/]+); // \[sp\+(?P<sp>[0-9A-Fa-f]+)h\] \[bp[+-][0-9A-Fa-f]+h\](?P<byref> BYREF)?\s*$")
NAME = re.compile(r"(?P<type>.*?)(?P<name>\b[A-Za-z_]\w*)(?P<dims>(?:\[\d+\])*)$")
SIZES = {"char": 1, "signed char": 1, "unsigned char": 1, "uint8_t": 1, "int8_t": 1, "bool": 1,
         "int16_t": 2, "uint16_t": 2, "short": 2, "unsigned short": 2,
         "int": 4, "unsigned int": 4, "unsigned": 4, "int32_t": 4, "uint32_t": 4, "float": 4,
         "long": 4, "unsigned long": 4,
         "int64_t": 8, "uint64_t": 8, "double": 8, "long long": 8, "unsigned long long": 8}
DONE = "} _frame;"


def slot_size(decl: str) -> tuple[str, int] | None:
    """Return (name, bytes) of one declaration, or None when the size is unknown."""
    fn = re.match(r"^.*\(\s*\*\s*(\w+)\s*\)\s*\(.*\)$", decl)
    if fn:
        return fn.group(1), 4
    m = NAME.match(decl.strip())
    if not m:
        return None
    base = re.sub(r"\b(volatile|const)\b", " ", m.group("type"))
    size = 4 if "*" in base else SIZES.get(" ".join(base.split()))
    if size is None:
        return None
    for d in re.findall(r"\[(\d+)\]", m.group("dims")):
        size *= int(d)
    return m.group("name"), size


def frame_function(lines: list[str]) -> list[str] | None:
    """Return the function's lines with its stack locals in one frame struct."""
    if any(DONE in ln for ln in lines):
        return None
    sig = lines[1] if len(lines) > 1 else ""
    params = set(re.findall(r"\b([A-Za-z_]\w*)\b(?=\s*[,)])", sig.split("{", 1)[0]))
    idx = [i for i, ln in enumerate(lines) if SLOT.match(ln)]
    if len(idx) < 2 or idx[-1] - idx[0] != len(idx) - 1 or idx[-1] + 1 >= len(lines):
        return None
    slots = []
    for i in idx:
        m = SLOT.match(lines[i])
        ns = slot_size(m.group("decl"))
        if ns is None or ns[0] in params:
            return None
        slots.append((int(m.group("sp"), 16), ns[1], ns[0], i, m))
    if not any(s[4].group("byref") for s in slots) or slots != sorted(slots, key=lambda s: s[0]):
        return None
    groups: list[list[tuple[int, int, str, int, re.Match]]] = []
    for s in slots:
        if groups and groups[-1][0][0] == s[0]:
            groups[-1].append(s)
        else:
            groups.append([s])
    out, end = list(lines), groups[0][0][0]
    for n, grp in enumerate(groups):
        sp = grp[0][0]
        if sp < end:
            return None
        pad = f"char _pad{n}[{sp - end}]; " if sp > end else ""
        head = "struct __attribute__((packed)) { " if n == 0 else ""
        if len(grp) == 1:
            i = grp[0][3]
            out[i] = f"  {head}{pad}{lines[i][2:]}"
        else:
            first_i = grp[0][3]
            out[first_i] = f"  {head}{pad}union {{ {lines[first_i][2:]}"
            last_i, last_m = grp[-1][3], grp[-1][4]
            semi = lines[last_i].index(";")
            out[last_i] = f"{lines[last_i][:semi + 1]} }};{lines[last_i][semi + 1:]}"
        end = sp + max(s[1] for s in grp)
    names = re.compile(r"(?<![\w.>])(" + "|".join(re.escape(s[2]) for s in slots) + r")\b")
    last = idx[-1]
    for i in range(last + 1, len(out)):
        out[i] = names.sub(r"_frame.\1", out[i])
    out[last + 1] = f"  {DONE}{out[last + 1]}" if out[last + 1].strip() else f"  {DONE}\n"
    return out


def apply(text: str) -> tuple[str, int]:
    """Return (text, number of functions given a frame struct)."""
    lines = text.splitlines(keepends=True)
    starts = [i for i, ln in enumerate(lines) if MARKER.match(ln)]
    n = 0
    for a, b in reversed(list(zip(starts, starts[1:] + [len(lines)]))):
        new = frame_function(lines[a:b])
        if new is not None:
            lines[a:b] = new
            n += 1
    return "".join(lines), n


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    pending = 0
    for img in IMAGES:
        path = REPO / "src" / img / "main.c"
        out, n = apply(path.read_text(errors="replace"))
        pending += n
        print(f"[stack_frames] {img}: {n} functions {'pending' if args.check else 'framed'}")
        if n and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
