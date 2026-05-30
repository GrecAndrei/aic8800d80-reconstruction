#!/usr/bin/env python3
"""Select a broad but relevant set of functions for IDA pseudocode export."""

from __future__ import annotations

import argparse
import json
from collections import defaultdict
from pathlib import Path


def load_recent_queues(run_root: Path, queue_window: int) -> list[dict]:
    candidates = sorted((run_root / "runs").glob("*/mining_queue_top300.jsonl"), key=lambda p: p.stat().st_mtime)
    if not candidates:
        return []
    if queue_window > 0 and len(candidates) > queue_window:
        candidates = candidates[-queue_window:]
    rows: list[dict] = []
    for queue_file in candidates:
        for line in queue_file.read_text(encoding="utf-8", errors="ignore").splitlines():
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


def load_focus_index(run_root: Path) -> list[dict]:
    path = run_root / "focus" / "focus_index.json"
    if not path.is_file():
        return []
    try:
        rows = json.loads(path.read_text(encoding="utf-8", errors="ignore"))
    except json.JSONDecodeError:
        return []
    if not isinstance(rows, list):
        return []
    return [r for r in rows if isinstance(r, dict)]


def load_descriptors(run_root: Path) -> list[dict]:
    path = run_root / "analysis" / "function_descriptors.json"
    if not path.is_file():
        return []
    try:
        rows = json.loads(path.read_text(encoding="utf-8", errors="ignore"))
    except json.JSONDecodeError:
        return []
    if not isinstance(rows, list):
        return []
    return [r for r in rows if isinstance(r, dict)]


def load_existing_pseudo(global_path: Path) -> set[tuple[str, str]]:
    if not global_path.is_file():
        return set()
    out: set[tuple[str, str]] = set()
    for line in global_path.read_text(encoding="utf-8", errors="ignore").splitlines():
        line = line.strip()
        if not line:
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError:
            continue
        if not isinstance(row, dict):
            continue
        image = str(row.get("image", "")).strip()
        address = str(row.get("address", "")).strip().lower()
        if image and address.startswith("0x"):
            out.add((image, address))
    return out


def load_lift_units(run_root: Path) -> list[dict]:
    path = run_root / "lift" / "lift_units.json"
    if not path.is_file():
        return []
    try:
        rows = json.loads(path.read_text(encoding="utf-8", errors="ignore"))
    except json.JSONDecodeError:
        return []
    if not isinstance(rows, list):
        return []
    return [r for r in rows if isinstance(r, dict)]


