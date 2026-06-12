#!/usr/bin/env python3
"""Model-powered summarizer for harness v15.

The summarization layer sits ABOVE the worker agents. When queried:
  1. Gathers the important events from all tasks
  2. Extracts key per-task info: synth bodies, verifier verdicts, errors
  3. Calls the model API to produce a concise narrative summary
  4. Caches the summary for 60s (configurable)

Usage:
  python3 harness_v15/summarize.py                  # one-shot summary to stdout
  python3 harness_v15/summarize.py --watch          # re-summarize every 30s
  python3 harness_v15/summarize.py --output FILE    # write to file
  python3 harness_v15/summarize.py --no-model       # skip model, raw text only
"""
import argparse
import json
import os
import re
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "harness_v15"))

from load_balancer import LoadBalancer, call_provider, make_chat_completion_payload  # noqa: E402

DEFAULT_OUT = REPO / "harness_v15" / "out"
DEFAULT_KEYS = REPO / "harness_v15" / "keys" / "keys.json"

SUMMARY_SYSTEM = """You are a meta-supervisor for a parallel firmware-decompilation pipeline.
You will receive a digest of what N workers have done in the last period. Produce
a CONCISE summary (under 500 words) for the human orchestrator.

Structure:
  - **Overall progress**: X/Y tasks done, Z pass, W fail
  - **Cost & tokens**: $X.XX, X.XM tokens
  - **Per-task highlights**: for each completed task, what was achieved or what failed
  - **Patterns/issues**: any common problems (e.g., all leaf functions have 0 tools, API errors, etc.)
  - **Recommendations**: concrete next steps

Be specific. Cite task IDs. Note if a task is stuck or has a real problem.
"""


def gather_digest(out_root: Path, max_tasks: int = 30) -> dict:
    """Gather a digest of the most important info from all tasks."""
    digest = {
        "n_tasks": 0,
        "tasks_done": 0,
        "tasks_pass": 0,
        "tasks_fail": 0,
        "tasks_in_progress": 0,
        "totals": {"prompt_tokens": 0, "completion_tokens": 0, "cached_tokens": 0, "cost_usd": 0.0},
        "errors": [],
        "highlights": [],
    }

    task_dirs = sorted([d for d in out_root.iterdir() if d.is_dir() and not d.name.startswith(".")])
    digest["n_tasks"] = len(task_dirs)

    for td in task_dirs[-max_tasks:]:
        rpath = td / "result.json"
        spath = td / "state.json"
        if spath.exists():
            try:
                s = json.loads(spath.read_text())
                t = s.get("totals", {})
                digest["totals"]["prompt_tokens"] += t.get("prompt_tokens", 0)
                digest["totals"]["completion_tokens"] += t.get("completion_tokens", 0)
                digest["totals"]["cached_tokens"] += t.get("cached_tokens", 0)
                digest["totals"]["cost_usd"] += t.get("cost_usd", 0)
                if s.get("phase") == "done":
                    digest["tasks_done"] += 1
                else:
                    digest["tasks_in_progress"] += 1
            except json.JSONDecodeError:
                pass
        if rpath.exists():
            try:
                r = json.loads(rpath.read_text())
                v = r.get("verify", {})
                if v.get("ok"):
                    digest["tasks_pass"] += 1
                else:
                    digest["tasks_fail"] += 1
                # Highlight
                if v.get("ok"):
                    synth_chars = r.get("total_tokens", 0)
                    digest["highlights"].append({
                        "task": td.name,
                        "status": "pass",
                        "reason": v.get("reason", "")[:80],
                        "tokens": r.get("total_tokens", 0),
                    })
                else:
                    digest["highlights"].append({
                        "task": td.name,
                        "status": "fail",
                        "reason": v.get("reason", "")[:200],
                    })
            except json.JSONDecodeError:
                pass

    # Recent errors from telemetry
    for td in task_dirs[-max_tasks:]:
        tpath = td / "telemetry.json"
        if tpath.exists():
            try:
                t = json.loads(tpath.read_text())
                for err in t.get("api_errors", [])[-3:]:
                    digest["errors"].append({
                        "task": td.name,
                        "iter": err.get("iter"),
                        "error": err.get("error", "")[:150],
                    })
            except json.JSONDecodeError:
                pass

    digest["totals"]["cost_usd"] = round(digest["totals"]["cost_usd"], 4)
    return digest


def digest_to_prompt(digest: dict) -> str:
    """Format digest as a user prompt for the model."""
    t = digest["totals"]
    lines = [
        f"# Pipeline digest",
        f"Tasks: {digest['n_tasks']} total, {digest['tasks_done']} done, {digest['tasks_in_progress']} in-progress",
        f"  - {digest['tasks_pass']} PASS, {digest['tasks_fail']} FAIL",
        f"Tokens: {t['prompt_tokens']:,} prompt + {t['completion_tokens']:,} completion = {t['prompt_tokens'] + t['completion_tokens']:,} total",
        f"  (cached: {t['cached_tokens']:,})",
        f"Cost: ${t['cost_usd']:.4f}",
        "",
        f"# Per-task highlights ({len(digest['highlights'])})",
    ]
    for h in digest["highlights"][-20:]:
        status = h["status"].upper()
        lines.append(f"  [{status}] {h['task']}: {h.get('reason', '')[:120]}")
    if digest["errors"]:
        lines.append("")
        lines.append(f"# Recent API errors ({len(digest['errors'])})")
        for e in digest["errors"][-10:]:
            lines.append(f"  [{e['task']} iter {e['iter']}]: {e['error']}")
    return "\n".join(lines)


def call_summarizer(digest: dict, keys_path: Path) -> str | None:
    """Call the model to summarize. Returns the summary text or None on failure."""
    if not keys_path.exists():
        return None
    lb = LoadBalancer(keys_path)
    ks = lb.acquire()
    if not ks:
        return None
    prompt = digest_to_prompt(digest)
    payload = make_chat_completion_payload(
        system=SUMMARY_SYSTEM,
        user=prompt,
        model=ks.provider["model"],
        max_tokens=2000,
        temperature=0.2,
    )
    ok, text, err = call_provider(ks, payload, timeout=120.0)
    if ok:
        return text
    print(f"[summarize] API error: {err}", file=sys.stderr)
    return None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default=str(DEFAULT_OUT))
    ap.add_argument("--keys", default=str(DEFAULT_KEYS))
    ap.add_argument("--watch", action="store_true", help="re-summarize periodically")
    ap.add_argument("--interval", type=int, default=30)
    ap.add_argument("--output", default=None, help="write to file (e.g., harness_v15/SUMMARY.md)")
    ap.add_argument("--no-model", action="store_true", help="skip model, just print raw digest")
    args = ap.parse_args()

    out_root = Path(args.out)
    out_root.mkdir(parents=True, exist_ok=True)
    keys_path = Path(args.keys)

    def do_one():
        digest = gather_digest(out_root)
        if args.no_model:
            output = digest_to_prompt(digest)
        else:
            output = call_summarizer(digest, keys_path) or digest_to_prompt(digest)
        if args.output:
            Path(args.output).write_text(output)
            print(f"[summarize] wrote {args.output}")
        else:
            print(output)
        return output

    if args.watch:
        print(f"[summarize] watching {out_root} every {args.interval}s (Ctrl-C to stop)")
        try:
            while True:
                do_one()
                time.sleep(args.interval)
        except KeyboardInterrupt:
            print("\n[summarize] stopped")
    else:
        do_one()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
