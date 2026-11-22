#!/usr/bin/env python3
"""dword_compares.py — a `_DWORD` load compared with a signed local is a signed compare.

Hex-Rays' `_DWORD` has no sign of its own: `*(_DWORD *)p > 1u` is how it
prints an unsigned compare and `*(_DWORD *)a1 < v4`, with `int v4`, a signed
one (`cmp r2, r3; bge` in the binary). `src/` spells `_DWORD` as `uint32_t`,
which makes every such compare unsigned, so `0 < -1` holds and the branch goes
the other way. Per function, a relational compare whose one side is exactly a
`*(volatile uint32_t *)` load and whose other side is exactly a local or
parameter declared `int` gets `(int)` on the load. Compares against a literal,
an unsigned or 64-bit variable, or a larger expression are left alone.
Idempotent; `--check` exits 1 if anything is pending.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMAGES = ("fmacfw_u02", "fmacfw_h_u02", "fmacfwbt_u02", "lmacfw_rf_u02")
MARKER = re.compile(r"^// \S+ @ 0x[0-9a-fA-F]+[ \t]*$", re.M)
ATOM = r"(?:\w+|\((?:[^()\n]|\((?:[^()\n]|\([^()\n]*\))*\))*\))"
LOAD = r"\*\(volatile uint32_t \*\)" + ATOM
BEFORE, AFTER = r"(?<=[(|&] )", r"(?= \)| &&| \|\|)"
LOAD_FIRST = re.compile(BEFORE + "(" + LOAD + r") (<=?|>=?) ([A-Za-z_]\w*)" + AFTER)
LOAD_LAST = re.compile(BEFORE + r"([A-Za-z_]\w*) (<=?|>=?) (" + LOAD + ")" + AFTER)
LOCAL = re.compile(r"^\s+int ([A-Za-z_]\w*); //", re.M)
PARAM = re.compile(r"[(,]\s*int ([A-Za-z_]\w*)(?=[,)])")


def apply(text: str) -> tuple[str, int]:
    """Return (text, number of compares made signed)."""
    cuts = [m.start() for m in MARKER.finditer(text)] + [len(text)]
    out, total = [text[:cuts[0]]], 0
    for a, b in zip(cuts, cuts[1:]):
        body = text[a:b]
        if "*(volatile uint32_t *)" not in body:
            out.append(body)
            continue
        head = body.find("{")
        signed = set(LOCAL.findall(body)) | set(PARAM.findall(body[:head if head >= 0 else 0]))

        def first(m: re.Match) -> str:
            nonlocal total
            if m.group(3) not in signed:
                return m.group(0)
            total += 1
            return f"(int){m.group(1)} {m.group(2)} {m.group(3)}"

        def last(m: re.Match) -> str:
            nonlocal total
            if m.group(1) not in signed:
                return m.group(0)
            total += 1
            return f"{m.group(1)} {m.group(2)} (int){m.group(3)}"

        out.append(LOAD_LAST.sub(last, LOAD_FIRST.sub(first, body)))
    return "".join(out), total


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    pending = 0
    for img in IMAGES:
        path = REPO / "src" / img / "main.c"
        out, n = apply(path.read_text(errors="replace"))
        pending += n
        print(f"[dword_compares] {img}: {n} compares {'pending' if args.check else 'made signed'}")
        if n and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
