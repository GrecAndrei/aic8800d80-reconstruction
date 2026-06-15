#!/usr/bin/env python3
"""v20: annotate v19 decompiled C with struct field references.

For each MMIO write/read in the v19 decompiled code, leave as-is.
For each MEMORY[0xADDR] reference where ADDR looks like a struct base, leave as-is.
Future: we could parse the v19 decompiled C and replace dword_XX[off] with struct_name.field.

For now, this script just produces a manifest of v20 work done.
"""
import json
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent.parent

def main():
    # Aggregate v20 results across all 4 binaries
    summary = {
        'extraction': {},
        'struct_candidates': {},
        'clusters': {},
        'llm_proposals': {},
    }
    for f in (REPO / "harness_v20/access_patterns").glob("*_patterns.json"):
        d = json.load(open(f))
        summary['extraction'][d['img']] = {
            'funcs': len(d['funcs']),
            'total_accesses': sum(len(f['accesses']) for f in d['funcs']),
        }
    for f in (REPO / "harness_v20/structs").glob("*_structs.json"):
        d = json.load(open(f))
        summary['struct_candidates'][d.get('img', f.stem)] = {
            'candidates': len(d.get('candidates', {})),
            'accesses': d.get('access_count', 0),
        }
    for f in (REPO / "harness_v20/structs").glob("*_clusters.json"):
        d = json.load(open(f))
        summary['clusters'][d['img']] = {
            'total_funcs': d['total_funcs'],
            'total_groups': d['total_groups'],
            'significant_groups': len(d['significant_groups']),
        }
    # LLM proposals
    p = REPO / "harness_v20/structs/proposals_v4.json"
    if p.exists():
        d = json.load(open(p))
        summary['llm_proposals'] = {
            'n_proposed': len(d.get('parsed', {}).get('groups', [])) if d.get('parsed') else 0,
            'struct_names': [g['name'] for g in d.get('parsed', {}).get('groups', [])] if d.get('parsed') else [],
        }
    
    out_path = REPO / "harness_v20/structs/SUMMARY.json"
    out_path.write_text(json.dumps(summary, indent=2))
    print(f"Saved summary: {out_path}")
    print(json.dumps(summary, indent=2))

if __name__ == "__main__":
    main()
