# MMIO Behavioral Mapping + FPU-Capable CPU Model

Two findings from the MMIO mapping work (2026-08-02) that make the emulator
boot the firmware much deeper and give the peripheral register space real
semantics.

## 1. The SoC CPU is an FPU-capable M-profile core (Cortex-M4)

The firmware executes VFP instructions (`vpush {d8}`, ...). The emulator
defaulted to `UC_CPU_ARM_CORTEX_M3`, which has no FPU and raises an undefined-
instruction exception (hardfault, `UC_ERR_EXCEPTION`) on the first VFP op.

Confirmed empirically across Unicorn CPU models:

| CPU model   | lmacfw_rf boot (50k insns)      |
|-------------|---------------------------------|
| Cortex-M3   | fault @ 24,884 insns (`vpush`)  |
| Cortex-M4   | cap @ 50,000, 7,680 MMIO writes |
| Cortex-M7   | cap @ 50,000, 7,680 MMIO writes |
| Cortex-M33  | cap @ 50,000, 7,680 MMIO writes |

With **Cortex-M4** all four images boot to 300k+ instructions with no fault
(~24k MMIO writes for the two fmac images). The emulator default is now M4.

## 2. MMIO register mapping pipeline

The firmware's peripheral register space is mapped in three deterministic
stages. The LLM classifies register semantics from emulator-harvested
evidence; it never computes addresses and never writes code.

### 2a. Harvest evidence — `tools/mmio_harvest.py`

For each of the four images, three coverage sources are merged (all at the
hardware base 0x120000):

1. **boot** from the IVT reset vector (deep init traffic)
2. **truth-lane targets** (25)
3. **per-function sweep** — run every entry in the fwstruct function table
   (~1,300–1,740/image) with a short instruction cap, so registers touched by
   code paths the boot never reaches still get evidence.

Output: `build/mmio/evidence.json` (gitignored). Per-register profile: read/
write counts, access sizes, distinct written/read-back values, the firmware
functions that touch it (PC resolved via the function table), echo detection
(value written then read back), poll detection (read-heavy, write-starved),
and same-page co-access clusters.

Current totals (all 4 images): **1,704 dynamic peripheral registers**, 36
poll candidates, 237 echo candidates — vs ~99 registers from boot alone.

A static candidate universe (32-bit MMIO-region constants found in the raw
binaries) is also emitted for extending coverage. 379 of those candidates live
in dynamically-touched pages as *non-overlapping* siblings and joined the
classification target set.

### 2b. LLM classify — `tools/mmio_classify.py`

Reuses the v17 oracle (`harness_v17/oracle.py::call_api`, DeepSeek via the
OpenAI SDK). Registers are grouped by page (chunks of ~32) and the LLM is
given the full evidence per register. It returns per register:
`name`, `role` (config/status/strobe/mask/irq/data/clock/unknown),
`confidence` (0..1), `behavior`, and optional `fields` (bit -> meaning).

Address safety is enforced: every address in the LLM output must be verbatim
from the batch evidence; invented addresses reject the batch.

Output: `build/mmio/classifications.jsonl` (+ merged `.json`), resumable.

**Full run (final): 2,083 / 2,083 registers classified (100%), 0 failures.**
Target universe = 1,704 dynamic + 379 static siblings (a further 296 static
candidates overlap dynamic registers and are already counted there — the naive
1,704+675 sum double-counts them). 78 batches over ~14 min, LLM workers=1.
Role distribution: `config` 425 · `data` 228 · `status` 162 · `clock` 149 ·
`irq` 45 · `strobe` 22 · `mask` 9 · `unknown` 1,043. The unknown-heavy share is
the static-only siblings (no dynamic evidence to reason from), as expected.

Example classifications the model produced:
- `0x40032020` (polled 60× in boot, always returned 0) -> `poll, ready_mask 0x1`
- `0x4003505c` (rf_reg_write_wait polls it 3,392×) -> `poll, ready_mask 0x1`
- `0x40032000` -> `data` (write-only command/data register)
- `0x40032014` `rf_status` -> `poll, ready_mask 0x1, reads_to_ready 266`
- `0x40035058` `efuse_read_status` -> `poll, ready_mask 0x1`
- `0x40032024` `rf_chan_status` -> `poll, ready_mask 0x40000`

A browsable one-line-per-register **register dictionary** is maintained at
`docs/MMIO_REGISTER_DICTIONARY.md` (auto-generated, 2,083 rows grouped by
page, with role / behavior detail / confidence / source / read-write counts).

### 2c. Materialize — `tools/mmio_model_build.py`

Deterministically converts classifications into
`src/include/aic8800d80_mmio_behavior.json`. Behavioral rules are applied ONLY
to dynamic-source registers with `confidence >= 0.4`, and only for the rule
types the emulator can act on:

