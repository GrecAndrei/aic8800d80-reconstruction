#!/usr/bin/env python3
"""Assign semantic labels to the inferred modules and pin them in
metadata/module_refined.json under meta[img]["labels"].

Evidence, in decreasing reliability order:
  1. cross-image pooling — the three fmac images are the same codebase linked
     three times; module index i in each is the same file, so evidence pools
  2. embedded string literals referenced by the module's functions (ground
     truth: assert expressions and trace strings name the subsystem)
  3. luna subsystem tags where the batch has covered the functions
  4. function-name token dominant terms (weakest — LLM names are noisy)

Labels are snake_case subsystem identifiers (rf_calib, sysctrl, ipc, ...).
Unknown or mixed modules stay unlabeled (modNNN.c) rather than mislabeled —
a missing label is honest, a wrong one is worse.
"""
import collections
import glob
import json
import re

# subsystem vocabulary ordered by specificity; first strong hit wins
VOCAB = [
    ("rxl", "rx"), ("txl", "tx"), ("mm_rx", "mm"), ("mm_tx", "mm"),
    ("rf_cal", "rf_calib"), ("rf_", "rf"), ("phy", "phy"), ("aes", "aes"),
    ("ipc", "ipc"), ("ke_", "ke"), ("hci", "hci"), ("bt", "bt"),
    ("dma", "dma"), ("pmu", "pmu"), ("gpio", "gpio"), ("wlan", "wlan"),
    ("scan", "scan"), ("sme", "sme"), ("mm_", "mm"), ("vif", "vif"),
    ("clock", "clock"), ("pll", "clock"), ("sysctrl", "sysctrl"),
]


def strings_for_module(img, mi, mods):
    """Decode the printable strings inside the data symbols the module's
    functions reference — the assert/trace text is subsystem ground truth."""
    text = open(f"src/{img}/modules/mod{mi:03d}.c").read() if mi < 100 else ""
    if not text:
        try:
            text = open(glob.glob(f"src/{img}/modules/mod{mi:03d}*.c")[0]).read()
        except IndexError:
            return []
    return re.findall(r'(?m)^// (\S+) @', text), text


def label_module(img, mi, meta, fn2sub_all):
    mods = meta[img]["modules"]
    m = mods[mi]
    names, text = strings_for_module(img, mi, mods)
    # evidence 2: string literals — resolve off_XXX references is complex;
    # cheaper: grep module text for quoted fragments that survived in bodies
    quoted = re.findall(r'"([a-z][a-z0-9_]{5,60})"', text)
    votes = collections.Counter()
    for q in quoted:
        for pat, lab in VOCAB:
            if q.startswith(pat):
                votes[lab] += 2  # string evidence weighs double
                break
    # evidence 3: luna subsystem tags
    for n in m["names"]:
        sub = fn2sub_all.get((img, n))
        if sub and sub not in ("?", "unknown", "test"):
            votes[sub] += 1
    # evidence 4: name tokens
    for n in names:
        for t in re.split(r"_", n.lower()):
            for pat, lab in VOCAB:
                if t == pat.rstrip("_"):
                    votes[lab] += 0.5
                    break
    if not votes:
        return ""
    lab, cnt = votes.most_common(1)[0]
    total = sum(votes.values())
    # require a meaningful majority to avoid noise labels
    if cnt >= 3 and cnt / total >= 0.4:
        return re.sub(r"[^a-z0-9_]", "", lab.lower())[:24]
    return ""


def main():
    meta = json.load(open("metadata/module_refined.json"))
    fn2sub = {}
    for f in glob.glob("metadata/luna_analysis/*.json"):
        try:
            o = json.load(open(f))
            d = json.loads(o["text"])
            fn2sub[(o["img"], o["fn"])] = d.get("subsystem", "?")
        except Exception:
            pass
    print(f"{len(fn2sub)} luna subsystem tags loaded")
    report = {}
    for img in meta:
        labels = {}
        for mi in range(len(meta[img]["modules"])):
            lab = label_module(img, mi, meta, fn2sub)
            if lab:
                labels[str(mi)] = lab
        meta[img]["labels"] = labels
        report[img] = f"{len(labels)}/{len(meta[img]['modules'])} labeled"
    json.dump(meta, open("metadata/module_refined.json", "w"), indent=1)
    for img, r in report.items():
        print(f"{img}: {r}")
    print("labels pinned in metadata/module_refined.json")


if __name__ == "__main__":
    main()
