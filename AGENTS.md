# AGENTS.md — Quick Reference for AI Agents

## Project goal
Reconstruct human-readable C source from the AIC8800D80 WiFi/BT firmware
binaries (4 × ~340KB ARM Thumb images, Marvell 88W8800-derived, loaded at
0x100000), with byte-level ground truth always anchored to the binaries.

## Current series: Unified (replaces v15–v26)

The old "v-series" (v15, v17, v18, v19, v20–v25, v26) is legacy. Do not
build new layers on it. The unified series is ONE pipeline:

```
inputs/firmware/*.bin
   │  [deterministic] fwstruct extract + Hex-Rays decompile (v19 machinery)
   ▼
decompiled C per function
   │  [deterministic] fwstruct datasgen  → data segment materialized
   │  [deterministic] fwstruct compose   → src/<image>/main.c (real bodies only)
   │  [LLM oracle]    naming_src.py      → names for sub_* functions
   ▼
src/  (single output: per-function files + composed main.c + headers)
   │  [deterministic] emulation verify   → per-function behavioral gate
   ▼
release tarball
```

- **One tool**: `fwstruct` (Go, `cmd/fwstruct/`, build: `go build -o bin/fwstruct ./cmd/fwstruct`)
- **One output**: `src/` — 5,623 per-function files under `src/<image>/functions/`,
  composed `src/<image>/main.c`, shared headers in `src/include/`
- **One naming dataset**: `harness_v17/names/{fn}__{img}.json` (shared cache,
  skip-if-exists; legacy harness_v17 code is reused as a library, not extended)
- Legacy harness dirs (harness_v15 … v26) stay in the tree as frozen
  references; their outputs remain valid evidence.

## Current status (2026-08-01)

- **Reset entry corrected (2026-11-24)**: the real IVT entry `start`
  at analysis `0x1001a8` / hardware `0x1201a8` is reconstructed in all 4
  images from hardware-base Hex-Rays decompilation
  (`harness_v19/scripts/ida_decompile_reset_entry.py`, mechanical conversion:
  `tools/rebuild_boot_entry.py`). Compose now excludes the old data-as-code
  artifact at `0x100100` (file 0x100-0x1a7 is header/padding, not code).
  Targeted boot verification at 500k instructions: every reconstructed
  peripheral write matches the original prefix (fmacfw_h 1,964/1,964,
  fmacfw 1,960/1,960, fmacfwbt 1,953/1,953, lmacfw_rf 2,236/2,236);
  `tools/fidelity_meter.py` therefore defaults `--boot-insns` to 500k.

- **Final fidelity evidence (2026-11-27)**: `metadata/fidelity_meter.json`
  covers all 4,718 composed functions across five probe vectors. Static
  defect functions, under-arity rows, jumpout/memory-macro defects, missing
  stubs, residual full-link undefs, and failing dynamic rows are all zero.
  3,181 functions are exercised all-match (67.42%), 1,320 are vacuous
  all-match, 217 are never-comparable (209 originals never return in standalone
  probes; 8 interior libmatch fragments are non-callable), truth lane is
  25/25 on bare_zero and all vectors, and boot MMIO writes are exact ordered
  prefixes through the 500k-instruction cap. Do not describe vacuous or
  never-comparable rows as proof of deep equivalence; the precise caveats are
  in `docs/FIDELITY_V26_VERDICT.md`.

- **Naming DONE**: all 5,623 `sub_*` functions in `src/` have `status=ok`
  names in `harness_v17/names/` (23,498 files; 0 unnamed).
  - LLM path: GLM-5.3 (`reasoning_effort="max"`) via **OpenAI SDK** (`openai` pkg,
    `base_url` from `harness_v15/keys/keys.json` — untracked, do NOT commit),
    client sets `User-Agent: aic8800d80-pipeline/1.0`, `x-opencode-session`,
    no `max_tokens`, and `timeout=None`.
  - **OpenCode Go defaults**: no concurrency limits, no output limits
    (`max_tokens` omitted / `0`), and no HTTP timeout (`timeout=None` / `0`);
    prompt caching is automatic via stable `x-opencode-session`.
  - Disasm cache (linear r2 sweep) mis-decodes 2 bytes when a data pool
    precedes a function start → `naming_src.py::disasm_at_fallback` spawns
    r2 per address with the proven `-a arm -b 16 -m 0x100000` form.
