#!/usr/bin/env python3
"""v24 release: build navigable cross-binary function index."""
import json
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent.parent
OUT_DIR = REPO / "harness_v24"


def main():
    cross_map = json.load(open(OUT_DIR / "cross_map.json"))
    
    # Build reverse index: per-addr list of (img, name)
    by_addr = defaultdict(list)
    for k, v in cross_map.items():
        by_addr[v['addr']].append((v['img'], v['name'], v['hash']))
    
    # Per-image: list of funcs sorted by addr, with cross-refs
    out = {}
    for img in sorted(set(v['img'] for v in cross_map.values())):
        funcs_in_img = [(v['addr'], v) for k, v in cross_map.items() if v['img'] == img]
        funcs_in_img.sort()
        rows = []
        for addr, v in funcs_in_img:
            cross_refs = {}
            for variant in v['variants']:
                if variant['same_hash']:
                    cross_refs.setdefault('identical', []).append(f"{variant['img']}@{variant['addr']}={variant['name']}")
                else:
                    cross_refs.setdefault('variant', []).append(f"{variant['img']}@{variant['addr']}={variant['name']}({variant['n_lines']}L)")
            rows.append({
                'addr': addr,
                'name': v['name'],
                'n_lines': v['n_lines'],
                'cross_refs': cross_refs,
            })
        out[img] = rows
    
    # Save
    (OUT_DIR / "navigation.json").write_text(json.dumps(out, indent=2))
    
    # Print a sample
    sample_img = 'fmacfw_8800d80_h_u02_bin'
    funcs_with_xref = [r for r in out[sample_img] if r['cross_refs']]
    print(f"\n{sample_img}: {len(out[sample_img])} funcs, {len(funcs_with_xref)} with cross-refs")
    print(f"\nFirst 5 with cross-refs:")
    for r in funcs_with_xref[:5]:
        print(f"  {r['addr']} {r['name']}: {r['cross_refs']}")


if __name__ == "__main__":
    main()
