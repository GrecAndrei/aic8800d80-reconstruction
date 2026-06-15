#!/usr/bin/env python3
"""v24 v2: propagate LLM names across binaries via address-based map.

If fmacfw_u02's 0x100200 = memset_thunk, then fmacfw_h's 0x100200 should also be named memset_thunk.
Build propagated name map.
"""
import json, re, shutil
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent.parent
DEC_DIR = REPO / "harness_v19/decompiled"
OUT_DIR = REPO / "harness_v24"


def main():
    cross_map = json.load(open(OUT_DIR / "cross_map.json"))
    
    # For each address, find the best name (prefer non-sub_XXXXX)
    addr_to_names = defaultdict(list)  # addr -> [(img, name, hash)]
    for k, v in cross_map.items():
        addr_to_names[v['addr']].append((v['img'], v['name'], v['hash']))
    
    # For each address, pick best name
    addr_to_best = {}
    for addr, lst in addr_to_names.items():
        # Find name that's not "sub_XXXXX" or "start"
        named = [(i, n) for (i, n, h) in lst if not n.startswith('sub_') and n != 'start']
        if named:
            # Use the first named one
            addr_to_best[addr] = named[0][1]
        else:
            addr_to_best[addr] = lst[0][1]  # any name
    
    # For each function, check if its name differs from the propagated name
    propagated = {}
    n_changed = 0
    for k, v in cross_map.items():
        best = addr_to_best[v['addr']]
        if v['name'] != best:
            propagated[k] = {
                'img': v['img'],
                'addr': v['addr'],
                'old_name': v['name'],
                'new_name': best,
                'source_img': next((i for (i, n, h) in addr_to_names[v['addr']] if n == best), '?'),
            }
            n_changed += 1
    (OUT_DIR / "propagated_names.json").write_text(json.dumps(propagated, indent=2))
    print(f"Functions to rename: {n_changed}")
    
    # Apply names
    renamed = 0
    for k, v in propagated.items():
        img = v['img']
        addr_hex = v['addr'][2:].upper()  # strip "0x"
        new_name = v['new_name']
        old_file = DEC_DIR / img / f"{addr_hex}_{v['old_name']}.c"
        new_file = DEC_DIR / img / f"{addr_hex}_{new_name}.c"
        if old_file.exists():
            # Rename file
            if not new_file.exists():
                old_file.rename(new_file)
                # Update inside file too: sub_100200 -> new_name
                body = new_file.read_text()
                # Replace sub_OLDHEX with new_name in identifiers
                body = body.replace(v['old_name'] + ' ', new_name + ' ')
                body = body.replace(v['old_name'] + '(', new_name + '(')
                body = body.replace(v['old_name'] + ')', new_name + ')')
                body = body.replace(v['old_name'] + ',', new_name + ',')
                body = body.replace(v['old_name'] + ';', new_name + ';')
                body = body.replace(v['old_name'] + '}', new_name + '}')
                new_file.write_text(body)
                renamed += 1
    print(f"Renamed: {renamed} files")
    
    # Save summary
    summary = {
        'total_propagated': n_changed,
        'renamed': renamed,
        'names_used': sorted(set(v['new_name'] for v in propagated.values())),
    }
    (OUT_DIR / "propagation_summary.json").write_text(json.dumps(summary, indent=2))


if __name__ == "__main__":
    main()
