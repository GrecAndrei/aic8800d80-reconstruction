#!/usr/bin/env python3
"""Compress large per-run artifacts for older reconstruction cycles."""

from __future__ import annotations

import argparse
import gzip
import shutil
from pathlib import Path


def maybe_gzip(path: Path) -> int:
    if not path.is_file():
        return 0
    gz = path.with_suffix(path.suffix + ".gz")
    if gz.exists():
        return 0
    with path.open("rb") as src, gzip.open(gz, "wb", compresslevel=6) as dst:
        shutil.copyfileobj(src, dst)
    path.unlink()
    return 1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--run-root", type=Path, required=True, help="reconstruction run root (contains runs/)")
    ap.add_argument("--keep-latest", type=int, default=8, help="number of newest runs to keep uncompressed")
    ap.add_argument(
        "--file",
        action="append",
        default=["mining_queue_full.jsonl"],
        help="large run-local file to gzip in older runs (repeatable)",
    )
    args = ap.parse_args()

    runs_dir = args.run_root / "runs"
    if not runs_dir.is_dir():
        raise SystemExit(f"runs dir missing: {runs_dir}")
    keep_latest = max(0, int(args.keep_latest))
    run_dirs = sorted([p for p in runs_dir.iterdir() if p.is_dir()])
    if keep_latest > 0:
        targets = run_dirs[:-keep_latest]
    else:
        targets = run_dirs

    compressed = 0
    scanned = 0
    names = [n.strip() for n in args.file if n.strip()]
    for r in targets:
        for name in names:
            scanned += 1
            compressed += maybe_gzip(r / name)
    print({"runs_total": len(run_dirs), "runs_pruned": len(targets), "files_checked": scanned, "files_compressed": compressed})
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
