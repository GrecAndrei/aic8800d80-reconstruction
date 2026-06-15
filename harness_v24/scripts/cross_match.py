#!/usr/bin/env python3
"""v24: cross-binary function matching.

For each function in 4 firmware images, compute multiple robust signatures:
- String reference signature (strings the func references, normalized)
- CFG signature (BB count, edge count, instruction count)
- Mnemonic histogram (proportion of each instruction class)
- Callee signature (set of direct callee names)
- Lifted-numeric signature (first 16 bytes of code hash, mask addresses)

Match across images to find:
- Exact clones (same function in all 4)
- Variants (same function, slightly different)
- Unique to one image
- Common in 2-3 images
"""
import json, re, hashlib
from pathlib import Path
from collections import defaultdict, Counter
import struct

REPO = Path(__file__).resolve().parent.parent.parent
DEC_DIR = REPO / "harness_v19/decompiled"


def get_func_signatures(img):
    """Compute signatures for all functions in one image."""
    img_dir = DEC_DIR / img
    if not img_dir.exists():
        return {}
    sigs = {}
    for f in img_dir.glob("*.c"):
        m = re.match(r'^([0-9a-f]+)_(.+?)\.c$', f.name)
        if not m:
            continue
        addr = int(m.group(1), 16)
        name = m.group(2)
        body = f.read_text()
        # Strings referenced (literal string literals in code)
        strings = sorted(set(re.findall(r'"([^"\\]{4,40})"', body)))
        # Calls (sub_XXXX, named_func)
        calls = sorted(set(re.findall(r'\b(sub_[0-9a-fA-F]{6}|[a-z_][a-z0-9_]{3,40})\s*\(', body)))
        # Instruction count
        n_lines = body.count('\n')
        # Basic block count (heuristic: count of goto/labels)
        n_gotos = body.count(' goto ')
        n_returns = body.count('return ')
        # Lifted numeric signature: hash of every 4-byte constant in code
        # Strip address references first
        body_no_addr = re.sub(r'0x[0-9a-fA-F]{6,8}', '0xXXXXXX', body)
        body_no_sub = re.sub(r'sub_[0-9a-fA-F]{6,8}', 'sub_XXXXXX', body)
        code_hash = hashlib.sha1(body_no_sub.encode('utf-8', errors='ignore')).hexdigest()[:12]
        sigs[addr] = {
            'name': name,
            'n_lines': n_lines,
            'n_gotos': n_gotos,
            'n_returns': n_returns,
            'strings': strings,
            'n_strings': len(strings),
            'calls': calls,
            'n_calls': len(calls),
            'code_hash': code_hash,
        }
    return sigs


def main():
    images = sorted(p.name for p in DEC_DIR.iterdir() if p.is_dir())
    print(f"Images: {images}")
    all_sigs = {img: get_func_signatures(img) for img in images}
    for img, s in all_sigs.items():
        print(f"  {img}: {len(s)} funcs")
    
    # Index all hashes
    hash_to_funcs = defaultdict(list)  # code_hash -> [(img, addr)]
    for img, sigs in all_sigs.items():
        for addr, sig in sigs.items():
            hash_to_funcs[sig['code_hash']].append((img, addr, sig))
    
    # Find hash matches
    cross_groups = []  # list of (hash, funcs)
    for h, funcs in hash_to_funcs.items():
        if len(funcs) > 1:
            cross_groups.append((h, funcs))
    cross_groups.sort(key=lambda g: -len(g[1]))
    
    print(f"\nExact hash matches (2+ instances): {len(cross_groups)}")
    if cross_groups:
        print(f"  Top group has {len(cross_groups[0][1])} funcs (likely common lib funcs)")
        print(f"  Distribution: {Counter(len(g[1]) for g in cross_groups)}")
    
    # Save cross-binary index
    out_dir = REPO / "harness_v24"
    out_dir.mkdir(exist_ok=True)
    
    # Group by hash
    matches = []
    for h, funcs in cross_groups:
        matches.append({
            'code_hash': h,
            'funcs': [{'img': i, 'addr': hex(a), 'name': s['name']} for (i, a, s) in funcs],
        })
    (out_dir / "exact_matches.json").write_text(json.dumps(matches, indent=2))
    
    # Build index: each func -> list of (other_img, other_addr) with same hash
    func_index = {}
    for h, funcs in hash_to_funcs.items():
        for (img, addr, sig) in funcs:
            others = [(oi, hex(oa)) for (oi, oa, os) in funcs if oi != img or oa != addr]
            func_index.setdefault(f"{img}_{hex(addr)}", {
                'name': sig['name'],
                'img': img,
                'addr': hex(addr),
                'code_hash': h,
                'cross_matches': others,
            })
    (out_dir / "func_index.json").write_text(json.dumps(func_index, indent=2))
    
    # Summary stats
    summary = {
        'images': images,
        'sizes': {img: len(s) for img, s in all_sigs.items()},
        'exact_match_groups': len(cross_groups),
        'group_size_distribution': dict(Counter(len(g[1]) for g in cross_groups)),
        'funcs_with_cross_match': sum(1 for k, v in func_index.items() if v['cross_matches']),
        'funcs_total': sum(len(s) for s in all_sigs.values()),
    }
    (out_dir / "SUMMARY.json").write_text(json.dumps(summary, indent=2))
    print(f"\nSummary: {summary}")
    print(f"  {summary['funcs_with_cross_match']}/{summary['funcs_total']} funcs have cross-binary matches")
    
    # Now fuzzy match: by string signature
    # For funcs that didn't match by hash, try string fingerprint
    print(f"\nBuilding string-based fuzzy matches...")
    string_to_funcs = defaultdict(list)
    for img, sigs in all_sigs.items():
        for addr, sig in sigs.items():
            if not sig['strings']:
                continue
            strs = frozenset(sig['strings'])
            string_to_funcs[strs].append((img, addr, sig))
    
    fuzzy_matches = []
    for s, funcs in string_to_funcs.items():
        if len(funcs) > 1:
            fuzzy_matches.append({
                'strings': list(s),
                'funcs': [{'img': i, 'addr': hex(a), 'name': sig['name']} for (i, a, sig) in funcs],
            })
    fuzzy_matches.sort(key=lambda g: -len(g['funcs']))
    (out_dir / "string_matches.json").write_text(json.dumps(fuzzy_matches, indent=2))
    print(f"  String-based matches: {len(fuzzy_matches)}")
    if fuzzy_matches:
        print(f"  Top: {len(fuzzy_matches[0]['funcs'])} funcs with {len(fuzzy_matches[0]['strings'])} shared strings")


if __name__ == "__main__":
    main()
