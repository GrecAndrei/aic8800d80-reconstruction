#!/usr/bin/env python3
"""Run queue-driven smoke probes and record outcomes for dynamic learning.

This utility is intentionally generic:
- reads mining queue JSONL
- skips already checkpointed functions from README
- probes top targets with unicorn_smoke.py
- appends machine-readable outcomes for pipeline ingestion
"""

from __future__ import annotations

import argparse
import json
import re
import subprocess
from collections import Counter, defaultdict
from pathlib import Path

DEF_RE = re.compile(r"^\s*(?:[A-Za-z_][A-Za-z0-9_\s\*]+)\s+([A-Za-z_][A-Za-z0-9_]*)\s*\([^;]*\)\s*\{")


def load_queue_records(path: Path) -> list[dict]:
    rows: list[dict] = []
    seen: set[str] = set()
    for line in path.read_text(encoding="utf-8", errors="ignore").splitlines():
        line = line.strip()
        if not line:
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError:
            continue
        name = str(row.get("name", "")).strip()
        if not name or name in seen:
            continue
        seen.add(name)
        rows.append(row)
    return rows


def load_checkpointed(readme: Path) -> set[str]:
    text = readme.read_text(encoding="utf-8", errors="ignore")
    return set(re.findall(r"`([A-Za-z0-9_]+)`", text))


def load_outcome_stats(path: Path) -> tuple[dict[str, dict[str, int]], dict[str, list[tuple[str, int]]]]:
    stats: dict[str, dict[str, int]] = defaultdict(lambda: {"attempts": 0, "success": 0, "fault": 0, "missing_symbol": 0})
    fault_by_prefix: dict[str, Counter[str]] = defaultdict(Counter)
    if not path.is_file():
        return stats, {}
    for line in path.read_text(encoding="utf-8", errors="ignore").splitlines():
        line = line.strip()
        if not line:
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError:
            continue
        fn = str(row.get("function", "")).strip()
        if not fn:
            continue
        st = str(row.get("status", "")).strip().lower()
        k = fn.lower()
        stats[k]["attempts"] += 1
        if st in stats[k]:
            stats[k][st] += 1
        if st == "fault":
            addr = str(row.get("fault_address", "")).strip().lower()
            if addr.startswith("0x"):
                fault_by_prefix[prefix(fn)][addr] += 1
    top_faults = {
        p: sorted(counter.items(), key=lambda kv: (-kv[1], kv[0]))[:3]
        for p, counter in fault_by_prefix.items()
        if counter
    }
    return stats, top_faults


def index_functions(sources: list[Path]) -> tuple[dict[str, Path], dict[str, str]]:
    out: dict[str, Path] = {}
    canon: dict[str, str] = {}
    for src in sources:
        if not src.is_file():
            continue
        for line in src.read_text(encoding="utf-8", errors="ignore").splitlines():
            m = DEF_RE.match(line)
            if not m:
                continue
            name = m.group(1)
            out.setdefault(name, src)
            lower = name.lower()
            canon.setdefault(lower, name)
    return out, canon


def prefix(name: str) -> str:
    n = name.strip().lower()
    if "_" in n:
        return n.split("_", 1)[0]
    return n


