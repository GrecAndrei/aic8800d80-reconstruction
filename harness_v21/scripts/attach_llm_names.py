#!/usr/bin/env python3
"""v21: attach LLM struct names to v21 cluster reports by fingerprint match."""
import json
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent.parent

# Load v20 proposals
props = json.load(open(REPO / "harness_v20/structs/proposals_v4.json"))
llm_fps = {}
for g in props.get('parsed', {}).get('groups', []):
    name = g['name']
    fingerprint = tuple(sorted((f['off'], f['size']) for f in g.get('fields', [])))
    llm_fps[fingerprint] = name

# For each v21 cluster report, attach LLM name by matching fingerprint
out_dir = REPO / "harness_v21/field_map"
for xref_file in out_dir.glob("*_cluster_xref.json"):
    d = json.load(open(xref_file))
    img = d['img']
    for cid, c in d['clusters'].items():
        # Get fingerprint from primary_arg + field_touches
        fps = []
        for fid, f in c['field_touches'].items():
            fps.append((f['offset'], f['size']))
        fp = tuple(sorted(fps))
        if fp in llm_fps:
            c['llm_name'] = llm_fps[fp]
        else:
            c['llm_name'] = None
    # Save back
    xref_file.write_text(json.dumps(d, indent=2))
    named = sum(1 for c in d['clusters'].values() if c.get('llm_name'))
    print(f"{img}: {named}/{len(d['clusters'])} clusters got LLM names")

# Also build a cross-binary summary
summary = []
for xref_file in sorted(out_dir.glob("*_cluster_xref.json")):
    d = json.load(open(xref_file))
    for cid, c in d['clusters'].items():
        if c.get('llm_name'):
            summary.append({
                'img': d['img'],
                'cluster_id': cid,
                'llm_name': c['llm_name'],
                'primary_arg': c['primary_arg'],
                'n_funcs': c['n_funcs_total'],
                'top_funcs': c['funcs_named'][:3],
            })

out = REPO / "harness_v21/SUMMARY.json"
out.write_text(json.dumps({
    'total_clusters': len(summary),
    'by_struct': {}
}, indent=2))

# Group by LLM name
by_name = defaultdict(list)
for s in summary:
    by_name[s['llm_name']].append(s)
out_data = {
    'total_named_clusters': len(summary),
    'unique_structs': len(by_name),
    'by_struct': {n: {'instances': len(v), 'total_funcs': sum(x['n_funcs'] for x in v), 'all_images': list(set(x['img'] for x in v))} for n, v in by_name.items()},
    'all_clusters': summary,
}
out.write_text(json.dumps(out_data, indent=2))
print(f"\nSummary saved: {out}")
print(f"  {len(by_name)} unique named structs, {len(summary)} cluster instances")
for n, v in sorted(by_name.items(), key=lambda x: -sum(x[1][0].get('n_funcs', 0) for _ in [0]) and -len(x[1])):
    print(f"  {n}: {len(v)} instances, {sum(x['n_funcs'] for x in v)} total funcs")
