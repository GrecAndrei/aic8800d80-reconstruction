"""Targeted decompile at the HARDWARE base 0x120000.

The 6 functions that the v19 pipeline reported as ``decompile_none`` fail
because their switch jump tables are linked for base 0x120000 (their table
entries point exactly +0x20000 past the in-function targets in analysis
space). Loading the ELF at 0x120000 makes the tables resolve, so Hex-Rays
can decompile them.

For each target we:
  1. ensure a function exists (add_func with a known size as a fallback),
  2. decompile via Hex-Rays,
  3. shift every firmware-internal address-bearing name in the body down by
     0x20000 back into ANALYSIS space (so the body integrates with the
     0x100000-space reconstruction),
  4. write ``<analysis_addr>_<name>.c`` into harness_v19/decompiled/<img>/.

Env:
  DIMG       - image key, e.g. fmacfw_8800d80_h_u02_bin (output dir + names)
  DADDRS     - comma-separated hardware-space (0x120000-base) target addrs
  DSIZES     - comma-separated sizes in bytes, parallel to DADDRS
  DNAMES     - comma-separated output names (analysis-space, e.g. sub_135528)
"""
import os
import re
from pathlib import Path
import idc, idaapi, idautils, ida_funcs, ida_segment, ida_hexrays

HW_BASE = 0x120000
ANALYSIS_BASE = 0x100000
HW_OFFSET = HW_BASE - ANALYSIS_BASE  # 0x20000
OUT = Path(os.environ.get("V19_ROOT", "harness_v19")) / "decompiled"


def log(msg):
    print(f"[hwb-dec] {msg}", flush=True)


img = os.environ.get("DIMG", "")
addrs = [int(a, 16) for a in os.environ.get("DADDRS", "").split(",") if a.strip()]
sizes = [int(s, 0) for s in os.environ.get("DSIZES", "").split(",") if s.strip()]
names = [n.strip() for n in os.environ.get("DNAMES", "").split(",") if n.strip()]
log(f"image={img} targets={[hex(a) for a in addrs]}")

# Wait for analysis to settle.
idaapi.auto_wait()
log("analysis settled")

seg = idaapi.getnseg(0)
if seg is None:
    log("ERROR: no segment")
    idc.qexit(1)
log(f"segment {seg.start_ea:#x}-{seg.end_ea:#x}")
seg.perm = ida_segment.SEGPERM_READ | ida_segment.SEGPERM_WRITE | ida_segment.SEGPERM_EXEC

# Hex-Rays must be loaded before decompiling.
if not idaapi.init_hexrays_plugin():
    log("Hex-Rays unavailable")
    idc.qexit(1)

out_dir = OUT / img
out_dir.mkdir(parents=True, exist_ok=True)

# shift: firmware-internal hardware-space address -> analysis-space name.
# Word-anchored (names appear inline in signatures and call sites).
addr_re = re.compile(r"\b(sub_|dword_|word_|byte_|unk_|off_|qword_|algn_)([0-9A-Fa-f]{4,8})\b")

def to_analysis(m):
    kind, val = m.group(1), int(m.group(2), 16)
    if ANALYSIS_BASE <= val < 0x200000:
        return f"{kind}{val - HW_OFFSET:X}"
    return f"{kind}{val:X}"

results = []
for addr, size, name in zip(addrs, sizes, names):
    fn = idaapi.get_func(addr)
    if fn is None:
        # Explicit end fallback: add_func(addr, addr+size).
        end = addr + size
        if not ida_funcs.add_func(addr, end):
            log(f"  add_func FAILED at {addr:#x}")
            results.append({"addr": hex(addr), "name": name, "status": "no_func"})
            continue
        log(f"  add_func at {addr:#x} size {size}")
    else:
        log(f"  function exists {fn.start_ea:#x}-{fn.end_ea:#x}")
    try:
        hf = ida_hexrays.hexrays_failure_t()
        cfunc = ida_hexrays.decompile_func(idaapi.get_func(addr), hf, 0)
        if cfunc is None:
            log(f"  decompile None: code={hf.code} errea={hf.errea:#x} {hf.str!r}")
            results.append({"addr": hex(addr), "name": name, "status": "decompile_none"})
            continue
        pseudo = str(cfunc)
        # Shift firmware-internal address-bearing names to analysis space.
        pseudo = addr_re.sub(to_analysis, pseudo)
        ana = addr - HW_OFFSET
        fname_safe = "".join(c if (c.isalnum() or c in "_-") else "_" for c in name)[:80]
        out_path = out_dir / f"{ana:x}_{fname_safe}.c"
        out_path.write_text(f"// {name} @ {hex(ana)}, size {size} bytes\n" + pseudo + "\n")
        log(f"  wrote {out_path.name} ({len(pseudo)} chars)")
        results.append({"addr": hex(addr), "ana_addr": hex(ana), "name": name,
                        "status": "ok", "out": str(out_path), "pseudo_len": len(pseudo)})
    except Exception as e:
        log(f"  EXCEPTION: {type(e).__name__}: {e}")
        results.append({"addr": hex(addr), "name": name, "status": "exception",
                        "error": str(e)[:200]})

(log_path := out_dir / "_hwbase_decompile_log.json").write_text(
    __import__("json").dumps({"image": img, "targets": len(addrs), "results": results}, indent=1))
log(f"done: {[r['status'] for r in results]}")
