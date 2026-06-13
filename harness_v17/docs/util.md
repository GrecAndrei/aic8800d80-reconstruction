# util Subsystem

<think>
I have enough information from the function names and their grouping to write the documentation. Let me compose the markdown. The subsystem "util" is a heterogeneous collection of utility routines, but it breaks down into recognizable groups:

1. SDIO buffer preparation (many variants) - for host I/O
2. Log buffer management - the bulk of functions
3. Logging infrastructure
4. IRQ/Interrupt control
5. Init/Boot
6. Timer
7. Crypto
8. Misc helpers (chip ID, list, queue, panic, etc.)

Key patterns:
- Many variants of similar dispatch functions (n4XX, n_XXX suffixes indicating different entry offsets)
- Some functions exist across multiple firmware images (fmac/lmac/bt)
- SDIO prepare has many variants, some handling cached/non-cached DMA
- Log free dispatch has a primary path + secondary "pool2" path
- Init functions are called from a startup sequence (fw_init_entry, subsystem_init_helper)
- Some helpers appear to be stubs that just save LR and dispatch

Let me write this up.
</think>
# util subsystem

## Overview

The `util` subsystem is a heterogeneous collection of firmware service routines that together implement the low-level housekeeping functions of the WiFi/BT/Combo SoC firmware: bringing up the core (interrupt controller, timers, crypto, chip-revision detection, panic handler), formatting log records and recycling their buffers back to the host over SDIO, and preparing SDIO DMA buffers for every kind of host-facing transfer. It is the "glue" layer that sits below the MAC/Modem state machines and above the bare MMIO/CSR layer. The function set exists in three parallel compilations (`fmacfw`, `lmacfw`, `fmacfwbt`) of the same chip image — most routines have multiple address-shifted variants (e.g. `…_n4ba`, `…_n_1ca`, `…_nac`) representing different entry points or inlining contexts of the same logical routine.

## Major function groups

### SDIO host-buffer preparation (largest group)
A family of `sdio_buffer_prepare*` and `sdio_buffer_prepare_alt*` routines. They build DMA descriptors / scatter-gather entries for SDIO host transfers, handling alignment, length, cached-vs-non-cached mapping, and index shifting (`…_nb4` performs an explicit shifted-index computation; `…_n2c2` handles the non-cached→cached case). Variants exist for the LMAC and FMAC paths and for alt paths.

### Log buffer free/dispatch (second largest group)
- `log_free_dispatch` and its many offset variants — recycle a single freed log entry.
- `log_free_pool_dispatch` / `log_free_pool_dispatch2` — drain/return entries to the primary and secondary log free-pools.
- `log_buffer_dispatch` / `log_pool_dispatch_462` — bulk dispatch of multiple freed entries to log sinks (host SDIO path, ring buffers).
- These are paired: one path services the LMAC producer, the other services the FMAC/BT producer.

### Logging infrastructure
- `log_hw_init` — initialise the hardware logger block.
- `log_alloc` — log a memory-allocation event.
- `timestamp_remove` — strip the timestamp field from a log message before forwarding it.

### Interrupt controller
- `irq_config` — configure interrupt lines/groups.
- `irq_prio_set` — set an NVIC priority with a bounds check.
- `irq_enable` — globally enable IRQs.
- `irq_mask_test` — sanity check the IRQ mask register.

### Init / boot
- `fw_init_entry` — top-of-reset entry, called from the boot vector.
- `subsystem_init_helper` — generic step-driver that initialises one subsystem at a time.
- `fmac_init_step` — FMAC-specific initialisation step.
- `fmac_state_check_nbf4` — tests an FMAC state flag and dispatches accordingly.
- `fmac_misc_handler`, `fmac_sub_2315c`, `sub_1201A58` — miscellaneous FMAC service routines.
- `sub_121B680` — init/state probe that compares a flag byte against constant 3.

### Timer
- `timer_init` — set up the firmware tick / hardware timer block.

### Crypto
- `crypto_hw_reset_seq` — issue the documented crypto-engine reset sequence (assert/deassert/flush).

### Chip identity / version
- `chip_rev_id_get` — read the chip revision register and return `(val & 0xf) - 1`.

### Data structures helpers
- `list_count` — count elements in a singly- or doubly-linked list.
- `queue_process` — drain and process pending entries from a work queue.

### Fault / panic
- `panic_entry` — the system fault/panic entry point; typically halts the core after capturing diagnostics.

