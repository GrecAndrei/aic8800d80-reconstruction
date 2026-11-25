#!/usr/bin/env python3
"""Module-boundary inference: reconstruct the original repo file structure
from link-order + embedded __LINE__ constant monotonicity.

Evidence model: the original firmware was compiled file-by-file; the linker
emitted objects in build order, so binary-adjacent functions are usually
same-file. Trace/assert macros bake __LINE__ constants into the binary
(e.g. irq_disable_mmio_write(x, y, 707)); within one translation unit these
increase monotonically in address order and reset at file boundaries.

Usage: python3 tools/module_segments.py [--image fmacfw_h_u02]
"""
import re, json, collections, sys, argparse

IMAGES = ("fmacfw_h_u02", "fmacfw_u02", "fmacfwbt_u02", "lmacfw_rf_u02")


def extract_records(text):
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
        pref = re.match(r"([a-z]+)_", name)
        records.append({
            "name": name, "addr": addr, "lns": lns,
            "pref": pref.group(1) if pref else "",
        })
    return records


def segment(records, reset_drop=200):
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
    ap.add_argument("--out", default=None)
    args = ap.parse_args()
    images = [args.image] if args.image else list(IMAGES)
    result = {}
    for img in images:
        records = extract_records(open(f"src/{img}/main.c").read())
        segs = segment(records)
        result[img] = {
            "functions": len(records),
            "segments": [
                {
                    "start": hex(s[0]["addr"]),
                    "end": hex(s[-1]["addr"]),
                    "size": len(s),
                    "names": [r["name"] for r in s],
                    "prefixes": dict(collections.Counter(
                        r["pref"] for r in s if r["pref"]).most_common(4)),
                }
                for s in segs
            ],
        }
        print(f"{img}: {len(segs)} segments from {len(records)} functions")
    out = args.out or "metadata/module_segments.json"
    json.dump(result, open(out, "w"), indent=1)
    print(f"wrote {out}")


if __name__ == "__main__":
    main()
