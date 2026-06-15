#!/usr/bin/env python3
"""v23: annotate v19 decompiled C with struct type hints per function.

For each function in v19 decompiled:
1. Find its cluster (from v22 xref)
2. Attach struct name and field list as a header comment
3. Also build a "field usage table" showing which offsets are touched
"""
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
    v22_xref = REPO / "harness_v22/field_map"
    v22_structs = json.load(open(REPO / "harness_v22/structs/aic8800d80_v22_structs.json"))
    
    out_dir = REPO / "harness_v23/annotated"
    out_dir.mkdir(parents=True, exist_ok=True)
    
    summary = {}
    for xref_file in v22_xref.glob("*_cluster_xref.json"):
        xref = json.load(open(xref_file))
        img = xref['img']
        img_dir = v19_dec / img
        if not img_dir.exists(): continue
        names = get_llm_names(img_dir)
        # Build cluster -> name mapping
        cluster_structs = {}
        for cid, c in xref['clusters'].items():
            if not c['name'].startswith('group_'):
                cluster_structs[cid] = c['name']
        
        # Build func_addr -> cluster (via xref names + sample_funcs)
        # Actually xref already has n_funcs_total, but not all funcs
        # Let me read full cluster xref from v21 instead
        v21_xref = json.load(open(REPO / "harness_v21/field_map" / f"{img}_cluster_xref.json"))
        v22_xref_data = xref  # already loaded
        # Build map: v21 cluster_id -> v22 name
        v21_to_v22_name = {}
        for cid_v21, c_v21 in v21_xref['clusters'].items():
            gid = c_v21.get('group_id')
            v22_cid = f"cluster_{gid}"
            v22_c = v22_xref_data['clusters'].get(v22_cid)
            if v22_c:
                v21_to_v22_name[cid_v21] = v22_c.get('name')
        # Build func_name -> cluster
        func_to_cluster = {}
        for cid, c in v21_xref['clusters'].items():
            all_funcs_in_cluster = set()
            for fid, f in c['field_touches'].items():
                for r in f.get('reads', []):
                    all_funcs_in_cluster.add(r)
                for w in f.get('writes', []):
                    all_funcs_in_cluster.add(w)
            # Attach name
            c['_v22_name'] = v21_to_v22_name.get(cid)
            for fn in all_funcs_in_cluster:
                func_to_cluster[fn] = c
        
        # Now annotate each function
        img_out_dir = out_dir / img
        img_out_dir.mkdir(parents=True, exist_ok=True)
        n_annotated = 0
        n_with_struct = 0
        for f in img_dir.glob("*.c"):
            m = re.match(r'^([0-9a-f]+)_(.+?)\.c$', f.name)
            if not m:
                continue
            addr = int(m.group(1), 16)
            fname = m.group(2)
            cluster = func_to_cluster.get(fname)
            original = f.read_text()
            
            # Build annotation header
            annotation = f"// v23 annotated: {fname} @ 0x{addr:x}\n"
            annotation += f"// Original: {f.name}\n"
            if cluster:
                cname = cluster.get('_v22_name') or cluster.get('name', 'unknown')
                if cname in v22_structs:
                    fields = v22_structs[cname]
                    annotation += f"// Primary struct: {cname} (cluster {cluster.get('group_id', '?')}, {cluster.get('n_funcs_total', '?')} funcs)\n"
                    annotation += f"// Fields: {', '.join(f'{n}=0x{o:x}' for n, o in list(fields.items())[:10])}\n"
                    n_with_struct += 1
                else:
                    annotation += f"// Primary struct: {cname} (cluster {cluster.get('group_id', '?')})\n"
                n_annotated += 1
            else:
                annotation += f"// Primary struct: <unclustered>\n"
            
            # Add cluster fingerprint as comment
            if cluster:
                fp = cluster.get('fingerprint', [])
                if fp:
                    annotation += f"// Cluster fingerprint: {[(f'+0x{o:04x}', s) for o, s in fp]}\n"
            
            annotation += "//\n"
            
            # Write
            out_file = img_out_dir / f.name
            with open(out_file, 'w') as of:
                of.write(annotation)
                of.write(original)
        
        summary[img] = {
            'total_funcs': len(list(img_dir.glob("*.c"))),
            'annotated': n_annotated,
            'with_struct': n_with_struct,
        }
        print(f"{img}: {n_annotated}/{summary[img]['total_funcs']} annotated, {n_with_struct} with named struct")
    
    out_path = REPO / "harness_v23/SUMMARY.json"
    out_path.write_text(json.dumps(summary, indent=2))
    print(f"\nSummary: {out_path}")


if __name__ == "__main__":
    main()
