#!/usr/bin/env python3
"""V15 truth lane scorer using the STRONG verifier.

Unlike v13/v14 (which used a text-based scorer), this:
  1. Reads truth_lane_targets.json (25 critical functions).
  2. For each (function, image), finds the matching behavioral_<fn>__<image>.synth.c
     in the v14 release synth directory.
  3. Runs the strong verifier (harness_v15/verifier/verify.py) on each.
  4. Outputs pass/fail counts + per-function result.

The strong verifier:
  - Rejects v13 behavior_lift templates (template_detected)
  - For leaf functions (0 BL targets, or only anonymous fcn.0xADDR targets):
    requires real register/MMIO operations in the body
  - For calling functions: at least 1 callee must match a real BL target

This scorer is the source of truth for v15. Old text-based scoring was
buggy and inflated PASS counts (or rejected real files).
"""
import json
import os
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
TRUTH_LANE_STATE = REPO / "extraction_out" / "reconstruction" / "truth_lane_state"
V14_SYNTH_DIR = REPO / "artifacts" / "releases" / "aic8800d80-rebuild-v1" / "synth"
sys.path.insert(0, str(REPO / "harness_v15"))
from verifier.verify import verify


def load_truth_targets() -> list[dict]:
    p = TRUTH_LANE_STATE / "truth_lane_targets.json"
    with p.open() as f:
        return json.load(f)


def find_behavioral_file(fn: str, image: str, v14_dir: Path) -> Path | None:
    image_noext = image.replace(".bin", "")
    candidates = list(v14_dir.glob(f"behavioral_{fn}__{image_noext}_bin.synth.c"))
    if not candidates:
        candidates = list(v14_dir.glob(f"behavioral_{fn}_*.synth.c"))
    if not candidates:
        return None
    if len(candidates) == 1:
        return candidates[0]
    best = None
    for c in candidates:
        if image_noext in c.name:
            best = c
            break
    return best or candidates[0]


def main() -> int:
    ap_arg = sys.argv[1] if len(sys.argv) > 1 and not sys.argv[1].startswith("-") else None
    ap = __import__("argparse").ArgumentParser()
    ap.add_argument("--v14-dir", default=str(V14_SYNTH_DIR))
    ap.add_argument("--out", default=str(REPO / "artifacts" / "releases" / "aic8800d80-rebuild-v1" / "scorecards" / "v15_strong_scorecard.json"))
    ap.add_argument("--targets", default=str(TRUTH_LANE_STATE / "truth_lane_targets.json"))
    args = ap.parse_args()

    targets = load_truth_targets()
    print(f"[v15_score] {len(targets)} truth-lane targets")
    v14_dir = Path(args.v14_dir)
    out_path = Path(args.out)
    out_path.parent.mkdir(parents=True, exist_ok=True)

    rows = []
    pass_n = review_n = fail_n = no_file_n = 0
    for t in targets:
        fn = t["function"]
        img = t["image"]
        addr = t.get("address", "")
        fpath = find_behavioral_file(fn, img, v14_dir)
        if not fpath:
            rows.append({"function": fn, "image": img, "address": addr, "ok": False, "reason": "no_behavioral_file", "verifier": "strong", "source": "v14_release"})
            no_file_n += 1
            continue
        body = fpath.read_text(encoding="utf-8", errors="replace")
        addr_int = int(addr, 16) if addr else 0
        if img == "fmacfw_8800d80_h_u02.bin":
            runtime_addr = 0x100000 + addr_int
        else:
            runtime_addr = 0x120000 + addr_int
        task = {
            "task_id": f"{fn}_{img}",
            "image": img,
            "binary": f"inputs/firmware/{img}",
            "address_hex": addr,
            "address_int": addr_int,
            "runtime_address_hex": hex(runtime_addr),
            "function": fn,
            "min_callees": 2,
            "min_helpers": 1,
        }
        try:
            r = verify(task, body)
        except Exception as e:
            r = {"ok": False, "reason": f"verify_exception: {e}"}
        row = {
            "function": fn,
            "image": img,
            "address": addr,
            "ok": r.get("ok", False),
            "reason": r.get("reason", "unknown"),
            "callees": r.get("callees", []),
            "is_leaf": r.get("is_leaf", False),
            "verifier": "strong",
            "source": str(fpath.relative_to(REPO)),
        }
        rows.append(row)
        if r.get("ok"):
            pass_n += 1
        else:
            fail_n += 1

    result = {
        "scorer": "v15_strong",
        "verifier_path": "harness_v15/verifier/verify.py",
        "v14_synth_dir": str(v14_dir),
        "total": len(targets),
        "pass": pass_n,
        "fail": fail_n,
        "no_file": no_file_n,
        "results": rows,
    }
    with out_path.open("w") as f:
        json.dump(result, f, indent=2)
    print(f"\n[v15_score] TOTAL: {result['total']} | PASS: {result['pass']} | FAIL: {result['fail']} | NO_FILE: {result['no_file']}")
    print(f"[v15_score] Scorecard: {out_path}")
    print()
    print(f"{'OK':<3} {'FUNCTION':<28} {'IMAGE':<35} REASON")
    for r in rows:
        ok = "✓" if r["ok"] else "✗"
        print(f"{ok:<3} {r['function']:<28} {r['image']:<35} {r['reason'][:80]}")
    return 0 if result["fail"] == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
