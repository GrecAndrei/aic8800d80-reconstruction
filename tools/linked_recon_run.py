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
"""
from __future__ import annotations

import argparse
import bisect
import json
import re
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

from unicorn import UC_HOOK_CODE
from unicorn.arm_const import UC_ARM_REG_PC

import aic8800d80_emulator as emu

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
LINK_SPAN = 0x00400000


def marker_names(image: str) -> dict[int, str]:
    text = (REPO / "src" / SHORT[image] / "main.c").read_text(errors="replace")
    return {int(a, 16): n for n, a in MARKER.findall(text)}


def load_elf(path: Path) -> tuple[int, bytes, int, list[tuple[int, str]]]:
    """Return (base, loadable bytes, end of .bss, sorted [(addr, function)])."""
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
    plat.function_table = emu.load_function_table(Path(path.name).stem)
    term, stats = plat.run(key + emu.HW_OFFSET, max_insns, sp=plat.ivt()["stack_pointer"])
    return {"termination": term, "instructions": stats["instructions"],
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
        term, stats = plat.run(by_name[name], max_insns, sp=sp)
    finally:
        emu.CHIP_BASE = saved
    stopped_in = None
    if term != "returned":
        stopped_in = function_at(funcs, plat.mu.reg_read(UC_ARM_REG_PC))
    return {"termination": term, "stopped_in": stopped_in, "symbol": name, "linked_address": hex(by_name[name]),
            "instructions": stats["instructions"], "functions": stats["functions"],
            "fault": stats["fault"], "fault_pc": stats["fault_pc"],
            "fault_address": stats["fault_address"],
            "left_reconstruction_at": left, **fingerprint(plat.traffic)}


def linked_verdict(orig: dict, recon: dict) -> tuple[str, str]:
    """Return (verdict, basis) for one target's complete peripheral traffic."""
    if recon["termination"] == "no_symbol":
        return "REVIEW", "target_not_in_linked_image"
    if recon["termination"] != "returned":
        return "FAIL", "linked_run_did_not_return"
    if recon["left_reconstruction_at"]:
        return "REVIEW", "linked_run_left_reconstruction"
    if orig["termination"] != "returned":
        return "REVIEW", "original_did_not_return"
    if recon["periph_write_sequence"] == orig["periph_write_sequence"]:
        if recon["periph_sequence"] == orig["periph_sequence"]:
            return "PASS", "identical_peripheral_sequence"
        return "PASS", "identical_peripheral_write_sequence"
    if recon["periph_write_addrs"] == orig["periph_write_addrs"]:
        return "FAIL", "same_write_registers_different_sequence"
    return "FAIL", "peripheral_writes_differ"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--targets", type=Path, default=emu.TARGETS_DEFAULT)
    ap.add_argument("--orig-baseline", type=Path, default=ORIG_BASELINE)
    ap.add_argument("--all", action="store_true",
                    help="run every target, not only those whose original writes peripherals only in callees")
    ap.add_argument("--max-insns", type=int, default=200000)
    ap.add_argument("--out", type=Path, required=True)
    args = ap.parse_args()

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