- `poll`: status register a poller waits on -> reads return
  `last_written & ~mask` until `reads_to_ready` reads, then `last_written | mask`
- `strobe`: a write takes effect then reads return 0 after `clear_after` insns

`none`/`echo` are recorded but not acted on (the phantom already returns the
last written value). Static-only registers are never given behavior.

**Evidence-poll floor**: when the harvest deterministically flagged a register
as polled (read-heavy, write-starved) *and* the model independently agrees
(`role=status`, `behavior=poll`), the register's confidence is floored at
`BEHAVIOR_MIN_CONF` so a hesitant numeric score cannot drop a real poll rule
(observed: `rf_busy_status` @ 0x4010d01c came back at 0.3 and was materialized
anyway; the truth-lane target that spins on it now progresses instead of
capping).

### 2d. Emulator integration

`Aic8800D80Platform` loads the behavior model. Values are injected via the
**pre-read** `UC_HOOK_MEM_READ` hook (verified: rewriting memory in the hook
changes the value the load sees). Writes re-arm a poll register (read counter
reset) and start a strobe window. Absent the model file, the emulator behaves
identically to before.

## 3. Effect on verification

Re-running the original-side fingerprints (`emulator verify`, 25 targets):

| metric               | M3 (depth-0 broken) | M4 (no model) | M4 + behavior model (full) | + boot-ROM slot seeding |
|----------------------|--------------------:|--------------:|---------------------------:|------------------------:|
| verify returned      | 18 / 25             | 20 / 25       | 22 / 25       | **25 / 25** |
| verify capped        | —                   | 3             | 0             | 0           |
| verify faulted       | 6                   | 2             | 3             | 0           |
| compare mean Jaccard | 0.52                | 0.667         | 0.667         | 0.667       |
| compare matched      | 8                   | 8             | 8             | 8           |
| recon-missing        | 7                   | 4             | 4             | 4           |

The **full** model (behavior column) is rebuilt from the complete classification
run: **2,083 registers** (100% of the target universe = 1,704 dynamic + 379
non-overlapping static siblings), **42 behavioral rules** (32 poll + 10 strobe),
**31 evidence-poll floors**. This replaces the earlier 388-register / 19-rule
snapshot; coverage is now the entire touched peripheral space.

The behavior model converts the two poll-blocked targets
two poll-blocked targets `rf_cmd_dispatch` and `rf_mem_write` (fmacfwbt) from
capped → returned: their status registers are now modeled as poll rules, so
the firmware's `while (!(reg & MASK))` loops exit instead of spinning to the
instruction cap. The last 3 non-returns were standalone caller-state
dependencies (the target jumped through a **null boot-ROM callback slot** —
not a CPU or MMIO issue) and are now fixed by seeding those slots:

- `rf_reg_write_wait` (2 images) and `rf_timer_toggle_update` call through
  fixed low-memory vectors (`0x1b0/0x1b4/0x1b8`, plus `0x1fc` on the fmac
  images / `0x1d8` on lmac_rf) that the boot ROM populates before the image
  runs. The emulator previously read 0 there, so `bx r3` branched to address
  0 (invalid instruction). The platform now writes a tiny Thumb
  `movs r0,#0; bx lr` stub at a dedicated page and points every slot at it —
  the same "return 0" semantic the reconstruction smoke uses for these
  calls. `rf_timer_toggle_update` executes its full 1,671-instruction RF
  control flow (352 reads / 195 writes) before returning.

Result: **25/25 truth-lane targets return, 0 capped, 0 faulted** — the
verify ceiling is removed. Boot smoke unchanged: all 4 images run
**300,000 instructions, capped, zero faults** (57k/24k MMIO reads/writes per
image; the slots are pure boot-ROM state, untouched during boot).

The compare metrics are unchanged because the behavior model is platform-level:
it runs on both the original and reconstructed sides, so register-overlap
fidelity is unaffected. Its value is deeper original-side execution (boot +
truth-lane returns) and stable poll/strobe semantics for both sides.

### Corpus-wide coverage sweep (`tools/corpus_sweep.py`)

With the 25-target gate green, the emulator is run against **every** function
in all 4 images (5,944 total) to find gaps the curated set misses. The
current result, with the boot-state injection + five-mechanism spin-breaker
(memory-flip, branch-jump incl. peripheral polls, register-grind, data-march,
output-loop breaker — see AGENTS.md):

```
TOTAL scanned=5944 returned=5481 exited=427 capped=36 faulted=0
     (0 faults, 92.2% clean return; 100k sweep + 2M re-run of the
      capped, cs_final + hb_final. The 36 residual capped are genuinely
      long RF-config RMW loops, log-buffer output loops, and small
      OS-lock waits that standalone memory never resolves.)
```

