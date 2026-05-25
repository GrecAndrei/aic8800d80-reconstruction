#!/usr/bin/env python3
"""Compile a recovered C function to ARM Thumb and smoke-test it under Unicorn.

This is intentionally small and targeted:
- compile one source file to an ARMv7-M object with clang
- extract the requested function from the ELF symbol table
- map the function text into Unicorn
- seed a few MMIO words
- execute only a bounded number of instructions

It is a smoke test, not a full-system firmware emulator.
"""

from __future__ import annotations

import argparse
import json
import os
import shutil
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path

from elftools.elf.elffile import ELFFile
from unicorn import UC_ARCH_ARM, UC_HOOK_CODE, UC_MODE_THUMB, Uc
from unicorn.arm_const import UC_ARM_REG_LR, UC_ARM_REG_PC, UC_ARM_REG_SP


PAGE_SIZE = 0x1000
CODE_BASE = 0x1000
STACK_BASE = 0x2000
STACK_SIZE = 0x2000


@dataclass
class Seed:
    addr: int
    value: int
    width: int = 4


def parse_int(s: str) -> int:
    return int(s, 0)


def compile_object(src: Path, out_dir: Path, target: str, cpu: str, opt: str) -> Path:
    obj = out_dir / (src.stem + ".o")
    cmd = [
        "clang",
        f"--target={target}",
        f"-mcpu={cpu}",
        "-mthumb",
        "-ffreestanding",
        "-fno-builtin",
        f"-O{opt}",
        "-c",
        str(src),
        "-o",
        str(obj),
    ]
    subprocess.run(cmd, check=True)
    return obj


def load_function(obj: Path, fn_name: str) -> tuple[bytes, int, int]:
    with obj.open("rb") as f:
        elf = ELFFile(f)
        text = elf.get_section_by_name(".text")
        if text is None:
            raise RuntimeError("object has no .text section")
        code = text.data()
        symtab = elf.get_section_by_name(".symtab")
        if symtab is None:
            raise RuntimeError("object has no symbol table")
        for sym in symtab.iter_symbols():
            if sym.name != fn_name:
                continue
            if sym.entry["st_info"]["type"] != "STT_FUNC":
                continue
            off = int(sym.entry["st_value"]) & ~1
            size = int(sym.entry["st_size"])
            return code, off, size
    raise RuntimeError(f"function {fn_name!r} not found in {obj}")


def map_page(mu: Uc, addr: int, size: int = PAGE_SIZE) -> None:
    base = addr & ~(PAGE_SIZE - 1)
    try:
        mu.mem_map(base, size)
    except Exception:
        # The page may already be mapped by another seed.
        pass


def write_seed(mu: Uc, seed: Seed) -> None:
    map_page(mu, seed.addr)
    data = seed.value.to_bytes(seed.width, "little", signed=False)
    mu.mem_write(seed.addr, data)


def run_smoke(code: bytes, fn_off: int, fn_size: int, seeds: list[Seed], max_insns: int) -> tuple[Uc, int]:
    mu = Uc(UC_ARCH_ARM, UC_MODE_THUMB)
    map_page(mu, CODE_BASE)
    mu.mem_write(CODE_BASE, code)
    map_page(mu, STACK_BASE, STACK_SIZE)
    mu.reg_write(UC_ARM_REG_SP, STACK_BASE + STACK_SIZE // 2)

    for seed in seeds:
        write_seed(mu, seed)

    start = CODE_BASE + fn_off + 1
    insn_count = {"n": 0}

    def on_code(uc, address, size, user_data):
        insn_count["n"] += 1
        if insn_count["n"] >= max_insns:
            uc.emu_stop()

    mu.hook_add(UC_HOOK_CODE, on_code)
    mu.reg_write(UC_ARM_REG_PC, start)
    mu.reg_write(UC_ARM_REG_LR, start)
    mu.emu_start(start, 0)
    return mu, insn_count["n"]


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("source", type=Path, help="Recovered C source file")
    ap.add_argument("function", help="Function name to smoke-test")
    ap.add_argument("--target", default="armv7m-none-eabi", help="Clang target triple")
    ap.add_argument("--cpu", default="cortex-m3", help="Clang CPU target")
    ap.add_argument("--opt", default="0", choices=["0", "1", "2", "3", "s"], help="Clang optimization level")
    ap.add_argument("--max-insns", type=int, default=40, help="Maximum instructions to execute")
    ap.add_argument(
        "--seed",
        action="append",
        default=[],
        metavar="ADDR=VALUE",
        help="Seed a little-endian word in emulated memory (repeatable, hex or decimal)",
    )
    ap.add_argument(
        "--check-clear-lsb",
        action="append",
        default=[],
        metavar="ADDR",
        help="Assert that the little-endian word at ADDR has bit 0 cleared after execution",
    )
    ap.add_argument(
        "--expect-eq",
        action="append",
        default=[],
        metavar="ADDR=VALUE",
        help="Assert that the little-endian word at ADDR equals VALUE after execution",
    )
    args = ap.parse_args()

    if not args.source.is_file():
        raise SystemExit(f"source not found: {args.source}")

    seeds: list[Seed] = []
    for item in args.seed:
        if "=" not in item:
            raise SystemExit(f"invalid --seed {item!r}, expected ADDR=VALUE")
        a, v = item.split("=", 1)
        seeds.append(Seed(addr=parse_int(a), value=parse_int(v)))

    with tempfile.TemporaryDirectory(prefix="unicorn_smoke_") as td:
        td_path = Path(td)
        obj = compile_object(args.source, td_path, args.target, args.cpu, args.opt)
        code, off, size = load_function(obj, args.function)
        mu, count = run_smoke(code, off, size, seeds, args.max_insns)

        print(json.dumps({
            "source": str(args.source),
            "function": args.function,
            "instructions": count,
            "object": str(obj),
        }, indent=2))

    for a in args.check_clear_lsb:
        addr = parse_int(a)
        val = int.from_bytes(mu.mem_read(addr, 4), "little")
        print(f"{hex(addr)} = {hex(val)}")
        if val & 1:
            raise SystemExit(f"assertion failed: {hex(addr)} bit0 still set")

    for item in args.expect_eq:
        if "=" not in item:
            raise SystemExit(f"invalid --expect-eq {item!r}, expected ADDR=VALUE")
        a, v = item.split("=", 1)
        addr = parse_int(a)
        expected = parse_int(v)
        val = int.from_bytes(mu.mem_read(addr, 4), "little")
        print(f"{hex(addr)} = {hex(val)}")
        if val != expected:
            raise SystemExit(
                f"assertion failed: {hex(addr)} expected {hex(expected)} got {hex(val)}"
            )

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
