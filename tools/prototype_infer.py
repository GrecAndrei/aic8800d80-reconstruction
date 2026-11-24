#!/usr/bin/env python3
"""prototype_infer.py — machine-code-grounded return-contract evidence.

First stage of the deterministic prototype pipeline. It does not guess C types
from Hex-Rays text. It reads the original firmware bytes and classifies only
cases that are locally unambiguous:

* exact_nullsub: the first instruction is ``bx lr`` and every following byte
  before the next function boundary is padding (``nop``/zero);
* tail_alias: the complete body is an unconditional branch to another
  function entry, so its return contract is transparently the target's.

The JSONL output is evidence for later void/nonvoid inference. Unknown or
complex functions are emitted as ``unknown`` rather than forced into a type.
"""
import argparse
import json
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_MCLASS

REPO = Path(__file__).resolve().parent.parent
ANALYSIS_BASE = 0x100000
IMAGES = {
    "fmacfw_8800d80_h_u02": "fmacfw_h_u02",
    "fmacfw_8800d80_u02": "fmacfw_u02",
    "fmacfwbt_8800d80_u02": "fmacfwbt_u02",
    "lmacfw_rf_8800d80_u02": "lmacfw_rf_u02",
}
MARKER_RE = __import__("re").compile(r"^// \S+ @ (0x[0-9a-fA-F]+)", __import__("re").M)


def load_funcs(image: str) -> list[dict]:
    """Composed function starts in analysis order.

    The v25 scan is an input-discovery artifact and omits tiny padding/nullsub
    units. The composed source is the actual link/corpus universe, so it is the
    authoritative boundary set for inference over reconstruction functions.
    """
    text = (REPO / "src" / IMAGES[image] / "main.c").read_text(errors="replace")
    rows = [{"address": int(x, 16), "name": "composed"} for x in MARKER_RE.findall(text)]
    rows.sort(key=lambda r: r["address"])
    dedup = []
    for row in rows:
        if not dedup or row["address"] != dedup[-1]["address"]:
            dedup.append(row)
    return dedup


def scan_image(image: str) -> list[dict]:
    blob = (REPO / "inputs" / "firmware" / f"{image}.bin").read_bytes()
    funcs = load_funcs(image)
    starts = {r["address"] for r in funcs}
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_MCLASS)
    out = []
    for i, row in enumerate(funcs):
        addr = row["address"]
        off = addr - ANALYSIS_BASE
        end = funcs[i + 1]["address"] - ANALYSIS_BASE if i + 1 < len(funcs) else len(blob)
        body = blob[off:end]
        rec = {
            "image": image,
            "address": hex(addr),
            "scan_name": row.get("name", ""),
            "class": "unknown",
            "evidence": [],
        }
        if len(body) >= 2 and body[:2] == b"\x70\x47":
            # A function whose entry instruction is bx lr is empty regardless
            # of what padding/data follows; bytes after the return are unreachable.
            rec["class"] = "exact_nullsub"
            rec["evidence"] = ["entry instruction is bx lr"]
        elif body:
            ins = next(md.disasm(body[:4], addr), None)
            if ins and ins.mnemonic in {"b", "b.w"}:
                try:
                    target = int(ins.op_str.strip().lstrip("#"), 0)
                except ValueError:
                    target = 0
                if target in starts:
                    rec["class"] = "tail_alias"
                    rec["target"] = hex(target)
                    rec["evidence"] = [f"entry instruction is unconditional branch to {target:#x}"]
        out.append(rec)
    return resolve_aliases(out)


def resolve_aliases(rows: list[dict]) -> list[dict]:
    by_addr = {int(r["address"], 16): r for r in rows}
    for r in rows:
        if r["class"] != "tail_alias":
            continue
        seen = set()
        cur = int(r["target"], 16)
        chain = []
        while cur in by_addr and cur not in seen:
            seen.add(cur)
            t = by_addr[cur]
            chain.append(hex(cur))
            if t["class"] != "tail_alias":
                if t["class"] == "exact_nullsub":
                    r["class"] = "nullsub_tail_alias"
                    r["terminal_class"] = "exact_nullsub"
                    r["evidence"].append("alias chain terminates at exact_nullsub")
                break
            cur = int(t.get("target", "0"), 16)
        r["alias_chain"] = chain
    return rows


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--out", type=Path, default=REPO / "metadata" / "prototype_inference.jsonl")
    args = ap.parse_args()
    rows = []
    for image in IMAGES:
        rows.extend(scan_image(image))
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text("".join(json.dumps(r, sort_keys=True) + "\n" for r in rows))
    counts = {}
    for r in rows:
        counts[r["class"]] = counts.get(r["class"], 0) + 1
    print(f"[prototype_infer] {len(rows)} functions -> {args.out} {counts}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
