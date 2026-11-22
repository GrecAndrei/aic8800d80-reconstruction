#!/usr/bin/env python3
"""call_cast_returns.py — a call wrapped in `((int (*)())F)` keeps F's 64-bit result.

`tools/heal_composed.py` routes a call whose argument count does not fit the
prototype through `((int (*)())F)(...)`. For a callee defined as returning
`uint64_t` (the soft-float helpers: a double in r0:r1) that cast drops r1, so
`v8 = ((int (*)())parse_data_field)(v7, HIDWORD(v7))` stores a sign-extended
low word in the 64-bit `v8`. This rule gives the cast the return type the
composed definition has, for 64-bit returns only: a pointer, an unsigned or a
void callee read through `int` is the same register. The run-time ABI helpers
that return a double or a 64-bit integer (`__aeabi_dmul`, `__aeabi_f2d`, ...:
fixed by the ARM RTABI) are treated the same, called by their own name or
through a prototype libmatch bound to them (`int double_add_1(...)
__asm__("__libmatch___aeabi_dmul")`, or `unsigned int`, becomes `uint64_t`). Idempotent; `--check`
exits 1 if anything is pending.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMAGES = ("fmacfw_u02", "fmacfw_h_u02", "fmacfwbt_u02", "lmacfw_rf_u02")
DEFINITION = re.compile(r"^// (\S+) @ 0x[0-9a-fA-F]+[ \t]*\n(uint64_t|int64_t)\s+(\w+)\s*\(", re.M)
# ARM RTABI helpers whose result is r0:r1.
RTABI_64 = frozenset("__aeabi_" + n for n in (
    "dadd dsub drsub dmul ddiv f2d i2d ui2d l2d ul2d d2lz d2ulz f2lz f2ulz lmul llsl llsr lasr").split())
BOUND = re.compile(r"^(?:unsigned int|int)(\s+(\w+)\s*\([^;{]*\)\s*__asm__\(\"__libmatch_(\w+)\"\);)", re.M)
CAST = re.compile(r"\(\(int( \(\s*\*\s*\)\s*\([^()]*\)\)\s*)(\w+)\)\(")


def widen(text: str) -> tuple[str, int]:
    """Return (text, number of casts and bound prototypes given their callee's 64-bit return type)."""
    wide = {m.group(3): m.group(2) for m in DEFINITION.finditer(text) if m.group(1) == m.group(3)}
    wide.update((name, "uint64_t") for name in RTABI_64)
    n = 0

    def bound(m: re.Match) -> str:
        nonlocal n
        if m.group(3) not in RTABI_64:
            return m.group(0)
        n += 1
        wide[m.group(2)] = "uint64_t"
        return "uint64_t" + m.group(1)

    text = BOUND.sub(bound, text)
    for m in re.finditer(r"^uint64_t\s+(\w+)\s*\([^;{]*\)\s*__asm__\(\"__libmatch_(\w+)\"\);", text, re.M):
        if m.group(2) in RTABI_64:
            wide[m.group(1)] = "uint64_t"

    def sub(m: re.Match) -> str:
        nonlocal n
        ret = wide.get(m.group(2))
        if ret is None:
            return m.group(0)
        n += 1
        return f"(({ret}{m.group(1)}{m.group(2)})("

    return CAST.sub(sub, text), n


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    pending = 0
    for img in IMAGES:
        path = REPO / "src" / img / "main.c"
        out, n = widen(path.read_text(errors="replace"))
        pending += n
        print(f"[call_cast_returns] {img}: {n} casts {'pending' if args.check else 'widened'}")
        if n and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
