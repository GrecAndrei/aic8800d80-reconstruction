#!/usr/bin/env python3
"""v21 v2: cross-reference using v20 cluster fingerprints.

For each v20 cluster (which identifies a struct by its full access fingerprint),
list the LLM-named functions that use it. This is a more accurate cross-reference
because it matches the entire struct pattern, not just one offset.
"""
import json
import re
import sys
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent.parent


def get_llm_names(img_dir):
    mapping = {}
    for f in img_dir.glob("*.c"):
        m = re.match(r'^([0-9a-f]+)_(.+?)\.c$', f.name)
        if m:
            addr = int(m.group(1), 16)
            name = m.group(2)
            mapping[addr] = name
    return mapping


def main():
    v19_dec = REPO / "harness_v19/decompiled"
    v20_pat = REPO / "harness_v20/access_patterns"
    v20_clu = REPO / "harness_v20/structs"
    out_dir = REPO / "harness_v21/field_map"
    out_dir.mkdir(parents=True, exist_ok=True)
    
    structs = json.load(open(REPO / "harness_v20/structs/aic8800d80_v20_structs.json"))
    
    # For each binary
    for clu_file in v20_clu.glob("*_clusters.json"):
        img = clu_file.stem.removesuffix("_clusters")
        img_dir = v19_dec / img
        if not img_dir.exists():
            continue
        # Get LLM names
        names = get_llm_names(img_dir)
        # Get cluster data
        clu_data = json.load(open(clu_file))
        # For each cluster, get the list of funcs in that cluster
        # Cluster funcs are SAMPLE funcs; need full cluster membership
        # But for v21 report, sample is enough
        
        # Also get access patterns to compute full coverage
        pat_data = json.load(open(REPO / "harness_v20/access_patterns" / f"{img}_patterns.json"))
        # Build func_addr -> set of (offset, size) accessed on its primary arg
        func_fingerprints = {}
        for func in pat_data['funcs']:
            base_accs = defaultdict(set)
            for acc in func['accesses']:
                if acc['base'] in ('r0', 'r1', 'r2', 'r3', 'r4', 'r5'):
                    base_accs[acc['base']].add((acc['offset'], acc['size']))
            # Pick primary arg
            if base_accs:
                primary = max(base_accs, key=lambda b: len(base_accs[b]))
                func_fingerprints[func['func_addr']] = frozenset(base_accs[primary])
        
        # Build fingerprint -> cluster
        fp_to_group = {}
        for g in clu_data['significant_groups']:
            fp = frozenset(tuple(p) for p in g['fingerprint'])
            fp_to_group[fp] = g
        
        # For each cluster, find ALL funcs in this binary matching its fingerprint
        cluster_funcs = defaultdict(set)
        for faddr, fp in func_fingerprints.items():
            if fp in fp_to_group:
                cluster_funcs[fp_to_group[fp]['group_id']].add(faddr)
        
        # Build report
        out = {'img': img, 'clusters': {}}
        for g in clu_data['significant_groups']:
            gid = g['group_id']
            faddrs = cluster_funcs.get(gid, set())
            named_funcs = [names.get(a, f"sub_{a:x}") for a in sorted(faddrs)]
            # For each fingerprint field, identify which named funcs touch it
            field_touches = defaultdict(lambda: {"reads": set(), "writes": set()})
            for faddr in faddrs:
                fname = names.get(faddr, f"sub_{faddr:x}")
                for func in pat_data['funcs']:
                    if func['func_addr'] != faddr:
                        continue
                    for acc in func['accesses']:
                        if acc['base'] != g['primary_arg']:
                            continue
                        if [acc['offset'], acc['size']] in g['fingerprint']:
                            direction = 'reads' if acc['direction'] == 'load' else 'writes'
                            field_touches[(acc['offset'], acc['size'])][direction].add(fname)
            
            cluster_name = g.get('name', f"group_{gid}")
            out['clusters'][f"cluster_{gid}_{cluster_name}"] = {
                'group_id': gid,
                'name': cluster_name,
                'primary_arg': g['primary_arg'],
                'n_funcs_total': len(faddrs),
                'funcs_named': [f for f in named_funcs if not f.startswith('sub_')][:30],
                'funcs_sub': [f for f in named_funcs if f.startswith('sub_')][:5],
                'field_touches': {
                    f"off_{off:04x}_s{size}": {
                        'offset': off, 'size': size,
                        'reads': list(info['reads'])[:10],
                        'writes': list(info['writes'])[:10],
                    }
                    for (off, size), info in field_touches.items()
                }
            }
        out_path = out_dir / f"{img}_cluster_xref.json"
        out_path.write_text(json.dumps(out, indent=2))
        total_funcs = sum(c['n_funcs_total'] for c in out['clusters'].values())
        print(f"{img}: {len(out['clusters'])} clusters, {total_funcs} funcs total")


if __name__ == "__main__":
    main()