### Generic helpers
- `sub_12178DE`, `sub_121E604`, `sub_122829C`, `sub_12392A8`, `sub_1236504`, `util_sub_f0b4` — small un-instrumented utility stubs: save `r0..r3, lr`, look up a value in a global pointer table (`sub_1236504` explicitly loads a signed halfword from a global table), or forward to a dispatcher. They serve as the named dispatchers referenced by jump tables and inline glue code.

## Key data flow

1. **Boot** — on reset, the vector table jumps to `fw_init_entry`, which calls `subsystem_init_helper` to step through initialisation: `chip_rev_id_get` is consulted for revision-dependent behaviour, `irq_config` and `irq_prio_set` set up the NVIC, `timer_init` brings up the tick source, `log_hw_init` brings up the logger, and `crypto_hw_reset_seq` is issued to put the crypto engine in a known state.
2. **Steady state** — on each interrupt, an IRQ handler dequeues work; `queue_process` walks the work-queue and calls subsystem handlers. Producers (LMAC, FMAC, BT) push completed log records into per-producer log buffers.
3. **Log drain** — when a producer's log buffer fills, `log_free_dispatch` (or the variant matching the producer) pulls the entry, calls `timestamp_remove` if the host wants a stripped format, and forwards it to the host via `log_buffer_dispatch` / `log_pool_dispatch_462`. Empty slots are returned to the producer through `log_free_pool_dispatch` / `log_free_pool_dispatch2`.
4. **SDIO host I/O** — any host-bound message (logs, command responses, FW→host indications) is handed to one of the `sdio_buffer_prepare*` routines, which copies or maps the payload into a host-visible DMA buffer (handling cached→non-cached flushing and index shifting for ring buffers) and posts the descriptor to the SDIO engine.
5. **Fault** — if a fatal condition is detected, `panic_entry` runs, captures diagnostics via the logger path, and halts the core.

## Notable patterns

- **Per-producer duplication of dispatch chains.** The same `log_free_dispatch` / `log_free_pool_dispatch2` machinery is replicated for LMAC, FMAC, and BT, identified by the `_n4XX` offset suffix and the presence of separate "log_free_dispatch" and "log_free_pool_dispatch2" + "log_free_pool_dispatch2_n3c6" / "…_n3fa" pairs. This is a classic producer/consumer split with one free-pool per producer.
- **Heavy inlining / entry-offset variants.** The `…_n4ba`, `…_n_1ca`, `…_nac`, `…_n_2f6`, `…_n_1e` style suffixes indicate that the same logical routine has multiple entry points corresponding to different inlined call-sites. The compiler/assembler kept the suffixes to preserve the original sub-address. Code reading should treat each variant as the same function with a different prologue.
- **Cached ↔ non-cached DMA bridging.** The SDIO prepare functions explicitly handle the "non-cached-to-cached" case (`sdio_buffer_prepare_n2c2`) and use STM/LDM block copies (`sdio_buffer_prepare`: "Prepares SDIO transfer buffer by copying data via STM/LDM") — typical for ARM Cortex-M cores where DMA buffers must live in a non-cached region.
- **Ring-index shifting.** `sdio_buffer_prepare_nb4` performs an explicit `& (N-1)` style shift on the buffer index, indicating a power-of-two ring of SDIO buffers.
- **Flag-byte state probes.** Several init helpers (`sub_121B680`, `fmac_state_check_nbf4`) read a single byte from an object and compare it against a small constant (3, etc.), a common idiom for "is this state machine in state X" probes.
- **Stub dispatchers.** A handful of `sub_` functions (e.g. `sub_12178DE` — "save args/lr, set r4=r0; dispatcher stub") are intentionally tiny: they save caller-saved state and tail-jump to the real handler, serving as veneers so callers can take a stable address.
- **Boot sequence chaining.** `fw_init_entry` → `subsystem_init_helper` → `fmac_init_step` (with `fmac_misc_handler` and `fmac_sub_2315c` as subsequent stages) is the canonical init ladder, with each step called in order and responsible for one hardware block.
- **Revision gating.** `chip_rev_id_get` returns a small integer (`(val & 0xf) - 1`) used as a switch index by later init steps, which is why the function is always called very early.
- **No public API surface.** None of these functions appear to be exported to the host; the subsystem is purely internal firmware plumbing, and all host-visible effects are indirect (via SDIO-prepared buffers carrying log records or indications).
