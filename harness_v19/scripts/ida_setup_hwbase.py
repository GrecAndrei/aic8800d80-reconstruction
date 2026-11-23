"""v19 setup variant for a HARDWARE-base (0x120000) IDB.

Same segment setup as ida_setup_v19.py, but the boundary seeds from
boundaries.json (analysis-space addresses) are shifted +0x20000 into
hardware space so function creation lands on the real starts.
Run: idat -A -B -L<log> -S<this script> -o<idb> harness_v19/elf/<img>_hw.elf
"""
import json
import os
from pathlib import Path
import idc, idaapi, ida_segment, ida_name

HW_OFFSET = 0x20000
ROOT = Path(os.environ.get('V19_ROOT', 'harness_v19'))


def log(msg):
    print(f"[v19-hw] {msg}", flush=True)


idaapi.auto_wait()
seg = idaapi.getnseg(0)
if seg is None:
    log("ERROR: no segment")
    idc.qexit(1)
log(f"Segment: {hex(seg.start_ea)}-{hex(seg.end_ea)}")
seg.perm = ida_segment.SEGPERM_READ | ida_segment.SEGPERM_WRITE | ida_segment.SEGPERM_EXEC

new_end = 0x200000
if seg.end_ea < new_end:
    ida_segment.set_segm_end(seg.start_ea, new_end,
                             ida_segment.SEGMOD_KEEP | ida_segment.SEGMOD_SPARSE)
    seg = idaapi.getnseg(0)
    seg.perm = ida_segment.SEGPERM_READ | ida_segment.SEGPERM_WRITE | ida_segment.SEGPERM_EXEC
    log(f"Extended LOAD to {hex(new_end)}")

if not ida_segment.get_segm_by_name("MMIO"):
    r = ida_segment.add_segm(0, 0x40000000, 0x60000000, "MMIO", "DATA")
    mmio_seg = ida_segment.get_segm_by_name("MMIO")
    if mmio_seg:
        mmio_seg.perm = ida_segment.SEGPERM_READ | ida_segment.SEGPERM_WRITE
    log(f"Added MMIO segment: {r}")

# Image key from input path
input_path = idaapi.get_input_file_path()
img = None
for k in ['fmacfw_8800d80_h_u02', 'fmacfw_8800d80_u02', 'fmacfwbt_8800d80_u02',
          'lmacfw_rf_8800d80_u02']:
    if k in input_path:
        img = k + '_bin'
        break
if not img:
    log(f"ERROR: unknown image from {input_path}")
    idc.qexit(1)
log(f"Image: {img}")

# MMIO register names (absolute addresses, base-independent)
m = json.loads((ROOT / 'mmio_registers.json').read_text())
n_ok = n_fail = 0
for entry in m:
    try:
        if ida_name.set_name(int(entry['addr'], 16), entry['name'], ida_name.SN_FORCE):
            n_ok += 1
        else:
            n_fail += 1
    except Exception:
        n_fail += 1
log(f"MMIO names: applied={n_ok} failed={n_fail}")

# Boundary seeds shifted into hardware space
bpath = ROOT / 'boundaries.json'
if bpath.exists():
    boundaries = json.loads(bpath.read_text())
    for addr_s, fname in boundaries.get(img, []):
        try:
            addr = int(addr_s, 16) + HW_OFFSET
        except ValueError:
            continue
        if idaapi.get_func(addr) is None:
            idc.add_func(addr)
        ida_name.set_name(addr, fname, ida_name.SN_FORCE)
    log(f"Seeded {len(boundaries.get(img, []))} shifted boundaries")

log("setup done")
