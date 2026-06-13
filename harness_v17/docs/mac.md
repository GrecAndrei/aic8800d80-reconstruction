# mac Subsystem

<think>
The user wants me to stop using tools and provide the final answer based on what I've gathered. I have the function list and descriptions from the original prompt. Let me write the markdown document based on what I know about the subsystem from the function names and descriptions provided.

The subsystem is "mac" and contains functions related to:
- SDIO buffer preparation (many variants for different transfer paths)
- FMAC main loop and IRQ handler
- MAC message dispatching
- MAC aggregation (A-MPDU)
- MAC RX reorder
- APM (AP Manager) handlers
- USB init
- LMAC interrupt init
- Patch apply
- RF state check
- Various message dispatchers

Let me write the markdown document.
</think>
# MAC Subsystem

## Overview

The `mac` subsystem is the host-to-MAC bridge layer of a Wi-Fi (802.11) firmware image, exposing host-facing control via SDIO/USB DMA and dispatching MAC management messages into the lower MAC (LMAC) and AP Manager (APM) engines. It owns the SDIO scatter-gather buffer preparation pipeline (the dominant function count in this subsystem), the host message dispatch and post paths, A-MPDU aggregation/reorder processing on the data path, RF state coordination, and CAC (Channel Availability Check) request handling for DFS channels. The subsystem is anchored by a polling `fmac_main_loop`, an interrupt entry `fmac_irq_handler`, and a vector of `message_dispatch_n*` and `fmac_subhandler_n*` entry points that fan messages out by opcode/offset to per-handler implementations.

## Major Function Groups

- **SDIO Host I/O Buffer Preparation** — A very large family of `sdio_buffer_prepare*` / `sdio_buf_prepare*` routines (TX, RX, generic, BT-path, byte-shifted, comparison-based, descriptor-priming variants for the n25c/n1cb/n_1ac/n_4e6/n_434/n_378/etc. controllers). These compute address/size shifts, validate state bytes, and prime the scatter-gather register block for inbound/outbound DMA.
- **FMAC Control / Dispatch** — `fmac_main_loop` (idle/poll loop), `fmac_irq_handler_n0b7c` (interrupt entry), `fmac_misc_handler`, `fmac_subhandler_n_05b4` (sub-handler dispatcher), `msg_dispatch_handler` (host message fan-out).
- **Message Post / Dispatch** — `message_dispatch_n_49f`, `message_dispatch_n_26e`, `message_dispatch_n45a`, `message_dispatch_n_45e`, `mac_msg_post_4ff` (posts opcode `0x4ff` to the MAC hardware register `REG_4032_00a0`).
- **MAC Data Path** — `mac_agg_process` and `mac_ampdu_agg` (A-MPDU aggregation), `mac_rx_reorder` (RX reorder buffer handler).
- **AP Manager (APM)** — `apm_start_cac_req_handler`, `apm_stop_cac_req_handler`, `apm_bss_config_init` (DFS CAC and BSS config).
- **LMAC / Vector Plumbing** — `lmac_interrupt_init` (installs LMAC handlers into the vector table and enables NVIC lines), `patch_apply_n116` (installs handler function pointers and clears boot status bits), `rf_state_check_n300` (RF state → MAC mailbox registers).
- **Host Interface Init** — `usb_init` (USB host/device bring-up, prints `usb init done` on success).

## Key Data Flow

1. The host writes messages over SDIO/USB; `sdio_buffer_prepare*` variants compute DMA addresses/sizes and prime the SG descriptor block for the transfer.
2. `sdio_transfer` performs the actual DMA, populating the host message struct in shared RAM.
3. `fmac_irq_handler_n0b7c` fires on completion, handing off to `msg_dispatch_handler`, which uses `message_dispatch_n*` (indexed by an offset/0xc5, by msg-struct field, or by type) to route the message to the correct sub-handler (`fmac_subhandler_n_05b4`, `fmac_misc_handler`, APM handlers, etc.).
4. Outbound MAC operations are posted via `mac_msg_post_4ff` to the MAC hardware register, and via `message_dispatch_n*` for local processing.
5. On the data path, A-MPDU aggregation (`mac_agg_process` / `mac_ampdu_agg`) builds aggregates that are then DMA'd to the host through the same `sdio_buffer_prepare_tx` / `sdio_transfer` path; incoming aggregates are reassembled by `mac_rx_reorder` before being pushed back over SDIO via `sdio_buffer_prepare_rx`.
6. RF/CAC state changes flow through `rf_state_check_n300` and the `apm_*_cac_req_handler` pair, writing into the MAC mailbox registers.
7. `patch_apply_n116` and `lmac_interrupt_init` are one-shot boot-time routines that wire handlers into the vector table and clear boot status bits.

## Notable Patterns

- **Massive SDIO buffer-prepare duplication.** More than 25 of the 54 functions are SDIO buffer-prepare variants. Naming suffixes (`_n1cb2`, `_n76`, `_n286`, `_n_1ac`, `_n48`, `_n3c6`, `_n_1be`, `_n38`, `_n_41c`, `_n25c`, `_n41e`, `_n_4e6`, `_n_3ae`, `_n_434`, `_n_100`, `_n_8a`, `_n198`, `_n_378`, `_na2`, `_n1cb`, `_n_398`, `_n188`, plus `_tx`/`_rx`/`_68`/`_ac`) suggest compiler/linker duplication of an inlined helper, with the suffix encoding the call-site offset into the caller — a classic inlining-explosion pattern in embedded firmware.
- **Dispatcher-of-dispatchers.** The `fmac_main_loop` / `fmac_irq_handler` → `msg_dispatch_handler` → `message_dispatch_n*` / `fmac_subhandler_n*` chain is multi-layered; messages are indexed by both an offset into the message struct (e.g. `0xc5`) and by opcode, and several near-duplicate dispatchers exist (`_n_49f`, `_n_26e`, `_n45a`, `_n_45e`).
- **Direct MMIO / magic-register post.** `mac_msg_post_4ff` posts opcode `0x4ff` straight to a named hardware register `REG_4032_00a0`, indicating a hand-rolled IPC to the MAC engine rather than a queued OS primitive.
- **State-byte validation on the SDIO path.** Multiple `sdio_buffer_prepare*` variants open by reading a "state byte" on the descriptor before priming SG registers (e.g. `n25c` checks the descriptor state byte and primes `0x2007ff0c`–`0x2007ff74`), a producer/consumer handshake pattern for host ↔ FW shared descriptors.
- **Boot-time vector table surgery.** `lmac_interrupt_init` and `patch_apply_n116` both install function pointers into a vector table and clear boot status bits — characteristic of a firmware that self-patches/relocates its IVT during init.
- **DFS/CAC split.** CAC start and stop are separate handlers (`apm_start_cac_req_handler`, `apm_stop_cac_req_handler`) with a dedicated `apm_bss_config_init` initializer, suggesting CAC is a stateful, two-phase operation tracked by the APM.
- **`usb_init` co-resident with SDIO code** indicates a dual transport (USB *or* SDIO) host interface selected at build time, even though only SDIO prep is heavily expanded.
