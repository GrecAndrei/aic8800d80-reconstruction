#!/usr/bin/env python3
"""v20_retype.py — Cross-reference Hex-Rays v19 types against r2 disassembly.

Builds a per-register memory-access-size map for each function, then compares
against the v19 variable declarations to fix pointer-width mismatches.

Strategy:
  1. Disassemble entire binary once via r2 (with asm.bytes=true for lengths).
  2. Build addr -> (mnemonic, ops, byte_len) lookup.
  3. For each function, walk its address range and collect per-register sizes
     for LDRB/STRB/LDRH/STRH/LDR/STR/LDRD/STRD instructions.
  4. For each v19 variable with a register mapping, compare declared pointer
     element width against narrowest observed size.
  5. If narrowest ≠ declared and the size is confident (small std-dev), rewrite.
  6. If Hex-Rays says non-pointer but r2 shows pointer-only use, mark.
"""
import re
import subprocess
import sys
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent.parent
DECOMPILED = REPO / "harness_v19/decompiled"
RECOMPILED = REPO / "harness_v19/decompiled_v20"

BINARIES = {
    "fmacfw_8800d80_h_u02_bin": "fmacfw_8800d80_h_u02",
    "fmacfw_8800d80_u02_bin": "fmacfw_8800d80_u02",
    "fmacfwbt_8800d80_u02_bin": "fmacfwbt_8800d80_u02",
    "lmacfw_rf_8800d80_u02_bin": "lmacfw_rf_8800d80_u02",
}

SIZE_MAP = {
    "ldrb": 1, "ldrsb": 1, "strb": 1,
    "ldrh": 2, "ldrsh": 2, "strh": 2,
    "ldr": 4, "str": 4,
    "ldrd": 8, "strd": 8,
}

WIDTH_TYPE = {1: "uint8_t", 2: "uint16_t", 4: "uint32_t", 8: "uint64_t"}
PTR_WIDTH = {
    "uint8_t *": 1, "unsigned char *": 1, "char *": 1, "__int8 *": 1, "_BYTE *": 1,
    "uint16_t *": 2, "unsigned short *": 2, "short *": 2, "__int16 *": 2, "_WORD *": 2,
    "uint32_t *": 4, "unsigned int *": 4, "int *": 4, "__int32 *": 4, "_DWORD *": 4,
    "uint64_t *": 8, "unsigned long long *": 8, "long long *": 8, "__int64 *": 8,
    "_QWORD *": 8,
}


def dump_disasm(bin_path, out_path):
    """Dump disassembly to a temp file via r2."""
    cmd = ["r2", "-q", "-2", "-m", "0x100000", "-c",
           "e asm.arch=arm; e asm.bits=16; e scr.color=false; e asm.emu=false; "
           "e asm.xrefs=false; e asm.cmt.right=false; e asm.tabs=0; "
           "e asm.bb.line=false; e asm.flags=false; e asm.bytes=true; "
           "e asm.pseudo=false; e asm.offset=true; "
           "pD 90000 @ 0x100000", str(bin_path)]
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=120)
    with open(out_path, 'w') as f:
        f.write(r.stdout)
    print(f"  Disasm dump: {len(r.stdout.splitlines())} lines", file=sys.stderr)


def parse_disasm_file(path):
    """Parse r2 dump to dict: addr -> (mnemonic, ops, byte_len)."""
    disasm = {}
    with open(path) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith((";", "│", "└", "├", "┌")):
                continue
            m = re.match(r'^(0x[0-9a-fA-F]+)\s+([0-9a-f]+)\s+(\S+)(.*)', line)
            if m:
                a = int(m.group(1), 16)
                raw_bytes = m.group(2)
                mnem = re.sub(r'\.(w|n)$', '', m.group(3).rstrip("."))
                ops = m.group(4).strip()
                byte_len = len(raw_bytes) // 2
                disasm[a] = (mnem, ops, byte_len)
    return disasm


def get_reg(ops):
    """Extract base register from memory-operand '[reg, ...]'."""
    bm = re.search(r'\[\s*(r\d+|sp|lr|pc|ip|sb|sl|fp)', ops.lower())
    return bm.group(1) if bm else None


def collect_reg_sizes(disasm, start, end):
    """Walk [start,end) in disasm, return dict: reg -> set of access sizes."""
    sizes = defaultdict(set)
    cur = start
    while cur < end:
        if cur in disasm:
            mnem, ops, blen = disasm[cur]
            sz = SIZE_MAP.get(mnem, 0)
            if sz:
                base = get_reg(ops)
                if base:
                    sizes[base].add(sz)
            cur += blen
        else:
            cur += 2
    return sizes


