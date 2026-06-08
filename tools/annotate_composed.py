#!/usr/bin/env python3
"""Post-process composed files to add addr=0x... annotations for every function.

The composed file currently only annotates lifted units. Dependency stubs
lack addr= comments, preventing the name resolver from matching behavioral
synth bodies.

If a function name is already sub_XXXXXX, the address is derived directly
from the name (sub_121118C -> runtime 0x121118C -> file offset 0x1118C).
For human-readable names, the name map (sub->human inverted) is used.

Usage:
  python3 tools/annotate_composed.py \\
    --composed-dir extraction_out/reconstruction/mega7/composed \\
    --name-map /tmp/opencode/name_map.json
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

BASE = 0x1200000


def build_human_to_addr(name_map_path: str) -> dict[str, str]:
    """Invert sub_XXXXXX -> human_name map and derive file offsets."""
    result: dict[str, str] = {}
    with open(name_map_path) as f:
        name_map = json.load(f)
    for img, mapping in name_map.items():
        for sub_name, human_name in mapping.items():
            try:
                runtime = int(sub_name.replace('sub_', ''), 16)
                file_off = runtime - BASE if runtime >= BASE else runtime
                result[human_name] = hex(file_off)
            except ValueError:
                pass
    return result


def annotate_file(composed_path: Path, human_to_addr: dict[str, str], dry_run: bool = False) -> int:
    text = composed_path.read_text(encoding='utf-8', errors='replace')
    lines = text.split('\n')

    addr_re = re.compile(r'addr=0x([0-9a-fA-F]+)')
    fn_def_re = re.compile(r'void\s+([a-zA-Z_][a-zA-Z0-9_]+)\s*\(\s*void\s*\)\s*\{')
    fn_decl_re = re.compile(r'void\s+([a-zA-Z_][a-zA-Z0-9_]+)\s*\(\s*void\s*\)\s*;')
    sub_re = re.compile(r'^sub_[0-9A-Fa-f]+$')

    existing: set[str] = set()
    pending = None
    for line in lines:
        m = addr_re.search(line)
        if m:
            pending = m.group(1)
            continue
        m = fn_def_re.search(line)
        if m:
            if pending:
                existing.add(m.group(1))
            pending = None
        elif ';' in line and 'void' in line:
            pending = None

    new_lines = []
    added = 0
    for line in lines:
        m = fn_def_re.search(line)
        if m:
            fn_name = m.group(1)
            if fn_name not in existing:
                addr = None
                if sub_re.match(fn_name):
                    try:
                        runtime = int(fn_name.replace('sub_', ''), 16)
                        addr = runtime - BASE if runtime >= BASE else runtime
                    except ValueError:
                        pass
                elif fn_name in human_to_addr:
                    try:
                        addr = int(human_to_addr[fn_name], 16)
                    except ValueError:
                        pass
                if addr is not None:
                    if dry_run:
                        print(f'  [DRY] {fn_name} @ 0x{addr:x}', file=sys.stderr)
                    else:
                        new_lines.append(f'/* addr=0x{addr:x} */')
                    added += 1
        new_lines.append(line)

    if not dry_run and added > 0:
        composed_path.write_text('\n'.join(new_lines), encoding='utf-8')
    return added


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--composed-dir', required=True, type=Path)
    ap.add_argument('--name-map', required=True, type=Path)
    ap.add_argument('--dry-run', action='store_true')
    args = ap.parse_args()

    human_to_addr = build_human_to_addr(str(args.name_map))
    print(f'Loaded {len(human_to_addr)} human-readable names', file=sys.stderr)

    total = 0
    for fpath in sorted(args.composed_dir.glob('*.reconstructed.c')):
        added = annotate_file(fpath, human_to_addr, dry_run=args.dry_run)
        print(f'{fpath.name}: +{added} annotations', file=sys.stderr)
        total += added

    print(f'Total: +{total}', file=sys.stderr)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
