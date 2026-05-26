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
import subprocess
import tempfile
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from textwrap import dedent

from elftools.elf.elffile import ELFFile
from unicorn import (
    UC_ARCH_ARM,
    UC_HOOK_CODE,
    UC_HOOK_MEM_READ,
    UC_HOOK_MEM_WRITE,
    UC_HOOK_MEM_FETCH_UNMAPPED,
    UC_HOOK_MEM_READ_UNMAPPED,
    UC_HOOK_MEM_WRITE_UNMAPPED,
    UC_MODE_THUMB,
    Uc,
    UcError,
    UC_MEM_READ,
)
from unicorn.arm_const import UC_ARM_REG_LR, UC_ARM_REG_PC, UC_ARM_REG_SP


PAGE_SIZE = 0x1000
STACK_SIZE = 0x8000
RETURN_STOP = 0xDEADC000
SRAM_BASE = 0x20000000
SRAM_SIZE = 0x20000
HEAP_BASE = 0x21000000
HEAP_SIZE = 0x10000


def is_mmio_addr(addr: int) -> bool:
    # Common peripheral/system-mapped ranges for firmware smoke traces.
    return (0x40000000 <= addr <= 0x5FFFFFFF) or (0xE0000000 <= addr <= 0xE00FFFFF)


@dataclass
class Seed:
    addr: int
    value: int
    width: int = 4


def parse_int(s: str) -> int:
    return int(s, 0)


def compile_object(src: Path, out_dir: Path, target: str, cpu: str, opt: str, entry: str) -> Path:
    elf = out_dir / (src.stem + ".elf")
    cmd = [
        "clang",
        f"--target={target}",
        f"-mcpu={cpu}",
        "-mthumb",
        "-ffreestanding",
        "-fno-builtin",
        "-fdata-sections",
        "-ffunction-sections",
        f"-O{opt}",
        str(src),
        "-nostdlib",
        "-Wl,--unresolved-symbols=ignore-all",
        "-Wl,-Ttext=0x1000",
        f"-Wl,-e,{entry}",
        "-o",
        str(elf),
    ]
    subprocess.run(cmd, check=True)
    return elf


def synthesize_wrapper_source(src: Path, out_dir: Path, stub_names: list[str]) -> Path:
    wrapper = out_dir / f"{src.stem}_wrapped.c"
    stubs = "\n".join(f"void {name}(void) {{}}" for name in stub_names)
    wrapper.write_text(
        dedent(
            f"""
            #include \"{src.as_posix()}\"

            {stubs}
            """
        ).lstrip(),
        encoding="utf-8",
    )
    return wrapper


def load_function(obj: Path, fn_name: str) -> tuple[bytes, int, int, list[tuple[int, bytes, int]]]:
    with obj.open("rb") as f:
        elf = ELFFile(f)
        segments: list[tuple[int, bytes, int]] = []
        for seg in elf.iter_segments():
            if seg["p_type"] != "PT_LOAD":
                continue
            vaddr = int(seg["p_vaddr"])
            memsz = int(seg["p_memsz"])
            if memsz == 0:
                continue
            segments.append((vaddr, seg.data(), memsz))
        symtab = elf.get_section_by_name(".symtab")
        if symtab is None:
            raise RuntimeError("object has no symbol table")
        for sym in symtab.iter_symbols():
            if sym.name != fn_name:
                continue
            if sym.entry["st_info"]["type"] != "STT_FUNC":
                continue
            shndx = sym.entry["st_shndx"]
            if not isinstance(shndx, int):
                raise RuntimeError(f"function {fn_name!r} has no concrete section")
            section = elf.get_section(shndx)
            if section is None:
                raise RuntimeError(f"function {fn_name!r} section is missing")
            code = section.data()
            fn_addr = int(sym.entry["st_value"]) & ~1
            size = int(sym.entry["st_size"])
            return code, fn_addr, size, segments
    raise RuntimeError(f"function {fn_name!r} not found in {obj}")


