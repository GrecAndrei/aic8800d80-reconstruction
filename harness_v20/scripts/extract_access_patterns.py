#!/usr/bin/env python3
"""v20 Step 1: extract access patterns from disassembly.

For each function, find every load/store instruction and record:
- base register (r0-r7, sp, lr)
- offset (immediate or symbolic)
- size (1=ldrb/strb, 2=ldrh/strh, 4=ldr/str)
- direction (load vs store)

Group accesses by base register + offset to identify struct field candidates.
"""
import json, re, subprocess, sys
from pathlib import Path
from collections import defaultdict, Counter

REPO = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(REPO / "harness_v17"))
from tools import _bin  # type: ignore

binaries = {
    "fmacfw_8800d80_h_u02_bin": "fmacfw_8800d80_h_u02",
    "fmacfw_8800d80_u02_bin": "fmacfw_8800d80_u02",
    "fmacfwbt_8800d80_u02_bin": "fmacfwbt_8800d80_u02",
    "lmacfw_rf_8800d80_u02_bin": "lmacfw_rf_8800d80_u02",
}

def disasm_function(img, func_addr, max_insn=200):
    """Use r2 to disassemble function. Returns list of (addr, size, insn)."""
    bin_path = REPO / f"inputs/firmware/{binaries[img]}.bin"
    cmd = ["r2", "-q", "-2", "-m", "0x100000", "-c",
           f"e asm.arch=arm; e asm.bits=16; pd {max_insn} @ {func_addr}",
           str(bin_path)]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=15)
    except Exception as e:
        return []
    out = re.sub(r'\x1b\[[0-9;]*m', '', result.stdout)
    items = []
    for line in out.split('\n'):
        m = re.match(r'\s*(?:[│┌└─> ]*)\s*0x([0-9a-f]+)\s+([0-9a-f]+)(?:\s+([0-9a-f]+))?\s*(.*)', line)
        if not m:
            continue
        cur = int(m.group(1), 16)
        if cur < func_addr:
            continue
        size = int(m.group(2), 16) // 2
        insn = m.group(4).strip()
        items.append((cur, size, insn))
        if 'bx lr' in insn or ('pop' in insn and 'pc' in insn):
            break
    return items

# Patterns:
# ldr  rN, [rM, #imm]    -> size 4 load
# ldrh rN, [rM, #imm]    -> size 2 load
# ldrb rN, [rM, #imm]    -> size 1 load
# str  rN, [rM, #imm]    -> size 4 store
# strh rN, [rM, #imm]    -> size 2 store
# strb rN, [rM, #imm]    -> size 1 store
# ldr  rN, [sp, #imm]    -> sp-based
PATTERN = re.compile(
    r'(ldr|ldrh|ldrb|str|strh|strb)\s+(\w+),\s*\[(\w+)(?:,\s*#(-?\d+))?\]'
)

# Address ranges (we can also extract from v18 source)
def extract_funcs_from_v18(v18_path):
    """Get function addresses from v18 .c file."""
    funcs = []
    for m in re.finditer(r'void\s+(\w+)\s*\(\s*void\s*\)', v18_path.read_text()):
        name = m.group(1)
        funcs.append(name)
    return funcs

# Step 1: get all function addrs from v18 sources
# The v18 source has the function body as .byte directives - we can get the address range
# Better: use the decompiled filenames which have <addr>_<name>.c format
v19_decompiled = REPO / "harness_v19/decompiled"
print("Step 1: getting function addrs from v19 decompiled filenames")

for img_dir in v19_decompiled.iterdir():
    if not img_dir.is_dir():
        continue
    img = img_dir.name
    addrs = []
    for f in img_dir.glob("*.c"):
        m = re.match(r'^([0-9a-f]+)_', f.name)
        if m:
            addrs.append(int(m.group(1), 16))
    addrs.sort()
    print(f"  {img}: {len(addrs)} functions")
    # Test disasm on first 5
    if img == "fmacfw_8800d80_h_u02_bin":
        for addr in addrs[:5]:
            insns = disasm_function(img, addr, max_insn=30)
            print(f"    0x{addr:x}: {len(insns)} insns")
            if insns:
                print(f"      first: {insns[0]}")
