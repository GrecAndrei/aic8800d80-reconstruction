#!/usr/bin/env python3
"""Run truth-lane targets in the fully linked reconstruction, callees included.

`truth_lane_smoke.py` compiles one body and stubs everything it calls, so a
target whose peripheral writes all happen in callees cannot be judged there.
This tool runs the same target inside the `tools/full_link.py` ELF, where every
callee is the reconstructed body, on the same Unicorn platform and MMIO model
`aic8800d80_emulator.py verify` uses for the original binary, and compares the
complete peripheral traffic of the two runs.

The comparison covers one default-state path (zeroed RAM, boot callbacks
stubbed). An identical write sequence on that path is not behavioral
equivalence of the function.

Prerequisites:
  make -C src check
  python3 tools/full_link.py --text-base 0x800000 --out build/full_link_run

Usage:
  python3 tools/linked_recon_run.py --out /tmp/linked_run
  python3 tools/linked_recon_run.py --all --out /tmp/linked_run_all
  python3 tools/linked_recon_run.py --corpus --out /tmp/linked_corpus   # every composed function
"""
from __future__ import annotations

import argparse
import bisect
import functools
import json
import multiprocessing
import re
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

from unicorn import UC_HOOK_CODE
from unicorn.arm_const import UC_ARM_REG_PC, UC_ARM_REG_R0

import aic8800d80_emulator as emu
import link_freshness

REPO = Path(__file__).resolve().parent.parent
FULL_LINK = REPO / "build" / "full_link_run"
ORIG_BASELINE = REPO / "metadata" / "truth_lane_orig_depth0.json"
SHORT = {"fmacfw_8800d80_h_u02": "fmacfw_h_u02", "fmacfw_8800d80_u02": "fmacfw_u02",
         "fmacfwbt_8800d80_u02": "fmacfwbt_u02", "lmacfw_rf_8800d80_u02": "lmacfw_rf_u02"}
MARKER = re.compile(r"^// (\S+) @ (0x[0-9a-fA-F]+)\s*$", re.MULTILINE)
# The reconstructed data model keeps the original's absolute pointers into the
# image at 0x120000, so the linked code is placed clear of it and the original
# image stays mapped as the data those pointers refer to.
LINK_BASE = 0x00800000
# A run ends by returning or by reaching the firmware's assert trap (udf #255,
# which never returns on hardware). Both are comparable; a cap or a fault is not.
ENDED = ("returned", "asserted")
# The tick counters advance by this much per read in both runs (not by
# instruction count, which differs between the two builds of the same logic).
COUNTER_TICKS_PER_READ = 100
LINK_SPAN = 0x00400000


@functools.lru_cache(maxsize=None)
def marker_names(image: str) -> dict[int, str]:
    # main.c is an umbrella of #include "modules/modNNN.c" since
    # de-monolithization — expand includes so markers in module files are seen
    import re as _re
    base = REPO / "src" / SHORT[image]
    umbrella = (base / "main.c").read_text(errors="replace")
    parts = []
    for line in umbrella.splitlines(keepends=True):
        inc = _re.match(r'#include "(modules/mod[^"]+\.c)"\s*$', line)
        if inc and (base / inc.group(1)).exists():
            parts.append((base / inc.group(1)).read_text(errors="replace"))
        else:
            parts.append(line)
    text = "".join(parts)
    return {int(a, 16): n for n, a in MARKER.findall(text)}


def check_elf_freshness(path: Path) -> None:
    """Reject a runtime ELF whose content does not derive from current inputs.

    The behavioral corpus is meaningless when it accidentally executes a stale
    reconstruction — and `make reproduce` rewrites main.c even when the compose
    fixed point leaves the bytes unchanged, so mtimes cannot prove freshness.
    The ELF must carry a full_link stamp whose content fingerprint of the whole
    derivation chain (main.c, headers, Makefile, object, full_link.py) matches
    the current tree, linked at the runtime base.
    """
    stem = path.parent.name
    regenerate = ("regenerate with "
                  "python3 tools/full_link.py --text-base 0x800000 --out build/full_link_run")
    stamp = link_freshness.read_stamp(path)
    if stamp is None:
        raise SystemExit(f"unstamped linked reconstruction {path}: predates provenance tracking; {regenerate}")
    if int(stamp.get("text_base", "0"), 16) != LINK_BASE:
        raise SystemExit(
            f"wrong-base linked reconstruction {path}: linked at {stamp.get('text_base')} "
            f"but the runtime corpus requires {LINK_BASE:#x}; {regenerate}")
    current = link_freshness.src_fingerprint(stem)
    if stamp.get("src_fingerprint") != current:
        raise SystemExit(
            f"stale linked reconstruction {path}: inputs changed since it was linked; {regenerate}")


