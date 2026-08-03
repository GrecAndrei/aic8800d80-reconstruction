#!/usr/bin/env python3
"""Full-corpus emulator sweep: run every function in all 4 images.

For each function in the fwstruct scan (harness_v25/out/*_funcs.jsonl), boot
a fresh platform and run the function at hardware base (chip addr =
scan addr + HW_OFFSET) up to ``--max-insns``. Classify each run as
returned / capped / fault and summarize:

  - how many functions execute cleanly under the behavioral MMIO model
  - which fault, and on what (unknown MMIO page, null context slot, ...)
  - which cap (deep loop, poll never ready, OS-style wait)

The 25 truth-lane targets are the curated gate; this sweep is the corpus-wide
coverage check that finds gaps the curated set misses (an unmapped MMIO page
the behavior model didn't classify, an extra boot-ROM slot, etc.).

Faults are bucketed by (fault_address page, fault_pc page) so novel gaps are
visible in aggregate instead of as 5,000 individual rows.
"""

from __future__ import annotations

import argparse
import json
import sys
import time
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))

from tools.aic8800d80_emulator import (  # noqa: E402
    Aic8800D80Platform,
    HW_OFFSET,
    IMAGE_NAMES,
    SCAN_GLOB,
    load_mmio_model,
    load_function_table,
    resolve_image,
)

DEFAULT_CAP = 5000
PAGE = 0x1000


def sweep_image(image: str, max_insns: int, every: int, out_path: Path) -> dict:
    scan = Path(str(SCAN_GLOB).format(image))
    if not scan.is_file():
        return {"error": f"no scan {scan}"}
    fns = [json.loads(l) for l in scan.read_text().splitlines() if l.strip()]
    fns = [f for f in fns if isinstance(f.get("address"), int) and f.get("name")]
    fns.sort(key=lambda f: f["address"])

    img_path = resolve_image(f"{image}.bin")
    model = load_mmio_model()
    ivt = None
    rows = []
    start = time.time()
    for i, fn in enumerate(fns):
        if every > 1 and i % every != 0:
            continue
        chip = fn["address"] + HW_OFFSET
        plat = Aic8800D80Platform(img_path, mmio_model=model)
        plat.function_table = load_function_table(image)
        if ivt is None:
            ivt = plat.ivt()
        term, stats = plat.run(chip, max_insns, sp=ivt["stack_pointer"])
        rows.append({
            "image": image,
            "name": fn["name"],
            "address": hex(chip),
            "termination": term,
            "instructions": stats["instructions"],
            "fault": stats.get("fault") or "",
            "fault_pc": stats.get("fault_pc"),
            "fault_access": stats.get("fault_access"),
            "fault_address": stats.get("fault_address"),
            "mmio_reads": stats["mmio_reads"],
            "mmio_writes": stats["mmio_writes"],
        })
    elapsed = time.time() - start

    with out_path.open("w", encoding="utf-8") as f:
        for r in rows:
            f.write(json.dumps(r, sort_keys=True) + "\n")

    counts = Counter(r["termination"] for r in rows)
    faults = [r for r in rows if "fault" in r["termination"]]
    # Bucket faults by fault-address page and fault-pc page.
    fault_pages = Counter()
    fault_pcs = Counter()
    for r in faults:
        if r["fault_address"]:
            a = int(r["fault_address"], 16)
            fault_pages[(a & ~(PAGE - 1))] += 1
        if r["fault_pc"]:
            pc = int(r["fault_pc"], 16)
            fault_pcs[(pc & ~(PAGE - 1))] += 1

    return {
        "image": image,
        "scanned": len(fns),
        "sampled": len(rows),
        "returned": counts["returned"],
        "capped": counts["capped"],
        "faulted": counts["fault"],
        "elapsed_s": round(elapsed, 1),
        "fault_pages": [{"page": hex(p), "n": n} for p, n in fault_pages.most_common(15)],
        "fault_pcs": [{"page": hex(p), "n": n} for p, n in fault_pcs.most_common(15)],
    }


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--images", nargs="*", default=list(IMAGE_NAMES),
                    help="images to sweep (default: all)")
    ap.add_argument("--max-insns", type=int, default=DEFAULT_CAP)
    ap.add_argument("--every", type=int, default=1,
                    help="only run every Nth function (sampling)")
    ap.add_argument("--out", default="/tmp/opencode/corpus_sweep",
                    help="output directory")
    args = ap.parse_args()

    out_dir = Path(args.out)
    out_dir.mkdir(parents=True, exist_ok=True)
    summaries = []
    for img in args.images:
        out = out_dir / f"{img}.jsonl"
        s = sweep_image(img, args.max_insns, args.every, out)
        summaries.append(s)
        print(f"[sweep] {s['image']:28s} scanned={s['scanned']:5d} "
              f"sampled={s['sampled']:5d} returned={s['returned']:5d} "
              f"capped={s['capped']:5d} faulted={s['faulted']:5d} "
              f"({s['elapsed_s']:.0f}s)", file=sys.stderr)
        for fp in s.get("fault_pages", [])[:6]:
            print(f"    fault@page {fp['page']}: {fp['n']}", file=sys.stderr)

    (out_dir / "summary.json").write_text(json.dumps(summaries, indent=2))
    print(json.dumps(summaries, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
