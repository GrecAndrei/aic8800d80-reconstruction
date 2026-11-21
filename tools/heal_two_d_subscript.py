#!/usr/bin/env python3
"""heal_two_d_subscript.py — re-apply the corrected 2D-subscript rule.

tools/convert_decompiled_to_functions.py turned Hex-Rays `SYM[i][k]` into the
address of the element instead of the element. The rule is fixed there
(`deref_two_d`); the raw Hex-Rays text of the affected function is not in the
tree and IDA is not always available, so this applies the same function to
what the old rule already produced: src/<image>/functions/*.c and the composed
src/<image>/main.c. Idempotent; `--check` exits 1 if anything is pending.
"""
import argparse
import sys
from pathlib import Path

from convert_decompiled_to_functions import deref_two_d

REPO = Path(__file__).resolve().parent.parent
IMAGES = ("fmacfw_u02", "fmacfw_h_u02", "fmacfwbt_u02", "lmacfw_rf_u02")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    pending = 0
    for img in IMAGES:
        root = REPO / "src" / img
        for path in [*sorted((root / "functions").glob("*.c")), root / "main.c"]:
            out, n = deref_two_d(path.read_text())
            if not n:
                continue
            pending += n
            print(f"[heal_two_d_subscript] {path.relative_to(REPO)}: {n} "
                  f"{'pending' if args.check else 'rewritten'}")
            if not args.check:
                path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