def parse_seed(seed: str) -> tuple[str, str]:
    if "=" not in seed:
        raise ValueError(f"invalid seed {seed!r}, expected ADDR=VALUE")
    a, v = seed.split("=", 1)
    return a.strip(), v.strip()


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--source", type=Path, required=True, help="Primary recovered C source path")
    ap.add_argument(
        "--source-glob",
        action="append",
        default=[],
        help="Extra glob(s) for source pool selection (repeatable), e.g. 'extraction_out/reconstruction/mega7/**/*.c'",
    )
    ap.add_argument("--queue", type=Path, required=True, help="mining_queue_top300.jsonl or similar")
    ap.add_argument("--outcomes", type=Path, required=True, help="smoke_observations.jsonl path")
    ap.add_argument("--readme", type=Path, default=Path("README.md"), help="README to mine known checkpoints")
    ap.add_argument("--limit", type=int, default=12, help="maximum functions to probe")
    ap.add_argument("--max-insns", type=int, default=120, help="instruction cap per probe")
    ap.add_argument("--missing-cooldown", type=int, default=3, help="skip targets with this many missing_symbol hits")
    ap.add_argument("--fault-seed-top", type=int, default=2, help="learn up to this many historical fault addresses per prefix as seeds")
    ap.add_argument("--retry-fault-once", action="store_true", help="on fault, retry once with the reported fault address seeded")
    ap.add_argument(
        "--seed",
        action="append",
        default=[],
        help="global default seed ADDR=VALUE, repeatable",
    )
    args = ap.parse_args()

    if not args.source.is_file():
        raise SystemExit(f"source not found: {args.source}")
    if not args.queue.is_file():
        raise SystemExit(f"queue not found: {args.queue}")
    if not args.readme.is_file():
        raise SystemExit(f"readme not found: {args.readme}")

    global_seeds = [parse_seed(s) for s in args.seed]
    checkpointed = load_checkpointed(args.readme)
    queue_rows = load_queue_records(args.queue)
    outcomes, top_faults = load_outcome_stats(args.outcomes)
    source_pool: list[Path] = [args.source]
    for pattern in args.source_glob:
        source_pool.extend(sorted(Path(".").glob(pattern)))
    # Keep order stable and dedupe.
    seen_src: set[str] = set()
    uniq_pool: list[Path] = []
    for p in source_pool:
        rp = str(p.resolve())
        if rp in seen_src:
            continue
        seen_src.add(rp)
        uniq_pool.append(p)
    fn_index, fn_canon = index_functions(uniq_pool)

    # Small generic seed hints by prefix. These are intentionally conservative.
    prefix_seeds: dict[str, list[tuple[str, str]]] = {
        "rf": [("0x40010000", "0"), ("0x40000000", "0")],
        "sdio": [("0x40020000", "0"), ("0x40000000", "0")],
        "irq": [("0xe000ed08", "0x20000000"), ("0x40000000", "0")],
        "msg": [("0x40000000", "0")],
        "log": [("0x40000000", "0")],
        "tx": [("0x40000000", "0")],
    }
    # Learn additional seeds from prior unmapped-fault addresses.
    for pfx, rows in top_faults.items():
        learned = []
        for addr, _count in rows[: max(0, args.fault_seed_top)]:
            learned.append((addr, "0"))
        if learned:
            prefix_seeds.setdefault(pfx, [])
            prefix_seeds[pfx].extend(learned)

    candidates: list[dict] = []
    for row in queue_rows:
        name = str(row.get("name", "")).strip()
        if name.startswith("sub_"):
            continue
        if name in checkpointed:
            continue
        low = name.lower()
        stat = outcomes.get(low, {"attempts": 0, "success": 0, "fault": 0, "missing_symbol": 0})
        candidates.append(
            {
                "name": name,
                "priority": float(row.get("priority_score", 0.0)),
                "attempts": int(stat.get("attempts", 0)),
                "success": int(stat.get("success", 0)),
                "fault": int(stat.get("fault", 0)),
                "missing_symbol": int(stat.get("missing_symbol", 0)),
                "prefix": prefix(name),
            }
        )

    # Prefer under-tested, high-priority candidates and avoid immediate repeats.
    candidates.sort(
        key=lambda c: (
            c["success"] > 0,              # unseen first
            c["attempts"],                 # fewer attempts first
            c["missing_symbol"],           # fewer missing-symbol misses first
            -c["priority"],                # then higher queue priority
            c["name"].lower(),
        )
    )

    picked: list[str] = []
    prefix_counts: dict[str, int] = defaultdict(int)
    for c in candidates:
        if c["missing_symbol"] >= args.missing_cooldown:
            continue
        p = c["prefix"]
        # Soft diversity cap: avoid spending a whole cycle on one prefix.
        if prefix_counts[p] >= max(1, args.limit // 3):
            continue
        picked.append(c["name"])
        prefix_counts[p] += 1
        if len(picked) >= args.limit:
            break
    # Fallback fill if diversity gate was too strict.
    if len(picked) < args.limit:
        picked_set = set(picked)
        for c in candidates:
            if c["name"] in picked_set:
                continue
            picked.append(c["name"])
            if len(picked) >= args.limit:
                break

    print(json.dumps({"selected": picked, "count": len(picked), "candidates": len(candidates)}, indent=2))

    for fn in picked:
        resolved_fn = fn_canon.get(fn.lower(), fn)
        source = fn_index.get(resolved_fn, args.source)
        cmd = [
            "python3",
            "tools/unicorn_smoke.py",
            str(source),
            resolved_fn,
            "--max-insns",
            str(args.max_insns),
            "--record-outcome",
            str(args.outcomes),
        ]
        merged = {}
        for a, v in global_seeds + prefix_seeds.get(prefix(fn), []):
            merged[a.lower()] = v
        for a, v in merged.items():
            cmd.extend(["--seed", f"{a}={v}"])

        print(f"== probe {fn} -> {resolved_fn} @ {source}")
        proc = subprocess.run(cmd, text=True, capture_output=True, timeout=90)
        if proc.stdout:
            print(proc.stdout.strip())
        if proc.stderr:
            print(proc.stderr.strip())
        print(f"rc={proc.returncode}")

        if not args.retry_fault_once:
            continue
        if proc.returncode != 2:
            continue
        fault_addr = ""
        for line in (proc.stdout or "").splitlines():
            line = line.strip()
            if not line.startswith("{"):
                continue
            try:
                row = json.loads(line)
            except json.JSONDecodeError:
                continue
            addr = str(row.get("fault_address", "")).strip().lower()
            if addr.startswith("0x"):
                fault_addr = addr
                break
        if not fault_addr:
            continue
        retry_cmd = list(cmd)
        retry_cmd.extend(["--seed", f"{fault_addr}=0"])
        print(f"== retry {fn} with learned seed {fault_addr}=0")
        retry = subprocess.run(retry_cmd, text=True, capture_output=True, timeout=90)
        if retry.stdout:
            print(retry.stdout.strip())
        if retry.stderr:
            print(retry.stderr.strip())
        print(f"retry_rc={retry.returncode}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
