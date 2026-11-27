#!/usr/bin/env python3
"""rf_table_address_arithmetic.py — RF table selectors are address arithmetic, not data loads.

Hex-Rays rendered the machine's byte-address computation as a dword-array
dereference with half the required element scale. In fmacfw_h the machine
proven sequence at hardware 0x125e60-0x125e76 is:

  ldr r0, =0x16eb70
  mov.w r3, #0x4f0
  mul r3, r3, r5
  add.w r1, r3, #0x490
  adds r3, #0x10
  add r1, r0
  add r0, r3
  bl copy_helper

Thus the two helper arguments are base + 0x4f0*a5 + 0x10/0x490. The composed
clones instead load `(uint32_t *)base[158*a5 + 2/146]`, which both dereferences
table bytes and scales by 4 rather than the machine's 8-byte pair stride. In
the linked reconstruction that produced the bogus source value 0x82a33e90 and
zeroed RF register tables; the original copies the real table at base+0x10.

The same instruction pattern and wrong Hex-Rays shape occur in all four clone
families. Rewrite to explicit byte-address arithmetic. This preserves the
original fixed-memory-layout semantics of the firmware; it does not claim a
general data-relocation model.
"""
import argparse
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent

TARGETS = {
    "fmacfw_h_u02": ("sdio_irq_mask_enable", "off_1060C4"),
    "fmacfw_u02": ("bt_control_set", "off_1061DC"),
    "fmacfwbt_u02": ("radio_irq_setup", "off_106034"),
    "lmacfw_rf_u02": ("rf_reg_init", "off_105BB4"),
}


def replacement(helper: str, sym: str) -> str:
    base = f"(uintptr_t){sym}"
    return (f"  {helper}((int)({base} + 0x4F0u * a5 + 0x10u), "
            f"(int)({base} + 0x4F0u * a5 + 0x490u));")


def original(helper: str, sym: str) -> str:
    arr = f"((volatile uint32_t *)(uintptr_t){sym})"
    return f"  {helper}((int){arr}[158 * a5 + 2], (int){arr}[158 * a5 + 146]);"


def transform(text: str, helper: str, sym: str) -> tuple[str, int, str | None]:
    old = original(helper, sym)
    new = replacement(helper, sym)
    n_old = text.count(old)
    n_new = text.count(new)
    if n_old == 1:
        return text.replace(old, new, 1), 1, None
    if n_old == 0 and n_new == 1:
        return text, 0, None
    return text, 0, f"expected one site for {helper}/{sym}, got old={n_old} new={n_new}"


def apply_one(root: Path, short: str, helper: str, sym: str, check: bool) -> tuple[int, str | None]:
    imgroot = root / short
    paths = [imgroot / "main.c"] + sorted((imgroot / "modules").glob("mod*.c"))
    saw = False
    total = 0
    for path in paths:
        if not path.exists():
            continue
        text = path.read_text(errors="replace")
        old = original(helper, sym)
        new = replacement(helper, sym)
        if old not in text and new not in text:
            continue
        saw = True
        out, n, err = transform(text, helper, sym)
        if err:
            return total, err
        total += n
        if n and not check:
            path.write_text(out)
    if not saw:
        return total, f"{sym} not present in {short}"
    return total, None


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--src", default="", help="override src root (testing)")
    args = ap.parse_args()
    root = Path(args.src) if args.src else REPO / "src"
    rc = 0
    for short, (helper, sym) in TARGETS.items():
        n, err = apply_one(root, short, helper, sym, args.check)
        if err:
            print(f"[rf_table_addr] ERROR {short}: {err}", file=sys.stderr)
            rc = 1
            continue
        print(f"[rf_table_addr] {short}: {n} rewrite(s) {'pending' if args.check else 'applied/fixed-point'}")
        if n and args.check:
            rc = 1
    return rc


if __name__ == "__main__":
    sys.exit(main())
