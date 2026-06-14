"""v19 IDA setup: load ELF, verify modes, seed functions, apply LLM names/docstrings.

Run: idat -A -B -L<log> -S<harness_v19/scripts/ida_setup_v19.py> -o<idb> harness_v19/elf/<image>.elf

Env:
  V19_ROOT - path to harness_v19 (default: harness_v19)
"""
import json
import os
import sys
from pathlib import Path
import idc, idaapi, idautils, ida_funcs, ida_name

ROOT = Path(os.environ.get('V19_ROOT', 'harness_v19'))


def log(msg):
    print(f"[v19] {msg}", flush=True)


def load_bin_data(img):
    """Load firmware binary for byte-level checks."""
    bin_map = {
        'fmacfw_8800d80_h_u02_bin': 'fmacfw_8800d80_h_u02',
        'fmacfw_8800d80_u02_bin': 'fmacfw_8800d80_u02',
        'fmacfwbt_8800d80_u02_bin': 'fmacfwbt_8800d80_u02',
        'lmacfw_rf_8800d80_u02_bin': 'lmacfw_rf_8800d80_u02',
    }
    base = bin_map.get(img)
    if not base:
        return b''
    p = ROOT.parent / 'inputs' / 'firmware' / f'{base}.bin'
    return p.read_bytes() if p.exists() else b''


def addr_has_code(bin_data, addr, base_addr=0x100000, n_bytes=4):
    """Check if address has non-zero code (likely real function, not BSS)."""
    off = addr - base_addr
    if off < 0 or off + n_bytes > len(bin_data):
        return False
    chunk = bin_data[off:off + n_bytes]
    return any(b != 0 for b in chunk)


# Wait for analysis
idaapi.auto_wait()
log("Analysis complete")

# Get segment
seg = idaapi.getnseg(0)
if not seg:
    log("ERROR: no segment")
    idc.qexit(1)
log(f"Segment: {hex(seg.start_ea)}-{hex(seg.end_ea)} size={seg.size()}")

# Verify ARM/Thumb modes at known addresses
ivt_t = idc.get_sreg(seg.start_ea, 'T')
text_t = idc.get_sreg(seg.start_ea + 0x200, 'T')
log(f"T-reg: IVT={ivt_t} (0=ARM) text={text_t} (1=Thumb)")

# Get image basename from input file path
input_path = idaapi.get_input_file_path()
img = None
for k in ['fmacfw_8800d80_h_u02', 'fmacfw_8800d80_u02', 'fmacfwbt_8800d80_u02', 'lmacfw_rf_8800d80_u02']:
    if k in input_path:
        img = k + '_bin'
        break
if not img:
    log(f"ERROR: unknown image from {input_path}")
    idc.qexit(1)
log(f"Image: {img} (from {input_path})")

# Load bin data
bin_data = load_bin_data(img)
log(f"Bin size: {len(bin_data)} bytes")

# === Phase 1: Seed function boundaries (only real code) ===
bpath = ROOT / 'boundaries.json'
img_fns = []
n_skipped_bss = 0
if bpath.exists():
    boundaries = json.loads(bpath.read_text())
    img_fns_raw = boundaries.get(img, [])
    log(f"Raw boundaries: {len(img_fns_raw)}")
    # Filter: only keep addresses with real code
    for addr_s, fname in img_fns_raw:
        try:
            addr = int(addr_s, 16)
        except ValueError:
            continue
        if not addr_has_code(bin_data, addr):
            n_skipped_bss += 1
            continue
        img_fns.append((addr_s, fname))
    img_fns.sort(key=lambda x: int(x[0], 16))
    log(f"Real-code boundaries: {len(img_fns)} (skipped {n_skipped_bss} BSS)")

# Add functions (start, end) pairs
n_added = n_existed = n_failed = 0
for i, (addr_s, fname) in enumerate(img_fns):
    try:
        start = int(addr_s, 16)
    except ValueError:
        continue
    if i + 1 < len(img_fns):
        end = int(img_fns[i+1][0], 16)
    else:
        end = seg.end_ea
    if start >= end:
        continue
    if ida_funcs.get_func(start):
        n_existed += 1
        continue
    try:
        if ida_funcs.add_func(start, end):
            n_added += 1
        else:
            n_failed += 1
    except Exception:
        n_failed += 1
log(f"Boundaries: added={n_added} existed={n_existed} failed={n_failed}")

# === Phase 2: Apply LLM names (only at valid code addresses) ===
npath = ROOT / 'llm_names.json'
n_names = n_failed_names = n_skipped_invalid = 0
if npath.exists():
    names = json.loads(npath.read_text())
    for key, n in names.items():
        if not key.startswith(img + '|'):
            continue
        addr_s = key.split('|')[1]
        try:
            addr = int(addr_s, 16)
        except ValueError:
            continue
        if addr < seg.start_ea or addr >= seg.end_ea:
            n_skipped_invalid += 1
            continue
        if not addr_has_code(bin_data, addr):
            n_skipped_invalid += 1
            continue
        new_name = n['name']
        if not new_name or not (new_name[0].isalpha() or new_name[0] == '_'):
            n_skipped_invalid += 1
            continue
        safe = ''.join(c if (c.isalnum() or c == '_') else '_' for c in new_name)
        try:
            ok = ida_name.set_name(addr, safe, ida_name.SN_FORCE)
            if ok:
                n_names += 1
            else:
                n_failed_names += 1
        except Exception:
            n_failed_names += 1
log(f"Names: applied={n_names} failed={n_failed_names} skipped_invalid={n_skipped_invalid}")

# === Phase 3: Apply docstrings as comments (only at valid code addresses) ===
n_docs = 0
if npath.exists():
    names = json.loads(npath.read_text())
    for key, n in names.items():
        if not key.startswith(img + '|'):
            continue
        addr_s = key.split('|')[1]
        try:
            addr = int(addr_s, 16)
        except ValueError:
            continue
        if addr < seg.start_ea or addr >= seg.end_ea:
            continue
        if not addr_has_code(bin_data, addr):
            continue
        doc = n.get('docstring', '')
        if not doc:
            continue
        try:
            name = n.get('name', '')
            sub = n.get('subsystem', '?')
            cmt = f"{name} [{sub}]: {doc}"
            idc.set_func_cmt(addr, cmt, 0)  # 0 = repeatable
            n_docs += 1
        except Exception:
            pass
log(f"Docs: applied={n_docs}")

# Final stats
n_funcs = len(list(idautils.Functions()))
log(f"Final: {n_funcs} functions in {img}")
log(f"DB saved")
