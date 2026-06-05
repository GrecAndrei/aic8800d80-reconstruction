#!/usr/bin/env python3
"""Compile-check the truth-lane synth output.

Bundles all 25 truth-lane synth C files into a single translation unit with
forward decls for any callees that don't have a body in the bundle, then
compiles it with `gcc -Wall -Wextra`. Returns the gcc exit code.

This is the real fidelity check: a function that doesn't compile with
-forward-declared stubs is not a real implementation, no matter how many
helpers it references.
"""
import argparse
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TRUTH_LANE_STATE = REPO / "extraction_out/reconstruction/truth_lane_state"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--synth-dir", required=True, type=Path,
                    help="Directory containing <NNN>_<fn>.synth.c files")
    ap.add_argument("--targets", type=Path,
                    default=TRUTH_LANE_STATE / "truth_lane_targets.json",
                    help="Path to truth_lane_targets.json")
    ap.add_argument("--out", type=Path,
                    help="Write the bundle to this path (default: temp file)")
    ap.add_argument("--keep", action="store_true",
                    help="Keep the bundle file after compilation")
    ap.add_argument("--compiler", default="gcc")
    ap.add_argument("--cflags", default="-Wall -Wextra -Wno-unused-variable -Wno-unused-but-set-variable -c")
    args = ap.parse_args()

    if not args.synth_dir.exists():
        print(f"[compile_truth_lane] synth dir not found: {args.synth_dir}", file=sys.stderr)
        return 2
    if not args.targets.exists():
        print(f"[compile_truth_lane] targets not found: {args.targets}", file=sys.stderr)
        return 2

    targets = json.loads(args.targets.read_text())
    target_names = {t["function"] for t in targets}

    files = {}
    for t in targets:
        fn = t["function"]
        # Look for files matching the synth-side naming: <NNN>_<fn>.synth.c
        matches = list(args.synth_dir.glob(f"*_{fn}.synth.c"))
        if matches:
            files[fn] = matches[0]
    if not files:
        print(f"[compile_truth_lane] no synth files found in {args.synth_dir}", file=sys.stderr)
        return 2

    # Collect all callee forward decls.
    callees: set[str] = set()
    for fn, p in files.items():
        body = p.read_text(errors="replace")
        for m in re.finditer(r"^void\s+(\w+)\s*\(\s*\)\s*;\s*$", body, re.MULTILINE):
            callees.add(m.group(1))
    needed_stubs = sorted(callees - target_names)

    # Build the bundle.
    parts = [
        f"/* compile_truth_lane: {len(files)} truth-lane targets, "
        f"{len(needed_stubs)} stub callees */",
        "#include <stdint.h>",
        "",
    ]
    for n in needed_stubs:
        parts.append(f"void {n}(void) {{}}")
    parts.append("")
    for fn, p in sorted(files.items()):
        body = p.read_text(errors="replace")
        for line in body.split("\n"):
            if line.startswith("/*"):
                continue
            if line.startswith("#include"):
                continue
            parts.append(line)
        parts.append("")
    bundle_text = "\n".join(parts)

    if args.out:
        bundle_path = args.out
        bundle_path.write_text(bundle_text)
    else:
        tmp = tempfile.NamedTemporaryFile(suffix=".c", delete=False)
        bundle_path = Path(tmp.name)
        bundle_path.write_text(bundle_text)
        if not args.keep:
            tmp.close()

    print(f"[compile_truth_lane] bundle: {bundle_path} "
          f"({len(bundle_text)} bytes, {len(files)} targets, {len(needed_stubs)} stubs)")

    # Compile.
    with tempfile.NamedTemporaryFile(suffix=".o", delete=False) as objf:
        obj_path = Path(objf.name)
    cmd = [args.compiler, *args.cflags.split(), str(bundle_path), "-o", str(obj_path)]
    print(f"[compile_truth_lane] running: {' '.join(cmd)}")
    rc = subprocess.call(cmd)
    obj_path.unlink(missing_ok=True)
    if not args.keep and not args.out:
        bundle_path.unlink(missing_ok=True)
    if rc == 0:
        print(f"[compile_truth_lane] OK: bundle compiled cleanly")
    else:
        print(f"[compile_truth_lane] FAIL: gcc exit {rc}", file=sys.stderr)
    return rc


if __name__ == "__main__":
    sys.exit(main())
