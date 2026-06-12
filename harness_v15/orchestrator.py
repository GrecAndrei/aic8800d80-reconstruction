#!/usr/bin/env python3
"""Orchestrator: distribute tasks across N parallel workers.

Each worker is a subprocess running worker.py on one task. We spawn up
to N workers at a time, each with its own output dir and its own key
(rotated by the load balancer inside worker.py).

Usage:
  python3 harness_v15/orchestrator.py \\
    --tasks harness_v15/tasks/ \\
    --out harness_v15/out/ \\
    --config harness_v15/keys/keys.json \\
    --max-workers 10
"""
import argparse
import json
import os
import subprocess
import sys
import time
from concurrent.futures import ProcessPoolExecutor, as_completed
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]


def run_one(args_tuple):
    """Worker entry: run worker.py on one task, return (task_id, ok, log_path).

    Uses python -u for unbuffered output, streams stdout/stderr to log file
    in real-time (not captured until completion).
    """
    import select
    task_path, out_dir, config_path, max_retries = args_tuple
    cmd = [
        sys.executable, "-u",  # unbuffered
        str(REPO / "harness_v15" / "workers" / "worker.py"),
        "--task", str(task_path),
        "--out", str(out_dir),
        "--config", str(config_path),
        "--max-retries", str(max_retries),
    ]
    log_path = out_dir / "worker.log"
    out_dir.mkdir(parents=True, exist_ok=True)
    try:
        with open(log_path, "w", buffering=1) as logf:  # line-buffered
            proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, bufsize=1)
            assert proc.stdout is not None
            # NO TIMEOUT. Let workers run as long as they need.
            for line in proc.stdout:
                logf.write(line)
                logf.flush()
            proc.wait()
        return (task_path.stem, proc.returncode == 0, str(log_path))
    except Exception as e:
        return (task_path.stem, False, f"error: {e}")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--tasks", required=True, help="dir of task JSONs")
    ap.add_argument("--out", required=True, help="output root dir")
    ap.add_argument("--config", required=True, help="keys.json")
    ap.add_argument("--max-workers", type=int, default=10)
    ap.add_argument("--max-retries", type=int, default=2)
    ap.add_argument("--filter", default="", help="only run tasks starting with this prefix")
    args = ap.parse_args()

    tasks_dir = Path(args.tasks)
    out_root = Path(args.out)
    out_root.mkdir(parents=True, exist_ok=True)

    task_files = sorted(tasks_dir.glob("*.json"))
    if args.filter:
        task_files = [t for t in task_files if t.stem.startswith(args.filter)]

    print(f"[orchestrator] {len(task_files)} tasks, {args.max_workers} workers")
    job_args = []
    for tf in task_files:
        out_dir = out_root / tf.stem
        job_args.append((tf, out_dir, Path(args.config), args.max_retries))

    results = []
    t0 = time.time()
    with ProcessPoolExecutor(max_workers=args.max_workers) as pool:
        futures = {pool.submit(run_one, ja): ja[0].stem for ja in job_args}
        for fut in as_completed(futures):
            task_id = futures[fut]
            try:
                tid, ok, log = fut.result()
            except Exception as e:
                tid, ok, log = task_id, False, f"submission error: {e}"
            results.append((tid, ok, log))
            elapsed = time.time() - t0
            print(f"[orchestrator] {tid}: {'OK' if ok else 'FAIL'} ({elapsed:.1f}s elapsed)")

    # Summary
    ok_count = sum(1 for _, ok, _ in results if ok)
    fail_count = len(results) - ok_count
    print(f"\n[orchestrator] DONE: {ok_count} ok, {fail_count} fail in {time.time()-t0:.1f}s")

    # Aggregate
    summary = {
        "total": len(results),
        "ok": ok_count,
        "fail": fail_count,
        "elapsed_seconds": time.time() - t0,
        "results": [
            {"task_id": tid, "ok": ok, "log": log}
            for tid, ok, log in results
        ],
    }
    (out_root / "summary.json").write_text(json.dumps(summary, indent=2))
    print(f"[orchestrator] wrote {out_root / 'summary.json'}")
    return 0 if fail_count == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
