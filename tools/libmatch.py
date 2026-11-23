#!/usr/bin/env python3
"""libmatch.py — bind toolchain library routines by byte identity.

The firmware statically links newlib and libgcc routines (strlen, memcpy,
__aeabi_dmul, ...). They are hand-written assembly (`uadd8`/`sel`, flag-driven
tail jumps between entry points) that Hex-Rays cannot express: the decompiled
`strlen` is `while ( !HIDWORD(0) )`, an infinite loop, and the soft-float
routines are split into fragments joined by `JUMPOUT`.

Where the bytes of a function in the image are identical to a relocation-free
routine of the installed toolchain's libc.a / libgcc.a, the routine is known
exactly, so the reconstruction links the library routine instead of the
decompiled body:

  scan    search the 4 images, write metadata/libmatch.json (address, size,
          library symbol, archive member, sha256 of the matched bytes).
  apply   in src/<img>/main.c, for every composed function that starts at a
          matched address: drop the decompiled body and put an asm label on
          its forward declaration (`... memmove_5(unsigned int a1)
          __asm__("__libmatch_strlen");`). Names are untouched. Idempotent.
          The decompiled body stays in src/<img>/functions/.

`link_objects()` (used by tools/full_link.py) extracts the matched archive
members and renames their global symbols with the `__libmatch_` prefix, so the
binding cannot collide with a composed function that the naming dataset
happens to call `strlen` or `memcpy`.

Runs after `fwstruct compose` + `tools/heal_composed.py`, before
`tools/volatile_pointees.py`. A match is evidence about that one routine's
bytes only. Functions with relocations are not matched.
"""
import argparse
import hashlib
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

REPO = Path(__file__).resolve().parent.parent
META = REPO / "metadata" / "libmatch.json"
CC, AR, OBJCOPY = "arm-none-eabi-gcc", "arm-none-eabi-ar", "arm-none-eabi-objcopy"
ARCH = ["-mcpu=cortex-m4", "-mthumb"]
LIBS = ("libc.a", "libgcc.a")
IMAGES = {
    "fmacfw_8800d80_h_u02": "fmacfw_h_u02",
    "fmacfw_8800d80_u02": "fmacfw_u02",
    "fmacfwbt_8800d80_u02": "fmacfwbt_u02",
    "lmacfw_rf_8800d80_u02": "lmacfw_rf_u02",
}
ANALYSIS_BASE = 0x100000
MIN_SIZE = 16
PREFIX = "__libmatch_"
MARKER = re.compile(r"(?m)^// (\w+) @ 0x([0-9a-fA-F]+)[^\n]*\n")
BODIES = "/* --- function bodies --- */"


def lib_path(lib: str) -> Path:
    return Path(subprocess.check_output([CC, *ARCH, f"-print-file-name={lib}"], text=True).strip()).resolve()


def toolchain() -> str:
    return subprocess.check_output([CC, "--version"], text=True).splitlines()[0]


def extract(lib: str, dest: Path) -> list[Path]:
    dest.mkdir(parents=True, exist_ok=True)
    subprocess.run([AR, "x", str(lib_path(lib))], cwd=dest, check=True)
    return sorted(dest.glob("*.o"))


def library_functions(tmp: Path) -> dict[str, dict]:
    """Global relocation-free functions: symbol -> {bytes, lib, member}."""
    out: dict[str, dict] = {}
    for lib in LIBS:
        for obj in extract(lib, tmp / lib):
            with obj.open("rb") as f:
                elf = ELFFile(f)
                symtab = elf.get_section_by_name(".symtab")
                if symtab is None:
                    continue
                relocs: dict[int, list[int]] = {}
                for sec in elf.iter_sections():
                    if isinstance(sec, RelocationSection):
                        relocs.setdefault(sec["sh_info"], []).extend(r["r_offset"] for r in sec.iter_relocations())
                for sym in symtab.iter_symbols():
                    if (sym["st_info"]["type"] != "STT_FUNC" or sym["st_info"]["bind"] == "STB_LOCAL"
                            or sym["st_size"] < MIN_SIZE or not isinstance(sym["st_shndx"], int)):
                        continue
                    start, size = sym["st_value"] & ~1, sym["st_size"]
                    if any(start <= r < start + size for r in relocs.get(sym["st_shndx"], [])):
                        continue
                    data = elf.get_section(sym["st_shndx"]).data()[start:start + size]
                    out.setdefault(sym.name, {"bytes": data, "lib": lib, "member": obj.name})
    return out


def canonical(names: list[str]) -> str:
    """One symbol per address: the AEABI name if any, else the first by name."""
    return sorted(names, key=lambda n: (not n.startswith("__aeabi_"), n))[0]


def scan() -> dict:
    with tempfile.TemporaryDirectory() as td:
        funcs = library_functions(Path(td))
    images = {}
    for img in IMAGES:
        data = (REPO / "inputs" / "firmware" / f"{img}.bin").read_bytes()
        at: dict[int, list[str]] = {}
        for name, fn in funcs.items():
            pos = data.find(fn["bytes"])
            while pos >= 0:
                at.setdefault(pos, []).append(name)
                pos = data.find(fn["bytes"], pos + 1)
        rows = []
        for pos in sorted(at):
            sym = canonical(at[pos])
            fn = funcs[sym]
            rows.append({
                "address": f"{ANALYSIS_BASE + pos:#x}",
                "size": len(fn["bytes"]),
                "symbol": sym,
                "aliases": sorted(set(at[pos]) - {sym}),
                "lib": fn["lib"],
                "member": fn["member"],
                "sha256": hashlib.sha256(fn["bytes"]).hexdigest(),
            })
        images[img] = rows
    return {"toolchain": toolchain(), "min_size": MIN_SIZE, "images": images}


