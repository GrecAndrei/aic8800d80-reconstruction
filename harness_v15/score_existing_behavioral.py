#!/usr/bin/env python3
"""Score all existing behavioral synth files with the strong verifier.

Runs in the background. Writes results to out/_existing_behavioral_scorecard.json.
"""
import json
import os
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "harness_v15"))
from verifier.verify import verify

SYNTH_ROOT = REPO / "artifacts/releases/aic8800d80-rebuild-v1/synth"
TRUTH_LANE = REPO / "extraction_out/reconstruction/truth_lane_state/truth_lane_targets.json"
OUTPUT = REPO / "harness_v15/out/_existing_behavioral_scorecard.json"

FAIL_FNS = {
    'rf_hw_timer_init', 'crypto_key_load', 'crypto_hw_disable',
    'rf_mem_write', 'rf_bus_write2', 'rf_cmd_dispatch', 'rf_mem_read',
}
REVIEW_FNS = {
    'feature_guard_sdio', 'rf_reg_write_wait', 'rf_state_check',
    'rf_bus_mark', 'rf_level_apply',
}


def main() -> int:
    targets = json.loads(TRUTH_LANE.read_text())
    results = []
    t0 = time.time()
    for t in targets:
        fn = t["function"]
        img = t["image"]
        img_us = img.replace(".bin", "_bin")
        addr = int(t["address"], 16) if isinstance(t["address"], str) else t["address"]
        runtime = addr + 0x120000
        task_id = f"truth_lane_{fn}_{img_us}"
        # Find matching behavioral file
        matches = list(SYNTH_ROOT.glob(f"behavioral_{fn}__{img_us}.synth.c"))
        if not matches:
            results.append({
                "task_id": task_id, "function": fn, "image": img, "addr": f"0x{addr:x}",
                "file": None, "ok": False, "reason": "no_behavioral_file",
            })
            print(f"[{time.time()-t0:.1f}s] {fn} {img}: NO FILE", flush=True)
            continue
        f = matches[0]
        body = f.read_text()
        task = {
            "task_id": task_id,
            "image": img,
            "binary": f"inputs/firmware/{img}",
            "address_hex": f"0x{addr:x}",
            "address_int": addr,
            "runtime_address_hex": f"0x{runtime:x}",
            "function": fn,
            "min_callees": 2,
            "min_helpers": 1,
        }
        r = verify(task, body)
        results.append({
            "task_id": task_id, "function": fn, "image": img, "addr": f"0x{addr:x}",
            "file": f.name, "ok": r["ok"], "reason": r.get("reason", ""),
            "is_leaf": r.get("is_leaf", None),
            "callee_calls": r.get("callee_calls", 0),
        })
        print(f"[{time.time()-t0:.1f}s] {fn} {img}: ok={r['ok']} reason={r.get('reason','')[:60]}", flush=True)

    # Summary
    n_ok = sum(1 for r in results if r["ok"])
    n_fail = len(results) - n_ok
    summary = {
        "total": len(results), "ok": n_ok, "fail": n_fail,
        "elapsed_seconds": time.time() - t0,
        "results": results,
    }
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT.write_text(json.dumps(summary, indent=2))
    print(f"\nDONE: {n_ok}/{len(results)} pass in {time.time()-t0:.1f}s")
    print(f"Wrote {OUTPUT}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
