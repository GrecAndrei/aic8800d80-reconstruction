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
from datetime import datetime, timezone
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


def parse_iso_time(s: str) -> datetime | None:
    s = (s or "").strip()
    if not s:
        return None
    if s.endswith("Z"):
        s = s[:-1] + "+00:00"
    try:
        dt = datetime.fromisoformat(s)
    except ValueError:
        return None
    if dt.tzinfo is None:
        dt = dt.replace(tzinfo=timezone.utc)
    return dt.astimezone(timezone.utc)


def load_outcome_stats(path: Path, min_success_insns: int) -> tuple[dict[str, dict[str, int]], dict[str, list[tuple[str, int]]], dict[str, datetime]]:
    stats: dict[str, dict[str, int]] = defaultdict(lambda: {"attempts": 0, "success": 0, "fault": 0, "missing_symbol": 0, "shallow_success": 0})
    fault_by_prefix: dict[str, Counter[str]] = defaultdict(Counter)
    last_seen: dict[str, datetime] = {}
    if not path.is_file():
        return stats, {}, last_seen
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
        dt = parse_iso_time(str(row.get("generated_at", "")))
        if dt is not None:
            prev = last_seen.get(k)
            if prev is None or dt > prev:
                last_seen[k] = dt
        if st in stats[k]:
            stats[k][st] += 1
        if st == "success":
            try:
                insns = int(row.get("instructions", -1))
            except (TypeError, ValueError):
                insns = -1
            if 0 <= insns < max(0, min_success_insns):
                stats[k]["shallow_success"] += 1
        if st == "fault":
            addr = str(row.get("fault_address", "")).strip().lower()
            if addr.startswith("0x"):
                fault_by_prefix[prefix(fn)][addr] += 1
    top_faults = {
        p: sorted(counter.items(), key=lambda kv: (-kv[1], kv[0]))[:3]
        for p, counter in fault_by_prefix.items()
        if counter
    }
    return stats, top_faults, last_seen


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


