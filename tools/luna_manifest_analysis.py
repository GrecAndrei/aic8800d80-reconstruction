#!/usr/bin/env python3
"""Generate luna_batch manifests for corpus-wide function analysis.

Each job carries module context (the segment the function sits in, its
neighbor names, the dominant subsystem prefixes) plus the composed body, so
the model names/analyzes with subsystem awareness instead of in isolation —
the qualitative upgrade over the harness_v17 naming pass.

Output schema requested from the model (parsed downstream):
  {"name": ..., "confidence": "high|medium|low", "docstring": ...,
   "subsystem": ..., "var_renames": {"v1": "...", ...},
   "struct_hints": [{"offset": N, "meaning": "..."}]}
"""
import json
import re
import sys
import argparse

# Stable mega-prefix for prompt caching: this block is byte-identical across
# every job, so after the first call the subscription backend serves it from
# the prompt cache at deep discount instead of billing it fresh each time.
# It must stay large (well past the 1024-token cache-engagement floor) and
# NEVER vary per job — all varying content goes in the user input.
INSTR = (
    "You are a firmware reverse-engineering expert analyzing RivieraWaves-derived "
    "WiFi/BT firmware (AIC8800D80, ARM Thumb, Marvell 88W8800 heritage, Cortex-M4 "
    "with fpv4-sp-d16, images loaded at chip base 0x100000, runtime base 0x120000). "
    "\n\nARCHITECTURAL REFERENCE — the codebase you are analyzing:\n"
    "This is a FullMAC 802.11 + Bluetooth dual-mode firmware descended from the "
    "RivieraWaves (RW) IP stack. Its major subsystems and their vocabularies:\n"
    "- ke (kernel event): the RW cooperative kernel — tasks, messages, timers, "
    "events. Functions manage message queues, event bitfields, timer lists. "
    "Assert strings look like 'ke_state_get(TASK_MM) != MM_IDLE'.\n"
    "- mm (MAC memory manager): pool-based buffer allocation, rx/tx descriptor "
    "rings, 'pbd' packet buffer descriptors, host buffer recovery.\n"
    "- ipc (inter-processor comm): embedded-host message forwarding, 'kmsg' "
    "kernel messages, shared memory windows, doorbell registers.\n"
    "- rf/phy: radio calibration tables, channel config, gain control, AGC, "
    "PLL programming, per-band NV parameters. Heavy MMIO register sequences.\n"
    "- mac/umac/lmac: 802.11 protocol machinery — scan, sme (station management "
    "entity), beacon handling, BA sessions, rate control, vif/sta contexts.\n"
    "- bt/ble: Bluetooth link layer, HCI command/event path, encryption (aes "
    "blocks), connection contexts, advertising/scan state machines.\n"
    "- hal/dma/pmu/gpio: hardware abstraction — clock trees, power management, "
    "DMA channel programming, interrupt masking.\n"
    "- libmisc: libc-ish utilities, softfloat/aeabi helpers, memcmp/printf "
    "family. Format strings are frequent.\n"
    "\nDECOMPILATION ARTIFACTS you will see (do not mistake them for real logic):\n"
    "- v0..vN variables are Hex-Rays register names, volatile casts mark "
    "MMIO/literal access, off_XXXXXX are data-segment symbols, dword_XXXXXX "
    "are materialized globals, goto LABEL_NN are structuring failures, "
    "frame structs are packed stack frames.\n"
    "- a1..a4 are the first four arguments in r0-r3 per the ARM AAPCS.\n"
    "\nNAMING CONVENTIONS for your output names: idiomatic snake_case C, "
    "subsystem-prefixed when confident (ke_msg_alloc, rf_channel_set, "
    "mm_rx_frame_handle). Prefer honest partial names over confident guesses.\n"
    "\nYou will receive a decompiled function with its module context. Reply "
    "with ONLY a JSON object, no markdown fences: {\"name\": concise idiomatic "
    "C name, \"confidence\": \"high\"|\"medium\"|\"low\", \"docstring\": one "
    "precise sentence, \"subsystem\": mac|phy|rf|bt|ble|ipc|mm|ke|hal|libmisc|wlan, "
    "\"var_renames\": {\"v1\": \"meaningful_name\", ...} only for variables whose "
    "role is clear, \"struct_hints\": [{\"offset\": int, \"meaning\": \"...\"}] for "
    "struct fields accessed at numeric offsets. Be conservative: omit unsure keys. "
    "Never invent subsystem certainty the evidence does not support."
    "\n\nHARDWARE MODEL reference for interpreting MMIO access patterns:\n"
    "The firmware runs on a Cortex-M4 with the peripheral space at 0x40000000-"
    "0x41000000. Recurring register blocks: 0x40000000 system control (clock "
    "enables, resets), 0x40200000 baseband/radio control with per-bitfield "
    "channel and gain programming, 0x40320000 RF interface with tick counters "
    "and calibration strobes, 0x40500000 timer block, 0x40600000 DMA engines "
    "with per-channel descriptor rings, 0x40800000 Bluetooth link-layer "
    "control. A sequence of writes to ascending offsets in one block is "
    "register-table initialization; a read-modify-write with a single-bit "
    "mask is a strobe/enable; a poll loop on a status register is hardware "
    "handshaking. Literal pools referenced through off_XXXXXX symbols hold "
    "jump tables, format strings, or calibration tables — infer which from "
    "usage.\n"
    "\nCOMMON FIRMWARE IDIOMS to recognize and name correctly:\n"
    "- variadic tracing: functions pushing r1-r3 and reading them back from "
    "the stack save area are printf-family; name them for their role "
    "(trace_printf, log_line, dbg_printf).\n"
    "- critical sections: a disable-interrupt intrinsic paired with a "
    "re-enable, often wrapped around queue manipulation — the kernel's "
    "atomicity primitive.\n"
    "- timer comparisons: subtraction-based tick comparisons are "
    "wrap-safe elapsed-time checks, not subtraction for its own sake.\n"
    "- linked-list idioms: intrusive doubly-linked lists with the link "
    "member first are the RW co_list pattern used by message queues, "
    "timer lists, and free pools.\n"
    "- state machines: a switch on a small integer state field with "
    "per-case transitions is a task or connection state machine; name it "
    "for the protocol it serves when the evidence supports it.\n"
    "- pool allocators: a bitmap or free-list scan returning an index or "
    "slot pointer is a fixed-pool allocator; zeroing the slot is allocation, "
    "re-linking is free.\n"
    "- byte-scan maxima with a 0x7f mask on 802.11 rate bytes strip the "
    "basic-rate flag bit; similar masks on other byte arrays strip "
    "validity or polarity bits.\n"
    "\nQUALITY BAR: a correct partial answer beats a confident wrong one. "
    "Confidence high means you would bet the name is what the original "
    "author wrote or nearly so; medium means the semantic role is clear "
    "but the exact name is uncertain; low means the function is too "
    "ambiguous — then keep the answer minimal rather than guessing."
)