def map_page(mu: Uc, addr: int, size: int = PAGE_SIZE) -> None:
    base = addr & ~(PAGE_SIZE - 1)
    try:
        mu.mem_map(base, size)
    except Exception:
        pass


def write_seed(mu: Uc, seed: Seed) -> None:
    map_page(mu, seed.addr)
    data = seed.value.to_bytes(seed.width, "little", signed=False)
    mu.mem_write(seed.addr, data)


def try_map_region(mu: Uc, base: int, size: int) -> bool:
    aligned_base = base & ~(PAGE_SIZE - 1)
    aligned_size = ((size + PAGE_SIZE - 1) // PAGE_SIZE) * PAGE_SIZE
    if aligned_size <= 0:
        return False
    try:
        mu.mem_map(aligned_base, aligned_size)
        return True
    except Exception:
        return False


def run_smoke(
    code: bytes,
    fn_off: int,
    fn_size: int,
    segments: list[tuple[int, bytes, int]],
    seeds: list[Seed],
    max_insns: int,
    state_profile: str,
    mmio_autopage: bool,
    mmio_default: int,
) -> tuple[Uc, int, dict[str, int | None], str, dict]:
    mu = Uc(UC_ARCH_ARM, UC_MODE_THUMB)
    highest_end = 0
    merged_ranges: list[tuple[int, int]] = []
    for vaddr, data, memsz in sorted(segments, key=lambda item: item[0]):
        base = vaddr & ~(PAGE_SIZE - 1)
        end = ((vaddr + memsz + PAGE_SIZE - 1) // PAGE_SIZE) * PAGE_SIZE
        highest_end = max(highest_end, vaddr + memsz)
        if not merged_ranges:
            merged_ranges.append((base, end))
            continue
        prev_base, prev_end = merged_ranges[-1]
        if base <= prev_end:
            merged_ranges[-1] = (prev_base, max(prev_end, end))
        else:
            merged_ranges.append((base, end))

    for base, end in merged_ranges:
        size = end - base
        try:
            mu.mem_map(base, size)
        except Exception:
            pass

    for vaddr, data, memsz in segments:
        if data:
            mu.mem_write(vaddr, data)

    stack_base = ((highest_end + PAGE_SIZE - 1) // PAGE_SIZE) * PAGE_SIZE + PAGE_SIZE
    map_page(mu, stack_base, STACK_SIZE)
    mu.reg_write(UC_ARM_REG_SP, stack_base + STACK_SIZE - 0x100)

    if state_profile == "rich":
        if try_map_region(mu, SRAM_BASE, SRAM_SIZE):
            try:
                mu.mem_write(SRAM_BASE, b"\x00" * SRAM_SIZE)
            except Exception:
                pass
        if try_map_region(mu, HEAP_BASE, HEAP_SIZE):
            try:
                mu.mem_write(HEAP_BASE, b"\x00" * HEAP_SIZE)
            except Exception:
                pass

    for seed in seeds:
        write_seed(mu, seed)

    start = fn_off | 1
    insn_count = {"n": 0}
    fault: dict[str, int | None] = {"access": None, "address": None, "size": None}
    mmio_reads = {"count": 0}
    mmio_writes = {"count": 0}
    mmio_addrs: set[int] = set()
    helper_touches = {"count": 0}
    branch_taken = {"count": 0}
    branch_depth = {"cur": 0, "max": 0}
    prev = {"addr": None, "size": None}
    stop_reason = {"value": "running"}
    mmio_auto_mapped = {"count": 0}

    def on_code(uc, address, size, user_data):
        if prev["addr"] is not None and prev["size"] is not None:
            expected = int(prev["addr"]) + int(prev["size"])
            if int(address) != expected:
                branch_taken["count"] += 1
                branch_depth["cur"] += 1
                if branch_depth["cur"] > branch_depth["max"]:
                    branch_depth["max"] = branch_depth["cur"]
            else:
                branch_depth["cur"] = 0
        prev["addr"] = int(address)
        prev["size"] = int(size)

        # Approximate helper touches by counting BL/BLX-like opcodes.
        try:
            h1 = int.from_bytes(bytes(uc.mem_read(address, 2)), "little")
            if (h1 & 0xF800) == 0xF000:
                h2 = int.from_bytes(bytes(uc.mem_read(address + 2, 2)), "little")
                if (h2 & 0xD000) == 0xD000:
                    helper_touches["count"] += 1
            elif (h1 & 0xFF87) == 0x4780:
                helper_touches["count"] += 1
        except UcError:
            pass

        insn_count["n"] += 1
        if insn_count["n"] >= max_insns:
            stop_reason["value"] = "instruction_cap"
            uc.emu_stop()

    def on_mem_access(uc, access, address, size, value, user_data):
        if not is_mmio_addr(int(address)):
            return
        mmio_addrs.add(int(address))
        if access == UC_MEM_READ:
            mmio_reads["count"] += 1
        else:
            mmio_writes["count"] += 1

    def on_unmapped(uc, access, address, size, value, user_data):
        if mmio_autopage and is_mmio_addr(int(address)):
            map_page(uc, int(address))
            mmio_auto_mapped["count"] += 1
            # For read/fetch, provide deterministic default data.
            try:
                uc.mem_write(int(address), int(mmio_default).to_bytes(4, "little", signed=False))
            except Exception:
                pass
            return True
        fault["access"] = access
        fault["address"] = address
        fault["size"] = size
        uc.emu_stop()
        return False

    mu.hook_add(UC_HOOK_CODE, on_code)
    mu.hook_add(UC_HOOK_MEM_READ | UC_HOOK_MEM_WRITE, on_mem_access)
    mu.hook_add(
        UC_HOOK_MEM_READ_UNMAPPED
        | UC_HOOK_MEM_WRITE_UNMAPPED
        | UC_HOOK_MEM_FETCH_UNMAPPED,
        on_unmapped,
    )
    mu.reg_write(UC_ARM_REG_PC, start)
    mu.reg_write(UC_ARM_REG_LR, RETURN_STOP | 1)

    try:
        mu.emu_start(start, RETURN_STOP)
    except UcError:
        stop_reason["value"] = "fault"
        if fault["address"] is not None:
            print(
                json.dumps(
                    {
                        "fault_access": fault["access"],
                        "fault_address": hex(int(fault["address"])),
                        "fault_size": fault["size"],
                    },
                    indent=2,
                )
            )
        trace = {
            "termination_reason": "fault",
            "mmio_auto_mapped_count": mmio_auto_mapped["count"],
            "mmio_read_count": mmio_reads["count"],
            "mmio_write_count": mmio_writes["count"],
            "mmio_unique_addrs": [hex(a) for a in sorted(mmio_addrs)[:16]],
            "branch_taken_count": branch_taken["count"],
            "branch_depth_max": branch_depth["max"],
            "helper_touch_count": helper_touches["count"],
        }
        return mu, insn_count["n"], fault, "fault", trace

    status = "returned"
    if stop_reason["value"] == "instruction_cap":
        status = "capped"

    trace = {
        "termination_reason": "natural_return" if status == "returned" else "instruction_cap",
        "mmio_auto_mapped_count": mmio_auto_mapped["count"],
        "mmio_read_count": mmio_reads["count"],
        "mmio_write_count": mmio_writes["count"],
        "mmio_unique_addrs": [hex(a) for a in sorted(mmio_addrs)[:16]],
        "branch_taken_count": branch_taken["count"],
        "branch_depth_max": branch_depth["max"],
        "helper_touch_count": helper_touches["count"],
    }
    return mu, insn_count["n"], fault, status, trace


def append_outcome(path: Path, payload: dict) -> None:
    payload = dict(payload)
    payload.setdefault("generated_at", datetime.now(timezone.utc).isoformat())
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a", encoding="utf-8") as f:
        f.write(json.dumps(payload, sort_keys=True) + "\n")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("source", type=Path, help="Recovered C source file")
    ap.add_argument("function", help="Function name to smoke-test")
    ap.add_argument("--image", default="", help="Optional image identifier for outcome identity")
    ap.add_argument("--address", default="", help="Optional function address for outcome identity")
    ap.add_argument("--target", default="armv7m-none-eabi", help="Clang target triple")
    ap.add_argument("--cpu", default="cortex-m3", help="Clang CPU target")
    ap.add_argument("--opt", default="0", choices=["0", "1", "2", "3", "s"], help="Clang optimization level")
    ap.add_argument("--max-insns", type=int, default=40, help="Maximum instructions to execute")
    ap.add_argument("--state-profile", choices=["basic", "rich"], default="rich", help="Memory/state initialization profile")
    ap.add_argument("--mmio-autopage", action="store_true", help="Auto-map MMIO pages on first unmapped access")
    ap.add_argument("--mmio-default", default="0", help="Default MMIO word value used with --mmio-autopage")
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
    ap.add_argument(
        "--dump",
        action="append",
        default=[],
        metavar="ADDR",
        help="Print the little-endian word at ADDR after execution",
    )
    ap.add_argument(
        "--stub-fn",
        action="append",
        default=[],
        metavar="NAME",
        help="Synthesize an empty stub for a missing no-arg function before compiling",
    )
    ap.add_argument(
        "--record-outcome",
        type=Path,
        default=None,
        help="Append JSONL outcome row for dynamic queue learning",
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
    mmio_default = parse_int(args.mmio_default)

    with tempfile.TemporaryDirectory(prefix="unicorn_smoke_") as td:
        td_path = Path(td)
        source = args.source
        if args.stub_fn:
            source = synthesize_wrapper_source(args.source.resolve(), td_path, args.stub_fn)
        obj = compile_object(source, td_path, args.target, args.cpu, args.opt, args.function)
        try:
            code, off, size, segments = load_function(obj, args.function)
        except RuntimeError as err:
            print(
                json.dumps(
                    {
                        "source": str(args.source),
                        "image": args.image,
                        "address": args.address,
                        "function": args.function,
                        "status": "missing_symbol",
                        "error": str(err),
                        "object": str(obj),
                    },
                    indent=2,
                )
            )
            if args.record_outcome is not None:
                append_outcome(
                    args.record_outcome,
                    {
                        "image": args.image,
                        "address": args.address,
                        "function": args.function,
                        "status": "missing_symbol",
                        "source": str(args.source),
                        "error": str(err),
                    },
                )
            return 3
        mu, count, fault, status, trace = run_smoke(
            code,
            off,
            size,
            segments,
            seeds,
            args.max_insns,
            args.state_profile,
            args.mmio_autopage,
            mmio_default,
        )

        print(
            json.dumps(
                {
                    "source": str(args.source),
                    "image": args.image,
                    "address": args.address,
                    "function": args.function,
                    "instructions": count,
                    "object": str(obj),
                    "status": status,
                    **trace,
                },
                indent=2,
            )
        )

    if args.record_outcome is not None:
        row = {
            "image": args.image,
            "address": args.address,
            "function": args.function,
            "status": status,
            "source": str(args.source),
            "instructions": count,
            **trace,
        }
        if fault.get("address") is not None:
            row["fault_address"] = hex(int(fault["address"]))
        append_outcome(args.record_outcome, row)

    if status == "fault":
        return 2
    if status == "capped":
        return 4

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
            raise SystemExit(f"assertion failed: {hex(addr)} expected {hex(expected)} got {hex(val)}")

    for a in args.dump:
        addr = parse_int(a)
        val = int.from_bytes(mu.mem_read(addr, 4), "little")
        print(f"{hex(addr)} = {hex(val)}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
