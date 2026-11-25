#!/usr/bin/env python3
"""Instruction-fingerprint matching: quantify which firmware functions are
source-recoverable verbatim from the public RivieraWaves tree.

Method: extract per-function normalized fingerprints from both sides —
  * compiled RW objects (/tmp/ke_armobj/*.o) via objdump
  * firmware binary functions via capstone at corpus addresses
Fingerprint = (mnemonic histogram, immediate-constant multiset). Scoring
combines mnemonic cosine similarity with distinctive-constant overlap;
constants survive compiler-version differences better than exact sequences,
and mnemonic histograms capture loop/branch structure.

Usage: python3 tools/fingerprint_match.py [--topn 5]
"""
import json
import re
import subprocess
import sys
import argparse
import collections
import glob
import os

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

OBJDIR = "/tmp/ke_armobj"
FW = "inputs/firmware/fmacfw_8800d80_h_u02.bin"
FWBASE = 0x100000


def obj_functions(path):
    """objdump -d an object file, split per function symbol."""
    out = subprocess.run(["arm-none-eabi-objdump", "-d", path],
                         capture_output=True, text=True).stdout
    funcs = {}
    cur = None
    for line in out.splitlines():
        m = re.match(r"^[0-9a-f]+ <([\w.]+)>:", line)
        if m:
            cur = m.group(1)
            funcs[cur] = []
            continue
        im = re.match(r"^\s*[0-9a-f]+:\s+(.*)", line)
        if im and cur is not None:
            # consume leading hex halfword tokens (1-2 for thumb), the next
            # token is the mnemonic, the rest operands
            toks = im.group(1).split(None, 8)
            i = 0
            while i < len(toks) and re.fullmatch(r"[0-9a-f]{4,8}", toks[i] or ""):
                i += 1
            if i < len(toks) and 0 < i:
                mnem = toks[i]
                ops = " ".join(toks[i + 1:])
                funcs[cur].append((mnem, ops))
    return funcs


def norm_mnemonic(mn):
    # strip condition suffixes and width qualifiers for structural comparison
    return re.sub(r"\.w$|\.n$", "", mn)


def consts_of(ops):
    out = []
    for c in re.findall(r"#(0x[0-9a-f]+|\d+)", ops):
        v = int(c, 0)
        if v >= 4:  # ignore trivially small structure offsets/immediates
            out.append(v)
    return out


def fingerprint(insns):
    mnems = collections.Counter(norm_mnemonic(m) for m, _ in insns)
    consts = collections.Counter()
    for _, ops in insns:
        consts.update(consts_of(ops))
    return {"mnems": mnems, "consts": consts, "n": len(insns)}


def cosine(a, b):
    if not a or not b:
        return 0.0
    inter = set(a) & set(b)
    num = sum(min(a[k], b[k]) for k in inter)
    den = (sum(v * v for v in a.values()) ** 0.5) * (sum(v * v for v in b.values()) ** 0.5)
    return num / den if den else 0.0


def fw_functions(img_path, keys):
    """Disassemble firmware functions with capstone at corpus addresses."""
    from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_MCLASS
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_MCLASS)
    data = open(img_path, "rb").read()
    out = {}
    for key in keys:
        off = key - FWBASE
        if off < 0 or off >= len(data):
            continue
        insns = []
        for ins in list(md.disasm(data[off:off + 96], key))[:28]:
            insns.append((ins.mnemonic, ins.op_str))
        out[key] = insns
    return out


def corpus_keys(img):
    text = open(f"src/{img}/main.c").read()
    return sorted(int(m.group(1), 16) for m in re.finditer(r"(?m)^\x2f\x2f \S+ @ 0x([0-9a-f]+)\n", text))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--topn", type=int, default=5)
    ap.add_argument("--image", default="fmacfw_h_u02")
    ap.add_argument("--bin", default=FW)
    args = ap.parse_args()

    rw = {}
    for obj in sorted(glob.glob(f"{OBJDIR}/*.o")):
        for fname, insns in obj_functions(obj).items():
            if len(insns) >= 6:
                rw[fname] = fingerprint(insns)
    print(f"{len(rw)} RW functions fingerprinted from objects")

    keys = corpus_keys(args.image)
    fwf = fw_functions(args.bin, keys)
    fwfp = {k: fingerprint(v) for k, v in fwf.items() if len(v) >= 6}
    print(f"{len(fwfp)} firmware functions fingerprinted")

    report = {}
    strong = 0
    for rwname, rwfp in sorted(rw.items()):
        scored = []
        for key, fp in fwfp.items():
            ms = cosine(rwfp["mnems"], fp["mnems"])
            if ms < 0.5:
                continue
            cs = cosine(rwfp["consts"], fp["consts"])
            score = 0.6 * ms + 0.4 * cs
            scored.append((score, ms, cs, key))
        scored.sort(reverse=True)
        top = scored[:args.topn]
        report[rwname] = [
            {"score": round(s, 3), "mnem": round(m, 3), "const": round(c, 3),
             "fw_addr": hex(k)} for s, m, c, k in top]
        if top and top[0][0] >= 0.75 and top[0][1] >= 0.7:
            strong += 1
    json.dump(report, open("metadata/fingerprint_ke.json", "w"), indent=1)
    print(f"strong matches (score>=0.75, mnem>=0.7): {strong}/{len(rw)} RW functions")
    for rwname, top in sorted(report.items()):
        if top and top[0]["score"] >= 0.75:
            print(f"  {rwname}: {top[0]['fw_addr']} score {top[0]['score']}")


if __name__ == "__main__":
    main()
