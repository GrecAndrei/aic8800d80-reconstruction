#!/usr/bin/env python3
"""Re-run capped functions at a higher instruction budget.

The corpus sweep classifies functions as returned / exited / capped / fault.
Capped functions are genuinely long but bounded runs (large structure scans,
RF register-config loops) that only need more budget. This tool takes a
sweep's output JSONL, picks out every capped entry, and re-runs each at
``--budget`` (default 2,000,000) instructions under the same bootstate
conditions, so completion measures the *natural* length of the function
rather than the 30k/100k corpus budget.

Output: per-image JSONL mirroring the corpus_sweep row schema, plus a
console summary. Writes ``summary.json`` if --out-dir is given.
"""
from __future__ import annotations

import argparse
import json
import sys
import time
from collections import Counter
from pathlib import Path

from aic8800d80_emulator import (
    Aic8800D80Platform,
    HW_OFFSET,
    load_function_table,
    load_mmio_model,
    resolve_image,
)
from corpus_sweep import apply_bootstate, capture_bootstate

IMAGES = ["fmacfw_8800d80_h_u02", "fmacfw_8800d80_u02",
          "fmacfwbt_8800d80_u02", "lmacfw_rf_8800d80_u02"]


def load_sweep(sweep_jsonl: Path) -> list[dict]:
    """Read a corpus_sweep output JSONL (rows have image/name/address/...)."""
    rows = [json.loads(l) for l in sweep_jsonl.read_text().splitlines() if l.strip()]
    return rows


def run_one(image: str, hw_addr: int, budget: int, boot: dict,
            max_reexits: int = 256) -> tuple[str, dict]:
    """Run one function under bootstate mode with the given budget."""
    img_path = resolve_image(f"{image}.bin")
    plat = Aic8800D80Platform(img_path, mmio_model=load_mmio_model())
    plat.function_table = load_function_table(image)
    apply_bootstate(plat.mu, boot)
    ivt = plat.ivt()
    term, stats = plat.run(hw_addr, budget, sp=ivt["stack_pointer"], spin_break=True)
    return term, stats


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("sweep_jsonl", type=Path,
                    help="corpus_sweep output JSONL (or dir of per-image JSONLs)")
    ap.add_argument("--budget", type=int, default=2_000_000,
                    help="high budget for re-running capped functions")
    ap.add_argument("--boot-insns", type=int, default=50000,
                    help="bootstate capture budget")
    ap.add_argument("--max-reexits", type=int, default=256,
                    help="re-entry budget per run; raise for wait-chained init "
                         "functions that land in exited:0x<pc> instead of capped")
    ap.add_argument("--out-dir", type=Path, default=None,
                    help="directory to write per-image result JSONLs + summary.json")
    args = ap.parse_args()

    src: Path = args.sweep_jsonl
    if src.is_dir():
        rows: list[dict] = []
        for p in sorted(src.glob("*.jsonl")):
            rows += load_sweep(p)
    else:
        rows = load_sweep(src)

    capped = [r for r in rows if r["termination"] == "capped"]
    print(f"Total rows: {len(rows)}, capped to re-run: {len(capped)}")

    # Boot states per image (captured once each).
    boot_cache = {}
    for r in capped:
        boot_cache.setdefault(r["image"], capture_bootstate(r["image"], args.boot_insns))

    results = []
    t0 = time.time()
    for i, r in enumerate(capped, 1):
        hw = int(r["address"], 16)
        term, stats = run_one(r["image"], hw, args.budget, boot_cache[r["image"]],
                              max_reexits=args.max_reexits)
        results.append({
            "image": r["image"],
            "name": r["name"],
            "address": r["address"],
            "termination": term,
            "instructions": stats["instructions"],
            "fault": stats.get("fault") or "",
            "fault_pc": stats.get("fault_pc"),
            "fault_access": stats.get("fault_access"),
            "fault_address": stats.get("fault_address"),
            "mmio_reads": stats["mmio_reads"],
            "mmio_writes": stats["mmio_writes"],
        })
        if i % 20 == 0 or i == len(capped):
            el = time.time() - t0
            print(f"  [{i}/{len(capped)}] {el:.0f}s  "
                  f"{term:9} {r['name'][:46]}", flush=True)

    counts = Counter(r["termination"] for r in results)
    n_exited = sum(v for k, v in counts.items() if k.startswith("exited"))
    print(f"\n=== High-budget re-run ({args.budget}) of {len(capped)} capped ===")
    print(f"  returned={counts['returned']} capped={counts['capped']} "
          f"exited={n_exited} fault={counts['fault']}")

    if args.out_dir:
        args.out_dir.mkdir(parents=True, exist_ok=True)
        per_img = {}
        for r in results:
            per_img.setdefault(r["image"], []).append(r)
        for img, rrows in per_img.items():
            (args.out_dir / f"{img}.jsonl").write_text(
                "\n".join(json.dumps(x, sort_keys=True) for x in rrows) + "\n")
        residual = [r for r in results if r["termination"] == "capped"]
        summary = {
            "budget": args.budget,
            "re_run": len(capped),
            "returned": counts["returned"],
            "capped": counts["capped"],
            "exited": n_exited,
            "faulted": counts["fault"],
            "residual_capped": [{
                "image": r["image"], "name": r["name"], "address": r["address"],
                "instructions": r["instructions"], "mmio_reads": r["mmio_reads"],
                "mmio_writes": r["mmio_writes"],
            } for r in sorted(residual, key=lambda z: -z["instructions"])],
        }
        (args.out_dir / "summary.json").write_text(
            json.dumps(summary, indent=2, sort_keys=True) + "\n")
        print(f"Wrote results + summary.json to {args.out_dir}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
