import idaapi
import ida_auto
import ida_hexrays
import ida_lines
import idautils
import idc
import json
import os
import re

OUT_DIR = os.environ.get("IDA_EXPORT_DIR", ".")
TARGET_FILE = os.environ.get("IDA_PSEUDO_TARGETS_FILE", "")
os.makedirs(OUT_DIR, exist_ok=True)
base = idaapi.get_root_filename()
out_path = os.path.join(OUT_DIR, f"{base}.pseudo.jsonl")


def load_targets(path):
    if not path or not os.path.isfile(path):
        return None
    try:
        rows = json.load(open(path, "r", encoding="utf-8"))
    except Exception:
        return None
    if not isinstance(rows, list):
        return None
    addrs = set()
    bases = [0x120000, 0x11F0000, 0x1200000, 0x1100000, 0x10F0000]
    for row in rows:
        if not isinstance(row, dict):
            continue
        if str(row.get("image", "")).strip() != base:
            continue
        addr = str(row.get("address", "")).strip().lower()
        if addr.startswith("0x"):
            try:
                ea = int(addr, 16)
                candidates = [ea]
                for base_off in bases:
                    if ea > base_off:
                        candidates.append(ea - base_off)
                    candidates.append(ea + base_off)
                for cand in candidates:
                    fn = idaapi.get_func(cand)
                    addrs.add(fn.start_ea if fn else cand)
            except Exception:
                pass
    return addrs


def sanitize_calls(text):
    calls = []
    seen = set()
    for name in re.findall(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(", text):
        if name in {"if", "for", "while", "switch", "return", "sizeof"}:
            continue
        if name in seen:
            continue
        seen.add(name)
        calls.append(name)
    return calls[:8]


def mmio_consts(text):
    out = []
    seen = set()
    for tok in re.findall(r"0x[0-9A-Fa-f]+", text):
        try:
            v = int(tok, 16)
        except Exception:
            continue
        if v < 0x40000000 and not (0xE0000000 <= v <= 0xE00FFFFF):
            continue
        norm = hex(v)
        if norm in seen:
            continue
        seen.add(norm)
        out.append(norm)
    return out[:8]


ida_auto.auto_wait()
targets = load_targets(TARGET_FILE)
if not ida_hexrays.init_hexrays_plugin():
    open(out_path, "w", encoding="utf-8").close()
    print("Hex-Rays unavailable; wrote empty pseudocode export")
    idaapi.qexit(0)

rows = 0
attempted = 0
decompile_fail = 0
with open(out_path, "w", encoding="utf-8") as f:
    for f_ea in idautils.Functions():
        fn = idaapi.get_func(f_ea)
        if not fn:
            continue
        if targets is not None and f_ea not in targets:
            continue
        attempted += 1
        try:
            cfunc = ida_hexrays.decompile(fn)
        except Exception:
            decompile_fail += 1
            continue
        if not cfunc:
            decompile_fail += 1
            continue
        try:
            sv = cfunc.get_pseudocode()
            text = "\n".join(ida_lines.tag_remove(line.line) for line in sv)
        except Exception:
            text = str(cfunc)
        if not text.strip():
            continue
        rec = {
            "image": base,
            "address": hex(f_ea),
            "name": idc.get_func_name(f_ea) or "",
            "line_count": len([ln for ln in text.splitlines() if ln.strip()]),
            "loop_count": text.count("for (") + text.count("while (") + text.count("do\n") + text.count("do {"),
            "switch_count": text.count("switch ("),
            "if_count": text.count("if ("),
            "return_count": text.count("return"),
            "call_names": sanitize_calls(text),
            "mmio_addrs": mmio_consts(text),
            "pseudocode": text,
        }
        f.write(json.dumps(rec) + "\n")
        rows += 1

print(f"IDA pseudocode export complete: targets={(len(targets) if targets is not None else -1)} attempted={attempted} rows={rows} decompile_fail={decompile_fail}")
idaapi.qexit(0)
