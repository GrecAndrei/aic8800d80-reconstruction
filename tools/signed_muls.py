#!/usr/bin/env python3
"""signed_muls.py — preserve ARM `smull` signed 32x32->64 multiplications.

Hex-Rays emits signed 32x32->64 magic divisions (`smull`) as
`dword_XXXXXX * (__int64)expr` (without an `(unsigned int)` cast on either
factor, unlike `umull`). Rewriting `__int64` to `uint64_t` plus unsigned
`uint32_t` `dword_*` definitions in `data.c` turned every such `smull` into
unsigned 64-bit multiplication (`uint32_t * uint64_t`), producing wrong upper
32 bits whenever `dword_XXXXXX >= 0x80000000` (e.g. `dword_1038D4` in
`crypto_init`) or `expr < 0`.

Similarly, `pow2f` (`(v9 & 0x7FFFFF) * (uint64_t)(int)_frame.v11[...]`) is an
ARM `smull` whose `(int)` second factor was zero-extended by `(uint64_t)`.

Casting both factors via `(int32_t)lhs * (int64_t)(int32_t)(rhs)` restores
exact `smull` 64-bit product semantics. Idempotent; `--check` exits 1 if
anything is pending.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMAGES = ("fmacfw_u02", "fmacfw_h_u02", "fmacfwbt_u02", "lmacfw_rf_u02")

DWORD_MUL = re.compile(
    r"(\((?:unsigned\s+int|int32_t|int)\)\s*)?\b(dword_[0-9A-Fa-f]+)\s*\*\s*\(uint64_t\)"
)
MASK_INT_MUL = re.compile(
    r"(\(\s*\w+\s*&\s*0x[0-9A-Fa-f]+\s*\))\s*\*\s*\(uint64_t\)\s*\(int\)"
)


def _scan_rhs_end(text: str, pos: int) -> int:
    """Return end index of one C unary/postfix expression starting at `pos`."""
    n = len(text)
    while pos < n and text[pos].isspace():
        pos += 1
    while pos < n and text[pos] in "*+-~!":
        pos += 1
        while pos < n and text[pos].isspace():
            pos += 1
    if pos < n and text[pos] == "(":
        depth = 0
        j = pos
        while j < n:
            if text[j] == "(":
                depth += 1
            elif text[j] == ")":
                depth -= 1
                if depth == 0:
                    j += 1
                    break
            j += 1
        k = j
        while k < n and text[k].isspace():
            k += 1
        if k < n and (text[k].isalnum() or text[k] in "_*("):
            return _scan_rhs_end(text, k)
        return j
    while pos < n and (text[pos].isalnum() or text[pos] in "_."):
        pos += 1
    while pos < n and text[pos] in "([":
        open_c, close_c = text[pos], (")" if text[pos] == "(" else "]")
        depth = 0
        while pos < n:
            if text[pos] == open_c:
                depth += 1
            elif text[pos] == close_c:
                depth -= 1
                if depth == 0:
                    pos += 1
                    break
            pos += 1
    return pos


def apply(text: str) -> tuple[str, int]:
    """Return (text, number of signed 64-bit multiplies restored)."""
    out, last, total = [], 0, 0
    for m in DWORD_MUL.finditer(text):
        if m.group(1):
            continue
        rhs_start = m.end()
        rhs_end = _scan_rhs_end(text, rhs_start)
        rhs = text[rhs_start:rhs_end].strip()
        if rhs.startswith("(unsigned"):
            continue
        wrapped = rhs if (rhs.startswith("(") and rhs.endswith(")")) else f"({rhs})"
        out.append(text[last:m.start()])
        out.append(f"(int32_t){m.group(2)} * (int64_t)(int32_t){wrapped}")
        last = rhs_end
        total += 1
    out.append(text[last:])
    text = "".join(out)

    out2, last2 = [], 0
    for m in MASK_INT_MUL.finditer(text):
        rhs_start = m.end()
        rhs_end = _scan_rhs_end(text, rhs_start)
        rhs = text[rhs_start:rhs_end].strip()
        wrapped = rhs if (rhs.startswith("(") and rhs.endswith(")")) else f"({rhs})"
        out2.append(text[last2:m.start()])
        out2.append(f"(int64_t)(int32_t){m.group(1)} * (int64_t)(int32_t){wrapped}")
        last2 = rhs_end
        total += 1
    out2.append(text[last2:])
    return "".join(out2), total


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    pending = 0
    for img in IMAGES:
        path = REPO / "src" / img / "main.c"
        out, n = apply(path.read_text(errors="replace"))
        pending += n
        print(f"[signed_muls] {img}: {n} multiplies {'pending' if args.check else 'fixed'}")
        if n and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
