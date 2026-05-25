#!/usr/bin/env python3
"""Promote stable smoke successes into README checkpoint list."""

from __future__ import annotations

import argparse
import json
import re
from collections import defaultdict
from pathlib import Path


def load_success_counts(path: Path) -> dict[str, int]:
    counts: dict[str, int] = defaultdict(int)
    if not path.is_file():
        return counts
    for line in path.read_text(encoding="utf-8", errors="ignore").splitlines():
        line = line.strip()
        if not line:
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError:
            continue
        status = str(row.get("status", "")).strip().lower()
        fn = str(row.get("function", "")).strip()
        if not fn:
            continue
        if status == "success":
            counts[fn] += 1
    return counts


def extract_checkpoints(readme: str) -> tuple[int, int, list[str]]:
    lines = readme.splitlines()
    start = -1
    end = len(lines)
    for i, line in enumerate(lines):
        if line.strip().lower() == "## smoke checkpoints":
            start = i
            break
    if start < 0:
        return -1, -1, []
    for j in range(start + 1, len(lines)):
        if lines[j].startswith("## "):
            end = j
            break
    existing: list[str] = []
    for line in lines[start:end]:
        m = re.search(r"`([A-Za-z0-9_]+)`", line)
        if m:
            existing.append(m.group(1))
    return start, end, existing


def extract_all_backtick_functions(readme: str) -> set[str]:
    return {m.lower() for m in re.findall(r"`([A-Za-z0-9_]+)`", readme)}


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--readme", type=Path, default=Path("README.md"))
    ap.add_argument("--outcomes", type=Path, required=True)
    ap.add_argument("--min-success", type=int, default=2)
    ap.add_argument("--max-add", type=int, default=30)
    args = ap.parse_args()

    if not args.readme.is_file():
        raise SystemExit(f"README not found: {args.readme}")
    readme = args.readme.read_text(encoding="utf-8", errors="ignore")
    start, end, existing = extract_checkpoints(readme)
    if start < 0:
        raise SystemExit("Smoke Checkpoints section not found in README")

    existing_set = {x.lower() for x in existing}
    all_seen = extract_all_backtick_functions(readme)
    success = load_success_counts(args.outcomes)
    candidates = []
    for fn, cnt in success.items():
        if cnt < args.min_success:
            continue
        if fn.lower() in existing_set or fn.lower() in all_seen:
            continue
        if fn.startswith("sub_"):
            continue
        candidates.append((fn, cnt))
    candidates.sort(key=lambda x: (-x[1], x[0].lower()))
    selected = candidates[: max(0, args.max_add)]

    if not selected:
        print(json.dumps({"added": 0, "functions": []}, indent=2))
        return 0

    lines = readme.splitlines()
    insert_at = end
    for fn, _cnt in selected:
        lines.insert(insert_at, f"- `{fn}`")
        insert_at += 1
    args.readme.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(json.dumps({"added": len(selected), "functions": [fn for fn, _ in selected]}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
