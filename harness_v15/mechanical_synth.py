#!/usr/bin/env python3
"""Phase B: Mechanically generate synth bodies from r2 disassembly.

For each missing behavioral file:
  1. Run r2 to get the disassembly
  2. Extract MMIO operations (LDR/STR with constant pool, MOV/MVN)
  3. Emit a C body that replays those operations
  4. (Optional) Use the LLM to add structure: loops, branches, callee hints

The LLM is NOT asked to translate assembly. It only suggests structure
based on a complete mechanical draft + the disasm.

Outputs to out/_mechanical/<task_id>/synth.c
"""
import json
import re
import subprocess
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
SYNTH_ROOT = REPO / "artifacts/releases/aic8800d80-rebuild-v1/synth"
TRUTH_LANE = REPO / "extraction_out/reconstruction/truth_lane_state/truth_lane_targets.json"
OUT_ROOT = REPO / "harness_v15/out/_mechanical"
ANSI_RE = re.compile(r"\x1b\[[0-9;]*m")

# 3 missing behavioral traces
MISSING = [
    ("crypto_hw_disable", 0x2b40, "lmacfw_rf_8800d80_u02.bin"),
    ("rf_mem_write", 0x2fd64, "fmacfwbt_8800d80_u02.bin"),
    ("rf_bus_write2", 0x11524, "lmacfw_rf_8800d80_u02.bin"),
]


def r2_pdf(binary: Path, runtime: int) -> str:
    """Run r2 pdf, return stripped text."""
    cmd = ["r2", "-q", "-A", "-a", "arm", "-b", "16", "-m", "0x120000",
           "-c", f"pdf @ 0x{runtime:x}", str(binary)]
    try:
        out = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
        return ANSI_RE.sub("", (out.stdout or "") + (out.stderr or ""))
    except Exception as e:
        return f"[r2 error: {e}]"


# Patterns to extract MMIO operations from r2 disasm
LDR_CONSTPOOL = re.compile(
    r"ldr\s+r(\d+),\s*\[pc,\s*#(0x[0-9a-fA-F]+)\][^\n]*?;\s*\(0x([0-9a-fA-F]+)\)",
    re.IGNORECASE,
)
STR_TO_REG = re.compile(r"str\s+r(\d+),\s*\[r(\d+)(?:,\s*#(0x[0-9a-fA-F]+))?\]", re.IGNORECASE)
LDR_FROM_REG = re.compile(r"ldr\s+r(\d+),\s*\[r(\d+)(?:,\s*#(0x[0-9a-fA-F]+))?\]", re.IGNORECASE)
MOV_IMM = re.compile(r"movs?\s+r(\d+),\s*#(0x[0-9a-fA-F]+)", re.IGNORECASE)
MVN_IMM = re.compile(r"mvn\s+r(\d+),\s*#(0x[0-9a-fA-F]+)", re.IGNORECASE)
SUBS = re.compile(r"subs\s+r(\d+),\s*r(\d+),\s*#1\b", re.IGNORECASE)
B = re.compile(r"^\s*0x[0-9a-fA-F]+\s+(\S+)\s+(b|bne|beq|bl|blx|b\s)", re.IGNORECASE | re.MULTILINE)


def emit_mechanical_body(disasm: str, fn_name: str) -> str:
    """Convert r2 disasm to a mechanical C body.

    Strategy: emit MMIO reads/writes literally, with comments showing original asm.
    """
    lines = [
        f"/* Auto-generated mechanical synth from r2 disasm */",
        f"/* function: {fn_name} */",
        f"",
        f"void {fn_name}(void) {{",
    ]

    # Track register->value mappings we can resolve
    reg_vals = {}  # rN -> int

    for line in disasm.splitlines():
        # Skip headers/footers
        if "──" in line or "Relic" in line or "[" in line and "0x" in line and "]" in line and ":" in line and len(line) < 80:
            continue
        if "│" in line and ("0x" in line) and (":" in line):
            # Processable disasm line, extract the instruction
            m = re.search(r"0x[0-9a-fA-F]+\s+[0-9a-fA-F]+\s+(.+?)\s*(;.*)?$", line)
            if not m:
                continue
            inst = m.group(1).strip()
            comment = m.group(2) or ""
            inst = inst.strip()
            if not inst:
                continue
            # LDR from constant pool
            m = LDR_CONSTPOOL.search(inst)
            if m:
                reg_n, _, addr = m.groups()
                addr_int = int(addr, 16)
                lines.append(f"  (void)*((volatile uint32_t *)(uintptr_t)0x{addr_int:x}U);  /* ldr r{reg_n}, 0x{addr_int:x} */")
                continue
            # MOV imm
            m = MOV_IMM.search(inst)
            if m:
                reg_n, val = m.groups()
                reg_vals[int(reg_n)] = int(val, 16)
                continue
            # MVN imm
            m = MVN_IMM.search(inst)
            if m:
                reg_n, val = m.groups()
                reg_vals[int(reg_n)] = ~int(val, 16) & 0xFFFFFFFF
                continue
            # Skip branches/bl/push/pop for now
            if any(x in inst.lower() for x in [" b ", "bl ", "blx", "push", "pop", "bx ", "nop"]):
                continue
            # Skip compares
            if inst.lower().startswith("cmp"):
                continue

    lines.append("}")
    return "\n".join(lines)


def main() -> int:
    OUT_ROOT.mkdir(parents=True, exist_ok=True)
    t0 = time.time()
    for fn, addr, img in MISSING:
        runtime = addr + 0x120000
        binary = REPO / f"inputs/firmware/{img}"
        task_id = f"mechanical_{fn}_{img.replace('.bin','')}"
        out_dir = OUT_ROOT / task_id
        out_dir.mkdir(parents=True, exist_ok=True)
        print(f"[{time.time()-t0:.1f}s] {fn} @ 0x{addr:x} in {img}", flush=True)
        disasm = r2_pdf(binary, runtime)
        (out_dir / "disasm.txt").write_text(disasm)
        body = emit_mechanical_body(disasm, fn)
        (out_dir / "synth.c").write_text(body)
        print(f"   wrote {out_dir}/synth.c ({len(body)} chars)", flush=True)
    print(f"\nDone in {time.time()-t0:.1f}s")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