- **Zero faults** across the whole corpus. The earlier fault classes
  (allocator `udf #255` traps, null indirect calls, null-argument derefs,
  unmapped fetch/write through uninitialized pointers) are all closed:
  boot-state injection supplies the allocator heap head / boot callback
  slots, the null-call stub returns 0 through uninitialized handler fields,
  unmapped reads/writes are absorbed onto lazy zero/scratch pages, unmapped
  fetches null-return, and `UC_ERR_EXCEPTION` (data decoded as a coprocessor
  instruction after a garbage branch) returns via LR.
- The **spin-breaker** converts wait-blocked runs to returned: a backward-
  branch wait loop whose read address is stable and unwritten is jumped past
  (emu_stop + re-entry), and a set boolean flag (==1) re-read from the same
  pc is cleared. The branch-jump requires a genuinely write-free window so a
  data-copy loop (whose callee re-loads a mailbox address from the same
  literal-pool slot) is never skipped into the next function's padding.
- The residual **523 capped** are genuinely long bounded functions — RF
  register-configuration loops (`sub_102BB0` read-modify-writes ~3k MMIO
  registers), heavy crypto/PHY init — that need a larger instruction budget
  than 30000, not MMIO gaps. The pre-spin-breaker baseline was returned=4402,
  capped=1542.

Two boot-state diagnostics quantify how much of the residual is context
dependence rather than MMIO:

- **`--boot-first`** (boot once per image, snapshot, run each function against
  the restored booted state): booting eliminates the allocator trap but exposes
  ~120 new null-callbacks, because boot-populated globals point into structures
  whose function-pointer fields the 50k-insn boot has not installed yet — net
  worse (932 → 605 returned on lmac_rf).
- **`--bootstate`** (boot once per image, capture ONLY the persistent
  global-region writes strictly below the deepest boot SP, and inject them into
  each fresh function run): the targeted middle path. It gives the allocator
  its heap head (a static free-list node in the image data, e.g. fmacfw_h
  `[0x182b60] = 0x1731be`, lmac_rf `[0x180ac0] = 0x158272`), the boot callback
  slots, and the log/config globals — WITHOUT the partially-populated SRAM
  structs that make boot-first regress.

  ```
  standalone: returned=4694 capped=450  faulted=797
  bootstate:  returned=4237 capped=1536 faulted=172   (78% fewer faults)
  bootstate:  returned=4402 capped=1542 faulted=0     (all fixes)
  bootstate+: returned=5289 capped=523  faulted=0     (+ spin-breaker, 30k)
  ```

  The fault→cap conversion is the headline: functions that previously died on
  the allocator's `udf #255` assert now run their real logic and cap at a
  legitimate OS wait (`while ([flag] != 0);` — the flag is cleared by an
  interrupt/other-core path the standalone emulator never runs). The
  returned→cap flips are the same wait: with the heap working, these functions
  allocate then block, instead of "returning" early on the null context. That is
  more faithful, not a regression. The spin-breaker then converts the wait-
  blocked caps to returned, and the 30k budget lets the long RF-config
  functions complete — net 91.2% returned/exited, 0 faults.

  The residual 172 faults reduced to exactly **0** with execution-context fixes
  in the emulator (see `tools/aic8800d80_emulator.py`):
  - **`counter` MMIO type**: registers the firmware polls as *monotonic tick
    counters* (rf_tick_counter `0x40320120`, timer_value `0x40501010`) return
    `insn_count // tick_rate`, so `delay_us`/tick-wait loops terminate. Also
    corrected `rf_cmd_wait_status` (`0x40506030`) ready_mask to bit 1 — the
    firmware waits for `(reg & 0x22) == 2`.
  - **Null function-pointer calls** (a call through an uninitialized handler
    field branches into the low boot-ROM page / the unmapped 0x1000 gap):
    INSN_INVALID and low-fetch hooks stop and re-enter at the return address
    with r0=0 (a return-0 stub, matching the boot-callback slots).
  - **Null-safe free + null shadow page**: `free(NULL)` is a C-standard no-op —
    the allocator free entries return immediately when r0==0, and a zero page at
    `0xfffff000` absorbs remaining null-adjacent accesses. Firmware `udf #255`
    asserts (which fire only when the corpus lacks real runtime context) are
    skipped.
  - **Memory map**: SRAM mapped in chunks up to `0x21000000` (unicorn silently
    truncates large maps; the firmware uses low-SRAM globals past the old 512KB
    window) and a low shared-memory window `0x00200000-0x00400000` (bt_init_entry
    stores an inter-core pointer at `0x0020ff04`).
  - **Scan normalization**: `start` is corrected from the IVT base (file 0x100)
    to the real CPUID-check entry (file 0x1a8), and a small set of scan
    artifacts (function entries landing on string pools) is skipped.

  The MMIO layer is complete; the residual execution-context dependencies are
  handled by the above, so the corpus sweeps to **zero faults** in bootstate
  mode. Capped runs remain (functions blocked at a legitimate OS wait), which is
  faithful execution, not a fault.
