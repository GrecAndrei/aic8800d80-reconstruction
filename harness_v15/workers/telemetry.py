#!/usr/bin/env python3
"""Per-task + global telemetry for the worker harness.

Tracks per-iteration:
  - prompt_tokens / completion_tokens / cached_tokens
  - TTFT (time to first byte, if available)
  - context_chars (size of messages sent)
  - tool_calls_count, tool_results_chars
  - thinking_chars (raw <think> content)
  - key used, latency
  - finished reason (tool_calls | stop | length)

Tracks pricing (MiniMax-M3):
  - <= 512K input: $0.30/M input, $1.20/M output, $0.06/M cached
  -  > 512K input: $0.60/M input, $2.40/M output, $0.12/M cached

Streams events to:
  - per-task:  <out_dir>/events.jsonl   (append-only)
  - per-task:  <out_dir>/state.json     (atomic snapshot)
  - global:    <out_root>/.events.jsonl (orchestrator-managed)
  - global:    <out_root>/.state.json   (orchestrator-managed)
"""
import json
import os
import tempfile
import time
from dataclasses import dataclass, field, asdict
from pathlib import Path
from typing import Any


# MiniMax-M3 pricing (per 1M tokens)
PRICING = {
    "MiniMax-M3": {
        "input_under_512k": 0.30,
        "output_under_512k": 1.20,
        "cached_under_512k": 0.06,
        "input_over_512k": 0.60,
        "output_over_512k": 2.40,
        "cached_over_512k": 0.12,
    }
}


def estimate_cost(prompt_tokens: int, completion_tokens: int, cached_tokens: int,
                  model: str = "MiniMax-M3") -> float:
    """Estimate USD cost for an API call."""
    rates = PRICING.get(model, PRICING["MiniMax-M3"])
    if prompt_tokens > 512_000:
        in_r, out_r, cache_r = rates["input_over_512k"], rates["output_over_512k"], rates["cached_over_512k"]
    else:
        in_r, out_r, cache_r = rates["input_under_512k"], rates["output_under_512k"], rates["cached_under_512k"]
    non_cached = max(0, prompt_tokens - cached_tokens)
    cost = (non_cached / 1_000_000) * in_r
    cost += (cached_tokens / 1_000_000) * cache_r
    cost += (completion_tokens / 1_000_000) * out_r
    return cost


def atomic_write_json(path: Path, obj: Any):
    """Write JSON atomically: write to .tmp then rename."""
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, tmp_path = tempfile.mkstemp(dir=path.parent, prefix=".tmp_", suffix=".json")
    try:
        with os.fdopen(fd, "w") as f:
            json.dump(obj, f, indent=2)
        os.replace(tmp_path, path)
    except Exception:
        if os.path.exists(tmp_path):
            os.unlink(tmp_path)
        raise


def append_event(path: Path, event: dict):
    """Append a single event to a JSONL file (one event per line)."""
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "a") as f:
        f.write(json.dumps(event) + "\n")


@dataclass
class IterationRecord:
    iter_idx: int
    prompt_tokens: int = 0
    completion_tokens: int = 0
    cached_tokens: int = 0
    total_tokens: int = 0
    context_chars: int = 0
    tool_calls_count: int = 0
    thinking_chars: int = 0
    content_chars: int = 0
    key_name: str = ""
    latency_seconds: float = 0.0
    finished: str = ""  # "tool_calls" | "stop" | "length" | ""
    cost_usd: float = 0.0


@dataclass
class ToolUsage:
    name: str
    count: int = 0
    total_chars_returned: int = 0
    total_latency: float = 0.0


@dataclass
class PhaseRecord:
    name: str
    start: float = 0.0
    end: float = 0.0

    @property
    def duration(self) -> float:
        return self.end - self.start if self.end else 0.0


