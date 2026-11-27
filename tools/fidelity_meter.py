#!/usr/bin/env python3
"""fidelity_meter.py — 4-axis behavioral & structural fidelity meter for AIC8800D80.

Replaces single-vector MMIO-only corpus parity (which saturates at DIFFER=0
while hiding return-value, RAM-write, bootstate, and input-gated defects) with
an explicit four-axis measurement across all composed functions:

  Axis 1 — Static & Link Integrity:
    - post_compose --check pending count, make reproduce, full_link report
    - JUMPOUT / MEMORY[] / COERCE_* leftovers
    - Under-arity cast-calls: ((T (*)())callee)(...) passing fewer args than
      callee's defined prototype
  Axis 2 — Default-State Full Equivalence ((0, 0, 0, 0) on zeroed RAM):
    - Compares ordered MMIO writes + non-stack persistent RAM byte deltas +
      non-void return value r0 + termination status
    - Uses hook-free final region snapshots (avoiding Unicorn 2.1.4 TCG bugs
      triggered by UC_HOOK_MEM_WRITE over executing code/stack)
    - Surfaces "mmio_only_hidden_differ" where old MMIO-only matching hid an
      r0 or RAM divergence, plus "exercised" vs "vacuous" matches
  Axis 3 — Multi-Vector Bootstate Equivalence:
    - Re-runs every function under captured 300k bootstate across:
        * boot_zero:   (0, 0, 0, 0) + bootstate
        * boot_scalar: (1, 2, 3, 4) + bootstate
        * boot_neg:    (0xffffffff, 0xffffffff, 1, 1) + bootstate
        * boot_ptr:    (0x20002000, 0x20002400, 1, 1) + bootstate + seeded SRAM
    - Aggregates per-function verdict across all 5 vectors and reports
      "exercised behavioral coverage" (functions proven with non-trivial output)
  Axis 4 — End-to-End Boot Trace & Truth-Lane Gate:
    - Truth-lane 25 targets verified with FULL (MMIO + RAM + r0) parity
    - End-to-end boot trace from reset entry measuring prefix MMIO write parity
      up to first divergence (or full boot window)

Usage:
  python3 tools/fidelity_meter.py
  python3 tools/fidelity_meter.py --image lmacfw_rf_8800d80_u02 --no-build-check
  python3 tools/fidelity_meter.py --out /tmp/fidelity_detail --json metadata/fidelity_meter.json
"""
from __future__ import annotations

import argparse
import collections
import json
import multiprocessing
import re
import subprocess
import sys
import time
from pathlib import Path

from elftools.elf.elffile import ELFFile
from unicorn import UC_HOOK_CODE
from unicorn.arm_const import (
    UC_ARM_REG_PC,
    UC_ARM_REG_R0,
    UC_ARM_REG_R1,
    UC_ARM_REG_R2,
    UC_ARM_REG_R3,
)

TOOLS_DIR = Path(__file__).resolve().parent
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

import aic8800d80_emulator as emu
import composed_source
import corpus_sweep as cs
import linked_recon_run as lrr
import prototype_infer

REPO = TOOLS_DIR.parent
DEFAULT_JSON = REPO / "metadata" / "fidelity_meter.json"
IMAGES = [
    "fmacfw_8800d80_h_u02",
    "fmacfw_8800d80_u02",
    "fmacfwbt_8800d80_u02",
    "lmacfw_rf_8800d80_u02",
]
SHORT = lrr.SHORT

MARKER_RE = re.compile(r"^//\s+(\S+)\s+@\s+(0x[0-9a-fA-F]+)\s*$", re.MULTILINE)
CAST_CALL_PREFIX_RE = re.compile(
    r"\(\([^;{}]*\(\s*\*?\s*\)\s*\(\s*(?:void\s*)?\)\s*\)\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)\s*\("
)
JUMPOUT_RE = re.compile(r"\bJUMPOUT\s*\(")
MEMORY_RE = re.compile(r"\bMEMORY\s*\[")
UNINIT_RESULT_RE = re.compile(r"^\s*[A-Za-z_][\w\s\*]*\bresult\s*;\s*(?://.*)?$", re.MULTILINE)
RESULT_WRITE_RE = re.compile(r"(?:\bresult\s*=|\*\([^;\n]*\)\s*&result\s*=)", re.MULTILINE)
PSEUDO_REG_NAMES = {
    "_R0", "_R1", "_R2", "_R3", "_R4", "_R5", "_R6", "_R7",
    "_R8", "_R9", "_R10", "_R11", "_R12", "_SP", "_LR", "_PC",
    "_CF", "_ZF", "_NF", "_OF", "_VF", "MEMORY_IMG",
}

SRAM_PTR_A = 0x20002000
SRAM_NODE_A = 0x20002200
SRAM_PTR_B = 0x20002400
SRAM_NODE_B = 0x20002600

# Fixed non-stack persistent RAM windows (strictly below 16KB top-of-stack [0x19c000..0x1a0000)).
RAM_WINDOWS: tuple[tuple[int, int], ...] = (
    (0x00000000, 0x00001000),  # Low boot-ROM / VTOR slots
    (0x00120000, 0x0007C000),  # Image bytes, .data/.bss, boot globals < 0x19c000
    (0x00200000, 0x00200000),  # Low shared-memory window (LOW_SHM)
    (0x20000000, 0x00100000),  # Main SRAM low 1MB (covers 0x20002000 structs & 0x20080000 stub)
    (0x20FF0000, 0x00010000),  # High SRAM handoff window
    (0x21000000, 0x00010000),  # Heap window
)
NULL_SHADOW_PAGE = 0xFFFFF000

DEFAULT_VECTORS = ("bare_zero", "boot_zero", "boot_scalar", "boot_neg", "boot_ptr", "boot_double")
ALL_VECTORS = {
    "bare_zero":   {"bootstate": False, "sram_seed": False, "args": (0, 0, 0, 0)},
    "boot_zero":   {"bootstate": True,  "sram_seed": False, "args": (0, 0, 0, 0)},
    "boot_scalar": {"bootstate": True,  "sram_seed": False, "args": (1, 2, 3, 4)},
    "boot_neg":    {"bootstate": True,  "sram_seed": False, "args": (0xFFFFFFFF, 0xFFFFFFFF, 1, 1)},
    "boot_ptr":    {"bootstate": True,  "sram_seed": True,  "args": (SRAM_PTR_A, SRAM_PTR_B, 1, 1)},
    # Softfp register pairs encode two finite nonzero doubles: 1.5 in r0/r1
    # and -2.25 in r2/r3. This exercises high-word arithmetic/control flow that
    # scalar integer vectors cannot reach while remaining ordinary input data.
    "boot_double": {"bootstate": True,  "sram_seed": False, "args": (0, 0x3FF80000, 0, 0xC0020000)},
}


# ---------------------------------------------------------------------------
# Source parsing & static integrity scanner (Axis 1)
# ---------------------------------------------------------------------------

def _split_param_list(param_str: str) -> tuple[list[str] | None, bool]:
    """Return (fixed parameter declarations or None if unspecified, has_varargs)."""
    s = param_str.strip()
    if s == "":
        return None, False
    if s == "void":
        return [], False
    parts: list[str] = []
    depth = 0
    cur: list[str] = []
    for ch in s:
        if ch in "([":
            depth += 1
        elif ch in ")]":
            depth = max(0, depth - 1)
        if ch == "," and depth == 0:
            parts.append("".join(cur).strip())
            cur = []
        else:
            cur.append(ch)
    if cur:
        parts.append("".join(cur).strip())
    has_varargs = bool(parts and parts[-1] == "...")
    if has_varargs:
        parts = parts[:-1]
    return parts, has_varargs


def _split_params(param_str: str) -> tuple[int | None, bool]:
    """Return (fixed_param_count_or_None_if_unspecified, has_varargs)."""
    parts, varargs = _split_param_list(param_str)
    return (None if parts is None else len(parts)), varargs


def _normalize_abi_arg(value: int, decl: str) -> int:
    """Normalize a raw injected rN value to a narrow integer parameter type."""
    d = re.sub(r"\s+", " ", decl)
    signed = width = None
    if re.search(r"\b(?:uint8_t|unsigned char|_BYTE|bool)\b", d):
        signed, width = False, 8
    elif re.search(r"\b(?:int8_t|signed char|char|__int8)\b", d):
        signed, width = True, 8
    elif re.search(r"\b(?:uint16_t|unsigned short|_WORD)\b", d):
        signed, width = False, 16
    elif re.search(r"\b(?:int16_t|signed short|short|__int16)\b", d):
        signed, width = True, 16
    if width is None:
        return value & 0xFFFFFFFF
    mask = (1 << width) - 1
    value &= mask
    if signed and value & (1 << (width - 1)):
        value -= 1 << width
    return value & 0xFFFFFFFF


def normalize_abi_args(args: tuple[int, int, int, int], param_types: list[str] | None) -> tuple[int, int, int, int]:
    if not param_types:
        return args
    out = list(args)
    for i, decl in enumerate(param_types[:4]):
        out[i] = _normalize_abi_arg(out[i], decl)
    return tuple(out)  # type: ignore[return-value]


def _extract_balanced_parens(text: str, open_idx: int) -> tuple[str, int] | None:
    """Return (inner_text, close_idx) matching text[open_idx] == '('."""
    depth = 0
    in_str = False
    in_chr = False
    esc = False
    for i in range(open_idx, len(text)):
        ch = text[i]
        if esc:
            esc = False
            continue
        if ch == "\\" and (in_str or in_chr):
            esc = True
            continue
        if in_str:
            if ch == '"':
                in_str = False
            continue
        if in_chr:
            if ch == "'":
                in_chr = False
            continue
        if ch == '"':
            in_str = True
        elif ch == "'":
            in_chr = True
        elif ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
            if depth == 0:
                return text[open_idx + 1 : i], i
    return None


