#!/usr/bin/env python3
"""Apply luna renames to noise-named functions — the pure-upside slice of the
analysis batch.

Only functions whose CURRENT name is compositional noise are eligible:
  sub_<hex>, test_NN, *_global_op_*, jump_*, nullsub_*, loc_*, unk_*
For those, any high-confidence luna name is strictly better — there is no
correct existing name to contradict (measured counterexamples like
ble_get_rssi -> rx_dma_advance_cursor show why confidence in replacing a
real name is NOT justified).

Safety properties:
  - address-keyed: renames follow the function's binary address, robust to
    regeneration order
  - collision-aware: a candidate name already taken in the image is skipped
  - high-confidence only
  - runs as a post-compose chain rule; deterministic given the batch cache

Emits metadata/luna_renames.json mapping per image for audit.

Usage: python3 tools/luna_rename_apply.py [--check]
"""
import json
import glob
import os
import re
import sys

IMAGES = ("fmacfw_h_u02", "fmacfw_u02", "fmacfwbt_u02", "lmacfw_rf_u02")

NOISE = re.compile(
    r"^(sub_[0-9A-Fa-f]+|test_\d+|.*_global_op_0x[0-9a-f]+|jump_.*|nullsub_.*|loc_[0-9A-Fa-f]+|unk_.*|.*_test_15)$"
)


def load_batch():
    out = {}
    for f in glob.glob("metadata/luna_analysis/*.json"):
        try:
            o = json.load(open(f))
            d = json.loads(o["text"])
            out[(o["img"], o["fn"])] = d
        except Exception:
            continue
    return out


def module_files(img):
    # the umbrella main.c carries the forward declarations — a rename that
    # does not reach it leaves the prototype under the noise name while the
    # definition and call sites move, breaking callers with implicit-
    # declaration errors (dump_tx_queue_state was the first measured case)
    return sorted(glob.glob(f"src/{img}/modules/mod*.c")) + [f"src/{img}/main.c"]


def apply_image(img, batch, check=False):
    """Rename noise-named function definitions and their call sites across
    the image's module slices. Returns (applied, skipped, collisions)."""
    files = module_files(img)
    if not files:
        return 0, 0, 0, {}
    texts = {f: open(f).read() for f in files}
    all_text = "".join(texts.values())

    # collect current noise names with their addresses from module slices
    defs = {}  # name -> (file, addr)
    for f, text in texts.items():
        for m in re.finditer(r"(?m)^// (\S+) @ 0x([0-9a-f]+)\n[\w\s\*]+?\b(\w+)\s*\(", text):
            disp = m.group(1)
            addr = int(m.group(2), 16)
            # the display name in the comment is the canonical current name
            if NOISE.match(disp):
                defs[disp] = (f, addr)

    taken = set()
    for f, text in texts.items():
        for m in re.finditer(r"(?m)^// (\S+) @", text):
            taken.add(m.group(1))

    renames = {}
    collisions = 0
    skipped = 0
    assigned = set()  # names taken by this pass itself — two noise-named
    # trivial functions can draw the same obvious candidate (noop_success
    # collided across modules this way)
    for disp, (f, addr) in sorted(defs.items()):
        d = batch.get((img, disp))
        if not d:
            skipped += 1
            continue
        new = d.get("name", "")
        conf = d.get("confidence", "")
        if conf != "high" or not new or new == disp or not re.fullmatch(r"[a-z][a-z0-9_]{2,40}", new):
            skipped += 1
            continue
        if (new in taken and new != disp) or new in assigned:
            collisions += 1
            continue
        renames[disp] = new
        assigned.add(new)

    if check:
        return len(renames), skipped, collisions, {}

    # apply: definition line comment + definition identifier + call sites.
    # Word-boundary exact-token replacement is safe because C identifiers
    # cannot partially match inside other identifiers with \b on both ends.
    audit = {}
    for old, new in renames.items():
        for f in files:
            t = texts[f]
            if re.search(rf"\b{re.escape(old)}\b", t):
                texts[f] = re.sub(rf"\b{re.escape(old)}\b", new, t)
        audit[old] = new

    if renames:
        for f, t in texts.items():
            open(f, "w").write(t)
    return len(renames), skipped, collisions, audit


def main():
    check = "--check" in sys.argv
    batch = load_batch()
    print(f"{len(batch)} luna analyses loaded")
    total = 0
    audit_all = {}
    for img in IMAGES:
        n, skipped, collisions, audit = apply_image(img, batch, check=check)
        total += n
        audit_all[img] = audit
        print(f"{img}: {n} renames applicable, {skipped} skipped, {collisions} collisions")
    if check:
        sys.exit(1 if total else 0)
    json.dump(audit_all, open("metadata/luna_renames.json", "w"), indent=1)
    print(f"applied {total} renames; audit in metadata/luna_renames.json")


if __name__ == "__main__":
    main()
