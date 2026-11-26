#!/usr/bin/env python3
"""Scaled gpt-6-luna batch pipeline — corpus-wide LLM analysis at flat rate.

Generic concurrent batch runner over the Codex subscription backend
(tools/codex_backend.py). Jobs are JSONL manifests; each job is a dict with:
  key          unique cache key (filename-safe)
  instructions system instructions
  prompt       user prompt
  effort       reasoning effort (default: max — flat-rate, quality first)
  meta         arbitrary payload copied into the result file

Results are written to <outdir>/<key>.json with skip-if-exists resume, in
the harness_v17 names-cache convention. No concurrency limits exist on the
subscription side (verified with the owner); default workers=16.

Usage:
  python3 tools/luna_batch.py manifest.jsonl outdir [--workers 16] [--limit N]
"""
import json
import sys
import time
import os
import argparse
import threading
from concurrent.futures import ThreadPoolExecutor, as_completed

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from codex_backend import complete, load_tokens

write_lock = threading.Lock()


def run_job(job, outdir, tokens, backend="codex"):
    key = job["key"]
    path = os.path.join(outdir, f"{key}.json")
    if os.path.exists(path):
        return key, "cached"
    instr = job.get("instructions", "You are a firmware reverse-engineering expert.")
    # transient-failure backoff: timeouts, 429 rate limits, 5xx and
    # connection resets MUST NOT freeze as permanent error records under
    # skip-if-exists — retry with generous exponential backoff matched to
    # xhigh-grade latency. Only after exhaustion is the error recorded.
    last_err = None
    text = None
    for attempt in range(4):
        try:
            if backend == "qwen":
                # qwen3.8-flash: xhigh is the top effort tier (no 'max'); the
                # shared mega-prefix rides the system message with an explicit
                # cache breakpoint — deterministic 10% hits sustained by the
                # batch's own traffic (5-min TTL resets on hit)
                from qwen_backend import complete as qcomplete
                effort = {"max": "xhigh"}.get(job.get("effort", "max"), job.get("effort", "xhigh"))
                text, _usage = qcomplete(job["prompt"], instr, effort=effort,
                                         max_tokens=8192, explicit_cache=True)
            else:
                text = complete(
                    job["prompt"],
                    instructions=instr,
                    reasoning_effort=job.get("effort", "max"),
                    tokens=tokens)
            break
        except Exception as e:
            last_err = e
            msg = str(e).lower()
            transient = any(k in msg for k in (
                "timed out", "timeout", "429", "rate", "reset", "refused",
                "502", "503", "504", "500", "connection"))
            if not transient or attempt == 3:
                break
            time.sleep(min(20 * (3 ** attempt), 240))  # 20s, 60s, 180s
    if text is not None:
        rec = dict(job.get("meta", {}))
        rec.update({"key": key, "status": "ok", "text": text})
    else:
        e = last_err
        rec = dict(job.get("meta", {}))
        rec.update({"key": key, "status": "error", "error": str(e)[:300]})
    tmp = path + ".tmp"
    with write_lock:
        with open(tmp, "w") as f:
            json.dump(rec, f, indent=1)
        os.replace(tmp, path)
    return key, rec["status"]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("manifest")
    ap.add_argument("outdir")
    ap.add_argument("--workers", type=int, default=16)
    ap.add_argument("--backend", default="codex", choices=["codex", "qwen"])
    ap.add_argument("--limit", type=int, default=0)
    args = ap.parse_args()

    os.makedirs(args.outdir, exist_ok=True)
    jobs = [json.loads(l) for l in open(args.manifest) if l.strip()]
    # skip already-cached before scheduling
    pending = [j for j in jobs if not os.path.exists(os.path.join(args.outdir, f"{j['key']}.json"))]
    if args.limit:
        pending = pending[:args.limit]
    tokens = load_tokens()
    print(f"{len(jobs)} jobs in manifest, {len(pending)} pending, {args.workers} workers")

    done = err = 0
    with ThreadPoolExecutor(max_workers=args.workers) as ex:
        futs = {ex.submit(run_job, j, args.outdir, tokens, args.backend): j for j in pending}
        for fut in as_completed(futs):
            key, status = fut.result()
            if status == "ok":
                done += 1
            elif status == "error":
                err += 1
            total = done + err
            if total % 50 == 0:
                print(f"  progress: {total}/{len(pending)} ({err} errors)", flush=True)
    print(f"complete: {done} ok, {err} errors of {len(pending)} pending")


if __name__ == "__main__":
    main()
