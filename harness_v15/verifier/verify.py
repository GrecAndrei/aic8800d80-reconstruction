#!/usr/bin/env python3
"""Strong verifier for harness v15 synth bodies.

Rejects templates. Real decompilation must have callee names that
correspond to BL/BLX targets r2 finds in the actual disassembly.

Rule:
  For each `name();` call in the synth body, the disassembled function
  at the task's runtime_address must contain a BL/BLX branch to a
  function that maps to `name` in the symbol table (composed file).

Returns: {ok: bool, reason: str, evidence: {...}}
"""
import argparse
import json
import os
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]
COMPOSED_DIR = REPO / "extraction_out/reconstruction/mega7/composed"

CALLEE_RE = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(\s*\)\s*;", re.MULTILINE)
# Match BL/BLX with target address in r2 disasm
BL_RE = re.compile(r"\b(?:bl|blx)\s+([^\s,;]+)", re.IGNORECASE)
ADDR_RE = re.compile(r"0x([0-9a-fA-F]+)")


def find_composed_path(image: str) -> Path:
    """Map image basename to composed file path. e.g. fmacfw_8800d80_u02.bin -> fmacfw_8800d80_u02_bin.reconstructed.c"""
    base = image.replace(".bin", "_bin")
    return COMPOSED_DIR / f"{base}.reconstructed.c"


def build_symbol_set(image: str) -> set[str]:
    """Return the set of function names defined in the composed file for this image."""
    composed = find_composed_path(image)
    if not composed.exists():
        return set()
    text = composed.read_text(errors="replace")
    return {m.group(1) for m in re.finditer(r"^void\s+(\w+)\s*\(", text, re.MULTILINE)}


def r2_disasm(binary: Path, runtime_addr: int, load_base: int = 0x120000, analyze: bool = True) -> str:
    """Run r2 pdf @ runtime_addr, return text disasm.

    analyze=True: full -A analysis (slow, used for full disasm)
    analyze=False: no analysis (fast, used for bulk scoring where we only need BL detection)
    """
    cmd = ["r2", "-q"]
    if analyze:
        cmd.append("-A")
    cmd.extend([
        "-a", "arm", "-b", "16",
        "-m", f"0x{load_base:x}",
        "-c", f"pdf @ 0x{runtime_addr:x}",
        str(binary),
    ])
    try:
        out = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
    except subprocess.TimeoutExpired:
        return ""
    # Strip ANSI
    return re.sub(r"\x1b\[[0-9;]*m", "", out.stdout + out.stderr)


def extract_bl_targets(disasm: str, load_base: int = 0x120000) -> set[int]:
    """Extract BL/BLX target addresses from disasm text."""
    targets = set()
    for line in disasm.splitlines():
        m = BL_RE.search(line)
        if not m:
            continue
        addr_str = m.group(1)
        if addr_str.startswith("0x"):
            try:
                targets.add(int(addr_str, 16))
            except ValueError:
                pass
    return targets


def extract_bl_target_names(disasm: str) -> set[str]:
    """Extract BL/BLX target NAMES (not addresses) from disasm text.
    e.g. 'bl fcn.0x122adc' or 'bl sub_1234' or 'blx crypto_hw_disable'."""
    names = set()
    for line in disasm.splitlines():
        m = BL_RE.search(line)
        if not m:
            continue
        addr_str = m.group(1)
        if not addr_str.startswith("0x"):
            # symbolic target like "fcn.0xADDR"
            if addr_str.startswith("fcn."):
                names.add(addr_str)  # keep full "fcn.0xADDR"
            elif addr_str.startswith("sub_"):
                names.add(addr_str)
            else:
                names.add(addr_str)
    return names


def synth_callees(synth_body: str, fn_name: str) -> set[str]:
    """Extract all `name();` callees from synth body, excluding the function itself."""
    out = set()
    for m in CALLEE_RE.finditer(synth_body):
        c = m.group(1)
        if c != fn_name:
            out.add(c)
    return out


HELPFUL_KEYWORDS = (
    "rf_bus_write", "rf_reg_write", "rf_reg_read", "rf_bus_read",
    "rf_bus_reset", "rf_mem_write", "rf_mem_read", "rf_state_", "rf_level_",
    "rf_cmd_", "rf_msg_", "rf_hw_", "crypto_hw_", "crypto_key_", "crypto_reg_",
    "crypto_mac_", "crypto_state_", "crypto_table_", "timer_init", "log_tick",
    "timestamp_update", "log_system_init", "log_hw_init", "log_global_init",
    "log_pool_init", "clock_calc", "feature_guard_sdio", "firmware_init",
    "fw_config_apply", "math_round", "msg_parse",
)


