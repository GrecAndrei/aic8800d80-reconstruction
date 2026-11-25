#!/usr/bin/env python3
"""Defect-shape census: IDA 9.3 vs 9.5 decompiler output comparison.

Quantifies what the migration buys per defect class, per function and total:
  - goto count (structuring failure noise — 9.5's switch reassembly and
    binary-search-tree recovery should collapse these)
  - JUMPOUT / undocumented Hex-Rays artifacts
  - switch statements present (recovered control flow)
  - cast density (spurious-cast noise)
  - line count (verbosity proxy)

Inputs: the 9.3-era baseline from extraction_out/ida_export_live/*.pseudo.jsonl
(or the composed module text) and the 9.5 outputs produced by
ida_decompile_v19.py run under the 9.5 install.

Usage: python3 tools/ida95_census.py --old-src src/fmacfw_h_u02/modules \
       --new-dir /tmp/ida95_test/decompiled [--limit 200]
"""
import argparse
import collections
import glob
import json
import os
import re


def metrics(text):
    return {
        "goto": len(re.findall(r"\bgoto\b", text)),
        "jumpout": len(re.findall(r"JUMPOUT", text)),
        "switch": len(re.findall(r"\bswitch\b", text)),
        "casts": len(re.findall(r"\([a-zA-Z_][\w ]*\*\)", text)),
        "lines": text.count("\n"),
        "labels": len(re.findall(r"^LABEL_\d+:", text, re.M)),
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--old-src", default="src/fmacfw_h_u02/modules")
    ap.add_argument("--new-dir", default="/tmp/ida95_test/decompiled")
    ap.add_argument("--limit", type=int, default=100000)
    args = ap.parse_args()

    old = collections.Counter()
    for f in sorted(glob.glob(os.path.join(args.old_src, "mod*.c"))):
        m = metrics(open(f).read())
        for k, v in m.items():
            old[k] += v

    new = collections.Counter()
    nfuncs = 0
    if os.path.isdir(args.new_dir):
        for f in sorted(glob.glob(os.path.join(args.new_dir, "**/*.c"), recursive=True))[: args.limit]:
            m = metrics(open(f, errors="replace").read())
            for k, v in m.items():
                new[k] += v
            nfuncs += 1

    print(f"9.3 baseline (all modules): {dict(old)}")
    print(f"9.5 census over {nfuncs} functions: {dict(new)}")
    if nfuncs and new["lines"]:
        scale = old["lines"] / max(new["lines"], 1)
        print("normalized per-line ratios (9.5/9.3, lower = less noise):")
        for k in ("goto", "jumpout", "labels"):
            if old[k]:
                print(f"  {k}: {new[k] / max(old[k], 1):.3f}")
        print(f"  switch recovery ratio (higher = better): {new['switch'] / max(old['switch'], 1):.2f}")


if __name__ == "__main__":
    main()
