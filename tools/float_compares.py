#!/usr/bin/env python3
"""float_compares.py — preserve ARM VFP NaN-exits in backward float loop checks.

When the original firmware loops backward while `v >= x` (`vcmpe.f32 sA, sB;
vmrs apsr_nzcv, fpscr; bge loop`), IEEE-754 unordered (`NaN`) sets `N=0, V=1`
so `bge` (`N == V`) does NOT branch and the loop breaks immediately. Hex-Rays
inverts the loop condition into `if ( v < x ) break;` (or `goto`), which under
IEEE-754 evaluates `NaN` comparisons as false and fails to exit the loop.

For any function declaring `float` locals/parameters, rewriting a loop-exit
`if ( lhs < rhs ) break;` or `goto <label>;` on two `float` variables into
`if ( !(lhs >= rhs) )` restores exact ARM VFP semantics on ordered and `NaN`
inputs alike. Idempotent; `--check` exits 1 if anything is pending.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMAGES = ("fmacfw_u02", "fmacfw_h_u02", "fmacfwbt_u02", "lmacfw_rf_u02")
MARKER = re.compile(r"^// \S+ @ 0x[0-9a-fA-F]+[ \t]*$", re.M)
LOCAL = re.compile(r"^\s+float ([A-Za-z_]\w*); //", re.M)
PARAM = re.compile(r"[(,]\s*float ([A-Za-z_]\w*)(?=[,)])")
EXIT_LT = re.compile(
    r"(if \(\s*)([A-Za-z_]\w*)\s*<\s*([A-Za-z_]\w*)(\s*\)\s*\n[ \t]*(?:break|goto \w+);)"
)


def apply(text: str) -> tuple[str, int]:
    """Return (text, number of float loop-exit compares rewritten to !(a >= b))."""
    cuts = [m.start() for m in MARKER.finditer(text)] + [len(text)]
    out, total = [text[:cuts[0]]], 0
    for a, b in zip(cuts, cuts[1:]):
        body = text[a:b]
        if "float " not in body:
            out.append(body)
            continue
        head = body.find("{")
        floats = set(LOCAL.findall(body)) | set(PARAM.findall(body[:head if head >= 0 else 0]))
        if not floats:
            out.append(body)
            continue

        def sub(m: re.Match) -> str:
            nonlocal total
            if m.group(2) not in floats or m.group(3) not in floats:
                return m.group(0)
            total += 1
            return f"{m.group(1)}!({m.group(2)} >= {m.group(3)}){m.group(4)}"

        out.append(EXIT_LT.sub(sub, body))
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
        print(f"[float_compares] {img}: {n} compares {'pending' if args.check else 'rewritten'}")
        if n and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
