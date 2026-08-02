#!/usr/bin/env python3
"""Full-system Unicorn emulator for the AIC8800D80 WiFi/BT firmware.

Loads a raw firmware image at the HARDWARE runtime base 0x120000, models
the MMIO register map from ``src/include/aic8800d80_mmio.h``, boots from
the IVT reset vector, and logs ordered MMIO traffic with register names.
Also traces single functions and runs the truth-lane target set to produce
ground-truth behavioral fingerprints from the ORIGINAL binary.

Image layout (AIC8800D80, per internal/ivt + harness_v19/scripts/make_elf.py):
  file offset 0x000-0x0FF : IVT + boot header (WFFW magic @ 0x20)
  file offset 0x100+      : code + data
  hardware address        : file offset + 0x120000
  (the reconstruction's naming dataset / composed src use analysis space =
  file offset + 0x100000; the two differ by 0x20000 — see
  docs/RUNTIME_BASE_120000.md)

The IVT reset vector (0x1201a9 = file 0x1a8) IS the first-stage init: a
CPUID check against 0xC241 (``movw r2, 0xc241``), then MSP setup + jump to
the second stage. ``boot`` starts from it (or ``resolve_boot_entry``, which
finds the same routine by byte signature).

This builds on ``tools/unicorn_smoke.py`` (single-function smoke) and
``tools/orig_binary_trace.py`` (per-function ground truth): the platform
class here is the shared full-system substrate, and ``verify`` wires the
truth-lane targets (extraction_out/reconstruction/truth_lane_state/
truth_lane_targets.json) to per-function fingerprints.

Commands:
  header <image>                 Show IVT / boot header info
  boot   <image> [--max-insns N] [--entry ADDR] [--out FILE]
                                 Boot from the reset vector, log MMIO traffic
  trace  <image> <addr> [--max-insns N] [--out FILE]
                                 Run one function in the original binary
  verify [--targets JSON] [--max-insns N] [--out DIR]
                                 Fingerprint every truth-lane target
  compare --orig FING.jsonl --recon SMOKE.jsonl [--out DIR]
                                 Pair original fingerprints with reconstructed
                                 smoke outcomes and score address overlap
"""
from __future__ import annotations

import argparse
import json
import re
import struct
import sys
from datetime import datetime, timezone
from pathlib import Path

from unicorn import (
    UC_ARCH_ARM,
    UC_HOOK_CODE,
    UC_HOOK_MEM_READ,
    UC_HOOK_MEM_READ_UNMAPPED,
    UC_HOOK_MEM_WRITE,
    UC_HOOK_MEM_WRITE_UNMAPPED,
    UC_MEM_READ,
    UC_MEM_WRITE,
    UC_MODE_THUMB,
    Uc,
    UcError,
)
from unicorn.arm_const import (
    UC_ARM_REG_LR,
    UC_ARM_REG_PC,
    UC_ARM_REG_SP,
    UC_CPU_ARM_CORTEX_M3,
)

REPO = Path(__file__).resolve().parent.parent
SRC = REPO / "src"
MMIO_HEADER = SRC / "include" / "aic8800d80_mmio.h"
TARGETS_DEFAULT = REPO / "extraction_out" / "reconstruction" / "truth_lane_state" / "truth_lane_targets.json"
SCAN_GLOB = REPO / "harness_v25" / "out" / "{}_bin_funcs.jsonl"
FIRMWARE_DIR = REPO / "inputs" / "firmware"

# Memory map (all absolute addresses).
# HARDWARE base: the SoC loads each WFFW image at 0x120000 (the IVT reset
# vector 0x1201a9 == the CPUID-check `start` at file 0x1a8 is CORRECT at this
# base). The reconstruction / naming dataset / composed src use a
# self-consistent ANALYSIS space of file_offset + 0x100000; the two are
# related by a constant 0x20000 (see docs/RUNTIME_BASE_120000.md).
ANALYSIS_BASE = 0x100000        # reconstruction convention (not hardware)
CHIP_BASE = 0x120000            # image load base (hardware runtime base)
HW_OFFSET = CHIP_BASE - ANALYSIS_BASE  # analysis-space addr -> hardware addr
LINK_BASE = 0x1200000           # boot-header link space (image mirror)
CODE_END = 0x180000             # end of code/BSS window (image spans 0x120000-0x180000)
IMAGE_MAX = 0x200000            # hard cap on image size we will map
STACK_BASE = 0x180000           # stack window below the IVT SP (0x1a0000)
STACK_SIZE = 0x20000
SRAM_BASE = 0x20000000          # main SRAM (existing tools use this)
SRAM_SIZE = 0x80000
HEAP_BASE = 0x21000000
HEAP_SIZE = 0x10000
MMIO_PHANTOM_BASE = 0x40000000  # APB/AHB peripherals (IDA phantom segment)
MMIO_PHANTOM_END = 0x60000000
RETURN_STOP = 0xDEADC000
PAGE_SIZE = 0x1000