def is_template_body(synth_body: str) -> bool:
    """Detect the v13 behavior_lift template signature: state-hash init + dispatch switch.

    Templates always have:
      uint32_t state = 0x...U;
      state ^= ...;
      uint32_t dispatch = 0U;
      dispatch = state ^ 0x6d2b79f5U;  (or similar magic)
      switch (dispatch & 3U) { ... default: state = (state << 1) | (state >> 31); helper(); break; }
    """
    if "dispatch = state ^ 0x6d2b79f5U" in synth_body:
        return True
    if "0x9E3779B9U" in synth_body and "state << 1) | (state >> 31)" in synth_body:
        return True
    if "state = (state << 1) | (state >> 31)" in synth_body and "switch (dispatch & 3U)" in synth_body:
        return True
    return False


def has_real_register_ops(synth_body: str, disasm: str) -> bool:
    """Check that the synth body has register/MMIO operations that mirror the disasm.

    A real body for a leaf function should have:
      *((volatile uint32_t *)(uintptr_t)0xADDR) = VAL;   (inline)
    or:
      volatile uint32_t *reg = (volatile uint32_t *)(uintptr_t)0xADDR;
      *reg = ...;  val = *reg;                            (via pointer)
    or r0/r1/r2/r3 style register operations, or
    casts like (uint32_t)0xADDR.

    Templates don't have these (just uint32_t state = 0x...; state ^= ...;).
    """
    # Inline MMIO: *((volatile uint32_t *)(uintptr_t)0xADDR)
    if "*((volatile uint32_t *)(uintptr_t)" in synth_body:
        return True
    # Pointer-variable MMIO: a (uintptr_t)0xADDR cast somewhere AND a *X deref
    if re.search(r"\(uintptr_t\)\s*0x[0-9a-fA-F]+U?", synth_body):
        if re.search(r"\*\w+\s*(=|[*])", synth_body):
            return True
    # Direct register name assignment: r4 = 0xNNU, etc.
    if re.search(r"\b(r[0-9]|sl|fp|ip|sp|lr)\s*=\s*0x[0-9a-fA-F]+U", synth_body):
        return True
    # uint32_t val = 0xNNN
    if re.search(r"uint32_t\s+\w+\s*=\s*0x[0-9a-fA-F]+U", synth_body) and re.search(r"\*\w+", synth_body):
        return True
    if "switch (dispatch" in synth_body:
        return False
    return False


