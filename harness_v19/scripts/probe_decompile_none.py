"""Probe why Hex-Rays returns None for the 'decompile_none' functions."""
import os
import idc, idaapi, idautils, ida_funcs, ida_bytes, ida_ua

def log(msg):
    print(f"[probe] {msg}", flush=True)

idaapi.auto_wait()
log("analysis settled")
addrs = [int(a, 16) for a in os.environ.get('PROBE_ADDRS', '').split(',') if a.strip()]
log(f"probing: {[hex(a) for a in addrs]}")

for ea in addrs:
    log(f"--- {ea:#x} ---")
    fn = idaapi.get_func(ea)
    if fn:
        log(f"  func: {fn.start_ea:#x}-{fn.end_ea:#x} flags={fn.flags:#x}")
    else:
        log("  NO function at this address")
    log(f"  is_code={ida_bytes.is_code(ida_bytes.get_flags(ea))} is_data={ida_bytes.is_data(ida_bytes.get_flags(ea))}")
    try:
        log(f"  disasm0: {idc.generate_disasm_line(ea, 0)}")
        log(f"  disasm1: {idc.generate_disasm_line(ea + 2, 0)}")
    except Exception as e:
        log(f"  disasm err: {e}")
    if idaapi.init_hexrays_plugin():
        import ida_hexrays
        fn2 = idaapi.get_func(ea)
        try:
            hf = ida_hexrays.hexrays_failure_t()
            cfunc = ida_hexrays.decompile_func(fn2, hf, 0)
            if cfunc is None:
                log(f"  decompile_func -> None; hf.code={hf.code} errea={hf.errea:#x} str={hf.str!r} desc={hf.desc()!r}")
            else:
                pseudo = str(cfunc)
                log(f"  decompile_func -> OK ({len(pseudo)} chars)")
                log(f"  pseudo head: {pseudo[:120]!r}")
        except Exception as e:
            log(f"  decompile_func EXCEPTION: {type(e).__name__}: {e}")
    else:
        log("  Hex-Rays not available")

log("done")
