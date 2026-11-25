#!/usr/bin/env python3
"""arity_scan.py — machine-grounded under-arity call-site detection.

For every call site in the composed sources that targets a composed function,
count the arguments the decompiler emitted and compare against the callee's
machine-proven input arity (metadata/prototype_inference.jsonl machine_inputs,
a lower bound from the read-before-write prologue analysis).

A call site providing fewer arguments than the machine-proven input count is a
definitive under-arity defect: the original binary passes those registers and
the reconstruction silently drops them, so the callee reads stack garbage or
residue instead of the caller's intent.

Output: JSONL per site with image, caller, callee, callee_addr, proven arity,
call-site arity and the call text. Analysis only — nothing is rewritten.
"""
import json
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMAGES = {
    "fmacfw_h_u02": "fmacfw_8800d80_h_u02",
    "fmacfw_u02": "fmacfw_8800d80_u02",
    "fmacfwbt_u02": "fmacfwbt_8800d80_u02",
    "lmacfw_rf_u02": "lmacfw_rf_8800d80_u02",
}

MARKER_RE = re.compile(r"(?m)^// (\w+) @ 0x([0-9a-fA-F]+)")
CALL_RE = re.compile(r"\b([A-Za-z_]\w*)\s*\(")

KEYWORDS = {"if", "while", "for", "switch", "return", "sizeof", "defined",
            "do", "else", "case", "goto", "__asm__", "volatile"}


def split_args(argstr: str) -> list[str]:
    """Split a call argument list on top-level commas; [] when empty."""
    s = argstr.strip()
    if not s:
        return []
    args, depth, cur, in_str, in_chr, esc = [], 0, [], False, False, False
    for ch in s:
        if esc:
            cur.append(ch)
            esc = False
            continue
        if ch == "\\" and (in_str or in_chr):
            cur.append(ch)
            esc = True
            continue
        if in_str:
            cur.append(ch)
            if ch == '"':
                in_str = False
            continue
        if in_chr:
            cur.append(ch)
            if ch == "'":
                in_chr = False
            continue
        if ch == '"':
            in_str = True
            cur.append(ch)
            continue
        if ch == "'":
            in_chr = True
            cur.append(ch)
            continue
        if ch in "([{":
            depth += 1
        elif ch in ")]}":
            depth -= 1
        if ch == "," and depth == 0:
            args.append("".join(cur).strip())
            cur = []
        else:
            cur.append(ch)
    if cur:
        args.append("".join(cur).strip())
    return [a for a in args if a != ""]


def extract_calls(body: str):
    """Yield (callee_name, arglist) for simple direct calls in a body.

    Skips cast function-pointer calls (they start with '(' before the name)
    because their arity is a separate artifact class."""
    for m in CALL_RE.finditer(body):
        name = m.group(1)
        if name in KEYWORDS:
            continue
        # skip declarations/definitions heuristically: a call inside a body is fine;
        # the body passed in here is only the function body text.
        # find matching close paren
        i = m.end()
        depth = 1
        out = []
        while i < len(body) and depth:
            ch = body[i]
            if ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
                if depth == 0:
                    break
            out.append(ch)
            i += 1
        if depth:
            continue
        yield name, "".join(out), m.start()


