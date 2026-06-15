#!/usr/bin/env python3
"""v20 Step 2.5: cluster functions by their primary struct fingerprint.

For each function, find the arg register (r0-r3) with the most diverse
accesses. Treat its (offset, size) set as a fingerprint.
Cluster functions with similar fingerprints together.

Output: harness_v20/structs/clusters.json
"""
import json, sys
from pathlib import Path
from collections import defaultdict, Counter

REPO = Path(__file__).resolve().parent.parent.parent

def main():
    pat_dir = REPO / "harness_v20/access_patterns"
    out_dir = REPO / "harness_v20/structs"
    out_dir.mkdir(parents=True, exist_ok=True)
    
    for f in pat_dir.glob("*_patterns.json"):
        img = f.stem.removesuffix("_patterns")
        data = json.load(open(f))
        # For each function, find primary struct (arg with most access diversity)
        func_structs = []
        for func in data['funcs']:
            arg_accs = defaultdict(list)
            for acc in func['accesses']:
                if acc['base'] in ('r0', 'r1', 'r2', 'r3', 'r4', 'r5', 'r6', 'r7', 'sp'):
                    arg_accs[acc['base']].append((acc['offset'], acc['size']))
            if not arg_accs:
                continue
            # Pick arg with most unique (offset, size) pairs
            best_arg = max(arg_accs, key=lambda a: len(set(arg_accs[a])))
            best_accs = arg_accs[best_arg]
            unique_pairs = sorted(set(best_accs))
            # Also include load-only / store-only info
            if len(unique_pairs) < 2:
                continue  # skip trivial
            func_structs.append({
                'func_addr': func['func_addr'],
                'func_name': func['func_name'],
                'primary_arg': best_arg,
                'fingerprint': [[o, s] for o, s in unique_pairs],
                'access_count': len(best_accs),
            })
        # Group by signature
        sig_groups = defaultdict(list)
        for fs in func_structs:
            # Use the (offset, size) tuple as signature
            sig = tuple(tuple(p) for p in fs['fingerprint'])
            sig_groups[sig].append(fs)
        # Sort by group size
        sorted_groups = sorted(sig_groups.items(), key=lambda x: -len(x[1]))
        # Filter to groups with >= 5 funcs (significant struct)
        significant = [(sig, funcs) for sig, funcs in sorted_groups if len(funcs) >= 5]
        print(f"\n{img}: {len(func_structs)} functions with primary arg, {len(significant)} significant struct groups")
        for i, (sig, funcs) in enumerate(significant[:15]):
            offsets = [(f"#{o:04x}", s) for o, s in sig[:8]]
            print(f"  Group {i}: {len(funcs)} funcs, arg={funcs[0]['primary_arg']}, fields={offsets}")
        # Save
        out = {
            'img': img,
            'total_funcs': len(func_structs),
            'total_groups': len(sorted_groups),
            'significant_groups': [
                {
                    'group_id': i,
                    'primary_arg': funcs[0]['primary_arg'],
                    'fingerprint': [[o, s] for o, s in sig],
                    'func_count': len(funcs),
                    'sample_funcs': funcs[:5],
                }
                for i, (sig, funcs) in enumerate(significant)
            ]
        }
        out_path = out_dir / f"{img}_clusters.json"
        with open(out_path, 'w') as f:
            json.dump(out, f, indent=2)
        print(f"  saved -> {out_path.name}")

if __name__ == "__main__":
    main()
