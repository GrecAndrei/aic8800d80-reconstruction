#!/usr/bin/env python3
"""fidelity_probe.py — evaluate selected composed functions with fidelity_meter semantics.

This is the small-input counterpart of tools/fidelity_meter.py: it loads the
same original binary, linked reconstruction ELF, bootstate, RAM comparison,
MMIO comparison and r0 rules, but runs only the functions named on the command
line. Intended for mechanical-rule iteration; it changes no source or build
artifact.

Examples:
  python3 tools/fidelity_probe.py --image fmacfw_8800d80_h_u02 rf_reg_0x1b call_patch_hook_0
  python3 tools/fidelity_probe.py --image fmacfw_h_u02 --vectors bare_zero 0x114a6c
"""
import argparse
import json
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path.insert(0, str(TOOLS))

import aic8800d80_emulator as emu
import corpus_sweep as cs
import fidelity_meter as fm
import linked_recon_run as lrr

LONG = {v: k for k, v in lrr.SHORT.items()}
LONG.update({k: k for k in lrr.SHORT})


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--image", required=True, choices=sorted(LONG))
    ap.add_argument("--vectors", default=",".join(fm.DEFAULT_VECTORS))
    ap.add_argument("--max-insns", type=int, default=50000)
    ap.add_argument("--boot-insns", type=int, default=300000)
    ap.add_argument("select", nargs="+", help="function marker/name or analysis-space hex address")
    args = ap.parse_args()

    image = LONG[args.image]
    short = lrr.SHORT[image]
    vectors = tuple(v.strip() for v in args.vectors.split(",") if v.strip())
    bad = [v for v in vectors if v not in fm.ALL_VECTORS]
    if bad:
        ap.error(f"unknown vectors: {bad}")

    elf_path = lrr.FULL_LINK / image / f"{image}.full.elf"
    if not elf_path.is_file():
        raise SystemExit(f"missing {elf_path}; run the linked-reconstruction build first")
    elf_info = fm.load_elf_info(elf_path, image=image)
    bootstate = cs.capture_bootstate(image, args.boot_insns)
    parsed = fm.parse_composed_functions((fm.REPO / "src" / short / "main.c").read_text(errors="replace"))
    proto_by_addr = {int(r["address"], 16): r for r in fm.prototype_infer.scan_image(image)}
    func_meta = {}
    for k, v in parsed.items():
        prow = proto_by_addr.get(k, {})
        machine_class = prow.get("class", "unknown")
        contract = prow.get("contract")
        if contract == "void_machine":
            r0_exclude = True
        elif contract == "nonvoid_machine":
            r0_exclude = False
        else:
            r0_exclude = machine_class in {"exact_nullsub", "nullsub_tail_alias"}
        func_meta[k] = {
            "marker": v["marker"],
            "is_void": v["is_void"],
            "is_void_ub": v["is_void_ub"],
            "machine_class": machine_class,
            "contract": contract,
            "param_types": v["param_types"],
            "r0_exclude": r0_exclude,
        }

    keys = []
    for sel in args.select:
        try:
            key = int(sel, 0)
            if key not in func_meta:
                raise SystemExit(f"{sel}: no composed function at {key:#x} in {short}")
        except ValueError:
            matches = [k for k, v in parsed.items() if sel in (v["marker"], v["c_name"])]
            if len(matches) != 1:
                raise SystemExit(f"{sel}: {len(matches)} matches in {short}")
            key = matches[0]
        if key not in keys:
            keys.append(key)

    fm._init_worker(image, bootstate, elf_info, func_meta, vectors, args.max_insns)
    rows = [fm._eval_function(k) for k in keys]
    for row in rows:
        print(json.dumps(row, sort_keys=True))
    return 1 if any(v.get("status") == "DIFFER" for r in rows for v in r["vectors"].values()) else 0


if __name__ == "__main__":
    sys.exit(main())
