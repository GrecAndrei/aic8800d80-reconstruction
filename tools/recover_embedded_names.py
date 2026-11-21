#!/usr/bin/env python3
"""Index identifier strings whose hardware addresses occur as aligned words.

The observations are byte matches, not instruction references or function names.
"""
import argparse
import hashlib
import json
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
HARDWARE_BASE = 0x120000
IMAGES = (
    "fmacfw_8800d80_u02",
    "fmacfw_8800d80_h_u02",
    "fmacfwbt_8800d80_u02",
    "lmacfw_rf_8800d80_u02",
)
_STRING_RE = re.compile(rb"[\x20-\x7e]{5,}")
_IDENT_RE = re.compile(rb"[a-z][a-z0-9]*(?:_[a-z0-9]+)+")


def identifier_strings(data):
    """Yield (file offset, text) for complete, NUL-terminated printable runs."""
    for m in _STRING_RE.finditer(data):
        if data[m.end():m.end() + 1] == b"\0" and _IDENT_RE.fullmatch(m.group()):
            yield m.start(), m.group().decode("ascii")


def image_evidence(data):
    strings = dict(identifier_strings(data))
    matches = defaultdict(list)
    aligned = memoryview(data)[:len(data) - len(data) % 4]
    for index, (word,) in enumerate(struct.iter_unpack("<I", aligned)):
        string_offset = word - HARDWARE_BASE
        if string_offset in strings:
            matches[string_offset].append(hex(index * 4))
    return {
        "sha256": hashlib.sha256(data).hexdigest(),
        "identifiers": [
            {"string_offset": hex(offset), "text": text,
             "word_offsets": matches[offset]}
            for offset, text in strings.items() if offset in matches
        ],
    }


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--out", type=Path, default=REPO / "metadata/embedded_identifiers.json")
    ap.add_argument("--firmware-dir", type=Path, default=REPO / "inputs/firmware")
    args = ap.parse_args()

    result = {"schema_version": 1, "hardware_base": hex(HARDWARE_BASE), "images": {}}
    missing = []
    for blob in IMAGES:
        bin_path = args.firmware_dir / f"{blob}.bin"
        if not bin_path.is_file():
            missing.append(bin_path.name)
            continue
        evidence = image_evidence(bin_path.read_bytes())
        result["images"][f"{blob}_bin"] = evidence
        print(f"{blob}: {len(evidence['identifiers'])} identifier strings with "
              "matching words", file=sys.stderr)
    if missing:
        print("missing firmware: " + ", ".join(missing)
              + " (run tools/fetch_firmware.sh)", file=sys.stderr)
        return 1
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(result, indent=1) + "\n", encoding="utf-8")
    print(f"wrote {args.out}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main())
