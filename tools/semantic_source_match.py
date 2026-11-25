#!/usr/bin/env python3
"""Semantic source matching via the Decisions API — the version-robust
replacement for instruction fingerprinting.

Instruction fingerprints die to compiler-version skew (measured: zero hits
even at 0.5 mnemonic cosine across all 35 compiled RW functions). Logic
survives: the model reads decompiled C semantics, not instruction
histograms. This tool batches predicate decisions — "does this decompiled
firmware function implement the same logic as this RW source function?" —
over candidate pairs, pre-filtered by rough size so the pairing cost stays
small.

Candidate pre-filter: firmware functions whose composed body line count is
within 0.4x-2.5x of the source function's line count AND whose LLM-assigned
name shares a token with the source function name or the ke/mm/ipc vocabulary.

Usage:
  python3 tools/semantic_source_match.py --src-tree /tmp/beken-ke/.../modules/ke/src \
      --image fmacfw_h_u02 --limit 60 --out metadata/semantic_match_ke.json
"""
import argparse
import collections
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from decisions_client import decide

VOCAB = ("ke_", "msg", "timer", "evt", "event", "task", "queue", "mm_", "mem",
         "ipc", "list", "alloc", "free")


def split_source_functions(path):
    """Naive C function splitter for the RW source files: returns
    {name: body} for top-level function definitions."""
    text = open(path, errors="replace").read()
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    out = {}
    pat = re.compile(
        r"(?m)^(?:static\s+)?(?:INLINE\s+)?[A-Za-z_][\w\s\*]*?\s+"
        r"([a-zA-Z_]\w*)\s*\(([^;{}]*)\)\s*\{", re.M)
    for m in pat.finditer(text):
        name = m.group(1)
        if name in ("if", "while", "for", "switch", "return", "sizeof"):
            continue
        depth = 1
        i = m.end()
        while i < len(text) and depth:
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1
            i += 1
        out[name] = text[m.start():i]
    return out


def extract_fw_functions(img):
    text = open(f"src/{img}/main.c").read()
    funcs = []
    for m in re.finditer(r"(?m)^// (\S+) @ 0x([0-9a-f]+)\n", text):
        funcs.append((m.group(1), int(m.group(2), 16), m.start()))
    funcs.sort(key=lambda x: x[1])
    out = []
    for i, (name, addr, pos) in enumerate(funcs):
        end = funcs[i + 1][2] if i + 1 < len(funcs) else len(text)
        out.append({"name": name, "addr": addr, "body": text[pos:end].strip()})
    return out


def candidates(src_name, src_lines, fw_funcs):
    out = []
    toks = set(re.split(r"[_\W]+", src_name.lower())) - {""}
    for f in fw_funcs:
        lines = f["body"].count("\n")
        if not (0.4 * src_lines <= lines <= 2.5 * src_lines + 20):
            continue
        ftoks = set(re.split(r"[_\W]+", f["name"].lower()))
        if toks & ftoks or any(v in f["name"].lower() for v in VOCAB):
            out.append(f)
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--src-tree", required=True)
    ap.add_argument("--image", default="fmacfw_h_u02")
    ap.add_argument("--limit", type=int, default=60)
    ap.add_argument("--out", default="metadata/semantic_match_ke.json")
    args = ap.parse_args()

    src_funcs = {}
    for fn in sorted(os.listdir(args.src_tree)):
        if fn.endswith(".c"):
            src_funcs.update(split_source_functions(os.path.join(args.src_tree, fn)))
    print(f"{len(src_funcs)} source functions from {args.src_tree}")

    fw_funcs = extract_fw_functions(args.image)
    print(f"{len(fw_funcs)} firmware functions in {args.image}")

    # build candidate pairs
    pairs = []
    for sname, sbody in sorted(src_funcs.items()):
        slines = sbody.count("\n")
        for f in candidates(sname, slines, fw_funcs):
            pairs.append({"src": sname, "src_body": sbody, "fw": f})
    print(f"{len(pairs)} candidate pairs before limit")
    pairs = pairs[: args.limit]

    # batch decisions: group pairs sharing the same firmware function into
    # one input payload where possible; simplest correct v1: one request per
    # pair is wasteful — instead batch up to 20 questions per request when
    # the input evidence (fw body) is shared.
    by_fw = collections.defaultdict(list)
    for p in pairs:
        by_fw[p["fw"]["name"]].append(p)

    results = []
    done = 0
    for fwname, group in by_fw.items():
        fw = group[0]["fw"]
        evidence = (
            "Decompiled firmware function (Hex-Rays, ARM Thumb, "
            "RivieraWaves-derived WiFi firmware):\n```c\n"
            + fw["body"][:2600] + "\n```"
        )
        questions = []
        for p in group[:20]:
            src_snip = p["src_body"][:1500]
            questions.append({
                "type": "predicate",
                "instructions": (
                    "Does the firmware function implement the same core logic as this "
                    f"RivieraWaves source function named {p['src']}? Judge semantics, not "
                    "naming or codegen details. Source:\n```c\n" + src_snip + "\n```"
                ),
            })
        try:
            answers = decide(evidence, questions)
        except Exception as e:
            print(f"decide failed for {fwname}: {str(e)[:100]}")
            continue
        for p, a in zip(group[:20], answers):
            prob = a.get("probability", 0)
            results.append({
                "src": p["src"], "fw": fwname, "fw_addr": hex(fw["addr"]),
                "probability": prob,
            })
        done += 1
        if done % 10 == 0:
            print(f"  {done}/{len(by_fw)} fw functions evaluated", flush=True)

    json.dump(results, open(args.out, "w"), indent=1)
    strong = [r for r in results if r["probability"] >= 0.7]
    print(f"{len(results)} pairs scored, {len(strong)} strong matches (p>=0.7)")
    for r in sorted(strong, key=lambda x: -x["probability"])[:12]:
        print(f"  {r['src']:24s} ~= {r['fw']:28s} @ {r['fw_addr']} p={r['probability']:.2f}")


if __name__ == "__main__":
    main()
