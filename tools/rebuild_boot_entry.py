#!/usr/bin/env python3
"""Mechanically rebuild the true reset-entry function (file 0x1a8).

The old v19 scan treated file 0x100-0x1a7 (header/padding bytes) as the start
of ``start``. The IVT reset vector enters at file 0x1a8. This tool validates
that invariant directly from the firmware bytes, optionally refreshes the
hardware-base Hex-Rays decompile through IDA, and converts the decompilation
into ``src/<image>/functions/1001a8_start.c``. No hand-written C is involved.

Usage:
  python3 tools/rebuild_boot_entry.py              # convert existing decompiles
  python3 tools/rebuild_boot_entry.py --ida        # refresh decompiles first
"""
from __future__ import annotations

import argparse
import os
import subprocess
import sys
from pathlib import Path

import convert_decompiled_to_functions as conv

REPO = Path(__file__).resolve().parent.parent
IMAGES = {
    "fmacfw_8800d80_h_u02": "fmacfw_h_u02",
    "fmacfw_8800d80_u02": "fmacfw_u02",
    "fmacfwbt_8800d80_u02": "fmacfwbt_u02",
    "lmacfw_rf_8800d80_u02": "lmacfw_rf_u02",
}
RESET_OFF = 0x1A8
RESET_END = 0x200
# ldr r3,[pc,#0x40]; ldr r3,[r3]; movw r2,#0xc241 — the CPUID-check prologue.
RESET_SIGNATURE = bytes.fromhex("104b1b684cf24122")
IDAT = Path(os.environ.get("IDAT", Path.home() / "ida-pro-9.3" / "idat"))


def validate_firmware_entries() -> None:
    bad = []
    for long in IMAGES:
        blob = (REPO / "inputs" / "firmware" / f"{long}.bin").read_bytes()
        if not blob[RESET_OFF:RESET_OFF + len(RESET_SIGNATURE)] == RESET_SIGNATURE:
            bad.append(long)
        if int.from_bytes(blob[4:8], "little") != (0x120000 + RESET_OFF + 1):
            bad.append(f"{long}: ivt-reset")
    if bad:
        raise SystemExit("reset-entry signature mismatch: " + ", ".join(bad))


def refresh_decompile(long: str) -> None:
    img = f"{long}_bin"
    idb = REPO / "harness_v19" / "idb" / f"{long}_hw.i64"
    script = REPO / "harness_v19" / "scripts" / "ida_decompile_reset_entry.py"
    log = REPO / "harness_v19" / "log" / f"{long}_reset_entry.log"
    log.parent.mkdir(parents=True, exist_ok=True)
    if not idb.is_file():
        raise SystemExit(f"missing hardware-base IDB: {idb}")
    env = dict(os.environ, DIMG=img, V19_ROOT=str(REPO / "harness_v19"))
    cmd = [str(IDAT), "-A", f"-L{log}", f"-S{script}", str(idb)]
    r = subprocess.run(cmd, cwd=REPO, env=env, capture_output=True, text=True)
    if r.returncode:
        raise SystemExit(f"IDA reset-entry decompile failed for {long}:\n{r.stdout}\n{r.stderr}")


def convert_one(long: str, short: str) -> Path:
    src = REPO / "harness_v19" / "decompiled" / f"{long}_bin" / "1001a8_start.c"
    out_dir = REPO / "src" / short / "functions"
    if not src.is_file():
        raise SystemExit(f"missing {src}; run with --ida after building the hardware-base IDB")
    out = conv.build(src.read_text(errors="replace"), out_dir, "start")
    if out is None:
        raise SystemExit(f"conversion produced no output for {src}")
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--ida", action="store_true", help="refresh the Hex-Rays decompile through IDA first")
    args = ap.parse_args()
    validate_firmware_entries()
    for long, short in IMAGES.items():
        if args.ida:
            refresh_decompile(long)
        print(f"{short}: {convert_one(long, short)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