- **Verification**: `make -C src check` — all 4 images compile clean
  (real decompiled bodies + materialized data segment, no stubs).
  `tools/truth_lane_smoke.py --src` remains only the shallow depth-0 screen
  (**18 PASS / 7 REVIEW / 0 FAIL**): it stubs callees, so the 7 REVIEW rows are
  targets whose original writes occur in callees. The authoritative ordered-
  peripheral truth-lane gate is `python3 tools/linked_recon_run.py --all`;
  rerun on 2026-11-27 it is **25 PASS / 0 REVIEW / 0 FAIL**. Twenty rows have
  identical full peripheral sequences; five (`rf_timer_toggle_update`, the two
  `rf_bus_write2`, and the two `rf_level_apply`) have identical ordered
  peripheral write sequences while read timing differs, which the linked-run
  criterion treats as PASS because writes are the externally visible sequence.
  The older 1-PASS/6-FAIL callee defects are historical forensic evidence in
  `docs/TRUTH_LANE_REVIEW_VERDICTS.md`, not the current status. The fidelity
  meter independently reports the same 25 targets as 25/25 on bare_zero and
  all vectors under its MMIO+RAM+r0 comparison.
- **Emulator (milestone)**: `tools/aic8800d80_emulator.py` — full-system
  Unicorn platform, **Cortex-M4 CPU model** (corrected 2026-08-02: the
  firmware uses VFP instructions like `vpush {d8}`, which hardfault on a
  plain Cortex-M3 — all 4 images faulted at ~25k insns; under M4 they boot to
  300k+ insns with ~24k MMIO writes), MMIO device model from
  `src/include/aic8800d80_mmio.h`, optional behavioral model from
  `src/include/aic8800d80_mmio_behavior.json` (poll registers become ready
  after N reads, strobe registers self-clear), boot from the IVT
  reset vector, and original-binary behavioral fingerprints for the 25
  truth-lane targets. `load_function_table` returns hardware-space addresses
  (+0x20000) so PC→function resolution and depth-0 body tracking work at the
  0x120000 runtime base; `on_mem` records read-back values.
  - **RUNTIME BASE IS 0x120000, NOT 0x100000** (corrected 2026-08-02). The
    IVT reset vector is 0x1201a9 = 0x1201a8|1 = the CPUID-check `start` at
    file 0x1a8 — *correct* at base 0x120000. The earlier "stale IVT" finding
    was an artifact of assuming base 0x100000. Confirmed by: (a) reset vector
    lands exactly on the CPUID start at 0x120000; (b) switch jump tables that
    Hex-Rays cannot decompile point to targets exactly +0x20000 past the
    functions in 0x100000-space, i.e. in-function at 0x120000; (c) all 4
    images boot DEEP from the reset vector at 0x120000 (8000+ insns, ~2660
    MMIO writes, no fault) vs the old base where fmacfwbt short-circuited at
    125 insns and the other 3 faulted at ~44 insns on a null-pointer write.
    The reconstruction / naming dataset / composed src intentionally stay in
    a self-consistent "analysis space" = file + 0x100000; the ORIGINAL
    binary is loaded at 0x120000 by the emulator (targets run at key+0x20000,
    compare key unchanged). `run()` reports `fault_address`/`fault_access`/
    `fault_size` for every unmapped access.
  - `verify` → `orig_fingerprints.jsonl`; `compare` vs
    `truth_lane_smoke.py` outcomes scores peripheral-register overlap on
    the SAME basis (depth-0 = the entry function's own body traffic,
    excluding callees — the reconstruction stubs callees, so the original's
    callee traffic must be excluded too): **12 matched / 13 no-peripheral-traffic**.
    The former 4 recon-missing results came from truncating the reported
    addresses before filtering out ordinary memory. Equal address sets do
    not establish equal values, access order or behavior.
  - **25/25 verify, 0 faults** (2026-08-02): the last 3 non-returns
    (`rf_reg_write_wait` ×2, `rf_timer_toggle_update`) jumped through null
    boot-ROM callback slots (0x1b0/0x1b4/0x1b8 + 0x1fc/0x1d8) that the ROM
    populates before the image runs. `_seed_boot_callbacks` now writes a
    Thumb `movs r0,#0; bx lr` stub at 0x20080000 and points every slot at
    it (the same return-0 the recon smoke stubs use), so the indirect calls
    return cleanly. Verify: 25/25 returned, 0 capped, 0 faulted. The full
    slot union is 0x1b0/0x1b4/0x1b8/0x1c8/0x1d8 + 0x1fc (fmac images) or
    0x1d0/0x1d4/0x1e0 (lmac_rf); seeding it lifted the corpus sweep
    (tools/corpus_sweep.py, all 5,945 functions) to 79.0% clean execution
    with 0 genuine unmapped-MMIO faults.
  - **`--bootstate` mode (2026-08-02)**: boot once per image (300k insns),
    capture ONLY the persistent global-region writes strictly below the deepest
    boot SP, inject them into each fresh function run. Gives the allocator its
    heap head (fmacfw_h `[0x182b60]=0x1731be`, lmac_rf `[0x180ac0]=0x158272`,
    static free-list nodes in the image data), the boot callback slots, and
    log/config globals — WITHOUT the partially-populated SRAM structs that make
    `--boot-first` regress (null-callbacks).
  - **Zero faults (2026-08-03)**: faults 797 → 172 → **0** across all 5,944
    functions. The residual 172 (null-block-to-allocator derefs + null
    function-pointer calls) were closed with execution-context fixes in the
    emulator: a `counter` MMIO type (tick-counter registers return
    insn_count//rate so `delay_us`/tick-waits terminate), null-call stubs (a
    call through an uninitialized handler field returns 0), null-safe free +
    null shadow page (`free(NULL)` no-ops; `0xfffff000` absorbs null-adjacent
    accesses), `udf #255` assert skip, SRAM mapped in chunks up to 0x21000000,
    a low shared-memory window, and a `start`-entry scan correction. MMIO
    layer complete; execution context fully injected.
  - **Spin-breaker / garbage-branch handling (2026-08-03)**: residual capped /
    faulted runs are functions blocked at a legitimate OS wait or derailed by an
    uninitialized handler slot that the real interrupt / other-core path would
    resolve but the standalone emulator can't. ``run(spin_break=True)`` (on in
    the corpus sweep, off for boot/verify) delivers the event. Five mechanisms:
    (1) **memory-flip** — a stable set boolean flag (==1) re-read from the same
    pc is cleared; value 0 fields are NEVER overwritten (may be a pointer wait);
    (2) **branch-jump** — a backward branch executed repeatedly with a read
    recently (candidate-global OR peripheral) and no write since is a wait:
    jump past it (pc+2). Peripheral MMIO traffic updates the read/write
    timestamps so an MMIO register *walk* (rf_bus_reset's 0x40200900/20/40
    sequence) is seen as advancing and never mistaken for a wait; (3)
    **register-grind** — a backward branch with NO memory activity since the
    loop's previous iteration is a pure-register/FPU delay loop: skip past it;
    (4) **data-march** — a fetch outside the image bytes (stack window, SRAM,
    heap) is a garbage indirect branch executing data-as-code: null-return via
    LR; (5) **output-loop breaker** — a backward branch whose body wrote the
    SAME peripheral register >=4096 times is an output pump (UART/printf TX
    over an unterminated standalone buffer): skip past it. Stack-scratch
    writes/reads near SP (abs(addr-sp) < 0x200) are exempt from the timestamps
    — a delay loop decrementing `[sp,#4]` must not mask a slow re-check wait —
    but the exemption is NEAR-SP only: the 0x180000-0x1a0000 window also holds
    firmware GLOBALS, and a memset writing them is real work (the old whole-
    window exemption left the write timestamp stale and let the branch-jump
    misfire on init-loop back-edges, e.g. key_mfp/sub_1420A0). The garbage-
    branch / unmodeled-access classes are closed by: unmapped FETCH →
    null-return, non-MMIO unmapped WRITE → lazy scratch page, UC_ERR_EXCEPTION
    → null-return via LR, and **sentinel-page return** — a pop {pc} restoring
    RETURN_STOP|1 (0xdeadc001) makes unicorn raise UC_ERR_EXCEPTION at the odd
    fetch before the code hook stops it (key_mfp ran a spurious 606k-write
    loop from the re-entry), so any fetch in the sentinel page (all `b .`) is
    now a clean return. A data fix corrected `rf_bus_reset_status`
    (0x40200014) ready_mask from 0x1 to 0xC0 (firmware polls bits 6/7 via
    `lsls #0x18/#0x19`).
    Three later mechanisms (2026-08-04) target the residual capped classes:
    (6) **self-loop abort** — a branch to its own pc (`b .`) can never
    terminate; real firmware reaches it only through an abort/assert hang, so
    return via LR after a few executions (the abort traps rf_sub_12EF88,
    error_trap, ke_timer_set, ...); (7) **memset fast-forward** — a fill loop
    `str rN,[rM],#4; cmp rM,rK; bne` over a large span (is_patch_loaded,
    start, ring_buf_used zero ~1MB global regions) is executed at once by
    writing the whole span and jumping past the loop (detected via capstone
    so a copy loop with a preceding `ldr` is never matched). The behavior
    model also gained an **"rx" type** — a status register whose ready bit
    reflects a byte available in a paired data register, cleared when that
    data register is read (consume-on-read). 0x40032014 (rf_status) was a poll
    with reads_to_ready=200, a harvest artifact that made console echo loops
    (log_boot_message, timeout_handler, process_debug_char, ...) spuriously
    "ready" then spin consuming 0x00 bytes; as "rx" with no host producing a
    byte, the bit stays clear and those loops block (exited) — the correct
    no-host emulation.
    Final full-sweep result (100k bootstate): **0 faults** across all 5,944
    functions — see docs/MMIO_MAPPING.md for the current returned/capped/exited
    split. The earlier 30k-era split was returned=5289, capped=523; the
    pre-spin-breaker baseline was returned=4402, capped=1542.
    `tools/mmio_model_build.py` normalizes the `counter` MMIO type (was
    hand-edited into the model only): the two tick-counter registers
    `rf_tick_counter` (0x40320120) and `timer_value` (0x40501010) survive
    regeneration and make `delay_us` / elapsed-tick waits terminate.
  - **Unicorn 2.1.4 valid-read-hook epilogue defect (machine-proven
    2026-11-26)**: a valid `UC_HOOK_MEM_READ` hook — even one scoped only to
    MMIO — can drop the writeback/control transfer of a Thumb epilogue
    `pop {..., pc}`; execution then continues through the literal pool with
    SP unchanged, producing bogus MMIO writes from data bytes. The exact same
    machine code returns correctly with write-only or unmapped-access hooks.
    Do not “fix” faithful C for this shape. The default meter still uses the
    behavioral read-hook backend, but the two machine-proven artifact sites
    (`sub_1383DC`, `osal_int_exit`) are cross-validated with
    `Aic8800D80Platform(mmio_read_hooks=False)`; only vectors that become full
    MMIO+RAM+r0 matches under that backend are reclassified. See
    `docs/OSAL_INT_EXIT_FORENSICS.md`.
