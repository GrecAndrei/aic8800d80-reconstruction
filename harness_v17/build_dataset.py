#!/usr/bin/env python3
"""v17 dataset builder.

Create a HuggingFace-ready dataset with:
- function name (LLM-proposed, v17)
- disasm
- behavioral C
- docstring
- subsystem
- tool calls made
- number of tool rounds
- success indicator

Output: artifacts/releases/aic8800d80-rebuild-v1-v17/dataset/v17_ml_pairs.jsonl
"""
import json, sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
NAMES_DIR = REPO / "harness_v17/names"
BEHAV_DIR = REPO / "extraction_out/reconstruction/mega7/synth"
OUT = REPO / "artifacts/releases/aic8800d80-rebuild-v1-v17/dataset"
OUT.mkdir(parents=True, exist_ok=True)

# Read the existing v15 ml pairs (function, disasm, behavioral_c)
v15_pairs = []
with open(REPO / "artifacts/releases/aic8800d80-rebuild-v1/dataset/v15_ml_pairs.jsonl") as f:
    for line in f:
        v15_pairs.append(json.loads(line))
print(f"Loaded {len(v15_pairs)} v15 pairs", file=sys.stderr)

# Build a function -> v17 name lookup
fn_lookup = {}
for f in NAMES_DIR.glob("*.json"):
    try:
        d = json.load(open(f))
        if d.get('status') != 'ok': continue
        if not d.get('name'): continue
        # key: (original_fn, image)
        fn_lookup[(d['fn'], d['img'])] = d
    except Exception:
        pass
print(f"Loaded {len(fn_lookup)} v17 namings", file=sys.stderr)

# Merge: v15 + v17
out_path = OUT / "v17_ml_pairs.jsonl"
n_merged = 0
with open(out_path, 'w') as out:
    for pair in v15_pairs:
        fn = pair.get('function', '')
        img = pair.get('image', '')
        v17 = fn_lookup.get((fn, img))
        if not v17:
            continue
        # Build v17 record
        v17_record = {
            'function': fn,
            'image': img,
            'chip_address': pair.get('chip_address', ''),
            'v17_name': v17.get('name'),
            'docstring': v17.get('docstring', ''),
            'subsystem': v17.get('subsystem', 'unknown'),
            'arm_thumb': pair.get('arm_thumb', ''),
            'behavioral_c': pair.get('behavioral_c', ''),
            'mmio_op_count': pair.get('mmio_op_count', 0),
            'disambiguated': v17.get('disambiguated', False),
        }
        out.write(json.dumps(v17_record) + '\n')
        n_merged += 1
print(f"Merged {n_merged} v17 records to {out_path}", file=sys.stderr)
print(f"Size: {out_path.stat().st_size:,} bytes", file=sys.stderr)
