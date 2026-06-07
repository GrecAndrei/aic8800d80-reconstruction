#!/usr/bin/env python3
"""Generate behavioral fingerprint synth files and add them to the pipeline.

Usage:
  python3 tools/run_behavioral_gen.py \\
      --out-dir extraction_out/reconstruction/mega7/synth \\
      [--targets extraction_out/reconstruction/mega7/focus/cluster_*.focus.c]
      [--max-insns 10000]
      [--workers 4]

Without --targets, processes all functions from all 4 firmware binaries'
focus/implwork lists (critical-priority functions only).

Output: For each function traced, a behavioral_{name}.synth.c file in out-dir
that fwapplysynth will pick up automatically.
"""
from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

BINARIES = {
    "lmacfw_rf_8800d80_u02.bin": "inputs/firmware/lmacfw_rf_8800d80_u02.bin",
    "fmacfwbt_8800d80_u02.bin": "inputs/firmware/fmacfwbt_8800d80_u02.bin",
    "fmacfw_8800d80_u02.bin": "inputs/firmware/fmacfw_8800d80_u02.bin",
    "fmacfw_8800d80_h_u02.bin": "inputs/firmware/fmacfw_8800d80_h_u02.bin",
}

REPO_ROOT = Path(__file__).resolve().parent.parent


def run_tracer(bin_path: str, targets_path: str, out_path: str, max_insns: int) -> dict:
    result = subprocess.run(
        [sys.executable, "tools/behavioral_fingerprint.py",
         "--bin", bin_path,
         "--targets", targets_path,
         "--out", out_path,
         "--max-insns", str(max_insns)],
        capture_output=True, text=True, cwd=str(REPO_ROOT), timeout=300)
    if result.returncode != 0:
        return {"error": result.stderr.strip(), "bin": bin_path, "targets": targets_path}
    try:
        return json.loads(result.stdout.splitlines()[-1])
    except (json.JSONDecodeError, IndexError):
        return {"error": "parse failed", "stderr": result.stderr.strip(), "stdout": result.stdout.strip()}


def find_targets_by_image() -> dict[str, list[dict]]:
    """Read all focus files and implwork to build a target list per image."""
    targets = []
    # Paths to search for critical functions
    search_dirs = [
        REPO_ROOT / "extraction_out" / "reconstruction" / "mega7" / "focus",
        REPO_ROOT / "extraction_out" / "reconstruction" / "mega7" / "implwork",
        REPO_ROOT / "extraction_out" / "reconstruction" / "truth_lane_eval" / "v12_realpseudo" / "synth",
    ]
    seen = set()
    for d in search_dirs:
        if not d.exists():
            continue
        for fpath in sorted(d.iterdir()):
            if fpath.suffix == ".c":
                fns = extract_truth_lane_fns(fpath)
                for fn in fns:
                    key = (fn["image"], fn["address"])
                    if key not in seen:
                        seen.add(key)
                        targets.append(fn)
    return targets


