"""v19 IDA decompile: iterate all functions, save Hex-Rays pseudo-C per function.

Run: idat -A -B -L<log> -S<harness_v19/scripts/ida_decompile_v19.py> -o<idb> harness_v19/elf/<image>.elf

Reads the IDB set up by ida_setup_v19.py. For each function, decompiles and
saves pseudo-C to harness_v19/decompiled/<img>/<func_addr>_<func_name>.c

Tracks per-function: name, addr, size, decompile_status, error_msg
Outputs: harness_v19/decompiled/<img>/_decompile_log.json
"""
import json
import os
import sys
import time
import traceback
from pathlib import Path
import idc, idaapi, idautils, ida_funcs, ida_name

ROOT = Path(os.environ.get('V19_ROOT', 'harness_v19'))


def log(msg):
    print(f"[v19-dec] {msg}", flush=True)


# Wait for analysis to settle
idaapi.auto_wait()
log("Decompile start")

# Get segment
seg = idaapi.getnseg(0)
if not seg:
    log("ERROR: no segment")
    idc.qexit(1)

# Get image basename
input_path = idaapi.get_input_file_path()
img = None
for k in ['fmacfw_8800d80_h_u02', 'fmacfw_8800d80_u02', 'fmacfwbt_8800d80_u02', 'lmacfw_rf_8800d80_u02']:
    if k in input_path:
        img = k + '_bin'
        break
if not img:
    log(f"ERROR: unknown image from {input_path}")
    idc.qexit(1)
log(f"Image: {img}")

# Output directory
out_dir = ROOT / 'decompiled' / img
out_dir.mkdir(parents=True, exist_ok=True)

# Get all functions
funcs = list(idautils.Functions())
funcs.sort()
log(f"Total functions: {len(funcs)}")

# Stats
stats = {
    'ok': 0,
    'fail_decompile': 0,
    'fail_too_small': 0,
    'skipped_no_func': 0,
    'no_hexrays': 0,
}
results = []

# Check Hex-Rays is available
if not idaapi.init_hexrays_plugin():
    log("Hex-Rays plugin not available!")
    idc.qexit(1)
log("Hex-Rays initialized")

t0 = time.time()
for i, ea in enumerate(funcs):
    fn = idaapi.get_func(ea)
    if not fn:
        stats['skipped_no_func'] += 1
        continue
    size = fn.end_ea - fn.start_ea
    name = idc.get_func_name(ea) or f"sub_{ea:x}"
    fname_safe = ''.join(c if (c.isalnum() or c in '_-') else '_' for c in name)[:80]
    out_path = out_dir / f"{ea:x}_{fname_safe}.c"

    if size < 4:
        # Skip tiny "functions" (alignment padding, etc.)
        stats['fail_too_small'] += 1
        results.append({
            'addr': f"0x{ea:x}", 'name': name, 'size': size,
            'status': 'too_small', 'out': None,
        })
        continue

    # Try to decompile
    try:
        cfunc = idaapi.decompile(ea)
        if cfunc is None:
            stats['fail_decompile'] += 1
            results.append({
                'addr': f"0x{ea:x}", 'name': name, 'size': size,
                'status': 'decompile_none', 'out': None,
            })
            continue
        pseudo = str(cfunc)
        if not pseudo or len(pseudo) < 20:
            stats['fail_decompile'] += 1
            results.append({
                'addr': f"0x{ea:x}", 'name': name, 'size': size,
                'status': 'empty_pseudo', 'out': None,
            })
            continue
        # Write to file
        header = f"// {name} @ {hex(ea)}, size {size} bytes\n"
        # Get repeatable comment if any
        cmt = idc.get_func_cmt(ea, 0)
        if cmt:
            header += f"// Doc: {cmt}\n"
        out_path.write_text(header + pseudo + "\n")
        stats['ok'] += 1
        results.append({
            'addr': f"0x{ea:x}", 'name': name, 'size': size,
            'status': 'ok', 'out': str(out_path),
            'pseudo_len': len(pseudo),
        })
    except Exception as e:
        stats['fail_decompile'] += 1
        err = str(e)[:200]
        results.append({
            'addr': f"0x{ea:x}", 'name': name, 'size': size,
            'status': 'exception', 'error': err, 'out': None,
        })
        if i < 5:
            log(f"  Decompile err on {hex(ea)} {name}: {err}")

    if (i + 1) % 50 == 0:
        elapsed = time.time() - t0
        rate = (i + 1) / elapsed if elapsed > 0 else 0
        log(f"  {i+1}/{len(funcs)} done ({stats['ok']} ok) {rate:.1f}/s, elapsed {elapsed:.1f}s")

# Save log
log_path = out_dir / '_decompile_log.json'
log_data = {
    'img': img,
    'total': len(funcs),
    'stats': stats,
    'results': results,
    'elapsed_s': time.time() - t0,
}
log_path.write_text(json.dumps(log_data, indent=2))
log(f"Done: {stats['ok']} ok / {stats['fail_decompile']} fail / {stats['fail_too_small']} too_small in {time.time()-t0:.1f}s")
log(f"Log: {log_path}")
