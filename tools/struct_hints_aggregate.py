#!/usr/bin/env python3
"""Aggregate the batch's struct_hints into a corpus-wide evidence dataset.

Each luna analysis can carry struct_hints: [{offset, meaning}] describing
fields accessed at numeric offsets in the owning function. Individually they
are local observations; aggregated corpus-wide they are the human-grade
complement to the machine-verified stride evidence (the 1320-byte structs):
offsets that many independent functions describe consistently are real
fields; the meanings converge on the true field semantics.

Output: metadata/struct_hints_aggregate.json
  by_offset:    {offset: {meaning: count}} — corpus-wide field consensus
  by_function:  {img/fn: [{offset, meaning}]} — per-function raw evidence
  hot_offsets:  offsets described by 3+ independent functions (strongest)

This is an evidence dataset only — nothing is applied to src/. Type
synthesis consumes it later alongside the machine stride data.
"""
import collections
import glob
import json


def main():
    by_offset = collections.defaultdict(collections.Counter)
    by_function = {}
    nfiles = 0
    nhints = 0
    for f in glob.glob("metadata/luna_analysis/*.json"):
        try:
            o = json.load(open(f))
            d = json.loads(o["text"])
        except Exception:
            continue
        nfiles += 1
        hints = d.get("struct_hints") or []
        if not hints:
            continue
        key = f"{o['img']}/{o['fn']}"
        valid = []
        for h in hints:
            try:
                off = int(h.get("offset", -1))
                meaning = str(h.get("meaning", "")).strip()[:80]
            except Exception:
                continue
            if off < 0 or off > 8192 or not meaning:
                continue
            valid.append({"offset": off, "meaning": meaning})
            by_offset[off][meaning] += 1
            nhints += 1
        if valid:
            by_function[key] = valid
    hot = {
        str(off): dict(c.most_common(5))
        for off, c in sorted(by_offset.items())
        if sum(c.values()) >= 3
    }
    out = {
        "functions_with_hints": len(by_function),
        "total_hints": nhints,
        "hot_offsets": hot,
        "by_function": by_function,
    }
    json.dump(out, open("metadata/struct_hints_aggregate.json", "w"), indent=1)
    print(f"{nfiles} analyses scanned: {len(by_function)} functions with hints, {nhints} total hints")
    print(f"hot offsets (3+ independent observers): {len(hot)}")
    for off in sorted(hot, key=int)[:10]:
        top = max(hot[off].items(), key=lambda kv: kv[1])
        print(f"  +{off}: {top[0]!r} x{top[1]}")


if __name__ == "__main__":
    main()
