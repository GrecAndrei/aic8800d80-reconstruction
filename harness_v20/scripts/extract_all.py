#!/usr/bin/env python3
"""v20 Step 1: extract all load/store access patterns from all functions.

Output: harness_v20/access_patterns/<img>_patterns.json
Each entry: {
  func_addr: int,
  func_name: str,
  accesses: [{op, dst, base, offset, size, addr}, ...]
}
"""
import json, re, subprocess, sys, time
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor, as_completed

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
    img_key = img
    bin_path = REPO / f"inputs/firmware/{binaries[img]}.bin"
    cmd = ["r2", "-q", "-2", "-m", "0x100000", "-c",
           f"e asm.arch=arm; e asm.bits=16; pd {max_insn} @ {func_addr}",
           str(bin_path)]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=15)
    except Exception:
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

PATTERN = re.compile(
    r'(ldr|ldrh|ldrb|str|strh|strb)(?:\.w)?\s+(\w+),\s*\[(\w+)(?:,\s*(?:#|0x)?(-?0x[0-9a-f]+|-?\d+))?\]'
)

def extract_accesses(img, func_addr, func_name, max_insn=200):
    insns = disasm_function(img, func_addr, max_insn)
    accesses = []
    for addr, sz, insn in insns:
        m = PATTERN.search(insn)
        if not m:
            continue
        op, dst, base, off = m.group(1), m.group(2), m.group(3), m.group(4)
        if op in ('ldr', 'str'):
            size = 4
        elif op in ('ldrh', 'strh'):
            size = 2
        else:
            size = 1
        direction = 'load' if op.startswith('ldr') else 'store'
        if off is None:
            offset = 0
        elif off.startswith('0x') or off.startswith('-0x'):
            offset = int(off, 16)
        else:
            offset = int(off)
        if base.startswith('0x'):
            continue
        accesses.append({
            'op': op, 'dst': dst, 'base': base, 'offset': offset,
            'size': size, 'direction': direction, 'addr': addr
        })
    return func_addr, func_name, accesses

def main():
    v19_decompiled = REPO / "harness_v19/decompiled"
    out_dir = REPO / "harness_v20/access_patterns"
    out_dir.mkdir(parents=True, exist_ok=True)

    for img_dir in v19_decompiled.iterdir():
        if not img_dir.is_dir():
            continue
        img = img_dir.name
        if img not in binaries:
            continue
        out_file = out_dir / f"{img}_patterns.json"
        if out_file.exists():
            print(f"SKIP {img} (exists)")
            continue
        # Get all function addrs
        tasks = []
        for f in img_dir.glob("*.c"):
            m = re.match(r'^([0-9a-f]+)_(.+?)\.c$', f.name)
            if m:
                tasks.append((img, int(m.group(1), 16), m.group(2)))
        tasks.sort()
        print(f"Processing {img}: {len(tasks)} functions")
        t0 = time.time()
        results = []
        # Run in parallel
        with ThreadPoolExecutor(max_workers=8) as ex:
            futs = {ex.submit(extract_accesses, img, addr, name): (addr, name) for img, addr, name in tasks}
            for i, fut in enumerate(as_completed(futs)):
                addr, name, accesses = fut.result()
                results.append({'func_addr': addr, 'func_name': name, 'accesses': accesses})
                if (i+1) % 200 == 0:
                    print(f"  {i+1}/{len(tasks)} ({time.time()-t0:.0f}s)")
        results.sort(key=lambda r: r['func_addr'])
        with open(out_file, 'w') as f:
            json.dump({'img': img, 'funcs': results}, f)
        total_accesses = sum(len(r['accesses']) for r in results)
        print(f"  Done: {len(results)} funcs, {total_accesses} accesses, {time.time()-t0:.0f}s")

if __name__ == "__main__":
    main()
