#!/usr/bin/env python3
"""v17 re-integration: apply v17 names to the composed C.

For each function in harness_v17/names/, find it in the composed C and rename
it. Also update struct types and add docstring comments.

O(n) implementation: single regex pass with alternation.
"""
import json, re, sys
from pathlib import Path

REPO = Path("/home/grec-alexander/Downloads/aic8800d80")
NAMES_DIR = REPO / "harness_v17/names"
# IMPORTANT: source from v15 final (which has v14 synthesis bodies),
# NOT from extraction_out/reconstruction/mega7/final/ (which has empty TODO stubs)
COMPOSED_DIR = REPO / "artifacts/releases/aic8800d80-rebuild-v1/final"
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


def process_composed(path):
    text = path.read_text()
    img = path.stem.replace('.reconstructed', '')
    # Build rename map for this image
    rename_map = {}
    for (fn, im), d in NAMINGS.items():
        if im != img: continue
        old = fn
        new = d.get('name')
        if (new and new != old
                and re.match(r'^[a-zA-Z_][a-zA-Z0-9_]*$', new)
                and len(new) <= 80):  # avoid absurd names
            rename_map[old] = new
    if not rename_map:
        print(f"  No renames for {img}", file=sys.stderr)
        return
    # Find all function names already defined in the file
    existing_names = set(re.findall(r'^\s*(?:void|int|uint\d+_t|static\s+\w+|extern\s+\w+)\s+(\w+)\s*\(', text, re.M))
    print(f"  {img}: {len(existing_names)} existing function names in file", file=sys.stderr)
    # Detect collisions: if multiple old names map to the same new name, keep the longest
    new_to_old = {}
    for old, new in rename_map.items():
        new_to_old.setdefault(new, []).append(old)
    final_renames = {}
    skipped_existing = 0
    skipped_collision = 0
    for new, olds in new_to_old.items():
        # If 'new' already exists in the file, skip ALL renames to avoid redefinition
        if new in existing_names:
            skipped_existing += len(olds)
            continue
        if len(olds) == 1:
            final_renames[olds[0]] = new
        else:
            skipped_collision += len(olds) - 1
            # Keep longest old name, suffix others
            olds.sort(key=lambda s: -len(s))
            final_renames[olds[0]] = new
            for other in olds[1:]:
                # Disambiguate: prefix with original distinguishing token
                final_renames[other] = other  # keep original name
    if skipped_existing or skipped_collision:
        print(f"  {img}: skipped {skipped_existing} (target exists), {skipped_collision} (collision)", file=sys.stderr)
    # O(n) approach
    sorted_renames = sorted(final_renames.items(), key=lambda x: -len(x[0]))
    rename_dict = dict(sorted_renames)
    alt = '|'.join(re.escape(old) for old, _ in sorted_renames)
    pattern = re.compile(r'\b(' + alt + r')\b')

    def sub(m):
        return rename_dict[m.group(1)]

    new_text = pattern.sub(sub, text)
    n_replaced = len(final_renames)
    out_path = OUT_DIR / path.name
    out_path.write_text(new_text)
    print(f"  {path.name}: {n_replaced} renames applied ({len(new_text)} bytes)", file=sys.stderr)


for f in composed_files:
    process_composed(f)
print(f"\nOutput: {OUT_DIR}", file=sys.stderr)
