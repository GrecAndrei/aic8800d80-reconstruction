import idaapi
import idautils
import idc
import ida_ua
import ida_auto
import ida_bytes
import ida_segment
import json
import os

OUT_DIR = os.environ.get('IDA_EXPORT_DIR', '.')
os.makedirs(OUT_DIR, exist_ok=True)
base = idaapi.get_root_filename()
func_out = os.path.join(OUT_DIR, f"{base}.functions.jsonl")
edge_out = os.path.join(OUT_DIR, f"{base}.call_edges.jsonl")

def s(x):
    return x if x else ""

ida_auto.auto_wait()

func_cnt = 0
edge_cnt = 0
seen_edges = set()
func_by_insn = {}

with open(func_out, 'w', encoding='utf-8') as ff, open(edge_out, 'w', encoding='utf-8') as ef:
    for f_ea in idautils.Functions():
        fn = idaapi.get_func(f_ea)
        if not fn:
            continue
        name = s(idc.get_func_name(f_ea))
        rec = {
            'image': base,
            'address': hex(f_ea),
            'name': name,
            'end': hex(fn.end_ea),
            'size': int(fn.end_ea - fn.start_ea),
        }
        ff.write(json.dumps(rec) + "\n")
        func_cnt += 1
        for ea in idautils.FuncItems(f_ea):
            func_by_insn[ea] = f_ea

        for insn_ea in idautils.FuncItems(f_ea):
            insn = ida_ua.insn_t()
            if ida_ua.decode_insn(insn, insn_ea) == 0:
                continue
            if not idaapi.is_call_insn(insn):
                continue
            for callee in idautils.CodeRefsFrom(insn_ea, False):
                key = (f_ea, callee)
                if key in seen_edges:
                    continue
                seen_edges.add(key)
                tgt_name = s(idc.get_func_name(callee))
                edge = {
                    'schema_version': '0.1.0',
                    'image': base,
                    'source_addr': hex(f_ea),
                    'source_name': name,
                    'target_addr': hex(callee),
                    'target_name': tgt_name,
                    'evidence': 'ida_headless_call_ref',
                    'source': 'ida_export',
                    'confidence': 0.95,
                }
                ef.write(json.dumps(edge) + "\n")
                edge_cnt += 1

    # Additional recovery pass: scan executable segments for call instructions
    # even when IDA did not recover the containing function.
    for seg_ea in idautils.Segments():
        seg = ida_segment.getseg(seg_ea)
        if not seg:
            continue
        perms = seg.perm
        if (perms & ida_segment.SEGPERM_EXEC) == 0:
            continue
        ea = seg.start_ea
        end = seg.end_ea
        while ea < end:
            flags = ida_bytes.get_full_flags(ea)
            if not ida_bytes.is_code(flags):
                ea = idc.next_head(ea, end)
                if ea == idc.BADADDR:
                    break
                continue
            insn = ida_ua.insn_t()
            n = ida_ua.decode_insn(insn, ea)
            if n <= 0:
                ea = idc.next_head(ea, end)
                if ea == idc.BADADDR:
                    break
                continue
            if idaapi.is_call_insn(insn):
                src_fn = func_by_insn.get(ea, idaapi.get_func(ea).start_ea if idaapi.get_func(ea) else ea)
                src_name = s(idc.get_func_name(src_fn))
                if not src_name:
                    src_name = f"sub_{src_fn:x}"
                for callee in idautils.CodeRefsFrom(ea, False):
                    key = (src_fn, callee)
                    if key in seen_edges:
                        continue
                    seen_edges.add(key)
                    tgt_name = s(idc.get_func_name(callee))
                    if not tgt_name:
                        tgt_name = f"sub_{callee:x}"
                    edge = {
                        'schema_version': '0.1.0',
                        'image': base,
                        'source_addr': hex(src_fn),
                        'source_name': src_name,
                        'target_addr': hex(callee),
                        'target_name': tgt_name,
                        'evidence': 'ida_execseg_callscan',
                        'source': 'ida_export',
                        'confidence': 0.90,
                    }
                    ef.write(json.dumps(edge) + "\n")
                    edge_cnt += 1
            ea = idc.next_head(ea, end)
            if ea == idc.BADADDR:
                break

print(f"IDA export complete: funcs={func_cnt} edges={edge_cnt}")
idaapi.qexit(0)