def add_score(score_by_key: dict[tuple[str, str], float], image: str, address: str, delta: float) -> None:
    if not image or not address.startswith("0x"):
        return
    score_by_key[(image, address)] += delta


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--run-root", type=Path, default=Path("extraction_out/reconstruction/mega7"))
    ap.add_argument("--out", type=Path, required=True)
    ap.add_argument("--limit", type=int, default=4096)
    ap.add_argument("--queue-window", type=int, default=12, help="How many recent mining queues to include")
    ap.add_argument("--outcomes-window", type=int, default=8000, help="How many recent outcomes to include")
    ap.add_argument("--existing-pseudo", type=Path, default=Path("extraction_out/ida_export_pseudo/pseudocode_hints.jsonl"), help="Existing pseudocode hints JSONL for novelty boosting")
    args = ap.parse_args()

    grouped: dict[str, dict[str, str]] = defaultdict(dict)
    score_by_key: dict[tuple[str, str], float] = defaultdict(float)

    for row in load_recent_queues(args.run_root, args.queue_window):
        image = str(row.get("image", "")).strip()
        address = str(row.get("address", "")).strip().lower()
        name = str(row.get("name", row.get("function", ""))).strip()
        if not image or not address.startswith("0x"):
            continue
        grouped[image][address] = name
        add_score(score_by_key, image, address, 15.0)
        try:
            add_score(score_by_key, image, address, float(row.get("score", 0.0)) * 0.01)
        except (TypeError, ValueError):
            pass

    capped_rank: dict[tuple[str, str], int] = defaultdict(int)
    outcomes = load_recent_outcomes(args.run_root)
    if args.outcomes_window > 0 and len(outcomes) > args.outcomes_window:
        outcomes = outcomes[-args.outcomes_window:]
    for row in outcomes:
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
        add_score(score_by_key, image, address, 3.0)

    for row in load_focus_index(args.run_root):
        image = str(row.get("image", "")).strip()
        address = str(row.get("target_address", row.get("address", ""))).strip().lower()
        name = str(row.get("target_function", row.get("name", ""))).strip()
        if not image or not address.startswith("0x"):
            continue
        grouped[image][address] = name
        work_score = float(row.get("work_score", 0.0) or 0.0)
        add_score(score_by_key, image, address, 20.0 + work_score)
        pri = str(row.get("priority_class", "")).strip().lower()
        if pri == "critical":
            add_score(score_by_key, image, address, 15.0)
        elif pri == "high":
            add_score(score_by_key, image, address, 8.0)

    for row in load_descriptors(args.run_root):
        image = str(row.get("image", "")).strip()
        address = str(row.get("address", "")).strip().lower()
        name = str(row.get("name", "")).strip()
        if not image or not address.startswith("0x"):
            continue
        if image not in grouped or address not in grouped[image]:
            grouped[image][address] = name
        add_score(score_by_key, image, address, 5.0)
        probe = row.get("probe", {}) if isinstance(row.get("probe"), dict) else {}
        phenotype = str(probe.get("phenotype", "")).strip().lower()
        if phenotype in {"capped_mmio_wait", "capped_low_mmio", "missing_symbols"}:
            add_score(score_by_key, image, address, 6.0)
        motif = row.get("motif", {}) if isinstance(row.get("motif"), dict) else {}
        try:
            conf = float(motif.get("confidence", 0.0) or 0.0)
        except (TypeError, ValueError):
            conf = 0.0
        add_score(score_by_key, image, address, conf * 10.0)

    for row in load_lift_units(args.run_root):
        image = str(row.get("image", "")).strip()
        address = str(row.get("address", "")).strip().lower()
        name = str(row.get("function", row.get("name", ""))).strip()
        if not image or not address.startswith("0x"):
            continue
        if image not in grouped or address not in grouped[image]:
            grouped[image][address] = name
        # Lift units give broad fallback coverage; keep score lower than
        # focused queue/focus-index descriptors so relevance still leads.
        add_score(score_by_key, image, address, 1.0)
        pri = str(row.get("priority_class", "")).strip().lower()
        if pri == "critical":
            add_score(score_by_key, image, address, 3.0)
        elif pri == "high":
            add_score(score_by_key, image, address, 1.5)

    existing_pseudo = load_existing_pseudo(args.existing_pseudo)

    ranked: list[tuple[float, str, str, str]] = []
    for image, items in grouped.items():
        for address, name in items.items():
            novelty = 0.0 if (image, address) in existing_pseudo else 12.0
            capped = float(capped_rank.get((image, address), 0))
            total = score_by_key.get((image, address), 0.0) + capped + novelty
            ranked.append((total, image, address, name))
    ranked.sort(key=lambda x: (-x[0], x[1], x[2]))

    per_image: dict[str, list[tuple[float, str, str, str]]] = defaultdict(list)
    for row in ranked:
        per_image[row[1]].append(row)

    selected: list[tuple[float, str, str, str]] = []
    image_order = sorted(per_image.keys())
    indexes = {img: 0 for img in image_order}
    target_limit = max(1, args.limit)
    while len(selected) < target_limit:
        progressed = False
        for image in image_order:
            idx = indexes[image]
            rows = per_image[image]
            if idx >= len(rows):
                continue
            selected.append(rows[idx])
            indexes[image] = idx + 1
            progressed = True
            if len(selected) >= target_limit:
                break
        if not progressed:
            break

    out_rows: list[dict] = []
    for score, image, address, name in selected:
        out_rows.append({"image": image, "address": address, "name": name})

    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(out_rows, indent=2, sort_keys=True), encoding="utf-8")
    image_counts = defaultdict(int)
    for row in out_rows:
        image_counts[row["image"]] += 1
    print({
        "selected": len(out_rows),
        "out": str(args.out),
        "images": dict(sorted(image_counts.items())),
        "existing_pseudo_rows": len(existing_pseudo),
    })
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
