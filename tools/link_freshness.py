#!/usr/bin/env python3
"""link_freshness.py — content-hash provenance for runtime-linked ELFs.

A runtime-linked reconstruction ELF derives from a chain of inputs:

  src/<image>/main.c  -(make -C src check: src/Makefile flags)->  src/<img>.o
  src/<img>.o + artifacts (tools/full_link.py, its CFLAGS, --text-base)
      -> build/full_link_run/<img>/<img>.full.elf

mtime comparisons cannot prove that chain: `make reproduce` rewrites main.c
even when the compose fixed point leaves the bytes unchanged, so any
mtime-based guard both false-fires on a healthy tree and can miss a genuinely
stale object. full_link.py therefore writes <elf>.stamp.json next to the ELF
recording the sha256 of every input it does not control plus its own inputs,
and linked_recon_run.check_elf_freshness recomputes the fingerprint and
refuses the ELF when it differs.
"""
import hashlib
import json
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent

SHORT = {"fmacfw_8800d80_h_u02": "fmacfw_h_u02", "fmacfw_8800d80_u02": "fmacfw_u02",
         "fmacfwbt_8800d80_u02": "fmacfwbt_u02", "lmacfw_rf_8800d80_u02": "lmacfw_rf_u02"}

STAMP_SUFFIX = ".stamp.json"


def src_fingerprint(image: str) -> str:
    """sha256 over every input of the link chain that must be current.

    Covers the composed source, the forced-include headers, the Makefile that
    compiles the object, the object itself (catches a stale object built from
    older sources) and full_link.py (catches flag/scaffolding changes).
    """
    short = SHORT.get(image, image)
    h = hashlib.sha256()
    inputs = [REPO / "src" / short / "main.c", REPO / "src" / "Makefile",
              REPO / "src" / f"{image}.o", REPO / "tools" / "full_link.py"]
    inputs += sorted((REPO / "src" / "include").glob("*.h"))
    for p in inputs:
        h.update(p.name.encode())
        if p.is_file():
            h.update(p.read_bytes())
        else:
            h.update(b"<missing>")
    return h.hexdigest()


def stamp_path(elf: Path) -> Path:
    return elf.with_suffix(elf.suffix + STAMP_SUFFIX) if elf.suffix else Path(str(elf) + STAMP_SUFFIX)


def write_stamp(elf: Path, image: str, text_base: int) -> None:
    stamp = {
        "image": image,
        "text_base": hex(text_base),
        "src_fingerprint": src_fingerprint(image),
    }
    stamp_path(elf).write_text(json.dumps(stamp, indent=2) + "\n")


def read_stamp(elf: Path) -> dict | None:
    p = stamp_path(elf)
    if not p.is_file():
        return None
    try:
        return json.loads(p.read_text())
    except (json.JSONDecodeError, OSError):
        return None