class Telemetry:
    """Per-task telemetry recorder with streaming event output."""

    def __init__(self, task_id: str, out_dir: Path):
        self.task_id = task_id
        self.out_dir = out_dir
        self.t_start = time.time()
        self.iterations: list[IterationRecord] = []
        self.phases: dict[str, PhaseRecord] = {}
        self.tool_usage: dict[str, ToolUsage] = {}
        self.events_path = out_dir / "events.jsonl"
        self.state_path = out_dir / "state.json"
        self.api_errors: list[dict] = []
        self.events_path.parent.mkdir(parents=True, exist_ok=True)
        # Truncate any prior events file
        self.events_path.write_text("")
        self._emit_event("task_start", {"task_id": task_id, "out_dir": str(out_dir)})

    def _emit_event(self, event_type: str, data: dict):
        event = {
            "ts": time.time(),
            "iso": time.strftime("%Y-%m-%dT%H:%M:%S", time.gmtime()) + f".{int((time.time()%1)*1000):03d}Z",
            "task_id": self.task_id,
            "type": event_type,
            "data": data,
        }
        append_event(self.events_path, event)
        # Update state atomically
        self.save_state()

    def start_phase(self, name: str):
        self.phases[name] = PhaseRecord(name=name, start=time.time())
        self._emit_event("phase_start", {"phase": name})

    def end_phase(self, name: str):
        if name in self.phases:
            self.phases[name].end = time.time()
            dur = self.phases[name].duration
            self._emit_event("phase_end", {"phase": name, "duration": dur})

    def record_iteration(self, *, iter_idx: int, prompt_tokens: int, completion_tokens: int,
                         total_tokens: int, tool_calls_count: int, key_name: str,
                         latency_seconds: float, context_chars: int = 0,
                         finished: str = "", thinking_chars: int = 0,
                         content_chars: int = 0, cached_tokens: int = 0):
        cost = estimate_cost(prompt_tokens, completion_tokens, cached_tokens)
        rec = IterationRecord(
            iter_idx=iter_idx,
            prompt_tokens=prompt_tokens,
            completion_tokens=completion_tokens,
            cached_tokens=cached_tokens,
            total_tokens=total_tokens,
            context_chars=context_chars,
            tool_calls_count=tool_calls_count,
            thinking_chars=thinking_chars,
            content_chars=content_chars,
            key_name=key_name,
            latency_seconds=latency_seconds,
            finished=finished,
            cost_usd=cost,
        )
        self.iterations.append(rec)
        self._emit_event("api_response", {
            "iter": iter_idx,
            "prompt_tokens": prompt_tokens,
            "completion_tokens": completion_tokens,
            "cached_tokens": cached_tokens,
            "total_tokens": total_tokens,
            "thinking_chars": thinking_chars,
            "content_chars": content_chars,
            "context_chars": context_chars,
            "key": key_name,
            "latency": latency_seconds,
            "finished": finished,
            "cost_usd": round(cost, 6),
        })

    def record_tool(self, name: str, args_chars: int = 0, result_chars: int = 0,
                    latency: float = 0.0):
        if name not in self.tool_usage:
            self.tool_usage[name] = ToolUsage(name=name)
        self.tool_usage[name].count += 1
        self.tool_usage[name].total_chars_returned += result_chars
        self.tool_usage[name].total_latency += latency
        self._emit_event("tool_call", {
            "tool": name,
            "args_chars": args_chars,
            "result_chars": result_chars,
            "latency": latency,
        })

    def record_api_error(self, iter_idx: int, error: str, key: str = ""):
        self.api_errors.append({"iter": iter_idx, "error": error, "key": key, "ts": time.time()})
        self._emit_event("api_error", {"iter": iter_idx, "error": error, "key": key})

    def finish(self, ok: bool, reason: str, synth_chars: int = 0):
        total_cost = sum(r.cost_usd for r in self.iterations)
        self._emit_event("task_end", {
            "ok": ok,
            "reason": reason,
            "wall_total": time.time() - self.t_start,
            "total_cost_usd": round(total_cost, 4),
            "synth_chars": synth_chars,
        })
        self.save_state()
        self.save_telemetry()

    def save_state(self):
        """Atomic snapshot for live query."""
        total_prompt = sum(r.prompt_tokens for r in self.iterations)
        total_completion = sum(r.completion_tokens for r in self.iterations)
        total_cached = sum(r.cached_tokens for r in self.iterations)
        total_cost = sum(r.cost_usd for r in self.iterations)
        state = {
            "task_id": self.task_id,
            "wall_elapsed": time.time() - self.t_start,
            "phase": self._current_phase(),
            "iterations_completed": len(self.iterations),
            "totals": {
                "prompt_tokens": total_prompt,
                "completion_tokens": total_completion,
                "cached_tokens": total_cached,
                "total_tokens": total_prompt + total_completion,
                "cost_usd": round(total_cost, 4),
                "tools_used": {n: {"count": u.count, "chars": u.total_chars_returned}
                               for n, u in self.tool_usage.items()},
            },
            "current_iteration": self.iterations[-1] if self.iterations else None,
        }
        # Make current_iteration JSON-serializable
        if state["current_iteration"] is not None:
            state["current_iteration"] = asdict(state["current_iteration"])
        atomic_write_json(self.state_path, state)

    def _current_phase(self) -> str:
        for name, p in self.phases.items():
            if p.end == 0.0:
                return name
        return "done" if self.iterations else "init"

    def save_telemetry(self):
        """Full telemetry JSON for archival."""
        total_prompt = sum(r.prompt_tokens for r in self.iterations)
        total_completion = sum(r.completion_tokens for r in self.iterations)
        total_cached = sum(r.cached_tokens for r in self.iterations)
        total_cost = sum(r.cost_usd for r in self.iterations)
        data = {
            "task_id": self.task_id,
            "wall_total_seconds": time.time() - self.t_start,
            "iterations": [asdict(r) for r in self.iterations],
            "phases": {n: {"start": p.start, "end": p.end, "duration": p.duration}
                       for n, p in self.phases.items()},
            "totals": {
                "iterations": len(self.iterations),
                "total_prompt_tokens": total_prompt,
                "total_completion_tokens": total_completion,
                "total_cached_tokens": total_cached,
                "total_tokens": total_prompt + total_completion,
                "estimated_cost_usd": round(total_cost, 4),
                "tools_used": {n: asdict(u) for n, u in self.tool_usage.items()},
            },
            "api_errors": self.api_errors,
        }
        atomic_write_json(self.out_dir / "telemetry.json", data)


def count_message_chars(messages: list[dict]) -> int:
    """Estimate the total character count of a messages list (for context tracking)."""
    total = 0
    for m in messages:
        c = m.get("content")
        if isinstance(c, str):
            total += len(c)
        tcs = m.get("tool_calls") or []
        for tc in tcs:
            args = tc.get("function", {}).get("arguments", "")
            total += len(args)
    return total


def extract_thinking_chars(raw_text: str) -> int:
    """Count characters in <think>...</think> blocks (raw, unstripped)."""
    import re
    matches = re.findall(r"<think>.*?</think>", raw_text, flags=re.DOTALL)
    return sum(len(m) for m in matches)
