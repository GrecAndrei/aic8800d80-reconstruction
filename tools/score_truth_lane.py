#!/usr/bin/env python3
"""Run fwimplsynth on the 25 truth-lane functions and produce a scorecard.

This script:
  1. Reads truth_lane_targets.json (the 25 critical functions).
  2. Filters the full implementation queue to just those functions.
  3. Writes a focused implementation_queue.json under a scratch dir.
  4. Invokes fwimplsynth against the existing run-root (which already
     has all the descriptors, edges, cfg, pseudocode).
  5. Reads the generated C for each function and scores:
     - callee_calls: number of `<name>();` calls in the body
     - motif_match: motif family extracted from the comment header
     - has_helpers: any name-derived helpers (rf_bus_write, crypto_hw_*, ...)
     - risk_class: passed through from synth evidence row
  6. Writes the per-function scorecard JSON + a markdown summary.

Usage: tools/score_truth_lane.py <run_root> [--out-dir OUT]
"""
import argparse
import json
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
TRUTH_LANE_STATE = REPO / "extraction_out/reconstruction/truth_lane_state"
DEFAULT_RUN_ROOT = REPO / "extraction_out/reconstruction/mega7"
FWIMPLSYNTH = REPO / "bin" / "fwimplsynth"

CALLEE_RE = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(\s*\)\s*;", re.MULTILINE)
MOTIF_COMMENT_RE = re.compile(r"//\s*Descriptor motif:\s*([A-Za-z_]+)")


def load_truth_targets() -> list[dict]:
    p = TRUTH_LANE_STATE / "truth_lane_targets.json"
    return json.loads(p.read_text())


def filter_implqueue(targets: list[dict], src_queue: Path, dst_queue: Path) -> list[dict]:
    """Filter the implementation queue to just truth-lane functions."""
    data = json.loads(src_queue.read_text())
    wanted = {(t["image"], t["address"], t["function"]) for t in targets}
    name_wanted = {t["function"] for t in targets}
    keep = []
    for row in data:
        key = (row.get("image", ""), row.get("address", ""), row.get("function", ""))
        if key in wanted or row.get("function", "") in name_wanted:
            keep.append(row)
    dst_queue.parent.mkdir(parents=True, exist_ok=True)
    dst_queue.write_text(json.dumps(keep, indent=2))
    return keep


def run_synth(run_root: Path, focused_queue: Path, out_dir: Path) -> int:
    """Run fwimplsynth on the focused queue. Returns exit code."""
    cmd = [
        str(FWIMPLSYNTH),
        "-run-root", str(run_root),
        "-implqueue", str(focused_queue),
        "-out", str(out_dir / "synth"),
        "-max-tasks", "0",  # use all tasks in the focused queue
        "-include-dependencies=false",
    ]
    print(f"[score_truth_lane] running: {' '.join(cmd)}", file=sys.stderr)
    return subprocess.call(cmd, cwd=REPO)


def read_body(out_dir: Path, fn: str) -> str | None:
    """Locate the generated C for a function. Naming is the synth-side naming."""
    # The synth writes <out_dir>/synth/<NNN>_<fn>.synth.c. Walk recursively.
    synth_dir = out_dir / "synth"
    if not synth_dir.exists():
        return None
    safe = re.sub(r"[^A-Za-z0-9_]", "_", fn)
    candidates = [
        synth_dir / f"{safe}.synth.c",
        synth_dir / f"{fn}.synth.c",
        synth_dir / f"{safe}.c",
        synth_dir / f"{fn}.c",
    ]
    for c in candidates:
        if c.exists():
            return c.read_text(errors="replace")
    # Fallback: find a file whose comment header names this function
    # (e.g. "task=backfill_<fn>") rather than just contains it as a forward
    # decl. We disallow forward decls (line ending in `;`) by requiring the
    # function definition body to start with `{` after the parameter list.
    defn_pat = re.compile(
        rf"task=backfill_{re.escape(fn)}\b|^\s*void\s+{re.escape(fn)}\s*\([^)]*\)\s*\{{",
        re.MULTILINE,
    )
    for c in synth_dir.rglob("*.synth.c"):
        head = c.read_text(errors="replace")[:2000]
        if defn_pat.search(head):
            return c.read_text(errors="replace")
    for c in synth_dir.rglob("*.c"):
        head = c.read_text(errors="replace")[:2000]
        if defn_pat.search(head):
            return c.read_text(errors="replace")
    return None


