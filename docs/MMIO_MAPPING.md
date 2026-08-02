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
binaries) is also emitted for extending coverage.

### 2b. LLM classify — `tools/mmio_classify.py`

Reuses the v17 oracle (`harness_v17/oracle.py::call_api`, DeepSeek via the
OpenAI SDK). Registers are grouped by page (chunks of ~32) and the LLM is
given the full evidence per register. It returns per register:
`name`, `role` (config/status/strobe/mask/irq/data/clock/unknown),
`confidence` (0..1), `behavior`, and optional `fields` (bit -> meaning).

Address safety is enforced: every address in the LLM output must be verbatim
from the batch evidence; invented addresses reject the batch.

Output: `build/mmio/classifications.jsonl` (+ merged `.json`), resumable.

Example classifications the model produced:
- `0x40032020` (polled 60× in boot, always returned 0) -> `poll, ready_mask 0x1`
- `0x4003505c` (rf_reg_write_wait polls it 3,392×) -> `poll, ready_mask 0x1`
- `0x40032000` -> `data` (write-only command/data register)

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

### 2d. Emulator integration

`Aic8800D80Platform` loads the behavior model. Values are injected via the
**pre-read** `UC_HOOK_MEM_READ` hook (verified: rewriting memory in the hook
changes the value the load sees). Writes re-arm a poll register (read counter
reset) and start a strobe window. Absent the model file, the emulator behaves
identically to before.

## 3. Effect on verification

Re-running the original-side fingerprints under M4 (before the behavior model
was ready):

| metric               | old (M3, depth-0 broken) | new (M4, depth-0 fixed) |
|----------------------|--------------------------|--------------------------|
| verify returned      | 18 / 25                  | 20 / 25                  |
| verify faulted       | 6                        | 2                        |
| compare mean Jaccard | 0.52                     | 0.667                    |
| compare matched      | 8                        | 8                        |
| recon-missing        | 7                        | 4                        |

The remaining 2 faults are `rf_reg_write_wait` run standalone (it jumps
through a null context pointer — a caller-state dependency, not a CPU or MMIO
issue). The behavior model's poll rules primarily change *boot* fidelity and
any target that polls a modeled register while running in caller context.