IVT_SP_OFF = 0x00
IVT_RESET_OFF = 0x04


def is_mmio_addr(addr: int) -> bool:
    """AIC8800D80 SoC MMIO / memory-mapped regions (same as unicorn_smoke)."""
    return (
        (0x00000000 <= addr <= 0x001FFFFF)   # flash / boot ROM / vendor peripherals
        or (0x20000000 <= addr <= 0x3FFFFFFF)  # SRAM
        or (0x40000000 <= addr <= 0x5FFFFFFF)  # APB / AHB peripherals
        or (0xE0000000 <= addr <= 0xE00FFFFF)  # system control (NVIC etc.)
    )


def is_periph_addr(addr: int) -> bool:
    """True for actual peripheral registers (APB/AHB + system control).

    Excludes the 0x120000-0x1A0000 image/BSS window and 0x0-0x1FFFFF, which
    ``is_mmio_addr`` also flags but are really firmware data / boot flash.
    Behavioral fingerprints of register traffic use this narrower set.
    """
    return (
        (0x40000000 <= addr <= 0x5FFFFFFF)
        or (0xE0000000 <= addr <= 0xE00FFFFF)
    )


def parse_int(s: str) -> int:
    return int(s, 0)


# ---------------------------------------------------------------------------
# MMIO device model (from the generated register header)
# ---------------------------------------------------------------------------

_REG_NAME_RE = re.compile(r"^#define\s+(REG_[0-9A-Fa-f]+_[0-9A-Fa-f]+)\s*\(\*\(\(volatile\s+uint32_t\s+\*\)(0x[0-9A-Fa-f]+)\)\)")


def load_mmio_model(header: Path | None = None) -> dict[int, str]:
    """Parse the generated MMIO header into {address: register-name}.

    The header defines ~25k ``REG_<page>_<off>`` macros for the SoC
    peripheral registers. Returns an address -> name map used to annotate
    MMIO traffic.
    """
    path = header or MMIO_HEADER
    if not path.is_file():
        raise SystemExit(f"MMIO header not found: {path}")
    model: dict[int, str] = {}
    for line in path.read_text(errors="replace").splitlines():
        m = _REG_NAME_RE.match(line.strip())
        if not m:
            continue
        model[int(m.group(2), 16)] = m.group(1)
    return model


def mmio_name(model: dict[int, str], addr: int) -> str:
    """Best-effort register name for an MMIO address.

    Exact match wins; otherwise synthesize ``REG_<page>_<off>`` (the same
    scheme the generator uses) so the name is still human-readable.
    """
    if addr in model:
        return model[addr]
    return f"REG_{addr >> 16:04X}_{addr & 0xFFFF:04X}"


# ---------------------------------------------------------------------------
# Function table (PC -> name, from the fwstruct scan)
# ---------------------------------------------------------------------------

def load_function_table(image: str) -> list[tuple[int, str]]:
    """Return sorted [(address, name)] from the fwstruct scan JSONL.

    Scan addresses are the project's chip-space "model" addresses (e.g.
    ``start`` at 0x100100); some are a few bytes ahead of the real code.
    We keep them raw and resolve PCs with a tolerance at lookup time.
    """
    path = Path(str(SCAN_GLOB).format(image))
    table: list[tuple[int, str]] = []
    if not path.is_file():
        return table
    for line in path.read_text(errors="replace").splitlines():
        line = line.strip()
        if not line:
            continue
        try:
            j = json.loads(line)
        except json.JSONDecodeError:
            continue
        addr = j.get("address")
        name = j.get("name")
        if not isinstance(addr, int) or not name:
            continue
        table.append((addr, name))
    table.sort()
    return table


