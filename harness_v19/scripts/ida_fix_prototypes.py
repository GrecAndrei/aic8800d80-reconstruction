#!/usr/bin/env python3
"""Targeted prototype fix + re-decompile for units whose Hex-Rays output lost
their arguments (decompiled as ``void __fastcall sub_X()`` with uninitialized
r0-r3 locals, so every call site also lost its arguments).

For each target unit:
  1. parse_decl + apply_tinfo(TINFO_DEFINITE) to set the REAL prototype
     (derived from the original disassembly: register args + stack args),
  2. re-decompile with DECOMP_NO_CACHE,
  3. shift firmware-internal address-bearing names to analysis space when the
     IDB is at the hardware base (0x120000),
  4. overwrite harness_v19/decompiled/<img>/<analysis_addr>_<name>.c.

Also re-decompiles the listed CALLERS so their call sites regain the args
(Hex-Rays drops call args when the callee's prototype says ``()``).

Env:
  DIMG      - image key, e.g. lmacfw_rf_8800d80_u02_bin (output dir)
  DFIXES    - JSON list of {addr, proto, size, name} (name = output file base,
              analysis-space, e.g. "sub_100A80")
  DREDECLS  - comma-separated analysis-space addrs of callers to re-decompile
              (output file name = analysis-space sub_ name)
  DVOLATILES - comma-separated absolute addrs to type as `volatile unsigned int`
              before decompiling (e.g. tick-counter MMIO `0x40501010`)
  DHW       - "1" when the IDB is at the hardware base (targets += 0x20000)
"""
import json
import os
import re
from pathlib import Path
import idc, idaapi, idautils, ida_funcs, ida_hexrays, ida_typeinf

HW_OFFSET = 0x20000
ANALYSIS_BASE = 0x100000
OUT = Path(os.environ.get("V19_ROOT", "harness_v19")) / "decompiled"


def log(msg):
    print(f"[fixproto] {msg}", flush=True)


img = os.environ.get("DIMG", "")
fixes = json.loads(os.environ.get("DFIXES", "[]"))
reds = [int(a, 16) for a in os.environ.get("DREDECLS", "").split(",") if a.strip()]
vols = [int(a, 16) for a in os.environ.get("DVOLATILES", "").split(",") if a.strip()]
hw = os.environ.get("DHW", "0") == "1"
shift = lambda a: a + HW_OFFSET if hw else a

idaapi.auto_wait()
log(f"image={img} fixes={len(fixes)} reds={[hex(a) for a in reds]} hw={hw}")

seg = idaapi.getnseg(0)
log(f"segment {seg.start_ea:#x}-{seg.end_ea:#x}")

if not idaapi.init_hexrays_plugin():
    log("Hex-Rays unavailable")
    idc.qexit(1)

til = ida_typeinf.get_idbtil() if hasattr(ida_typeinf, "get_idbtil") else None
for va in vols:
    vtif = ida_typeinf.tinfo_t()
    ida_typeinf.parse_decl(vtif, til, "volatile unsigned int x;", ida_typeinf.PT_SIL)
    ok = ida_typeinf.apply_tinfo(va, vtif, ida_typeinf.TINFO_DEFINITE)
    log(f"  volatile set at {va:#x}: ok={ok}")

out_dir = OUT / img
out_dir.mkdir(parents=True, exist_ok=True)

# shift: firmware-internal hardware-space address -> analysis-space name.
addr_re = re.compile(r"\b(sub_|dword_|word_|byte_|unk_|off_|qword_|algn_)([0-9A-Fa-f]{4,8})\b")

def to_analysis(m):
    kind, val = m.group(1), int(m.group(2), 16)
    if ANALYSIS_BASE <= val < 0x200000:
        return f"{kind}{val - HW_OFFSET:X}"
    return f"{kind}{val:X}"

results = []


def write_out(ana_addr: int, name: str, pseudo: str, size: int) -> Path:
    if hw:
        pseudo = addr_re.sub(to_analysis, pseudo)
    fname_safe = "".join(c if (c.isalnum() or c in "_-") else "_" for c in name)[:80]
    out_path = out_dir / f"{ana_addr:x}_{fname_safe}.c"
    out_path.write_text(f"// {name} @ {hex(ana_addr)}, size {size} bytes\n" + pseudo + "\n")
    return out_path


def decompile_at(ea: int) -> str | None:
    fn = idaapi.get_func(ea)
    if fn is None:
        log(f"  NO FUNCTION at {ea:#x}")
        return None
    hf = ida_hexrays.hexrays_failure_t()
    cfunc = ida_hexrays.decompile(fn.start_ea, hf, ida_hexrays.DECOMP_NO_CACHE)
    if cfunc is None:
        log(f"  decompile None at {ea:#x}: {hf.str!r}")
        return None
    return str(cfunc)


for fx in fixes:
    addr = int(fx["addr"], 16)
    proto = fx["proto"]
    size = int(fx.get("size", 0))
    out_name = fx.get("name", "")
    ea = shift(addr)
    tif = ida_typeinf.tinfo_t()
    til = ida_typeinf.get_idbtil() if hasattr(ida_typeinf, "get_idbtil") else None
    err = ida_typeinf.parse_decl(tif, til, proto + ";", ida_typeinf.PT_SIL)
    if not tif.is_correct():
        log(f"  parse_decl FAILED for {proto!r}: {err}")
        results.append({"addr": fx["addr"], "status": "parse_decl_fail", "err": str(err)})
        continue
    if not ida_typeinf.apply_tinfo(ea, tif, ida_typeinf.TINFO_DEFINITE):
        log(f"  apply_tinfo FAILED at {ea:#x}")
        results.append({"addr": fx["addr"], "status": "apply_tinfo_fail"})
        continue
    log(f"  prototype set at {ea:#x}: {proto}")
    pseudo = decompile_at(ea)
    if pseudo is None:
        results.append({"addr": fx["addr"], "status": "decompile_none"})
        continue
    fn = idaapi.get_func(ea)
    size = fn.end_ea - fn.start_ea if fn else size
    p = write_out(addr, out_name, pseudo, size)
    log(f"  wrote {p.name} ({len(pseudo)} chars)")
    results.append({"addr": fx["addr"], "status": "ok", "out": p.name, "len": len(pseudo)})

for ea_a in reds:
    ea = shift(ea_a)
    pseudo = decompile_at(ea)
    if pseudo is None:
        results.append({"addr": hex(ea_a), "status": "decompile_none"})
        continue
    fn = idaapi.get_func(ea)
    size = fn.end_ea - fn.start_ea if fn else 0
    idb_name = idc.get_func_name(ea) or f"sub_{ea:x}"
    out_name = re.sub(r"^sub_[0-9A-Fa-f]+$", f"sub_{ea_a:X}", idb_name)
    p = write_out(ea_a, out_name, pseudo, size)
    log(f"  wrote {p.name} (redecl {idb_name}) ({len(pseudo)} chars)")
    results.append({"addr": hex(ea_a), "status": "ok", "out": p.name, "len": len(pseudo)})

(out_dir / "_fix_prototypes_log.json").write_text(json.dumps({"image": img, "results": results}, indent=1))
log(f"done: {[r['status'] for r in results]}")