def _count_call_args(text: str, open_paren_idx: int) -> tuple[int | None, int]:
    """Given index of '(' opening a call's arg list, return (arg_count, close_idx)."""
    n = len(text)
    depth = 0
    count = 0
    has_tokens = False
    in_str = False
    in_chr = False
    esc = False
    i = open_paren_idx
    while i < n:
        ch = text[i]
        if esc:
            esc = False
            i += 1
            continue
        if ch == "\\" and (in_str or in_chr):
            esc = True
            i += 1
            continue
        if in_str:
            if ch == '"':
                in_str = False
            i += 1
            continue
        if in_chr:
            if ch == "'":
                in_chr = False
            i += 1
            continue
        if ch == '"':
            in_str = True
            has_tokens = True
        elif ch == "'":
            in_chr = True
            has_tokens = True
        elif ch in "([{":
            if i != open_paren_idx:
                has_tokens = True
            depth += 1
        elif ch in ")]}":
            depth -= 1
            if depth == 0:
                if has_tokens:
                    count += 1
                return count, i
            has_tokens = True
        elif ch == "," and depth == 1:
            count += 1
            has_tokens = False
        elif not ch.isspace():
            has_tokens = True
        i += 1
    return None, n


def _parse_fn_signature(block: str) -> dict:
    """Extract (c_name, is_void, param_count, has_varargs, has_c_body, body_offset)."""
    pos = 0
    # Skip leading // doc or /* libmatch */ comments inside the marker block.
    while pos < len(block):
        while pos < len(block) and block[pos].isspace():
            pos += 1
        if block.startswith("//", pos):
            nl = block.find("\n", pos)
            pos = len(block) if nl < 0 else nl + 1
        elif block.startswith("/*", pos):
            end = block.find("*/", pos + 2)
            pos = len(block) if end < 0 else end + 2
        else:
            break

    sig_start = pos
    paren_idx = block.find("(", pos)
    if paren_idx < 0:
        return {"c_name": None, "is_void": False, "param_count": None,
                "has_varargs": False, "has_c_body": False, "body_offset": pos}

    head = block[sig_start:paren_idx]
    if ";" in head or "{" in head:
        return {"c_name": None, "is_void": False, "param_count": None,
                "has_varargs": False, "has_c_body": False, "body_offset": pos}

    # Distinguish normal `ret fn(args) {` vs function-pointer param parens inside args.
    bal = _extract_balanced_parens(block, paren_idx)
    if bal is None:
        return {"c_name": None, "is_void": False, "param_count": None,
                "has_varargs": False, "has_c_body": False, "body_offset": pos}
    param_str, close_idx = bal
    after = block[close_idx + 1 :].lstrip()
    if not after.startswith("{"):
        return {"c_name": None, "is_void": False, "param_count": None,
                "has_varargs": False, "has_c_body": False, "body_offset": pos}

    m_name = re.search(r"([A-Za-z_][A-Za-z0-9_]*)\s*$", head)
    if not m_name:
        return {"c_name": None, "is_void": False, "param_count": None,
                "has_varargs": False, "has_c_body": False, "body_offset": pos}
    c_name = m_name.group(1)
    ret_prefix = head[: m_name.start()].strip()
    is_void = bool(re.match(r"^(?:static\s+|inline\s+|__attribute__\s*\([^)]*\)\s+)*void\s*$", ret_prefix))
    param_types, varargs = _split_param_list(param_str)
    pcount = None if param_types is None else len(param_types)
    body_offset = block.find("{", close_idx + 1) + 1
    return {
        "c_name": c_name,
        "return_type": ret_prefix,
        "is_void": is_void,
        "param_count": pcount,
        "param_types": param_types,
        "has_varargs": varargs,
        "has_c_body": True,
        "body_offset": body_offset,
    }


def parse_composed_functions(text: str) -> dict[int, dict]:
    """Parse every `// name @ 0xADDR` composed block in main.c into {addr: meta}."""
    matches = list(MARKER_RE.finditer(text))
    out: dict[int, dict] = {}
    for idx, m in enumerate(matches):
        marker_name = m.group(1)
        addr = int(m.group(2), 16)
        block_start = m.end() + 1 if m.end() < len(text) and text[m.end()] == "\n" else m.end()
        block_end = matches[idx + 1].start() if idx + 1 < len(matches) else len(text)
        block = text[block_start:block_end]
        sig = _parse_fn_signature(block)
        body = block[sig["body_offset"] :] if sig["has_c_body"] else ""
        is_void_ub = bool(
            marker_name.startswith("nullsub_")
            or (
                sig["has_c_body"]
                and UNINIT_RESULT_RE.search(body)
                and not RESULT_WRITE_RE.search(body)
            )
        )
        libmatch_desc = None
        libmatch_target = None
        libmatch_linked = False
        libmatch_dropped = False
        lm = re.search(r"/\* libmatch: ([^*]+)\*/", block)
        if lm:
            libmatch_desc = lm.group(1).strip()
            libmatch_linked = "library routine is linked" in libmatch_desc
            libmatch_dropped = "dropped" in libmatch_desc
            tm = re.search(r"identical to ([^ ;]+)", libmatch_desc)
            if tm:
                libmatch_target = tm.group(1)
        out[addr] = {
            "addr": addr,
            "marker": marker_name,
            "c_name": sig["c_name"] or marker_name,
            "return_type": sig.get("return_type"),
            "is_void": sig["is_void"],
            "is_void_ub": is_void_ub,
            "param_count": sig["param_count"],
            "param_types": sig.get("param_types"),
            "has_varargs": sig["has_varargs"],
            "has_c_body": sig["has_c_body"],
            "body": body,
            "libmatch_target": libmatch_target,
            "libmatch_linked": libmatch_linked,
            "libmatch_dropped": libmatch_dropped,
        }
    return out


def scan_static_defects(image: str) -> dict:
    """Scan composed main.c of one image for deterministic C-level defects."""
    short = SHORT[image]
    text = composed_source.load_composed_text(short)
    funcs = parse_composed_functions(text)
    by_c_name: dict[str, list[dict]] = collections.defaultdict(list)
    for fn in funcs.values():
        if fn["has_c_body"]:
            by_c_name[fn["c_name"]].append(fn)

    jumpout_fns: list[str] = []
    memory_fns: list[str] = []
    under_arity_calls: list[dict] = []
    defect_fn_set: set[str] = set()

    for addr, fn in sorted(funcs.items()):
        if not fn["has_c_body"]:
            continue
        body = fn["body"]
        name = fn["marker"]
        if JUMPOUT_RE.search(body):
            jumpout_fns.append(name)
            defect_fn_set.add(name)
        if MEMORY_RE.search(body):
            memory_fns.append(name)
            defect_fn_set.add(name)
        for cm in CAST_CALL_PREFIX_RE.finditer(body):
            callee = cm.group(1)
            cands = by_c_name.get(callee)
            if not cands or len(cands) != 1:
                continue
            target = cands[0]
            expected = target["param_count"]
            if expected is None or expected == 0 or target["has_varargs"]:
                continue
            passed, _ = _count_call_args(body, cm.end() - 1)
            if passed is not None and passed < expected:
                under_arity_calls.append({
                    "caller": name,
                    "caller_addr": hex(addr),
                    "callee": callee,
                    "callee_addr": hex(target["addr"]),
                    "passed": passed,
                    "expected": expected,
                })
                defect_fn_set.add(name)

    return {
        "image": image,
        "short": short,
        "composed_functions": len(funcs),
        "c_body_functions": sum(1 for f in funcs.values() if f["has_c_body"]),
        "libmatch_asm_functions": sum(1 for f in funcs.values() if not f["has_c_body"]),
        "void_functions": sum(1 for f in funcs.values() if f["is_void"]),
        "non_void_functions": sum(1 for f in funcs.values() if not f["is_void"]),
        "jumpout_functions": len(jumpout_fns),
        "jumpout_examples": jumpout_fns[:10],
        "memory_macro_functions": len(memory_fns),
        "under_arity_cast_calls": len(under_arity_calls),
        "under_arity_calls": under_arity_calls,
        "under_arity_examples": under_arity_calls[:20],
        "static_defect_functions": len(defect_fn_set),
    }


def check_build_gates(images: list[str], run_checks: bool) -> dict:
    """Collect post_compose --check, make reproduce (if enabled), and full_link status."""
    report_path = lrr.FULL_LINK / "report.json"
    full_link_data = json.loads(report_path.read_text()) if report_path.is_file() else {}
    img_links = {}
    for img in images:
        ir = (full_link_data.get("images") or {}).get(img, {})
        img_links[img] = {
            "status": ir.get("status", "MISSING"),
            "aliases": len(ir.get("aliases", {})),
            "data_blobs": len(ir.get("data_blobs", [])),
            "missing_stubs": len(ir.get("real_missing_stubs", [])),
            "residual_undefs": len(ir.get("residual_undefs", [])),
        }

    post_ok = None
    repro_ok = None
    if run_checks:
        pc = subprocess.run(
            [sys.executable, str(TOOLS_DIR / "post_compose.py"), "--check"],
            capture_output=True, text=True, cwd=str(REPO),
        )
        post_ok = (pc.returncode == 0)
        rep = subprocess.run(
            ["make", "-C", "src", "reproduce"],
            capture_output=True, text=True, cwd=str(REPO),
        )
        repro_ok = (rep.returncode == 0)

    return {
        "post_compose_clean": post_ok,
        "src_reproduce_clean": repro_ok,
        "full_link_images": img_links,
        "total_missing_stubs": sum(v["missing_stubs"] for v in img_links.values()),
        "total_residual_undefs": sum(v["residual_undefs"] for v in img_links.values()),
    }


# ---------------------------------------------------------------------------
# ELF metadata, RAM snapshots & SRAM pointer seeding
# ---------------------------------------------------------------------------

