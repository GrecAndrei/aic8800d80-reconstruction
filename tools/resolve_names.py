#!/usr/bin/env python3
"""Resolve sub_XXXXXX → human-readable function names from composed files.

Parses the composed .reconstructed.c files for `/* addr=0x... */` comments
and builds a mapping from IDA's sub_XXXXXX addresses to the human-readable
function name. Then patches behavioral synth files that use sub_XXXXXX names.

Usage:
  python3 tools/resolve_names.py \\
    --composed-dir extraction_out/reconstruction/mega7/composed \\
    --synth-dir extraction_out/reconstruction/mega7/synth \\
    [--dry-run]
"""
from __future__ import annotations

import argparse
import json
import os
import re
import sys
from pathlib import Path

BASE = 0x1200000


def load_name_map(composed_dir: str) -> dict[str, dict[str, str]]:
    """Parse all composed files, return {image_name: {sub_name: human_name}}."""
    composed_dir = Path(composed_dir)
    result: dict[str, dict[str, str]] = {}

    addr_re = re.compile(r'addr=0x([0-9a-fA-F]+)')
    fn_re = re.compile(r'void\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*\(')

    for fpath in sorted(composed_dir.glob('*.reconstructed.c')):
        image = fpath.stem  # e.g. "lmacfw_rf_8800d80_u02_bin"
        text = fpath.read_text(encoding='utf-8', errors='replace')
        lines = text.split('\n')

        mapping: dict[str, str] = {}
        pending_addr: str | None = None
        for line in lines:
            m = addr_re.search(line)
            if m:
                pending_addr = m.group(1)
                continue
            if pending_addr is not None:
                m = fn_re.search(line)
                if m:
                    human_name = m.group(1)
                    if 'sub_' not in human_name.lower():
                        file_off = int(pending_addr, 16)
                        runtime_addr = file_off + BASE
                        sub_name = f'sub_{runtime_addr:X}'
                        mapping[sub_name] = human_name
                pending_addr = None

        if mapping:
            result[image] = mapping
            print(f'  {image}: {len(mapping)} name mappings', file=sys.stderr)

    return result


def patch_synth_file(synth_path: Path, name_map: dict[str, str], dry_run: bool = False) -> bool:
    """Patch a single synth file: rename sub_XXXXXX to human name in filename and body."""
    text = synth_path.read_text(encoding='utf-8', errors='replace')

    # Find which sub_XXXXXX name is in this file
    sub_names = re.findall(r'\bsub_[0-9A-Fa-f]+\b', text)
    if not sub_names:
        return False

    # Try each sub name until we find one in the map
    target_sub = None
    target_human = None
    for sn in sub_names:
        if sn in name_map:
            target_sub = sn
            target_human = name_map[sn]
            break

    if target_sub is None:
        return False

    # Patch the body: void sub_XXXXXX(void) -> void human_name(void)
    new_text = re.sub(
        rf'\bvoid\s+{re.escape(target_sub)}\s*\(',
        f'void {target_human}(',
        text
    )

    if new_text == text:
        return False

    # Rename the file
    old_name = synth_path.name
    new_name = old_name.replace(target_sub, target_human, 1)
    new_path = synth_path.with_name(new_name)
    # Also patch task= header if present
    new_text = re.sub(
        rf'task={re.escape(target_sub)}\b',
        f'task={target_human}',
        new_text
    )
    # Regenerate marker comment
    new_text = re.sub(
        rf'/\*\s*reconstructed_micro_flow:\s*yes\s*\*/',
        '/* reconstructed_micro_flow: yes */',
        new_text
    )

    if dry_run:
        print(f'  [DRY] {old_name} -> {new_name} ({target_sub} -> {target_human})', file=sys.stderr)
        return True

    if new_path != synth_path:
        synth_path.unlink()
    new_path.write_text(new_text, encoding='utf-8')
    print(f'  {old_name} -> {new_name}', file=sys.stderr)
    return True


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--composed-dir', required=True, type=Path)
    ap.add_argument('--synth-dir', required=True, type=Path)
    ap.add_argument('--dry-run', action='store_true')
    ap.add_argument('--out-map', type=Path, help='Write name map JSON for reuse')
    args = ap.parse_args()

    print('Loading name map from composed files...', file=sys.stderr)
    name_map = load_name_map(str(args.composed_dir))

    if args.out_map:
        with open(args.out_map, 'w') as f:
            json.dump(name_map, f, indent=2)
        print(f'Wrote name map to {args.out_map}', file=sys.stderr)

    total_map = {}
    for image, mapping in name_map.items():
        total_map.update(mapping)
    print(f'Total name mappings: {len(total_map)}', file=sys.stderr)

    # Build per-image lookup: filename stem -> image tag in synth filename
    synth_files = sorted(args.synth_dir.glob('behavioral_*.synth.c'))
    patched = 0
    skipped = 0
    for sf in synth_files:
        # Extract image tag from filename: behavioral_sub_XXXXXX__TAG.synth.c
        name = sf.name  # e.g. "behavioral_sub_121118C__lmacfw_rf_8800d80_u02_bin.synth.c"
        # Strip .synth.c first
        base = name.replace('.synth.c', '')  # "behavioral_sub_121118C__lmacfw_rf_8800d80_u02_bin"
        parts = base.split('__')
        if len(parts) < 2:
            skipped += 1
            continue
        img_tag = parts[-1]  # "lmacfw_rf_8800d80_u02_bin"

        mapping = None
        for key in name_map:
            img_key = key.replace('.reconstructed', '')
            if img_tag == img_key:
                mapping = name_map.get(key)
                break
            # Also try: img_key might contain img_tag or vice versa
            if img_tag in img_key or img_key in img_tag:
                mapping = name_map.get(key)
                break
        if mapping is None:
            skipped += 1
            continue
        if patch_synth_file(sf, mapping, dry_run=args.dry_run):
            patched += 1
        else:
            skipped += 1

    print(f'\nPatched: {patched}, Skipped: {skipped}', file=sys.stderr)
    print(f'Total behavioral files: {len(synth_files)}', file=sys.stderr)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