def main() -> int:
    proto_rows = {}
    for line in (REPO / "metadata" / "prototype_inference.jsonl").read_text().splitlines():
        r = json.loads(line)
        proto_rows[(r["image"], int(r["address"], 16))] = r

    results = []
    for short, image in IMAGES.items():
        text = (REPO / "src" / short / "main.c").read_text(errors="replace")
        # map composed name -> (addr) within this image
        markers = {}
        for nm, a in MARKER_RE.findall(text):
            markers[nm] = int(a, 16)
        # split into function bodies by markers
        positions = [(mm.start(), mm.group(1), int(mm.group(2), 16)) for mm in MARKER_RE.finditer(text)]
        positions.sort()
        for idx, (pos, cname, caddr) in enumerate(positions):
            end = positions[idx + 1][0] if idx + 1 < len(positions) else len(text)
            body = text[pos:end]
            for callee, argstr, off in extract_calls(body):
                if callee not in markers:
                    continue
                taddr = markers[callee]
                prow = proto_rows.get((image, taddr))
                if prow is None:
                    continue
                proven = len(prow.get("machine_inputs") or [])
                if not proven:
                    continue
                site_args = split_args(argstr)
                if len(site_args) < proven:
                    results.append({
                        "image": image,
                        "caller": cname,
                        "caller_addr": hex(caddr),
                        "callee": callee,
                        "callee_addr": hex(taddr),
                        "proven_inputs": prow.get("machine_inputs"),
                        "proven_arity": proven,
                        "site_arity": len(site_args),
                        "call": f"{callee}({argstr.strip()[:120]})",
                    })
    out = REPO / "metadata" / "under_arity_sites.jsonl"
    out.write_text("".join(json.dumps(r, sort_keys=True) + "\n" for r in results))
    by_image = {}
    for r in results:
        by_image[r["image"]] = by_image.get(r["image"], 0) + 1
    callees = {(r["image"], r["callee_addr"]) for r in results}
    print(f"[arity_scan] {len(results)} under-arity sites across {len(callees)} callees -> {out}")
    print(f"[arity_scan] by image: {by_image}")
    defects = scan_defects()
    dpath = REPO / "metadata" / "arity_defects.json"
    dpath.write_text(json.dumps(defects, indent=1) + "\n")
    print(f"[arity_scan] {len(defects)} width-adjusted prototype defects -> {dpath}")
    return 0




def prototype_reg_capacity(params: str) -> tuple[int, int]:
    """Register-carrying capacity of a C parameter list.

    64-bit types occupy a register pair under the AAPCS soft-float ABI;
    everything else one register. Returns (param_count, register_capacity)."""
    plist = [p.strip() for p in params.split(",") if p.strip() and p.strip() not in ("...",)]
    cap = 0
    for p in plist:
        if re.search(r"\b(uint64_t|int64_t|double|long long|unsigned long long)\b", p):
            cap += 2
        else:
            cap += 1
    return len(plist), cap


def find_capacity(text: str, name: str, cache: dict):
    if name in cache:
        return cache[name]
    m = re.search(rf"(?m)^\s*[\w][\w\s\*]*\b{re.escape(name)}\s*\(([^;{{}}]*)\)\s*;", text)
    res = None
    if m:
        params = m.group(1).strip()
        res = (0, 0) if params in ("void", "") else prototype_reg_capacity(params)
    cache[name] = res
    return res


def scan_defects() -> list[dict]:
    """Width-aware true defects: machine-proven input registers exceed the
    callee prototype's register-carrying capacity. Compiled call sites always
    match the prototype arity, so the defect lives in the prototype itself:
    the original binary passes registers the reconstruction cannot receive."""
    proto_rows = {}
    for line in (REPO / "metadata" / "prototype_inference.jsonl").read_text().splitlines():
        r = json.loads(line)
        proto_rows[(r["image"], int(r["address"], 16))] = r
    defects = []
    for short, image in IMAGES.items():
        text = (REPO / "src" / short / "main.c").read_text(errors="replace")
        markers = {nm: int(a, 16) for nm, a in MARKER_RE.findall(text)}
        capcache: dict = {}
        for nm, taddr in sorted(markers.items()):
            prow = proto_rows.get((image, taddr))
            if prow is None:
                continue
            proven = prow.get("machine_inputs") or []
            if not proven:
                continue
            info = find_capacity(text, nm, capcache)
            if info is None:
                continue
            nparams, cap = info
            if len(proven) > cap:
                defects.append({
                    "image": image,
                    "callee": nm,
                    "callee_addr": hex(taddr),
                    "proven_inputs": proven,
                    "proto_params": nparams,
                    "proto_reg_capacity": cap,
                })
    return defects


if __name__ == "__main__":
    sys.exit(main())
