#!/usr/bin/env python3
"""Full (non --gc-sections) link for every AIC8800D80 firmware image.

The gc-sections gate keeps only code reachable from the entry, so it never
sees references from dead functions. A full link keeps every function and
surfaces every undefined symbol the reconstruction model must satisfy.
This tool makes the full link WORK: it generates a per-image ``artifacts.c``
that resolves each undefined symbol, links with ``--no-undefined``, and
verifies the result has zero undefs.

Undef resolution strategy (per symbol, in order):
  1. ``__aeabi_*``            -> linked from ``-lgcc`` (float helpers).
  2. libc helpers (memmove,
     memcpy, memset, strlen…)  -> linked from ``-lc``.
  3. name has an LLM-naming-dataset entry (indexed by BOTH the original
     ``fn`` and the LLM ``name``) whose chip address is inside a composed
     function in ``src/<img>/main.c``:
       - relocation is a call (R_ARM_THM_CALL / *_JUMP24 / R_ARM_CALL):
         emit a weak alias ``name -> <composed function>``. The dataset
         recorded the name for a (legacy / mid-function) address; the
         composed function that owns it is the real target.
       - relocation is a data ref (R_ARM_ABS32, …): emit a ``.bss`` blob.
         The decompiler emitted a data address as a named symbol
         (``*(uint32_t*)name``); a writable blob is the link-time target.
  4. name has a dataset entry but NO composed function owns the address
     (genuine gap / legacy boundary): emit a weak stub and record it.
  5. no dataset entry:
       - call relocation or ``sub_*`` prefix: weak stub + record (real
         missing code that still needs decompile + LLM name + recompose).
       - data relocation: ``.bss`` blob.
  6. ``MEMORY`` / ``COERCE_*`` decompiler noise: ``.bss`` blob.

The weak aliases/stubs are LINK-TIME SCAFFOLDING only — they are not claimed
as reconstructed bodies. Every stub is listed in ``report.json`` under
``real_missing`` and is the actionable next-rename list.

Outputs (gitignored ``build/full_link/``):
  build/full_link/<img>/artifacts.c, artifacts.o, <img>.full.elf
  build/full_link/report.json

Usage:
  python3 tools/full_link.py            # link all 4 images
  python3 tools/full_link.py --image fmacfw_8800d80_u02
"""
from __future__ import annotations

import argparse
import bisect
import json
import os
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMGS = ["fmacfw_8800d80_h_u02", "fmacfw_8800d80_u02",
        "fmacfwbt_8800d80_u02", "lmacfw_rf_8800d80_u02"]
LONG_TO_SHORT = {
    "fmacfw_8800d80_h_u02": "fmacfw_h_u02",
    "fmacfw_8800d80_u02": "fmacfw_u02",
    "fmacfwbt_8800d80_u02": "fmacfwbt_u02",
    "lmacfw_rf_8800d80_u02": "lmacfw_rf_u02",
}
V14_TO_CHIP = 0x1100000
FUNC_RELOCS = {"R_ARM_THM_CALL", "R_ARM_THM_JUMP24", "R_ARM_CALL", "R_ARM_JUMP24"}
LIBC_HELPERS = {"memmove", "memcpy", "memset", "strlen", "strcpy", "strcmp", "memcmp"}
ARTIFACT_NAMES = {"MEMORY", "COERCE_UNSIGNED_INT", "COERCE_FLOAT"}
CC = os.environ.get("CROSS_COMPILE", "arm-none-eabi-") + "gcc"
NM = os.environ.get("CROSS_COMPILE", "arm-none-eabi-") + "nm"
READELF = os.environ.get("CROSS_COMPILE", "arm-none-eabi-") + "readelf"
OBJDUMP = os.environ.get("CROSS_COMPILE", "arm-none-eabi-") + "objdump"
CFLAGS = ["-mcpu=cortex-m4", "-mthumb", "-O2", "-Iinclude", "-w", "-std=gnu99",
          "-ffunction-sections", "-fdata-sections", "-include", "include/aic8800d80_types.h"]
# artifacts.c is pure scaffolding (stdint only) — compiling it with the forced
# firmware header would re-emit Hex-Rays register globals (_CF/_R0/...) and
# collide with the same globals in main.o.
ARTIFACT_CFLAGS = ["-mcpu=cortex-m4", "-mthumb", "-O2", "-w", "-std=gnu99",
                   "-ffunction-sections", "-fdata-sections"]
BLOB_SIZE = 0x1000  # .bss blob covering indexed accesses like [0x3F8]


def to_chip(img: str, addr: int) -> int | None:
    """Dataset addresses mix chip-space and v14-space; return chip address."""
    lo, hi = 0x100000, 0x100000 + (REPO / f"inputs/firmware/{img}.bin").stat().st_size
    for cand in (addr, addr - V14_TO_CHIP):
        if lo <= cand < hi:
            return cand
    return None


