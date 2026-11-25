#!/usr/bin/env python3
"""Generate luna_batch manifests for corpus-wide function analysis.

Each job carries module context (the segment the function sits in, its
neighbor names, the dominant subsystem prefixes) plus the composed body, so
the model names/analyzes with subsystem awareness instead of in isolation —
the qualitative upgrade over the harness_v17 naming pass.

Output schema requested from the model (parsed downstream):
  {"name": ..., "confidence": "high|medium|low", "docstring": ...,
   "subsystem": ..., "var_renames": {"v1": "...", ...},
   "struct_hints": [{"offset": N, "meaning": "..."}]}
"""
import json
import re
import sys
import argparse

INSTR = (
    "You are a firmware reverse-engineering expert analyzing RivieraWaves-derived "
    "WiFi/BT firmware (AIC8800D80, ARM Thumb, Marvell heritage). You will receive a "
    "decompiled function with its module context. Reply with ONLY a JSON object, no "
    "markdown fences: {\"name\": concise idiomatic C name, \"confidence\": "
    "\"high\"|\"medium\"|\"low\", \"docstring\": one precise sentence, "
    "\"subsystem\": e.g. mac|phy|rf|bt|ipc|mm|ke|hal|libmisc, "
    "\"var_renames\": {\"v1\": \"meaningful_name\", ...} only for variables whose "
    "role is clear, \"struct_hints\": [{\"offset\": int, \"meaning\": \"...\"}] for "
    "struct fields accessed at numeric offsets. Be conservative: omit unsure keys."
)


def extract_functions(text):
    funcs = []
    for m in re.finditer(r"(?m)^// (\S+) @ 0x([0-9a-f]+)\n", text):
        funcs.append((m.group(1), int(m.group(2), 16), m.start()))
    funcs.sort(key=lambda x: x[1])
    out = []
    for i, (name, addr, pos) in enumerate(funcs):
        end = funcs[i + 1][2] if i + 1 < len(funcs) else len(text)
        out.append({"name": name, "addr": addr, "body": text[pos:end].strip()})
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--images", default="fmacfw_h_u02")
    ap.add_argument("--out", default="/tmp/luna_analysis_manifest.jsonl")
    ap.add_argument("--max-body", type=int, default=3000)
    args = ap.parse_args()

    segments = json.load(open("metadata/module_segments.json"))
    jobs = []
    for img in args.images.split(","):
        text = open(f"src/{img}/main.c").read()
        funcs = extract_functions(text)
        segs = segments.get(img, {}).get("segments", [])
        # map address -> segment index
        def seg_for(addr):
            for si, s in enumerate(segs):
                if int(s["start"], 16) <= addr <= int(s["end"], 16):
                    return si, s
            return None, None
        for f in funcs:
            si, seg = seg_for(f["addr"])
            neighbors = []
            prefs = {}
            if seg:
                idx = seg["names"].index(f["name"]) if f["name"] in seg["names"] else 0
                neighbors = [n for n in seg["names"][max(0, idx - 3):idx + 4] if n != f["name"]][:6]
                prefs = seg.get("prefixes", {})
            body = f["body"]
            if len(body) > args.max_body:
                body = body[:args.max_body] + "\n// [truncated]"
            prompt = (
                f"Module context: this function sits in a link-order cluster with neighbors "
                f"{', '.join(neighbors) if neighbors else '(none)'}; dominant subsystem "
                f"prefixes in the cluster: {json.dumps(prefs)}.\n"
                f"Current machine-generated name: {f['name']} @ 0x{f['addr']:x}\n\n"
                f"```c\n{body}\n```"
            )
            jobs.append({
                "key": f"{f['name']}__{img}",
                "instructions": INSTR,
                "prompt": prompt,
                "meta": {"fn": f["name"], "img": img, "addr": hex(f["addr"]), "seg": si},
            })
    with open(args.out, "w") as fh:
        for j in jobs:
            fh.write(json.dumps(j) + "\n")
    print(f"wrote {len(jobs)} jobs to {args.out}")


if __name__ == "__main__":
    main()
