#!/usr/bin/env python3
"""volatile_pointees.py — qualify every scalar pointee in src/<img>/main.c volatile.

Hex-Rays lists the loads and stores the original code performs, but through
plain pointers (`*((uint32_t *)off_10DF68 + 7)`), so the C compiler is free to
hoist, merge, drop and reorder them. For memory-mapped registers that changes
behavior: `hw_poll_status` polls 0x4010d01c in a `while` loop that `-O2` turns
into one read and `b .`, and `crypto_hw_enable` writes 0x40344094 four times
where the `-O2` build writes it twice (docs/TRUTH_LANE_REVIEW_VERDICTS.md).

Which pointer reaches a register is not decidable from the text (addresses
come from literal pools and arguments), so the rule is uniform: every pointer
declaration and cast whose pointee is a scalar type gets a `volatile` pointee,
and so does the `MEMORY[]` absolute-address array. Each access the decompiler
wrote is then performed exactly once, in order. Nothing else is rewritten.

Not covered: direct reads of data symbols (`dword_xxx`), pointees reached
through a second indirection (`uint32_t **`: only the innermost is volatile),
and struct-typed pointees.

Runs after `fwstruct compose` and `tools/heal_composed.py`; idempotent.

    python3 tools/volatile_pointees.py            # rewrite the 4 images in place
    python3 tools/volatile_pointees.py --check    # exit 1 if a rewrite is pending
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMAGES = ("fmacfw_u02", "fmacfw_h_u02", "fmacfwbt_u02", "lmacfw_rf_u02")

SCALAR = (r"(?:(?:unsigned|signed)\s+)?"
          r"(?:u?int(?:8|16|32|64)_t|_BYTE|_WORD|_DWORD|_QWORD|__int(?:8|16|32|64)|"
          r"char|short|int|long(?:\s+long)?|float|double)")
# Comments and literals are matched first and copied through unchanged.
TOKEN = re.compile(
    r'(?P<skip>/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\')'
    r"|(?P<q>\b(?:volatile\s+)(?:const\s+)?" + SCALAR + r"\b(?=\s*\*))"
    r"|(?P<t>\b" + SCALAR + r"\b(?=\s*\*))"
    r"|(?P<m>\bextern\s+uint32_t\s+MEMORY\[\])",
    re.S)


def qualify(text: str) -> tuple[str, int]:
    """Return (rewritten text, number of pointees newly qualified)."""
    n = 0

    def sub(m: re.Match) -> str:
        nonlocal n
        if m.group("t"):
            n += 1
            return "volatile " + m.group("t")
        if m.group("m"):
            n += 1
            return "extern volatile uint32_t MEMORY[]"
        return m.group(0)

    return TOKEN.sub(sub, text), n


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true", help="report only; exit 1 if anything would change")
    args = ap.parse_args()
    pending = 0
    for img in IMAGES:
        path = REPO / "src" / img / "main.c"
        text = path.read_text()
        out, n = qualify(text)
        pending += n
        print(f"[volatile_pointees] {img}: {n} pointees {'pending' if args.check else 'qualified'}")
        if n and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