def load_dataset() -> dict[str, list[tuple[str, int]]]:
    """Index the LLM naming dataset by BOTH original fn and LLM name.

    Returns {name: [(img_long, chip_addr), ...]}. Images stored as the long
    form (dataset uses ``fmacfw_8800d80_u02`` after stripping ``_bin``).
    """
    out: dict[str, list[tuple[str, int]]] = {}
    names_dir = REPO / "harness_v17" / "names"
    for f in os.listdir(names_dir):
        if not f.endswith(".json"):
            continue
        try:
            j = json.loads((names_dir / f).read_text(errors="replace"))
        except Exception:
            continue
        img = (j.get("img") or "").replace("_bin", "")
        if img not in LONG_TO_SHORT:
            continue
        addr = j.get("addr", "")
        try:
            a = int(addr, 16)
        except ValueError:
            continue
        chip = to_chip(img, a)
        if chip is None:
            continue
        for k in {j.get("fn"), j.get("name")}:
            if k:
                out.setdefault(k, []).append((img, chip))
    return out


def load_composed(img: str) -> dict[int, str]:
    """{start_addr: function_name} from the composed main.c (// name @ addr)."""
    main = REPO / "src" / LONG_TO_SHORT[img] / "main.c"
    d: dict[int, str] = {}
    if main.is_file():
        for m in re.finditer(r"^// (\S+) @ (0x[0-9a-fA-F]+)$",
                             main.read_text(errors="replace"), re.M):
            d[int(m.group(2), 16)] = m.group(1)
    return d


def reloc_types(obj: Path) -> dict[str, set[str]]:
    """{symbol: {reloc type}} across the whole object (--wide, no truncation)."""
    out = subprocess.run([READELF, "-W", "-r", str(obj)],
                         capture_output=True, text=True).stdout
    r: dict[str, set[str]] = {}
    for line in out.splitlines():
        parts = line.split()
        if len(parts) >= 5 and parts[2].startswith("R_ARM"):
            r.setdefault(parts[-1], set()).add(parts[2])
    return r


def collect_undefs(img: str) -> list[str]:
    obj = REPO / "src" / f"{img}.o"
    if not obj.is_file():
        raise SystemExit(f"missing {obj}; run 'make -C src check' first")
    out = subprocess.run([NM, "-u", str(obj)], capture_output=True, text=True)
    return sorted({line.split()[-1] for line in out.stdout.splitlines() if line.split()})


