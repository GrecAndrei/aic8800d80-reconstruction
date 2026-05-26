import idaapi
import ida_auto
import idautils
import ida_gdl
import idc
import ida_ua
import json
import os
from collections import Counter

OUT_DIR = os.environ.get("IDA_EXPORT_DIR", ".")
os.makedirs(OUT_DIR, exist_ok=True)
base = idaapi.get_root_filename()
out_path = os.path.join(OUT_DIR, f"{base}.cfg.jsonl")


def safe_name(ea):
    n = idc.get_func_name(ea)
    return n if n else ""


ida_auto.auto_wait()

rows = 0
with open(out_path, "w", encoding="utf-8") as f:
    for f_ea in idautils.Functions():
        fn = idaapi.get_func(f_ea)
        if not fn:
            continue
        flow = ida_gdl.FlowChart(fn)
        blocks = list(flow)
        bb_count = len(blocks)
        edge_count = 0
        for bb in blocks:
            edge_count += sum(1 for _ in bb.succs())
        has_loop = edge_count >= bb_count and bb_count > 1
        insn_count = sum(1 for _ in idautils.FuncItems(f_ea))
        callsite_count = 0
        load_count = 0
        store_count = 0
        load_byte_count = 0
        load_half_count = 0
        load_word_count = 0
        store_byte_count = 0
        store_half_count = 0
        store_word_count = 0
        stack_ref_count = 0
        imm_count = 0
        branch_count = 0
        cmp_count = 0
        ret_count = 0
        branch_cond_eq = 0
        branch_cond_ne = 0
        branch_cond_lt = 0
        branch_cond_ge = 0
        branch_cond_gt = 0
        branch_cond_le = 0
        branch_cond_hi = 0
        branch_cond_ls = 0
        branch_cond_other = 0
        alu_arith_count = 0
        alu_logic_count = 0
        alu_shift_count = 0
        alu_mul_count = 0
        pro_push_count = 0
        epi_pop_count = 0
        sp_adjust_count = 0
        reg_hist = Counter()
        mnem_hist = Counter()
        stack_off_hist = Counter()
        stack_off_min = None
        stack_off_max = None
        max_imm = 0
        imm_hist = Counter()
        reg_names = ["r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "r12", "sp", "lr", "pc"]
        for ea in idautils.FuncItems(f_ea):
            mnem = idc.print_insn_mnem(ea)
            if mnem and mnem.lower().startswith("bl"):
                callsite_count += 1
            if mnem:
                ml = mnem.lower()
                mnem_hist[ml] += 1
                if ml.startswith("ldr"):
                    load_count += 1
                    if ml.startswith("ldrb"):
                        load_byte_count += 1
                    elif ml.startswith("ldrh"):
                        load_half_count += 1
                    else:
                        load_word_count += 1
                if ml.startswith("str"):
                    store_count += 1
                    if ml.startswith("strb"):
                        store_byte_count += 1
                    elif ml.startswith("strh"):
                        store_half_count += 1
                    else:
                        store_word_count += 1
                if ml.startswith("b") and not ml.startswith("bl"):
                    branch_count += 1
                    cond = ml[1:]
                    if cond in ("eq",):
                        branch_cond_eq += 1
                    elif cond in ("ne",):
                        branch_cond_ne += 1
                    elif cond in ("lt", "mi"):
                        branch_cond_lt += 1
                    elif cond in ("ge", "pl"):
                        branch_cond_ge += 1
                    elif cond in ("gt",):
                        branch_cond_gt += 1
                    elif cond in ("le",):
                        branch_cond_le += 1
                    elif cond in ("hi",):
                        branch_cond_hi += 1
                    elif cond in ("ls",):
                        branch_cond_ls += 1
                    else:
                        branch_cond_other += 1
                if ml.startswith("cmp") or ml.startswith("cmn") or ml.startswith("tst"):
                    cmp_count += 1
                if ml.startswith("bx") or ml.startswith("pop"):
                    ret_count += 1
                if ml.startswith("add") or ml.startswith("sub") or ml.startswith("adc") or ml.startswith("sbc") or ml.startswith("rsb"):
                    alu_arith_count += 1
                if ml.startswith("and") or ml.startswith("orr") or ml.startswith("eor") or ml.startswith("bic") or ml.startswith("mvn"):
                    alu_logic_count += 1
                if ml.startswith("lsl") or ml.startswith("lsr") or ml.startswith("asr") or ml.startswith("ror"):
                    alu_shift_count += 1
                if ml.startswith("mul") or ml.startswith("mla") or ml.startswith("umull") or ml.startswith("smull"):
                    alu_mul_count += 1
                if ml.startswith("push"):
                    pro_push_count += 1
                if ml.startswith("pop"):
                    epi_pop_count += 1
                if ml.startswith("sub") or ml.startswith("add"):
                    # lightweight SP adjust heuristic from textual operands
                    ot = (idc.print_operand(ea, 0) + " " + idc.print_operand(ea, 1)).lower()
                    if "sp" in ot or "r13" in ot:
                        sp_adjust_count += 1
            insn = ida_ua.insn_t()
            if ida_ua.decode_insn(insn, ea) > 0:
                for i in range(0, 8):
                    op = insn.ops[i]
                    t = int(op.type)
                    # o_displ/o_phrase stack refs often carry SP/FP-based data accesses.
                    if t in (ida_ua.o_displ, ida_ua.o_phrase):
                        txt = idc.print_operand(ea, i).lower()
                        if "sp" in txt or "fp" in txt or "r13" in txt or "r11" in txt:
                            stack_ref_count += 1
                            # Capture likely stack displacement profile for local-layout hints.
                            if t == ida_ua.o_displ:
                                off = int(op.addr)
                                if off > 0x7FFFFFFF:
                                    off -= 0x100000000
                                if -0x400 <= off <= 0x400:
                                    stack_off_hist[off] += 1
                                    if stack_off_min is None or off < stack_off_min:
                                        stack_off_min = off
                                    if stack_off_max is None or off > stack_off_max:
                                        stack_off_max = off
                        for rn in reg_names:
                            if rn in txt:
                                reg_hist[rn] += 1
                    if t == ida_ua.o_imm:
                        imm_count += 1
                        v = int(op.value) & 0xFFFFFFFF
                        imm_hist[v] += 1
                        if v > max_imm:
                            max_imm = v
                    elif t != ida_ua.o_void:
                        txt = idc.print_operand(ea, i).lower()
                        for rn in reg_names:
                            if rn in txt:
                                reg_hist[rn] += 1
        top_imms = [k for k, _ in imm_hist.most_common(4)]
        top_regs = [k for k, _ in reg_hist.most_common(6)]
        top_stack_offsets = [k for k, _ in stack_off_hist.most_common(6)]
        top_mnems = [k for k, _ in mnem_hist.most_common(8)]
        xrefs_to = sum(1 for _ in idautils.CodeRefsTo(f_ea, False))
        xrefs_from = 0
        for ea in idautils.FuncItems(f_ea):
            xrefs_from += sum(1 for _ in idautils.CodeRefsFrom(ea, False))
        frame_size = int(idc.get_frame_size(f_ea))
        rec = {
            "image": base,
            "address": hex(f_ea),
            "name": safe_name(f_ea),
            "bb_count": bb_count,
            "edge_count": edge_count,
            "insn_count": insn_count,
            "callsite_count": callsite_count,
            "xrefs_to": xrefs_to,
            "xrefs_from": xrefs_from,
            "frame_size": frame_size,
            "has_loop": bool(has_loop),
            "load_count": load_count,
            "store_count": store_count,
            "load_byte_count": load_byte_count,
            "load_half_count": load_half_count,
            "load_word_count": load_word_count,
            "store_byte_count": store_byte_count,
            "store_half_count": store_half_count,
            "store_word_count": store_word_count,
            "stack_ref_count": stack_ref_count,
            "imm_count": imm_count,
            "branch_count": branch_count,
            "branch_cond_eq": branch_cond_eq,
            "branch_cond_ne": branch_cond_ne,
            "branch_cond_lt": branch_cond_lt,
            "branch_cond_ge": branch_cond_ge,
            "branch_cond_gt": branch_cond_gt,
            "branch_cond_le": branch_cond_le,
            "branch_cond_hi": branch_cond_hi,
            "branch_cond_ls": branch_cond_ls,
            "branch_cond_other": branch_cond_other,
            "cmp_count": cmp_count,
            "ret_count": ret_count,
            "alu_arith_count": alu_arith_count,
            "alu_logic_count": alu_logic_count,
            "alu_shift_count": alu_shift_count,
            "alu_mul_count": alu_mul_count,
            "pro_push_count": pro_push_count,
            "epi_pop_count": epi_pop_count,
            "sp_adjust_count": sp_adjust_count,
            "max_imm": max_imm,
            "top_imms": top_imms,
            "top_regs": top_regs,
            "top_mnems": top_mnems,
            "top_stack_offsets": top_stack_offsets,
            "stack_off_min": (stack_off_min if stack_off_min is not None else 0),
            "stack_off_max": (stack_off_max if stack_off_max is not None else 0),
        }
        f.write(json.dumps(rec) + "\n")
        rows += 1

print(f"IDA CFG export complete: rows={rows}")
idaapi.qexit(0)
