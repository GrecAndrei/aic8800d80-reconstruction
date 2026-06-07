#!/usr/bin/env python3
"""Capture MMIO-address fingerprints from the original binary via Unicorn.

For each (binary, function_name, address) tuple, runs the function in
Unicorn and records the ordered sequence of MMIO addresses touched
(reads and writes). Outputs a JSONL where each line is a function with
its fingerprint.

Usage:
  python3 tools/behavioral_fingerprint.py \\
      --bin inputs/firmware/lmacfw_rf_8800d80_u02.bin \\
      --targets targets.jsonl \\
      --out /tmp/opencode/fingerprints.jsonl \\
      [--max-insns 10000] [--max-fns 5]

targets.jsonl format (one JSON per line):
  {"image": "lmacfw_rf_8800d80_u02.bin", "name": "rf_bus_mark", "address": "0x121118c"}
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
    UC_HOOK_MEM_WRITE,
    UC_HOOK_MEM_READ_UNMAPPED,
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


def is_mmio(addr: int) -> bool:
    return (
        (0x00000000 <= addr <= 0x001FFFFF)
        or (0x20000000 <= addr <= 0x3FFFFFFF)
        or (0x40000000 <= addr <= 0x5FFFFFFF)
        or (0xE0000000 <= addr <= 0xE00FFFFF)
    )


def parse_int(s: str) -> int:
    return int(s, 0)


def trace_function(bin_data: bytes, entry: int, max_insns: int, function_name: str = "", binary_path: str = "") -> dict:
    entry = entry & ~1

    mu = Uc(UC_ARCH_ARM, UC_MODE_THUMB)

    bin_end = ((BASE + len(bin_data) + PAGE_SIZE - 1) // PAGE_SIZE) * PAGE_SIZE
    try:
        mu.mem_map(BASE, bin_end - BASE)
    except Exception:
        pass
    mu.mem_write(BASE, bin_data)

    try:
        mu.mem_map(SRAM_BASE, SRAM_SIZE)
    except Exception:
        pass

    stack_base = STACK_TOP - STACK_SIZE
    try:
        mu.mem_map(stack_base, STACK_SIZE)
    except Exception:
        pass

    mmio_seq: list[str] = []
    unique_addrs: set[int] = set()
    counts = {"insns": 0, "mmio_reads": 0, "mmio_writes": 0, "faults": 0}
    auto_mapped: set[int] = set()
    stop_reason = {"value": "running"}

    def on_unmapped(uc, access, address, size, value, user_data):
        addr = int(address)
        if is_mmio(addr):
            base = addr & ~(PAGE_SIZE - 1)
            if base not in auto_mapped:
                try:
                    uc.mem_map(base, PAGE_SIZE)
                    auto_mapped.add(base)
                except Exception:
                    pass
            try:
                uc.mem_write(addr & ~3, b"\x00" * 4)
            except Exception:
                pass
            return True
        return False

    def on_code(uc, address, size, user_data):
        pc = int(address)
        if pc == (RETURN_STOP | 1) or pc == RETURN_STOP:
            stop_reason["value"] = "returned"
            uc.emu_stop()
            return
        counts["insns"] += 1
        if counts["insns"] >= max_insns:
            stop_reason["value"] = "capped"
            uc.emu_stop()
            return

    def on_mem_access(uc, access, address, size, value, user_data):
        addr = int(address)
        if not is_mmio(addr):
            return
        op = "read" if access == UC_MEM_READ else "write"
        counts["mmio_reads" if op == "read" else "mmio_writes"] += 1
        unique_addrs.add(addr)
        if op == "write":
            mmio_seq.append(f"W:{hex(addr)}:{hex(int(value))}")
        else:
            mmio_seq.append(f"R:{hex(addr)}")

    mu.hook_add(UC_HOOK_CODE, on_code)
    mu.hook_add(UC_HOOK_MEM_READ | UC_HOOK_MEM_WRITE, on_mem_access)
    mu.hook_add(UC_HOOK_MEM_READ_UNMAPPED | UC_HOOK_MEM_WRITE_UNMAPPED, on_unmapped)

    mu.reg_write(UC_ARM_REG_SP, STACK_TOP - 0x100)
    mu.reg_write(UC_ARM_REG_LR, RETURN_STOP | 1)
    mu.reg_write(UC_ARM_REG_PC, entry | 1)

    try:
        mu.emu_start(entry | 1, RETURN_STOP)
    except UcError as e:
        stop_reason["value"] = f"fault: {e}"
        counts["faults"] += 1

    if stop_reason["value"] == "running":
        try:
            final_pc = mu.reg_read(UC_ARM_REG_PC)
            if final_pc in (RETURN_STOP, RETURN_STOP | 1):
                stop_reason["value"] = "returned"
            else:
                stop_reason["value"] = f"exited: pc=0x{final_pc:x}"
        except Exception:
            pass

    return {
        "function": function_name,
        "binary": binary_path,
        "address": hex(entry),
        "instructions": counts["insns"],
        "mmio_reads": counts["mmio_reads"],
        "mmio_writes": counts["mmio_writes"],
        "unique_mmio_addrs": sorted(hex(a) for a in unique_addrs),
        "mmio_sequence": mmio_seq,
        "termination": stop_reason["value"],
        "faults": counts["faults"],
    }


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--bin", required=True, type=Path, help="Firmware .bin file")
    ap.add_argument("--targets", required=True, type=Path, help="JSONL with target functions")
    ap.add_argument("--out", required=True, type=Path, help="Output JSONL")
    ap.add_argument("--max-insns", type=int, default=10000)
    ap.add_argument("--max-fns", type=int, default=0, help="Max functions to trace (0 = all)")
    args = ap.parse_args()

    bin_data = args.bin.read_bytes()

    targets = []
    with args.targets.open("r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            targets.append(json.loads(line))

    if args.max_fns and len(targets) > args.max_fns:
        targets = targets[:args.max_fns]

    seen_images = set()
    for t in targets:
        seen_images.add(t.get("image", ""))

    if not targets:
        print(json.dumps({"error": "no targets", "bin": str(args.bin), "targets_file": str(args.targets)}))
        return 1

    args.out.parent.mkdir(parents=True, exist_ok=True)
    results = []
    with args.out.open("w", encoding="utf-8") as f:
        for t in targets:
            name = t.get("name", t.get("function", "unknown"))
            addr_str = t.get("address", "")
            if not addr_str:
                continue
            entry = parse_int(addr_str)
            print(f"Tracing {name} @ {addr_str} ...", file=sys.stderr)

            result = trace_function(bin_data, entry, args.max_insns,
                                    function_name=name, binary_path=str(args.bin))
            result["image"] = t.get("image", str(args.bin))
            results.append(result)
            f.write(json.dumps(result, sort_keys=True) + "\n")
            f.flush()

    report = {
        "bin": str(args.bin),
        "traced": len(results),
        "returned": sum(1 for r in results if r["termination"] == "returned"),
        "capped": sum(1 for r in results if r["termination"] == "capped"),
        "faulted": sum(1 for r in results if r["faults"] > 0),
        "out": str(args.out),
    }
    print(json.dumps(report, indent=2), file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
