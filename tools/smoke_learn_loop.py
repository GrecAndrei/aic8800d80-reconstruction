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
from pathlib import Path

DEF_RE = re.compile(r"^\s*(?:[A-Za-z_][A-Za-z0-9_\s\*]+)\s+([A-Za-z_][A-Za-z0-9_]*)\s*\([^;]*\)\s*\{")


def load_queue_names(path: Path) -> list[str]:
    names: list[str] = []
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
        names.append(name)
    return names


def load_checkpointed(readme: Path) -> set[str]:
    text = readme.read_text(encoding="utf-8", errors="ignore")
    return set(re.findall(r"`([A-Za-z0-9_]+)`", text))


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
    names = load_queue_names(args.queue)
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

    picked: list[str] = []
    for name in names:
        if name.startswith("sub_"):
            continue
        if name in checkpointed:
            continue
        picked.append(name)
        if len(picked) >= args.limit:
            break

    print(json.dumps({"selected": picked, "count": len(picked)}, indent=2))

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

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