- **Full-link (non-gc) analysis**: `tools/analyze_full_link_undefs.py`
  quantifies the ~421 undefs when linking without `--gc-sections`:
  58% naming artifacts (name points inside a composed function — code
  exists), 23% no-mapping (mostly data-symbol-as-function decompile
  artifacts), 15% `__aeabi_*` float helpers (need `-lgcc`), ~2% real
  missing code (6 `sub_*` gaps). **Decision: keep `--gc-sections`
  reachability as the gate** — the undefs are model artifacts, not missing
  code. Full write-up: `docs/FULL_LINK_ANALYSIS.md`.
- **Full link (WORKING, non-gc)**: `tools/full_link.py` makes the full link
  actually succeed: 4/4 ELFs at chip base 0x100000 with **zero undefs**.
  Resolves the ~421 undefs as: 5 call-site aliases to composed functions
  (via the LLM dataset, indexed by BOTH `fn` and `name`, resolved with
  `.thumb_func` trampolines — C `alias()` and `.thumb_set` both lose Thumb
  mode), 346 `.bss` data blobs for the decompiler data-symbol refs
  (`*(uint32_t*)name`), `-lgcc`/`-lc` for `__aeabi_*` + libc helpers, and —
  after the base-0x120000 decompile work — **no genuine code gaps remain**:
  `report.json['total_missing']` = 0.
  The 8 former stubs were closed as: 6 `sub_*` switch-analysis failures
  decompiled at the hardware base 0x120000 (their jump tables are linked for
  that base) and shifted −0x20000 into analysis space; fmacfwbt's boot `start`
  composed like the other 3 images; and the Hex-Rays intrinsic
  `COERCE_UNSIGNED_INT` defined in `aic8800d80_types.h` + compose's
  `headerIntrinsic`. New tooling: `harness_v19/scripts/ida_decompile_hwbase.py`
  (targeted decompile at 0x120000 with analysis-space shift) and
  `tools/convert_decompiled_to_functions.py` (decompiled → src/functions
  format, incl. 2D data-symbol subscript + MSVC `__asm` + JUMPOUT shifts).
  Outputs go to gitignored `build/full_link/`.
