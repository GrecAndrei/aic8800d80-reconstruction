#!/usr/bin/env python3
"""Trace a single function in the ORIGINAL firmware binary via Unicorn.

Loads the .bin at base 0x1200000, sets PC to the function entry, runs with
MMIO auto-paging, and emits a JSONL of every MMIO access (read/write +
address + value). This is the ground-truth trace we diff against the
reconstructed C body's smoke trace.

Usage:
  python3 tools/orig_binary_trace.py \\
      --bin inputs/firmware/lmacfw_rf_8800d80_u02.bin \\
      --function rf_bus_mark --address 0x121118c \\
      --max-insns 10000 --out /tmp/opencode/orig_trace.jsonl
"""
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

from unicorn import (
    UC_ARCH_ARM,
    UC_HOOK_CODE,
    UC_HOOK_MEM_READ,
    UC_HOOK_MEM_READ_UNMAPPED,
    UC_HOOK_MEM_WRITE,
    UC_HOOK_MEM_WRITE_UNMAPPED,
    UC_MODE_THUMB,
    Uc,
    UcError,
    UC_MEM_READ,
    UC_MEM_WRITE,
)
from unicorn.arm_const import UC_ARM_REG_LR, UC_ARM_REG_PC, UC_ARM_REG_SP

BASE = 0x1200000
PAGE_SIZE = 0x1000
STACK_SIZE = 0x8000
STACK_TOP = 0x20080000
SRAM_BASE = 0x20000000
SRAM_SIZE = 0x80000
RETURN_STOP = 0xDEADC000

# AIC8800D80 MMIO map (same as unicorn_smoke.py).
def is_mmio(addr: int) -> bool:
    return (
        (0x00000000 <= addr <= 0x001FFFFF)
        or (0x20000000 <= addr <= 0x3FFFFFFF)
        or (0x40000000 <= addr <= 0x5FFFFFFF)
        or (0xE0000000 <= addr <= 0xE00FFFFF)
    )


def parse_int(s: str) -> int:
    return int(s, 0)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--bin", required=True, type=Path, help="Raw firmware .bin file")
    ap.add_argument("--function", required=True, help="Function name (for labeling)")
    ap.add_argument("--address", required=True, help="Runtime address of function entry")
    ap.add_argument("--max-insns", type=int, default=10000)
    ap.add_argument("--out", required=True, type=Path)
    args = ap.parse_args()

    entry = parse_int(args.address)
    bin_data = args.bin.read_bytes()

    mu = Uc(UC_ARCH_ARM, UC_MODE_THUMB)

    # Map the firmware at BASE.
    bin_end = ((BASE + len(bin_data) + PAGE_SIZE - 1) // PAGE_SIZE) * PAGE_SIZE
    try:
        mu.mem_map(BASE, bin_end - BASE)
    except Exception as e:
        print(f"failed to map firmware at 0x{BASE:x}: {e}", file=sys.stderr)
        return 2
    mu.mem_write(BASE, bin_data)

    # Map SRAM (zero-initialized).
    try:
        mu.mem_map(SRAM_BASE, SRAM_SIZE)
    except Exception:
        pass
    mu.mem_write(SRAM_BASE, b"\x00" * SRAM_SIZE)

    # Map stack region.
    stack_base = STACK_TOP - STACK_SIZE
    try:
        mu.mem_map(stack_base, STACK_SIZE)
    except Exception:
        pass

    # Per-trace state.
    trace: list[dict] = []
    counts = {"insns": 0, "mmio_reads": 0, "mmio_writes": 0, "faults": 0}
    auto_mapped: set[int] = set()
    prev_addr: int | None = None
    stop_reason = {"value": "running"}

    def on_unmapped(uc, access, address, size, value, user_data):
        if is_mmio(int(address)):
            base = int(address) & ~(PAGE_SIZE - 1)
            if base not in auto_mapped:
                try:
                    uc.mem_map(base, PAGE_SIZE)
                    auto_mapped.add(base)
                except Exception:
                    pass
            # Default read returns 0 (we write 0 to the page).
            try:
                uc.mem_write(int(address) & ~3, b"\x00" * 4)
            except Exception:
                pass
            return True
        return False

    def on_code(uc, address, size, user_data):
        if int(address) == (RETURN_STOP | 1) or int(address) == RETURN_STOP:
            stop_reason["value"] = "returned"
            uc.emu_stop()
            return
        counts["insns"] += 1
        if counts["insns"] >= args.max_insns:
            stop_reason["value"] = "capped"
            uc.emu_stop()
            return
        prev_addr = int(address)

    def on_mem_access(uc, access, address, size, value, user_data):
        addr = int(address)
        if not is_mmio(addr):
            return
        if access == UC_MEM_READ:
            counts["mmio_reads"] += 1
            try:
                actual = int.from_bytes(bytes(uc.mem_read(addr, size)), "little")
            except Exception:
                actual = None
            trace.append({
                "insn": counts["insns"],
                "op": "read",
                "addr": hex(addr),
                "size": size,
                "value": hex(actual) if actual is not None else None,
            })
        else:
            counts["mmio_writes"] += 1
            trace.append({
                "insn": counts["insns"],
                "op": "write",
                "addr": hex(addr),
                "size": size,
                "value": hex(int(value)),
            })

    mu.hook_add(UC_HOOK_CODE, on_code)
    mu.hook_add(UC_HOOK_MEM_READ | UC_HOOK_MEM_WRITE, on_mem_access)
    mu.hook_add(UC_HOOK_MEM_READ_UNMAPPED | UC_HOOK_MEM_WRITE_UNMAPPED, on_unmapped)

    # Set up registers: SP, LR, PC.
    mu.reg_write(UC_ARM_REG_SP, STACK_TOP - 0x100)
    mu.reg_write(UC_ARM_REG_LR, RETURN_STOP | 1)
    mu.reg_write(UC_ARM_REG_PC, entry | 1)  # Thumb bit

    try:
        mu.emu_start(entry | 1, RETURN_STOP)
    except UcError as e:
        stop_reason["value"] = f"fault: {e}"
        counts["faults"] += 1

    # If emu_start returned without setting stop_reason, the function
    # executed a `pop {pc}` (or similar) that set PC to RETURN_STOP | 1
    # but Unicorn's `until` matched on a different form. Check the final PC.
    if stop_reason["value"] == "running":
        try:
            final_pc = mu.reg_read(UC_ARM_REG_PC)
            if final_pc in (RETURN_STOP, RETURN_STOP | 1):
                stop_reason["value"] = "returned"
            else:
                stop_reason["value"] = f"exited: pc=0x{final_pc:x}"
        except Exception:
            pass

    args.out.parent.mkdir(parents=True, exist_ok=True)
    with args.out.open("w", encoding="utf-8") as f:
        for row in trace:
            row["function"] = args.function
            row["bin"] = str(args.bin)
            row["address"] = args.address
            f.write(json.dumps(row, sort_keys=True) + "\n")

    print(json.dumps({
        "function": args.function,
        "bin": str(args.bin),
        "address": args.address,
        "instructions": counts["insns"],
        "mmio_reads": counts["mmio_reads"],
        "mmio_writes": counts["mmio_writes"],
        "faults": counts["faults"],
        "termination": stop_reason["value"],
        "auto_mapped_pages": len(auto_mapped),
        "trace_rows": len(trace),
        "trace_out": str(args.out),
    }, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
