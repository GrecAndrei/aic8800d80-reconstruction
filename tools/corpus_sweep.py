#!/usr/bin/env python3
"""Full-corpus emulator sweep: run every function in all 4 images.

For each function in the fwstruct scan (harness_v25/out/*_funcs.jsonl), boot
a fresh platform and run the function at hardware base (chip addr =
scan addr + HW_OFFSET) up to ``--max-insns``. Classify each run as
returned / capped / fault and summarize:

  - how many functions execute cleanly under the behavioral MMIO model
  - which fault, and on what (unknown MMIO page, null context slot, ...)
  - which cap (deep loop, poll never ready, OS-style wait)

The 25 truth-lane targets are the curated gate; this sweep is the corpus-wide
coverage check that finds gaps the curated set misses (an unmapped MMIO page
the behavior model didn't classify, an extra boot-ROM slot, etc.).

Faults are bucketed by (fault_address page, fault_pc page) so novel gaps are
visible in aggregate instead of as 5,000 individual rows.

``--boot-first`` boots the image once (50k insns by default), snapshots every
mapped region, and runs each function against a restored copy of that booted
state with behavioral counters reset. This quantifies how many standalone
faults are boot-state dependencies. Measured on the current model it makes
things WORSE overall (lmac_rf: 932 -> 605 returned): booting eliminates the
allocator's `udf #255` trap (INSN_INVALID_other 83 -> 3) but exposes ~120 new
null-callbacks, because boot-populated globals point into structures whose
function-pointer fields the 50k-insn boot has not yet installed. So the
standalone fresh-platform mode is the cleaner null-context measurement, and
boot-first is a diagnostic that the residual faults are context dependencies,
not MMIO gaps.

``--bootstate`` is the targeted middle path: boot once (``--boot-insns``),
record every write the boot makes to the persistent global-region islands
(the low ``0x182000-0x184000`` / ``0x186000-0x18a000`` / ``0x192000-0x193000``
pages where the firmware keeps its runtime globals), and inject exactly those
writes into each fresh function platform. This gives the allocator its valid
heap head (``0x182b60`` -> a negative-magic node in the image data) and the
boot callback table without dragging in the partially-populated SRAM structs
that make ``--boot-first`` regress. Functions that previously died on the
allocator's ``udf #255`` assert instead run real logic and cap at a legitimate
OS wait, so ``--bootstate`` converts the largest fault bucket into the cap
class. (Diagnostic of runtime-global dependencies, not an MMIO gap.)
"""

from __future__ import annotations

import argparse
import json
import sys
import time
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))

from tools.aic8800d80_emulator import (  # noqa: E402
    Aic8800D80Platform,
    HW_OFFSET,
    IMAGE_NAMES,
    SCAN_GLOB,
    load_mmio_model,
    load_function_table,
    resolve_image,
)

DEFAULT_CAP = 5000
PAGE = 0x1000

# Regions the platform maps (mirrors _map_memory in the emulator).
_MAPPED_REGIONS = [
    (0x120000, 0x180000 - 0x120000),        # primary image + BSS window
    (0x180000, 0x20000),                    # stack under the IVT SP
    (0x20000000, 0x80000),                  # main SRAM
    (0x21000000, 0x10000),                  # heap
    (0x20080000 & ~0xFFF, 0x1000),          # boot-ROM stub page
    (0x0, 0x1000),                          # low boot-ROM page (seeded slots)
    (0xDEADC000, 0x1000),                   # return sentinel page
]


def snapshot_memory(mu) -> list[tuple[int, bytes]]:
    """Dump every mapped region's bytes for later restore."""
    out = []
    for base, size in _MAPPED_REGIONS:
        try:
            out.append((base, mu.mem_read(base, size)))
        except Exception:
            continue
    return out


def restore_memory(mu, snapshot: list[tuple[int, bytes]]) -> None:
    """Restore previously snapshotted region bytes."""
    for base, data in snapshot:
        try:
            mu.mem_write(base, data)
        except Exception:
            continue


# The global-region window the firmware keeps its runtime globals in (the low
# end of the 0x180000-0x1a0000 "stack" region). Pages written here during boot
# are globals as long as they sit BELOW the deepest SP the boot reaches; pages
# at/above that line are pure stack scratch. The exact island floor differs per
# image (fmac images start at 0x182000, lmac_rf at 0x180000), so the capture is
# adaptive: it records writes in this whole window and then drops everything at
# or above the minimum SP observed during the boot.
BOOTSTATE_WINDOW = (0x180000, 0x1a0000)