- **Call-site disambiguation (duplicate names)**: the LLM naming gave the
  same name to distinct functions (214 same-image dupes, ~460 redundant
  bindings). Compose keeps the definitions unique (base + `_1`) but baked-in
  call sites kept the base name, so calls meant for the second unit bound to
  the first. `cmd/fwstruct/compose.go::disambiguateCallSites` now rewrites
  each call site to the address the ORIGINAL binary actually targets (IDA
  call edges from `extraction_out/ida_export_live/*.call_edges.jsonl`,
  chip-space; no-op if absent). Skips 0-arg Hex-Rays artifact calls (the
  deduped target may be variadic). ~1000 call sites fixed across 3 images;
  `make -C src check` still succeeds (current smoke results above).
- **Linked comparison over all composed functions**:
  `tools/linked_recon_run.py --corpus` compares all 4,714 composed functions
  against the original in the full link: **4,230 match / 228 differ / 256 not
  comparable** (exercised default-state path only; first run 3,581 / 433 /
  700). The run ends at a return or at the assert trap (`udf #255`) and the
  tick counters advance per read. Post-compose rules that came out of it, in
  order: `tools/callsite_targets.py`, `periph_symbols.py`, `asm_returns.py`,
  `call_cast_returns.py`, `double_args.py`, `float_bits.py`,
  `stack_frames.py`, `dword_compares.py` (each has `--check`);
  `fwstruct compose` runs them with heal through `tools/post_compose.py`, and
  `make -C src reproduce` checks a fresh compose equals the tracked `src/`. The 25 targets
  are 20 PASS / 5 FAIL in the linked run. Causes and counts:
  `docs/LINKED_CORPUS_COMPARISON.md`.
