#!/usr/bin/env python3
"""Materialize the LLM register classifications into the emulator's behavioral
MMIO model (src/include/aic8800d80_mmio_behavior.json).

Rules (deterministic; the LLM never writes code):
  - Every classified register is recorded with name/role/confidence/source.
  - Behavioral rules are applied ONLY to dynamic-source registers whose
    confidence >= BEHAVIOR_MIN_CONF, and only for the rule types the emulator
    can act on: poll (status register a poller waits on -> become ready after
    ~N reads) and strobe (write self-clears after N instructions).
  - "none" and "echo" are recorded but not acted on: the emulator's default
    phantom already returns last-written on read (echo) / zero on fresh read.
  - Static-source registers (only seen in a constant pool) are never given
    behavior, regardless of the LLM's claim.
"""
from __future__ import annotations

import argparse
import json
import re
from datetime import datetime, timezone
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent

DEFAULT_CLASS = REPO / "build" / "mmio" / "classifications.json"
DEFAULT_EVIDENCE = REPO / "build" / "mmio" / "evidence.json"
DEFAULT_OUT = REPO / "src" / "include" / "aic8800d80_mmio_behavior.json"

BEHAVIOR_MIN_CONF = 0.4
_POLL_RE = re.compile(r"^0x[0-9a-fA-F]+$")


def _norm_poll(b: dict) -> dict | None:
    rm = b.get("ready_mask")
    try:
        mask = int(rm, 16) if isinstance(rm, str) else int(rm)
    except (TypeError, ValueError):
        mask = 1
    mask = mask & 0xFFFFFFFF or 1
    try:
        n = int(b.get("reads_to_ready", 1))
    except (TypeError, ValueError):
        n = 1
    n = max(1, min(200, n))
    return {"type": "poll", "ready_mask": f"0x{mask:X}", "reads_to_ready": n}


def _norm_strobe(b: dict) -> dict | None:
    try:
        n = int(b.get("clear_after", 64))
    except (TypeError, ValueError):
        n = 64
    n = max(1, min(10000, n))
    return {"type": "strobe", "clear_after": n}


def _norm_counter(b: dict) -> dict | None:
    try:
        rate = int(b.get("tick_rate", 100))
    except (TypeError, ValueError):
        rate = 100
    rate = max(1, min(10000, rate))
    return {"type": "counter", "tick_rate": str(rate)}


def normalize(rec: dict, source: str) -> dict:
    """Normalize a classification record into the model entry."""
    out = {
        "name": rec.get("name") or "unknown",
        "role": rec.get("role") or "unknown",
        "confidence": float(rec.get("confidence", 0.0)),
        "source": source,
    }
    b = rec.get("behavior") or {}
    btype = b.get("type")
    behavior = None
    if source == "dynamic" and out["confidence"] >= BEHAVIOR_MIN_CONF:
        if btype == "poll":
            behavior = _norm_poll(b)
        elif btype == "strobe":
            behavior = _norm_strobe(b)
        elif btype == "counter":
            behavior = _norm_counter(b)
    if behavior is not None:
        out["behavior"] = behavior
    fields = rec.get("fields") or {}
    if isinstance(fields, dict) and fields:
        out["fields"] = fields
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--classifications", type=Path, default=DEFAULT_CLASS)
    ap.add_argument("--evidence", type=Path, default=DEFAULT_EVIDENCE)
    ap.add_argument("--out", type=Path, default=DEFAULT_OUT)
    ap.add_argument("--min-conf", type=float, default=BEHAVIOR_MIN_CONF,
                    help="only apply behavior to dynamic regs at/above this confidence")
    args = ap.parse_args()

    if not args.classifications.is_file():
        raise SystemExit(f"classifications not found: {args.classifications}")
    raw = json.loads(args.classifications.read_text()).get("classifications", {})
    evidence = json.loads(args.evidence.read_text()) if args.evidence.is_file() else {}
    dyn_addrs = set(evidence.get("registers", {}))

    # Deterministic evidence: registers the harvest flagged as polled
    # (read-heavy, write-starved). When the model independently agrees
    # (status + poll), a low numeric confidence should not drop a real
    # poll rule — floor it at the materialize threshold.
    ev_poll = {a.lower() for a, e in evidence.get("registers", {}).items() if e.get("poll")}

    model: dict[str, dict] = {}
    role_counts: dict[str, int] = {}
    behavior_counts: dict[str, int] = {}
    n_behavior = 0
    n_static = 0
    n_evfloor = 0
    for addr, rec in sorted(raw.items(), key=lambda kv: int(kv[0], 16)):
        source = "dynamic" if addr.lower() in dyn_addrs else "static"
        if source == "static":
            n_static += 1
        rec = dict(rec)
        b = rec.get("behavior") or {}
        if (source == "dynamic" and addr.lower() in ev_poll
                and rec.get("role") == "status" and b.get("type") == "poll"):
            rec["confidence"] = max(float(rec.get("confidence", 0.0)), BEHAVIOR_MIN_CONF)
            n_evfloor += 1
        entry = normalize(rec, source)
        model[addr.lower()] = entry
        role_counts[entry["role"]] = role_counts.get(entry["role"], 0) + 1
        if "behavior" in entry:
            behavior_counts[entry["behavior"]["type"]] = behavior_counts.get(entry["behavior"]["type"], 0) + 1
            n_behavior += 1

    doc = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "source_classifications": str(args.classifications),
        "min_confidence": args.min_conf,
        "register_count": len(model),
        "behavior_rules": n_behavior,
        "static_only": n_static,
        "evidence_poll_floor": n_evfloor,
        "role_counts": role_counts,
        "behavior_counts": behavior_counts,
        "registers": model,
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(doc, indent=1))
    print(f"[mmio_model] wrote {args.out}")
    print(f"[mmio_model] {len(model)} registers; {n_behavior} behavioral rules "
          f"({dict(behavior_counts)}); {n_static} static-only; {n_evfloor} evidence-poll floors")
    print(f"[mmio_model] roles: {dict(sorted(role_counts.items(), key=lambda kv: -kv[1]))}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
