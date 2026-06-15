#!/usr/bin/env python3
"""v21: cross-reference v17 LLM-named functions with v20 struct field access.

For each (named_function, struct_field), identify which functions read/write
the field. This lets us:
1. See which functions are involved in a struct's lifecycle
2. Identify "owner" functions (write a field) vs "reader" functions
3. Find sets of fields touched together (likely semantic groups)
"""
import json
import re
import sys
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent.parent


def get_llm_names(img_dir):
    """Get func_addr -> LLM name mapping from v19 decompiled."""
    mapping = {}
    for f in img_dir.glob("*.c"):
        # Filename format: {addr}_{name}.c
        m = re.match(r'^([0-9a-f]+)_(.+?)\.c$', f.name)
        if m:
            addr = int(m.group(1), 16)
            name = m.group(2)
            mapping[addr] = name
    return mapping


def main():
    v19_dec = REPO / "harness_v19/decompiled"
    v20_pat = REPO / "harness_v20/access_patterns"
    out_dir = REPO / "harness_v21/field_map"
    out_dir.mkdir(parents=True, exist_ok=True)
    
    # Load v20 struct definitions (v19 + v20 combined)
    structs = json.load(open(REPO / "harness_v20/structs/aic8800d80_v20_structs.json"))
    
    # For each binary, build field access map
    for pat_file in v20_pat.glob("*_patterns.json"):
        img = pat_file.stem.removesuffix("_patterns")
        img_dir = v19_dec / img
        if not img_dir.exists():
            continue
        # Get LLM names
        names = get_llm_names(img_dir)
        # Get access patterns
        pat_data = json.load(open(pat_file))
        # Build field access map: struct_name -> field_offset -> [funcs]
        # Use base+offset to identify "this is likely a struct X"
        # Simple heuristic: any r0-r3 access is a struct pointer
        field_map = defaultdict(lambda: defaultdict(lambda: {"reads": [], "writes": [], "name_set": set()}))
        for func in pat_data['funcs']:
            faddr = func['func_addr']
            fname = names.get(faddr, f"sub_{faddr:x}")
            for acc in func['accesses']:
                base = acc['base']
                if base not in ('r0', 'r1', 'r2', 'r3'):
                    continue  # only function args
                # For each struct, check if this offset is a field
                for sname, fields in structs.items():
                    # Convert fields to offset->name map
                    for fname_in_struct, off_v in fields.items():
                        off = off_v if isinstance(off_v, int) else (off_v[0] if off_v else 0)
                        if acc['offset'] == off and acc['size'] == 4:
                            direction = 'reads' if acc['direction'] == 'load' else 'writes'
                            field_map[sname][off][direction].append({
                                'func': fname, 'addr': faddr
                            })
                            field_map[sname][off]['name'] = fname_in_struct
                            break
        # Build output
        out = {
            'img': img,
            'structs': {}
        }
        for sname, fields in field_map.items():
            s = {}
            for off, info in fields.items():
                if not info['reads'] and not info['writes']:
                    continue
                s[info['name']] = {
                    'offset': off,
                    'reads': info['reads'][:10],  # top 10
                    'read_count': len(info['reads']),
                    'writes': info['writes'][:10],
                    'write_count': len(info['writes']),
                }
            if s:
                out['structs'][sname] = s
        out_path = out_dir / f"{img}_field_map.json"
        out_path.write_text(json.dumps(out, indent=2))
        total_fields = sum(len(s) for s in out['structs'].values())
        print(f"{img}: {len(out['structs'])} structs, {total_fields} field touches")


if __name__ == "__main__":
    main()
