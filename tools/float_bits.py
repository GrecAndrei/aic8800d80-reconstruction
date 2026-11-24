#!/usr/bin/env python3
"""float_bits.py — a soft-float value moves through a `float` local as bits.

The firmware is soft-float: a `float` is a 32-bit pattern in r0. Hex-Rays
types such a local `float`, assigns it the result of a conversion helper it
calls through an `int` cast (`v5 = ((int (*)(...))double_to_int)(v4)`) and
passes it on as `LODWORD(v5)`. In C the first is a numeric int-to-float
conversion and the second a float-to-int one, which round the pattern's low
bits away. Per function, for a local declared `float`, an assignment from an
`((int (*)(...))` cast call is wrapped in Hex-Rays' own bit-copy
`COERCE_FLOAT(...)` and `LODWORD(local)` becomes `COERCE_UNSIGNED_INT(local)`.
Float arithmetic and other calls are left alone. The same representation rule
applies to `float` parameters: Hex-Rays `LODWORD(aN)`/`SLODWORD(aN)` are raw
register-bit uses, not numeric conversions. Idempotent; `--check` exits 1 if
anything is pending.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMAGES = ("fmacfw_u02", "fmacfw_h_u02", "fmacfwbt_u02", "lmacfw_rf_u02")
MARKER = re.compile(r"^// \S+ @ 0x[0-9a-fA-F]+[ \t]*$", re.M)
LOCAL = re.compile(r"^\s+float ([A-Za-z_]\w*); //", re.M)
SIGNATURE = re.compile(r"^float\s+[A-Za-z_]\w*\(([^\n]*)\)\s*\{", re.M)
FLOAT_PARAM = re.compile(r"^float\s+([A-Za-z_]\w*)$")
SLOW = re.compile(r"\bSLODWORD\(([A-Za-z_]\w*)\)")
ASSIGN = re.compile(r"^(\s+)([A-Za-z_]\w*) = (\(\(int \(\*\)\([^()\n]*\)\)\w+\)\(.*\));$", re.M)
LOW = re.compile(r"\bLODWORD\(([A-Za-z_]\w*)\)")


def apply(text: str) -> tuple[str, int]:
    """Return (text, number of conversions made bit copies)."""
    cuts = [m.start() for m in MARKER.finditer(text)] + [len(text)]
    out, total = [text[:cuts[0]]], 0
    for a, b in zip(cuts, cuts[1:]):
        body = text[a:b]
        floats = set(LOCAL.findall(body))
        sig = SIGNATURE.search(body)
        if sig:
            for part in sig.group(1).split(","):
                pm = FLOAT_PARAM.match(part.strip())
                if pm:
                    floats.add(pm.group(1))
        if not floats:
            out.append(body)
            continue

        def assign(m: re.Match) -> str:
            nonlocal total
            if m.group(2) not in floats:
                return m.group(0)
            total += 1
            return f"{m.group(1)}{m.group(2)} = COERCE_FLOAT({m.group(3)});"

        def low(m: re.Match) -> str:
            nonlocal total
            if m.group(1) not in floats:
                return m.group(0)
            total += 1
            return f"COERCE_UNSIGNED_INT({m.group(1)})"

        def slow(m: re.Match) -> str:
            nonlocal total
            if m.group(1) not in floats:
                return m.group(0)
            total += 1
            return f"COERCE_INT({m.group(1)})"

        body = LOW.sub(low, ASSIGN.sub(assign, body))
        out.append(SLOW.sub(slow, body))
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
        print(f"[float_bits] {img}: {n} conversions {'pending' if args.check else 'made bit copies'}")
        if n and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
