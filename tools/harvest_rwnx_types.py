#!/usr/bin/env python3
"""Harvest struct/enum/message-type definitions from the rwnx host-driver
headers into a machine-usable type database.

The rwnx FullMAC host driver shares its IPC/LMAC protocol headers with the
on-chip firmware build: the message structs in lmac_msg.h, the shared IPC
layouts in ipc_shared.h and the hardware descriptor ring types in hal_desc.h
are wire-visible types identical on both sides. Harvested fields give the
reconstruction real names for what is otherwise offset arithmetic.

Output: metadata/rwnx_types.json — {struct_name: {size, fields:[{name,type,
offset}]}}, offsets computed for flat fixed-size C types only.
"""
import json
import re
import sys
import glob

CTYPE_SIZE = {
    "uint8_t": 1, "u8": 1, "char": 1, "int8_t": 1, "bool": 1, "u8_t": 1,
    "uint16_t": 2, "u16": 2, "int16_t": 2, "u16_t": 2, "short": 2,
    "uint32_t": 4, "u32": 4, "int32_t": 4, "u32_t": 4, "int": 4,
    "uint64_t": 8, "u64": 8, "int64_t": 8,
    "dma_addr_t": 4, "uintptr_t": 4,
}

HEADERS = glob.glob("/tmp/aic8800-dkms/aic8800_fdrv/*.h")


def strip_comments(text):
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    return re.sub(r"//[^\n]*", "", text)


def parse_structs(path):
    text = strip_comments(open(path, errors="replace").read())
    out = {}
    for m in re.finditer(r"struct\s+([a-zA-Z_0-9]+)\s*\{(.*?)\}\s*(?:__attribute__\s*\(\(.*?\)\))?\s*;", text, re.S):
        name, body = m.group(1), m.group(2)
        fields = []
        offset = 0
        exact = True
        for fm in re.finditer(r"([a-zA-Z_0-9\s\*]+?)\s+([a-zA-Z_0-9]+)\s*(?:\[(\d+)\])?\s*;", body):
            ftype = " ".join(fm.group(1).split())
            fname = fm.group(2)
            count = int(fm.group(3)) if fm.group(3) else 1
            base = CTYPE_SIZE.get(ftype)
            if base is None:
                nested = re.match(r"struct\s+([a-zA-Z_0-9]+)$", ftype)
                if nested:
                    base = -1  # resolved in pass 2
                else:
                    exact = False
                    base = 4 if "*" in ftype else 0
            fields.append({
                "name": fname, "type": ftype, "offset": offset,
                "count": count, "size": base,
            })
            if base > 0:
                offset += base * count
            else:
                exact = False
        out[name] = {"size": offset if exact else None,
                     "exact": exact, "fields": fields,
                     "source": path.split("/")[-1]}
    return out


def main():
    db = {}
    for h in sorted(HEADERS):
        db.update(parse_structs(h))
    # pass 2: resolve nested struct sizes where possible
    for name, s in db.items():
        for f in s["fields"]:
            if f["size"] == -1:
                nested = re.match(r"struct\s+([a-zA-Z_0-9]+)$", f["type"])
                if nested and nested.group(1) in db and db[nested.group(1)]["size"]:
                    f["size"] = db[nested.group(1)]["size"]
    json.dump(db, open("metadata/rwnx_types.json", "w"), indent=1)
    sized = sum(1 for s in db.values() if s["size"])
    print(f"harvested {len(db)} structs from {len(HEADERS)} headers; {sized} with exact sizes")
    big = sorted(((n, s["size"]) for n, s in db.items() if s["size"] and s["size"] > 200),
                 key=lambda x: -x[1])[:8]
    print("largest exact-size structs:", big)


if __name__ == "__main__":
    main()
