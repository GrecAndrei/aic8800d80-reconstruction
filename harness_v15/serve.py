#!/usr/bin/env python3
"""Live query HTTP server for the harness pipeline.

Serves on http://localhost:7777 by default.

Endpoints:
  GET /                   — index with quick stats
  GET /state              — global state (all tasks, aggregate)
  GET /state/<task_id>    — single task state
  GET /tasks              — list of all task_ids
  GET /events             — last N events (default 50)
  GET /events?since=N     — events with index > N
  GET /summary            — model-generated summary of recent activity
  GET /stats              — aggregate stats (tokens, cost, success rate)
  GET /health             — returns ok if data dir exists

Reads from:
  harness_v15/out/                       (per-task out dirs)
  harness_v15/out/.state.json            (global state, orchestrator-written)
  harness_v15/out/.events.jsonl          (global events)
"""
import argparse
import json
import os
import re
import subprocess
import sys
import time
import urllib.parse
from collections import Counter
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
DEFAULT_OUT = REPO / "harness_v15" / "out"
DEFAULT_PORT = 7777


def gather_global_state(out_root: Path) -> dict:
    """Aggregate state from all per-task state files."""
    tasks = {}
    for task_dir in sorted(out_root.iterdir()):
        if not task_dir.is_dir() or task_dir.name.startswith("."):
            continue
        state_path = task_dir / "state.json"
        if state_path.exists():
            try:
                tasks[task_dir.name] = json.loads(state_path.read_text())
            except json.JSONDecodeError:
                tasks[task_dir.name] = {"error": "state.json malformed"}
    # Global totals
    total_prompt = 0
    total_completion = 0
    total_cached = 0
    total_cost = 0.0
    n_done = 0
    n_pass = 0
    for t in tasks.values():
        if "totals" in t:
            total_prompt += t["totals"].get("prompt_tokens", 0)
            total_completion += t["totals"].get("completion_tokens", 0)
            total_cached += t["totals"].get("cached_tokens", 0)
            total_cost += t["totals"].get("cost_usd", 0)
        if t.get("phase") == "done":
            n_done += 1

    # Read result.json for pass/fail
    for task_dir in out_root.iterdir():
        if not task_dir.is_dir() or task_dir.name.startswith("."):
            continue
        rpath = task_dir / "result.json"
        if rpath.exists():
            try:
                r = json.loads(rpath.read_text())
                v = r.get("verify", {})
                if v.get("ok"):
                    n_pass += 1
            except json.JSONDecodeError:
                pass

    return {
        "out_root": str(out_root),
        "wall_now": time.time(),
        "n_tasks_total": len(tasks),
        "n_tasks_done": n_done,
        "n_tasks_pass": n_pass,
        "totals": {
            "prompt_tokens": total_prompt,
            "completion_tokens": total_completion,
            "cached_tokens": total_cached,
            "cost_usd": round(total_cost, 4),
        },
        "tasks": tasks,
    }


def gather_events(out_root: Path, since: int = 0, limit: int = 50) -> list:
    """Read events from all per-task events.jsonl files."""
    events = []
    for task_dir in sorted(out_root.iterdir()):
        if not task_dir.is_dir() or task_dir.name.startswith("."):
            continue
        epath = task_dir / "events.jsonl"
        if not epath.exists():
            continue
        try:
            with open(epath) as f:
                for line in f:
                    try:
                        ev = json.loads(line)
                        ev["_source_task"] = task_dir.name
                        events.append(ev)
                    except json.JSONDecodeError:
                        pass
        except Exception:
            pass
    events.sort(key=lambda e: e.get("ts", 0))
    return events[since:since + limit]


def build_summary(out_root: Path) -> str:
    """Build a text summary of recent activity. Cached for 10s."""
    cache_path = out_root / ".summary_cache.json"
    if cache_path.exists():
        try:
            cache = json.loads(cache_path.read_text())
            if time.time() - cache.get("ts", 0) < 10:
                return cache["text"]
        except json.JSONDecodeError:
            pass

    state = gather_global_state(out_root)
    events = gather_events(out_root, limit=200)

    # Counts
    by_type = Counter(e.get("type", "") for e in events)
    n_tasks = state["n_tasks_total"]
    n_done = state["n_tasks_done"]
    n_pass = state["n_tasks_pass"]
    total_cost = state["totals"]["cost_usd"]
    total_prompt = state["totals"]["prompt_tokens"]
    total_completion = state["totals"]["completion_tokens"]

    # Recent events (last 5)
    recent = events[-5:] if events else []
    recent_text = "\n".join(
        f"  [{e.get('iso', '?')}] {e.get('type', '?')}: {e.get('_source_task', '?')}"
        for e in recent
    ) or "  (no events yet)"

    # Per-task status
    task_lines = []
    for tid, t in sorted(state["tasks"].items()):
        phase = t.get("phase", "?")
        toks = t.get("totals", {}).get("total_tokens", 0)
        cost = t.get("totals", {}).get("cost_usd", 0)
        task_lines.append(f"  {tid[:50]:50s} {phase:12s} {toks:>10d} tok  ${cost:.4f}")
    task_text = "\n".join(task_lines) or "  (no tasks)"

    text = f"""Harness v15 Live Summary
{'='*60}
Tasks:     {n_done}/{n_tasks} done ({n_pass} pass)
Tokens:    {total_prompt + total_completion:,} total ({total_prompt:,} prompt + {total_completion:,} completion)
Cost:      ${total_cost:.4f}
Event counts: {dict(by_type)}

Recent events:
{recent_text}

Per-task status:
{task_text}
"""
    cache_path.write_text(json.dumps({"ts": time.time(), "text": text}))
    return text