# Scan artifacts: fwstruct registered a "function" on a string/crypto pool
# (no real code). Identified individually from corpus faults.
DATA_ARTIFACT_ENTRIES = {
    ("sub_12F954", 0x12F954),  # lmac_rf: log string "val - ShortGI en"
}


def capture_bootstate(image: str, boot_insns: int) -> dict[int, tuple[int, int]]:
    """Boot the image and record the persistent global-region writes.

    Returns {address: (size, value)}: every write the boot makes to the
    global-region window strictly BELOW the deepest SP it reached (so stack
    scratch is excluded). This gives the allocator its heap head, the boot
    callback slots, and the log/config globals WITHOUT the partially-populated
    SRAM structs that full-restore boot-first drags in.
    """
    from unicorn import UC_HOOK_MEM_WRITE
    import unicorn.arm_const as _ac

    lo, hi = BOOTSTATE_WINDOW
    img_path = resolve_image(f"{image}.bin")
    model = load_mmio_model()
    plat = Aic8800D80Platform(img_path, mmio_model=model)
    plat.function_table = load_function_table(image)
    ivt = plat.ivt()
    writes: dict[int, tuple[int, int]] = {}
    min_sp = [ivt["stack_pointer"]]

    def on_write(uc, access, address, size, value, user_data):
        if lo <= address < hi:
            writes[address] = (size, value & 0xFFFFFFFF)
            sp = plat.mu.reg_read(_ac.UC_ARM_REG_SP)
            if sp < min_sp[0]:
                min_sp[0] = sp
        return True

    h = plat.mu.hook_add(UC_HOOK_MEM_WRITE, on_write)
    plat.run(ivt["reset_vector"], boot_insns, sp=ivt["stack_pointer"])
    plat.mu.hook_del(h)
    # Drop everything at/above the deepest stack touch (stack scratch).
    cutoff = min_sp[0]
    return {a: v for a, v in writes.items() if a < cutoff}


def apply_bootstate(mu, bootstate: dict[int, tuple[int, int]]) -> None:
    """Write a captured bootstate dict into a fresh platform."""
    for addr, (size, value) in bootstate.items():
        try:
            mu.mem_write(addr, int(value).to_bytes(size, "little"))
        except Exception:
            continue