- **Compose dedupe**: units deduped by address, preferring the plain
  `sub_<ADDR>` file (pre-rename decompile with real data symbols) over
  LLM-renamed re-decompiles (`cmd/fwstruct/compose.go::readFunctionUnits`).

## Defect class: IPSR/PRIMASK conflation (machine-proven)

Hex-Rays prints both `mrs rN, IPSR` and `mrs rN, PRIMASK` as
`__get_CPSR()`. These are not interchangeable: IPSR is the active exception
number (zero in thread mode even when interrupts are masked), while PRIMASK
bit 0 is the interrupt-mask state mutated by `cpsid/cpsie`. The shared header
therefore keeps the PRIMASK shadow for `__get_CPSR()` but now provides a real
`__get_IPSR()` (`mrs %0, ipsr`). Machine evidence: all three fmac-family
logging/formatter functions execute `f3ef 8605 = mrs r6, IPSR` at +8:
`stack_struct_init` 0x10d6c8 (fmacfw_h), `prepare_debug_buffer` 0x10d808
(fmacfw), and `debug_printf` 0x10d660 (fmacfwbt). Treating that as PRIMASK
suppressed the final UART-ready write `0x40035040=1` after a log line when
called inside a critical section, producing the six remaining fmac boot-vector
`mmio_differ` rows. `tools/mrs_ipsr.py` is the address-keyed post-compose
repair; after validation all six rows match every vector and the full corpus
has zero proven behavioral divergences. Do not replace the PRIMASK shadow globally: many critical-section
functions genuinely execute sysreg 0x10 (`MRS PRIMASK`).

