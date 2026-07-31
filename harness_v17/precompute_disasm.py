#!/usr/bin/env python3
"""Precompute full linear disassembly for each firmware image with ONE r2
process per image, cached to harness_v17/disasm_cache/<img>.jsonl.

tools.py::disasm_at then serves lookups from this cache instead of spawning
an r2 process per function (which was the O(n)-process anti-pattern).

Cache line format:  <hex addr>\t<stripped r2 instruction line>
"""
import re, subprocess, sys, time
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
FW_DIR = REPO / "inputs/firmware"
CACHE_DIR = REPO / "harness_v17/disasm_cache"
CACHE_DIR.mkdir(parents=True, exist_ok=True)

IMAGES = [
    ("fmacfw_8800d80_u02", "fmacfw_8800d80_u02.bin"),
    ("fmacfw_8800d80_h_u02", "fmacfw_8800d80_h_u02.bin"),
    ("fmacfwbt_8800d80_u02", "fmacfwbt_8800d80_u02.bin"),
    ("lmacfw_rf_8800d80_u02", "lmacfw_rf_8800d80_u02.bin"),
]

_ANSI = re.compile(r'\x1b\[[0-9;]*m')


def main():
    for img, fname in IMAGES:
        out_path = CACHE_DIR / f"{img}.jsonl"
        if out_path.exists() and out_path.stat().st_size > 0:
            print(f"cache exists: {out_path.name} ({out_path.stat().st_size} bytes)", flush=True)
            continue
        bin_path = FW_DIR / fname
        size = bin_path.stat().st_size
        n_instr = size // 2 + 100
        t0 = time.time()
        cmd = ["r2", "-q", "-2", "-n", "-a", "arm", "-b", "16", "-m", "0x100000",
               "-c", f"s 0x100000; pd {n_instr}", str(bin_path)]
        try:
            result = subprocess.run(cmd, capture_output=True, text=True, timeout=600)
        except Exception as e:
            print(f"{img}: r2 failed: {e}", flush=True)
            continue
        n = 0
        with open(out_path, "w") as f:
            for line in result.stdout.split("\n"):
                line = _ANSI.sub("", line).strip()
                if not line.startswith("0x"):
                    continue
                addr = line.split()[0]
                if len(addr) < 10:
                    continue
                f.write(f"{addr}\t{line}\n")
                n += 1
        print(f"{img}: {n} instructions cached in {time.time()-t0:.1f}s -> {out_path.name}", flush=True)


if __name__ == "__main__":
    main()
