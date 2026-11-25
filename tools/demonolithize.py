#!/usr/bin/env python3
"""De-monolithize composed main.c into per-module translation-unit slices.

The composed monolith is reorganized into the recovered repo structure:
  src/<image>/main.c            umbrella — preamble (includes, data segment,
                                forward declarations) + #include of each
                                module slice in address order
  src/<image>/modules/modNNN.c  contiguous function bodies of one inferred
                                original file (metadata/module_refined.json)

Because the umbrella #includes the slices in order, the preprocessor output
is byte-identical to the monolith — compilation semantics are exactly
preserved (statics, forward declarations, and data symbols remain visible
across module boundaries exactly as before). The split is deterministic
given the pinned segmentation metadata, so the post-compose chain reproduces
it byte-for-byte (make -C src reproduce fixed-point).

Runs as a post-compose chain rule. Idempotent: if main.c is already an
umbrella it is left untouched.
"""
import json
import os
import re
import sys

IMAGES = ("fmacfw_h_u02", "fmacfw_u02", "fmacfwbt_u02", "lmacfw_rf_u02")


def split_image(img, meta):
    path = f"src/{img}/main.c"
    text = open(path).read()
    if '#include "modules/' in text:
        return img, 0, "already split"

    mods = meta[img]["modules"]
    # locate all function units in order
    funcs = []
    for m in re.finditer(r"(?m)^// (\S+) @ 0x([0-9a-f]+)\n", text):
        funcs.append((m.group(1), int(m.group(2), 16), m.start()))
    funcs.sort(key=lambda x: x[1])
    if not funcs:
        return img, 0, "no functions"

    # map function address -> text span
    spans = {}
    for i, (name, addr, pos) in enumerate(funcs):
        end = funcs[i + 1][2] if i + 1 < len(funcs) else len(text)
        spans[addr] = (pos, end)

    first_pos = funcs[0][2]
    preamble = text[:first_pos]

    # group consecutive functions by module membership (address-ordered)
    addr_to_mod = {}
    for mi, mod in enumerate(mods):
        for name in mod["names"]:
            pass  # names unreliable across regenerations; use spans by address
        a0, a1 = int(mod["start"], 16), int(mod["end"], 16)
        for addr in spans:
            if a0 <= addr <= a1:
                addr_to_mod[addr] = mi

    labels = meta[img].get("labels", {})

    outdir = f"src/{img}/modules"
    os.makedirs(outdir, exist_ok=True)
    # remove stale slices from prior runs (renamed labels or shifted
    # boundaries) — leaving them duplicates every symbol at compile time
    for stale in os.listdir(outdir):
        if stale.startswith("mod") and stale.endswith(".c"):
            os.unlink(os.path.join(outdir, stale))
    includes = []
    written = 0
    cur_mod = None
    buf = []
    def flush(mi):
        nonlocal written, buf
        if not buf:
            return
        label = labels.get(str(mi), "")
        fn = f"mod{mi:03d}_{label}.c" if label else f"mod{mi:03d}.c"
        with open(os.path.join(outdir, fn), "w") as f:
            f.write("".join(buf))
        includes.append(fn)
        written += 1
        buf = []

    tail_after_last = None
    last_end = None
    for name, addr, pos in funcs:
        mi = addr_to_mod.get(addr)
        if mi is None:
            mi = cur_mod if cur_mod is not None else 0
        if cur_mod is None:
            cur_mod = mi
        if mi != cur_mod:
            flush(cur_mod)
            cur_mod = mi
        s, e = spans[addr]
        buf.append(text[s:e])
        last_end = e
    flush(cur_mod)

    # anything after the last function span (shouldn't happen, but preserve)
    if last_end is not None and last_end < len(text):
        trailer = text[last_end:]
        if trailer.strip():
            # append to the last module file
            with open(os.path.join(outdir, includes[-1]), "a") as f:
                f.write(trailer)

    umbrella = preamble + "\n/* module slices in link order — see metadata/module_refined.json */\n"
    for fn in includes:
        umbrella += f'#include "modules/{fn}"\n'
    open(path, "w").write(umbrella)
    return img, written, "split"


def main():
    if "--check" in sys.argv:
        sys.argv.remove("--check")
        pending = []
        for img in (sys.argv[1:] or list(IMAGES)):
            try:
                text = open(f"src/{img}/main.c").read()
                if '#include "modules/' not in text:
                    pending.append(img)
            except FileNotFoundError:
                pass
        if pending:
            print(f"demonolithize pending: {', '.join(pending)}", file=sys.stderr)
            sys.exit(1)
        sys.exit(0)
    meta = json.load(open("metadata/module_refined.json"))
    images = sys.argv[1:] or list(IMAGES)
    for img in images:
        if img not in meta:
            print(f"{img}: no segmentation metadata — skipped")
            continue
        name, n, status = split_image(img, meta)
        print(f"{name}: {status} ({n} module files)")


if __name__ == "__main__":
    main()