def resolve_pc_name(table: list[tuple[int, str]], pc: int, tol: int = 0x100) -> str | None:
    """Map a runtime PC to the nearest function whose start is <= pc.

    ``tol`` absorbs the small model-vs-real address offset (e.g. start).
    None if the PC is before every known function start.
    """
    lo, hi = 0, len(table) - 1
    best = -1
    while lo <= hi:
        mid = (lo + hi) // 2
        if table[mid][0] <= pc:
            best = mid
            lo = mid + 1
        else:
            hi = mid - 1
    if best < 0:
        return None
    addr, name = table[best]
    if pc - addr > tol:
        return None
    return name


# ---------------------------------------------------------------------------
# Platform
# ---------------------------------------------------------------------------

class Aic8800D80Platform:
    """A full-system Unicorn model of the AIC8800D80 at hardware base 0x120000.

    Memory map (RWX where code may self-modify):
      [0x120000, 0x180000)   image + BSS (hardware space)
      [0x180000, 0x1A0000)   stack / firmware data (SP from IVT = 0x1A0000)
      [0x20000000, 0x20080000) main SRAM
      [0x21000000, 0x21010000) heap
      MMIO: pages auto-mapped on first access; written state is tracked so
      read-after-write returns the stored value.

    The reconstruction's naming dataset / composed src use the ANALYSIS space
    (file_offset + 0x100000); run addresses are +0x20000 from analysis-space
    keys (see ``_normalize_target_addr`` / ``HW_OFFSET``).
    """

    def __init__(self, image_path: Path, mmio_model: dict[int, str] | None = None,
                 cpu_model: int = UC_CPU_ARM_CORTEX_M3):
        self.image_path = Path(image_path)
        self.image = self.image_path.read_bytes()
        self.image_addr = CHIP_BASE
        self.mmio_model = mmio_model if mmio_model is not None else load_mmio_model()
        self.function_table: list[tuple[int, str]] = []

        if len(self.image) > IMAGE_MAX:
            raise SystemExit(f"image too large: {len(self.image):#x} > {IMAGE_MAX:#x}")

        self.mu = Uc(UC_ARCH_ARM, UC_MODE_THUMB)
        self.mu.ctl_set_cpu_model(cpu_model)

        self._map_memory()

        self.traffic: list[dict] = []
        self.mmio_state: dict[int, int] = {}
        self.mmio_auto_mapped: set[int] = set()
        self.insn_count = 0
        self.branch_taken = 0
        self.cur_fn: str | None = None
        self.fn_entries: list[str] = []
        self.call_stack: list[str] = []
        self.call_depth = 0

        self._install_hooks()

    # -- memory -----------------------------------------------------------
    def _map_memory(self) -> None:
        # Primary image + BSS window.
        self._map_rwx(CHIP_BASE, CODE_END - CHIP_BASE)
        self.mu.mem_write(CHIP_BASE, self.image)
        # Stack under the IVT SP.
        self._map_rwx(STACK_BASE, STACK_SIZE)
        # Return sentinel page (bx lr -> RETURN_STOP|1 must not fault).
        sentinel_base = RETURN_STOP & ~(PAGE_SIZE - 1)
        self._map_rwx(sentinel_base, PAGE_SIZE)
        try:
            # Thumb `b .` (0xe7fe) busy loop at every odd word so any jump
            # into the sentinel is mapped; the code hook stops first.
            self.mu.mem_write(sentinel_base, b"\xfe\xe7" * (PAGE_SIZE // 2))
        except UcError:
            pass
        # Main SRAM + heap.
        self._map_rwx(SRAM_BASE, SRAM_SIZE)
        self._map_rwx(HEAP_BASE, HEAP_SIZE)
        try:
            self.mu.mem_write(SRAM_BASE, b"\x00" * SRAM_SIZE)
        except UcError:
            pass
        try:
            self.mu.mem_write(HEAP_BASE, b"\x00" * HEAP_SIZE)
        except UcError:
            pass

    def _map_rwx(self, base: int, size: int) -> None:
        try:
            self.mu.mem_map(base, size)
        except UcError:
            pass

    # -- hooks ------------------------------------------------------------
    def _install_hooks(self) -> None:
        def on_code(uc, address, size, user_data):
            pc = int(address)
            if pc in (RETURN_STOP, RETURN_STOP | 1):
                uc.emu_stop()
                return
            self.insn_count += 1
            self._note_function(pc)

        def on_mem(uc, access, address, size, value, user_data):
            addr = int(address)
            if not is_mmio_addr(addr):
                return
            # call_depth: 0 = accesses made while the target function's own
            # body is on top of the stack (before any callee was entered and
            # after it returned). Used to compare original vs reconstruction
            # on the SAME basis: the reconstruction stubs callees, so the
            # original's callee-register traffic must be excluded too.
            depth = self.call_depth
            if access == UC_MEM_READ:
                self.traffic.append({
                    "pc": hex(int(uc.reg_read(UC_ARM_REG_PC))),
                    "op": "read",
                    "addr": hex(addr),
                    "name": mmio_name(self.mmio_model, addr),
                    "size": int(size),
                    "depth": depth,
                })
            else:
                self.traffic.append({
                    "pc": hex(int(uc.reg_read(UC_ARM_REG_PC))),
                    "op": "write",
                    "addr": hex(addr),
                    "name": mmio_name(self.mmio_model, addr),
                    "size": int(size),
                    "value": hex(int(value)),
                    "depth": depth,
                })
                self.mmio_state[addr] = int(value)

        self.last_unmapped = []  # (pc, access, addr) of the most recent misses

        def on_unmapped(uc, access, address, size, value, user_data):
            addr = int(address)
            pc = int(uc.reg_read(UC_ARM_REG_PC))
            # Record every unmapped access (even non-MMIO) for diagnostics.
            self.last_unmapped.append((pc, access, addr, int(size)))
            if not is_mmio_addr(addr):
                return False
            base = addr & ~(PAGE_SIZE - 1)
            if base not in self.mmio_auto_mapped:
                try:
                    uc.mem_map(base, PAGE_SIZE)
                    self.mmio_auto_mapped.add(base)
                except UcError:
                    return False
            # Provide a deterministic default word (or the last written value).
            try:
                word = self.mmio_state.get(addr & ~3, 0)
                uc.mem_write(addr & ~3, struct.pack("<I", word))
            except UcError:
                return False
            return True

        self.mu.hook_add(UC_HOOK_CODE, on_code)
        self.mu.hook_add(UC_HOOK_MEM_READ | UC_HOOK_MEM_WRITE, on_mem)
        self.mu.hook_add(
            UC_HOOK_MEM_READ_UNMAPPED | UC_HOOK_MEM_WRITE_UNMAPPED,
            on_unmapped,
        )

    def _note_function(self, pc: int) -> None:
        if not self.function_table:
            return
        name = resolve_pc_name(self.function_table, pc)
        if not name or name == self.cur_fn:
            return
        # Function-frame tracking: entering a callee pushes it; returning to
        # a frame that is already on the stack pops back to it. call_depth is
        # the number of frames above the entry function (0 = entry body).
        if self.call_stack and name == self.call_stack[-1]:
            self.call_stack.pop()
        elif self.call_stack and name in self.call_stack:
            # Returned to a grandparent frame (e.g. through a tail-call).
            while self.call_stack and self.call_stack[-1] != name:
                self.call_stack.pop()
        else:
            self.call_stack.append(name)
        self.cur_fn = name
        self.call_depth = max(0, len(self.call_stack) - 1)
        self.fn_entries.append(name)

    # -- ivt / boot -------------------------------------------------------
    def ivt(self) -> dict:
        sp = struct.unpack_from("<I", self.image, IVT_SP_OFF)[0]
        reset = struct.unpack_from("<I", self.image, IVT_RESET_OFF)[0]
        return {"stack_pointer": sp, "reset_vector": reset, "reset_handler": reset & ~1}

    def resolve_boot_entry(self) -> int:
        """Hardware address of the first-stage init (``start``).

        The IVT reset vector (0x1201a9) IS this routine: file 0x1a8 is a
        CPUID check against 0xC241 (``movw r2, 0xc241``) that sets MSP and
        jumps to the second stage, and 0x1201a8 is correct at hardware base
        0x120000. The signature is identical across all four images; we
        locate it by byte signature and fall back to file 0x1a8.
        """
        sig = bytes.fromhex("4cf24122")  # movw r2, 0xc241
        idx = self.image.find(sig)
        if idx > 4 and 0x100 <= idx - 4 < len(self.image):
            # The movw is preceded by `ldr r3,[lit]`; entry is 4 bytes earlier.
            return CHIP_BASE + (idx - 4)
        return CHIP_BASE + 0x1A8

    # -- execution --------------------------------------------------------
    def run(self, entry: int, max_insns: int, sp: int | None = None,
            lr: int | None = None) -> tuple[str, dict]:
        """Run from ``entry`` (thumb bit honored) until return, cap, or fault.

        Returns (termination, stats). Termination is one of
        ``returned`` / ``capped`` / ``fault``.
        """
        self.insn_count = 0
        self.traffic = []
        self.cur_fn = None
        self.fn_entries = []
        self.call_stack = []
        self.call_depth = 0
        self.last_unmapped = []
        if sp is not None:
            self.mu.reg_write(UC_ARM_REG_SP, sp)
        self.mu.reg_write(UC_ARM_REG_LR, (lr if lr is not None else RETURN_STOP) | 1)
        self.mu.reg_write(UC_ARM_REG_PC, entry | 1)
        # Seed the call stack with the entry function so depth 0 = entry body.
        if self.function_table:
            ename = resolve_pc_name(self.function_table, entry)
            if ename:
                self.cur_fn = ename
                self.call_stack = [ename]

        cap_flag = {"n": max_insns}
        fault = {"access": None, "address": None, "size": None, "detail": ""}
        stop = {"value": "running"}

        def on_code_cap(uc, address, size, user_data):
            if self.insn_count >= max_insns:
                stop["value"] = "capped"
                uc.emu_stop()
        cap_hook = self.mu.hook_add(UC_HOOK_CODE, on_code_cap)

        try:
            self.mu.emu_start(entry | 1, RETURN_STOP)
        except UcError as e:
            stop["value"] = "fault"
            fault["detail"] = str(e)
            fault["pc"] = hex(self.mu.reg_read(UC_ARM_REG_PC))
            if self.last_unmapped:
                pc0, acc, addr, sz = self.last_unmapped[-1]
                fault["access"] = "read" if acc == UC_MEM_READ else "write"
                fault["address"] = hex(addr)
                fault["size"] = sz

        self.mu.hook_del(cap_hook)

        if stop["value"] == "running":
            pc = self.mu.reg_read(UC_ARM_REG_PC)
            stop["value"] = "returned" if pc in (RETURN_STOP, RETURN_STOP | 1) else f"exited:0x{pc:x}"

        # A fault at the return sentinel is a natural return (bx lr reached
        # the sentinel page before the cap hook could stop us).
        if stop["value"] == "fault" and fault["pc"] in (
            hex(RETURN_STOP),
            hex(RETURN_STOP | 1),
        ):
            stop["value"] = "returned"
            fault["detail"] = ""

        reads = [t for t in self.traffic if t["op"] == "read"]
        writes = [t for t in self.traffic if t["op"] == "write"]
        unique = sorted({int(t["addr"], 16) for t in self.traffic})
        periph = sorted({int(t["addr"], 16) for t in self.traffic if is_periph_addr(int(t["addr"], 16))})
        # Depth-0 (target body only, excluding callee traffic): the SAME basis
        # the reconstruction smoke uses (it stubs callees, so their register
        # traffic is absent there too).
        depth0 = sorted({int(t["addr"], 16) for t in self.traffic
                         if t.get("depth", 0) == 0})
        depth0_periph = sorted({int(t["addr"], 16) for t in self.traffic
                                if t.get("depth", 0) == 0
                                and is_periph_addr(int(t["addr"], 16))})
        stats = {
            "instructions": self.insn_count,
            "mmio_reads": len(reads),
            "mmio_writes": len(writes),
            "unique_mmio_addrs": [hex(a) for a in unique],
            "unique_periph_addrs": [hex(a) for a in periph],
            "self_mmio_addrs": [hex(a) for a in depth0],
            "self_periph_addrs": [hex(a) for a in depth0_periph],
            "termination": stop["value"],
            "fault": fault["detail"],
            "fault_pc": fault.get("pc"),
            "fault_access": fault.get("access"),
            "fault_address": fault.get("address"),
            "functions": self.fn_entries[:50],
        }
        return stop["value"], stats

    # -- summaries --------------------------------------------------------
    def sequence(self) -> list[str]:
        """Ordered MMIO traffic as compact strings (behavioral_fingerprint style)."""
        out = []
        for t in self.traffic:
            if t["op"] == "write":
                out.append(f"W:{t['addr']}:{t['name']}:{t['value']}")
            else:
                out.append(f"R:{t['addr']}:{t['name']}")
        return out


# ---------------------------------------------------------------------------
# Commands
# ---------------------------------------------------------------------------

IMAGE_NAMES = {
    "fmacfw_8800d80_h_u02": "fmacfw_h",
    "fmacfw_8800d80_u02": "fmacfw",
    "fmacfwbt_8800d80_u02": "fmacfwbt",
    "lmacfw_rf_8800d80_u02": "lmacfw_rf",
}


def resolve_image(image: str) -> Path:
    path = Path(image)
    if path.is_file():
        return path
    candidate = FIRMWARE_DIR / image
    if candidate.is_file():
        return candidate
    if not image.endswith(".bin"):
        candidate = FIRMWARE_DIR / f"{image}.bin"
        if candidate.is_file():
            return candidate
    raise SystemExit(f"image not found: {image}")


def cmd_header(args: argparse.Namespace) -> int:
    path = resolve_image(args.image)
    plat = Aic8800D80Platform(path)
    ivt = plat.ivt()
    print(json.dumps({
        "image": path.name,
        "size": len(plat.image),
        "chip_base": hex(CHIP_BASE),
        "stack_pointer": hex(ivt["stack_pointer"]),
        "reset_vector": hex(ivt["reset_vector"]),
        "reset_handler": hex(ivt["reset_handler"]),
        "boot_entry": hex(plat.resolve_boot_entry()),
        "mmio_registers": len(plat.mmio_model),
    }, indent=2))
    return 0


def cmd_boot(args: argparse.Namespace) -> int:
    path = resolve_image(args.image)
    plat = Aic8800D80Platform(path)
    plat.function_table = load_function_table(_short_image(path.name))
    ivt = plat.ivt()
    if args.entry:
        entry = parse_int(args.entry)
    else:
        entry = plat.resolve_boot_entry()
    term, stats = plat.run(entry, args.max_insns, sp=ivt["stack_pointer"])
    seq = plat.sequence()
    report = {
        "command": "boot",
        "image": path.name,
        "boot_entry": hex(entry),
        "stack_pointer": hex(ivt["stack_pointer"]),
        "termination": term,
        **stats,
        "mmio_sequence": seq,
    }
    if args.out:
        out = Path(args.out)
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(json.dumps(report, indent=2) + "\n")
        print(f"[emulator] wrote {out}")
    else:
        print(json.dumps(report, indent=2))
        for s in seq[:args.log_limit]:
            print("  " + s)
    return 0 if term in ("returned", "capped") else 2


def cmd_trace(args: argparse.Namespace) -> int:
    path = resolve_image(args.image)
    plat = Aic8800D80Platform(path)
    plat.function_table = load_function_table(_short_image(path.name))
    addr = _normalize_target_addr(path.name, args.address)
    sp = args.sp if args.sp is not None else plat.ivt()["stack_pointer"]
    term, stats = plat.run(addr, args.max_insns, sp=sp)
    report = {
        "command": "trace",
        "image": path.name,
        "address": args.address,
        "chip_address": hex(addr),
        "termination": term,
        **stats,
        "mmio_sequence": plat.sequence(),
    }
    if args.out:
        out = Path(args.out)
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(json.dumps(report, indent=2) + "\n")
        print(f"[emulator] wrote {out}")
    else:
        print(json.dumps(report, indent=2))
    return 0 if term in ("returned", "capped") else 2


def _short_image(name: str) -> str:
    """fmacfw_8800d80_h_u02.bin -> fmacfw_8800d80_h_u02 (scan table key)."""
    return Path(name).stem


def _normalize_target_addr(image: str, addr_str: str) -> int:
    """Truth-lane targets mix analysis-space and offset-space addresses.

    fmacfw_h / fmacfw_u02 targets are analysis-space addresses (>= 0x100000);
    fmacfwbt / lmacfw_rf targets are file offsets (< 0x100000). Normalize to
    the ANALYSIS space (the compare key, matching truth_lane_smoke.py's
    reconstruction markers). The actual run address is +HW_OFFSET (hardware
    base 0x120000) — see cmd_verify.
    """
    addr = parse_int(addr_str)
    if addr < 0x100000:
        addr += ANALYSIS_BASE
    return addr


def cmd_verify(args: argparse.Namespace) -> int:
    if args.targets is None:
        targets_path = TARGETS_DEFAULT
    else:
        targets_path = Path(args.targets)
    if not targets_path.is_file():
        raise SystemExit(f"targets not found: {targets_path}")
    targets = json.loads(targets_path.read_text())

    out_dir = Path(args.out) if args.out else Path("/tmp/opencode/emulator_verify")
    out_dir.mkdir(parents=True, exist_ok=True)
    fingerprints_path = out_dir / "orig_fingerprints.jsonl"

    model = load_mmio_model()
    rows = []
    for t in targets:
        image = t.get("image", "")
        addr_str = t.get("address", "")
        fn = t.get("function", "")
        if not image or not addr_str:
            continue
        path = resolve_image(image)
        key = _normalize_target_addr(image, addr_str)
        run_addr = key + HW_OFFSET  # analysis-space key -> hardware base 0x120000
        plat = Aic8800D80Platform(path, mmio_model=model)
        plat.function_table = load_function_table(_short_image(path.name))
        ivt = plat.ivt()
        term, stats = plat.run(run_addr, args.max_insns, sp=ivt["stack_pointer"])
        row = {
            "image": image,
            "function": fn,
            "address": addr_str,
            "analysis_address": hex(key),
            "chip_address": hex(run_addr),
            "termination": term,
            **stats,
            "mmio_sequence": plat.sequence(),
        }
        rows.append(row)
        print(f"[verify] {fn:32s} {image:32s} {addr_str:10s} -> {term:10s} "
              f"insns={stats['instructions']:6d} r={stats['mmio_reads']:5d} "
              f"w={stats['mmio_writes']:5d}", file=sys.stderr)

    with fingerprints_path.open("w", encoding="utf-8") as f:
        for r in rows:
            r["generated_at"] = datetime.now(timezone.utc).isoformat()
            f.write(json.dumps(r, sort_keys=True) + "\n")

    summary = {
        "targets": len(rows),
        "returned": sum(1 for r in rows if r["termination"] == "returned"),
        "capped": sum(1 for r in rows if r["termination"] == "capped"),
        "faulted": sum(1 for r in rows if "fault" in r["termination"]),
        "wrote_mmio": sum(1 for r in rows if r["mmio_writes"] > 0),
        "out": str(fingerprints_path),
    }
    print(json.dumps(summary, indent=2))
    return 0


def cmd_compare(args: argparse.Namespace) -> int:
    """Pair original fingerprints with reconstructed smoke outcomes.

    The reconstructed side is produced by tools/truth_lane_smoke.py
    (smoke_outcomes.jsonl); the original side by ``verify``. Rows are
    matched on (image, address). The score is the Jaccard overlap of the
    unique MMIO address sets between the two sides.
    """
    orig_rows = []
    with Path(args.orig).open("r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if line:
                orig_rows.append(json.loads(line))
    recon_rows = []
    with Path(args.recon).open("r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if line:
                recon_rows.append(json.loads(line))

    recon_by_key: dict[tuple[str, str], dict] = {}
    for r in recon_rows:
        recon_by_key[(r.get("image", ""), r.get("address", ""))] = r

    out_dir = Path(args.out) if args.out else Path("/tmp/opencode/emulator_verify")
    out_dir.mkdir(parents=True, exist_ok=True)

    scored = []
    for o in orig_rows:
        key = (o.get("image", ""), o.get("address", ""))
        r = recon_by_key.get(key)
        if r is None:
            continue
        # Compare on the SAME basis: the reconstruction stubs callees, so its
        # traffic is the target body only. The original's "self" traffic
        # (call_depth 0) excludes callee register accesses the same way.
        # The self_* keys are only present in fingerprints produced with the
        # depth-0 tracker. Presence (not emptiness) selects the basis: an
        # empty self list is a genuine "no body-level traffic" signal, not a
        # missing field.
        if "self_mmio_addrs" in o:
            orig_all = {int(a, 16) for a in o.get("self_mmio_addrs", [])}
        else:
            orig_all = {int(a, 16) for a in o.get("unique_mmio_addrs", [])}
        recon_all = {int(a, 16) for a in r.get("mmio_unique_addrs", [])}
        # Narrow the comparison to actual peripheral registers; the full
        # set is polluted by firmware data-segment addresses (0x100000-0x180000).
        orig_addrs = {a for a in orig_all if is_periph_addr(a)}
        recon_addrs = {a for a in recon_all if is_periph_addr(a)}
        union = orig_addrs | recon_addrs
        jac = (len(orig_addrs & recon_addrs) / len(union)) if union else 1.0
        union_all = orig_all | recon_all
        jac_all = (len(orig_all & recon_all) / len(union_all)) if union_all else 1.0
        if not union:
            coverage = "no_periph_traffic"
        elif len(orig_addrs) == 0 and len(recon_addrs) > 0:
            coverage = "orig_no_periph"
        elif len(recon_addrs) == 0 and len(orig_addrs) > 0:
            coverage = "recon_missing_periph"
        elif jac >= 0.5:
            coverage = "matched"
        else:
            coverage = "partial"
        scored.append({
            "function": o.get("function", ""),
            "image": o.get("image", ""),
            "address": o.get("address", ""),
            "orig_termination": o.get("termination", ""),
            "recon_verdict": r.get("verdict", ""),
            "recon_status": r.get("status", ""),
            "orig_unique": len(orig_addrs),
            "recon_unique": len(recon_addrs),
            "jaccard": round(jac, 3),
            "jaccard_all": round(jac_all, 3),
            "coverage": coverage,
            "overlap_addrs": [hex(a) for a in sorted(orig_addrs & recon_addrs)],
            "orig_only": [hex(a) for a in sorted(orig_addrs - recon_addrs)],
            "recon_only": [hex(a) for a in sorted(recon_addrs - orig_addrs)],
        })

    out_path = out_dir / "compare_scores.jsonl"
    with out_path.open("w", encoding="utf-8") as f:
        for s in scored:
            f.write(json.dumps(s, sort_keys=True) + "\n")

    matched = len(scored)
    nonempty = [s for s in scored if s["coverage"] != "no_periph_traffic"]
    mean_jac = sum(s["jaccard"] for s in nonempty) / len(nonempty) if nonempty else 0.0
    summary = {
        "orig_rows": len(orig_rows),
        "recon_rows": len(recon_rows),
        "matched": matched,
        "mean_jaccard_nonempty": round(mean_jac, 3),
        "matched_periph": sum(1 for s in scored if s["coverage"] == "matched"),
        "partial": sum(1 for s in scored if s["coverage"] == "partial"),
        "recon_missing_periph": sum(1 for s in scored if s["coverage"] == "recon_missing_periph"),
        "orig_no_periph": sum(1 for s in scored if s["coverage"] == "orig_no_periph"),
        "no_periph_traffic": sum(1 for s in scored if s["coverage"] == "no_periph_traffic"),
        "out": str(out_path),
    }
    print(json.dumps(summary, indent=2))
    return 0


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def build_parser() -> argparse.ArgumentParser:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="command", required=True)

    p = sub.add_parser("header", help="show IVT / boot header info")
    p.add_argument("image")
    p.set_defaults(func=cmd_header)

    p = sub.add_parser("boot", help="boot from reset vector, log MMIO traffic")
    p.add_argument("image")
    p.add_argument("--max-insns", type=int, default=20000)
    p.add_argument("--entry", default="", help="override boot entry (chip address)")
    p.add_argument("--out", default="", help="write JSON report to file")
    p.add_argument("--log-limit", type=int, default=40, help="traffic lines to print (0=all)")
    p.set_defaults(func=cmd_boot)

    p = sub.add_parser("trace", help="run one function in the original binary")
    p.add_argument("image")
    p.add_argument("address")
    p.add_argument("--max-insns", type=int, default=10000)
    p.add_argument("--sp", type=lambda s: parse_int(s), default=None, help="stack pointer")
    p.add_argument("--out", default="")
    p.set_defaults(func=cmd_trace)

    p = sub.add_parser("verify", help="fingerprint every truth-lane target in the original binary")
    p.add_argument("--targets", default=None, help="targets JSON (default truth_lane_targets.json)")
    p.add_argument("--max-insns", type=int, default=10000)
    p.add_argument("--out", default="")
    p.set_defaults(func=cmd_verify)

    p = sub.add_parser("compare", help="score original fingerprints vs reconstructed smoke outcomes")
    p.add_argument("--orig", required=True, help="orig_fingerprints.jsonl from verify")
    p.add_argument("--recon", required=True, help="smoke_outcomes.jsonl from truth_lane_smoke.py")
    p.add_argument("--out", default="")
    p.set_defaults(func=cmd_compare)

    return ap


def main() -> int:
    args = build_parser().parse_args()
    if not hasattr(args, "log_limit"):
        args.log_limit = 0
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