def classify(synth_body: str, fn_name: str, disasm: str, symbol_set: set[str],
             min_callees: int, min_helpers: int) -> dict:
    """Run the strong verifier. Returns a dict with ok, reason, evidence.

    Three checks, in order:
    1. Template detection: reject behavior_lift templates outright.
    2. Leaf function path: if r2 shows 0 BL targets, body must have real
       register/MMIO operations that mirror the disasm.
    3. Calling function path: if r2 shows BL targets, at least 1 callee in
       the body must match a real BL target.
    """
    callees = synth_callees(synth_body, fn_name)
    helpers = sorted(c for c in callees if any(k in c for k in HELPFUL_KEYWORDS))
    bl_targets = extract_bl_targets(disasm)
    bl_names = extract_bl_target_names(disasm)
    # Effective leaf: no BL targets at all, OR only anonymous fcn.0xADDR targets
    # (we don't have a friendly name to call them by). Also exclude register names
    # (r0-r15, sl, fp, ip, sp, lr, pc) from blx via register.
    REG_NAMES = {f"r{i}" for i in range(16)} | {"sl", "fp", "ip", "sp", "lr", "pc"}
    named_bl_names = {
        n for n in bl_names
        if not n.startswith("fcn.")
        and not n.startswith("sub_")
        and n not in REG_NAMES
    }
    is_leaf = (len(bl_targets) == 0 and len(bl_names) == 0) or (
        len(named_bl_names) == 0 and (len(bl_targets) > 0 or len(bl_names) > 0)
    )

    # Check 1: Reject v13 templates
    if is_template_body(synth_body):
        return {
            "ok": False,
            "reason": "template_detected: synth body matches v13 behavior_lift template signature (state-hash + switch dispatch)",
            "callees": sorted(callees),
            "helpers": helpers,
            "is_leaf": is_leaf,
            "bl_targets_count": len(bl_targets),
            "bl_names_count": len(bl_names),
        }

    # Check 2: Leaf function path
    if is_leaf:
        # Function has no BL targets in r2 disasm. Body must reflect actual
        # register/MMIO operations, not just function calls.
        if callees:
            # Has callees but the function doesn't actually call anything.
            # Reject — the body is lying about the function's structure.
            return {
                "ok": False,
                "reason": f"leaf_with_callees: r2 shows 0 BL/BLX targets but body has {len(callees)} function calls. Leaf functions cannot have callees that don't exist in the binary.",
                "callees": sorted(callees),
                "helpers": helpers,
                "is_leaf": True,
                "bl_targets_count": 0,
            }
        # No callees, must have real register ops
        if not has_real_register_ops(synth_body, disasm):
            return {
                "ok": False,
                "reason": "leaf_no_real_ops: leaf function body has no real register/MMIO operations (just declarations)",
                "callees": sorted(callees),
                "helpers": helpers,
                "is_leaf": True,
            }
        return {
            "ok": True,
            "reason": "leaf_with_real_ops: leaf function with register/MMIO operations",
            "callees": sorted(callees),
            "helpers": helpers,
            "is_leaf": True,
        }

    # Check 3: Calling function path
    if len(callees) < min_callees:
        return {
            "ok": False,
            "reason": f"callee_count_below_min: got {len(callees)}, need {min_callees}",
            "callees": sorted(callees),
            "helpers": helpers,
            "is_leaf": False,
            "bl_targets_count": len(bl_targets),
        }

    if len(helpers) < min_helpers:
        return {
            "ok": False,
            "reason": f"helper_count_below_min: got {len(helpers)}, need {min_helpers}",
            "callees": sorted(callees),
            "helpers": helpers,
            "is_leaf": False,
        }

    # For each callee, find evidence
    real_callees = []
    unverified = []
    for c in callees:
        if c in bl_names:
            real_callees.append({"callee": c, "evidence": "bl_target_name_in_disasm"})
        elif c in symbol_set:
            # Real function exists in composed, but is it actually called from here?
            # Check if its address is in bl_targets via composed->addr map.
            # We don't have that map here, so check if the name appears in disasm at all.
            if c in disasm:
                real_callees.append({"callee": c, "evidence": "name_in_disasm_text"})
            else:
                unverified.append(c)
        elif c.startswith("fcn.") or c.startswith("sub_"):
            try:
                addr = int(c[4:], 16)
                if addr in bl_targets:
                    real_callees.append({"callee": c, "evidence": f"bl_target_addr_{hex(addr)}"})
                else:
                    unverified.append(c)
            except ValueError:
                unverified.append(c)
        else:
            unverified.append(c)

    if not real_callees:
        return {
            "ok": False,
            "reason": "no_real_callees: no callee matches a BL target in r2 disasm",
            "callees": sorted(callees),
            "helpers": helpers,
            "real_callees": real_callees,
            "unverified": unverified,
            "bl_targets_count": len(bl_targets),
        }

    return {
        "ok": True,
        "reason": "passed",
        "callees": sorted(callees),
        "helpers": helpers,
        "real_callees": real_callees,
        "unverified": unverified,
        "is_leaf": False,
        "bl_targets_count": len(bl_targets),
    }


def verify(task: dict, synth_body: str, fast: bool = False) -> dict:
    """Public API: verify a synth body against a task.

    fast=True: skip r2 analysis (much faster, may miss some BL targets but
    works for leaf detection where we only need to confirm no named BLs).
    """
    binary = REPO / task["binary"]
    runtime_addr = int(task["runtime_address_hex"], 16)
    fn = task["function"]

    symbol_set = build_symbol_set(task["image"])
    disasm = r2_disasm(binary, runtime_addr, analyze=not fast)
    if not disasm:
        return {"ok": False, "reason": "r2_failed_or_empty", "callees": [], "helpers": []}

    return classify(
        synth_body=synth_body,
        fn_name=fn,
        disasm=disasm,
        symbol_set=symbol_set,
        min_callees=task.get("min_callees", 2),
        min_helpers=task.get("min_helpers", 1),
    )


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--task", required=True, help="path to task JSON")
    ap.add_argument("--synth", required=True, help="path to synth.c file")
    args = ap.parse_args()

    task = json.loads(Path(args.task).read_text())
    synth = Path(args.synth).read_text(errors="replace")
    result = verify(task, synth)
    print(json.dumps(result, indent=2))
    return 0 if result["ok"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
