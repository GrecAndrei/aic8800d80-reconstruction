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


def dp_segment(counts, records, gap_range, target=18, min_size=4, max_size=48):
    """Optimal ordered segmentation by dynamic programming.

    Cost model per candidate file [i, j):
      - boundary cost: call edges crossing the gap at j (sparse gaps are
        cheap — real file boundaries), normalized to per-edge units
      - size penalty: quadratic deviation from the target file size —
        discourages both the size-3 noise fragmentation of greedy recursion
        and implausibly large monolith files
      - line-reset bonus: an embedded __LINE__ monotonicity reset at the
        boundary is strong independent evidence (negative cost)
    gap_range restricts boundaries to the coarse segment's interior, keeping
    the high-confidence coarse breaks exact.
    """
    lo, hi = gap_range  # function index span [lo, hi)
    n = hi - lo
    if n <= max_size:
        return [records[lo:hi]]

    INF = float("inf")
    # dp[k] = min cost to segment records[lo:lo+k]; choice[k] = last cut size
    dp = [INF] * (n + 1)
    choice = [0] * (n + 1)
    dp[0] = 0.0
    # line-reset evidence per global function index
    def has_reset(idx):
        if idx <= lo:
            return False
        prev_max = 0
        for r in records[lo:idx]:
            m = max(r["lns"], default=0)
            if m:
                prev_max = max(prev_max, m)
        m = max(records[idx]["lns"], default=0) if records[idx]["lns"] else 0
        return bool(m) and prev_max > 0 and m < prev_max - 200

    def boundary_cost(gidx):
        # edges crossing gap gidx (gap BEFORE function gidx), scaled so one
        # crossing edge costs roughly one function's worth of size deviation
        if lo <= gidx - 1 < hi - 1:
            return counts[gidx - 1] * 0.35
        return 0.0

    for k in range(min_size, n + 1):
        for size in range(min_size, max_size + 1):
            if size > k:
                break
            if k - size != 0 and k - size < min_size:
                continue  # remainder would be infeasible
            start = lo + k - size
            endg = lo + k
            cost = dp[k - size]
            cost += (size - target) ** 2 * 0.02
            if k < n:  # boundary inside the segment — evaluate it
                cost += boundary_cost(endg)
                if has_reset(endg):
                    cost -= 4.0
            if cost < dp[k]:
                dp[k] = cost
                choice[k] = size
    if dp[n] == INF:
        return [records[lo:hi]]
    # walk back
    out = []
    k = n
    while k > 0:
        size = choice[k] or min(n, max_size)
        out.append(records[lo + k - size: lo + k])
        k -= size
    out.reverse()
    return out


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
            pieces = dp_segment(counts, records, (cursor, cursor + n))
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