def extract_functions(text):
    funcs = []
    for m in re.finditer(r"(?m)^// (\S+) @ 0x([0-9a-f]+)\n", text):
        funcs.append((m.group(1), int(m.group(2), 16), m.start()))
    funcs.sort(key=lambda x: x[1])
    out = []
    for i, (name, addr, pos) in enumerate(funcs):
        end = funcs[i + 1][2] if i + 1 < len(funcs) else len(text)
        out.append({"name": name, "addr": addr, "body": text[pos:end].strip()})
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--images", default="fmacfw_h_u02")
    ap.add_argument("--out", default="/tmp/luna_analysis_manifest.jsonl")
    ap.add_argument("--max-body", type=int, default=3000)
    args = ap.parse_args()

    segments = json.load(open("metadata/module_segments.json"))
    jobs = []
    for img in args.images.split(","):
        # post-demonolithize the bodies live in module slices, not main.c
        import glob as _glob
        text = "".join(
            open(f).read() for f in sorted(_glob.glob(f"src/{img}/modules/mod*.c"))
        ) or open(f"src/{img}/main.c").read()
        funcs = extract_functions(text)
        segs = segments.get(img, {}).get("segments", [])
        # map address -> segment index
        def seg_for(addr):
            for si, s in enumerate(segs):
                if int(s["start"], 16) <= addr <= int(s["end"], 16):
                    return si, s
            return None, None
        for f in funcs:
            si, seg = seg_for(f["addr"])
            neighbors = []
            prefs = {}
            if seg:
                idx = seg["names"].index(f["name"]) if f["name"] in seg["names"] else 0
                neighbors = [n for n in seg["names"][max(0, idx - 3):idx + 4] if n != f["name"]][:6]
                prefs = seg.get("prefixes", {})
            body = f["body"]
            if len(body) > args.max_body:
                body = body[:args.max_body] + "\n// [truncated]"
            prompt = (
                f"Module context: this function sits in a link-order cluster with neighbors "
                f"{', '.join(neighbors) if neighbors else '(none)'}; dominant subsystem "
                f"prefixes in the cluster: {json.dumps(prefs)}.\n"
                f"Current machine-generated name: {f['name']} @ 0x{f['addr']:x}\n\n"
                f"```c\n{body}\n```"
            )
            jobs.append({
                "key": f"{f['name']}__{img}",
                "instructions": INSTR,
                "prompt": prompt,
                "meta": {"fn": f["name"], "img": img, "addr": hex(f["addr"]), "seg": si},
            })
    with open(args.out, "w") as fh:
        for j in jobs:
            fh.write(json.dumps(j) + "\n")
    print(f"wrote {len(jobs)} jobs to {args.out}")


if __name__ == "__main__":
    main()
