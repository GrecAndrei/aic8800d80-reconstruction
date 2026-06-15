#!/usr/bin/env python3
"""v24 v2: better cross-binary matching using string + callee + size fingerprint."""
import json, re, hashlib
from pathlib import Path
from collections import defaultdict, Counter

REPO = Path(__file__).resolve().parent.parent.parent
DEC_DIR = REPO / "harness_v19/decompiled"

# Callee names: strip sub_XXXXX and process named ones
CALL_RE = re.compile(r'\b(sub_[0-9a-fA-F]{6,8}|[a-z_][a-z0-9_]{3,40})\s*\(')
STR_RE = re.compile(r'"((?:[^"\\]|\\.){3,80})"')


def parse_func(path):
    body = path.read_text()
    # Strip comments
    code = re.sub(r'//.*', '', body)
    # Strings
    strings = tuple(sorted(set(STR_RE.findall(code))))
    # Callee names (named only, not sub_XXXXX)
    calls = tuple(sorted(set(m.group(1) for m in CALL_RE.finditer(code) if not m.group(1).startswith('sub_'))))
    # Size
    n_lines = body.count('\n')
    # Lifted hash (strip addresses, sub_XXXX, line nums, types)
    norm = re.sub(r'0x[0-9a-fA-F]+', '0xX', code)
    norm = re.sub(r'sub_[0-9a-fA-F]+', 'sub_X', norm)
    norm = re.sub(r'\b\d+(\.\d+)?[fFlLuU]*\b', 'N', norm)
    norm = re.sub(r'/\*.*?\*/', '', norm, flags=re.DOTALL)
    norm = re.sub(r'\s+', ' ', norm)
    return {
        'strings': strings,
        'calls': calls,
        'n_lines': n_lines,
        'hash': hashlib.sha1(norm.encode('utf-8', errors='ignore')).hexdigest()[:12],
    }


def main():
    images = sorted(p.name for p in DEC_DIR.iterdir() if p.is_dir())
    print(f"Images: {images}")
    
    # Build signature DB
    all_data = {}
    for img in images:
        img_dir = DEC_DIR / img
        d = {}
        for f in img_dir.glob("*.c"):
            m = re.match(r'^([0-9a-f]+)_(.+?)\.c$', f.name)
            if not m:
                continue
            addr = int(m.group(1), 16)
            d[addr] = {**parse_func(f), 'name': m.group(2)}
        all_data[img] = d
        print(f"  {img}: {len(d)} funcs")
    
    # 1. Exact hash matches
    hash_to_funcs = defaultdict(list)
    for img, funcs in all_data.items():
        for addr, sig in funcs.items():
            hash_to_funcs[sig['hash']].append((img, addr, sig))
    
    exact = [(h, fs) for h, fs in hash_to_funcs.items() if len(fs) > 1]
    exact.sort(key=lambda g: -len(g[1]))
    print(f"\nExact hash matches: {len(exact)} groups")
    for h, fs in exact[:5]:
        print(f"  {h}: {len(fs)} funcs - {fs[0][2]['name']}")
    
    # 2. String-based matching: build string -> funcs map, then expand
    string_to_funcs = defaultdict(list)
    for img, funcs in all_data.items():
        for addr, sig in funcs.items():
            for s in sig['strings']:
                string_to_funcs[s].append((img, addr, sig))
    
    # Count which strings are shared
    shared_strings = {s: fs for s, fs in string_to_funcs.items() if len(fs) > 1}
    print(f"\nStrings referenced in 2+ funcs: {len(shared_strings)}")
    
    # 3. Callee signature: for funcs that don't match by hash, match by (named_callees, size_bucket)
    print(f"\nCallee-based fuzzy matches...")
    callee_to_funcs = defaultdict(list)
    for img, funcs in all_data.items():
        for addr, sig in funcs.items():
            if not sig['calls']:
                continue
            # Use sorted callee tuple as key
            key = (sig['calls'], sig['n_lines'] // 5)  # bucket by line range
            callee_to_funcs[key].append((img, addr, sig))
    
    callee_matches = [(k, fs) for k, fs in callee_to_funcs.items() if len(fs) > 1]
    print(f"  Callee+size matches: {len(callee_matches)}")
    if callee_matches:
        # How many are in different images
        cross_img = sum(1 for k, fs in callee_matches if len(set(f[0] for f in fs)) > 1)
        print(f"  Cross-image: {cross_img}")
    
    # Save everything
    out_dir = REPO / "harness_v24"
    out_dir.mkdir(exist_ok=True)
    
    # Combined cross-binary map
    # Each func -> list of likely matches in other images
    out_map = {}
    for img, funcs in all_data.items():
        for addr, sig in funcs.items():
            key = f"{img}_{hex(addr)}"
            # Find matches in 3 ways
            hash_matches = [f for f in hash_to_funcs[sig['hash']] if f[0] != img or f[1] != addr]
            string_matches = []
            for s in sig['strings']:
                for f in string_to_funcs[s]:
                    if f[0] != img or f[1] != addr:
                        string_matches.append(f)
            string_matches = list({(i, a) for (i, a, _) in string_matches})
            out_map[key] = {
                'img': img,
                'addr': hex(addr),
                'name': sig['name'],
                'n_lines': sig['n_lines'],
                'n_strings': len(sig['strings']),
                'n_calls': len(sig['calls']),
                'hash_matches': [{'img': i, 'addr': hex(a)} for (i, a, _) in hash_matches],
                'string_match_count': len(string_matches),
                'string_match_imgs': sorted(set(i for (i, a) in string_matches)),
            }
    (out_dir / "cross_map.json").write_text(json.dumps(out_map, indent=2))
    
    # Summary
    summary = {
        'images': images,
        'sizes': {img: len(d) for img, d in all_data.items()},
        'exact_hash_groups': len(exact),
        'shared_strings': len(shared_strings),
        'callee_groups': len(callee_matches),
        'callee_cross_img': cross_img if callee_matches else 0,
    }
    (out_dir / "SUMMARY.json").write_text(json.dumps(summary, indent=2))
    print(f"\nSummary: {summary}")


if __name__ == "__main__":
    main()