def extract_truth_lane_fns(path: Path) -> list[dict]:
    """Extract function name + address + image from a focus/implwork C file."""
    text = path.read_text(encoding="utf-8", errors="replace")
    results = []
    # Look for comments with image+addr info
    for m in re.finditer(r'/\*\s*.*?image\s*=\s*(\S+?)\s.*?', text, re.IGNORECASE):
        ...
    # Fallback: look for function defs
    for m in re.finditer(r'void\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*\(\s*void\s*\)\s*\{', text):
        name = m.group(1)
        results.append({"name": name, "address": "", "image": ""})
    return results


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--out-dir", default=str(REPO_ROOT / "tmp" / "behavioral_synth"),
                    help="Output directory for synth files")
    ap.add_argument("--targets", type=Path, default=None,
                    help="JSONL file with target functions (optional)")
    ap.add_argument("--max-insns", type=int, default=10000)
    ap.add_argument("--workers", type=int, default=2,
                    help="Parallel workers per binary")
    args = ap.parse_args()

    out_dir = Path(args.out_dir)
    out_dir.mkdir(parents=True, exist_ok=True)

    if args.targets and args.targets.exists():
        with args.targets.open("r", encoding="utf-8") as f:
            all_targets = [json.loads(line) for line in f if line.strip()]
    else:
        print("No targets file specified, processing critical-priority functions...", file=sys.stderr)
        # Use the 17 truth-lane targets we already have
        all_targets = []
        fp = REPO_ROOT / "tmp" / "opencode" / "truth_lane_targets.jsonl"
        if fp.exists():
            with fp.open("r", encoding="utf-8") as f:
                all_targets = [json.loads(line) for line in f if line.strip()]

    if not all_targets:
        print("No targets found. Provide --targets or ensure truth_lane_targets.jsonl exists.", file=sys.stderr)
        return 1

    # Group by image
    by_image: dict[str, list[dict]] = {}
    for t in all_targets:
        img = t.get("image", "")
        if img not in BINARIES:
            print(f"  Skipping {t.get('name', '?')}: unknown image {img}", file=sys.stderr)
            continue
        by_image.setdefault(img, []).append(t)

    # For each image, trace and generate
    for img, targets in by_image.items():
        bin_path = BINARIES[img]
        if not Path(bin_path).exists():
            print(f"  Skipping {img}: binary not found at {bin_path}", file=sys.stderr)
            continue

        print(f"\nProcessing {img}: {len(targets)} targets via {bin_path}", file=sys.stderr)

        # Split into batches for parallel tracing
        batch_size = max(1, len(targets) // args.workers)
        batches = [targets[i:i+batch_size] for i in range(0, len(targets), batch_size)]

        fp_dir = Path(tempfile.mkdtemp(prefix=f"fp_{img.replace('.','_')}_"))

        with ThreadPoolExecutor(max_workers=args.workers) as pool:
            fut_to_batch = {}
            for bi, batch in enumerate(batches):
                tp = fp_dir / f"batch_{bi}.jsonl"
                with tp.open("w", encoding="utf-8") as f:
                    for t in batch:
                        f.write(json.dumps(t) + "\n")
                out_path = fp_dir / f"trace_{bi}.jsonl"
                fut = pool.submit(run_tracer, bin_path, str(tp), str(out_path), args.max_insns)
                fut_to_batch[fut] = (bi, batch, out_path)

            all_results = []
            for fut in as_completed(fut_to_batch):
                bi, batch, out_path = fut_to_batch[fut]
                try:
                    result = fut.result()
                    if "error" in result:
                        print(f"  Batch {bi} error: {result['error'][:120]}", file=sys.stderr)
                    else:
                        if result.get("traced", 0) > 0:
                            print(f"  Batch {bi}: {result['traced']} traced, {result['returned']} returned, {result['faulted']} faulted", file=sys.stderr)
                except Exception as e:
                    print(f"  Batch {bi} exception: {e}", file=sys.stderr)

                # Read trace results
                if out_path.exists():
                    with out_path.open("r", encoding="utf-8") as f:
                        for line in f:
                            if line.strip():
                                all_results.append(json.loads(line))

        # Combine traces
        combined_fp = fp_dir / "combined.jsonl"
        with combined_fp.open("w", encoding="utf-8") as f:
            for r in all_results:
                f.write(json.dumps(r, sort_keys=True) + "\n")
        print(f"  Combined {len(all_results)} traces -> {combined_fp}", file=sys.stderr)

        # Run behaviorsynth
        synth_bin = REPO_ROOT / "tmp" / "opencode" / "behaviorsynth"
        if not synth_bin.exists():
            print(f"  behaviorsynth binary not found at {synth_bin}, building...", file=sys.stderr)
            subprocess.run(
                ["go", "build", "-o", str(synth_bin), "."],
                cwd=str(REPO_ROOT / "cmd" / "behaviorsynth"),
                capture_output=True, timeout=60)

        result = subprocess.run(
            [str(synth_bin), str(combined_fp), str(out_dir)],
            capture_output=True, text=True, timeout=30)
        for line in result.stderr.strip().split("\n"):
            if line:
                print(f"  {line}", file=sys.stderr)

        # Cleanup
        import shutil
        shutil.rmtree(fp_dir, ignore_errors=True)

    print(f"\nDone. Behavioral synth files in {out_dir}", file=sys.stderr)
    print(f"  {len(list(out_dir.glob('*.synth.c')))} files generated", file=sys.stderr)
    print(f"  Copy to pipeline synth dir and re-run fwapplysynth", file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
