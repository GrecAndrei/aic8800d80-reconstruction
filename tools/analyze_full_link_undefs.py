#!/usr/bin/env python3
"""Quantify the undefined symbols of a FULL (non --gc-sections) link.

The unified series compiles each image to one object and links reachable
code with ``--gc-sections --entry=start`` (0 undefs). Without gc-sections
every function is kept, so the objects still reference symbols that have no
definition in the image. This tool classifies those undefs to decide whether
they are real missing code or artifacts of the naming/address model.

Method per image:
  1. ``nm -u <img>.o`` -> undefined symbols.
  2. ``__aeabi_*`` -> float helpers (need -lgcc), not missing code.
  3. Look each remaining name up in ``harness_v17/names/*.json`` (the LLM
     naming dataset). Normalize its recorded image (strip ``_bin``) and its
     address (the dataset mixes chip-space and v14-space; ``chip =
     v14 - 0x1100000``).
  4. If the name resolves to an address inside a composed function
     (scan-table boundaries) -> naming artifact, the code exists.
  5. Cross-image / rename-mismatch / no-mapping buckets make up the rest.

Usage:
  python3 tools/analyze_full_link_undefs.py            # uses src/*.o
  python3 tools/analyze_full_link_undefs.py --rebuild   # recompile first
"""
from __future__ import annotations

import argparse
import bisect
import json
import os
import re
import subprocess
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMGS = ["fmacfw_8800d80_h_u02", "fmacfw_8800d80_u02", "fmacfwbt_8800d80_u02", "lmacfw_rf_8800d80_u02"]
LONG_TO_SHORT = {
    "fmacfw_8800d80_h_u02": "fmacfw_h_u02",
    "fmacfw_8800d80_u02": "fmacfw_u02",
    "fmacfwbt_8800d80_u02": "fmacfwbt_u02",
    "lmacfw_rf_8800d80_u02": "lmacfw_rf_u02",
}
V14_TO_CHIP = 0x1100000
ARTIFACTS = {"MEMORY", "COERCE_UNSIGNED_INT", "COERCE_FLOAT", "memmove",
             "memcpy", "memset", "strlen", "strcpy", "while", "for", "return"}


def to_chip(img: str, addr: int) -> int | None:
    """Dataset addresses mix chip-space and v14-space; return chip address."""
    lo, hi = 0x100000, 0x100000 + (REPO / f"inputs/firmware/{img}.bin").stat().st_size
    for cand in (addr, addr - V14_TO_CHIP):
        if lo <= cand < hi:
            return cand
    return None


def load_scan(img: str) -> list[tuple[int, str]]:
    tbl = []
    seen = set()
    for line in (REPO / f"harness_v25/out/{img}_bin_funcs.jsonl").read_text(errors="replace").splitlines():
        try:
            j = json.loads(line)
        except json.JSONDecodeError:
            continue
        a = j.get("address")
        if isinstance(a, int) and a not in seen:
            seen.add(a)
            tbl.append((a, j.get("name", "")))
    tbl.sort()
    return tbl


def load_dataset() -> dict[str, list[tuple[str, int | None]]]:
    out: dict[str, list[tuple[str, int | None]]] = {}
    names_dir = REPO / "harness_v17" / "names"
    for f in os.listdir(names_dir):
        if not f.endswith(".json"):
            continue
        try:
            j = json.loads((names_dir / f).read_text(errors="replace"))
        except Exception:
            continue
        nm = j.get("fn") or j.get("name")
        img = (j.get("img") or "").replace("_bin", "")
        addr = j.get("addr", "")
        if not nm or img not in LONG_TO_SHORT or not addr:
            continue
        try:
            a = int(addr, 16)
        except ValueError:
            continue
        out.setdefault(nm, []).append((img, to_chip(img, a)))
    return out


def classify(img: str, undefs: list[str], defined: dict[int, str],
             scan: list[tuple[int, str]], dataset: dict[str, list[tuple[str, int | None]]]) -> dict:
    starts = [t[0] for t in scan]
    cats: dict[str, list] = {
        "__aeabi_float": [], "rename_mismatch": [], "naming_artifact": [],
        "cross_image": [], "sub_star_gap": [], "artifact": [], "no_mapping": [],
    }
    for u in undefs:
        if u.startswith("__aeabi_"):
            cats["__aeabi_float"].append(u)
            continue
        entries = dataset.get(u, [])
        local = [(img2, chip) for (img2, chip) in entries if img2 == img and chip is not None]
        if local:
            chip = local[0][1]
            if chip in defined:
                cats["rename_mismatch"].append((u, defined[chip], hex(chip)))
                continue
            i = bisect.bisect_right(starts, chip) - 1
            if i >= 0 and (i + 1 >= len(starts) or chip < starts[i + 1]):
                cats["naming_artifact"].append((u, scan[i][1], hex(chip)))
                continue
            cats["no_mapping"].append(u)
            continue
        other = [(img2, chip) for (img2, chip) in entries if img2 != img and chip is not None]
        if other:
            cats["cross_image"].append((u, other[0][0], hex(other[0][1])))
        elif u.startswith("sub_"):
            cats["sub_star_gap"].append(u)
        elif u in ARTIFACTS:
            cats["artifact"].append(u)
        else:
            cats["no_mapping"].append(u)
    return cats


def collect_undefs(img: str) -> list[str]:
    obj = REPO / "src" / f"{img}.o"
    if not obj.is_file():
        raise SystemExit(f"missing {obj}; run 'make -C src' first")
    out = subprocess.run(["arm-none-eabi-nm", "-u", str(obj)], capture_output=True, text=True)
    return sorted({line.split()[-1] for line in out.stdout.splitlines() if line.split()})


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rebuild", action="store_true", help="recompile src objects first")
    args = ap.parse_args()
    if args.rebuild:
        subprocess.run(["make", "-C", str(REPO / "src"), "check"], check=True)

    dataset = load_dataset()
    totals: dict[str, int] = {}
    for img in IMGS:
        defined = {}
        main = REPO / "src" / LONG_TO_SHORT[img] / "main.c"
        if main.is_file():
            for m in re.finditer(r"^// (\S+) @ (0x[0-9a-fA-F]+)$", main.read_text(errors="replace"), re.M):
                defined[int(m.group(2), 16)] = m.group(1)
        scan = load_scan(img)
        undefs = collect_undefs(img)
        cats = classify(img, undefs, defined, scan, dataset)
        print(f"=== {img} ({len(undefs)} undefs) ===")
        for k, v in cats.items():
            print(f"  {k:16s} {len(v):4d}")
            totals[k] = totals.get(k, 0) + len(v)
        if cats["naming_artifact"]:
            print("   naming-artifact ex:", cats["naming_artifact"][:3])
        if cats["sub_star_gap"]:
            print("   sub_* gaps (REAL missing code):", cats["sub_star_gap"])
        if cats["cross_image"]:
            print("   cross-image ex:", cats["cross_image"][:3])
        if cats["no_mapping"]:
            print("   no-mapping sample:", cats["no_mapping"][:8])
        print()

    grand = sum(totals.values())
    print("=== GRAND TOTAL ===")
    for k, v in sorted(totals.items(), key=lambda kv: -kv[1]):
        print(f"  {k:16s} {v:4d}  ({100 * v / grand:.1f}%)")
    real = totals.get("sub_star_gap", 0) + totals.get("rename_mismatch", 0)
    print(f"\nReal missing-code signals: ~{real} ({100 * real / grand:.1f}%); "
          f"the rest are libgcc float helpers + naming/address artifacts.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
