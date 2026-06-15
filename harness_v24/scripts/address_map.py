#!/usr/bin/env python3
"""v24 v2: build a per-function cross-binary map with address as primary key.

Since fmacfw variants share ROM addresses, we use addr+name as primary key.
Different hashes at same addr = "variant" (code differs slightly)
"""
import json, re, hashlib
from pathlib import Path
from collections import defaultdict, Counter

REPO = Path(__file__).resolve().parent.parent.parent
DEC_DIR = REPO / "harness_v19/decompiled"
OUT_DIR = REPO / "harness_v24"
OUT_DIR.mkdir(exist_ok=True)


def hash_func(body):
    code = re.sub(r'//.*', '', body)
    code = re.sub(r'/\*.*?\*/', '', code, flags=re.DOTALL)
    code = re.sub(r'0x[0-9a-fA-F]+', '0xX', code)
    code = re.sub(r'sub_[0-9a-fA-F]+', 'sub_X', code)
    code = re.sub(r'\b\d+(\.\d+)?[fFlLuU]*\b', 'N', code)
    code = re.sub(r'\s+', ' ', code).strip()
    return hashlib.sha1(code.encode('utf-8', errors='ignore')).hexdigest()[:12]


def main():
    images = sorted(p.name for p in DEC_DIR.iterdir() if p.is_dir())
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
                'first_line': body.split('\n')[0] if body else '',
            }
        all_data[img] = d
    
    # Per-address: which images have a func at this addr
    addr_to_imgs = defaultdict(list)
    for img, funcs in all_data.items():
        for addr in funcs:
            addr_to_imgs[addr].append(img)
    
    # Same addr, different hashes = variants
    same_addr_different = 0
    same_addr_same = 0
    same_addr_count = Counter()
    for addr, imgs in addr_to_imgs.items():
        hashes = set()
        for img in imgs:
            hashes.add(all_data[img][addr]['hash'])
        if len(hashes) > 1:
            same_addr_different += 1
        else:
            same_addr_same += 1
        same_addr_count[len(imgs)] += 1
    print(f"Same addr, same hash: {same_addr_same}")
    print(f"Same addr, different hash: {same_addr_different}")
    print(f"Addr coverage: {dict(same_addr_count)}")
    
    # Build per-function cross-map using addr as primary key
    func_map = {}
    for img, funcs in all_data.items():
        for addr, sig in funcs.items():
            key = f"{img}_{hex(addr)}"
            imgs_at_addr = sorted(addr_to_imgs[addr])
            others = []
            hashes_seen = set()
            for oimg in imgs_at_addr:
                if oimg == img: continue
                oaddr = addr
                osig = all_data[oimg][oaddr]
                others.append({
                    'img': oimg,
                    'addr': hex(oaddr),
                    'hash': osig['hash'],
                    'same_hash': osig['hash'] == sig['hash'],
                    'name': osig['name'],
                    'n_lines': osig['n_lines'],
                })
            func_map[key] = {
                'img': img,
                'addr': hex(addr),
                'name': sig['name'],
                'n_lines': sig['n_lines'],
                'hash': sig['hash'],
                'imgs_at_addr': imgs_at_addr,
                'n_imgs_at_addr': len(imgs_at_addr),
                'is_unique_to_img': len(imgs_at_addr) == 1,
                'variants': others,
            }
    
    (OUT_DIR / "cross_map.json").write_text(json.dumps(func_map, indent=2))
    
    # Stats: how many funcs are at shared addresses
    shared = sum(1 for v in func_map.values() if v['n_imgs_at_addr'] > 1)
    unique = sum(1 for v in func_map.values() if v['n_imgs_at_addr'] == 1)
    print(f"\nBy address:")
    print(f"  Shared (in 2+ imgs): {shared}")
    print(f"  Unique: {unique}")
    
    # How many of the shared are "identical" vs "variant"
    identical = sum(1 for v in func_map.values() if v['n_imgs_at_addr'] > 1 and v['variants'] and all(va['same_hash'] for va in v['variants']))
    print(f"  Shared with same hash: {identical}")
    print(f"  Shared with diff hash: {shared - identical}")
    
    # Find funcs unique to one image
    unique_to = defaultdict(int)
    for v in func_map.values():
        if v['n_imgs_at_addr'] == 1:
            unique_to[v['img']] += 1
    print(f"\nUnique to each image: {dict(unique_to)}")
    
    # Find common-shared (in all 3 fmacfw)
    all_3 = sum(1 for v in func_map.values() if 'fmacfw_8800d80_h_u02_bin' in v['imgs_at_addr'] and 'fmacfw_8800d80_u02_bin' in v['imgs_at_addr'] and 'fmacfwbt_8800d80_u02_bin' in v['imgs_at_addr'])
    print(f"\nIn all 3 fmacfw: {all_3}")
    
    summary = {
        'images': images,
        'total_funcs': len(func_map),
        'shared_addrs': shared,
        'unique_addrs': unique,
        'identical_hash': identical,
        'variant_hash': shared - identical,
        'in_all_3_fmacfw': all_3,
        'unique_to': dict(unique_to),
    }
    (OUT_DIR / "SUMMARY.json").write_text(json.dumps(summary, indent=2))
    print(f"\nSummary: {summary}")


if __name__ == "__main__":
    main()
