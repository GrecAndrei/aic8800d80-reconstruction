#!/usr/bin/env python3
"""Aggregate accepted synth files from harness_v15/out/ to the release dir.

For each task with verify.ok=true, copy synth.c to:
  <release>/synth/<task_id>.synth.c

Prints summary of accepted/rejected.
"""
import argparse
import json
import shutil
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", required=True, help="harness_v15/out/")
    ap.add_argument("--release", required=True, help="artifacts/releases/.../synth/")
    args = ap.parse_args()

    out_root = Path(args.out)
    release = Path(args.release)
    release.mkdir(parents=True, exist_ok=True)

    accepted = []
    rejected = []
    for task_dir in sorted(out_root.iterdir()):
        if not task_dir.is_dir():
            continue
        result_path = task_dir / "result.json"
        if not result_path.exists():
            rejected.append((task_dir.name, "no_result.json"))
            continue
        result = json.loads(result_path.read_text())
        verify = result.get("verify", {})
        if not verify.get("ok", False):
            rejected.append((task_dir.name, verify.get("reason", "unknown")))
            continue
        # Copy synth.c to release
        src = task_dir / "synth.c"
        if not src.exists():
            rejected.append((task_dir.name, "no_synth.c"))
            continue
        dst = release / f"{task_dir.name}.synth.c"
        shutil.copy2(src, dst)
        accepted.append((task_dir.name, verify.get("reason", "ok")))

    print(f"ACCEPTED ({len(accepted)}):")
    for tid, reason in accepted:
        print(f"  {tid}: {reason}")
    print(f"\nREJECTED ({len(rejected)}):")
    for tid, reason in rejected:
        print(f"  {tid}: {reason}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
