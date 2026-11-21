#!/usr/bin/env python3
"""Recover real vendor function names embedded in the firmware images.

The firmware's assert/debug prints carry function names as C strings. Each
string is referenced from the literal pool of the function that uses it, and
the pool word holds the string's HARDWARE address (file offset + 0x120000),
not the analysis-space address (file offset + 0x100000) that the naming
tools look up -- which is why the LLM naming pass never saw them.

Deterministic, no LLM, no IDA: needs only inputs/firmware/*.bin (run
tools/fetch_firmware.sh) and the function starts from src/<image>/functions/.

A name is accepted only when it is unambiguous both ways: the function
references exactly one identifier-like string, and that string is referenced
by exactly one function. Everything else is listed under "ambiguous".

Usage:
    python3 tools/recover_embedded_names.py [--out metadata/embedded_names.json]
"""
import argparse
import bisect
import json
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
ANALYSIS_BASE = 0x100000
HARDWARE_BASE = 0x120000
IMAGES = {
    "fmacfw_u02": "fmacfw_8800d80_u02",
    "fmacfw_h_u02": "fmacfw_8800d80_h_u02",
    "fmacfwbt_u02": "fmacfwbt_8800d80_u02",
    "lmacfw_rf_u02": "lmacfw_rf_8800d80_u02",
}
_STRING_RE = re.compile(rb"[\x20-\x7e]{5,}")
_IDENT_RE = re.compile(rb"[a-z][a-z0-9]*(?:_[a-z0-9]+)+")
_FILE_RE = re.compile(r"^([0-9a-fA-F]+)_(.+)\.c$")


def identifier_strings(data):
    """Return [(file_offset, name)] for NUL-terminated identifier-like strings."""
    out = []
    for m in _STRING_RE.finditer(data):
        if not _IDENT_RE.fullmatch(m.group()):
            continue
        end = m.end()
        if end >= len(data) or data[end] != 0:
            continue
        out.append((m.start(), m.group().decode("ascii")))
    return out


def recover(data, starts, bases=(HARDWARE_BASE, ANALYSIS_BASE)):
    """Map function start -> embedded name.

    data:   raw image bytes
    starts: sorted analysis-space function start addresses
    Returns (accepted, ambiguous): accepted is {start: name}; ambiguous is
    {start: sorted names} for functions that could not be resolved one-to-one.
    """
    fn_names = defaultdict(set)
    name_fns = defaultdict(set)
    for off, name in identifier_strings(data):
        for base in bases:
            pat = struct.pack("<I", base + off)
            i = data.find(pat)
            while i >= 0:
                if i % 4 == 0:
                    j = bisect.bisect_right(starts, ANALYSIS_BASE + i) - 1
                    if j >= 0:
                        fn_names[starts[j]].add(name)
                        name_fns[name].add(starts[j])
                i = data.find(pat, i + 1)
    accepted, ambiguous = {}, {}
    for start, names in fn_names.items():
        if len(names) == 1 and len(name_fns[next(iter(names))]) == 1:
            accepted[start] = next(iter(names))
        else:
            ambiguous[start] = sorted(names)
    return accepted, ambiguous


def function_starts(image_dir):
    starts = set()
    for p in (image_dir / "functions").iterdir():
        m = _FILE_RE.match(p.name)
        if m:
            a = int(m.group(1), 16)
            if a >= ANALYSIS_BASE:
                starts.add(a)
    return sorted(starts)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--out", default=str(REPO / "metadata/embedded_names.json"))
    ap.add_argument("--firmware-dir", default=str(REPO / "inputs/firmware"))
    ap.add_argument("--src-dir", default=str(REPO / "src"))
    args = ap.parse_args()

    result = {"hardware_base": hex(HARDWARE_BASE), "images": {}}
    missing = []
    for src_name, blob in IMAGES.items():
        bin_path = Path(args.firmware_dir) / f"{blob}.bin"
        if not bin_path.exists():
            missing.append(bin_path.name)
            continue
        starts = function_starts(Path(args.src_dir) / src_name)
        accepted, ambiguous = recover(bin_path.read_bytes(), starts)
        result["images"][f"{blob}_bin"] = {
            "functions": len(starts),
            "recovered": len(accepted),
            "names": {f"0x{a:x}": n for a, n in sorted(accepted.items())},
            "ambiguous": {f"0x{a:x}": n for a, n in sorted(ambiguous.items())},
        }
        print(f"{blob}: {len(accepted)}/{len(starts)} functions named, "
              f"{len(ambiguous)} ambiguous", file=sys.stderr)
    if missing:
        print("missing firmware: " + ", ".join(missing)
              + " (run tools/fetch_firmware.sh)", file=sys.stderr)
        return 1
    out = Path(args.out)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(result, indent=1, sort_keys=True) + "\n")
    print(f"wrote {out}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main())