def score_body(body: str | None, fn: str) -> dict:
    if not body:
        return {
            "callee_calls": 0,
            "motif_match": "",
            "has_helpers": [],
            "notes": ["no_body_generated"],
        }
    callees = set()
    for m in CALLEE_RE.finditer(body):
        callees.add(m.group(1))
    callees.discard(fn)
    motif = ""
    mm = MOTIF_COMMENT_RE.search(body)
    if mm:
        motif = mm.group(1)
    # Known helpful callees for truth-lane functions.
    helpful_keywords = (
        "rf_bus_write", "rf_reg_write", "rf_reg_read", "rf_bus_read",
        "rf_bus_reset", "rf_mem_write", "rf_mem_read", "rf_state_",
        "rf_level_", "rf_cmd_", "rf_msg_", "rf_hw_",
        "crypto_hw_", "crypto_key_", "crypto_reg_", "crypto_mac_",
        "crypto_state_", "crypto_table_",
        "timer_init", "log_tick", "timestamp_update", "log_system_init",
        "log_hw_init", "log_global_init", "log_pool_init",
        "clock_calc", "feature_guard_sdio", "firmware_init",
        "fw_config_apply", "math_round", "msg_parse",
    )
    helpers = sorted(c for c in callees if any(k in c for k in helpful_keywords))
    notes = []
    if len(callees) == 0:
        notes.append("no_callee_calls")
    if not helpers:
        notes.append("no_known_helpers")
    return {
        "callee_calls": len(callees),
        "callees": sorted(callees),
        "motif_match": motif,
        "has_helpers": helpers,
        "notes": notes,
    }


def classify(result: dict) -> str:
    """PASS if has real callee calls + helpers, REVIEW if has callees but no helpers, FAIL otherwise."""
    if result.get("callee_calls", 0) >= 2 and len(result.get("has_helpers", [])) >= 1:
        return "PASS"
    if result.get("callee_calls", 0) >= 1:
        return "REVIEW"
    return "FAIL"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--run-root", default=str(DEFAULT_RUN_ROOT))
    ap.add_argument("--out-dir", default=str(REPO / "extraction_out/reconstruction/truth_lane_eval"))
    ap.add_argument("--label", default="truth_lane_eval")
    ap.add_argument("--skip-synth", action="store_true",
                    help="Reuse existing synth output and only rescore.")
    args = ap.parse_args()

    run_root = Path(args.run_root)
    out_dir = Path(args.out_dir) / args.label
    out_dir.mkdir(parents=True, exist_ok=True)

    targets = load_truth_targets()
    print(f"[score_truth_lane] {len(targets)} truth-lane targets", file=sys.stderr)

    src_queue = run_root / "implqueue" / "implementation_queue.json"
    focused_queue = out_dir / "implementation_queue_truth_lane.json"

    if not args.skip_synth:
        keep = filter_implqueue(targets, src_queue, focused_queue)
        print(f"[score_truth_lane] filtered queue: {len(keep)} tasks", file=sys.stderr)
        rc = run_synth(run_root, focused_queue, out_dir)
        if rc != 0:
            print(f"[score_truth_lane] synth rc={rc}", file=sys.stderr)
            return rc
    else:
        print("[score_truth_lane] --skip-synth: reusing existing output", file=sys.stderr)

    rows = []
    pass_n = review_n = fail_n = 0
    for t in targets:
        fn = t["function"]
        body = read_body(out_dir, fn)
        result = score_body(body, fn)
        klass = classify(result)
        if klass == "PASS":
            pass_n += 1
        elif klass == "REVIEW":
            review_n += 1
        else:
            fail_n += 1
        row = {
            "function": fn,
            "image": t["image"],
            "address": t["address"],
            "motif_family": t.get("motif_family", ""),
            "phenotype": t.get("phenotype", ""),
            "behavior_role": t.get("behavior_role", ""),
            "score": {"PASS": 5, "REVIEW": 3, "FAIL": 1}[klass],
            "class": klass,
            "callee_calls": result["callee_calls"],
            "has_helpers": result.get("has_helpers", []),
            "callees": result.get("callees", []),
            "motif_match": result.get("motif_match", ""),
            "notes": result.get("notes", []),
        }
        rows.append(row)

    scorecard = {
        "schema_version": "0.1.0",
        "label": args.label,
        "summary": {
            "total": len(rows),
            "pass": pass_n,
            "review": review_n,
            "fail": fail_n,
        },
        "rows": rows,
    }
    out_json = out_dir / "scorecard.json"
    out_json.write_text(json.dumps(scorecard, indent=2))
    print(f"[score_truth_lane] wrote {out_json}", file=sys.stderr)

    # Markdown summary
    md = out_dir / "scorecard.md"
    lines = [f"# Truth Lane Scorecard ({args.label})", ""]
    s = scorecard["summary"]
    lines.append(f"PASS={s['pass']} REVIEW={s['review']} FAIL={s['fail']} total={s['total']}")
    lines.append("")
    for r in rows:
        lines.append(
            f"- [{r['class']}] {r['function']} ({r['image']} {r['address']}) "
            f"| motif={r['motif_family']} | pheno={r['phenotype']} | "
            f"callees={r['callee_calls']} | helpers={','.join(r['has_helpers']) or '-'} | "
            f"notes={','.join(r['notes']) or '-'}"
        )
    md.write_text("\n".join(lines) + "\n")
    print(f"[score_truth_lane] wrote {md}", file=sys.stderr)
    print(json.dumps(scorecard["summary"]))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
