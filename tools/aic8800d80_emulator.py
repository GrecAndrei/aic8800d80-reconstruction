#!/usr/bin/env python3
"""Full-system Unicorn emulator for the AIC8800D80 WiFi/BT firmware.

Loads a raw firmware image at the HARDWARE runtime base 0x120000, models
the MMIO register map from ``src/include/aic8800d80_mmio.h`` (plus an
optional behavioral model from ``aic8800d80_mmio_behavior.json`` that makes
poll/status registers become ready and strobe registers self-clear), boots
from the IVT reset vector, and logs ordered MMIO traffic with register names.
Also traces single functions and runs the truth-lane target set to produce
ground-truth behavioral fingerprints from the ORIGINAL binary.

CPU model: Cortex-M4 (default). The firmware uses VFP instructions
(``vpush {d8}``), which hardfault on a plain Cortex-M3; M4/M7/M33 execute
them and all four images boot to 300k+ instructions without fault.

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
import functools
import glob
import json
import re
import struct
import sys
from datetime import datetime, timezone
from pathlib import Path

from unicorn import (
    UC_ARCH_ARM,
    UC_ERR_EXCEPTION,
    UC_HOOK_CODE,
    UC_HOOK_INSN_INVALID,
    UC_HOOK_MEM_FETCH_UNMAPPED,
    UC_HOOK_MEM_READ,
    UC_HOOK_MEM_READ_UNMAPPED,
    UC_HOOK_MEM_WRITE,
    UC_HOOK_MEM_WRITE_UNMAPPED,
    UC_MEM_READ,
    UC_MEM_READ_UNMAPPED,
    UC_MEM_WRITE,
    UC_MEM_WRITE_UNMAPPED,
    UC_MODE_THUMB,
    Uc,
    UcError,
)
from unicorn.arm_const import (
    UC_ARM_REG_LR,
    UC_ARM_REG_PC,
    UC_ARM_REG_R0,
    UC_ARM_REG_SP,
    UC_CPU_ARM_CORTEX_M3,
    UC_CPU_ARM_CORTEX_M4,
)

REPO = Path(__file__).resolve().parent.parent
SRC = REPO / "src"
MMIO_HEADER = SRC / "include" / "aic8800d80_mmio.h"
MMIO_BEHAVIOR_PATH = SRC / "include" / "aic8800d80_mmio_behavior.json"
TARGETS_DEFAULT = REPO / "extraction_out" / "reconstruction" / "truth_lane_state" / "truth_lane_targets.json"
SCAN_GLOB = REPO / "harness_v25" / "out" / "{}_bin_funcs.jsonl"
FIRMWARE_DIR = REPO / "inputs" / "firmware"
# v26 unified naming dataset: one JSON per function, analysis-space addr -> fn.
NAMES_GLOB = (REPO / "artifacts" / "releases" / "aic8800d80-rebuild-v26-unified"
              / "names" / "*__{}_bin.json")

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
# The firmware references low-SRAM globals up to ~0x20ff04 (bt_init_entry writes
# a config pointer there); 512KB was too small. Unicorn commits large mem_map
# calls unreliably, so SRAM is mapped in 512KB chunks below (see _map_memory)
# up to the 0x21000000 heap base.
SRAM_SIZE = 0x1000000
SRAM_CHUNK = 0x80000
HEAP_BASE = 0x21000000
HEAP_SIZE = 0x10000
# Buffer pool / PSRAM region: the firmware's message/buffer pool lives at
# 0x04000000 (base constant in message_dispatch ``set_flag(0x4000000)``,
# buffer_pool_manage ``sub_12CA88``), with literal references up to
# 0x07ffffff. Not touched during boot (pool limit ``[0x1922c0]`` is 0 until
# runtime), so pages are mapped lazily on first access by on_unmapped.
BUFFER_POOL_BASE = 0x04000000
BUFFER_POOL_END = 0x08000000
MMIO_PHANTOM_BASE = 0x40000000  # APB/AHB peripherals (IDA phantom segment)
MMIO_PHANTOM_END = 0x60000000
RETURN_STOP = 0xDEADC000
PAGE_SIZE = 0x1000

# Boot-ROM callback slots: the firmware calls through these fixed low-memory
# vectors (`mov rN,#slot; ldr rM,[rN]; bx/blx rM`). The boot ROM populates
# them before the image runs; the emulator seeds them with a no-op stub so
# the indirect call returns cleanly instead of branching to 0. All four
# images use 0x1b0/0x1b4/0x1b8/0x1c8/0x1d8; the fmac images add 0x1fc and
# lmac_rf adds 0x1d0/0x1d4/0x1e0. Seeding the union is harmless for images
# that don't reference a slot. The recon smoke side stubs these same calls
# to return 0 (truth_lane_smoke), so a returning-0 stub keeps both sides
# comparable.
BOOT_CALLBACK_SLOTS = (0x1b0, 0x1b4, 0x1b8, 0x1c8, 0x1d0, 0x1d4, 0x1d8, 0x1e0, 0x1fc)

# Low shared-memory window: inter-core handoff globals (0x0020ff04 etc.).
LOW_SHM_BASE = 0x00200000
LOW_SHM_SIZE = 0x00200000

# Allocator free-entry addresses per image. The custom heap allocator derefs the
# block pointer before any NULL check, so ``free(NULL)`` (which the firmware
# legitimately calls on allocation-failure error paths) hardfaults. The C
# standard defines free(NULL) as a no-op; the emulator honors that by returning
# from these entries immediately when r0 == 0. (Same allocator, relocated.)
ALLOC_FREE_ENTRIES = {
    "fmacfw_8800d80_h_u02": (0x14CA88,),
    "fmacfw_8800d80_u02": (0x14CBC8,),
    "fmacfwbt_8800d80_u02": (0x14CDF0,),
    "lmacfw_rf_8800d80_u02": (0x13E078,),
}
BOOT_STUB_BASE = 0x20080000    # dedicated stub page just past main SRAM
BOOT_STUB_BYTES = b"\x00\x20\x70\x47"  # Thumb: movs r0,#0 ; bx lr

# Spin-breaker: a function blocked on an OS wait loops on a completion flag
# (`while (*flag != 0)` crypto/BT semaphore, `while (*flag == 0)` wait-event
# primitive). The real interrupt / other-core path would deliver the event; the
# standalone emulator can't. Two mechanisms, both opt-in per function run
# (``spin_break=True``), never during boot where the real init sets the flags:
#
#  1. Memory-flip: when the SAME address is read from the SAME pc repeatedly
#     with a STABLE value, the loop is waiting on it. Deliver the event ONLY
#     for a set boolean flag (value == 1, a `while (x != 0)` wait) by clearing
#     it. A value of 0 is never overwritten: the field may be a POINTER being
#     waited on to become non-NULL (`while (p == 0)`), and writing a fake
#     pointer there makes the code deref garbage. (The value-stability check
#     keeps a busy/changing counter from being clobbered.)
#  2. Branch-jump: a wait that cached the flag in a register (`ldr r3,[flag];
#     cmp r3,#0; bne` never re-reads memory, so mechanism 1 can't fire), and
#     `== 0` memory waits whose flag must NOT be overwritten. A backward branch
#     executed repeatedly, with a candidate-global read recently and no
#     candidate-global write since, is such a spin: jump past the branch
#     (pc+2) so the wait exits. The flag field is left untouched.
SPIN_BREAK_READS = 4        # reads of (pc, addr) before flipping
SPIN_BREAK_BRANCH = 6       # executions of one backward-branch pc before jumping
SPIN_BREAK_WINDOW = 2000    # max insn gap between events to count as one spin
# Only value the memory-flip ever writes: 0, to a flag currently == 1 (a set
# boolean being waited on to clear: `while (x != 0)`). Clearing a set flag is
# unambiguous. NEVER write a large value: a field read as 0 may be a POINTER
# being waited on to become non-NULL (`while (p == 0)`), and overwriting it
# with 0x7fffffff makes the code deref garbage (WRITE_UNMAPPED 0x7fffffff).
# Those `== 0` waits are exited by the branch-jump instead, which just skips
# the loop without touching the field.
# Flag candidate space: image/BSS window + stack (0x120000-0x200000), the low
# shared-memory window (0x200000-0x400000) and main SRAM/heap (0x20000000+).
# Excludes real peripherals (APB/AHB/system control) and the phantom/null
# regions (0x60000000+), where a data read is never a wait flag.
SPIN_BREAK_ADDR_LO = 0x120000
SPIN_BREAK_ADDR_HI = 0x60000000

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


def load_mmio_behavior(path: Path | None = None) -> dict[str, dict]:
    """Load the behavioral MMIO model: {addr_lower_hex: {name, role, behavior}}.

    Empty dict when the model is absent, so the emulator runs unchanged.
    """
    path = path or MMIO_BEHAVIOR_PATH
    if not path.is_file():
        return {}
    try:
        doc = json.loads(path.read_text())
    except json.JSONDecodeError:
        return {}
    regs = doc.get("registers", {})
    return {str(a).lower(): v for a, v in regs.items()}


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

def _is_placeholder_name(name: str) -> bool:
    """True for IDA/pipeline placeholder labels that carry no information."""
    n = name.strip()
    return (n.startswith("sub_") or n.startswith("loc_") or n.startswith("unk_")
            or n.startswith("off_") or n.startswith("j_")
            or n.startswith("log_sub_") or n == "")


@functools.lru_cache(maxsize=None)
def _load_v26_names(image: str) -> dict[int, str]:
    """analysis-space addr -> fn name from the v26 unified naming dataset.

    One JSON per function, keyed in the dataset by analysis-space address
    (e.g. 0x111e60 -> rf_bus_setup_n_9c). Cached because ``load_function_table``
    is called once per function run in the corpus sweep.
    """
    out: dict[int, str] = {}
    for p in glob.glob(str(NAMES_GLOB).format(image)):
        try:
            j = json.loads(Path(p).read_text())
        except (OSError, json.JSONDecodeError):
            continue
        addr = j.get("addr")
        # The dataset writes the LLM's proposed name in the ``name`` field but
        # often leaves ``fn`` as the original ``sub_<addr>`` placeholder (and
        # keeps the ``sub_<addr>`` filename). Prefer ``name``, fall back to
        # ``fn``, and drop pure placeholders so they never clobber a better
        # scan name.
        fn = j.get("name") or j.get("fn")
        if isinstance(addr, str) and addr.lower().startswith("0x") and fn:
            if _is_placeholder_name(fn):
                continue
            try:
                out[int(addr, 16)] = fn
            except ValueError:
                continue
    return out


def load_function_table(image: str) -> list[tuple[int, str]]:
    """Return sorted [(address, name)] from the fwstruct scan JSONL.

    Scan addresses are the project's analysis-space "model" addresses (e.g.
    ``start`` at 0x100100). The emulator runs every entry at hardware base
    0x120000, so the table is shifted +HW_OFFSET so ``resolve_pc_name`` can
    match runtime PCs (a 0x20000 offset would otherwise break function-frame
    and depth-0 tracking).

    Scan names are the raw IDA ``sub_*`` placeholders; the v26 unified naming
    dataset overlays meaningful names (analysis-space keyed) when available.
    """
    path = Path(str(SCAN_GLOB).format(image))
    v26 = _load_v26_names(image)
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
        # The scan registers ``start`` at file 0x100 (the IVT/header base); the
        # real CPUID-check entry is at file 0x1a8 (== the IVT reset vector).
        if name == "start" and addr == ANALYSIS_BASE + 0x100:
            addr = ANALYSIS_BASE + 0x1A8
        # Overlay the unified naming dataset name when the dataset has one
        # (``_load_v26_names`` already drops pure placeholders, so a dataset
        # record can never clobber a better scan name like firmware_init).
        if v26_name := v26.get(addr):
            name = v26_name
        table.append((addr + HW_OFFSET, name))
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
                 cpu_model: int = UC_CPU_ARM_CORTEX_M4,
                 behavior_model: dict[str, dict] | None = None):
        self.image_path = Path(image_path)
        self.image = self.image_path.read_bytes()
        self.image_addr = CHIP_BASE
        self.mmio_model = mmio_model if mmio_model is not None else load_mmio_model()
        self.behavior_model = (behavior_model if behavior_model is not None
                               else load_mmio_behavior())
        self.function_table: list[tuple[int, str]] = []

        if len(self.image) > IMAGE_MAX:
            raise SystemExit(f"image too large: {len(self.image):#x} > {IMAGE_MAX:#x}")

        self.mu = Uc(UC_ARCH_ARM, UC_MODE_THUMB)
        self.mu.ctl_set_cpu_model(cpu_model)

        self._map_memory()

        self.traffic: list[dict] = []
        self.mmio_state: dict[int, int] = {}
        self.mmio_auto_mapped: set[int] = set()
        # Behavioral-model state.
        self._poll_reads: dict[int, int] = {}
        self._strobe_until: dict[int, int] = {}
        self.insn_count = 0
        self.branch_taken = 0
        self.cur_fn: str | None = None
        self.fn_entries: list[str] = []
        self.call_stack: list[str] = []
        self.call_depth = 0
        # Set by the null-function-pointer hook; run() re-enters at this LR.
        self._null_return_lr: int | None = None
        # Set by the udf-assert hook; run() re-enters here (skipping the udf).
        self._skip_to: int | None = None
        # Spin-breaker: enabled per run() call (not during boot). Flipped wait
        # flags live in ``_spin_counts`` (reset at the start of every run).
        self._spin_break = False
        self._spin_counts: dict[tuple[int, int], tuple[int, int, int]] = {}
        self._spin_last_read = -10**9    # insn of most recent candidate-global read
        self._spin_last_read_addr = 0
        self._spin_last_write = -10**9   # insn of most recent candidate-global write
        self._spin_branches: dict[int, tuple[int, int, int]] = {}
        # Per-image allocator free entries (null-safe free).
        img_name = self.image_path.name
        if img_name.endswith(".bin"):
            img_name = img_name[:-4]
        self._free_entries: tuple[int, ...] = ALLOC_FREE_ENTRIES.get(img_name, ())

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
        # Null shadow page: firmware error paths deref a NULL block pointer
        # (free on an allocation failure, list op on an empty head) reading /
        # writing 0xfffffff0..0xffffffff. On real hardware those paths are
        # unreachable (the subsystems are initialized); in the standalone corpus
        # they are reachable, so absorb them: reads see 0, writes are dropped.
        self._map_rwx(0xfffff000, PAGE_SIZE)
        try:
            self.mu.mem_write(0xfffff000, b"\x00" * PAGE_SIZE)
        except UcError:
            pass
        # Low shared-memory window (2MB .. 4MB): bt_init_entry stores a config
        # pointer at 0x0020ff04 (inter-core handoff), and other globals live in
        # 0x00200000-0x00400000. Not in the MMIO model; model as plain RAM.
        self._map_rwx(LOW_SHM_BASE, LOW_SHM_SIZE)
        try:
            self.mu.mem_write(LOW_SHM_BASE, b"\x00" * LOW_SHM_SIZE)
        except UcError:
            pass
        # Main SRAM + heap (mapped in chunks: unicorn silently truncates large
        # single mem_map calls).
        for base in range(SRAM_BASE, SRAM_BASE + SRAM_SIZE, SRAM_CHUNK):
            self._map_rwx(base, SRAM_CHUNK)
        self._map_rwx(HEAP_BASE, HEAP_SIZE)
        for base in range(SRAM_BASE, SRAM_BASE + SRAM_SIZE, SRAM_CHUNK):
            try:
                self.mu.mem_write(base, b"\x00" * SRAM_CHUNK)
            except UcError:
                pass
        try:
            self.mu.mem_write(HEAP_BASE, b"\x00" * HEAP_SIZE)
        except UcError:
            pass
        self._seed_boot_callbacks()

    def _seed_boot_callbacks(self) -> None:
        """Install a no-op stub and point the boot-ROM callback slots at it.

        The firmware calls through fixed low-memory vectors (0x1b0/0x1b4/
        0x1b8 + one image-specific slot) that the boot ROM populates before
        the image runs. Without seeding, the emulator reads 0 there and the
        indirect call ``bx r3`` branches to address 0 (invalid instruction).
        We write a tiny Thumb ``movs r0,#0; bx lr`` stub into a dedicated
        page and point every slot at it, so the call returns 0 exactly like
        the reconstruction smoke's stub does.
        """
        stub = BOOT_STUB_BASE
        try:
            self._map_rwx(stub & ~(PAGE_SIZE - 1), PAGE_SIZE)
            self.mu.mem_write(stub, BOOT_STUB_BYTES)
        except UcError:
            return
        # Slots live in the low boot-ROM page (0x0-0xFFF); map it so the
        # seeded values are readable (on_mem fires for mapped reads, leaving
        # the value we wrote intact).
        low = 0x0
        try:
            self._map_rwx(low, PAGE_SIZE)
        except UcError:
            return
        for slot in BOOT_CALLBACK_SLOTS:
            try:
                # Thumb bit set: bx r3 enters Thumb mode at the stub.
                self.mu.mem_write(slot, struct.pack("<I", stub | 1))
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
            # A return into the low region (bx lr with a null LR, or a branch
            # through a low handler) is the null-call / null-return class.
            if pc < 0x10000:
                self._null_return(uc)
                return
            # free(NULL) is a no-op per C semantics; the firmware's allocator
            # derefs before checking, so return immediately when the free entry
            # is entered with r0 == 0.
            if self._free_entries and pc in self._free_entries:
                if uc.reg_read(UC_ARM_REG_R0) == 0:
                    lr = uc.reg_read(UC_ARM_REG_LR)
                    if lr >= 0x200:
                        uc.reg_write(UC_ARM_REG_PC, lr)
                        return
            # Spin-breaker, mechanism 2 (register-cached wait): a backward
            # branch executed repeatedly, with a candidate-global read recently
            # and no candidate-global write since, is a wait spin whose flag
            # never re-enters memory (``cmp rN,#0; bne``). Jump past it.
            if (self._spin_break and self._is_backward_branch(pc)):
                n, last, seen = self._spin_branches.get(pc, (0, -10**9, -1))
                # A wait-spin re-reads the SAME flag; a data-structure walk
                # advances its read address each iteration (r5 += 8; ldr [r5]).
                # Reset when the read address changes or the gap is too large.
                if (self.insn_count - last > SPIN_BREAK_WINDOW
                        or seen != self._spin_last_read_addr):
                    n = 0
                n += 1
                self._spin_branches[pc] = (n, self.insn_count,
                                           self._spin_last_read_addr)
                if (n >= SPIN_BREAK_BRANCH
                        and self._spin_last_read > self._spin_last_write
                        and self.insn_count - self._spin_last_read
                        <= SPIN_BREAK_WINDOW):
                    # Jump past the loop via the proven emu_stop + re-entry
                    # path (direct PC writes inside a code hook are unreliable
                    # here). run() re-enters at (pc+2)|1, Thumb-correct.
                    # The wait's flag field is deliberately NOT written: the
                    # observed waits (crypto semaphore, log assert) only gate
                    # on it and never consume its value downstream, so skipping
                    # the loop is sufficient and can't corrupt a pointer field.
                    self._skip_to = pc + 2
                    uc.emu_stop()
                    self._spin_branches[pc] = (0, self.insn_count,
                                               self._spin_last_read_addr)
                    return
            self.insn_count += 1
            self._note_function(pc)

        # Null / garbage function-pointer call: a call through an uninitialized
        # handler field branches into the low boot-ROM data page. Real code
        # starts at 0x120000+, so any fetch below 0x10000 is a bad call (the
        # mapped low page decodes as INSN_INVALID after a blx switches to ARM
        # mode, which real Cortex-M would hardfault on; the 0x1000 gap is an
        # unmapped fetch). Real firmware populates these handler tables at
        # runtime init; the standalone corpus never does. Stop and have ``run``
        # re-enter at the return address with r0=0 so the caller's error path
        # handles the NULL result instead of hardfaulting.
        LOW_CODE_CEIL = 0x10000  # nothing executable below this on this firmware

        def on_insn_invalid(uc, *args):
            pc = int(uc.reg_read(UC_ARM_REG_PC))
            if pc < LOW_CODE_CEIL:
                self._null_return(uc)
                return True
            # Firmware assert: `udf #255` (halfword 0xDEFF, stored LE as ff de).
            # These fire only when the standalone corpus lacks the runtime
            # context real hardware provides (uninitialized struct, invalid free
            # pointer). Skip the 2-byte udf (re-enter at pc+2) so the function
            # continues past the assertion instead of faulting.
            if CHIP_BASE <= pc < CHIP_BASE + len(self.image) - 1:
                off = pc - CHIP_BASE
                if (self.image[off] | (self.image[off + 1] << 8)) == 0xDEFF:
                    self._skip_to = pc + 2
                    uc.emu_stop()
                    return True
            # Any OTHER invalid instruction at a high PC is a garbage indirect
            # branch (a ``bx``/``blx``/``pop {pc}`` landing mid-instruction,
            # e.g. 0x1252c8 inside a 4-byte ``vmrs``) or an even-address Thumb
            # violation — the same class as the null-call the low-PC check
            # catches, but with a target inside real code. The firmware is
            # valid compiled code, so this only happens through an
            # uninitialized handler / stack slot. Return via LR (r0 = 0) so
            # the caller's error path handles it.
            self._null_return(uc)
            return True

        def on_unmapped_fetch(uc, access, address, size, value, user_data):
            # EVERY unmapped fetch is a garbage branch: real code (image
            # 0x120000+, boot-ROM below 0x10000) is always mapped, so a fetch
            # from unmapped space (e.g. 0x40000, in the 0x10000-0x120000 gap)
            # can only come from a corrupted return address / uninitialized
            # handler slot. Return via LR (r0 = 0) so the caller's error path
            # handles it, same as the INSN_INVALID garbage-branch path.
            self._null_return(uc)
            return True

        def on_mem(uc, access, address, size, value, user_data):
            addr = int(address)
            # Spin-breaker (wait-loop event delivery) runs BEFORE the MMIO
            # branch so image/BSS-window flags (0x17348c etc., which
            # is_mmio_addr classifies as MMIO) are caught. Only active for
            # per-function runs (``spin_break=True``), never the boot, where
            # the real init path sets those flags itself.
            if (self._spin_break
                    and SPIN_BREAK_ADDR_LO <= addr < SPIN_BREAK_ADDR_HI
                    and not is_periph_addr(addr)):
                if access == UC_MEM_READ:
                    pc = int(uc.reg_read(UC_ARM_REG_PC))
                    self._spin_last_read = self.insn_count
                    self._spin_last_read_addr = addr
                    # The hook's ``value`` arg is undefined for reads; read the
                    # current word ourselves for the stability check.
                    try:
                        v = int.from_bytes(uc.mem_read(addr, size), "little")
                    except UcError:
                        v = 0
                    key = (pc, addr)
                    n, last, val = self._spin_counts.get(key, (0, -10**9, None))
                    if (self.insn_count - last > SPIN_BREAK_WINDOW) or \
                       (val is not None and val != v):
                        n = 0
                    n += 1
                    self._spin_counts[key] = (n, self.insn_count, v)
                    if n >= SPIN_BREAK_READS and v == 1:
                        # Set boolean flag being waited on to clear
                        # (`while (x != 0)`): deliver the event by clearing it.
                        # v == 0 flags are left alone (may be a pointer wait;
                        # the branch-jump exits those loops without touching
                        # the field).
                        try:
                            uc.mem_write(addr, (0).to_bytes(4, "little"))
                        except UcError:
                            pass
                        self._spin_counts[key] = (0, self.insn_count, None)
                else:
                    # A write to the slot means it's live program state
                    # (mutating between reads), not a wait flag. Stack-scratch
                    # writes are exempt: a delay loop decrements a stack local
                    # ([sp,#4]) every iteration, and treating that as "state
                    # mutation" would mask a slow re-check wait that polls a
                    # global counter every ~200 insns.
                    if not (STACK_BASE <= addr < STACK_BASE + STACK_SIZE):
                        self._spin_last_write = self.insn_count
                        # A candidate-global write inside a backward-branch
                        # window means the loop is doing real work (a data
                        # copy / scatter loop mutates memory every iteration),
                        # not waiting on a flag. Such a loop's last read can
                        # look "stable" (e.g. a callee re-loading a mailbox
                        # register address from the same literal-pool slot),
                        # which would otherwise let the branch-jump misfire
                        # and skip past real code into the next function's
                        # alignment padding. Reset the branch counter so the
                        # jump only fires in a genuinely write-free window.
                        self._spin_branches.clear()
                    for k in [k for k in self._spin_counts if k[1] == addr]:
                        del self._spin_counts[k]
            if not is_mmio_addr(addr):
                return
            # call_depth: 0 = accesses made while the target function's own
            # body is on top of the stack (before any callee was entered and
            # after it returned). Used to compare original vs reconstruction
            # on the SAME basis: the reconstruction stubs callees, so the
            # original's callee-register traffic must be excluded too.
            depth = self.call_depth
            if access == UC_MEM_READ:
                # Behavioral injection BEFORE the load executes (UC_HOOK_MEM_READ
                # is a pre-access hook): a poll register becomes ready after N
                # reads, a strobe register clears after its window.
                self._inject_read_value(addr, int(size))
                # Capture the actual read-back value (the phantom model maps a
                # deterministic word, so this is stable) for echo/poll evidence.
                try:
                    rv = int.from_bytes(uc.mem_read(addr, size), "little")
                except UcError:
                    rv = None
                self.traffic.append({
                    "pc": hex(int(uc.reg_read(UC_ARM_REG_PC))),
                    "op": "read",
                    "addr": hex(addr),
                    "name": mmio_name(self.mmio_model, addr),
                    "size": int(size),
                    "depth": depth,
                    "value": hex(rv) if rv is not None else None,
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
                # Behavioral-model state on writes: a poll register is re-armed
                # (read counter reset), a strobe register starts its window.
                bh = self._behavior_for(addr)
                if bh:
                    if bh.get("type") == "poll":
                        self._poll_reads[addr] = 0
                    elif bh.get("type") == "strobe":
                        self._strobe_until[addr] = self.insn_count + int(bh.get("clear_after", 64))

        self.last_unmapped = []  # (pc, access, addr) of the most recent misses

        def on_unmapped(uc, access, address, size, value, user_data):
            addr = int(address)
            pc = int(uc.reg_read(UC_ARM_REG_PC))
            # Record every unmapped access (even non-MMIO) for diagnostics.
            self.last_unmapped.append((pc, access, addr, int(size)))
            if not is_mmio_addr(addr):
                # Non-MMIO unmapped access.
                #  - The buffer-pool region (0x04000000-0x08000000) is real RAM
                #    the firmware writes buffers/descriptors into; map the page
                #    lazily on first access.
                #  - Any other unmapped READ is a deref through an uninitialized
                #    pointer (standalone corpus lacks runtime context); absorb
                #    it by mapping a zero page so reads see 0.
                #  - Unmapped WRITES outside the pool are the same class: a
                #    store through an uninitialized table/array base (e.g.
                #    ``mla r3, r3, r5, r7; strb [r3, #0x56]`` with a garbage
                #    r7). Absorb by mapping a scratch page so the store lands
                #    (read-back consistent) and the function completes instead
                #    of faulting. The scratch page is zero-initialized and
                #    never overlaps real RAM/MMIO.
                if (BUFFER_POOL_BASE <= addr < BUFFER_POOL_END) or \
                        access in (UC_MEM_READ_UNMAPPED, UC_MEM_WRITE_UNMAPPED):
                    base = addr & ~(PAGE_SIZE - 1)
                    if base not in self.mmio_auto_mapped:
                        try:
                            uc.mem_map(base, PAGE_SIZE)
                            self.mmio_auto_mapped.add(base)
                        except UcError:
                            return False
                    return True
                return False
            base = addr & ~(PAGE_SIZE - 1)
            if base not in self.mmio_auto_mapped:
                try:
                    uc.mem_map(base, PAGE_SIZE)
                    self.mmio_auto_mapped.add(base)
                except UcError:
                    return False
            # Behavioral injection for the first access of a page; otherwise a
            # deterministic default word (or the last written value).
            bval = self._behavior_read_word(addr, int(size))
            if bval is not None:
                try:
                    lane = (1 << (8 * int(size))) - 1
                    uc.mem_write(addr, int(bval & lane).to_bytes(int(size), "little"))
                except UcError:
                    return False
            else:
                try:
                    word = self.mmio_state.get(addr & ~3, 0)
                    uc.mem_write(addr & ~3, struct.pack("<I", word))
                except UcError:
                    return False
            return True

        self.mu.hook_add(UC_HOOK_CODE, on_code)
        self.mu.hook_add(UC_HOOK_INSN_INVALID, on_insn_invalid)
        self.mu.hook_add(
            UC_HOOK_MEM_FETCH_UNMAPPED, on_unmapped_fetch,
        )
        self.mu.hook_add(UC_HOOK_MEM_READ | UC_HOOK_MEM_WRITE, on_mem)
        self.mu.hook_add(
            UC_HOOK_MEM_READ_UNMAPPED | UC_HOOK_MEM_WRITE_UNMAPPED,
            on_unmapped,
        )

    def _behavior_for(self, addr: int) -> dict | None:
        """The behavior rule dict for a register address (None if unmodeled)."""
        b = self.behavior_model.get(hex(addr).lower())
        if not b:
            return None
        return b.get("behavior") or None

    def _behavior_read_word(self, addr: int, size: int) -> int | None:
        """Value a read of ``addr`` should observe, or None for no rule.

        Updates behavioral state (poll read progression, strobe window).
        The caller writes the returned word to memory before the load reads it.
        """
        bh = self._behavior_for(addr)
        if bh is None:
            return None
        btype = bh.get("type")
        if btype == "poll":
            n = self._poll_reads.get(addr, 0) + 1
            self._poll_reads[addr] = n
            mask = int(bh.get("ready_mask", "0x1"), 16)
            last = self.mmio_state.get(addr, 0)
            if n >= int(bh.get("reads_to_ready", 1)):
                # Ready: config bits preserved, ready bit(s) set.
                return last | mask
            # Not ready yet: config bits preserved, ready bit(s) forced clear.
            return last & ~mask
        if btype == "strobe":
            if self.insn_count < self._strobe_until.get(addr, 0):
                return None  # in window: keep the written value visible
            return 0  # window elapsed: reads see zero
        if btype == "counter":
            # Monotonic hardware tick counter: advances with emulated time so
            # firmware ``while (counter < t + N)`` delay spins terminate.
            rate = int(bh.get("tick_rate", "500"))
            return min(0xFFFFFFFF, self.insn_count // rate)
        return None

    def _inject_read_value(self, addr: int, size: int) -> None:
        val = self._behavior_read_word(addr, size)
        if val is None:
            return
        # Mask to the access size: a byte/halfword read only observes that
        # lane, and a full-word ready_mask (e.g. 0x1825000) would otherwise
        # overflow to_bytes() on a narrow load.
        lane = (1 << (8 * size)) - 1
        try:
            self.mu.mem_write(addr, int(val & lane).to_bytes(size, "little"))
        except UcError:
            pass

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

    def _is_backward_branch(self, pc: int) -> bool:
        """True if ``pc`` holds a 2-byte Thumb branch that targets lower code.

        Used by the spin-breaker's branch-jump: wait loops end in a backward
        ``bne/beq``/``b`` whose fall-through (pc+2) exits the loop.
        """
        if not (CHIP_BASE <= pc < CHIP_BASE + len(self.image) - 1):
            return False
        off = pc - CHIP_BASE
        hw = self.image[off] | (self.image[off + 1] << 8)
        if (hw & 0xF000) == 0xD000:      # Bcc (2-byte): 8-bit signed offset
            return bool(hw & 0x80)
        if (hw & 0xF000) == 0xE000:      # B (2-byte): 11-bit signed offset
            return bool(hw & 0x400)
        return False

    def _null_return(self, uc) -> None:
        """Handle a null / garbage function-pointer call (stop, return 0).

        Called from the INSN_INVALID and low-fetch hooks. Stops the engine and
        records the return address so ``run`` re-enters there with r0=0; when
        LR is garbage too (a corrupt tail-call path), end at the return
        sentinel so the run is classified as returned rather than faulting.
        """
        lr = int(uc.reg_read(UC_ARM_REG_LR))
        # Only re-enter at LR when it's a plausible code address: real code +
        # BSS live in 0x120000-0x1a0000, the low page holds the seeded boot
        # callbacks. An LR into MMIO (0x4xxxxxxx) or elsewhere is garbage —
        # re-entering there fetches instructions from a peripheral and faults.
        if 0x10000 <= lr < 0x1a0000:
            self._null_return_lr = lr
        else:
            self._null_return_lr = None
            uc.reg_write(UC_ARM_REG_PC, RETURN_STOP)
        uc.emu_stop()

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
            lr: int | None = None, spin_break: bool = False) -> tuple[str, dict]:
        """Run from ``entry`` (thumb bit honored) until return, cap, or fault.

        ``spin_break`` enables the wait-loop breaker: a backward-branch wait
        loop (``while (*flag != 0)`` / ``== 0``) with a stable, unwritten read
        address is jumped past, and a set boolean flag (== 1) re-read from the
        same pc is cleared. Kept off during boot, where the real init path sets
        those flags.

        Returns (termination, stats). Termination is one of ``returned`` /
        ``capped`` / ``fault`` / ``exited:0x<pc>`` (completed to a non-sentinel
        pc, e.g. past the 256 re-entry budget of a driver init with many waits).
        """
        self.insn_count = 0
        self.traffic = []
        self.cur_fn = None
        self.fn_entries = []
        self.call_stack = []
        self.call_depth = 0
        self.last_unmapped = []
        self._spin_break = spin_break
        self._spin_counts = {}
        self._spin_last_read = -10**9
        self._spin_last_read_addr = 0
        self._spin_last_write = -10**9
        self._spin_branches = {}
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
        self._null_return_lr = None
        self._skip_to = None

        def on_code_cap(uc, address, size, user_data):
            if self.insn_count >= max_insns:
                stop["value"] = "capped"
                uc.emu_stop()
        cap_hook = self.mu.hook_add(UC_HOOK_CODE, on_code_cap)

        # Null-function-pointer calls, udf asserts and spin-break branch-jumps
        # stop the engine via the INSN_INVALID / code hooks (``_null_return_lr``
        # / ``_skip_to``). emu_start may return normally OR raise; either way
        # re-enter at the recorded address. 256 bounds a pathological chain
        # while leaving room for driver-init functions with many wait-jumps.
        start_ea = entry | 1
        for _ in range(256):
            try:
                self.mu.emu_start(start_ea, RETURN_STOP)
                if self._skip_to is not None:
                    start_ea = self._skip_to | 1
                    self._skip_to = None
                    continue
                if self._null_return_lr is not None:
                    lr = self._null_return_lr
                    self._null_return_lr = None
                    self.mu.reg_write(UC_ARM_REG_R0, 0)
                    start_ea = lr | 1
                    continue
                break
            except UcError as e:
                if self._skip_to is not None:
                    start_ea = self._skip_to | 1
                    self._skip_to = None
                    continue
                if self._null_return_lr is not None:
                    lr = self._null_return_lr
                    self._null_return_lr = None
                    self.mu.reg_write(UC_ARM_REG_R0, 0)
                    start_ea = lr
                    continue
                if getattr(e, "errno", None) == UC_ERR_EXCEPTION:
                    # CPU exception (e.g. ``mcr p0`` = Undefined Instruction).
                    # This firmware has no coprocessors, so such an instruction
                    # only appears as DATA/PADDING misdecoded after a garbage
                    # indirect branch into a data region. Same handling as the
                    # INSN_INVALID garbage branch: return via LR (r0 = 0) so
                    # the caller's error path handles it; if LR is garbage too,
                    # end at the return sentinel.
                    lr = int(self.mu.reg_read(UC_ARM_REG_LR))
                    self.mu.reg_write(UC_ARM_REG_R0, 0)
                    if 0x10000 <= lr < 0x1a0000:
                        start_ea = lr | 1
                    else:
                        self.mu.reg_write(UC_ARM_REG_PC, RETURN_STOP)
                        start_ea = RETURN_STOP
                    continue
                stop["value"] = "fault"
                fault["detail"] = str(e)
                fault["pc"] = hex(self.mu.reg_read(UC_ARM_REG_PC))
                if self.last_unmapped:
                    pc0, acc, addr, sz = self.last_unmapped[-1]
                    fault["access"] = ("read" if acc in (UC_MEM_READ, UC_MEM_READ_UNMAPPED)
                                       else "write")
                    fault["address"] = hex(addr)
                    fault["size"] = sz
                break

        self.mu.hook_del(cap_hook)

        if stop["value"] == "running":
            pc = self.mu.reg_read(UC_ARM_REG_PC)
            if pc in (RETURN_STOP, RETURN_STOP | 1) or pc < 0x10000:
                # Return to the sentinel, or to a null/low return address
                # (pop {pc} from a caller-less stack slot): the function
                # completed; classify as returned.
                stop["value"] = "returned"
            else:
                stop["value"] = f"exited:0x{pc:x}"

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