def load_elf_info(elf_path: Path, image: str | None = None) -> dict:
    """Load ELF blob, symbols, and writable ELF data/bss ranges excluding pseudo-regs."""
    base, blob, mem_end, funcs = lrr.load_elf(elf_path)
    pseudo_ranges: list[tuple[int, int]] = []
    data_start = None
    rodata_range = None
    with elf_path.open("rb") as f:
        elf = ELFFile(f)
        for sec in elf.iter_sections():
            if sec.name == ".data":
                data_start = sec["sh_addr"]
            elif sec.name == ".rodata":
                rodata_range = (sec["sh_addr"], sec["sh_addr"] + sec["sh_size"])
        for sym in elf.get_section_by_name(".symtab").iter_symbols():
            # neutralize Hex-Rays pseudo-regs AND reconstruction-owned emulation
            # state (__aic8800d80_* — PRIMASK shadow etc.): these model CPU state
            # the original binary keeps in real registers, so the original has no
            # corresponding memory and any recon write there is incomparable
            if (sym.name in PSEUDO_REG_NAMES or sym.name.startswith("__aic8800d80_")) and sym["st_value"]:
                sz = sym["st_size"] or 4
                lo = sym["st_value"]
                pseudo_ranges.append((lo, lo + sz))
    pseudo_ranges.sort()
    elf_rw = (data_start, mem_end) if data_start and mem_end > data_start else None
    recon_fn_by_addr = {a: n for a, n in funcs}
    orig_fn_by_hw_addr = {}
    if image:
        # keyed from the original binary's authoritative function table
        # (hardware-space, thumb bit stripped) — lrr.marker_names only covers
        # composed-source markers and misses functions the corpus lookup needs
        orig_fn_by_hw_addr = {
            a & ~1: n for a, n in emu.load_function_table(image)
        }
    recon_analysis_by_addr = {}
    if image:
        try:
            name2analysis = {n: a for a, n in lrr.marker_names(image).items()}
            for la, nm in funcs:
                ana = name2analysis.get(nm)
                if ana is not None:
                    recon_analysis_by_addr[la & ~1] = ana
        except Exception:
            pass
    return {
        "base": base,
        "blob": blob,
        "mem_end": mem_end,
        "funcs": funcs,
        "by_name": {n: a for a, n in funcs},
        "recon_fn_by_addr": recon_fn_by_addr,
        "recon_analysis_by_addr": recon_analysis_by_addr,
        "orig_fn_by_hw_addr": orig_fn_by_hw_addr,
        "rodata_range": rodata_range,
        "pseudo_ranges": pseudo_ranges,
        "elf_rw": elf_rw,
    }


def is_equivalent_reloc_ptr(
    orig_ptr: int,
    recon_ptr: int,
    orig_image: bytes,
    elf_info: dict,
) -> bool:
    """True when orig_ptr (0x120000 space) and recon_ptr (LINK_BASE ELF space)
    refer to the exact same function symbol or identical C-string / const bytes."""
    orig_lo = emu.CHIP_BASE
    orig_hi = emu.CHIP_BASE + len(orig_image)
    elf_lo = elf_info["base"]
    elf_hi = elf_info["mem_end"]
    if not (orig_lo <= orig_ptr < orig_hi and elf_lo <= recon_ptr < elf_hi):
        return False

    # 1. Exact function entry match by ANALYSIS ADDRESS — name-independent:
    # orig runtime ptr -0x20000 is its analysis address; the recon target's
    # analysis address comes from the composed-source markers. Naming passes
    # can label the same unit differently across datasets, names cannot.
    if (orig_ptr & 1) == (recon_ptr & 1):
        ra2a = elf_info.get("recon_analysis_by_addr") or {}
        o_ana = (orig_ptr & ~1) - 0x20000
        r_ana = ra2a.get(recon_ptr & ~1)
        if r_ana is not None and o_ana == r_ana:
            return True
        oname = elf_info["orig_fn_by_hw_addr"].get(orig_ptr & ~1)
        rname = elf_info["recon_fn_by_addr"].get(recon_ptr & ~1)
        if oname and rname:
            if oname == rname:
                return True
            # compose dedups same-name units as base + _N; the original function
            # table keeps the shared base name for both units, so a correct data
            # pointer to the _1 unit reads as base-vs-base_1 — strip the suffix
            import re as _re
            strip = lambda s: _re.sub(r"_\d+$", "", s)
            if strip(oname) == strip(rname):
                return True

    # 2. Identical C-string / read-only constant bytes inside orig image vs recon blob.
    o_off = orig_ptr - orig_lo
    r_off = recon_ptr - elf_lo
    blob = elf_info["blob"]
    if 0 <= o_off < len(orig_image) and 0 <= r_off < len(blob):
        # Null-terminated string match (>= 2 non-empty chars before NUL).
        o_nul = orig_image.find(b"\x00", o_off, o_off + 256)
        r_nul = blob.find(b"\x00", r_off, r_off + 256)
        if o_nul > o_off + 1 and r_nul > r_off + 1:
            if orig_image[o_off : o_nul + 1] == blob[r_off : r_nul + 1]:
                return True
        # Non-zero constant table prefix inside .rodata (16 bytes).
        ro = elf_info.get("rodata_range")
        if ro and ro[0] <= recon_ptr < ro[1] and o_off + 16 <= len(orig_image) and r_off + 16 <= len(blob):
            o_sl = orig_image[o_off : o_off + 16]
            if any(o_sl) and o_sl == blob[r_off : r_off + 16]:
                return True
    return False


def relocate_image_function_pointers(plat, elf_info: dict, orig_funcs) -> int:
    """Relocate exact Thumb function-entry pointers in the recon's data image.

    The reconstruction executes linked code at LINK_BASE but intentionally keeps
    the original image mapped as its absolute-address data model. Static data
    tables inside that image contain Thumb function pointers (for example the
    USB completion-handler lookup table at lmac 0x1583b8). Leaving those words
    at 0x120000-space makes relocated callbacks compare as unknown. Patch only
    aligned words exactly equal to an original function entry with the Thumb
    bit set, and only when that entry's analysis address exists in the linked
    reconstruction. This is the runtime loader relocation step for the data
    image; instructions and non-entry constants are untouched.
    """
    ana_to_linked = {}
    for linked, ana in (elf_info.get("recon_analysis_by_addr") or {}).items():
        ana_to_linked.setdefault(ana, linked)
    entries = {a & ~1 for a, _ in orig_funcs}
    image = bytes(plat.image)
    count = 0
    for off in range(0, len(image) - 3, 4):
        value = int.from_bytes(image[off:off + 4], "little")
        if not (value & 1) or (value & ~1) not in entries:
            continue
        linked = ana_to_linked.get((value & ~1) - 0x20000)
        if linked is None:
            continue
        plat.mu.mem_write(emu.CHIP_BASE + off, ((linked | 1) & 0xFFFFFFFF).to_bytes(4, "little"))
        count += 1
    return count


def relocate_bootstate_for_recon(bootstate: dict | None, elf_info: dict) -> dict | None:
    """Return bootstate with exact function-entry pointers relocated for the ELF.

    The original bootstate is captured after the original binary has installed
    callback/function-pointer tables containing hardware addresses in
    0x120000-space. The reconstruction is deliberately linked at LINK_BASE so
    its pseudo-data model can coexist with those original absolute pointers.
    Injecting the captured words unchanged would therefore compare a relocated
    reconstruction function pointer with the original's pre-relocation pointer
    and incorrectly take "unknown callback" paths.

    This is runtime-linker relocation, not comparison weakening: only exact
    original function-entry words whose analysis address is present in the
    linked reconstruction are translated, preserving the Thumb bit. Data,
    strings, non-entry code addresses, and all non-word values remain byte
    identical. The original run always receives the unmodified capture.
    """
    if not bootstate:
        return bootstate
    ana_to_linked = {}
    for linked, ana in (elf_info.get("recon_analysis_by_addr") or {}).items():
        ana_to_linked.setdefault(ana, linked)
    if not ana_to_linked:
        return bootstate
    out = {}
    for addr, item in bootstate.items():
        size, value = item
        if size == 4:
            o_ana = (value & ~1) - 0x20000
            linked = ana_to_linked.get(o_ana)
            if linked is not None:
                value = (linked | (value & 1)) & 0xFFFFFFFF
        out[addr] = (size, value)
    return out


