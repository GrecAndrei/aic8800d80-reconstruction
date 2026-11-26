#!/usr/bin/env python3
"""post_compose.py — the mechanical rules that turn compose output into src/<image>/main.c.

`fwstruct compose` runs this after it writes the four main.c files, so one
command produces the tracked source. Each step is a standalone tool with its
own documentation; the order here is the order they depend on each other:
call sites are rebound first so heal_composed casts the calls whose callee
prototype differs, and the remaining rules read the healed text.

  --check  run every step's --check (heal_composed: the file compiles) and
           exit 1 if any step would still change a file.
"""
import argparse
import subprocess
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent

# (script, arguments, has --check)
STEPS = [
    ("callsite_targets.py", ["--before-heal"], True),
    ("absolute_memory.py", [], True),
    ("heal_composed.py", [], True),
    ("heal_two_d_subscript.py", [], True),
    ("libmatch.py", ["scan"], True),
    ("libmatch.py", ["apply"], True),
    ("volatile_pointees.py", [], True),
    ("heap_boundary_literal.py", [], True),
    ("patch_tailcall_args.py", [], True),
    ("callsite_targets.py", [], True),
    ("periph_symbols.py", [], True),
    ("asm_returns.py", [], True),
    ("call_cast_returns.py", [], True),
    ("double_args.py", [], True),
    ("spilled_scalar_inputs.py", [], True),
    ("float_bits.py", [], True),
    ("stack_frames.py", [], True),
    ("rom_copy_frames.py", [], True),
    ("dword_compares.py", [], True),
    ("timer_signed_diffs.py", [], True),
    ("tick_signed_cmps.py", [], True),
    ("arm_shifts.py", [], True),
    ("float_compares.py", [], True),
    ("signed_muls.py", [], True),
    ("signed_halfwords.py", [], True),
    ("libc_names.py", [], True),
    ("find_ext_strncasecmp.py", [], True),
    ("ipv4_dot_libc.py", [], True),
    ("jump_trampolines.py", [], True),
    ("uncast_memset_zero.py", [], True),
    ("drop_spurious_fragments.py", [], True),
    ("validate_forward_args.py", [], True),
    ("format_hd_signextend.py", [], True),
    ("format_scratch_frame.py", [], True),
    ("frame_pair_forward.py", [], True),
    ("triple_arg_forward.py", [], True),
    ("first_arg_forward.py", [], True),
    ("single_input_contracts.py", [], True),
    ("fmac_zero_inputs.py", [], True),
    ("rx_queue_contract.py", [], True),
    ("alloc_result_forward.py", [], True),
    ("tailcall_inputs.py", [], True),
    ("zero_input_prototypes.py", [], True),
    ("timer_target_forward.py", [], True),
    ("mrs_ipsr.py", [], True),
    ("rf_config_frame.py", [], True),
    # demonolithize physically relocates the healed text into module slices;
    # every rule above reads the monolithic main.c
    ("demonolithize.py", [], True),
    # luna applications run AFTER demonolithize — they edit module slices.
    # deterministic given the analysis cache; coverage grows with the batch
    ("luna_rename_apply.py", [], True),
    ("luna_semantics_apply.py", [], True),
]


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    failed = []
    for script, extra, _ in STEPS:
        cmd = [sys.executable, str(TOOLS / script), *extra]
        if args.check:
            cmd.append("--check")
        print(f"[post_compose] {script} {' '.join(extra)}".rstrip(), flush=True)
        rc = subprocess.run(cmd).returncode
        if rc:
            failed.append(" ".join([script, *extra]))
            if not args.check:
                print(f"[post_compose] {script} failed (exit {rc})", file=sys.stderr)
                return rc
    if failed:
        print("[post_compose] pending: " + "; ".join(failed), file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
