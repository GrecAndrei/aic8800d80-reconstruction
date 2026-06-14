# AIC8800D80 Firmware Reconstruction Project

## Goal
Reconstruct human-readable C source from AIC8800D80 WiFi/BT firmware binaries
using a sequence of progressively better pipelines (v15 → v19).

## Constraints & Preferences
- **THINK IN TAGS, NOT BASH COMMANDS**: never use bash as scratch
- **LLM cost is NOT a constraint** — be aggressive, push through
- **Address-safety rule is absolute**: LLM may NOT compute any address in its head
- **LLM is NEVER a C author** — only tool user / naming oracle
- **Don't artificially limit**: no max_tokens cap, no iteration cap
- **O(n) is mandatory**: never O(n*m) text splices in loops on multi-MB files
- **Long-running commands detached**: `setsid nohup`, never `wait` on nohup'd process
- **No synthetic/template bodies**; demand real semantic fidelity
- **Bugs are blocking**: fix integration bugs first
- Regular commits on meaningful source changes
- Do not modify generated files manually
- **Dual-track (A + B)**: hardware test path + cloud release path
- **"take this to the end and dont stop until reached"**
- **Use Hex-Rays decompiler** for v19 human-readable C

## Progress

### v15 — Synthesis baseline (truth lane: 25/25 PASS)
Truth lane verifies the synthesized C is semantically equivalent to original.

### v17 — LLM tool-use pipeline
- 16 deterministic tools, oracle.py (LLM with function calling)
- naming_batch.py: 5 fns/s, 15,151 names, 3,475 renames
- 8/25 truth-lane, 75 compile-oracle reports, 10K+ dataset records

### v18 — Faithful inline-asm (1.1MB tarball)
- 18,841 functions with original bytes embedded as `.byte 0xXX`
- 89% byte-match confirmed via compile-oracle
- v18 is **byte-faithful** but **unreadable** to humans

### v19 — Hex-Rays decompilation (RELEASE)
- **4,675 of 4,723 functions decompiled (98.9%)**
- **1,256 functions have LLM-applied names**
- **25,815 MMIO register addresses named automatically**
- 22MB pseudo-C across 4 binaries
- **22MB → 4.7MB tarball** with 5,945 per-function .c files
- README + ORACLE_RESULTS + named samples
- ~30s per binary decompile time
- 4.7MB tarball at `artifacts/releases/aic8800d80-rebuild-v1-v19.tar.gz`

## Key Decisions
- v17 = LLM tool-use, replaces v16's hallucinating C generation
- v18 = byte-faithful layer (inline-asm), 0% hallucination
- v19 = human-readable layer (Hex-Rays), complements v18
- Strong verifier is the gate (v15)
- v14 BASE = 0x1200000; chip = v14 - 0x1100000
- Chip runtime addr = 0x100000 + file_offset
- r2 thumb disasm: `r2 -q -2 -c "e asm.arch=arm; e asm.bits=16; pd N @ ADDR"`
- Address-safety: validator collects addresses from tool RESULTS + INPUTS + prompt
- IDA ELF wrapper trick: load as 32-bit ARM Thumb at 0x100000
- IDA needs extended LOAD (sparse) to 0x200000 to enable BSS naming
- IDA needs `create_data()` before `set_name()` for BSS/data addresses
- IDA MMIO register naming: add_segm(0, 0x40000000, 0x60000000, "MMIO", "DATA")
- LLMs: 6 keys round-robin, `https://api.tokenrouter.com/v1`, model `MiniMax-M3`

## Critical Context
- 4 firmware binaries, ~340KB each, load at 0x100000
- AIC8800D80 is a Marvell 88W8800-derived WiFi/BT chip
- IDA Pro 9.3 at `/home/grec-alexander/ida-pro-9.3/idat`
- v18 7,642 functions for fmacfw_u02 (inline-asm)
- v19 1,273 functions for fmacfw_u02 (decompiled)
- Different scopes: v18 covers LLM-named, v19 covers IDA-discovered
- Total decompiled: 4,675/4,723 = 98.9% across 4 binaries
