#!/usr/bin/env python3
"""Select a broad but relevant set of functions for IDA pseudocode export."""

from __future__ import annotations

import argparse
import json
from collections import defaultdict
from pathlib import Path


def load_latest_queue(run_root: Path) -> list[dict]:
    candidates = sorted((run_root / "runs").glob("*/mining_queue_top300.jsonl"), key=lambda p: p.stat().st_mtime)
    if not candidates:
        return []
    rows: list[dict] = []
    for line in candidates[-1].read_text(encoding="utf-8", errors="ignore").splitlines():
        line = line.strip()
        if not line:
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError:
            continue
        if isinstance(row, dict):
            rows.append(row)
    return rows


def load_recent_outcomes(run_root: Path) -> list[dict]:
    path = run_root / "smoke_observations.jsonl"
    if not path.is_file():
        return []
    rows: list[dict] = []
    for line in path.read_text(encoding="utf-8", errors="ignore").splitlines():
        line = line.strip()
        if not line:
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError:
            continue
        if isinstance(row, dict):
            rows.append(row)
    return rows[-2000:]


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--run-root", type=Path, default=Path("extraction_out/reconstruction/mega7"))
    ap.add_argument("--out", type=Path, required=True)
    ap.add_argument("--limit", type=int, default=512)
    args = ap.parse_args()

    grouped: dict[str, dict[str, str]] = defaultdict(dict)

    for row in load_latest_queue(args.run_root):
        image = str(row.get("image", "")).strip()
        address = str(row.get("address", "")).strip().lower()
        name = str(row.get("name", "")).strip()
        if not image or not address.startswith("0x"):
            continue
        grouped[image][address] = name

    capped_rank: dict[tuple[str, str], int] = defaultdict(int)
    for row in load_recent_outcomes(args.run_root):
        image = str(row.get("image", "")).strip()
        address = str(row.get("address", "")).strip().lower()
        name = str(row.get("function", "")).strip()
        status = str(row.get("status", "")).strip().lower()
        if not image or not address.startswith("0x"):
            continue
        if status == "capped":
            capped_rank[(image, address)] += 3
        elif status in {"returned", "success"}:
            capped_rank[(image, address)] += 1
        if image not in grouped or address not in grouped[image]:
            grouped[image][address] = name

    ranked: list[tuple[int, str, str, str]] = []
    for image, items in grouped.items():
        for address, name in items.items():
            ranked.append((capped_rank.get((image, address), 0), image, address, name))
    ranked.sort(key=lambda x: (-x[0], x[1], x[2]))

    out_rows: list[dict] = []
    for _, image, address, name in ranked[: max(1, args.limit)]:
        out_rows.append({"image": image, "address": address, "name": name})

    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(out_rows, indent=2, sort_keys=True), encoding="utf-8")
    print({"selected": len(out_rows), "out": str(args.out)})
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
