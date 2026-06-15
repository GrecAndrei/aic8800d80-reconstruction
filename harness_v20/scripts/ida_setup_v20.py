"""v20 IDA setup: v19 + apply struct types via idc.parse_decl.

Run: idat -A -B -L<log> -S<harness_v20/scripts/ida_setup_v20.py> -o<idb> harness_v19/elf/<image>.elf
"""
import json
import os
import sys
from pathlib import Path
import idc, idaapi, idautils, ida_funcs, ida_name, ida_segment, ida_typeinf

ROOT = Path(os.environ.get('V19_ROOT', 'harness_v19'))
V20_ROOT = Path(os.environ.get('V20_ROOT', 'harness_v20'))


def log(msg):
    print(f"[v20] {msg}", flush=True)


def find_image_from_input():
    p = idaapi.get_input_file_path()
    return Path(p).stem


def apply_segment_perms():
    for seg_idx in range(ida_segment.get_segm_qty()):
        seg = ida_segment.getnseg(seg_idx)
        if seg:
            seg.perm = ida_segment.SEGPERM_READ | ida_segment.SEGPERM_WRITE | ida_segment.SEGPERM_EXEC
    seg0 = ida_segment.getnseg(0)
    if seg0 and seg0.end_ea < 0x200000:
        try:
            ida_segment.set_segm_end(seg0.start_ea, 0x200000, idaapi.SEGMOD_KEEP | idaapi.SEGMOD_SPARSE)
            log(f"Extended LOAD to 0x200000 (sparse)")
        except Exception as e:
            log(f"Failed to extend LOAD: {e}")
    try:
        for seg_idx in range(ida_segment.get_segm_qty()):
            seg = ida_segment.getnseg(seg_idx)
            if seg and seg.start_ea == 0x40000000:
                log("MMIO segment already exists")
                break
        else:
            ida_segment.add_segm(0, 0x40000000, 0x60000000, "MMIO", "DATA")
            seg = ida_segment.get_segm_by_name("MMIO")
            if seg:
                seg.perm = ida_segment.SEGPERM_READ | ida_segment.SEGPERM_WRITE
                seg.bitness = 1
                log("Added MMIO segment 0x40000000-0x60000000")
    except Exception as e:
        log(f"MMIO segment add failed: {e}")


def add_mmio_named_regs(mmio_db):
    count = 0
    for entry in mmio_db:
        if not isinstance(entry, dict):
            continue
        try:
            addr = int(entry.get('addr', '0'), 16)
            name = entry.get('name', '')
        except:
            continue
        if 0x40000000 <= addr < 0x60000000 and name:
            try:
                r = ida_name.set_name(addr, name, ida_name.SN_FORCE)
                if r:
                    count += 1
            except:
                pass
    log(f"MMIO names applied: {count}")
    return count


def add_struct_types_simple(structs):
    """Add struct types by parsing one declaration at a time with idc.parse_decl."""
    n = 0
    n_failed = 0
    for sname, fields in structs.items():
        # Build C decl
        decl = f"struct {sname} {{"
        for fname, off in fields.items():
            if isinstance(off, (list, tuple)):
                off = off[0] if off else 0
            # Guess type from offset and name
            # Default to uint32_t
            t = 'uint32_t'
            decl += f" {t} {fname};  // offset 0x{off:x}\n"
        decl += " }"
        # Use idc.parse_decl - returns (type_str, type_tif)
        try:
            tstr, tif = idc.parse_decl(decl, idc.PT_SILENT)
            if tif:
                # Apply
                if ida_typeinf.set_named_type(None, sname, ida_typeinf.NTF_REPLACE, tif):
                    n += 1
                else:
                    n_failed += 1
            else:
                n_failed += 1
        except Exception as e:
            n_failed += 1
            log(f"  parse fail for {sname}: {e}")
    log(f"Structs: applied={n} failed={n_failed}")
    return n


def main():
    img = find_image_from_input()
    log(f"Image: {img}")
    apply_segment_perms()
    mmio_p = V20_ROOT / 'mmio_registers.json'
    if not mmio_p.exists():
        mmio_p = ROOT / 'mmio_registers.json'
    if mmio_p.exists():
        mmio = json.load(open(mmio_p))
        add_mmio_named_regs(mmio)
    structs_p = V20_ROOT / 'structs/aic8800d80_v20_structs.json'
    if structs_p.exists():
        structs = json.load(open(structs_p))
        add_struct_types_simple(structs)
    log("Setup complete")
    try:
        idaapi.save_database("", 0)
    except Exception as e:
        log(f"Save failed: {e}")


if __name__ == "__main__":
    main()
