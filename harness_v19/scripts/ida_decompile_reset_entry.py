"""Targeted Hex-Rays decompile of the true reset entry at file 0x1a8.

The v19 scan mistakes file 0x100-0x1a7 (padding/header bytes) for the start
of ``start``. The IVT reset vector enters at file 0x1a8. In a hardware-base
IDB (0x120000) the real entry is 0x1201a8 and the function ends at 0x120200,
where the memset/reset-library routine begins. This script moves any covering
function chunk to that boundary, decompiles only the real entry, shifts
firmware-internal address-bearing names back into analysis space, and writes
``harness_v19/decompiled/<img>_bin/1001a8_start.c``.

Env:
  DIMG       image key, e.g. fmacfw_8800d80_u02_bin
  V19_ROOT   harness_v19 root (default: harness_v19)
"""
import json
import os
import re
from pathlib import Path

import idc
import idaapi
import ida_funcs
import ida_hexrays
import ida_name
import ida_segment

HW_RESET = 0x1201A8
HW_END = 0x120200
ANALYSIS_RESET = HW_RESET - 0x20000
SIZE = HW_END - HW_RESET
HW_OFFSET = 0x20000
ANALYSIS_BASE = 0x100000

ROOT = Path(os.environ.get("V19_ROOT", "harness_v19"))
IMG = os.environ.get("DIMG", "")
if not IMG:
    print("[reset-entry] ERROR: DIMG is required", flush=True)
    idc.qexit(1)


def log(msg: str) -> None:
    print(f"[reset-entry] {msg}", flush=True)


idaapi.auto_wait()
seg = idaapi.getnseg(0)
if seg is None:
    log("ERROR: no segment")
    idc.qexit(1)
seg.perm = ida_segment.SEGPERM_READ | ida_segment.SEGPERM_WRITE | ida_segment.SEGPERM_EXEC

if not idaapi.init_hexrays_plugin():
    log("ERROR: Hex-Rays unavailable")
    idc.qexit(1)

# The scan-created artifact function starts at 0x120100 and covers the real
# entry. Move its start to the exact reset-entry boundary. set_func_start is
# sufficient because bytes 0x100-0x1a7 are not code; they become non-function
# padding/header data again.
fn = idaapi.get_func(HW_RESET)
actions = []
if fn is not None and fn.start_ea < HW_RESET:
    old = (fn.start_ea, fn.end_ea)
    rc = ida_funcs.set_func_start(HW_RESET, HW_RESET)
    actions.append({"op": "set_func_start", "old": [hex(old[0]), hex(old[1])], "rc": rc})
    log(f"set_func_start {old[0]:#x}-{old[1]:#x} -> {HW_RESET:#x}: rc={rc}")
elif fn is None:
    if ida_funcs.add_func(HW_RESET, HW_END):
        actions.append({"op": "add_func"})
        log(f"add_func {HW_RESET:#x}-{HW_END:#x}")
    else:
        log("ERROR: no covering function and add_func failed")
        idc.qexit(1)

fn = idaapi.get_func(HW_RESET)
if fn is None or fn.start_ea != HW_RESET:
    log(f"ERROR: reset function boundary not established: {None if fn is None else (hex(fn.start_ea), hex(fn.end_ea))}")
    idc.qexit(1)
if fn.end_ea != HW_END:
    old_end = fn.end_ea
    if not ida_funcs.set_func_end(HW_RESET, HW_END):
        log(f"ERROR: set_func_end {old_end:#x} -> {HW_END:#x} failed")
        idc.qexit(1)
    actions.append({"op": "set_func_end", "old": hex(old_end), "new": hex(HW_END)})
    fn = idaapi.get_func(HW_RESET)

ida_name.set_name(HW_RESET, "start", ida_name.SN_FORCE)
log(f"decompiling {fn.start_ea:#x}-{fn.end_ea:#x}")

hf = ida_hexrays.hexrays_failure_t()
cfunc = ida_hexrays.decompile_func(fn, hf, 0)
if cfunc is None:
    log(f"ERROR: decompile None code={hf.code} errea={hf.errea:#x} {hf.str!r}")
    (ROOT / "decompiled" / IMG / "_reset_entry_log.json").write_text(json.dumps({
        "image": IMG, "status": "decompile_none", "actions": actions,
        "error": {"code": hf.code, "errea": hex(hf.errea), "text": hf.str},
    }, indent=1))
    idc.qexit(1)

pseudo = str(cfunc)

# Names formed from firmware-internal hardware-space addresses are shifted to
# the self-consistent analysis space used by src/ and the naming dataset.
addr_re = re.compile(r"\b(sub_|dword_|word_|byte_|unk_|off_|qword_|algn_)([0-9A-Fa-f]{4,8})\b")

def to_analysis(m: re.Match) -> str:
    kind, val = m.group(1), int(m.group(2), 16)
    if ANALYSIS_BASE <= val < 0x200000:
        return f"{kind}{val - HW_OFFSET:X}"
    return f"{kind}{val:X}"

pseudo = addr_re.sub(to_analysis, pseudo)
out_dir = ROOT / "decompiled" / IMG
out_dir.mkdir(parents=True, exist_ok=True)
out_path = out_dir / f"{ANALYSIS_RESET:x}_start.c"
out_path.write_text(f"// start @ {hex(ANALYSIS_RESET)}, size {SIZE} bytes\n" + pseudo + "\n")
(ROOT / "decompiled" / IMG / "_reset_entry_log.json").write_text(json.dumps({
    "image": IMG,
    "status": "ok",
    "hardware_entry": hex(HW_RESET),
    "analysis_entry": hex(ANALYSIS_RESET),
    "size": SIZE,
    "actions": actions,
    "out": str(out_path),
    "pseudo_len": len(pseudo),
}, indent=1))
log(f"wrote {out_path} ({len(pseudo)} chars)")
