#!/usr/bin/env python3
"""v24: extract strings from binaries and link to functions."""
import re, struct, json
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent.parent
INPUTS = REPO / "inputs/firmware"
DEC_DIR = REPO / "harness_v19/decompiled"
OUT = REPO / "harness_v24/strings.json"
OUT.parent.mkdir(exist_ok=True)


def extract_strings(bin_path, base_addr=0x100000):
    """Extract printable strings from a binary."""
    data = bin_path.read_bytes()
    strings = []  # list of (file_offset, addr, string)
    for m in re.finditer(rb'[\x20-\x7e]{4,}', data):
        s = m.group(0).decode('latin-1')
        fo = m.start()
        addr = base_addr + fo
        strings.append((fo, addr, s))
    return strings


def main():
    bins = {
        'fmacfw_8800d80_h_u02_bin': INPUTS / 'fmacfw_8800d80_h_u02.bin',
        'fmacfw_8800d80_u02_bin': INPUTS / 'fmacfw_8800d80_u02.bin',
        'fmacfwbt_8800d80_u02_bin': INPUTS / 'fmacfwbt_8800d80_u02.bin',
        'lmacfw_rf_8800d80_u02_bin': INPUTS / 'lmacfw_rf_8800d80_u02.bin',
    }
    
    all_data = {}
    for img, p in bins.items():
        # Find string references in C code (off_XXXXX, aOff, aXxxxxxx)
        img_dir = DEC_DIR / img
        if not img_dir.exists():
            continue
        strs = extract_strings(p)
        str_by_addr = {addr: s for (fo, addr, s) in strs}
        print(f"{img}: {len(strs)} strings")
        
        # For each function, find which off_ addresses it references
        func_strings = {}
        # Get function boundaries
        func_addrs = sorted(int(m.group(1), 16) for m in (re.match(r'^([0-9a-f]+)_', f.name) for f in img_dir.glob("*.c")) if m)
        for f in img_dir.glob("*.c"):
            m = re.match(r'^([0-9a-f]+)_(.+?)\.c$', f.name)
            if not m: continue
            addr = int(m.group(1), 16)
            body = f.read_text()
            # Find addresses referenced
            refs = set()
            for m2 in re.finditer(r'0x([0-9a-fA-F]{6,8})', body):
                try:
                    refs.add(int(m2.group(1), 16))
                except: pass
            # Find addresses that have strings
            ref_strs = []
            for r in refs:
                if r in str_by_addr:
                    ref_strs.append((hex(r), str_by_addr[r]))
            if ref_strs:
                func_strings[hex(addr)] = ref_strs
        all_data[img] = {
            'string_count': len(strs),
            'funcs_with_strings': len(func_strings),
            'func_strings': func_strings,
        }
        print(f"  funcs with strings: {len(func_strings)}")
    
    OUT.write_text(json.dumps(all_data, indent=2))
    print(f"\nSaved: {OUT}")


if __name__ == "__main__":
    main()
