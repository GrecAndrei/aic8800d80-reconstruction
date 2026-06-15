#!/usr/bin/env python3
"""v23 Part 2: build per-field invariants.

For each named struct, for each field:
- total_reads / total_writes
- first-writer function (the init function)
- last-reader function (the cleanup/exit function)
- read-before-write ratio (high = probably init field)
- write-before-read ratio (high = probably always set)
- common reader functions
- common writer functions
"""
import json
import re
from pathlib import Path
from collections import defaultdict, Counter

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
    v20_pat = REPO / "harness_v20/access_patterns"
    v22_xref = REPO / "harness_v22/field_map"
    v22_structs = json.load(open(REPO / "harness_v22/structs/aic8800d80_v22_structs.json"))
    
    # For each named struct, build field invariants
    invariants = {}
    for sname, fields in v22_structs.items():
        if sname in ('vif_info', 'tx_queue', 'rx_desc', 'tx_desc', 'ke_env', 'scan_req'):
            continue  # v19 known structs - skip (no v22 xref)
        # Find all clusters with this struct name
        s_invariants = {}
        for xref_file in v22_xref.glob("*_cluster_xref.json"):
            xref = json.load(open(xref_file))
            img = xref['img']
            # Find clusters with this struct
            for cid, c in xref['clusters'].items():
                if c.get('name') != sname:
                    continue
                # Build field stats for this cluster
                # Re-run the field analysis to get all readers/writers
                img_dir = v19_dec / img
                if not img_dir.exists(): continue
                names = get_llm_names(img_dir)
                pat_data = json.load(open(REPO / "harness_v20/access_patterns" / f"{img}_patterns.json"))
                # Get cluster fingerprint
                # Get from v20 clusters
                v20_clu = json.load(open(REPO / "harness_v20/structs" / f"{img}_clusters.json"))
                cluster_data = v20_clu['significant_groups'][c['group_id']]
                fp = cluster_data['fingerprint']
                primary_arg = cluster_data['primary_arg']
                # For each func matching fp, collect field accesses
                field_stats = defaultdict(lambda: {"reads": [], "writes": []})
                for func in pat_data['funcs']:
                    if func['func_addr'] not in c.get('all_funcs', []):
                        # Check fingerprint match
                        acc_set = set()
                        for acc in func['accesses']:
                            if acc['base'] == primary_arg:
                                acc_set.add((acc['offset'], acc['size']))
                        if frozenset(acc_set) != frozenset(tuple(p) for p in fp):
                            continue
                    fname = names.get(func['func_addr'], f"sub_{func['func_addr']:x}")
                    for acc in func['accesses']:
                        if acc['base'] != primary_arg:
                            continue
                        if [acc['offset'], acc['size']] not in fp:
                            continue
                        direction = 'reads' if acc['direction'] == 'load' else 'writes'
                        field_stats[(acc['offset'], acc['size'])][direction].append(fname)
                # Build field info
                for (off, size), stats in field_stats.items():
                    fname_in_struct = next((n for n, o in fields.items() if o == off), f"off_{off:04x}")
                    if not stats['reads'] and not stats['writes']:
                        continue
                    s_invariants.setdefault(fname_in_struct, {
                        'offset': off, 'size': size,
                        'read_count': 0, 'write_count': 0,
                        'common_readers': [], 'common_writers': [],
                        'per_binary': {},
                    })
                    s_invariants[fname_in_struct]['read_count'] += len(stats['reads'])
                    s_invariants[fname_in_struct]['write_count'] += len(stats['writes'])
                    s_invariants[fname_in_struct]['per_binary'][img] = {
                        'read_count': len(stats['reads']),
                        'write_count': len(stats['writes']),
                        'readers': Counter(stats['reads']).most_common(5),
                        'writers': Counter(stats['writes']).most_common(5),
                    }
        if s_invariants:
            # Aggregate common readers/writers
            for fname, info in s_invariants.items():
                all_readers = Counter()
                all_writers = Counter()
                for img, data in info['per_binary'].items():
                    for r, c in data['readers']:
                        all_readers[r] += c
                    for w, c in data['writers']:
                        all_writers[w] += c
                info['common_readers'] = all_readers.most_common(10)
                info['common_writers'] = all_writers.most_common(10)
            invariants[sname] = s_invariants
    
    out = REPO / "harness_v23/FIELD_INVARIANTS.json"
    out.write_text(json.dumps(invariants, indent=2))
    print(f"Saved: {out}")
    print(f"  {len(invariants)} structs with invariants")
    for sname, fields in invariants.items():
        print(f"  {sname}: {len(fields)} fields")
        # Show top field
        if fields:
            top = max(fields.values(), key=lambda f: f['read_count'] + f['write_count'])
            print(f"    top: {top['read_count']}R/{top['write_count']}W")


if __name__ == "__main__":
    main()