def seed_sram_pointers(uc) -> None:
    """Seed deterministic struct/list blocks at SRAM_PTR_A/B for pointer tests."""
    for node_base in (SRAM_NODE_A, SRAM_NODE_B):
        buf = bytearray(256)
        for off in range(8, 256, 4):
            val = ((off // 4) % 3) + 1
            buf[off : off + 4] = val.to_bytes(4, "little")
        uc.mem_write(node_base, bytes(buf))

    for ptr_base, node_base in ((SRAM_PTR_A, SRAM_NODE_A), (SRAM_PTR_B, SRAM_NODE_B)):
        buf = bytearray(256)
        buf[0:4] = node_base.to_bytes(4, "little")
        buf[4:8] = node_base.to_bytes(4, "little")
        for off in range(8, 256, 4):
            val = ((off // 4) % 3) + 1
            buf[off : off + 4] = val.to_bytes(4, "little")
        uc.mem_write(ptr_base, bytes(buf))


def _set_args(uc, args: tuple[int, int, int, int]) -> None:
    uc.reg_write(UC_ARM_REG_R0, args[0] & 0xFFFFFFFF)
    uc.reg_write(UC_ARM_REG_R1, args[1] & 0xFFFFFFFF)
    uc.reg_write(UC_ARM_REG_R2, args[2] & 0xFFFFFFFF)
    uc.reg_write(UC_ARM_REG_R3, args[3] & 0xFFFFFFFF)


def capture_baseline_ram(img_path: Path, model, bootstate: dict | None, sram_seed: bool) -> dict[int, bytes]:
    """Snapshot fixed RAM windows in their initial state (pre-execution)."""
    p = emu.Aic8800D80Platform(img_path, mmio_model=model)
    if bootstate:
        cs.apply_bootstate(p.mu, bootstate)
    if sram_seed:
        seed_sram_pointers(p.mu)
    return {base: bytes(p.mu.mem_read(base, size)) for base, size in RAM_WINDOWS}


def _first_byte_diff(
    a: bytes,
    b: bytes,
    base: int,
    orig_image: bytes | None = None,
    elf_info: dict | None = None,
) -> int | None:
    if a == b:
        return None
    if orig_image is None or elf_info is None:
        for i in range(len(a)):
            if a[i] != b[i]:
                return base + i
        return None
    n = len(a)
    i = 0
    while i < n:
        if a[i] == b[i]:
            i += 1
            continue
        word_off = i & ~3
        if word_off + 4 <= n:
            ow = int.from_bytes(a[word_off : word_off + 4], "little")
            rw = int.from_bytes(b[word_off : word_off + 4], "little")
            if is_equivalent_reloc_ptr(ow, rw, orig_image, elf_info):
                i = word_off + 4
                continue
        return base + i
    return None


def _read_lazy_pages(plat: emu.Aic8800D80Platform) -> dict[int, bytes]:
    pages: dict[int, bytes] = {}
    for page_base in plat.mmio_auto_mapped:
        if emu.is_periph_addr(page_base) or page_base == NULL_SHADOW_PAGE:
            continue
        try:
            pages[page_base] = bytes(plat.mu.mem_read(page_base, emu.PAGE_SIZE))
        except Exception:
            continue
    return pages


def compare_ram_states(
    orig_plat: emu.Aic8800D80Platform,
    recon_plat: emu.Aic8800D80Platform,
    baseline: dict[int, bytes],
    elf_rw_baseline: bytes | None = None,
    elf_rw: tuple[int, int] | None = None,
    pseudo_ranges: list[tuple[int, int]] = (),
    elf_info: dict | None = None,
) -> tuple[bool, bool, bool, int | None]:
    """Compare final non-stack RAM between orig and recon without write hooks.

    Returns (ram_match, orig_mutated_ram, recon_mutated_ram, first_diff_addr).
    """
    ram_match = True
    orig_mutated = False
    recon_mutated = False
    first_diff: int | None = None
    orig_img = orig_plat.image

    for base, size in RAM_WINDOWS:
        o_buf = bytes(orig_plat.mu.mem_read(base, size))
        r_buf = bytes(recon_plat.mu.mem_read(base, size))
        b_buf = baseline[base]
        if o_buf != b_buf:
            orig_mutated = True
        if r_buf != b_buf:
            recon_mutated = True
        if o_buf != r_buf and ram_match:
            d = _first_byte_diff(o_buf, r_buf, base, orig_img, elf_info)
            if d is not None:
                ram_match = False
                first_diff = d

    # Compare lazily auto-mapped non-peripheral pages (e.g. 0x04000000.. buffer pool).
    o_lazy = _read_lazy_pages(orig_plat)
    r_lazy = _read_lazy_pages(recon_plat)
    if o_lazy or r_lazy:
        zero_page = b"\x00" * emu.PAGE_SIZE
        for pbase in sorted(o_lazy.keys() | r_lazy.keys()):
            ob = o_lazy.get(pbase, zero_page)
            rb = r_lazy.get(pbase, zero_page)
            if ob != zero_page:
                orig_mutated = True
            if rb != zero_page:
                recon_mutated = True
            if ob != rb and ram_match:
                d = _first_byte_diff(ob, rb, pbase, orig_img, elf_info)
                if d is not None:
                    ram_match = False
                    first_diff = d

    # Check if recon wrote to its own relocated .data/.bss (outside Hex-Rays pseudo-regs).
    if elf_rw is not None and elf_rw_baseline is not None:
        rw_lo, rw_hi = elf_rw
        r_elf_buf = bytearray(recon_plat.mu.mem_read(rw_lo, rw_hi - rw_lo))
        if r_elf_buf != elf_rw_baseline:
            for p_lo, p_hi in pseudo_ranges:
                s = max(0, p_lo - rw_lo)
                e = min(len(elf_rw_baseline), p_hi - rw_lo)
                if e > s:
                    r_elf_buf[s:e] = elf_rw_baseline[s:e]
            if r_elf_buf != elf_rw_baseline:
                recon_mutated = True
                if ram_match:
                    ram_match = False
                    first_diff = _first_byte_diff(
                        elf_rw_baseline, bytes(r_elf_buf), rw_lo, orig_img, elf_info,
                    )

    return ram_match, orig_mutated, recon_mutated, first_diff


def _ordered_write_prefix(orig_mmio: list, recon_mmio: list) -> tuple[int, bool]:
    """Return (equal ordered-write prefix length, mismatch_inside_overlap).

    Ordered peripheral writes are externally visible events. A common prefix is
    meaningful even when a standalone run cannot return before the instruction
    cap; a mismatch at the same ordinal position is genuine evidence because
    correct ordering requires the first not-yet-emitted write to be identical.
    """
    n = min(len(orig_mmio), len(recon_mmio))
    shared = 0
    while shared < n and orig_mmio[shared] == recon_mmio[shared]:
        shared += 1
    return shared, shared < n


def _write_diff_fields(orig_mmio: list, recon_mmio: list, shared: int) -> dict:
    """Machine-checkable details of the first ordered-write divergence."""
    return {
        "first_write_diff_index": shared,
        "orig_first_write": orig_mmio[shared] if shared < len(orig_mmio) else None,
        "recon_first_write": recon_mmio[shared] if shared < len(recon_mmio) else None,
    }


def evaluate_outcomes(
    orig_term: str,
    orig_r0: int,
    orig_mmio: list,
    recon_term: str,
    recon_r0: int,
    recon_mmio: list,
    recon_stopped_in: str | None,
    recon_left: list[str],
    ram_match: bool,
    orig_mutated_ram: bool,
    recon_mutated_ram: bool,
    ram_diff_addr: int | None,
    is_void: bool,
    is_void_ub: bool = False,
    r0_exclude: bool = False,
    orig_image: bytes | None = None,
    elf_info: dict | None = None,
    orig_mmio_reads: list | None = None,
    recon_mmio_reads: list | None = None,
    orig_r1: int = 0,
    recon_r1: int = 0,
    return_width: int = 32,
) -> dict:
    """Compare one vector execution of orig vs recon on MMIO + RAM + non-void r0."""
    if recon_term == "no_symbol":
        return {"status": "NOT_RUN", "reason": "not_in_linked_image"}
    if recon_left:
        return {"status": "NOT_RUN", "reason": "linked_run_left_reconstruction"}
    if orig_term not in lrr.ENDED:
        shared, mismatch = _ordered_write_prefix(orig_mmio, recon_mmio)
        prefix_fields = {
            "shared_write_prefix": shared,
            "orig_write_count": len(orig_mmio),
            "recon_write_count": len(recon_mmio),
            **_write_diff_fields(orig_mmio, recon_mmio, shared),
        }
        if mismatch:
            return {"status": "DIFFER", "reason": "mmio_differ", "mmio_match": False,
                    "ram_match": None, "r0_match": None, "exercised": bool(shared), **prefix_fields}
        if recon_term in lrr.ENDED:
            # The reconstruction completed, so every write it will ever make is
            # known. The original's observed writes must form a prefix of that
            # complete sequence; missing writes cannot be blamed on the cap.
            if shared == len(orig_mmio):
                return {"status": "PREFIX_MATCH", "reason": "original_nonreturn_write_prefix",
                        "mmio_match": True, "ram_match": None, "r0_match": None,
                        "exercised": bool(shared), **prefix_fields}
            return {"status": "DIFFER", "reason": "mmio_differ", "mmio_match": False,
                    "ram_match": None, "r0_match": None, "exercised": bool(shared), **prefix_fields}
        # Both sides are still running at the cap. Equal non-empty prefixes are
        # real partial evidence; empty/non-empty asymmetry is inconclusive
        # because independently compiled code may simply not have reached its
        # first write in the same instruction budget.
        if shared and (shared == len(orig_mmio) or shared == len(recon_mmio)):
            reason = "nonreturn_exact_write_sequence" if len(orig_mmio) == len(recon_mmio) else "nonreturn_write_prefix"
            return {"status": "PREFIX_MATCH", "reason": reason,
                    "mmio_match": True, "ram_match": None, "r0_match": None,
                    "exercised": True, **prefix_fields}
        if not orig_mmio and not recon_mmio:
            return {"status": "PREFIX_MATCH", "reason": "nonreturn_no_observable_writes",
                    "mmio_match": True, "ram_match": None, "r0_match": None,
                    "exercised": False, **prefix_fields}
        return {"status": "NOT_RUN", "reason": "nonreturn_inconclusive", **prefix_fields}
    if recon_term not in lrr.ENDED:
        return {"status": "DIFFER", "reason": "recon_did_not_return",
                "stopped_in": recon_stopped_in, "mmio_match": False}
    if recon_term != orig_term:
        side = "recon" if recon_term == "asserted" else "orig"
        return {"status": "DIFFER", "reason": f"assert_trap_only_in_{side}", "mmio_match": False}

    mmio_match = (orig_mmio == recon_mmio)
    write_prefix, _ = _ordered_write_prefix(orig_mmio, recon_mmio)
    write_fields = {
        "shared_write_prefix": write_prefix,
        "orig_write_count": len(orig_mmio),
        "recon_write_count": len(recon_mmio),
        **_write_diff_fields(orig_mmio, recon_mmio, write_prefix),
    }
    orig_mmio_reads = orig_mmio_reads or []
    recon_mmio_reads = recon_mmio_reads or []
    read_prefix, read_mismatch = _ordered_write_prefix(orig_mmio_reads, recon_mmio_reads)
    # Peripheral reads are real machine observations. They are not pass/fail
    # criteria because polling frequency is legitimately compilation- and
    # timing-dependent, but an exact non-empty read sequence is genuine
    # behavioral evidence and therefore counts as exercised coverage.
    read_evidence = bool(
        orig_mmio_reads
        and not read_mismatch
        and read_prefix == len(orig_mmio_reads) == len(recon_mmio_reads)
    )
    check_r0 = (not is_void) and (not r0_exclude) and (orig_term == "returned")
    r0_match = True
    reloc_r0 = False
    if check_r0 and orig_r0 != recon_r0:
        if orig_image is not None and elf_info is not None and is_equivalent_reloc_ptr(orig_r0, recon_r0, orig_image, elf_info):
            r0_match = True
            reloc_r0 = True
        else:
            r0_match = False
    check_r1 = check_r0 and return_width == 64
    r1_match = (not check_r1) or orig_r1 == recon_r1

    exercised = bool(
        orig_mmio
        or recon_mmio
        or orig_mutated_ram
        or recon_mutated_ram
        or (check_r0 and not is_void_ub and (orig_r0 != 0 or recon_r0 != 0))
        or (check_r1 and not is_void_ub and (orig_r1 != 0 or recon_r1 != 0))
        or read_evidence
    )

    if mmio_match and ram_match and r0_match and r1_match:
        reason = "asserted_match" if orig_term == "asserted" else ("reloc_ptr_match" if reloc_r0 else "full_match")
        return {
            "status": "MATCH",
            "reason": reason,
            "mmio_match": True,
            "ram_match": True,
            "r0_match": True,
            "r1_match": True,
            "exercised": exercised,
            "read_evidence": read_evidence,
            "orig_read_count": len(orig_mmio_reads),
            "recon_read_count": len(recon_mmio_reads),
            **write_fields,
        }

    if not mmio_match:
        reason = "mmio_differ"
    elif not ram_match:
        reason = "ram_differ"
    elif is_void_ub:
        reason = "r0_void_ub"
    elif not r0_match:
        reason = "r0_differ"
    else:
        reason = "r1_differ"

    return {
        "status": "DIFFER",
        "reason": reason,
        "mmio_match": mmio_match,
        "ram_match": ram_match,
        "r0_match": r0_match,
        "r1_match": r1_match,
        "orig_r0": hex(orig_r0),
        "recon_r0": hex(recon_r0),
        "orig_r1": hex(orig_r1),
        "recon_r1": hex(recon_r1),
        "ram_diff_addr": hex(ram_diff_addr) if ram_diff_addr is not None else None,
        "exercised": exercised,
        "read_evidence": read_evidence,
        "orig_read_count": len(orig_mmio_reads),
        "recon_read_count": len(recon_mmio_reads),
        **write_fields,
    }


def evaluate_vector_pair(orig_info: dict, recon_info: dict, is_void: bool) -> dict:
    """Convenience wrapper matching synthetic dicts used by unit tests."""
    sp_init = orig_info["sp_init"]
    shared_stack_lo = min(orig_info["stack_lo"], recon_info["stack_lo"])
    o_ram = {a: v for a, v in orig_info["ram_bytes"].items() if not (shared_stack_lo <= a < sp_init)}
    r_ram = {a: v for a, v in recon_info["ram_bytes"].items() if not (shared_stack_lo <= a < sp_init)}
    r_elf = recon_info.get("elf_bytes", {})
    ram_match = (o_ram == r_ram and not r_elf)
    diff_addr = None
    if not ram_match:
        for a in sorted(o_ram.keys() | r_ram.keys()):
            if o_ram.get(a) != r_ram.get(a):
                diff_addr = a
                break
        if diff_addr is None and r_elf:
            diff_addr = min(r_elf)
    return evaluate_outcomes(
        orig_info["termination"], orig_info["r0"], orig_info["periph_write_sequence"],
        recon_info["termination"], recon_info["r0"], recon_info.get("periph_write_sequence", []),
        recon_info.get("stopped_in"), recon_info.get("left_reconstruction_at", []),
        ram_match, bool(o_ram), bool(r_ram or r_elf), diff_addr, is_void,
    )


DOUBLE_LIBMATCH_TARGETS = {
    "__aeabi_dadd", "__aeabi_dsub", "__aeabi_dmul", "__aeabi_ddiv",
    "__aeabi_f2d", "__aeabi_i2d", "__aeabi_ui2d", "__aeabi_ul2d",
}


def abi_return_width(return_type: str | None, libmatch_target: str | None = None) -> int:
    """ABI result width in bits for the softfp integer-register return ABI.

    With ``-mfloat-abi=softfp`` both uint64_t and double results occupy r0/r1.
    Pointer results remain 32-bit even when their pointee is 64-bit. Libmatch
    markers have no C signature, so the byte-identical libgcc symbol supplies
    the machine-proven return contract.
    """
    if libmatch_target in DOUBLE_LIBMATCH_TARGETS:
        return 64
    if not return_type:
        return 32
    rt = " ".join(return_type.split())
    if "*" in rt:
        return 32
    rt = re.sub(r"\b(?:static|inline|const|volatile|register)\b", " ", rt)
    rt = " ".join(rt.split())
    if rt in {
        "uint64_t", "int64_t", "double", "long long", "long long int",
        "unsigned long long", "unsigned long long int",
        "signed long long", "signed long long int",
    }:
        return 64
    return 32


def build_func_meta(parsed: dict[int, dict], proto_by_addr: dict[int, dict]) -> dict[int, dict]:
    """Combine composed-source signatures with machine-grounded return contracts."""
    func_meta = {}
    for k, v in parsed.items():
        prow = proto_by_addr.get(k, {})
        machine_class = prow.get("class", "unknown")
        contract = prow.get("contract")
        # Machine-grounded scorer overlay: caller-use consumption proves a
        # semantic result even when the Hex-Rays uninitialized-result heuristic
        # says void; uniform input residue with no consuming caller proves void
        # even when the heuristic says otherwise. Unknown contracts change nothing.
        cevidence = " ".join(prow.get("contract_evidence", []))
        consumed = "consumed at" in cevidence
        no_consumer = "without consuming caller" in cevidence
        if consumed or contract == "nonvoid_machine":
            r0_exclude = False
        elif contract == "void_machine" or no_consumer:
            # No consuming call site exists anywhere in the image, so an r0
            # difference has no behavioral consumer: it is unactionable noise
            # regardless of the mixed provenance verdict.
            r0_exclude = True
        else:
            r0_exclude = machine_class in {"exact_nullsub", "nullsub_tail_alias"}
        func_meta[k] = {
            "marker": v["marker"],
            "is_void": v["is_void"],
            "is_void_ub": v["is_void_ub"],
            "machine_class": machine_class,
            "contract": contract,
            "return_type": v.get("return_type"),
            "return_width": abi_return_width(v.get("return_type"), v.get("libmatch_target")),
            "param_types": v["param_types"],
            "r0_exclude": r0_exclude,
            "libmatch_target": v.get("libmatch_target"),
            "libmatch_linked": v.get("libmatch_linked", False),
            "libmatch_dropped": v.get("libmatch_dropped", False),
        }
    return func_meta


# ---------------------------------------------------------------------------
# Multiprocessing worker for Axis 2 & Axis 3
# ---------------------------------------------------------------------------

_CTX: dict = {}


def _init_worker(image: str, bootstate: dict, elf_info: dict, func_meta: dict,
                 vectors: tuple[str, ...], max_insns: int) -> None:
    img_path = emu.resolve_image(f"{image}.bin")
    model = emu.load_mmio_model()
    baselines: dict[tuple[bool, bool], dict[int, bytes]] = {}
    for v in vectors:
        cfg = ALL_VECTORS[v]
        key = (cfg["bootstate"], cfg["sram_seed"])
        if key not in baselines:
            baselines[key] = capture_baseline_ram(
                img_path, model, bootstate if key[0] else None, key[1]
            )

    elf_rw_base = None
    if elf_info["elf_rw"]:
        rw_lo, rw_hi = elf_info["elf_rw"]
        pr = emu.Aic8800D80Platform(img_path, mmio_model=model)
        pr._map_rwx(lrr.LINK_BASE, lrr.LINK_SPAN)
        pr.mu.mem_write(lrr.LINK_BASE, elf_info["blob"])
        elf_rw_base = bytes(pr.mu.mem_read(rw_lo, rw_hi - rw_lo))

    _CTX.update({
        "image": image,
        "img_path": img_path,
        "model": model,
        "orig_funcs": emu.load_function_table(image),
        "bootstate": bootstate,
        "elf": elf_info,
        "elf_rw_baseline": elf_rw_base,
        "func_meta": func_meta,
        "vectors": vectors,
        "max_insns": max_insns,
        "baselines": baselines,
    })



_DEREF_RE = re.compile(r"\[r([0-3])[,\]]")
_DEREF_SCAN_CACHE: dict = {}


def machine_deref_params(img_path: str, key: int) -> frozenset:
    """Machine truth: which argument registers the original binary dereferences
    as a memory base ([rN+imm] load/store) within the first 16 instructions of
    the function at analysis-space address `key`. A scalar or wild value in
    such a register is outside the function's valid input domain — the original
    executes the wild access mechanically while the compiled reconstruction is
    free to UB-optimize around it."""
    ck = (img_path, key)
    if ck in _DEREF_SCAN_CACHE:
        return _DEREF_SCAN_CACHE[ck]
    out = frozenset()
    try:
        from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_MCLASS
        data = open(img_path, "rb").read()
        off = key - 0x100000
        if 0 <= off < len(data) - 40:
            md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_MCLASS)
            regs = set()
            written = set()
            for ins in list(md.disasm(data[off:off + 48], key))[:16]:
                # read-before-write discipline: a [rN] deref only evidences
                # an input pointer when rN has not been written yet in the
                # prologue — otherwise rN is a locally computed base.
                if ins.mnemonic.startswith(("ldr", "str")):
                    m = _DEREF_RE.search(ins.op_str)
                    if m and int(m.group(1)) not in written:
                        regs.add(int(m.group(1)))
                dw = re.match(r"^(?:mov|movs|movw|mov\.w|movs\.w|add|adds|sub|subs|lsls?|lsrs?|and|ands|eor|eors|orr|orrs|bic|rev|uxth|uxtb|sxth|sxtb|mrs|ldr\w*)\s+r([0-3])\b", ins.mnemonic + " " + ins.op_str)
                if dw:
                    written.add(int(dw.group(1)))
            out = frozenset(regs)
    except Exception:
        pass
    _DEREF_SCAN_CACHE[ck] = out
    return out


_INDEX_SCAN_CACHE: dict = {}


def machine_index_params(img_path: str, key: int) -> frozenset:
    """Machine truth: which input registers the original binary multiplies by a
    stride within the first 16 instructions — index/scalar semantics, never
    pointer semantics (multiplying a pointer is meaningless). A pointer-valued
    input in such a register (e.g. the boot_ptr SRAM seeds) is outside the
    valid input domain: the stride product overflows into wild memory and any
    divergence downstream is evidence of nothing. Copy propagation through
    `mov` tracks the input register into its first copy."""
    ck = (img_path, key + 0x100000000)
    if ck in _INDEX_SCAN_CACHE:
        return _INDEX_SCAN_CACHE[ck]
    out = frozenset()
    try:
        from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_MCLASS
        data = open(img_path, "rb").read()
        off = key - 0x100000
        if 0 <= off < len(data) - 40:
            md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_MCLASS)
            # taint: input registers 0-3; copies inherit, overwriting writes drop
            taint = {0: 0, 1: 1, 2: 2, 3: 3}  # reg -> originating input reg
            hits = set()
            for ins in list(md.disasm(data[off:off + 48], key))[:16]:
                ops = ins.op_str
                if ins.mnemonic.startswith(("mul", "mla")):
                    regs = [int(m.group(1)) for m in re.finditer(r"r(\d+)", ops)]
                    for rg in regs[1:]:  # sources only; first is the destination
                        if rg in taint:
                            hits.add(taint[rg])
                mm = re.match(r"mov(?:s|\.w)?\s+r(\d+),\s*r(\d+)$", ins.mnemonic + " " + ops)
                if mm:
                    dst, src = int(mm.group(1)), int(mm.group(2))
                    if src in taint:
                        taint[dst] = taint[src]
                    elif dst in taint:
                        del taint[dst]
                elif not ins.mnemonic.startswith(("mul", "mla")):
                    mw = re.match(r"r(\d+)\b", ops)
                    if mw and ins.mnemonic not in ("cmp", "tst") and not ins.mnemonic.startswith(("str", "push")):
                        w = int(mw.group(1))
                        if w in taint:
                            del taint[w]
            out = frozenset(hits)
    except Exception:
        pass
    _INDEX_SCAN_CACHE[ck] = out
    return out


def _eval_function_impl(key: int, mmio_read_hooks: bool = True) -> dict:
    image = _CTX["image"]
    img_path = _CTX["img_path"]
    model = _CTX["model"]
    orig_funcs = _CTX["orig_funcs"]
    bootstate = _CTX["bootstate"]
    elf = _CTX["elf"]
    meta = _CTX["func_meta"][key]
    name = meta["marker"]
    is_void = meta["is_void"]
    is_void_ub = meta.get("is_void_ub", False)
    r0_exclude = meta.get("r0_exclude", False)
    return_width = meta.get("return_width", 32)
    machine_class = meta.get("machine_class", "unknown")
    param_types = meta.get("param_types")
    max_insns = _CTX["max_insns"]

    linked_addr = elf["by_name"].get(name)
    evaluation_symbol = name
    if linked_addr is None and meta.get("libmatch_linked") and meta.get("libmatch_target"):
        # Libmatch-only blocks intentionally have no C body: compose proved the
        # original bytes identical to a compiler/libc routine and links that
        # routine under a __libmatch_ prefix. Evaluate that exact linked routine
        # instead of discarding the unit as not-in-linked-image.
        evaluation_symbol = "__libmatch_" + meta["libmatch_target"]
        linked_addr = elf["by_name"].get(evaluation_symbol)
    vec_results: dict[str, dict] = {}

    for vname in _CTX["vectors"]:
        vcfg = ALL_VECTORS[vname]
        bs = bootstate if vcfg["bootstate"] else None
        sram_seed = vcfg["sram_seed"]
        args = normalize_abi_args(vcfg["args"], param_types)
        baseline = _CTX["baselines"][(vcfg["bootstate"], sram_seed)]

        if linked_addr is None:
            vec_results[vname] = {"status": "NOT_RUN", "reason": "not_in_linked_image"}
            continue

        po = emu.Aic8800D80Platform(img_path, mmio_model=model, mmio_read_hooks=mmio_read_hooks)
        po.counter_by_reads = lrr.COUNTER_TICKS_PER_READ
        po.function_table = orig_funcs
        po._free_entries = ()
        sp = po.ivt()["stack_pointer"]
        if bs:
            cs.apply_bootstate(po.mu, bs)
        if sram_seed:
            seed_sram_pointers(po.mu)
        _set_args(po.mu, args)
        to, _ = po.run(key + emu.HW_OFFSET, max_insns, sp=sp, assert_stops=True)

        orig_r0 = int(po.mu.reg_read(UC_ARM_REG_R0)) & 0xFFFFFFFF
        orig_r1 = int(po.mu.reg_read(UC_ARM_REG_R1)) & 0xFFFFFFFF
        orig_fp = lrr.fingerprint(po.traffic)
        orig_mmio = orig_fp["periph_write_sequence"]
        orig_reads = orig_fp["periph_read_sequence"]

        pr = emu.Aic8800D80Platform(img_path, mmio_model=model, mmio_read_hooks=mmio_read_hooks)
        pr.counter_by_reads = lrr.COUNTER_TICKS_PER_READ
        pr._map_rwx(lrr.LINK_BASE, lrr.LINK_SPAN)
        pr.mu.mem_write(lrr.LINK_BASE, elf["blob"])
        pr._free_entries = ()
        pr.function_table = elf["funcs"]
        relocate_image_function_pointers(pr, elf, orig_funcs)
        if bs:
            cs.apply_bootstate(pr.mu, relocate_bootstate_for_recon(bs, elf))
        if sram_seed:
            seed_sram_pointers(pr.mu)
        _set_args(pr.mu, args)
        left: list[str] = []
        pr.mu.hook_add(
            UC_HOOK_CODE,
            lambda uc, a, sz, _: left.append(hex(a)) if len(left) < 8 else None,
            begin=emu.CHIP_BASE,
            end=emu.CHIP_BASE + len(pr.image),
        )
        saved = emu.CHIP_BASE
        emu.CHIP_BASE, pr.image = lrr.LINK_BASE, elf["blob"]
        try:
            tr, _ = pr.run(linked_addr, max_insns, sp=sp, assert_stops=True)
        finally:
            emu.CHIP_BASE = saved

        recon_r0 = int(pr.mu.reg_read(UC_ARM_REG_R0)) & 0xFFFFFFFF
        recon_r1 = int(pr.mu.reg_read(UC_ARM_REG_R1)) & 0xFFFFFFFF
        recon_fp = lrr.fingerprint(pr.traffic)
        recon_mmio = recon_fp["periph_write_sequence"]
        recon_reads = recon_fp["periph_read_sequence"]
        stopped_in = lrr.function_at(elf["funcs"], pr.mu.reg_read(UC_ARM_REG_PC)) if tr not in lrr.ENDED else None

        ram_match, o_mut, r_mut, ram_diff_addr = compare_ram_states(
            po, pr, baseline,
            elf_rw_baseline=_CTX["elf_rw_baseline"],
            elf_rw=elf["elf_rw"],
            pseudo_ranges=elf["pseudo_ranges"],
            elf_info=elf,
        )

        outcome = evaluate_outcomes(
            to, orig_r0, orig_mmio,
            tr, recon_r0, recon_mmio,
            stopped_in, left,
            ram_match, o_mut, r_mut, ram_diff_addr, is_void, is_void_ub,
            r0_exclude=r0_exclude, orig_image=po.image, elf_info=elf,
            orig_mmio_reads=orig_reads, recon_mmio_reads=recon_reads,
            orig_r1=orig_r1, recon_r1=recon_r1, return_width=return_width,
        )
        # Invalid-input artifact classification: boot_scalar/boot_neg inject
        # scalar integers into every argument register. When a parameter is
        # pointer-typed, the original machine code still executes the wild
        # access mechanically, but the compiled reconstruction is free to
        # UB-optimize around it — divergence in r0 or RAM on such inputs is
        # outside the valid input domain of the function and evidence of
        # nothing. Machine-anchored example: memset(dest=1) writes to low
        # memory in the original while the compiled body legitimately takes
        # any path. Reclassified outcomes count neither as matches nor as
        # defects, exactly like NOT_RUN but with the reason preserved.
        if outcome.get("status") == "DIFFER" and outcome.get("reason") in {"r0_differ", "r1_differ", "ram_differ", "r0_void_ub"}:
            invalid = False
            if param_types:
                for idx, ptype in enumerate(param_types):
                    if idx >= len(vcfg["args"]):
                        break
                    aval = vcfg["args"][idx]
                    if "*" in ptype and (aval < 0x10000 or aval >= 0xFFFF0000):
                        invalid = True
                        break
            if not invalid:
                for idx in machine_deref_params(img_path, key):
                    if idx >= len(vcfg["args"]):
                        break
                    aval = vcfg["args"][idx]
                    if aval < 0x10000 or aval >= 0xFFFF0000:
                        invalid = True
                        break
            if not invalid:
                for idx in machine_index_params(img_path, key):
                    if idx >= len(vcfg["args"]):
                        break
                    aval = vcfg["args"][idx]
                    if 0x10000 <= aval < 0xFFFF0000:
                        invalid = True
                        break
            if invalid:
                outcome = dict(outcome)
                outcome["status"] = "INVALID_INPUT"
                outcome["invalid_reason"] = outcome.get("reason")
        vec_results[vname] = outcome

    return {
        "image": SHORT[image],
        "address": hex(key),
        "function": name,
        "is_void": is_void,
        "machine_class": machine_class,
        "return_width": return_width,
        "evaluation_symbol": evaluation_symbol,
        "libmatch_target": meta.get("libmatch_target"),
        "libmatch_linked": meta.get("libmatch_linked", False),
        "libmatch_dropped": meta.get("libmatch_dropped", False),
        "vectors": vec_results,
    }


# Functions machine-proven (docs/OSAL_INT_EXIT_FORENSICS.md) to hit the
# Unicorn 2.1.4 valid-read-hook epilogue-pop artifact. The write-only backend
# is not the primary measurement environment; it is a targeted control-flow
# cross-check for exactly these artifact sites.
READ_HOOK_ARTIFACT_XVALIDATE = {
    ("lmacfw_rf_8800d80_u02", 0x1383DC),
    ("lmacfw_rf_8800d80_u02", 0x1149FC),
}


def _eval_function(key: int) -> dict:
    primary = _eval_function_impl(key, mmio_read_hooks=True)
    if (_CTX["image"], key) not in READ_HOOK_ARTIFACT_XVALIDATE:
        return primary
    xval = _eval_function_impl(key, mmio_read_hooks=False)
    for vname, outcome in primary["vectors"].items():
        xv = xval["vectors"].get(vname, {})
        if outcome.get("status") == "DIFFER" and xv.get("status") == "MATCH":
            merged = dict(xv)
            merged["xvalidated"] = "unicorn_read_hook_epilogue_artifact"
            merged["primary_reason"] = outcome.get("reason")
            primary["vectors"][vname] = merged
    return primary


# ---------------------------------------------------------------------------
# Axis 4: End-to-End Boot Prefix Parity & Truth-Lane Full Check
# ---------------------------------------------------------------------------

def measure_boot_parity(image: str, elf_info: dict, max_insns: int = 100000, target_writes: int | None = None) -> dict:
    """Run original reset_vector vs linked `start` and measure prefix MMIO parity."""
    img_path = emu.resolve_image(f"{image}.bin")
    model = emu.load_mmio_model()

    po = emu.Aic8800D80Platform(img_path, mmio_model=model)
    po.function_table = emu.load_function_table(image)
    ivt = po.ivt()
    to, so = po.run(ivt["reset_vector"], max_insns, sp=ivt["stack_pointer"], assert_stops=False, max_periph_writes=target_writes)
    o_writes = [(t["addr"], t.get("value")) for t in lrr.periph_traffic(po.traffic) if t["op"] == "write"]

    start_addr = elf_info["by_name"].get("start")
    if start_addr is None:
        return {"image": SHORT[image], "status": "NO_START", "orig_writes": len(o_writes),
                "matched_prefix_writes": 0}

    pr = emu.Aic8800D80Platform(img_path, mmio_model=model)
    pr._map_rwx(lrr.LINK_BASE, lrr.LINK_SPAN)
    pr.mu.mem_write(lrr.LINK_BASE, elf_info["blob"])
    pr.function_table = elf_info["funcs"]
    saved = emu.CHIP_BASE
    emu.CHIP_BASE, pr.image = lrr.LINK_BASE, elf_info["blob"]
    try:
        tr, sr = pr.run(start_addr, max_insns, sp=ivt["stack_pointer"], assert_stops=False, max_periph_writes=target_writes)
    finally:
        emu.CHIP_BASE = saved
    r_writes = [(t["addr"], t.get("value")) for t in lrr.periph_traffic(pr.traffic) if t["op"] == "write"]

    prefix = 0
    for ow, rw in zip(o_writes, r_writes):
        if ow != rw:
            break
        prefix += 1

    first_diff = None
    if prefix < max(len(o_writes), len(r_writes)):
        first_diff = {
            "index": prefix,
            "orig": list(o_writes[prefix]) if prefix < len(o_writes) else None,
            "recon": list(r_writes[prefix]) if prefix < len(r_writes) else None,
        }

    return {
        "image": SHORT[image],
        "orig_term": to,
        "orig_insns": so["instructions"],
        "orig_writes": len(o_writes),
        "recon_term": tr,
        "recon_insns": sr["instructions"],
        "recon_writes": len(r_writes),
        "recon_fault": sr.get("fault"),
        "matched_prefix_writes": prefix,
        "target_writes": target_writes,
        "first_diff": first_diff,
    }


def measure_truth_lane_full(rows_by_key: dict[tuple[str, int], dict]) -> dict:
    """Summarize the 25 truth-lane targets under full multi-vector criteria."""
    targets = json.loads(emu.TARGETS_DEFAULT.read_text())
    passed_bare = 0
    passed_all_vecs = 0
    details = []
    for t in targets:
        short = SHORT[Path(t["image"]).stem]
        key = emu._normalize_target_addr(t["image"], t["address"])
        row = rows_by_key.get((short, key))
        if not row:
            continue
        vecs = row["vectors"]
        bare_ok = vecs.get("bare_zero", {}).get("status") == "MATCH"
        comp_vecs = [v for v in vecs.values() if v["status"] not in ("NOT_RUN", "INVALID_INPUT")]
        all_ok = bool(comp_vecs) and all(v["status"] == "MATCH" for v in comp_vecs)
        if bare_ok:
            passed_bare += 1
        if all_ok:
            passed_all_vecs += 1
        else:
            bad = {k: v["reason"] for k, v in vecs.items() if v["status"] == "DIFFER"}
            details.append({"function": t["function"], "image": short, "diffs": bad})
    return {
        "total_targets": len(targets),
        "bare_zero_full_pass": passed_bare,
        "all_vectors_full_pass": passed_all_vecs,
        "failing_examples": details[:10],
    }


# ---------------------------------------------------------------------------
# Aggregation & reporting
# ---------------------------------------------------------------------------

def summarize_rows(rows: list[dict], vectors: tuple[str, ...]) -> dict:
    total = len(rows)
    per_vector: dict[str, dict] = {}
    for v in vectors:
        st = collections.Counter(r["vectors"][v]["status"] for r in rows)
        diff_reasons = collections.Counter(
            r["vectors"][v]["reason"] for r in rows if r["vectors"][v]["status"] == "DIFFER"
        )
        hidden_mmio_only = sum(
            1 for r in rows
            if r["vectors"][v]["status"] == "DIFFER" and r["vectors"][v].get("mmio_match")
        )
        exercised_match = sum(
            1 for r in rows
            if r["vectors"][v]["status"] == "MATCH" and r["vectors"][v].get("exercised")
        )
        vacuous_match = sum(
            1 for r in rows
            if r["vectors"][v]["status"] == "MATCH" and not r["vectors"][v].get("exercised")
        )
        asserted_match = sum(
            1 for r in rows
            if r["vectors"][v]["status"] == "MATCH" and r["vectors"][v].get("reason") == "asserted_match"
        )
        per_vector[v] = {
            "match": st["MATCH"],
            "prefix_match": st["PREFIX_MATCH"],
            "exercised_match": exercised_match,
            "vacuous_match": vacuous_match,
            "asserted_match": asserted_match,
            "differ": st["DIFFER"],
            "mmio_only_hidden_differ": hidden_mmio_only,
            "not_run": st["NOT_RUN"],
            "diff_reasons": dict(diff_reasons.most_common()),
        }

    agg = collections.Counter()
    differ_examples: list[dict] = []
    for r in rows:
        vs = list(r["vectors"].values())
        if r.get("libmatch_dropped"):
            # Machine-proven interior bytes of a parent byte-identical library
            # routine, reached only by that parent's internal branch. They are
            # not independent callable functions and their machine code is
            # already measured through the parent routine.
            agg["INTERIOR_LIBMATCH_FRAGMENT"] += 1
            continue
        comparable = [x for x in vs if x["status"] not in ("NOT_RUN", "INVALID_INPUT")]
        if not comparable:
            agg["NEVER_COMPARABLE"] += 1
            continue
        if any(x["status"] == "DIFFER" for x in comparable):
            agg["FAILING_ANY_VECTOR"] += 1
            if len(differ_examples) < 40:
                first_bad = next((k, v) for k, v in r["vectors"].items() if v["status"] == "DIFFER")
                differ_examples.append({
                    "image": r["image"],
                    "address": r["address"],
                    "function": r["function"],
                    "vector": first_bad[0],
                    "reason": first_bad[1]["reason"],
                    "mmio_match": first_bad[1].get("mmio_match"),
                    "orig_r0": first_bad[1].get("orig_r0"),
                    "recon_r0": first_bad[1].get("recon_r0"),
                    "ram_diff_addr": first_bad[1].get("ram_diff_addr"),
                })
        elif any(x["status"] == "MATCH" and x.get("exercised") for x in comparable):
            agg["EXERCISED_ALL_MATCH"] += 1
        elif any(x["status"] == "PREFIX_MATCH" for x in comparable):
            agg["PREFIX_MATCH_NONRETURN"] += 1
            if any(x["status"] == "PREFIX_MATCH" and x.get("exercised") for x in comparable):
                agg["PREFIX_MATCH_NONRETURN_EXERCISED"] += 1
            else:
                agg["PREFIX_MATCH_NONRETURN_VACUOUS"] += 1
        else:
            agg["VACUOUS_ALL_MATCH"] += 1

    comparable_total = total - agg["NEVER_COMPARABLE"] - agg["INTERIOR_LIBMATCH_FRAGMENT"]
    per_image: dict[str, dict] = {}
    rows_by_img: dict[str, list[dict]] = collections.defaultdict(list)
    for r in rows:
        rows_by_img[r["image"]].append(r)
    for img_short, img_rows in sorted(rows_by_img.items()):
        i_agg = collections.Counter()
        for r in img_rows:
            if r.get("libmatch_dropped"):
                i_agg["INTERIOR_LIBMATCH_FRAGMENT"] += 1
                continue
            comp = [x for x in r["vectors"].values() if x["status"] not in ("NOT_RUN", "INVALID_INPUT")]
            if not comp:
                i_agg["NEVER_COMPARABLE"] += 1
            elif any(x["status"] == "DIFFER" for x in comp):
                i_agg["FAILING_ANY_VECTOR"] += 1
            elif any(x["status"] == "MATCH" and x.get("exercised") for x in comp):
                i_agg["EXERCISED_ALL_MATCH"] += 1
            elif any(x["status"] == "PREFIX_MATCH" for x in comp):
                i_agg["PREFIX_MATCH_NONRETURN"] += 1
                if any(x["status"] == "PREFIX_MATCH" and x.get("exercised") for x in comp):
                    i_agg["PREFIX_MATCH_NONRETURN_EXERCISED"] += 1
                else:
                    i_agg["PREFIX_MATCH_NONRETURN_VACUOUS"] += 1
            else:
                i_agg["VACUOUS_ALL_MATCH"] += 1
        itot = len(img_rows)
        per_image[img_short] = {
            "total": itot,
            "exercised_all_match": i_agg["EXERCISED_ALL_MATCH"],
            "vacuous_all_match": i_agg["VACUOUS_ALL_MATCH"],
            "failing_any_vector": i_agg["FAILING_ANY_VECTOR"],
            "prefix_match_nonreturn": i_agg["PREFIX_MATCH_NONRETURN"],
            "prefix_match_nonreturn_exercised": i_agg["PREFIX_MATCH_NONRETURN_EXERCISED"],
            "prefix_match_nonreturn_vacuous": i_agg["PREFIX_MATCH_NONRETURN_VACUOUS"],
            "interior_libmatch_fragment": i_agg["INTERIOR_LIBMATCH_FRAGMENT"],
            "never_comparable": i_agg["NEVER_COMPARABLE"],
            "exercised_coverage_pct": round(100.0 * i_agg["EXERCISED_ALL_MATCH"] / itot, 2) if itot else 0.0,
        }

    return {
        "total_functions": total,
        "per_vector": per_vector,
        "per_image": per_image,
        "aggregate": {
            "machine_nullsub_excluded": sum(1 for r in rows if r.get("machine_class") in {"exact_nullsub", "nullsub_tail_alias"}),
            "exercised_all_match": agg["EXERCISED_ALL_MATCH"],
            "vacuous_all_match": agg["VACUOUS_ALL_MATCH"],
            "failing_any_vector": agg["FAILING_ANY_VECTOR"],
            "prefix_match_nonreturn": agg["PREFIX_MATCH_NONRETURN"],
            "prefix_match_nonreturn_exercised": agg["PREFIX_MATCH_NONRETURN_EXERCISED"],
            "prefix_match_nonreturn_vacuous": agg["PREFIX_MATCH_NONRETURN_VACUOUS"],
            "interior_libmatch_fragment": agg["INTERIOR_LIBMATCH_FRAGMENT"],
            "never_comparable": agg["NEVER_COMPARABLE"],
            "strict_all_match_pct": round(100.0 * (agg["EXERCISED_ALL_MATCH"] + agg["VACUOUS_ALL_MATCH"]) / total, 2) if total else 0.0,
            "comparable_all_match_pct": round(100.0 * (agg["EXERCISED_ALL_MATCH"] + agg["VACUOUS_ALL_MATCH"]) / (comparable_total - agg["PREFIX_MATCH_NONRETURN"]), 2) if comparable_total - agg["PREFIX_MATCH_NONRETURN"] else 0.0,
            "exercised_coverage_pct": round(100.0 * agg["EXERCISED_ALL_MATCH"] / total, 2) if total else 0.0,
        },
        "top_differs": differ_examples,
    }


def print_dashboard(report: dict) -> None:
    s = report["axis1_static"]
    d = report["axis3_multivector"]
    agg = d["aggregate"]
    print("\n================ AIC8800D80 FIDELITY METER ================")
    print(f"Axis 1 (Static): composed={s['total_composed']} defect_fns={s['static_defect_functions']} "
          f"(jumpout={s['jumpout_functions']} under_arity_casts={s['under_arity_cast_calls']} "
          f"memory_macro={s['memory_macro_functions']} missing_stubs={s['build']['total_missing_stubs']})")
    if s["build"]["post_compose_clean"] is not None:
        print(f"                 post_compose_clean={s['build']['post_compose_clean']} "
              f"reproduce_clean={s['build']['src_reproduce_clean']}")

    print("\nAxis 2/3 (Dynamic Vectors — MMIO + RAM + non-void r0):")
    for vname, stats in d["per_vector"].items():
        print(f"  {vname:12s} MATCH={stats['match']:4d} (exercised={stats['exercised_match']:4d}, "
              f"vacuous={stats['vacuous_match']:4d}) | PREFIX={stats.get('prefix_match',0):4d} | DIFFER={stats['differ']:4d} "
              f"(mmio_only_hidden={stats['mmio_only_hidden_differ']:4d}) | NOT_RUN={stats['not_run']:4d}")
        if stats["diff_reasons"]:
            print(f"               diff breakdown: {stats['diff_reasons']}")

    print("\nPer-Image Breakdown:")
    for img_short, ps in d.get("per_image", {}).items():
        print(f"  {img_short:14s} exercised={ps['exercised_all_match']:4d}/{ps['total']:4d} "
              f"({ps['exercised_coverage_pct']:5.2f}%) | vacuous={ps['vacuous_all_match']:4d} | "
              f"failing={ps['failing_any_vector']:3d} | prefix={ps.get('prefix_match_nonreturn',0):3d} | "
              f"frag={ps.get('interior_libmatch_fragment',0):2d} | never_comp={ps['never_comparable']:3d}")

    print(f"\nHeadline Aggregate ({d['total_functions']} functions):")
    print(f"  EXERCISED_ALL_MATCH : {agg['exercised_all_match']:4d} ({agg['exercised_coverage_pct']:.2f}% true non-trivial fidelity)")
    print(f"  VACUOUS_ALL_MATCH   : {agg['vacuous_all_match']:4d} (all matched, but 0 MMIO/RAM/non-zero r0 observed)")
    print(f"  FAILING_ANY_VECTOR  : {agg['failing_any_vector']:4d} (proven bug on >=1 vector)")
    print(f"  PREFIX_MATCH_NONRET : {agg.get('prefix_match_nonreturn',0):4d} "
          f"(exercised={agg.get('prefix_match_nonreturn_exercised',0)}, vacuous={agg.get('prefix_match_nonreturn_vacuous',0)}; not full equivalence)")
    print(f"  INTERIOR_FRAGMENT   : {agg.get('interior_libmatch_fragment',0):4d} (proven non-entry bytes inside linked libmatch parents)")
    print(f"  NEVER_COMPARABLE    : {agg['never_comparable']:4d}")
    print(f"  MACHINE_NULLSUB_R0_EXCLUDED: {agg.get('machine_nullsub_excluded', 0):4d} (bx-lr/nullsub aliases; vacuous structural units)")

    tl = report.get("axis4_truth_lane")
    if tl:
        print(f"\nAxis 4 (Truth-Lane Full): bare_zero={tl['bare_zero_full_pass']}/{tl['total_targets']} "
              f"| all_vectors={tl['all_vectors_full_pass']}/{tl['total_targets']}")
    print("Axis 4 (Boot Trace Prefix Parity):")
    for b in report["axis4_boot"]:
        print(f"  {b['image']:14s} matched_mmio_prefix={b['matched_prefix_writes']:4d}/{b['orig_writes']:4d} "
              f"| orig=({b['orig_term']},{b['orig_insns']}i) recon=({b['recon_term']},{b['recon_insns']}i)")
    print("===========================================================\n")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--image", choices=IMAGES, help="evaluate one image only")
    ap.add_argument("--jobs", type=int, default=8, help="worker processes (default: 8)")
    ap.add_argument("--max-insns", type=int, default=50000, help="per-vector instruction cap")
    ap.add_argument("--boot-insns", type=int, default=2000000, help="Axis 4 boot instruction safety cap")
    ap.add_argument("--boot-writes", type=int, default=4096, help="Axis 4 ordered peripheral-write event target")
    ap.add_argument("--vectors", default=",".join(DEFAULT_VECTORS),
                    help=f"comma-separated vectors from {','.join(ALL_VECTORS)}")
    ap.add_argument("--no-build-check", action="store_true",
                    help="skip running post_compose --check and make reproduce")
    ap.add_argument("--out", type=Path, default=None, help="optional directory for per-function JSONL")
    ap.add_argument("--json", type=Path, default=DEFAULT_JSON, help="output summary JSON path")
    args = ap.parse_args()

    vectors = tuple(v.strip() for v in args.vectors.split(",") if v.strip())
    for v in vectors:
        if v not in ALL_VECTORS:
            ap.error(f"unknown vector {v!r}; expected one of {', '.join(ALL_VECTORS)}")

    images = [args.image] if args.image else list(IMAGES)
    t0 = time.monotonic()

    static_per_image = [scan_static_defects(img) for img in images]
    build_status = check_build_gates(images, not args.no_build_check)
    axis1 = {
        "total_composed": sum(s["composed_functions"] for s in static_per_image),
        "jumpout_functions": sum(s["jumpout_functions"] for s in static_per_image),
        "memory_macro_functions": sum(s["memory_macro_functions"] for s in static_per_image),
        "under_arity_cast_calls": sum(s["under_arity_cast_calls"] for s in static_per_image),
        "static_defect_functions": sum(s["static_defect_functions"] for s in static_per_image),
        "per_image": static_per_image,
        "build": build_status,
    }

    ctx = multiprocessing.get_context("fork")
    all_rows: list[dict] = []
    boot_results: list[dict] = []
    for img in images:
        short = SHORT[img]
        elf_path = lrr.FULL_LINK / img / f"{img}.full.elf"
        if not elf_path.is_file():
            raise SystemExit(f"missing {elf_path}: run tools/full_link.py --text-base 0x800000 --out build/full_link_run")
        elf_info = load_elf_info(elf_path, image=img)
        bootstate = cs.capture_bootstate(img, 300000)
        boot_results.append(measure_boot_parity(img, elf_info, args.boot_insns, args.boot_writes))

        # post-demonolith main.c is an umbrella; expand module slices in
        # include order so the parser sees the logical single-TU text.
        main_text = composed_source.load_composed_text(short)
        parsed = parse_composed_functions(main_text)
        proto_by_addr = {int(r["address"], 16): r for r in prototype_infer.scan_image(img)}
        func_meta = build_func_meta(parsed, proto_by_addr)
        keys = sorted(func_meta)
        with ctx.Pool(
            args.jobs,
            initializer=_init_worker,
            initargs=(img, bootstate, elf_info, func_meta, vectors, args.max_insns),
        ) as pool:
            img_rows = pool.map(_eval_function, keys, chunksize=8)
        all_rows.extend(img_rows)
        print(f"[meter] {short}: {len(img_rows)} functions evaluated ({time.monotonic() - t0:.1f}s)",
              file=sys.stderr, flush=True)

    rows_by_key = {(r["image"], int(r["address"], 16)): r for r in all_rows}
    axis3 = summarize_rows(all_rows, vectors)
    axis2 = axis3["per_vector"].get("bare_zero", {})
    truth_lane = measure_truth_lane_full(rows_by_key) if len(images) == len(IMAGES) else None

    report = {
        "generated_at": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
        "elapsed_sec": round(time.monotonic() - t0, 1),
        "vectors": list(vectors),
        "axis1_static": axis1,
        "axis2_default_state": axis2,
        "axis3_multivector": axis3,
        "axis4_truth_lane": truth_lane,
        "axis4_boot": boot_results,
    }

    if args.out is not None:
        args.out.mkdir(parents=True, exist_ok=True)
        with (args.out / "fidelity_rows.jsonl").open("w") as f:
            for r in all_rows:
                f.write(json.dumps(r, sort_keys=True) + "\n")
        (args.out / "fidelity_meter.json").write_text(json.dumps(report, indent=2) + "\n")

    if not args.image or args.json != DEFAULT_JSON:
        args.json.parent.mkdir(parents=True, exist_ok=True)
        args.json.write_text(json.dumps(report, indent=2) + "\n")

    print_dashboard(report)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
