#!/usr/bin/env python3
"""absolute_memory.py — Hex-Rays MEMORY[] is an absolute byte-addressed dword access.

Hex-Rays prints absolute memory as ``MEMORY[addr]``. Despite the square
brackets, the index is the byte address itself, not an element index and not
an offset into the reconstructed image: the callback thunk at 0x114a6c in
fmacfw_h is ``mov.w r3,#0x1fc; ldr r3,[r3]; bx r3``, so ``MEMORY[0x1FC]``
means ``*(volatile uint32_t *)0x1fc``. The tree represents that access as
``MEMD(addr)``, whose definition in ``aic8800d80_types.h`` is the volatile
absolute dword lvalue.

Compose initially keeps the raw ``MEMORY[]`` spelling and heals it only far
enough to compile. That leaves references to a linker-allocated ``MEMORY``
blob, so callback loads, null-page assert words, and MMIO/image-memory
absolute accesses all hit the wrong address. This rule mechanically rewrites
constant absolute references to the MEMD form before compile-directed
healing. It adds no body, renames nothing, is idempotent, and ``--check``
exits 1 when a rewrite is pending.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMAGES = ("fmacfw_u02", "fmacfw_h_u02", "fmacfwbt_u02", "lmacfw_rf_u02")

# Comments and literals are matched first and copied through unchanged. The
# constant forms are byte addresses, so preserve their numeric value while
# canonicalizing the spelling to hex. Legacy decimal MEMD(508) means decimal
# 508 (0x1fc), never the hex digit string 0x508.
NUM = r"(?:0[xX][0-9A-Fa-f]+|[0-9]+)"
TOKEN = re.compile(
    r'(?P<skip>/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\')'
    rf"|(?P<mem>\bMEMORY\s*\[\s*(?P<memnum>{NUM})\s*\])"
    rf"|(?P<memany>\bMEMORY\s*\[\s*(?P<anyexpr>[^\]\n]+?)\s*\])"
    rf"|(?P<memd>\bMEMD\s*\(\s*(?P<memdnum>{NUM})\s*\))",
    re.S,
)


def _addr(num: str) -> int:
    return int(num, 16) if num.lower().startswith("0x") else int(num, 10)


def _fmt(value: int) -> str:
    return "0" if value == 0 else f"0x{value:X}"


def rewrite(text: str) -> tuple[str, int, list[str]]:
    """Return (rewritten text, rewrite count, unsupported subscript forms)."""
    n = 0
    unsupported: list[str] = []

    def sub(m: re.Match) -> str:
        nonlocal n
        if m.group("skip"):
            return m.group(0)
        if m.group("mem"):
            n += 1
            return f"MEMD({_fmt(_addr(m.group('memnum')))})"
        if m.group("memd"):
            value = _addr(m.group("memdnum"))
            canonical = f"MEMD({_fmt(value)})"
            if m.group(0) != canonical:
                n += 1
            return canonical
        unsupported.append(m.group("anyexpr"))
        return m.group(0)

    return TOKEN.sub(sub, text), n, sorted(set(unsupported))


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    pending = 0
    for img in IMAGES:
        path = REPO / "src" / img / "main.c"
        out, n, unsupported = rewrite(path.read_text(errors="replace"))
        pending += n + len(unsupported)
        suffix = f", unsupported={len(unsupported)}" if unsupported else ""
        print(f"[absolute_memory] {img}: {n} sites {'pending' if args.check else 'rewritten'}{suffix}")
        if unsupported:
            print(f"[absolute_memory] {img}: unsupported subscripts: {unsupported[:8]}", file=sys.stderr)
        if n and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
