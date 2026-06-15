#!/usr/bin/env python3
"""v20 Step 2: group access patterns into struct candidates.

For each base register (r0-r3, sp), collect all (offset, size) pairs accessed.
These form a struct candidate: a set of fields.

We focus on:
- Function arguments (r0, r1, r2, r3): these are typically struct pointers
- Local frame accesses (sp-based)

Cross-function matching: if multiple functions access the same offset pattern
on the same register, they likely share the struct.
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
        # Group by (base register, direction)
        # struct fields are identified by stable (offset, size) tuples
        # accessed at the same base
        struct_candidates = defaultdict(Counter)  # base -> offset -> count
        access_count = 0
        for func in data['funcs']:
            for acc in func['accesses']:
                key = (acc['base'], acc['size'])
                struct_candidates[key][acc['offset']] += 1
                access_count += 1
        # Print summary
        print(f"{img}: {access_count} accesses")
        for (base, size), offsets in sorted(struct_candidates.items(), key=lambda x: -sum(x[1].values()))[:10]:
            top = offsets.most_common(5)
            print(f"  base={base:3s} size={size}: {sum(offsets.values()):4d} accesses, top: {[(f'#{o:04x}', c) for o, c in top]}")
        # Save candidates
        out = {
            'img': img,
            'access_count': access_count,
            'candidates': {
                f"{base}_s{size}": {
                    "base": base, "size": size,
                    "total": sum(offsets.values()),
                    "fields": [{"offset": o, "count": c} for o, c in offsets.most_common(50)]
                }
                for (base, size), offsets in struct_candidates.items()
                if sum(offsets.values()) >= 5  # at least 5 accesses
            }
        }
        out_path = out_dir / f"{img}_structs.json"
        with open(out_path, 'w') as f:
            json.dump(out, f, indent=2)
        print(f"  saved {len(out['candidates'])} struct candidates -> {out_path.name}")

if __name__ == "__main__":
    main()
