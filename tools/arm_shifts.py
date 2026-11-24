#!/usr/bin/env python3
"""arm_shifts.py — mask Hex-Rays mod-256 ARM shift counts to avoid C UB.

On ARM Thumb-2, variable shift instructions (`lsr.w`, `asrs`) use only the low
8 bits of the shift-count register (`count & 0xFF`). Hex-Rays exploits this
when simplifying IEEE-754 exponent shifts in `round()` (`double_exp_check`),
emitting e.g. `0xFFFFFFFF >> ((HIDWORD(a1) >> 20) - 19)` (for `exp - 1043`)
and `0x80000 >> ((HIDWORD(a1) >> 20) + 1)` (for `exp - 1023`). In C those
counts are >= 1024 (>= 32), which is undefined behavior and lets GCC -O2
delete the rounding body.

Masking the shift count with `& 0xFF` (`>> (((HIDWORD(a1) >> 20) - 19) & 0xFF)`)
restores the exact ARM shift count (0..31 / 0..19) for both positive and
negative doubles (since the sign bit at bit 11 of `HIDWORD >> 20` is 0 mod 256).
Idempotent; `--check` exits 1 if anything is pending.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMAGES = ("fmacfw_u02", "fmacfw_h_u02", "fmacfwbt_u02", "lmacfw_rf_u02")

# Matches `>> ((HIDWORD(x) >> 20) +/- N)` when not already masked with `& 0xFF`.
MOD256_SHIFT = re.compile(
    r"(>>\s*)\((\(HIDWORD\([^()]+\)\s*>>\s*20\)\s*[+-]\s*\d+)\)"
)


def apply(text: str) -> tuple[str, int]:
    """Return (text, number of shift counts masked with & 0xFF)."""
    return MOD256_SHIFT.subn(r"\1((\2) & 0xFF)", text)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    pending = 0
    for img in IMAGES:
        path = REPO / "src" / img / "main.c"
        out, n = apply(path.read_text(errors="replace"))
        pending += n
        print(f"[arm_shifts] {img}: {n} shifts {'pending' if args.check else 'masked'}")
        if n and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