## Defect class: frame-object overlap (recurring, machine-proven)

Three independent high-blast-radius defects shared one root cause: Hex-Rays
models raw stack scratch spans as small separate struct objects while the
original code treats the frame as contiguous raw memory. Pointer arithmetic
outside object bounds is undefined behavior in C, so correct compilation may
split/scalarize the frame and place spill slots where the original kept dead
scratch — clobbering data or being clobbered by oversized copies. Instances
repaired so far, all as post-compose union/merge rules:

- formatter digit scratch (tools/format_scratch_frame.py) — corrupted all
  decimal conversions, derailed boot logging in fmacfw images;
- patch_apply/patch_apply_ext ROM-copy frames (tools/rom_copy_frames.py) —
  the 72/320-byte boot-ROM copies overran the frame into saved registers;
  systematic orig=1/recon=-1 across the SMC/patch wrapper family.

Diagnostic signature: behavior correct in original, wrong in reconstruction
with inputs/memory verified identical; output/state containing leaked stack
pointer bytes; defects appearing only under some correct compilations.
Verification method: compare machine-level frame layout (copy dst offsets,
sp-adjust) in original disassembly vs objdump of the linked ELF, not just C.
Suspect this class whenever a packed `_frame` struct is indexed through
pointers that escape their member object, or a large copy targets a small
first member.

## Hard rules (do not violate)

1. **THINK IN TAGS, NOT BASH COMMANDS**: never use bash as scratch.
2. **LLM cost is NOT a constraint**: never halt execution early for token
   budget; never set max_tokens caps. Reasoning models need full output.
3. **Address-safety rule is absolute**: LLM may NOT compute any address,
   offset, pointer, or size in its head. Provide tools.
4. **LLM is NEVER a C author** — only tool user / naming oracle. All C is
   mechanically generated (v17+), decompiled (Hex-Rays), or emitted by
   fwstruct transforms.
5. **No artificial limits**: no max_tokens cap, no iteration cap, no
   batch-size capping for correctness.
6. **O(n) is mandatory**: never O(n*m) text splices in loops on multi-MB files.
7. **Long-running commands detached**: `setsid nohup ... > log 2>&1 &`,
   then poll the log in short sleeps. Never `wait` on a nohup'd process.
   Bash tool has 120s timeout.
