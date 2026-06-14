"""
IDAPython script: create function entries at known addresses, decompile with Hex-Rays, export pseudocode.
Usage: idat -A -S"tools/ida_full_export.py" <binary.i64>
Set env IDA_TARGETS_FILE to a JSON file with [{"name":..., "runtime":"0x..."}] per image.
"""
import idaapi
import ida_auto
import ida_funcs
import ida_hexrays
import ida_lines
import idc
import json
import os
import sys

targets_file = os.environ.get("IDA_TARGETS_FILE", "")
out_dir = os.environ.get("IDA_EXPORT_DIR", "extraction_out/ida_export_live")

if not targets_file or not os.path.isfile(targets_file):
    print(f"IDA full export: no targets file {targets_file}")
    idaapi.qexit(1)

base_name = idaapi.get_root_filename()
out_path = os.path.join(out_dir, f"{base_name}.full_pseudo.jsonl")
os.makedirs(out_dir, exist_ok=True)

targets = json.load(open(targets_file, "r", encoding="utf-8"))
print(f"Loaded {len(targets)} targets for {base_name}")

# Wait for basic auto-analysis
ida_auto.auto_wait()

# Create function entries
created = 0
for t in targets:
    try:
        addr = int(t["runtime"], 16)
    except (ValueError, KeyError):
        continue
    if idc.is_code(ida_funcs.get_flags(addr)):
        continue
    ok = idc.add_func(addr)
    if ok:
        created += 1

print(f"Created {created} new functions (already existed {len(targets) - created})")

# Initialize Hex-Rays
if not ida_hexrays.init_hexrays_plugin():
    print("Hex-Rays unavailable")
    # Still write empty file so caller doesn't hang
    open(out_path, "w", encoding="utf-8").close()
    idaapi.qexit(1)

# Decompile
rows = 0
attempted = 0
failures = 0
with open(out_path, "w", encoding="utf-8") as f:
    for t in targets:
        try:
            addr = int(t["runtime"], 16)
        except (ValueError, KeyError):
            continue
        attempted += 1
        fn = ida_funcs.get_func(addr)
        if not fn:
            failures += 1
            continue
        try:
            cfunc = ida_hexrays.decompile(fn)
        except Exception:
            failures += 1
            continue
        if not cfunc:
            failures += 1
            continue
        try:
            sv = cfunc.get_pseudocode()
            text = "\n".join(ida_lines.tag_remove(line.line) for line in sv)
        except Exception:
            text = str(cfunc)
        if not text.strip():
            continue
        
        rec = {
            "image": base_name,
            "address": hex(addr),
            "name": t.get("name", ""),
            "line_count": len([ln for ln in text.splitlines() if ln.strip()]),
            "pseudocode": text,
        }
        f.write(json.dumps(rec) + "\n")
        rows += 1

print(f"Done: attempted={attempted} rows={rows} failures={failures}")
idaapi.qexit(0)
