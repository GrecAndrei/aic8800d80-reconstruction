# AGENTS.md — Quick Reference for AI Agents

> **Historical workflow guide:** `docs/WORKFLOW_LEGACY.md` (formerly
> `agents.md`) covers the older `fwextract`/smoke-loop/`recon_cycle` era
> (v15-v18). Use this file for the v15-v25 pipeline state.

This file gives a fast overview of the AIC8800D80 firmware reconstruction
project so a fresh agent can orient quickly.

## Project goal
Reconstruct human-readable C source from AIC8800D80 WiFi/BT firmware
binaries using a sequence of progressively better pipelines (v15 → v19).

## Project status (2026-06-30)

Five release layers, each serves a different verification need:

| Layer | Output | Compiles? | Human-readable? | Functions |
|-------|--------|-----------|-----------------|-----------|
| **v15** | Synthesized C (curated 356 funcs) | ✅ | ✅ | 356 |
| **v17** | LLM-named C (4,002 funcs in release) | ✅ | ✅ | 4,002 |
| **v18** | Inline-asm byte-faithful (18,841 funcs) | ✅ | ❌ | 18,841 |
| **v19** | Hex-Rays decompilation (4,675 funcs) | ❌ (pseudo) | ✅ | 4,675 |
| **v25** | Per-function metadata via `fwstruct` | n/a | n/a | 5,945 analyzed |

**Latest human-readable C: v19** — 4,675 functions, 1,256 LLM-named,
25,815 MMIO register names.

**Latest analysis layer: v25** — unified Go tool (`bin/fwstruct`)
that parses v19's Hex-Rays C and produces per-function callees,
access patterns, numeric literals, struct candidates, boot init
path, and cross-binary diffs. Supersedes the v20-v24 Python harnesses.

## Hard rules (do not violate)

1. **THINK IN TAGS, NOT BASH COMMANDS**: never use bash as scratch.
2. **LLM cost is NOT a constraint** — be aggressive, push through.
3. **Address-safety rule is absolute**: LLM may NOT compute any address,
   offset, pointer, or size in its head. Provide tools.
4. **LLM is NEVER a C author** — only tool user / naming oracle. All C
   is mechanically generated (v17+) or decompiled (v19).
5. **Don't artificially limit**: no max_tokens cap, no iteration cap.
6. **O(n) is mandatory**: never O(n*m) text splices in loops on
   multi-MB files.
7. **Long-running commands detached**: `setsid nohup`, never `wait` on
   nohup'd process. Bash tool has 120s timeout.
8. **No synthetic/template bodies**; demand real semantic fidelity.
9. **Bugs are blocking**: fix integration bugs first, then continue.
10. **Regular commits** on meaningful source changes.
11. **Do not modify generated files manually**; fixes via real rebuild.
12. **Dual-track (A + B)**: hardware test path + cloud release path.
13. **"take this to the end and dont stop until reached"** — push through.
14. **Use Hex-Rays decompiler** (`$IDAT (or default $HOME/ida-pro-9.3/idat)`)
    for v19 human-readable C.
15. **Use `bin/fwstruct`** for v25 per-function metadata. Build with
    `go build -o bin/fwstruct ./cmd/fwstruct`.

## Where to start

- For pipeline architecture: see `PIPELINE.md`
- For v19 (latest): see `harness_v19/README.md`
- For v18 (byte-faithful): see `harness_v17/disasm_to_asm.py`
- For v17 (LLM tool-use): see `harness_v17/oracle.py`
- For v15 (synthesis): see `harness_v15/`

## Address conversion cheat sheet

```
v14 BASE           = 0x1200000
chip runtime BASE  = 0x100000
file_offset = 0x100000 → chip addr 0x100000
chip addr = v14 addr - 0x1100000
```

## IDA Pro setup for AIC8800D80

The firmware loads as ARM Thumb at `0x100000`. To get IDA to recognize it:

1. Wrap the raw `.bin` as a minimal ARM ELF (one LOAD segment at 0x100000)
   - See `harness_v19/scripts/make_elf.py`
2. Load via `idat -A -B -L<log> -S<setup_script> -o<idb> <elf>`
3. Setup script must:
   - Set LOAD perm to RWX (default is RX, blocks data symbol naming)
   - Extend LOAD to 0x200000 with SEGMOD_SPARSE (BSS coverage)
   - Add MMIO phantom segment at 0x40000000-0x60000000
4. Apply LLM names via `ida_name.set_name(addr, name, ida_name.SN_FORCE)`
5. BSS addresses need `ida_bytes.create_data()` BEFORE `set_name()`
6. Decompile with `idaapi.decompile(ea)`

## r2 thumb disasm command

```bash
r2 -q -2 -c "e asm.arch=arm; e asm.bits=16; pd N @ ADDR" inputs/firmware/<file>.bin
```

DOES NOT work: `-a arm -b 16` (byte-granular), `-a thumb` (wrong at fn start),
`-m 0x100000` (offsets wrong on raw .bin).

## LLMs

- 6 keys round-robin
- `https://api.tokenrouter.com/v1`
- Model: `MiniMax-M3`
- 1M context, 120s timeout

## LLM tool-use (v17)

- 16 deterministic tools
- Address-safety validator collects addrs from RESULTS + INPUTS + prompt
- Strips leading zeros
- Exempts sentinels
- LLM may rename but may not invent addresses

## AIC8800D80 firmware specs

- 4 binaries, ~340KB each
- Loads at 0x100000
- Marvell 88W8800-derived WiFi/BT chip
- 1,285 functions per image (fmacfw_h, fmacfw_u02, fmacfwbt)
- 866 functions (lmacfw_rf)
- Total: 4,723 functions across 4 images
- IDB size: 2.1 GB each (with MMIO segment)

## MMIO register pages

- 25,815 unique MMIO addresses
- 1,042 distinct 64KB pages
- Range: 0x40000000 - 0x60000000
- Top pages by address count: 0x4620 (569), 0x4604 (317), 0x4628 (260), ...

## IDA quirks discovered

- `idc.get_db_name` doesn't exist in 9.x
- Use `idaapi.get_input_file_path()` to get loaded file
- `idc.SN_FORCE` is in `ida_name.SN_FORCE`
- `set_segm_attributes` is gone — use `seg.perm = ...` directly
- `getnseg(0)` returns `segment_t` whose `perm` field is assignable
- Hex-Rays output is **cached** — changes to symbols require
  re-decompile or use `idaapi.decompile(ea, flags=idaapi.DECOMP_NO_CACHE)`
- Hex-Rays uses MSVC types: `__int64`, `__int16`, `_DWORD`, `_BYTE`, etc.
- Hex-Rays uses `_R0`, `_R1`, etc. for register writes
- Hex-Rays uses `_CF`, `_ZF`, etc. for condition flags

## Disk space

- /tmp is 7.5GB tmpfs — keep IDB usage low
- IDBs are 2.1GB each (due to MMIO phantom segment)
- Use `harness_v19/idb/` for IDB storage; not in git
- Tarball releases are < 10MB; safe for git

## Critical gitignore entries

- `*.i64` (IDA databases)
- `*.id0`, `*.id1`, `*.id2`, `*.nam`, `*.til` (IDA components)
- `*.bin` (raw firmware)
- `*.gz`, `*.tar.gz` (release tarballs, added with -f)
- `harness_v19/decompiled/`, `harness_v19/idb/`, `harness_v19/log/`
- `harness_v19/boundaries.json`, `llm_names.json`, etc. (regen'd)
- `harness_v16/out/` (44K review files, 177MB)
- `extraction_out/`, `analysis/`
