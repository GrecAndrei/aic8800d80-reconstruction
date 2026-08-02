#!/usr/bin/env python3
"""Harvest MMIO register evidence from all four AIC8800D80 firmware images.

Three coverage sources are merged per image, all at hardware base 0x120000:
  1. boot from the IVT reset vector (deep init traffic)
  2. every truth-lane target (analysis-space address + HW_OFFSET)
  3. per-function sweep: run every entry in the fwstruct function table with a
     short instruction cap, so registers touched by code paths the boot never
     reaches still get evidence.

For each distinct peripheral register the aggregate profile records:
  - read/write counts, access sizes
  - distinct written and read-back values (with counts)
  - echo detection (a value written then read back identically)
  - poll detection (read-heavy, write-starved access from one function)
  - the firmware functions that touch it (PC resolved via the function table)
  - co-access cluster: same-page siblings touched by the same function
  - cross-image usage

The dynamic set is the authoritative "firmware really uses this register" list.
A separate static candidate universe (32-bit MMIO-region constants found in the
raw binaries, relaxed page filter) is emitted so later phases can extend
semantic coverage to registers the sweeps never happened to exercise.

Output: build/mmio/evidence.json (gitignored intermediate).
"""
from __future__ import annotations

import argparse
import collections
import json
import sys
from concurrent.futures import ProcessPoolExecutor
from datetime import datetime, timezone
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))

from aic8800d80_emulator import (  # noqa: E402
    Aic8800D80Platform,
    HW_OFFSET,
    is_periph_addr,
    load_mmio_model,
    load_function_table,
    resolve_image,
    resolve_pc_name,
    _short_image,
)

IMAGES = [
    "fmacfw_8800d80_h_u02.bin",
    "fmacfw_8800d80_u02.bin",
    "fmacfwbt_8800d80_u02.bin",
    "lmacfw_rf_8800d80_u02.bin",
]

TARGETS_DEFAULT = REPO / "extraction_out" / "reconstruction" / "truth_lane_state" / "truth_lane_targets.json"
PAGE_SIZE = 0x1000


def _static_candidates() -> dict[int, list[int]]:
    """All 32-bit constants in the peripheral ranges, by page.

    Raw-byte scan over-counts (code/data bytes that happen to look like an
    address), so this is a candidate universe only; pages with few hits are
    kept but flagged. The dynamic evidence set is authoritative.
    """
    base = REPO / "inputs" / "firmware"
    page_hits: dict[int, collections.Counter] = collections.defaultdict(collections.Counter)
    for name in IMAGES:
        data = (base / name).read_bytes()
        for off in range(0, len(data) - 4, 2):
            v = int.from_bytes(data[off:off + 4], "little")
            if not ((0x40000000 <= v < 0x60000000) or (0xE0000000 <= v < 0xE00FFFFF)):
                continue
            page_hits[v >> 16][v] += 1
    return {page: sorted(addrs) for page, addrs in page_hits.items()}


