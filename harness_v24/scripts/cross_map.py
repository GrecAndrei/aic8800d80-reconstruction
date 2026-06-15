#!/usr/bin/env python3
"""v24: build a cross-binary function map and identify role distribution.

Approach:
1. Compute robust signature for each function (hashed normalized body)
2. Group by signature
3. Categorize each group:
   - all_3_fmacfw: in fmacfw_h, fmacfw_u02, fmacfwbt
   - wifi_h_only: in fmacfw_h only (not u02 or bt)
   - wifi_patch: in fmacfw_h + fmacfw_u02, not bt
   - bt_only: in fmacfwbt only
   - lmacfw_rf: in lmacfw_rf
   - etc.
4. Output a per-function cross-binary map
"""
import json, re, hashlib
from pathlib import Path
from collections import defaultdict, Counter

REPO = Path(__file__).resolve().parent.parent.parent
DEC_DIR = REPO / "harness_v19/decompiled"
OUT_DIR = REPO / "harness_v24"
OUT_DIR.mkdir(exist_ok=True)


def hash_func(body):
    """Robust hash: strip addresses, sub_XXXX, line numbers, types."""
    code = re.sub(r'//.*', '', body)
    code = re.sub(r'/\*.*?\*/', '', code, flags=re.DOTALL)
    code = re.sub(r'0x[0-9a-fA-F]+', '0xX', code)
    code = re.sub(r'sub_[0-9a-fA-F]+', 'sub_X', code)
    code = re.sub(r'\b\d+(\.\d+)?[fFlLuU]*\b', 'N', code)
    code = re.sub(r'\s+', ' ', code).strip()
    return hashlib.sha1(code.encode('utf-8', errors='ignore')).hexdigest()[:12]


def main():
    images = sorted(p.name for p in DEC_DIR.iterdir() if p.is_dir())
    
    # Step 1: compute sigs
    all_data = {}
    for img in images:
        img_dir = DEC_DIR / img
        d = {}
        for f in img_dir.glob("*.c"):
            m = re.match(r'^([0-9a-f]+)_(.+?)\.c$', f.name)
            if not m: continue
            addr = int(m.group(1), 16)
            body = f.read_text()
            d[addr] = {
                'name': m.group(2),
                'hash': hash_func(body),
                'n_lines': body.count('\n'),
            }
        all_data[img] = d
        print(f"{img}: {len(d)} funcs")
    
    # Step 2: group by hash
    hash_to_funcs = defaultdict(list)
    for img, funcs in all_data.items():
        for addr, sig in funcs.items():
            hash_to_funcs[sig['hash']].append((img, addr, sig))
    
    # Step 3: categorize each group
    group_meta = {}
    for h, funcs in hash_to_funcs.items():
        imgs = sorted(set(f[0] for f in funcs))
        # Categorize
        has_h = 'fmacfw_8800d80_h_u02_bin' in imgs
        has_u = 'fmacfw_8800d80_u02_bin' in imgs
        has_bt = 'fmacfwbt_8800d80_u02_bin' in imgs
        has_lmac = 'lmacfw_rf_8800d80_u02_bin' in imgs
        fmacfw_count = sum([has_h, has_u, has_bt])
        
        if fmacfw_count == 3:
            role = 'all_fmacfw'
        elif has_h and has_u and not has_bt:
            role = 'wifi_no_bt'
        elif has_u and has_bt and not has_h:
            role = 'u02_plus_bt'
        elif has_h and has_bt and not has_u:
            role = 'h_plus_bt'
        elif has_h and not has_u and not has_bt:
            role = 'h_only'
        elif has_u and not has_h and not has_bt:
            role = 'u02_only'
        elif has_bt and not has_h and not has_u:
            role = 'bt_only'
        elif has_lmac and fmacfw_count == 0:
            role = 'lmac_only'
        elif has_lmac and fmacfw_count > 0:
            role = 'lmac_plus_fmacfw'
        else:
            role = 'unknown'
        group_meta[h] = {
            'role': role,
            'imgs': imgs,
            'fmacfw_count': fmacfw_count,
            'n_funcs': len(funcs),
            'sample_name': funcs[0][2]['name'],
        }
    
    # Step 4: build per-function map
    func_map = {}
    for img, funcs in all_data.items():
        for addr, sig in funcs.items():
            key = f"{img}_{hex(addr)}"
            meta = group_meta[sig['hash']]
            others = [(i, hex(a)) for (i, a, _) in hash_to_funcs[sig['hash']] if i != img or a != addr]
            func_map[key] = {
                'img': img,
                'addr': hex(addr),
                'name': sig['name'],
                'n_lines': sig['n_lines'],
                'hash': sig['hash'],
                'role': meta['role'],
                'cross_in': sorted(set(i for (i, _) in others)),
                'cross_addrs': dict((i, sorted(set(a for (ii, a) in others if ii == i))) for i in set(i for (i, _) in others)),
            }
    
    # Save
    (OUT_DIR / "cross_map.json").write_text(json.dumps(func_map, indent=2))
    
    # Stats
    role_stats = Counter(v['role'] for v in func_map.values())
    print(f"\nRole distribution:")
    for r, c in role_stats.most_common():
        print(f"  {r}: {c}")
    
    # Cross-binary map (just the unique hashes)
    (OUT_DIR / "group_meta.json").write_text(json.dumps(group_meta, indent=2))
    
    # Summary
    summary = {
        'images': images,
        'total_funcs': sum(len(d) for d in all_data.values()),
        'unique_hashes': len(hash_to_funcs),
        'role_distribution': dict(role_stats),
    }
    (OUT_DIR / "SUMMARY.json").write_text(json.dumps(summary, indent=2))
    print(f"\nSummary: {summary}")


if __name__ == "__main__":
    main()