def sanitize(sym: str) -> str:
    return re.sub(r"[^0-9A-Za-z_]", "_", sym)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--image", choices=IMGS, default=None, help="link one image (default: all)")
    ap.add_argument("--out", default="", help="output root (default: build/full_link)")
    args = ap.parse_args()

    out_root = Path(args.out) if args.out else REPO / "build" / "full_link"
    dataset = load_dataset()
    images = [args.image] if args.image else IMGS

    report = {"images": {}, "total_missing": 0}
    rc = 0
    for img in images:
        composed = load_composed(img)
        csorted = sorted(composed.items())
        starts = [a for a, _ in csorted]
        reloc = reloc_types(REPO / "src" / f"{img}.o")

        aliases: dict[str, str] = {}      # sym -> composed fn
        blobs: list[str] = []             # .bss blobs
        stubs: list[dict] = []            # weak stub functions (real gaps)
        skipped: list[str] = []           # __aeabi_* / libc
        blob_l: list[str] = []

        for u in collect_undefs(img):
            if u.startswith("__aeabi_") or u in LIBC_HELPERS:
                skipped.append(u)
                continue
            kinds = reloc.get(u, set())
            is_call = bool(kinds & FUNC_RELOCS) or (not kinds and u.startswith("sub_"))
            local = [(i2, c) for (i2, c) in dataset.get(u, []) if i2 == img]
            if local:
                chip = local[0][1]
                i = bisect.bisect_right(starts, chip) - 1
                if i >= 0 and (i + 1 >= len(starts) or chip < starts[i + 1]):
                    # dataset address is inside a composed function
                    target = composed[starts[i]]
                    if is_call:
                        aliases[u] = target
                    else:
                        blobs.append(u)
                        blob_l.append(u)
                    continue
                # dataset entry but no composed owner -> stub
                stubs.append({"symbol": u, "address": hex(chip),
                              "reason": "dataset-address-not-in-composed"})
                continue
            if u in ARTIFACT_NAMES and not is_call:
                blobs.append(u)
                blob_l.append(u)
                continue
            if not is_call:
                blobs.append(u)
                blob_l.append(u)
                continue
            stubs.append({"symbol": u, "address": "",
                          "reason": "no-dataset-entry"})

        # ---- emit artifacts.c -------------------------------------------------
        out_dir = out_root / img
        out_dir.mkdir(parents=True, exist_ok=True)
        lines: list[str] = [
            "/* Generated by tools/full_link.py — LINK-TIME SCAFFOLDING ONLY. */",
            "/* Weak aliases/stubs/blobs resolve full-link undefs; they are NOT */",
            "/* claimed reconstructed bodies. See report.json for real gaps. */",
            "#include <stdint.h>",
            "",
        ]
        # Alias trampolines: C `__attribute__((alias))` requires a same-TU
        # definition; `.thumb_set` to an external symbol loses Thumb mode.
        # A `.thumb_func` stub that branches (b.w, not bl) to the target is
        # a real Thumb symbol, preserves the callee's behavior, and resolves
        # a full-link undef against the composed function that owns the
        # dataset address. Emitted as raw asm in the C artifact file.
        for sym, target in sorted(aliases.items()):
            s = sanitize(sym)
            t = sanitize(target)
            lines.append("__asm__("
                         '".syntax unified\\n" '
                         '".thumb\\n" '
                         f'".weak {s}\\n" '
                         '".thumb_func\\n" '
                         f'".global {s}\\n" '
                         f'"{s}:\\n" '
                         f'"  b {t}\\n");')
        if aliases:
            lines.append("")
        for sym in sorted(blobs):
            lines.append(f"unsigned char {sanitize(sym)}[{BLOB_SIZE}] "
                         "__attribute__((section(\".bss\"), weak));")
        if blobs:
            lines.append("")
        for s in stubs:
            sym = sanitize(s["symbol"])
            lines.append(f"__attribute__((weak)) int {sym}(void);")
            lines.append(f"int {sym}(void) {{ return 0; }}")
        if stubs:
            lines.append("")

        artifacts_c = out_dir / "artifacts.c"
        artifacts_c.write_text("\n".join(lines) + "\n")

        # ---- compile artifacts + link (no gc-sections) -----------------------
        obj = out_dir / "artifacts.o"
        gcc = [CC, *ARTIFACT_CFLAGS, "-c", str(artifacts_c), "-o", str(obj)]
        c = subprocess.run(gcc, capture_output=True, text=True, cwd=str(REPO / "src"))
        if c.returncode:
            print(f"[full_link] artifacts compile FAILED for {img}:\n{c.stderr[:2000]}",
                  file=sys.stderr)
            rc = 1
            continue

        # Entry: use `start` when the object defines it (fmacfw/fmacfw_h/
        # lmacfw_rf); fmacfwbt's boot entry (CPUID check at file 0x1a8) is a
        # genuine reconstruction gap, so fall back to an absolute address.
        nm_out = subprocess.run([NM, str(REPO / "src" / f"{img}.o")],
                                capture_output=True, text=True)
        has_start = any(len(p.split()) >= 3 and p.split()[2] == "start"
                        and p.split()[1] != "U"
                        for p in nm_out.stdout.splitlines())
        if has_start:
            entry_flag = ["-Wl,-e,start"]
        else:
            entry_flag = ["-Wl,-e,0x1001a8"]
            stubs.append({"symbol": "start", "address": "0x1001a8",
                          "reason": "boot-entry-not-composed"})

        elf = out_dir / f"{img}.full.elf"
        link = [CC, "-mcpu=cortex-m4", "-mthumb", "-nostdlib",
                "-Wl,--no-gc-sections", "-Wl,--no-undefined",
                "-Wl,-Ttext=0x100000", "-Wl,--fix-cortex-a8",
                *entry_flag,
                str(REPO / "src" / f"{img}.o"), str(obj),
                "-lgcc", "-lc", "-o", str(elf)]
        l = subprocess.run(link, capture_output=True, text=True)
        if l.returncode:
            print(f"[full_link] link FAILED for {img}:\n{l.stderr[:3000]}",
                  file=sys.stderr)
            rc = 1
            continue

        undef = subprocess.run([NM, "-u", str(elf)], capture_output=True, text=True)
        undef_syms = sorted({x.split()[-1] for x in undef.stdout.splitlines()
                             if x.split() and ":" not in x.split()[-1]})
        ok = not undef_syms
        if not ok:
            print(f"[full_link] {img}: residual undefs: {undef_syms[:10]}", file=sys.stderr)
            rc = 1

        img_report = {
            "aliases": {k: v for k, v in sorted(aliases.items())},
            "data_blobs": sorted(blob_l),
            "real_missing_stubs": sorted(stubs, key=lambda s: s["symbol"]),
            "skipped_libgcc_libc": sorted(skipped),
            "undefs_resolved": len(aliases) + len(blobs) + len(stubs) + len(skipped),
            "residual_undefs": undef_syms,
            "elf": str(elf),
            "status": "OK" if ok else "UNDEFS",
        }
        report["images"][img] = img_report
        report["total_missing"] += len(stubs)
        print(f"[full_link] {img}: aliases={len(aliases)} blobs={len(blobs)} "
              f"stubs={len(stubs)} libgcc/libc={len(skipped)} "
              f"residual={len(undef_syms)} -> {img_report['status']}")

    (out_root / "report.json").write_text(json.dumps(report, indent=2) + "\n")
    print(f"\n[full_link] report: {out_root / 'report.json'}")
    return rc


if __name__ == "__main__":
    raise SystemExit(main())