def load_meta() -> dict:
    return json.loads(META.read_text())


def bind(text: str, rows: list[dict]) -> tuple[str, list[dict]]:
    """Bind every composed function that starts at a matched address."""
    by_addr = {int(r["address"], 16): r for r in rows}
    split = text.index(BODIES)
    head, tail = text[:split], text[split:]
    marks = list(MARKER.finditer(tail))
    done: list[dict] = []
    pieces, last = [], 0
    for i, m in enumerate(marks):
        row = by_addr.get(int(m.group(2), 16))
        if row is None:
            continue
        end = marks[i + 1].start() if i + 1 < len(marks) else len(tail)
        if "{" not in tail[m.end():end]:
            continue                       # already bound
        name, label = m.group(1), PREFIX + row["symbol"]
        decl = re.compile(r"(?m)^([^\n;{}]*\b" + re.escape(name) + r"\s*\([^;{}]*\));$")
        hit = decl.search(head)
        if hit is None:
            raise SystemExit(f"libmatch: no forward declaration for {name}")
        head = head[:hit.start()] + f'{hit.group(1)} __asm__("{label}");' + head[hit.end():]
        pieces.append(tail[last:m.end()])
        pieces.append(f"/* libmatch: {row['size']} bytes identical to {row['symbol']} "
                      f"({row['lib']}:{row['member']}); the library routine is linked */\n\n\n")
        last = end
        done.append({"name": name, **row})
    pieces.append(tail[last:])
    return head + "".join(pieces), done


def _member_syms(obj: Path) -> dict[str, tuple[object, str]]:
    with obj.open("rb") as f:
        elf = ELFFile(f)
        syms: dict[str, tuple[object, str]] = {}
        for s in elf.get_section_by_name(".symtab").iter_symbols():
            if not s.name or s["st_info"]["bind"] == "STB_LOCAL" or not isinstance(s["st_shndx"], int):
                continue
            data = elf.get_section(s["st_shndx"]).data()[(s["st_value"] & ~1):][:s["st_size"]]
            syms[s.name] = (s, hashlib.sha256(data).hexdigest())
        return syms


def _find_member_for_row(lib_dir: Path, row: dict) -> Path:
    cand = lib_dir / row["member"]
    if cand.is_file():
        syms = _member_syms(cand)
        if row["symbol"] in syms and syms[row["symbol"]][1] == row["sha256"]:
            return cand
    # Archive member filenames vary across newlib/GCC releases (e.g. lib_a- vs libc_a-).
    for obj in sorted(lib_dir.glob("*.o")):
        syms = _member_syms(obj)
        if row["symbol"] in syms and syms[row["symbol"]][1] == row["sha256"]:
            return obj
    raise SystemExit(f"libmatch: {row['symbol']} ({row['sha256'][:12]}) not found in {lib_dir.name}; "
                     f"rerun 'tools/libmatch.py scan'")


def link_objects(img: str, out_dir: Path) -> list[Path]:
    """Matched archive members for `img`, global symbols prefixed, bytes re-checked."""
    rows = load_meta()["images"].get(img, [])
    src = out_dir / "libmatch"
    for lib in sorted({r["lib"] for r in rows}):
        extract(lib, src / lib)
    by_member: dict[tuple[str, Path], list[dict]] = {}
    for r in rows:
        obj = _find_member_for_row(src / r["lib"], r)
        by_member.setdefault((r["lib"], obj), []).append(r)
    objs = []
    for (lib, obj), _mrows in sorted(by_member.items(), key=lambda kv: (kv[0][0], kv[0][1].name)):
        syms = _member_syms(obj)
        ren = src / f"{lib}.{obj.name}.syms"
        ren.write_text("".join(f"{n} {PREFIX}{n}\n" for n in sorted(syms)))
        dst = src / f"{lib}.{obj.name}"
        subprocess.run([OBJCOPY, f"--redefine-syms={ren}", str(obj), str(dst)], check=True)
        objs.append(dst)
    return objs


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("command", choices=("scan", "apply"))
    ap.add_argument("--check", action="store_true", help="report only; exit 1 if anything would change")
    args = ap.parse_args()
    if args.command == "scan":
        meta = scan()
        text = json.dumps(meta, indent=1) + "\n"
        changed = not META.is_file() or META.read_text() != text
        for img, rows in meta["images"].items():
            print(f"[libmatch] {img}: {len(rows)} library routines matched")
        if changed and not args.check:
            META.write_text(text)
        return 1 if args.check and changed else 0
    pending = 0
    meta = load_meta()
    for img, short in IMAGES.items():
        path = REPO / "src" / short / "main.c"
        out, done = bind(path.read_text(), meta["images"].get(img, []))
        pending += len(done)
        print(f"[libmatch] {img}: {len(done)} functions {'pending' if args.check else 'bound'}"
              + "".join(f"\n    {d['name']} @ {d['address']} -> {d['symbol']}" for d in done))
        if done and not args.check:
            path.write_text(out)
    return 1 if args.check and pending else 0


if __name__ == "__main__":
    sys.exit(main())
