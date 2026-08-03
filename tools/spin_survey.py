#!/usr/bin/env python3
"""Survey capped runs: how many are true wait-spins vs long functions?

For every function in every image (bootstate mode, spin-breaker OFF), sample
the PC every ``--sample-every`` instructions. A capped run whose top sampled
PC accounts for >= ``--spin-frac`` of samples is a tight wait-spin; otherwise
it's a genuinely long function that only needs more instructions.

Output: per-image JSON of deduped spin sites (by spin PC), plus a summary
table. Baseline for measuring what the spin-breaker should convert.
"""
from __future__ import annotations

import argparse
import json
import time
from collections import Counter
from pathlib import Path

from unicorn import UC_HOOK_CODE

from aic8800d80_emulator import (
    Aic8800D80Platform,
    HW_OFFSET,
    SCAN_GLOB,
    load_function_table,
    load_mmio_model,
    resolve_image,
)
from corpus_sweep import DATA_ARTIFACT_ENTRIES, apply_bootstate, capture_bootstate

IMAGES = ["fmacfw_8800d80_h_u02", "fmacfw_8800d80_u02",
          "fmacfwbt_8800d80_u02", "lmacfw_rf_8800d80_u02"]


def load_fns(image: str) -> list[dict]:
    scan = Path(str(SCAN_GLOB).format(image))
    fns = [json.loads(l) for l in scan.read_text().splitlines() if l.strip()]
    fns = [f for f in fns if isinstance(f.get("address"), int) and f.get("name")]
    for f in fns:
        if f.get("name") == "start" and f.get("address") == 0x100100:
            f["address"] = 0x1001A8
    fns = [f for f in fns
           if not ((f.get("name"), f.get("address")) in DATA_ARTIFACT_ENTRIES)]
    fns.sort(key=lambda f: f["address"])
    return fns


def sweep_spins(image: str, max_insns: int, sample_every: int,
                spin_frac: float, boot_insns: int = 50000) -> dict:
    fns = load_fns(image)
    img_path = resolve_image(f"{image}.bin")
    model = load_mmio_model()
    boot = capture_bootstate(image, boot_insns)

    counts = {"returned": 0, "capped": 0, "faulted": 0, "exited": 0}
    long_fns = []
    spins: dict[int, dict] = {}   # spin pc -> {fn, samples, total}
    t0 = time.time()

    for fn in fns:
        plat = Aic8800D80Platform(img_path, mmio_model=model)
        plat.function_table = load_function_table(image)
        apply_bootstate(plat.mu, boot)
        ivt = plat.ivt()

        samples: list[int] = []
        counter = [0]

        def sampler(uc, address, size, user_data):
            counter[0] += 1
            if counter[0] % sample_every == 0:
                samples.append(int(address))

        h = plat.mu.hook_add(UC_HOOK_CODE, sampler)
        term, stats = plat.run(fn["address"] + HW_OFFSET, max_insns,
                               sp=ivt["stack_pointer"])
        plat.mu.hook_del(h)

        if term == "returned":
            counts["returned"] += 1
        elif term == "fault":
            counts["faulted"] += 1
        elif term == "capped":
            counts["capped"] += 1
            if samples:
                top_pc, top_n = Counter(samples).most_common(1)[0]
                frac = top_n / len(samples)
                if frac >= spin_frac and top_pc >= 0x120000:
                    spins.setdefault(top_pc, {
                        "fn": fn["name"],
                        "samples": len(samples),
                        "frac": round(frac, 3),
                    })
                else:
                    long_fns.append(fn["name"])
            else:
                long_fns.append(fn["name"])
        else:
            counts["exited"] += 1

    # Re-label each spin site with the function owning it.
    sites = []
    for pc in sorted(spins):
        s = spins[pc]
        sites.append({"pc": hex(pc), "fn": s["fn"],
                      "samples": s["samples"], "frac": s["frac"]})

    return {
        "image": image,
        "counts": counts,
        "spin_sites": sites,
        "long_fn_count": len(long_fns),
        "long_fn_sample": long_fns[:20],
        "seconds": round(time.time() - t0, 1),
    }


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--images", nargs="*", default=IMAGES)
    ap.add_argument("--max-insns", type=int, default=5000)
    ap.add_argument("--sample-every", type=int, default=100)
    ap.add_argument("--spin-frac", type=float, default=0.30)
    ap.add_argument("--boot-insns", type=int, default=50000)
    ap.add_argument("--out", type=Path, default=None)
    args = ap.parse_args()

    results = []
    for image in args.images:
        r = sweep_spins(image, args.max_insns, args.sample_every,
                        args.spin_frac, args.boot_insns)
        results.append(r)
        c = r["counts"]
        print(f"[{image}] returned={c['returned']} capped={c['capped']} "
              f"faulted={c['faulted']} exited={c['exited']} "
              f"| {len(r['spin_sites'])} spin sites | "
              f"{r['long_fn_count']} long fns | {r['seconds']}s")
        for s in r["spin_sites"]:
            print(f"    spin {s['pc']} {s['fn']} frac={s['frac']} "
                  f"samples={s['samples']}")

    if args.out:
        args.out.write_text(json.dumps(results, indent=2) + "\n")
        print(f"[spin_survey] wrote {args.out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
