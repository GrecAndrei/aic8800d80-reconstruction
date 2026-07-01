#!/usr/bin/env python3
"""arm_heal.py — Iterative ARM GCC fixup.

Strategy: trust disassembly-derived FORWARD DECLS, normalize call sites.
"""
import re, subprocess, sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
DEVICE_C = REPO / "harness_v19/device_c"
ARM_GCC = "/tmp/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-gcc"
INC = REPO / "harness_v19/inc"


def count_errors(src):
    r = subprocess.run(
        [ARM_GCC, "-fsyntax-only", "-mthumb", "-mcpu=cortex-r5",
         "-I", str(INC), "-w", str(src)],
        capture_output=True, text=True, timeout=60)
    return len([l for l in r.stderr.splitlines() if "error:" in l])


def parse_arg_list(s):
    if not s or s.strip() in ("void", ""): return []
    depth, cur, args = 0, "", []
    for c in s:
        if c in "([{": depth += 1; cur += c
        elif c in ")]}": depth -= 1; cur += c
        elif c == "," and depth == 0: args.append(cur.strip()); cur = ""
        else: cur += c
    if cur.strip(): args.append(cur.strip())
    return args


def heal(src, max_passes=8):
    for n in range(max_passes):
        c = count_errors(src)
        if c == 0:
            print(f"  Pass {n}: 0 errors.")
            return
        print(f"  Pass {n}: {c} errors")
        # Try no-op for now
        return
    return


def main():
    images = sys.argv[1:] if len(sys.argv) > 1 else [
        "fmacfw_8800d80_h_u02_bin", "fmacfw_8800d80_u02_bin",
        "fmacfwbt_8800d80_u02_bin", "lmacfw_rf_8800d80_u02_bin"]
    for img in images:
        src = DEVICE_C / f"{img}.c"
        if not src.exists():
            continue
        print(f"=== {img} ===")
        heal(src)


if __name__ == "__main__":
    main()
