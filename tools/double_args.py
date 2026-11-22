#!/usr/bin/env python3
"""double_args.py — a double handed to a run-time ABI helper keeps both words.

Hex-Rays types a soft-float temporary by the register it first sees, so a
double returned in r0:r1 lands in `int v6; // r0` and is handed on as
`((int (*)())double_to_uint)(v6)`, where `double_to_uint` is the prototype
libmatch bound to `__aeabi_d2f`. The helper reads r0:r1 (ARM RTABI), the call
passes r0 only. Per function:

- a local declared `int`/`unsigned int` whose every assignment is a direct call
  of a function returning 64 bits (a composed `uint64_t` definition or a
  prototype bound to an RTABI helper that returns r0:r1), and whose address is
  never taken and which is otherwise read only as `HIDWORD(vN)`, is declared
  `uint64_t`;
- a one-argument call of a helper taking exactly one double (`__aeabi_d2f`,
  `d2iz`, `d2uiz`, `d2lz`, `d2ulz`) through `((int (*)())F)(vN)` with a 64-bit
  local `vN` becomes `((int (*)(uint64_t))F)(vN)`.

A local is widened only when it reaches such a call. Run after
`call_cast_returns.py` (it supplies the 64-bit prototypes). Idempotent;
`--check` exits 1 if anything is pending.
"""
import argparse
import re
import sys
from pathlib import Path

import call_cast_returns

REPO = Path(__file__).resolve().parent.parent
IMAGES = call_cast_returns.IMAGES
UNARY = frozenset("__aeabi_" + n for n in "d2f d2iz d2uiz d2lz d2ulz".split())
PROTO = re.compile(r"^(\w+(?: \w+)*)\s+(\w+)\s*\([^;{]*\)\s*__asm__\(\"__libmatch_(\w+)\"\);", re.M)
MARKER = re.compile(r"^// \S+ @ 0x[0-9a-fA-F]+[ \t]*$", re.M)
CALL = re.compile(r"\(\(int \(\*\)\(\)\)(\w+)\)\((\w+)\)")
DECL = r"^(\s+)(unsigned int|int|uint64_t|int64_t) %s;"


def _widenable(body: str, var: str, wide: set) -> bool:
    if re.search(r"&\s*%s\b" % var, body):
        return False
    writes = re.findall(r"\b%s\s*(?:[-+*/|&^%%]|<<|>>)?=(?!=)\s*([^;]*);" % var, body)
    if not writes or re.search(r"(\+\+|--)\s*%s\b|\b%s\s*(\+\+|--)" % (var, var), body):
        return False
    if len(writes) != len(re.findall(r"\b%s = " % var, body)):
        return False
    rest = re.sub(DECL % var, "", body, flags=re.M)
    rest = re.sub(r"\b%s = " % var, "", rest)
    rest = re.sub(r"\(\(int \(\*\)\(\)\)\w+\)\(%s\)" % var, "", rest)
    rest = re.sub(r"HIDWORD\(%s\)" % var, "", rest)
    if re.search(r"\b%s\b" % var, rest):
        return False
    for rhs in writes:
        m = re.match(r"(?:\(\((?:u?int64_t) \(\*\)\([^()]*\)\)(\w+)\)|(\w+))\(", rhs)
        if not m or (m.group(1) or m.group(2)) not in wide:
            return False
    return True


def apply(text: str) -> tuple[str, int]:
    """Return (text, number of call sites given the helper's double argument)."""
    wide = {m.group(3) for m in call_cast_returns.DEFINITION.finditer(text) if m.group(1) == m.group(3)}
    unary = set()
    for m in PROTO.finditer(text):
        if m.group(3) in UNARY:
            unary.add(m.group(2))
        if m.group(1) in ("uint64_t", "int64_t") and m.group(3) in call_cast_returns.RTABI_64:
            wide.add(m.group(2))
    if not unary:
        return text, 0
    cuts = [m.start() for m in MARKER.finditer(text)] + [len(text)]
    out, total = [text[:cuts[0]]], 0
    for a, b in zip(cuts, cuts[1:]):
        body = text[a:b]
        sites = {m.group(2) for m in CALL.finditer(body) if m.group(1) in unary}
        ok = set()
        for var in sites:
            d = re.search(DECL % re.escape(var), body, re.M)
            if not d:
                continue
            if d.group(2) in ("uint64_t", "int64_t"):
                ok.add(var)
            elif _widenable(body, var, wide):
                body = body[:d.start()] + d.group(1) + "uint64_t " + var + ";" + body[d.end():]
                ok.add(var)
        if ok:
            def sub(m: re.Match) -> str:
                nonlocal total
                if m.group(1) not in unary or m.group(2) not in ok:
                    return m.group(0)
                total += 1
                return f"((int (*)(uint64_t)){m.group(1)})({m.group(2)})"
            body = CALL.sub(sub, body)
        out.append(body)
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
        print(f"[double_args] {img}: {n} calls {'pending' if args.check else 'given a double'}")
        if n and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