def extract_json_objects(text: str) -> list[dict]:
    out: list[dict] = []
    dec = json.JSONDecoder()
    i = 0
    n = len(text)
    while i < n:
        j = text.find("{", i)
        if j < 0:
            break
        try:
            obj, k = dec.raw_decode(text, j)
        except json.JSONDecodeError:
            i = j + 1
            continue
        if isinstance(obj, dict):
            out.append(obj)
        i = k
    return out


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
    ap.add_argument("--min-success-insns", type=int, default=8, help="treat success below this instruction count as shallow")
    ap.add_argument("--shallow-cooldown", type=int, default=3, help="skip targets with this many shallow successes")
    ap.add_argument("--retry-shallow-success", action="store_true", help="retry shallow successes once with a larger instruction cap")
    ap.add_argument("--shallow-retry-max-insns", type=int, default=512, help="instruction cap for shallow-success retry")
    ap.add_argument("--missing-cooldown", type=int, default=3, help="skip targets with this many missing_symbol hits")
    ap.add_argument("--fault-seed-top", type=int, default=2, help="learn up to this many historical fault addresses per prefix as seeds")
    ap.add_argument("--retry-fault-once", action="store_true", help="on fault, retry once with the reported fault address seeded")
    ap.add_argument("--recent-window-min", type=int, default=30, help="skip functions attempted within this many minutes")
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
    outcomes, top_faults, last_seen = load_outcome_stats(args.outcomes, args.min_success_insns)
    now = datetime.now(timezone.utc)
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
                "shallow_success": int(stat.get("shallow_success", 0)),
                "prefix": prefix(name),
                "recent_min": int((now - last_seen[low]).total_seconds() // 60) if low in last_seen else 10**9,
            }
        )

    # Prefer under-tested, high-priority candidates and avoid immediate repeats.
    candidates.sort(
        key=lambda c: (
            c["success"] > 0,              # unseen first
            c["attempts"],                 # fewer attempts first
            c["recent_min"],               # prefer less-recently attempted targets
            c["missing_symbol"],           # fewer missing-symbol misses first
            c["shallow_success"],          # fewer shallow successes first
            -c["priority"],                # then higher queue priority
            c["name"].lower(),
        )
    )

    # Staged selector:
    #  1) strict cooldown+recency with prefix diversity
    #  2) strict cooldown+recency without prefix diversity
    #  3) strict cooldown with softer recency (half window)
    #  4) strict cooldown with no recency
    #  5) one extra missing-symbol strike with no recency
    picked: list[str] = []
    picked_set: set[str] = set()

    def pick_stage(missing_max: int, recent_min: int, enforce_prefix_cap: bool) -> None:
        prefix_counts: dict[str, int] = defaultdict(int)
        for name in picked:
            for c in candidates:
                if c["name"] == name:
                    prefix_counts[c["prefix"]] += 1
                    break
        for c in candidates:
            if len(picked) >= args.limit:
                return
            if c["name"] in picked_set:
                continue
            if c["missing_symbol"] >= missing_max:
                continue
            if c["shallow_success"] >= max(0, args.shallow_cooldown):
                continue
            if c["recent_min"] < recent_min:
                continue
            if enforce_prefix_cap:
                p = c["prefix"]
                if prefix_counts[p] >= max(1, args.limit // 3):
                    continue
                prefix_counts[p] += 1
            picked.append(c["name"])
            picked_set.add(c["name"])

    strict_recent = max(0, args.recent_window_min)
    soft_recent = strict_recent // 2
    pick_stage(args.missing_cooldown, strict_recent, True)
    pick_stage(args.missing_cooldown, strict_recent, False)
    pick_stage(args.missing_cooldown, soft_recent, False)
    pick_stage(args.missing_cooldown, 0, False)
    pick_stage(args.missing_cooldown + 1, 0, False)

    print(json.dumps({"selected": picked, "count": len(picked), "candidates": len(candidates)}, indent=2))

    summary = {
        "probed": 0,
        "success": 0,
        "fault": 0,
        "missing_symbol": 0,
        "other_nonzero": 0,
        "retried": 0,
        "retry_recovered": 0,
        "shallow_success": 0,
        "shallow_retry_upgraded": 0,
    }
    for fn in picked:
        summary["probed"] += 1
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
        if proc.returncode == 0:
            summary["success"] += 1
        elif proc.returncode == 2:
            summary["fault"] += 1
        elif proc.returncode == 3:
            summary["missing_symbol"] += 1
        else:
            summary["other_nonzero"] += 1

        parsed_objs = extract_json_objects(proc.stdout or "")
        if proc.returncode == 0:
            insns = -1
            for row in parsed_objs:
                if str(row.get("status", "")).strip().lower() != "success":
                    continue
                try:
                    insns = int(row.get("instructions", -1))
                except (TypeError, ValueError):
                    insns = -1
                break
            if 0 <= insns < max(0, args.min_success_insns):
                summary["shallow_success"] += 1
                if args.retry_shallow_success:
                    retry_cmd = list(cmd)
                    for i, tok in enumerate(retry_cmd):
                        if tok == "--max-insns" and i+1 < len(retry_cmd):
                            retry_cmd[i+1] = str(max(args.max_insns, args.shallow_retry_max_insns))
                            break
                    print(f"== retry shallow-success {fn} with max-insns={max(args.max_insns, args.shallow_retry_max_insns)}")
                    retry = subprocess.run(retry_cmd, text=True, capture_output=True, timeout=120)
                    if retry.stdout:
                        print(retry.stdout.strip())
                    if retry.stderr:
                        print(retry.stderr.strip())
                    print(f"retry_shallow_rc={retry.returncode}")
                    if retry.returncode == 0:
                        for row in extract_json_objects(retry.stdout or ""):
                            if str(row.get("status", "")).strip().lower() != "success":
                                continue
                            try:
                                r_insns = int(row.get("instructions", -1))
                            except (TypeError, ValueError):
                                r_insns = -1
                            if r_insns > insns:
                                summary["shallow_retry_upgraded"] += 1
                            break

        if not args.retry_fault_once:
            continue
        if proc.returncode != 2:
            continue
        summary["retried"] += 1
        fault_addr = ""
        for row in parsed_objs:
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
        if retry.returncode == 0:
            summary["retry_recovered"] += 1

    print(json.dumps({"probe_summary": summary}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
