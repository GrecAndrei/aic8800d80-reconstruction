#!/usr/bin/env python3
"""Run one dynamic reconstruction-learning cycle.

Cycle steps:
1. Probe top queue targets with smoke_learn_loop.py and record outcomes
2. Re-run fwextract to ingest latest outcomes and produce updated learning signals
3. Emit a compact cycle report JSON for dashboarding / trend checks
"""

from __future__ import annotations

import argparse
import json
import subprocess
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path


def run(cmd: list[str], cwd: Path) -> subprocess.CompletedProcess[str]:
    return subprocess.run(cmd, cwd=cwd, text=True, capture_output=True)


def load_json(path: Path, default):
    if not path.is_file():
        return default
    try:
        return json.loads(path.read_text(encoding="utf-8", errors="ignore"))
    except json.JSONDecodeError:
        return default


def append_jsonl(path: Path, row: dict) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a", encoding="utf-8") as f:
        f.write(json.dumps(row, sort_keys=True) + "\n")


def read_last_jsonl(path: Path) -> dict:
    if not path.is_file():
        return {}
    last = ""
    with path.open("r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            if line.strip():
                last = line
    if not last:
        return {}
    try:
        return json.loads(last)
    except json.JSONDecodeError:
        return {}


def read_jsonl_rows(path: Path) -> list[dict]:
    if not path.is_file():
        return []
    out: list[dict] = []
    with path.open("r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            try:
                row = json.loads(line)
            except json.JSONDecodeError:
                continue
            if isinstance(row, dict):
                out.append(row)
    return out


def recommend_fault_seeds(outcomes_path: Path, top_n: int) -> list[str]:
    if top_n <= 0:
        return []
    counts: Counter[str] = Counter()
    for row in read_jsonl_rows(outcomes_path):
        status = str(row.get("status", "")).strip().lower()
        if status not in {"fault", "error", "failed"}:
            continue
        fault_addr = str(row.get("fault_address", "")).strip().lower()
        if not fault_addr:
            continue
        if not fault_addr.startswith("0x"):
            fault_addr = "0x" + fault_addr
        try:
            _ = int(fault_addr, 16)
        except ValueError:
            continue
        counts[fault_addr] += 1
    ranked = sorted(counts.items(), key=lambda kv: (-kv[1], kv[0]))
    return [f"{addr}=0" for addr, _ in ranked[:top_n]]


def parse_probe_summary(stdout: str) -> dict:
    summary: dict = {}
    for line in stdout.splitlines():
        line = line.strip()
        if not line.startswith("{"):
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError:
            continue
        if isinstance(row, dict) and "probe_summary" in row and isinstance(row["probe_summary"], dict):
            summary = row["probe_summary"]
    return summary


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--root", type=Path, default=Path("."), help="repo root")
    ap.add_argument("--run-root", type=Path, default=Path("extraction_out/reconstruction/mega7"), help="reconstruction run root")
    ap.add_argument("--primary-source", type=Path, required=True, help="primary C source used by smoke loop")
    ap.add_argument("--source-glob", action="append", default=[], help="additional source glob(s)")
    ap.add_argument("--limit", type=int, default=10, help="number of queue targets to probe this cycle")
    ap.add_argument("--max-insns", type=int, default=120, help="max instructions per probe")
    ap.add_argument("--min-success-insns", type=int, default=8, help="treat success below this instruction count as shallow")
    ap.add_argument("--shallow-cooldown", type=int, default=3, help="skip targets with repeated shallow-success outcomes")
    ap.add_argument("--seed", action="append", default=["0x40000000=0"], help="default seed ADDR=VALUE")
    ap.add_argument("--tag", default="", help="run tag for this cycle")
    ap.add_argument("--missing-cooldown", type=int, default=3, help="skip targets with repeated missing_symbol outcomes")
    ap.add_argument("--retry-fault-once", action="store_true", help="retry faulted probes once with learned fault seed")
    ap.add_argument("--retry-shallow-success", action="store_true", help="retry shallow successes once with higher instruction budget")
    ap.add_argument("--shallow-retry-max-insns", type=int, default=512, help="max instructions for shallow-success retry")
    ap.add_argument("--retry-capped-once", action="store_true", help="retry capped probes once with higher instruction budget")
    ap.add_argument("--capped-retry-max-insns", type=int, default=1024, help="max instructions for capped retry")
    ap.add_argument("--recent-window-min", type=int, default=30, help="skip functions attempted within this many minutes")
    ap.add_argument("--prefer-non-cycle-queue", action="store_true", help="prefer latest non-cycle queue over cycle queue")
    ap.add_argument("--auto-seed-top", type=int, default=8, help="auto-append top recurring fault-address seeds from historical outcomes")
    ap.add_argument("--embedder-model", default="", help="Path to GGUF embedding model for behavioral classification")
    args = ap.parse_args()

    root = args.root.resolve()
    run_root = (root / args.run_root).resolve()
    outcomes = run_root / "smoke_observations.jsonl"
    runs_dir = run_root / "runs"
    runs_dir.mkdir(parents=True, exist_ok=True)

    if args.tag.strip():
        tag = args.tag.strip()
    else:
        tag = "cycle_" + datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ")

    candidates = list((runs_dir).glob("*/mining_queue_top300.jsonl"))
    if not candidates:
        raise SystemExit("no mining_queue_top300.jsonl found under run root")
    candidates.sort(key=lambda p: p.stat().st_mtime)
    latest_queue = candidates[-1]
    if args.prefer_non_cycle_queue:
        non_cycle = [p for p in candidates if "cycle" not in p.parent.name.lower()]
        if non_cycle:
            latest_queue = non_cycle[-1]

    auto_seeds = recommend_fault_seeds(outcomes, args.auto_seed_top)
    merged_seeds: list[str] = []
    seen_seeds: set[str] = set()
    for seed in list(args.seed) + auto_seeds:
        key = seed.strip().lower()
        if not key or key in seen_seeds:
            continue
        seen_seeds.add(key)
        merged_seeds.append(seed)

    smoke_cmd = [
        "python3",
        "tools/smoke_learn_loop.py",
        "--source",
        str(args.primary_source),
        "--queue",
        str(latest_queue),
        "--outcomes",
        str(outcomes),
        "--readme",
        "README.md",
        "--limit",
        str(args.limit),
        "--max-insns",
        str(args.max_insns),
        "--min-success-insns",
        str(args.min_success_insns),
        "--shallow-cooldown",
        str(args.shallow_cooldown),
        "--shallow-retry-max-insns",
        str(args.shallow_retry_max_insns),
        "--missing-cooldown",
        str(args.missing_cooldown),
        "--recent-window-min",
        str(args.recent_window_min),
    ]
    if args.retry_fault_once:
        smoke_cmd.append("--retry-fault-once")
    if args.retry_shallow_success:
        smoke_cmd.append("--retry-shallow-success")
    if args.retry_capped_once:
        smoke_cmd.append("--retry-capped-once")
    smoke_cmd.extend(["--capped-retry-max-insns", str(args.capped_retry_max_insns)])
    for g in args.source_glob:
        smoke_cmd.extend(["--source-glob", g])
    for s in merged_seeds:
        smoke_cmd.extend(["--seed", s])
    if args.embedder_model:
        smoke_cmd.extend(["--embedder-model", str(args.embedder_model)])

    smoke = run(smoke_cmd, root)
    print(smoke.stdout)
    if smoke.returncode != 0:
        print(smoke.stderr)
        return smoke.returncode
    probe_summary = parse_probe_summary(smoke.stdout)

    extract_cmd = [
        "go",
        "run",
        "./cmd/fwextract",
        "-root",
        ".",
        "-out",
        str(args.run_root),
        "-run-tag",
        tag,
    ]
    ex = run(extract_cmd, root)
    print(ex.stdout)
    if ex.returncode != 0:
        print(ex.stderr)
        return ex.returncode

    run_dir = run_root / "runs" / tag
    summary = load_json(run_dir / "summary.json", {})
    learning = load_json(run_dir / "learning_signals.json", {})
    by_function = learning.get("by_function", {}) if isinstance(learning, dict) else {}
    by_prefix = learning.get("by_prefix", {}) if isinstance(learning, dict) else {}

    reason_counts: dict[str, int] = {}
    for row in by_function.values():
        if not isinstance(row, dict):
            continue
        reason = str(row.get("reason", "unknown"))
        reason_counts[reason] = reason_counts.get(reason, 0) + 1

    report = {
        "schema_version": "0.1.0",
        "tag": tag,
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "queue_source": str(latest_queue),
        "summary": summary,
        "learning_by_function_count": len(by_function),
        "learning_by_prefix_count": len(by_prefix),
        "learning_reason_counts": reason_counts,
        "learning_smoke_success_count": int(
            reason_counts.get("learned_smoke_returned", 0)
            + reason_counts.get("learned_smoke_success", 0)
        ),
        "learning_smoke_returned_count": int(reason_counts.get("learned_smoke_returned", 0)),
        "learning_smoke_capped_count": int(reason_counts.get("learned_smoke_capped", 0)),
        "outcomes_path": str(outcomes),
        "probe_summary": probe_summary,
        "recommended_seeds": auto_seeds,
        "effective_seeds": merged_seeds,
    }
    history_path = run_root / "cycle_history.jsonl"
    prev = read_last_jsonl(history_path)
    prev_func = int(prev.get("learning_by_function_count", 0)) if isinstance(prev, dict) else 0
    prev_prefix = int(prev.get("learning_by_prefix_count", 0)) if isinstance(prev, dict) else 0
    prev_success = 0
    if isinstance(prev, dict):
        if "learning_smoke_success_count" in prev:
            prev_success = int(prev.get("learning_smoke_success_count", 0))
        else:
            prev_reasons = prev.get("learning_reason_counts", {})
            if isinstance(prev_reasons, dict):
                prev_success = int(
                    prev_reasons.get("learned_smoke_returned", 0)
                    + prev_reasons.get("learned_smoke_success", 0)
                )
    report["delta_learning_by_function_count"] = len(by_function) - prev_func
    report["delta_learning_by_prefix_count"] = len(by_prefix) - prev_prefix
    report["delta_learning_smoke_success_count"] = int(report["learning_smoke_success_count"]) - prev_success
    report_path = run_dir / "cycle_report.json"
    report_path.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    append_jsonl(history_path, report)
    print(json.dumps(report, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
