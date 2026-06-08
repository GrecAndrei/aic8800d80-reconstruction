#!/usr/bin/env python3
"""Trace a single function in the RECONSTRUCTED C body via Unicorn.

Same engine as orig_binary_trace.py, but compiles the C body to ARM
Thumb ELF and loads the function symbol. Emits a JSONL of every MMIO
access (read/write + address + value). This is what we diff against the
original binary's trace.

Usage:
  python3 tools/reconstructed_trace.py \\
      --source /tmp/opencode/smoke/rf_bus_mark.c \\
      --function rf_bus_mark \\
      --image lmacfw_rf \\
      --stub-fn sub_120EBCC ... \\
      --max-insns 10000 --out /tmp/opencode/recon_traces/rf_bus_mark.jsonl
"""
from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

from elftools.elf.elffile import ELFFile
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


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--source", required=True, type=Path, help="C source file")
    ap.add_argument("--function", required=True, help="Function name")
    ap.add_argument("--image", default="", help="Image label (for output)")
    ap.add_argument("--max-insns", type=int, default=10000)
    ap.add_argument("--out", required=True, type=Path)
    ap.add_argument("--stub-fn", action="append", default=[],
                    help="Add a no-op macro stub for a sub_XX helper (repeatable)")
    ap.add_argument("--address", default="", help="Optional runtime address (for labeling)")
    args = ap.parse_args()

    if not args.source.is_file():
        raise SystemExit(f"source not found: {args.source}")

    with tempfile.TemporaryDirectory(prefix="recon_trace_") as td:
        td_path = Path(td)

        # Build wrapper with macro stubs (so any sub_X call expands to 0).
        if args.stub_fn:
            stubs = "\n".join(f"#define {name}(...) 0" for name in args.stub_fn)
            wrapper = td_path / f"{args.source.stem}_wrapped.c"
            wrapper.write_text(f"{stubs}\n\n#include \"{args.source.resolve()}\"\n", encoding="utf-8")
            src = wrapper
        else:
            src = args.source

        # Compile to ARMv7-M ELF with clang + lld.
        elf = td_path / "out.elf"
        cmd = [
            "clang",
            "--target=armv7m-none-eabi",
            "-mcpu=cortex-m3",
            "-mthumb",
            "-ffreestanding",
            "-fno-builtin",
            "-fdata-sections",
            "-ffunction-sections",
            "-fuse-ld=lld",
            "-O0",
            str(src),
            "-nostdlib",
            "-Wl,--unresolved-symbols=ignore-all",
            "-Wl,--image-base=0x1000",
            f"-Wl,-e,{args.function}",
            "-o", str(elf),
        ]
        try:
            subprocess.run(cmd, check=True, capture_output=True)
        except subprocess.CalledProcessError as e:
            print("compile failed:", file=sys.stderr)
            print(e.stderr.decode(errors="replace")[-1000:], file=sys.stderr)
            return 2

        # Load function symbol from ELF.
        with elf.open("rb") as f:
            elf_obj = ELFFile(f)
            segments: list[tuple[int, bytes, int]] = []
            for seg in elf_obj.iter_segments():
                if seg["p_type"] != "PT_LOAD":
                    continue
                vaddr = int(seg["p_vaddr"])
                memsz = int(seg["p_memsz"])
                if memsz == 0:
                    continue
                segments.append((vaddr, seg.data(), memsz))
            symtab = elf_obj.get_section_by_name(".symtab")
            fn_addr = fn_size = None
            for sym in symtab.iter_symbols():
                if sym.name != args.function:
                    continue
                if sym.entry["st_info"]["type"] != "STT_FUNC":
                    continue
                shndx = sym.entry["st_shndx"]
                if not isinstance(shndx, int):
                    continue
                section = elf_obj.get_section(shndx)
                if section is None:
                    continue
                fn_addr = int(sym.entry["st_value"]) & ~1
                fn_size = int(sym.entry["st_size"])
                break
            if fn_addr is None:
                print(f"function {args.function!r} not in symbol table", file=sys.stderr)
                return 3

    # Unicorn engine.
    mu = Uc(UC_ARCH_ARM, UC_MODE_THUMB)

    # Map all PT_LOAD segments and SRAM.
    highest = 0
    for vaddr, data, memsz in segments:
        base = vaddr & ~(PAGE_SIZE - 1)
        end = ((vaddr + memsz + PAGE_SIZE - 1) // PAGE_SIZE) * PAGE_SIZE
        highest = max(highest, vaddr + memsz)
        try:
            mu.mem_map(base, end - base)
        except Exception:
            pass
    for vaddr, data, memsz in segments:
        if data:
            try:
                mu.mem_write(vaddr, data)
            except Exception:
                pass
    try:
        mu.mem_map(SRAM_BASE, SRAM_SIZE)
    except Exception:
        pass
    mu.mem_write(SRAM_BASE, b"\x00" * SRAM_SIZE)
    stack_base = ((highest + PAGE_SIZE - 1) // PAGE_SIZE) * PAGE_SIZE + PAGE_SIZE
    try:
        mu.mem_map(stack_base, STACK_SIZE)
    except Exception:
        pass

    # Per-trace state.
    trace: list[dict] = []
    counts = {"insns": 0, "mmio_reads": 0, "mmio_writes": 0, "faults": 0}
    auto_mapped: set[int] = set()
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
            try:
                uc.mem_write(int(address) & ~3, b"\x00" * 4)
            except Exception:
                pass
            return True
        return False

    def on_code(uc, address, size, user_data):
        if int(address) in (RETURN_STOP, RETURN_STOP | 1):
            stop_reason["value"] = "returned"
            uc.emu_stop()
            return
        counts["insns"] += 1
        if counts["insns"] >= args.max_insns:
            stop_reason["value"] = "capped"
            uc.emu_stop()

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
    mu.reg_write(UC_ARM_REG_SP, stack_base + STACK_SIZE - 0x100)
    mu.reg_write(UC_ARM_REG_LR, RETURN_STOP | 1)

    start = fn_addr | 1
    try:
        mu.emu_start(start, RETURN_STOP)
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

    args.out.parent.mkdir(parents=True, exist_ok=True)
    with args.out.open("w", encoding="utf-8") as f:
        for row in trace:
            row["function"] = args.function
            row["image"] = args.image
            row["address"] = args.address
            f.write(json.dumps(row, sort_keys=True) + "\n")

    print(json.dumps({
        "function": args.function,
        "image": args.image,
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
