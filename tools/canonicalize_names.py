#!/usr/bin/env python3
"""canonicalize_names.py — unify the naming dataset to ONE name per chip address.

The harness_v17/names/ dataset accumulated records from two naming eras:
  - chip-style keys:   sub_1267E0   addr 0x1267e0   -> "ke_task_poll"
  - v14-style keys:    sub_12267E0  addr 0x12267e0   -> "bt_event_handler"
Both refer to the SAME physical function (v14 addr - 0x1100000 = chip addr),
but carry different LLM names. Compose reads the plain sub_<CHIP> unit and
names it via the chip-style record, while caller bodies (decompiled in the
v14 era) reference the v14-style name -> undefined symbols at link.

Fix: for every (img, chip_addr) pick ONE canonical name, rewrite ALL dataset
records for that address to carry the canonical name, and rewrite every call
site in src/<img>/functions/*.c from any legacy name to the canonical name.

Deterministic, no LLM. O(n) regex passes.
"""

import json
import re
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
NAMES_DIR = ROOT / "harness_v17" / "names"
SRC_DIR = ROOT / "src"

V14_BASE = 0x1200000
CHIP_BASE = 0x100000
V14_DELTA = V14_BASE - CHIP_BASE


def chip_addr(rec):
    a = int(rec.get("addr", "0"), 16)
    if a >= V14_BASE:
        a -= V14_DELTA
    return a


def canonical_key(addr):
    return f"sub_{addr:X}"


def main():
    records = defaultdict(list)  # img -> list of recs
    for f in sorted(NAMES_DIR.glob("*.json")):
        try:
            rec = json.loads(f.read_text())
        except Exception:
            continue
        if rec.get("status") != "ok":
            continue
        records[rec.get("img")].append((f, rec))

    total_fixed = 0
    for img, recs in records.items():
        by_addr = defaultdict(list)
        for f, rec in recs:
            by_addr[chip_addr(rec)].append((f, rec))

        # canonical name per address: prefer the chip-style record
        # (the one compose reads for the plain sub_<CHIP> unit).
        canonical = {}
        for addr, lst in sorted(by_addr.items()):
            chip_rec = None
            for f, rec in lst:
                if rec.get("fn") == canonical_key(addr):
                    chip_rec = rec
                    break
            name = chip_rec["name"] if chip_rec else sorted(lst, key=lambda x: x[0].name)[0][1]["name"]
            canonical[addr] = name

        # legacy name -> canonical name (only when they differ)
        legacy2canon = {}
        for addr, lst in sorted(by_addr.items()):
            canon = canonical[addr]
            for f, rec in lst:
                old = rec.get("name")
                if old and old != canon:
                    legacy2canon[old] = canon

        # function files carry the address in their name: <HEX>_<name>.c.
        # Any file whose embedded name differs from the canonical name is a
        # legacy caller-side name (the 212-name resync renamed dataset records
        # after canonicalization, orphaning call sites) -> also remap it.
        src_sub = SRC_DIR / img.replace("_bin", "").replace("8800d80_", "")
        func_dir = src_sub / "functions"
        if func_dir.is_dir():
            for f in sorted(func_dir.glob("*.c")):
                m = re.match(r"^([0-9A-Fa-f]{2,8})_(.+?)\.c$", f.name)
                if not m:
                    continue
                faddr = int(m.group(1), 16)
                fname = m.group(2)
                if faddr in canonical and fname != canonical[faddr]:
                    legacy2canon.setdefault(fname, canonical[faddr])

        # rewrite dataset records: name field -> canonical
        for addr, lst in sorted(by_addr.items()):
            canon = canonical[addr]
            for f, rec in lst:
                if rec.get("name") != canon:
                    rec["name"] = canon
                    f.write_text(json.dumps(rec, ensure_ascii=False))
                    total_fixed += 1

        # rewrite call sites in function files (word-boundary, longest-first)
        src_sub = SRC_DIR / img.replace("_bin", "").replace("8800d80_", "")
        func_dir = src_sub / "functions"
        if not func_dir.is_dir():
            continue
        if not legacy2canon:
            continue
        names = sorted(legacy2canon, key=len, reverse=True)
        re_alt = re.compile(r"\b(" + "|".join(re.escape(n) for n in names) + r")\b")
        n_files = n_subs = 0
        for f in sorted(func_dir.glob("*.c")):
            text = f.read_text()
            orig = text

            def repl(m):
                nn = legacy2canon.get(m.group(1))
                return nn if nn else m.group(0)

            new = re_alt.sub(repl, text)
            if new != orig:
                f.write_text(new)
                n_files += 1
                n_subs += len(re.findall(re_alt, orig))
        print(f"{img}: {len(by_addr)} addrs, {total_fixed and ''}legacy->canon fixed: {n_files} files, {n_subs} call sites")

    print(f"total dataset records rewritten: {total_fixed}")


if __name__ == "__main__":
    main()
