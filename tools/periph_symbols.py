#!/usr/bin/env python3
"""periph_symbols.py — a data symbol named after a peripheral address is that register.

Hex-Rays names an unnamed global after its address, so `dword_40504080` is the
word at 0x40504080. `fwstruct datasgen` materializes every such symbol as a
variable of the image, which is right for image data and wrong for an address
in the Cortex-M peripheral region (0x40000000-0x5FFFFFFF): the composed
`((volatile uint32_t *)(uintptr_t)&dword_40504080)[i]` then reads and writes a
linker-placed RAM word instead of the register block. This rule replaces the
address-of such a symbol with the address its name states. It adds no body.
Idempotent; `--check` exits 1 if anything is pending.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMAGES = ("fmacfw_u02", "fmacfw_h_u02", "fmacfwbt_u02", "lmacfw_rf_u02")
PERIPH_LO, PERIPH_HI = 0x40000000, 0x5FFFFFFF
ADDR_OF = re.compile(r"\(uintptr_t\)&(?:dword|word|byte|unk)_([0-9A-F]{8})\b")


def absolute(text: str) -> tuple[str, int]:
    """Return (text, number of address-of sites rewritten)."""
    def sub(m: re.Match) -> str:
        if PERIPH_LO <= int(m.group(1), 16) <= PERIPH_HI:
            return f"(uintptr_t)0x{m.group(1)}u"
        return m.group(0)
    out = ADDR_OF.sub(sub, text)
    return out, sum(PERIPH_LO <= int(a, 16) <= PERIPH_HI for a in ADDR_OF.findall(text))


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    pending = 0
    for img in IMAGES:
        path = REPO / "src" / img / "main.c"
        out, n = absolute(path.read_text(errors="replace"))
        pending += n
        print(f"[periph_symbols] {img}: {n} sites {'pending' if args.check else 'rewritten'}")
        if n and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