8. **No synthetic/template bodies**; demand real semantic fidelity.
9. **Bugs are blocking**: fix integration bugs first, then continue.
10. **Frequent Commits**: commit after every meaningful change.
11. **Do not modify generated files manually**; fixes via real rebuild.
12. **Dual-track (A + B)**: hardware test path + cloud release path.
13. **Task Completion**: execute to full completion; verify mechanically.
14. **Use Hex-Rays decompiler** (`$IDAT` or `$HOME/ida-pro-9.3/idat`) for
    human-readable C. Hex-Rays output is cached — re-decompile or use
    `idaapi.decompile(ea, flags=idaapi.DECOMP_NO_CACHE)`.
15. **Use `bin/fwstruct`** for all structure/metadata work.
16. **Do not commit `harness_v15/keys/`** — API keys are untracked.

## LLM configuration (GLM-5.3 via OpenCode Go)

- Provider: OpenCode Go (`opencode.ai`)
- Endpoint: `https://opencode.ai/inference/go/openai/v1/chat/completions`
- Model: `glm-5.3` with `reasoning_effort: "max"`
- Key: `harness_v15/keys/keys.json` → `providers[0].api_key` (untracked file)
- **REQUIRED headers**: `User-Agent: aic8800d80-pipeline/1.0` and a
  stable session ID `x-opencode-session: ses_<id>` per run/conversation (both
  Python `oracle.py` and Go `internal/llm` generate and send them).
- `glm-5.3` is run at `reasoning_effort="max"` with NO output limit
  (`max_tokens` omitted / `0`) and NO HTTP timeout (`timeout=None` in Python,
  `Timeout: 0` in Go).
- Python call path: `harness_v17/oracle.py::call_api` (reads key file,
  builds endpoint from `base_url` + `/chat/completions`).
- Go call path: `internal/llm.Client` (defaults match the same endpoint/model).
- Go keys: `AIC8800D80_LLM_KEY_<N>` / `OPENCODE_API_KEY` env vars,
  `--llm-key-dir`, or `harness_v15/keys/keys.json` (`--llm-keys`).

## Pipeline commands

```bash
# Build the one tool
go build -o bin/fwstruct ./cmd/fwstruct

# Deterministic structure + metadata (no LLM)
bin/fwstruct scan | callgraph | structs | magic | initpath | diff | types | ivt | annotate | xref | report

# LLM naming (uses glm-5.3 max reasoning, keys from harness_v15/keys/keys.json)
python3 harness_v17/naming_src.py            # name anonymous sub_* funcs in src/
bin/fwstruct names                           # name struct clusters
python3 harness_v17/naming.py                # legacy full-function naming driver

# Decompile pipeline (Hex-Rays, per image)
harness_v19/scripts/run_v19.sh <image> both   # image names: fmacfw_8800d80_*_u02_bin etc.

# Produce src/<image>/main.c: compose, then tools/post_compose.py (heal_composed +
# every mechanical rule, in order). Needs inputs/firmware/*.bin (tools/fetch_firmware.sh).
bin/fwstruct compose                          # -raw stops before post_compose
python3 tools/post_compose.py --check         # every rule at its fixed point, sources compile
make -C src reproduce                         # fresh compose == tracked src/ (git diff --exit-code)

# Truth-lane behavioral verification
python3 tools/truth_lane_smoke.py --final-dir extraction_out/reconstruction/mega7/final --out /tmp/opencode/truth_lane_smoke
```

## Address conversion cheat sheet

```
HARDWARE runtime BASE = 0x120000   (SoC loads the WFFW image here; IVT reset
                                   vector 0x1201a9 == CPUID start @ file 0x1a8)
v14 BASE           = 0x1200000     (old IDA-export convention)
analysis space     = 0x100000      (reconstruction / naming dataset / composed
                                   src: file_offset + 0x100000, self-consistent
                                   but NOT the hardware base)
file_offset + 0x100000 → analysis-space addr
analysis-space addr + 0x20000 → hardware addr (0x120000 base)
chip addr = v14 addr - 0x1100000
```

