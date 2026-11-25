#!/usr/bin/env python3
"""Refine coarse link-order segments into file-grade modules using call-graph
edge-crossing sparsity.

Model: translation units are contiguous in link order, so a file partition is
a segmentation of the address-ordered function sequence. At a true file
boundary very few call edges cross (static functions never do; cross-file
calls are sparse exports). Combined with the embedded __LINE__ reset evidence
from module_segments.py, this subdivides the 69 coarse segments into
file-grade modules without any supervision.

Usage: python3 tools/module_refine.py [--image fmacfw_h_u02]
"""
import argparse
import collections
import json
import re

IMAGES = {
    "fmacfw_h_u02": "fmacfw_8800d80_h_u02.bin",
    "fmacfw_u02": "fmacfw_8800d80_u02.bin",
    "fmacfwbt_u02": "fmacfwbt_8800d80_u02.bin",
    "lmacfw_rf_u02": "lmacfw_rf_8800d80_u02.bin",
}


def load_edges(img):
    path = f"extraction_out/ida_export_live/{IMAGES[img]}.call_edges.jsonl"
    edges = []
    for line in open(path):
        try:
            d = json.loads(line)
            edges.append((int(d["source_addr"], 16), int(d["target_addr"], 16)))
        except Exception:
            continue
    return edges


def extract_records(img):
    """Address-ordered function list with line constants, same extraction as
    module_segments.py."""
    text = open(f"src/{img}/main.c").read()
    funcs = []
    for m in re.finditer(r"(?m)^// (\S+) @ 0x([0-9a-f]+)\n", text):
        funcs.append((m.group(1), int(m.group(2), 16), m.start()))
    funcs.sort(key=lambda x: x[1])
    records = []
    for i, (name, addr, pos) in enumerate(funcs):
        end = funcs[i + 1][2] if i + 1 < len(funcs) else len(text)
        body = text[pos:end]
        lns = sorted({
            int(cm.group(1))
            for cm in re.finditer(
                r"\w+\((?:[^()]|\([^()]*\))*,\s*(?:[^()]|\([^()]*\))*,\s*(\d{2,4})\)",
                body)
            if 10 <= int(cm.group(1)) <= 9999
        })
        records.append({"name": name, "addr": addr, "lns": lns})
    return records


def crossing_counts(addrs, edges):
    """For each gap between consecutive addresses, count edges crossing it."""
    idx = {a: i for i, a in enumerate(addrs)}
    counts = [0] * (len(addrs) - 1)
    for s, t in edges:
        si, ti = idx.get(s), idx.get(t)
        if si is None or ti is None or si == ti:
            continue
        lo, hi = sorted((si, ti))
        for g in range(lo, hi):
            counts[g] += 1
    return counts


def split_segment(seg, counts, gaps, min_size=3, max_size=45):
    """Recursively split at the sparsest gaps while pieces stay plausible."""
    if len(seg) <= max_size:
        return [seg]
    lo, hi = gaps
    # candidate gaps strictly inside the segment, respecting min_size
    best, bestpos = None, None
    for pos in range(min_size, len(seg) - min_size + 1):
        # cutting after `pos` elements splits between within-segment indices
        # pos-1 and pos — the global gap index is lo+pos-1
        gpos = lo + pos - 1
        c = counts[gpos]
        if best is None or c < best:
            best, bestpos = c, pos
    if bestpos is None:
        return [seg]
    left = split_segment(seg[:bestpos], counts, (lo, lo + bestpos), min_size, max_size)
    right = split_segment(seg[bestpos:], counts, (lo + bestpos, hi), min_size, max_size)
    return left + right


def coarse_segments(records, reset_drop=200):
    """The module_segments.py coarse pass, reproduced for a single input flow."""
    segs = []
    cur = [records[0]]
    curmax = max(records[0]["lns"], default=0)
    for r in records[1:]:
        m = max(r["lns"], default=0)
        if r["lns"] and curmax > 0 and m and m < curmax - reset_drop:
            segs.append(cur)
            cur = [r]
            curmax = m
        else:
            cur.append(r)
            if m:
                curmax = max(curmax, m)
    segs.append(cur)
    return segs


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--image", default=None)
    ap.add_argument("--out", default="metadata/module_refined.json")
    ap.add_argument("--max-size", type=int, default=45)
    args = ap.parse_args()

    result = {}
    images = [args.image] if args.image else list(IMAGES)
    for img in images:
        records = extract_records(img)
        addrs = [r["addr"] for r in records]
        edges = load_edges(img)
        counts = crossing_counts(addrs, edges)
        coarse = coarse_segments(records)
        refined = []
        cursor = 0
        for seg in coarse:
            n = len(seg)
            pieces = split_segment(seg, counts, (cursor, cursor + n - 1), max_size=args.max_size)
            refined.extend(pieces)
            cursor += n
        result[img] = {
            "functions": len(records),
            "coarse": len(coarse),
            "refined_count": len(refined),
            "modules": [
                {
                    "start": hex(s[0]["addr"]),
                    "end": hex(s[-1]["addr"]),
                    "size": len(s),
                    "names": [r["name"] for r in s],
                }
                for s in refined
            ],
        }
        sizes = sorted(len(s) for s in refined)
        print(f"{img}: {len(coarse)} coarse -> {len(refined)} refined modules; "
              f"size median {sizes[len(sizes)//2]}, max {sizes[-1]}")
    json.dump(result, open(args.out, "w"), indent=1)
    print(f"wrote {args.out}")


if __name__ == "__main__":
    main()
