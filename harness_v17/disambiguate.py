#!/usr/bin/env python3
"""v17 variant disambiguator.

The LLM often collapses many _nNNN variants to the same name. This pass:
1. Detects name collisions (multiple functions -> same name)
2. Disambiguates by appending a short address-based suffix
3. Resolves conflicts with existing names in the file

Result: every function has a UNIQUE meaningful name, and the variant info
is preserved.
"""
import json, re, sys
from pathlib import Path
from collections import defaultdict

REPO = Path("/home/grec-alexander/Downloads/aic8800d80")
NAMES_DIR = REPO / "harness_v17/names"

def addr_to_short(addr):
    """Convert chip runtime address to short unique suffix."""
    if not addr or not isinstance(addr, str): return ""
    a = int(addr, 16) if addr.startswith("0x") else 0
    if a >= 0x200000:
        a = a - 0x1100000  # v14 -> chip
    # Use last 16 bits = 4 hex chars (more unique than 12 bits)
    return f"{a & 0xffff:04x}"


def disambiguate():
    """For each name collision, add a short address-based suffix."""
    # Group by (subsystem, name) -> list of (fn, img, addr, json_path)
    by_name = defaultdict(list)
    for f in NAMES_DIR.glob("*.json"):
        try:
            d = json.load(open(f))
            if d.get('status') != 'ok': continue
            name = d.get('name')
            if not name: continue
            by_name[name].append((d['fn'], d['img'], d.get('addr', ''), f))
        except Exception:
            pass
    print(f"Loaded {len(by_name)} unique names", file=sys.stderr)
    # Find collisions
    collisions = {n: v for n, v in by_name.items() if len(v) > 1}
    print(f"Found {len(collisions)} name collisions", file=sys.stderr)
    # Disambiguate
    fixed = 0
    for name, members in collisions.items():
        # Sort by full address for determinism
        members.sort(key=lambda m: m[2] if m[2] else '0x0')
        seen_suffixes = set()
        for i, (fn, img, addr, fpath) in enumerate(members):
            if i == 0:
                continue  # keep first one with bare name
            # Build a suffix that disambiguates this one from the first
            suf = addr_to_short(addr)
            # If suffix already used by another variant with same address, add an index
            new_name = f"{name}_{suf}"
            counter = 2
            while new_name in seen_suffixes or new_name in by_name:
                new_name = f"{name}_{suf}_{counter}"
                counter += 1
            seen_suffixes.add(new_name)
            d = json.load(open(fpath))
            d['name'] = new_name
            d['disambiguated'] = True
            fpath.write_text(json.dumps(d))
            fixed += 1
    print(f"Disambiguated {fixed} functions", file=sys.stderr)
    # Also detect ALL names that need uniqueness check (for the integration step)
    # Build a final name set
    final = {}
    for f in NAMES_DIR.glob("*.json"):
        try:
            d = json.load(open(f))
            if d.get('status') != 'ok': continue
            final[(d['fn'], d['img'])] = d.get('name')
        except Exception:
            pass
    # Check for remaining collisions
    name_count = defaultdict(list)
    for (fn, img), name in final.items():
        if name:
            name_count[name].append((fn, img))
    final_collisions = {n: v for n, v in name_count.items() if len(v) > 1}
    if final_collisions:
        print(f"REMAINING COLLISIONS: {len(final_collisions)}", file=sys.stderr)
        # Resolve by adding _2, _3 etc
        for n, members in final_collisions.items():
            members.sort()
            for i, (fn, img) in enumerate(members):
                if i == 0: continue
                fpath = NAMES_DIR / f"{fn}__{img}.json"
                d = json.load(open(fpath))
                d['name'] = f"{n}_{i+1}"
                d['disambiguated'] = True
                fpath.write_text(json.dumps(d))
        # Re-check
        final = {}
        for f in NAMES_DIR.glob("*.json"):
            try:
                d = json.load(open(f))
                if d.get('status') != 'ok': continue
                final[(d['fn'], d['img'])] = d.get('name')
            except Exception:
                pass
        name_count = defaultdict(list)
        for (fn, img), name in final.items():
            if name:
                name_count[name].append((fn, img))
        final_collisions = {n: v for n, v in name_count.items() if len(v) > 1}
        if final_collisions:
            print(f"STILL REMAINING: {len(final_collisions)}", file=sys.stderr)
        else:
            print("ALL NAMES UNIQUE (after second pass)", file=sys.stderr)
    else:
        print("ALL NAMES UNIQUE", file=sys.stderr)
    return len(final_collisions) == 0


if __name__ == "__main__":
    disambiguate()
