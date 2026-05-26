#!/usr/bin/env python3
"""Refresh IDA-derived call edges and CFG hints from local .i64 databases."""

from __future__ import annotations

import argparse
import os
import subprocess
from pathlib import Path


def run(cmd: list[str], env: dict[str, str]) -> None:
    p = subprocess.run(cmd, text=True, env=env, capture_output=True)
    if p.stdout.strip():
        print(p.stdout.strip())
    if p.returncode != 0:
        if p.stderr.strip():
            print(p.stderr.strip())
        raise SystemExit(p.returncode)


def concat_jsonl(files: list[Path], dst: Path) -> int:
    dst.parent.mkdir(parents=True, exist_ok=True)
    rows = 0
    with dst.open("w", encoding="utf-8") as out:
        for f in files:
            if not f.is_file():
                continue
            for line in f.read_text(encoding="utf-8", errors="ignore").splitlines():
                line = line.strip()
                if not line:
                    continue
                out.write(line + "\n")
                rows += 1
    return rows


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--idat", required=True, help="Path to IDA idat executable")
    ap.add_argument("--firmware-dir", default="inputs/firmware", help="Directory containing .i64 databases")
    ap.add_argument("--work-out", default="extraction_out/ida_export_live", help="Temporary raw export directory")
    ap.add_argument("--edge-out", default="extraction_out/call_edges.with_ida_raw.jsonl", help="Merged call edges JSONL")
    ap.add_argument("--cfg-out", default="extraction_out/ida_export_cfg/cfg_hints.jsonl", help="Merged CFG hints JSONL")
    ap.add_argument("--pseudo-out", default="extraction_out/ida_export_pseudo/pseudocode_hints.jsonl", help="Merged pseudocode hint JSONL")
    ap.add_argument("--edges-script", default="tools/export_ida_edges.py", help="IDA Python export script for call edges")
    ap.add_argument("--cfg-script", default="tools/export_ida_cfg.py", help="IDA Python export script for CFG hints")
    ap.add_argument("--pseudo-script", default="tools/export_ida_pseudocode.py", help="IDA Python export script for pseudocode hints")
    ap.add_argument("--pseudo-targets", default="", help="JSON file describing per-image pseudocode export targets")
    args = ap.parse_args()

    idat = Path(args.idat).expanduser().resolve()
    if not idat.is_file():
        raise SystemExit(f"idat not found: {idat}")
    fw_dir = Path(args.firmware_dir).resolve()
    if not fw_dir.is_dir():
        raise SystemExit(f"firmware dir not found: {fw_dir}")
    work_out = Path(args.work_out).resolve()
    work_out.mkdir(parents=True, exist_ok=True)
    edges_script = Path(args.edges_script).resolve()
    cfg_script = Path(args.cfg_script).resolve()
    pseudo_script = Path(args.pseudo_script).resolve()
    if not edges_script.is_file() or not cfg_script.is_file() or not pseudo_script.is_file():
        raise SystemExit("IDA export scripts missing")

    i64s = sorted(fw_dir.glob("*.i64"))
    if not i64s:
        raise SystemExit(f"no .i64 files under {fw_dir}")

    env = os.environ.copy()
    env["IDA_EXPORT_DIR"] = str(work_out)
    if args.pseudo_targets:
        env["IDA_PSEUDO_TARGETS_FILE"] = str(Path(args.pseudo_targets).resolve())
    for i64 in i64s:
        run([str(idat), "-A", f"-S{edges_script}", str(i64)], env)
        run([str(idat), "-A", f"-S{cfg_script}", str(i64)], env)
        run([str(idat), "-A", f"-S{pseudo_script}", str(i64)], env)

    edge_files = sorted(work_out.glob("*.call_edges.jsonl"))
    cfg_files = sorted(work_out.glob("*.cfg.jsonl"))
    pseudo_files = sorted(work_out.glob("*.pseudo.jsonl"))
    edge_rows = concat_jsonl(edge_files, Path(args.edge_out).resolve())
    cfg_rows = concat_jsonl(cfg_files, Path(args.cfg_out).resolve())
    pseudo_rows = concat_jsonl(pseudo_files, Path(args.pseudo_out).resolve())
    print({"db_count": len(i64s), "edge_files": len(edge_files), "cfg_files": len(cfg_files), "pseudo_files": len(pseudo_files), "edge_rows": edge_rows, "cfg_rows": cfg_rows, "pseudo_rows": pseudo_rows})
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
