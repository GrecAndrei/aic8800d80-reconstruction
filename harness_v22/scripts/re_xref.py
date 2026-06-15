#!/usr/bin/env python3
"""v22: re-run cross-reference with combined v19+v20+v22 struct list."""
import json, re, sys
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent.parent

def get_llm_names(img_dir):
    mapping = {}
    for f in img_dir.glob("*.c"):
        m = re.match(r'^([0-9a-f]+)_(.+?)\.c$', f.name)
        if m:
            mapping[int(m.group(1), 16)] = m.group(2)
    return mapping

def main():
    v19_dec = REPO / "harness_v19/decompiled"
    v20_pat = REPO / "harness_v20/access_patterns"
    v20_clu = REPO / "harness_v20/structs"
    out_dir = REPO / "harness_v22/field_map"
    out_dir.mkdir(parents=True, exist_ok=True)
    structs = json.load(open(REPO / "harness_v22/structs/aic8800d80_v22_structs.json"))
    
    for clu_file in v20_clu.glob("*_clusters.json"):
        img = clu_file.stem.removesuffix("_clusters")
        img_dir = v19_dec / img
        if not img_dir.exists(): continue
        names = get_llm_names(img_dir)
        clu_data = json.load(open(clu_file))
        pat_data = json.load(open(REPO / "harness_v20/access_patterns" / f"{img}_patterns.json"))
        # Build fp -> group mapping (with v22 naming)
        fp_to_group = {}
        for g in clu_data['significant_groups']:
            fp = frozenset(tuple(p) for p in g['fingerprint'])
            fp_to_group[fp] = g
        # For each cluster, find all funcs in this binary matching its fingerprint
        cluster_funcs = defaultdict(set)
        for func in pat_data['funcs']:
            base_accs = defaultdict(set)
            for acc in func['accesses']:
                if acc['base'] in ('r0', 'r1', 'r2', 'r3', 'r4', 'r5'):
                    base_accs[acc['base']].add((acc['offset'], acc['size']))
            if base_accs:
                primary = max(base_accs, key=lambda b: len(base_accs[b]))
                fp = frozenset(base_accs[primary])
                if fp in fp_to_group:
                    cluster_funcs[fp_to_group[fp]['group_id']].add(func['func_addr'])
        # Build report
        out = {'img': img, 'clusters': {}}
        # Load v22 named.json for struct names
        named = json.load(open(REPO / "harness_v22/structs/named.json"))
        # Map: fingerprint -> v22 name
        v22_fps = {}
        for p in named['proposals']:
            for f in p['fields']:
                # Build fp from v22 named
                v22_fps.setdefault(p['name'], []).append((f['off'], f['size']))
        v22_fp_to_name = {}
        for n, fs in v22_fps.items():
            fp = tuple(sorted(fs))
            v22_fp_to_name[fp] = n
        
        for g in clu_data['significant_groups']:
            gid = g['group_id']
            faddrs = cluster_funcs.get(gid, set())
            named_funcs = [names.get(a, f"sub_{a:x}") for a in sorted(faddrs)]
            # Attach name by fingerprint
            fp = tuple(sorted(tuple(p) for p in g['fingerprint']))
            sname = v22_fp_to_name.get(fp, None)
            # If still no name, try to match by v20 LLM proposals
            if not sname:
                # Try v20 proposals
                props = json.load(open(REPO / "harness_v20/structs/proposals_v4.json"))
                for pgroup in props.get('parsed', {}).get('groups', []):
                    pfp = tuple(sorted((f['off'], f['size']) for f in pgroup.get('fields', [])))
                    if pfp == fp:
                        sname = pgroup['name']
                        break
            
            out['clusters'][f"cluster_{gid}"] = {
                'group_id': gid,
                'name': sname or f"group_{gid}",
                'primary_arg': g['primary_arg'],
                'n_funcs_total': len(faddrs),
                'funcs_named': [f for f in named_funcs if not f.startswith('sub_')][:30],
                'funcs_sub': [f for f in named_funcs if f.startswith('sub_')][:5],
            }
        out_path = out_dir / f"{img}_cluster_xref.json"
        out_path.write_text(json.dumps(out, indent=2))
        # Count
        n_named = sum(1 for c in out['clusters'].values() if not c['name'].startswith('group_'))
        print(f"{img}: {n_named}/{len(out['clusters'])} clusters named")

if __name__ == "__main__":
    main()
