#!/usr/bin/env python3
"""Pre-scan firmware binaries for functions that touch MMIO addresses.

Uses Capstone to find LDR PC-relative instructions that load from the
literal pool containing MMIO-range values. Scans all functions from the
IDA export. Much faster than running every function through Unicorn.

Usage:
  python3 tools/find_mmio_functions.py \\
      --bin inputs/firmware/lmacfw_rf_8800d80_u02.bin \\
      --base 0x1200000 \\
      --functions extraction_out/ida_export_live/lmacfw_rf_8800d80_u02.bin.functions.jsonl \\
      --out /tmp/opencode/mmio_fns_lmacfw_rf.jsonl

Output: JSONL of {name, address, mmio_addrs_found, insn_count, has_mmio}
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

try:
    from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_MCLASS
except ImportError:
    print("capstone not installed. Install with: pip install capstone", file=sys.stderr)
    sys.exit(1)


def is_mmio(addr: int) -> bool:
    return (
        (0x40000000 <= addr <= 0x5FFFFFFF)
        or (0xE0000000 <= addr <= 0xE00FFFFF)
        or (0x00001000 <= addr <= 0x001FFFFF)
    )


def parse_int(s: str) -> int:
    return int(s, 0)


def scan_function(md, bin_data: bytes, file_off: int, name: str, max_insns: int = 200) -> dict:
    """Disassemble a function and find MMIO-referencing LDR instructions."""
    size = min(len(bin_data) - file_off, 1024)
    try:
        insns = list(md.disasm(bin_data[file_off:file_off + size], file_off))
    except Exception:
        return {"name": name, "address": hex(file_off), "mmio_addrs_found": [], "mmio_count": 0, "insn_count": 0, "has_mmio": False}

    mmio_refs: list[int] = []
    for insn in insns:
        if insn.mnemonic != 'ldr' or '[pc' not in insn.op_str.lower():
            continue
        try:
            m = re.search(r'#(0x[0-9a-fA-F]+)', insn.op_str.split(',')[-1])
            if not m:
                continue
            offset = parse_int(m.group(1))
            load_addr = ((insn.address + 4) & ~3) + offset
            if load_addr + 4 > len(bin_data):
                continue
            val = int.from_bytes(bin_data[load_addr:load_addr + 4], 'little')
            if is_mmio(val):
                mmio_refs.append(val)
        except (ValueError, IndexError):
            pass

        if len(mmio_refs) > 100:
            break

    unique = sorted(set(mmio_refs))
    return {
        "name": name,
        "address": hex(file_off),
        "mmio_addrs_found": [hex(a) for a in unique],
        "mmio_count": len(unique),
        "insn_count": len(insns),
        "has_mmio": len(unique) > 0,
    }


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--bin", required=True, type=Path)
    ap.add_argument("--base", default="0x1200000")
    ap.add_argument("--functions", required=True, type=Path)
    ap.add_argument("--out", required=True, type=Path)
    ap.add_argument("--max-insns", type=int, default=200)
    args = ap.parse_args()

    base = parse_int(args.base)
    bin_data = args.bin.read_bytes()
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_MCLASS)

    functions = []
    with args.functions.open("r") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            d = json.loads(line)
            name = d.get("name", d.get("function", "unknown"))
            addr_str = d.get("address", d.get("start_ea", ""))
            if not addr_str:
                continue
            addr = parse_int(addr_str)
            if addr >= base:
                file_off = addr - base
            elif addr < len(bin_data):
                file_off = addr
            else:
                continue
            functions.append({"name": name, "runtime_addr": addr, "file_off": file_off})

    print(f"Loaded {len(functions)} functions", file=sys.stderr)

    mmio_fns = 0
    with args.out.open("w") as f:
        for fn in functions:
            off = fn["file_off"]
            if off >= len(bin_data):
                continue
            result = scan_function(md, bin_data, off, fn["name"], args.max_insns)
            result["runtime_address"] = hex(fn["runtime_addr"])
            f.write(json.dumps(result, sort_keys=True) + "\n")
            if result["has_mmio"]:
                mmio_fns += 1

    print(f"Summary: {mmio_fns}/{len(functions)} touch MMIO, output: {args.out}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