## IDA Pro setup for AIC8800D80

Analysis wraps the firmware as ARM Thumb at `0x100000` (analysis space, for
dataset consistency — the hardware base is 0x120000). To get IDA to recognize it:

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
Note: `harness_v17/tools.py::disasm_at` uses the `-a arm -b 16 -m 0x100000`
form; it is empirically working for the naming pipeline — do not "fix" it.

## AIC8800D80 firmware specs

- 4 binaries, ~340KB each; hardware loads at 0x120000 (analysis space 0x100000)
- 4,723 total functions across 4 images (v19 boundaries)
- 5,945 function instances analyzed by v25 scan; 5,623 in src/ functions/
- 25,815 unique MMIO addresses; 1,042 distinct 64KB pages

## IDA quirks discovered

- `idc.get_db_name` doesn't exist in 9.x — use `idaapi.get_input_file_path()`
- `idc.SN_FORCE` is in `ida_name.SN_FORCE`
- `set_segm_attributes` is gone — use `seg.perm = ...` directly
- Hex-Rays output is **cached** — changes to symbols require re-decompile
  or `idaapi.decompile(ea, flags=idaapi.DECOMP_NO_CACHE)`
- Hex-Rays uses MSVC types (`__int64`, `_DWORD`, `_BYTE`), `_R0.._R15`
  registers, `_CF/_ZF/_NF/_OF` flags

## Disk space

- /tmp is 7.5GB tmpfs — keep IDB usage low
- IDBs are 2.1GB each (MMIO phantom segment) — store in `harness_v19/idb/`
  (gitignored), never in git
- Release tarballs < 10MB; safe for git

## Critical gitignore entries

- `*.i64`, `*.id0`, `*.id1`, `*.id2`, `*.nam`, `*.til` (IDA databases)
- `*.bin` (raw firmware), `*.o` (build artifacts — do not add back)
- `*.gz`, `*.tar.gz` (added with -f for releases)
- `harness_v15/keys/` (API keys — never commit)
- `harness_v19/decompiled/`, `harness_v19/idb/`, `harness_v19/log/`
- `extraction_out/`, `analysis/`

## Where to start

- Unified series status: this file; docs for the pipeline: `PIPELINE.md`
- fwstruct subcommands: `bin/fwstruct` (or `cmd/fwstruct/main.go`)
- src tree: `src/README.md`, `src/Makefile` (`make -C src check`)
- Legacy v19 machinery (still the decompile engine): `harness_v19/README.md`

## Luna batch pipeline (2026-11) — operational facts

- **gpt-6-luna batch**: `tools/luna_batch.py` over `tools/codex_backend.py`
  (Codex subscription backend). Batch corpus analysis output:
  `metadata/luna_analysis/{fn}__{img}.json` — analysis is nested JSON inside
  the top-level `text` field. Manifest: `tools/luna_manifest_analysis.py`
  reads module slices post-demonolithize.
- **Prompt caching on the subscription backend is REAL but conditional**
  (measured 2026-11-25): requires (a) shared prefix past the 1,024-token
  floor — tokens in hidden system content do NOT count, (b) stable
  `prompt_cache_key` for server affinity, (c) byte-identical prefix. Verified:
  2,176/2,415 tokens cached (90%). The batch mega-prefix in the manifest
  generator is ~1,265 tokens. Do NOT shrink it below the floor.
- **Fast mode** = `service_tier: "priority"` (the literal "fast" is
  rejected); measured 1.63x speedup, free through Dec 31 2026.
- **Application rules** in post-compose chain AFTER demonolithize:
  luna_rename_apply.py (noise-only, high-confidence, collision-aware,
  umbrella-prototype-aware) then luna_semantics_apply.py (docstrings
  medium+, var renames high-confidence, collision-guarded per-function).
- **Decisions API**: platform key in harness_v15/keys/openai_platform.json
  (gitignored); client tools/decisions_client.py; choice values must be
  objects not strings.