def sweep_image(image: str, max_insns: int, every: int, out_path: Path,
                boot_first: bool = False, boot_insns: int = 50000,
                bootstate: bool = False) -> dict:
    scan = Path(str(SCAN_GLOB).format(image))
    if not scan.is_file():
        return {"error": f"no scan {scan}"}
    fns = [json.loads(l) for l in scan.read_text().splitlines() if l.strip()]
    fns = [f for f in fns if isinstance(f.get("address"), int) and f.get("name")]
    for f in fns:
        # The scan registers ``start`` at file 0x100 (IVT base); the real
        # CPUID-check entry is at file 0x1a8 (== the IVT reset vector).
        if f.get("name") == "start" and f.get("address") == 0x100100:
            f["address"] = 0x1001A8
    # Drop known scan artifacts: function entries that land on string/crypto
    # pools (no real code there). These are rare and identified individually.
    fns = [f for f in fns
           if not (f.get("name"), f.get("address")) in DATA_ARTIFACT_ENTRIES]
    fns.sort(key=lambda f: f["address"])

    img_path = resolve_image(f"{image}.bin")
    model = load_mmio_model()
    ivt = None
    rows = []
    start = time.time()

    # In boot-first mode, boot the platform once per image, snapshot every
    # mapped region, then run each function against a RESTORED copy of that
    # booted state (heap initialized, globals populated) with MMIO behavior
    # state reset. This quantifies how many standalone faults are boot-state
    # dependencies (the allocator's udf trap, data-structure callbacks) vs
    # genuine model gaps: boot context is the real operating condition the
    # firmware expects. Each function gets the SAME booted memory, so runs
    # don't leak state into each other.
    plat = Aic8800D80Platform(img_path, mmio_model=model)
    plat.function_table = load_function_table(image)
    ivt = plat.ivt()
    boot_snapshot = None
    bootstate_dict = None
    if boot_first:
        bt, bstats = plat.run(ivt["reset_vector"], boot_insns, sp=ivt["stack_pointer"])
        boot_snapshot = snapshot_memory(plat.mu)
    elif bootstate:
        # Capture the boot's persistent global-region writes once per image.
        bootstate_dict = capture_bootstate(image, boot_insns)

    for i, fn in enumerate(fns):
        if every > 1 and i % every != 0:
            continue
        chip = fn["address"] + HW_OFFSET
        if boot_first:
            restore_memory(plat.mu, boot_snapshot)
            # Reset emulator behavioral state so each function sees the same
            # fresh post-boot MMIO state (poll counters, written values).
            plat.mmio_state = {}
            plat._poll_reads = {}
            plat._strobe_until = {}
        else:
            plat = Aic8800D80Platform(img_path, mmio_model=model)
            plat.function_table = load_function_table(image)
            ivt = plat.ivt()
            if bootstate_dict is not None:
                # Seed the boot-initialized globals into the fresh platform
                # (heap head, callback slots) WITHOUT the booted SRAM structs.
                apply_bootstate(plat.mu, bootstate_dict)
        term, stats = plat.run(chip, max_insns, sp=ivt["stack_pointer"])
        rows.append({
            "image": image,
            "name": fn["name"],
            "address": hex(chip),
            "termination": term,
            "instructions": stats["instructions"],
            "fault": stats.get("fault") or "",
            "fault_pc": stats.get("fault_pc"),
            "fault_access": stats.get("fault_access"),
            "fault_address": stats.get("fault_address"),
            "mmio_reads": stats["mmio_reads"],
            "mmio_writes": stats["mmio_writes"],
        })
    elapsed = time.time() - start

    with out_path.open("w", encoding="utf-8") as f:
        for r in rows:
            f.write(json.dumps(r, sort_keys=True) + "\n")

    counts = Counter(r["termination"] for r in rows)
    faults = [r for r in rows if "fault" in r["termination"]]
    # Bucket faults by fault-address page and fault-pc page.
    fault_pages = Counter()
    fault_pcs = Counter()
    for r in faults:
        if r["fault_address"]:
            a = int(r["fault_address"], 16)
            fault_pages[(a & ~(PAGE - 1))] += 1
        if r["fault_pc"]:
            pc = int(r["fault_pc"], 16)
            fault_pcs[(pc & ~(PAGE - 1))] += 1

    return {
        "image": image,
        "scanned": len(fns),
        "sampled": len(rows),
        "returned": counts["returned"],
        "capped": counts["capped"],
        "faulted": counts["fault"],
        "elapsed_s": round(elapsed, 1),
        "boot_first": boot_first,
        "bootstate": bootstate,
        "fault_pages": [{"page": hex(p), "n": n} for p, n in fault_pages.most_common(15)],
        "fault_pcs": [{"page": hex(p), "n": n} for p, n in fault_pcs.most_common(15)],
    }


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--images", nargs="*", default=list(IMAGE_NAMES),
                    help="images to sweep (default: all)")
    ap.add_argument("--max-insns", type=int, default=DEFAULT_CAP)
    ap.add_argument("--every", type=int, default=1,
                    help="only run every Nth function (sampling)")
    ap.add_argument("--out", default="/tmp/opencode/corpus_sweep",
                    help="output directory")
    ap.add_argument("--boot-first", action="store_true",
                    help="boot the image once, then run every function "
                         "against the booted state (heap/globals initialized)")
    ap.add_argument("--bootstate", action="store_true",
                    help="boot once, capture only the persistent global-region "
                         "writes, and inject them into each fresh function run "
                         "(allocator heap head + callback slots, no SRAM structs)")
    ap.add_argument("--boot-insns", type=int, default=50000,
                    help="instructions for the --boot-first/--bootstate boot")
    args = ap.parse_args()

    if args.boot_first and args.bootstate:
        ap.error("--boot-first and --bootstate are mutually exclusive")

    out_dir = Path(args.out)
    out_dir.mkdir(parents=True, exist_ok=True)
    summaries = []
    for img in args.images:
        out = out_dir / f"{img}.jsonl"
        s = sweep_image(img, args.max_insns, args.every, out,
                        boot_first=args.boot_first, boot_insns=args.boot_insns,
                        bootstate=args.bootstate)
        summaries.append(s)
        mode = ("boot-first" if args.boot_first
                else "bootstate" if args.bootstate else "standalone")
        print(f"[sweep:{mode}] {s['image']:28s} scanned={s['scanned']:5d} "
              f"sampled={s['sampled']:5d} returned={s['returned']:5d} "
              f"capped={s['capped']:5d} faulted={s['faulted']:5d} "
              f"({s['elapsed_s']:.0f}s)", file=sys.stderr)
        for fp in s.get("fault_pages", [])[:6]:
            print(f"    fault@page {fp['page']}: {fp['n']}", file=sys.stderr)

    (out_dir / "summary.json").write_text(json.dumps(summaries, indent=2))
    print(json.dumps(summaries, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