def parse_reg_map(text):
    """From v19 comments '// r5', build reg -> varname dict."""
    reg_map = {}
    for m in re.finditer(r'^\s*\S+\s+(\w+)\s*;\s*//\s*(r\d+|sp|lr|pc)\s*$', text, re.M):
        reg_map[m.group(2).lower()] = m.group(1)
    return reg_map


def determine_fixes(reg_map, reg_sizes, var_types):
    """Decide which variable declarations to rewrite."""
    fixes = []
    for reg, var in reg_map.items():
        if var not in var_types:
            continue
        cur_ty = var_types[var].strip()
        cur_sz = PTR_WIDTH.get(cur_ty)
        if cur_sz is None:
            continue  # not a pointer
        sizes = reg_sizes.get(reg, set())
        if not sizes:
            continue
        narrowest = min(sizes)
        if narrowest != cur_sz:
            # Confidence check: use narrowest unless the sizes are too mixed
            if len(sizes) == 1 or (len(sizes) == 2 and narrowest == 1):
                new_base = WIDTH_TYPE[narrowest]
                was_const = cur_ty.startswith("const ")
                new_ty = new_base + " *"
                if was_const:
                    new_ty = "const " + new_ty
                fixes.append((var, cur_ty, new_ty))
    return fixes


def apply_fixes(text, fixes):
    """Apply declaration rewrites to v19 function text."""
    if not fixes:
        return text
    lines = text.split('\n')
    for var, old_ty, new_ty in fixes:
        # Match declaration line
        pat = re.compile(
            r'^(\s*)' + re.escape(old_ty) + r'\s+' + re.escape(var) + r'(\s*;)'
        )
        for i, line in enumerate(lines):
            m = pat.match(line)
            if m:
                lines[i] = f'{m.group(1)}{new_ty}{var}{m.group(2)}'
                break
    return '\n'.join(lines)


def parse_var_types(text):
    """Parse local variable declarations from v19 function body."""
    types = {}
    for m in re.finditer(
        r'^\s+([\w\s\*]+?)\s+(\w+)\s*(?:\[[^\]]*\])?\s*;\s*(?://.*)?$',
        text, re.M
    ):
        ty = m.group(1).strip()
        v = m.group(2)
        if ty in (
            "return", "if", "else", "for", "while", "switch",
            "case", "default", "do", "break", "continue",
        ):
            continue
        if len(ty) < 1:
            continue
        types[v] = ty
    return types


def process_image(img, short_name, disasm, dump_path):
    src_dir = DECOMPILED / img
    dst_dir = RECOMPILED / img
    dst_dir.mkdir(parents=True, exist_ok=True)
    
    if not src_dir.exists():
        return 0
    
    files = sorted(src_dir.glob("*.c"))
    total = 0
    fixed = 0
    for cfile in files:
        m = re.match(r'^([0-9a-fA-F]+)_', cfile.name)
        if not m:
            continue
        addr = int(m.group(1), 16)
        text = cfile.read_text()
        sm = re.search(r'size (\d+) bytes', text)
        size = int(sm.group(1)) if sm else 32
        end = addr + size
        reg_map = parse_reg_map(text)
        reg_sizes = collect_reg_sizes(disasm, addr, end)
        var_types = parse_var_types(text)
        fixes = determine_fixes(reg_map, reg_sizes, var_types)
        if fixes:
            new_text = apply_fixes(text, fixes)
            (dst_dir / cfile.name).write_text(new_text)
            fixed += 1
        else:
            (dst_dir / cfile.name).write_text(text)
        total += 1
    print(f"  {img}: {fixed}/{total} functions modified", file=sys.stderr)
    return fixed


def main():
    tmp_dir = Path("/tmp/v20_retype")
    tmp_dir.mkdir(exist_ok=True)
    grand_total = 0
    for img, short in BINARIES.items():
        bin_path = REPO / f"inputs/firmware/{short}.bin"
        dump_path = tmp_dir / f"{short}.disasm"
        if not dump_path.exists():
            print(f"Dumping disasm for {img}...", file=sys.stderr)
            dump_disasm(bin_path, dump_path)
        else:
            print(f"Using existing dump for {img}", file=sys.stderr)
        print(f"Parsing disasm for {img}...", file=sys.stderr)
        disasm = parse_disasm_file(dump_path)
        print(f"  Disasm entries: {len(disasm)}", file=sys.stderr)
        n = process_image(img, short, disasm, dump_path)
        grand_total += n
    print(f"\nTotal functions modified: {grand_total}", file=sys.stderr)


if __name__ == '__main__':
    main()
