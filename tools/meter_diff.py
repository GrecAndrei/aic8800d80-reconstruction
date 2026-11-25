#!/usr/bin/env python3
"""Compare two fidelity-meter row sets: per-function status transitions.

Usage: python3 tools/meter_diff.py OLD_rows.jsonl NEW_rows.jsonl

Reports functions whose worst-vector outcome changed between runs, grouped by
transition class, so a repair's effect is measured per function rather than
only in aggregate.
"""
import json
import sys
from collections import Counter

RANK = {"MATCH": 0, "INVALID_INPUT": 1, "NOT_RUN": 1, "DIFFER": 2}

def load(path):
    rows = {}
    for line in open(path):
        r = json.loads(line)
        rows[(r["image"], r["address"])] = r
    return rows

def worst(row):
    """The worst status across vectors, DIFFER being worst."""
    statuses = [v["status"] for v in row.get("vectors", {}).values()]
    if "DIFFER" in statuses:
        return "DIFFER"
    if "MATCH" in statuses:
        return "MATCH"
    return "NOT_RUN"

def main():
    old = load(sys.argv[1])
    new = load(sys.argv[2])
    transitions = Counter()
    improved, regressed, changed = [], [], []
    for key in sorted(set(old) | set(new)):
        o, n = old.get(key), new.get(key)
        if not o or not n:
            continue
        wo, wn = worst(o), worst(n)
        if wo == wn:
            continue
        transitions[(wo, wn)] += 1
        entry = (key, wo, wn)
        if RANK[wn] < RANK[wo]:
            improved.append(entry)
        elif RANK[wn] > RANK[wo]:
            regressed.append(entry)
        else:
            changed.append(entry)
    print(f"improved: {len(improved)}  regressed: {len(regressed)}  lateral: {len(changed)}")
    print("transitions:", dict(transitions))
    if regressed:
        print("\nREGRESSED (first 15):")
        for key, wo, wn in regressed[:15]:
            print(f"  {key[0][:8]} {key[1]} {wo} -> {wn}")
    if improved:
        print("\nIMPROVED (first 15):")
        for key, wo, wn in improved[:15]:
            print(f"  {key[0][:8]} {key[1]} {wo} -> {wn}")
    return 0

if __name__ == "__main__":
    sys.exit(main())