@functools.lru_cache(maxsize=None)
def load_elf(path: Path) -> tuple[int, bytes, int, list[tuple[int, str]]]:
    """Return (base, loadable bytes, end of .bss, sorted [(addr, function)])."""
    check_elf_freshness(path)
    with path.open("rb") as f:
        elf = ELFFile(f)
        segs = [s for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
        base = min(s["p_vaddr"] for s in segs)
        end = max(s["p_vaddr"] + s["p_filesz"] for s in segs)
        mem_end = max(s["p_vaddr"] + s["p_memsz"] for s in segs)
        blob = bytearray(end - base)
        for s in segs:
            off = s["p_vaddr"] - base
            blob[off:off + s["p_filesz"]] = s.data()
        funcs = sorted({(sym["st_value"] & ~1, sym.name)
                        for sym in elf.get_section_by_name(".symtab").iter_symbols()
                        if sym["st_info"]["type"] == "STT_FUNC" and sym.name})
    return base, bytes(blob), mem_end, funcs


def periph_traffic(traffic: list[dict]) -> list[dict]:
    return [t for t in traffic if emu.is_periph_addr(int(t["addr"], 16))]


def fingerprint(traffic: list[dict]) -> dict:
    p = periph_traffic(traffic)
    writes = [(t["addr"], t.get("value")) for t in p if t["op"] == "write"]
    return {
        "periph_addrs": sorted({t["addr"] for t in p}),
        "periph_write_addrs": sorted({a for a, _ in writes}),
        "periph_write_sequence": [[a, v] for a, v in writes],
        "periph_write_pcs": [t["pc"] for t in p if t["op"] == "write"],
        "periph_sequence": [[t["op"], t["addr"]] for t in p],
    }


def differing_write_registers(orig: dict, recon: dict) -> list[str]:
    """Registers whose ordered written values differ between the two runs."""
    def per_reg(fp: dict) -> dict[str, list]:
        out: dict[str, list] = {}
        for addr, value in fp.get("periph_write_sequence", []):
            out.setdefault(addr, []).append(value)
        return out
    o, c = per_reg(orig), per_reg(recon)
    return sorted(a for a in o.keys() | c.keys() if o.get(a) != c.get(a))


def function_at(funcs: list[tuple[int, str]], pc: int) -> str | None:
    i = bisect.bisect_right(funcs, (pc, "\U0010ffff")) - 1
    return funcs[i][1] if i >= 0 else None


def run_original(image: str, key: int, max_insns: int, model) -> dict:
    path = emu.resolve_image(image)
    plat = emu.Aic8800D80Platform(path, mmio_model=model)
    plat.counter_by_reads = COUNTER_TICKS_PER_READ
    plat.function_table = emu.load_function_table(Path(path.name).stem)
    # The platform's free(NULL) shortcut for the original would let it run on
    # where the firmware asserts; the reconstruction gets no such shortcut.
    plat._free_entries = ()
    term, stats = plat.run(key + emu.HW_OFFSET, max_insns, sp=plat.ivt()["stack_pointer"],
                           assert_stops=True)
    return {"termination": term, "instructions": stats["instructions"],
            "r0": hex(plat.mu.reg_read(UC_ARM_REG_R0)),
            "functions": stats["functions"], **fingerprint(plat.traffic)}


def run_linked(image: str, key: int, max_insns: int, model) -> dict:
    stem = Path(image).stem
    elf = FULL_LINK / stem / f"{stem}.full.elf"
    if not elf.is_file():
        raise SystemExit(f"missing {elf}: see the prerequisites in this tool's docstring")
    name = marker_names(stem).get(key)
    base, blob, mem_end, funcs = load_elf(elf)
    by_name = {n: a for a, n in funcs}
    if name is None or name not in by_name:
        return {"termination": "no_symbol", "symbol": name}
    if base != LINK_BASE or mem_end > LINK_BASE + LINK_SPAN:
        raise SystemExit(f"{elf}: spans {base:#x}-{mem_end:#x}, expected --text-base {LINK_BASE:#x}")
    orig_image = emu.resolve_image(image)
    plat = emu.Aic8800D80Platform(orig_image, mmio_model=model)
    plat.counter_by_reads = COUNTER_TICKS_PER_READ
    sp = plat.ivt()["stack_pointer"]
    orig_len = len(plat.image)
    plat._map_rwx(LINK_BASE, LINK_SPAN)
    plat.mu.mem_write(LINK_BASE, blob)
    plat._free_entries = ()
    plat.function_table = funcs
    # A fetch inside the original image means the run left the reconstruction
    # (a code pointer in the data model that still holds a hardware address).
    left: list[str] = []

    def on_orig_code(uc, address, size, user_data):
        if len(left) < 16:
            left.append(hex(address))

    plat.mu.hook_add(UC_HOOK_CODE, on_orig_code, begin=emu.CHIP_BASE, end=emu.CHIP_BASE + orig_len)
    # The platform keys "is this code" off CHIP_BASE and the image bytes; point
    # both at the linked reconstruction for the run.
    saved = emu.CHIP_BASE
    emu.CHIP_BASE, plat.image = LINK_BASE, blob
    try:
        term, stats = plat.run(by_name[name], max_insns, sp=sp, assert_stops=True)
    finally:
        emu.CHIP_BASE = saved
    stopped_in = None
    if term not in ENDED:
        stopped_in = function_at(funcs, plat.mu.reg_read(UC_ARM_REG_PC))
    return {"termination": term, "stopped_in": stopped_in, "symbol": name, "linked_address": hex(by_name[name]),
            "instructions": stats["instructions"], "functions": stats["functions"],
            "r0": hex(plat.mu.reg_read(UC_ARM_REG_R0)),
            "fault": stats["fault"], "fault_pc": stats["fault_pc"],
            "fault_address": stats["fault_address"],
            "left_reconstruction_at": left, **fingerprint(plat.traffic)}


def linked_verdict(orig: dict, recon: dict) -> tuple[str, str]:
    """Return (verdict, basis) for one target's complete peripheral traffic."""
    if recon["termination"] == "no_symbol":
        return "REVIEW", "target_not_in_linked_image"
    if recon["termination"] not in ENDED:
        return "FAIL", "linked_run_did_not_return"
    if recon["left_reconstruction_at"]:
        return "REVIEW", "linked_run_left_reconstruction"
    if orig["termination"] not in ENDED:
        return "REVIEW", "original_did_not_return"
    if recon["termination"] != orig["termination"]:
        return "FAIL", "one_run_returns_the_other_asserts"
    if recon["periph_write_sequence"] == orig["periph_write_sequence"]:
        if recon["periph_sequence"] == orig["periph_sequence"]:
            return "PASS", "identical_peripheral_sequence"
        return "PASS", "identical_peripheral_write_sequence"
    if recon["periph_write_addrs"] == orig["periph_write_addrs"]:
        return "FAIL", "same_write_registers_different_sequence"
    return "FAIL", "peripheral_writes_differ"


def first_difference(orig: dict, recon: dict) -> dict | None:
    """First index at which the two ordered peripheral write sequences differ."""
    o, c = orig["periph_write_sequence"], recon.get("periph_write_sequence", [])
    for i in range(max(len(o), len(c))):
        x, y = (o[i] if i < len(o) else None), (c[i] if i < len(c) else None)
        if x != y:
            return {"index": i, "orig": x, "recon": y}
    return None


CONSOLE_TX = "0x40032000"


@functools.lru_cache(maxsize=None)
def marker_table(image: str) -> tuple[list[int], list[str]]:
    items = sorted(marker_names(image).items())
    return [a for a, _ in items], [n for _, n in items]


def writer_of(image: str, funcs, orig: dict, recon: dict, index: int) -> str | None:
    """Composed function executing the write at `index`: the reconstruction's
    when it has one there, else the original's (hardware pc -> analysis space)."""
    pcs = recon.get("periph_write_pcs", [])
    if index < len(pcs):
        return function_at(funcs, int(pcs[index], 16))
    pcs = orig["periph_write_pcs"]
    if index < len(pcs):
        addrs, names = marker_table(image)
        i = bisect.bisect_right(addrs, int(pcs[index], 16) - emu.HW_OFFSET) - 1
        return names[i] if i >= 0 else None
    return None


def corpus_outcome(orig: dict, recon: dict, verdict: str, diff: dict | None,
                   writer: str | None) -> tuple[str, str]:
    """(outcome, group) for one function of the corpus.

    MATCH / DIFFER are decided only where a comparison exists: the original
    returns on the default-state path and the function is in the linked image.
    The group of a DIFFER row is where the two runs part, which is a location,
    not a diagnosis; docs/LINKED_CORPUS_COMPARISON.md maps groups to causes.
    """
    if recon["termination"] == "no_symbol":
        return "NOT_RUN", "not_in_linked_image"
    if orig["termination"] not in ENDED:
        return "NOT_RUN", "original_does_not_return_standalone"
    if verdict == "PASS":
        if orig["termination"] == "asserted":
            return "MATCH", "identical_peripheral_writes_up_to_assert_trap"
        return "MATCH", "identical_peripheral_writes"
    if verdict == "REVIEW":
        return "NOT_RUN", "linked_run_left_reconstruction"
    if recon["termination"] not in ENDED:
        return "DIFFER", f"no_return_in:{recon.get('stopped_in')}"
    if recon["termination"] != orig["termination"]:
        side = "reconstruction" if recon["termination"] == "asserted" else "original"
        return "DIFFER", f"assert_trap_only_in_{side}"
    if diff and CONSOLE_TX in ((diff["orig"] or [None])[0], (diff["recon"] or [None])[0]):
        return "DIFFER", "console_text"
    return "DIFFER", f"register_write_in:{writer}"


def corpus_row(job: tuple[str, int, str, int]) -> dict:
    image, key, name, max_insns = job
    model = emu.load_mmio_model()
    orig = run_original(image, key, max_insns, model)
    recon = run_linked(image, key, max_insns, model)
    verdict, basis = linked_verdict(orig, recon)
    diff = first_difference(orig, recon)
    stem = Path(image).stem
    writer = None
    if diff and recon["termination"] != "no_symbol":
        funcs = load_elf(FULL_LINK / stem / f"{stem}.full.elf")[3]
        writer = writer_of(stem, funcs, orig, recon, diff["index"])
    outcome, group = corpus_outcome(orig, recon, verdict, diff, writer)

    def side(r: dict) -> dict:
        return {"termination": r["termination"], "instructions": r.get("instructions"),
                "r0": r.get("r0"), "periph_writes": len(r.get("periph_write_sequence", [])),
                "stopped_in": r.get("stopped_in")}
    return {"image": stem, "function": name, "address": hex(key), "outcome": outcome,
            "group": group, "verdict": verdict, "verdict_basis": basis,
            "orig": side(orig), "recon": side(recon),
            "first_difference": diff, "first_difference_in": writer}


def summarize_corpus(rows: list[dict]) -> dict:
    outcomes: dict[str, int] = {}
    groups: dict[str, dict[str, int]] = {}
    per_image: dict[str, dict[str, int]] = {}
    for r in rows:
        outcomes[r["outcome"]] = outcomes.get(r["outcome"], 0) + 1
        g = groups.setdefault(r["outcome"], {})
        g[r["group"]] = g.get(r["group"], 0) + 1
        pi = per_image.setdefault(r["image"], {})
        pi[r["outcome"]] = pi.get(r["outcome"], 0) + 1
    order = lambda d: dict(sorted(d.items(), key=lambda kv: (-kv[1], kv[0])))
    return {"functions": len(rows), "outcomes": dict(sorted(outcomes.items())),
            "per_image": {k: dict(sorted(v.items())) for k, v in sorted(per_image.items())},
            "groups": {k: order(v) for k, v in sorted(groups.items())}}


def run_corpus(args: argparse.Namespace) -> int:
    """Compare every function composed into src/<image>/main.c, not only the truth lane."""
    jobs = [(f"{image}.bin", key, name, args.max_insns)
            for image in SHORT if args.image in (None, image)
            for key, name in sorted(marker_names(image).items())]
    with multiprocessing.Pool(args.jobs) as pool:
        rows = []
        for i, row in enumerate(pool.imap(corpus_row, jobs, chunksize=8), 1):
            rows.append(row)
            if i % 250 == 0:
                print(f"[corpus] {i}/{len(jobs)}", file=sys.stderr)
    args.out.mkdir(parents=True, exist_ok=True)
    with (args.out / "corpus_outcomes.jsonl").open("w") as f:
        for row in rows:
            f.write(json.dumps(row, sort_keys=True) + "\n")
    summary = summarize_corpus(rows)
    (args.out / "corpus_summary.json").write_text(json.dumps(summary, indent=2) + "\n")
    for outcome, n in summary["outcomes"].items():
        print(f"{outcome:8s} {n}")
        for group, k in list(summary["groups"][outcome].items())[:args.top]:
            print(f"    {k:5d}  {group}")
    print(f"total={len(rows)}")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--targets", type=Path, default=emu.TARGETS_DEFAULT)
    ap.add_argument("--orig-baseline", type=Path, default=ORIG_BASELINE)
    ap.add_argument("--all", action="store_true",
                    help="run every target, not only those whose original writes peripherals only in callees")
    ap.add_argument("--corpus", action="store_true",
                    help="run every function composed into src/<image>/main.c")
    ap.add_argument("--image", choices=sorted(SHORT), help="with --corpus: one image only")
    ap.add_argument("--jobs", type=int, default=None, help="with --corpus: worker processes")
    ap.add_argument("--top", type=int, default=12, help="with --corpus: groups printed per outcome")
    ap.add_argument("--max-insns", type=int, default=200000)
    ap.add_argument("--out", type=Path, required=True)
    args = ap.parse_args()
    if args.corpus:
        return run_corpus(args)

    baseline = {(r["image"], r["address"]): r for r in json.loads(args.orig_baseline.read_text())}
    model = emu.load_mmio_model()
    rows = []
    for t in json.loads(args.targets.read_text()):
        b = baseline.get((t["image"], t["address"]))
        if not args.all and not (b and b["callee_periph_write"] and not b["self_periph_write_addrs"]):
            continue
        key = emu._normalize_target_addr(t["image"], t["address"])
        orig = run_original(t["image"], key, args.max_insns, model)
        recon = run_linked(t["image"], key, args.max_insns, model)
        verdict, basis = linked_verdict(orig, recon)
        rows.append({"image": t["image"], "function": t["function"], "address": t["address"],
                     "verdict": verdict, "verdict_basis": basis,
                     "differing_write_registers": differing_write_registers(orig, recon),
                     "orig": orig, "recon": recon})
        print(f"[linked] {t['function']:28s} {t['image']:28s} {verdict:6s} {basis}", file=sys.stderr)

    args.out.mkdir(parents=True, exist_ok=True)
    (args.out / "linked_outcomes.json").write_text(json.dumps(rows, indent=1, sort_keys=True) + "\n")
    lines = ["| function | image | verdict | basis | orig writes | recon writes | differing registers | stopped in |",
             "|---|---|---|---|---|---|---|---|"]
    for r in rows:
        o, c = r["orig"], r["recon"]
        lines.append(f"| {r['function']} | {r['image']} | {r['verdict']} | {r['verdict_basis']} | "
                     f"{len(o['periph_write_sequence'])} | {len(c.get('periph_write_sequence', []))} | "
                     f"{', '.join(r['differing_write_registers'][:4]) or '-'}"
                     f"{' ...' if len(r['differing_write_registers']) > 4 else ''} | "
                     f"{c.get('stopped_in') or '-'} |")
    counts = {v: sum(1 for r in rows if r["verdict"] == v) for v in ("PASS", "REVIEW", "FAIL")}
    lines.append("")
    lines.append(f"PASS={counts['PASS']} REVIEW={counts['REVIEW']} FAIL={counts['FAIL']} total={len(rows)}")
    (args.out / "linked_summary.md").write_text("\n".join(lines) + "\n")
    print(lines[-1])
    return 0


if __name__ == "__main__":
    sys.exit(main())