def _harvest_image(image: str, targets: list[dict], boot_insns: int,
                   sweep_insns: int) -> dict:
    img_key = image.replace(".bin", "")
    short = _short_image(img_key)
    plat = Aic8800D80Platform(resolve_image(image), mmio_model=load_mmio_model())
    plat.function_table = load_function_table(short)
    ivt = plat.ivt()
    sp = ivt["stack_pointer"]

    # Per-register evidence accumulator for this image.
    reg_ev: dict[int, dict] = {}
    fn_touches: dict[int, dict] = collections.defaultdict(collections.Counter)

    def ingest(run_id: str, traffic: list[dict]) -> None:
        for t in traffic:
            addr = int(t["addr"], 16)
            if not is_periph_addr(addr):
                continue
            ev = reg_ev.setdefault(addr, {
                "addr": addr,
                "images": set(),
                "reads": 0, "writes": 0,
                "sizes": set(),
                "written": collections.Counter(),
                "readback": collections.Counter(),
                "seq": [],
            })
            pc = int(t["pc"], 16)
            fn = None
            if plat.function_table:
                fn = resolve_pc_name(plat.function_table, pc)
            if t["op"] == "read":
                ev["reads"] += 1
                ev["sizes"].add(int(t["size"]))
                val = t.get("value")
                if val is not None:
                    ev["readback"][int(val, 16)] += 1
                ev["seq"].append(("R", addr, int(t["size"]), fn, run_id))
            else:
                ev["writes"] += 1
                ev["sizes"].add(int(t["size"]))
                v = int(t["value"], 16)
                ev["written"][v] += 1
                ev["seq"].append(("W", addr, int(t["size"]), fn, run_id, v))
            if fn:
                fn_touches[addr][fn] += 1

    # 1) boot from reset vector
    term, stats = plat.run(ivt["reset_handler"] | 1, boot_insns, sp=sp)
    ingest(f"boot:{term}", plat.traffic)
    print(f"[harvest] {img_key}: boot {term} insns={stats['instructions']}", flush=True)

    # 2) truth-lane targets (analysis address -> hardware)
    for t in targets:
        if t.get("image", "").replace(".bin", "") != img_key:
            continue
        addr_str = t.get("address", "")
        if not addr_str:
            continue
        try:
            key = int(addr_str, 16)
        except ValueError:
            continue
        if key < 0x100000:
            key += 0x100000
        term, stats = plat.run(key + HW_OFFSET, 10000, sp=sp)
        ingest(f"target:{t.get('function', '?')}:{term}", plat.traffic)
    print(f"[harvest] {img_key}: targets done", flush=True)

    # 3) per-function sweep. load_function_table returns hardware-space
    #    addresses (it adds HW_OFFSET internally), so run them directly.
    if plat.function_table:
        entries = sorted({addr for addr, _ in plat.function_table})
        for i, addr in enumerate(entries):
            term, _stats = plat.run(addr, sweep_insns, sp=sp)
            ingest(f"sweep:{addr:x}:{term}", plat.traffic)
            if (i + 1) % 200 == 0:
                print(f"[harvest] {img_key}: sweep {i + 1}/{len(entries)}", flush=True)
    print(f"[harvest] {img_key}: sweep done ({len(reg_ev)} periph regs)", flush=True)

    # Per-function co-access: same-page siblings touched by the same function.
    co_access: dict[int, set] = collections.defaultdict(set)
    for addr, ev in reg_ev.items():
        page = addr & ~0xFFFF
        for fn in fn_touches[addr]:
            # siblings of this register touched by the same function
            for other_addr, other_fn in fn_touches.items():
                if other_addr == addr or other_addr & ~0xFFFF != page:
                    continue
                if fn in other_fn:
                    co_access[addr].add(other_addr)

    out = {}
    for addr, ev in reg_ev.items():
        seq = ev["seq"]
        echo = False
        # echo: last written value appears among readback values
        if ev["writes"] and ev["readback"]:
            last_write = max(ev["written"], key=lambda v: (ev["written"][v], v))
            if last_write in ev["readback"]:
                echo = True
        # poll: read-heavy single-function usage with no writes between
        poll = False
        poll_note = ""
        rw_by_fn = collections.defaultdict(lambda: [0, 0])
        for item in ev["seq"]:
            rw_by_fn[item[3]][0 if item[0] == "R" else 1] += 1
        for fn, (r, w) in rw_by_fn.items():
            if r >= 5 and w == 0:
                poll = True
                poll_note = f"{fn}: {r} reads, 0 writes"
                break
            if r >= 5 and w == 1:
                poll = True
                poll_note = f"{fn}: {r} reads, 1 write (arm-then-poll)"
                break
        out[hex(addr)] = {
            "addr": hex(addr),
            "images": sorted(ev["images"] | {img_key}),
            "reads": ev["reads"],
            "writes": ev["writes"],
            "sizes": sorted(ev["sizes"]),
            "written_values": {hex(v): c for v, c in ev["written"].most_common(20)},
            "readback_values": {hex(v): c for v, c in ev["readback"].most_common(20)},
            "touching_functions": dict(sorted(fn_touches[addr].items(), key=lambda kv: -kv[1])),
            "echo": echo,
            "poll": poll,
            "poll_note": poll_note,
            "co_access": sorted(co_access.get(addr, set())),
            "last_written": hex(max(ev["written"], key=lambda v: (ev["written"][v], v))) if ev["written"] else None,
        }
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--images", nargs="*", default=IMAGES, choices=IMAGES)
    ap.add_argument("--targets", type=Path, default=TARGETS_DEFAULT)
    ap.add_argument("--boot-insns", type=int, default=50000)
    ap.add_argument("--sweep-insns", type=int, default=800)
    ap.add_argument("--out", type=Path, default=REPO / "build" / "mmio" / "evidence.json")
    args = ap.parse_args()

    targets = json.loads(args.targets.read_text()) if args.targets.is_file() else []

    # Merge per-image evidence, plus static candidate universe.
    merged: dict[str, dict] = {}
    with ProcessPoolExecutor(max_workers=len(args.images)) as ex:
        futures = {ex.submit(_harvest_image, img, targets, args.boot_insns, args.sweep_insns): img
                   for img in args.images}
        for fut in futures:
            img_key = futures[fut].replace(".bin", "")
            img_regs = fut.result()
            for addr, ev in img_regs.items():
                if addr in merged:
                    m = merged[addr]
                    m["reads"] += ev["reads"]
                    m["writes"] += ev["writes"]
                    m["images"] = sorted(set(m["images"]) | set(ev["images"]))
                    m["sizes"] = sorted(set(m["sizes"]) | set(ev["sizes"]))
                    m["poll"] = m["poll"] or ev["poll"]
                    m["echo"] = m["echo"] or ev["echo"]
                    if ev["poll_note"]:
                        m["poll_note"] = (m["poll_note"] + " | " if m["poll_note"] else "") + ev["poll_note"]
                    m["touching_functions"].update(ev["touching_functions"])
                else:
                    merged[addr] = dict(ev)
            print(f"[harvest] merged {img_key}: {len(img_regs)} regs", flush=True)

    # Sort deterministically.
    merged = {hex(int(a, 16)): v for a, v in sorted(merged.items(), key=lambda kv: int(kv[0], 16))}

    # Static candidate universe (page -> addrs), for the classify phase.
    static_pages = _static_candidates()
    static = {f"0x{p:04x}": addrs for p, addrs in sorted(static_pages.items())}

    dynamic_pages = {f"0x{((int(ev['addr'], 16) >> 16) & 0xFFFF):04x}"
                     for ev in merged.values()}
    static_in_dynamic_pages = {
        p: addrs for p, addrs in static.items() if p in dynamic_pages
    }

    doc = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "images": args.images,
        "register_count": len(merged),
        "dynamic_pages": len(dynamic_pages),
        "static_pages_total": len(static),
        "static_candidates_in_dynamic_pages": sum(len(v) for v in static_in_dynamic_pages.values()),
        "registers": merged,
        "static_candidates": static,
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(doc, indent=1, sort_keys=True))
    print(f"\n[harvest] wrote {args.out}")
    print(f"[harvest] dynamic registers: {doc['register_count']} "
          f"static candidates in dynamic pages: {doc['static_candidates_in_dynamic_pages']}")
    polls = sum(1 for ev in merged.values() if ev["poll"])
    echoes = sum(1 for ev in merged.values() if ev["echo"])
    print(f"[harvest] poll candidates: {polls}  echo candidates: {echoes}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