class Handler(BaseHTTPRequestHandler):
    out_root: Path = DEFAULT_OUT
    server_start: float = 0.0

    def log_message(self, format, *args):  # noqa: A002
        # quieter logging
        pass

    def _send(self, status: int, body, content_type="application/json"):
        if isinstance(body, (dict, list)):
            body = json.dumps(body, indent=2)
        elif not isinstance(body, (str, bytes)):
            body = str(body)
        if isinstance(body, str):
            body = body.encode("utf-8")
        self.send_response(status)
        self.send_header("Content-Type", content_type)
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def do_GET(self):
        url = urllib.parse.urlparse(self.path)
        path = url.path
        qs = urllib.parse.parse_qs(url.query)

        if path == "/" or path == "/index":
            html = f"""<!doctype html><html><head><title>Harness v15</title></head>
<body>
<h1>Harness v15 Live</h1>
<p>Server started: {time.strftime('%Y-%m-%d %H:%M:%S', time.gmtime(self.server_start))}</p>
<ul>
  <li><a href="/state">/state</a> - global state JSON</li>
  <li><a href="/tasks">/tasks</a> - task list</li>
  <li><a href="/events">/events</a> - last 50 events</li>
  <li><a href="/events?since=10&amp;limit=20">/events?since=10&amp;limit=20</a> - events with index filter</li>
  <li><a href="/summary">/summary</a> - text summary</li>
  <li><a href="/stats">/stats</a> - aggregate stats</li>
  <li><a href="/health">/health</a> - health check</li>
</ul>
</body></html>"""
            self._send(200, html, "text/html")
        elif path == "/health":
            self._send(200, {"ok": True, "out_root": str(self.out_root),
                             "uptime": time.time() - self.server_start})
        elif path == "/state":
            self._send(200, gather_global_state(self.out_root))
        elif path == "/tasks":
            st = gather_global_state(self.out_root)
            self._send(200, {"task_ids": sorted(st["tasks"].keys())})
        elif path.startswith("/state/"):
            tid = path[len("/state/"):]
            sp = self.out_root / tid / "state.json"
            if sp.exists():
                self._send(200, json.loads(sp.read_text()))
            else:
                self._send(404, {"error": f"task not found: {tid}"})
        elif path == "/events":
            since = int(qs.get("since", ["0"])[0])
            limit = int(qs.get("limit", ["50"])[0])
            evs = gather_events(self.out_root, since=since, limit=limit)
            self._send(200, {"count": len(evs), "events": evs})
        elif path == "/summary":
            self._send(200, {"text": build_summary(self.out_root)}, "text/plain")
        elif path == "/stats":
            st = gather_global_state(self.out_root)
            self._send(200, {
                "n_tasks_total": st["n_tasks_total"],
                "n_tasks_done": st["n_tasks_done"],
                "n_tasks_pass": st["n_tasks_pass"],
                "n_tasks_fail": st["n_tasks_done"] - st["n_tasks_pass"],
                "totals": st["totals"],
                "wall_now": st["wall_now"],
            })
        else:
            self._send(404, {"error": f"unknown endpoint: {path}"})


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default=str(DEFAULT_OUT))
    ap.add_argument("--port", type=int, default=DEFAULT_PORT)
    ap.add_argument("--bind", default="127.0.0.1")
    args = ap.parse_args()

    out_root = Path(args.out)
    out_root.mkdir(parents=True, exist_ok=True)

    Handler.out_root = out_root
    Handler.server_start = time.time()

    server = ThreadingHTTPServer((args.bind, args.port), Handler)
    print(f"[serve] harness v15 query server on http://{args.bind}:{args.port}")
    print(f"[serve] reading from {out_root}")
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\n[serve] shutting down")
        server.shutdown()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
