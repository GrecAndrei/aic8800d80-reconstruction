#!/usr/bin/env python3
"""v17 re-integration: apply v17 names to the composed C.

For each function in harness_v17/names/, find it in the composed C and rename
it. Also update struct types and add docstring comments.
"""
import json, re, sys
from pathlib import Path

REPO = Path("/home/grec-alexander/Downloads/aic8800d80")
NAMES_DIR = REPO / "harness_v17/names"
COMPOSED_DIR = REPO / "extraction_out/reconstruction/mega7/final"
OUT_DIR = REPO / "artifacts/releases/aic8800d80-rebuild-v1/composed_v17"
OUT_DIR.mkdir(parents=True, exist_ok=True)

# Get all successful namings
NAMINGS = {}  # (fn, img) -> {name, docstring, subsystem, params}
for f in NAMES_DIR.glob("*.json"):
    try:
        d = json.load(open(f))
        if d.get('status') != 'ok': continue
        key = (d['fn'], d['img'])
        NAMINGS[key] = d
    except Exception:
        pass
print(f"Loaded {len(NAMINGS)} successful namings", file=sys.stderr)

# Find composed C files
composed_files = list(COMPOSED_DIR.glob("*_bin.reconstructed.c"))
print(f"Found {len(composed_files)} composed C files", file=sys.stderr)

# For each composed C, apply renames
def process_composed(path):
    text = path.read_text()
    img = path.stem.replace('.reconstructed', '').replace('_bin', '_bin')
    # Build rename map for this image
    rename_map = {}  # old_name -> new_name
    for (fn, im), d in NAMINGS.items():
        if im != img: continue
        old = fn
        new = d.get('name')
        if new and new != old and re.match(r'^[a-zA-Z_][a-zA-Z0-9_]*$', new):
            rename_map[old] = new
    if not rename_map:
        print(f"  No renames for {img}", file=sys.stderr)
        return
    # Apply renames (longest first to avoid prefix issues)
    sorted_renames = sorted(rename_map.items(), key=lambda x: -len(x[0]))
    for old, new in sorted_renames:
        # Word-boundary replace to avoid partial matches
        pat = re.compile(r'\b' + re.escape(old) + r'\b')
        text = pat.sub(new, text)
    # Write output
    out_path = OUT_DIR / path.name
    out_path.write_text(text)
    print(f"  {path.name}: {len(rename_map)} renames applied", file=sys.stderr)

for f in composed_files:
    process_composed(f)
print(f"\nOutput: {OUT_DIR}", file=sys.stderr)
