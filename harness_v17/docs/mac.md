# mac Subsystem

<think>
The user is asking me to stop using tools and output my final answer. They want a markdown document, not JSON. The original system prompt asked for markdown. Let me provide the markdown document based on what I know about the MAC subsystem from the function names and descriptions.
</think>
```markdown
# MAC Subsystem

## Overview
The MAC subsystem implements the lower-MAC/firmware-MAC layer of a Wi-Fi SoC (NXP/Freescale 88W8800-style / "FMAC"), bridging the host driver and the on-chip LMAC hardware. It handles host I/O framing (SDIO/USB), message dispatch from the host and from LMAC interrupts, A-MPDU aggregation/reordering on the RX side, AP manager (APM) state including DFS channel-availability-check (CAC), and low-level RF/MAC status polling. A rich set of SDIO buffer-preparation variants encode the many controller/tx-rx/direction permutations used by the DMA engine.

## Major Function Groups

### Main loop and dispatch
- `fmac_main_loop` — top-level firmware processing loop
- `fmac_irq_handler_n0b7c` — top-level FMAC interrupt entry
- `msg_dispatch_handler` — dispatches incoming host messages to MAC sub-handlers
- `message_dispatch_n_26e`, `message_dispatch_n_49f`, `message_dispatch_n45a`, `message_dispatch_n_45e` — secondary dispatch paths indexed by message type/offset
- `fmac_misc_handler`, `fmac_subhandler_n_05b4` — catch-all and indexed sub-handlers

### A-MPDU aggregation / reorder (RX)
- `mac_agg_process` — A-MPDU aggregation processing
- `mac_ampdu_agg` — A-MPDU aggregation handler
- `mac_rx_reorder` — RX reorder buffer / per-TID reordering

### AP Manager (APM) / DFS CAC
- `apm_bss_config_init` — initializes the APM BSS configuration structure
- `apm_start_cac_req_handler` — start channel-availability-check
- `apm_stop_cac_req_handler` — stop channel-availability-check

### Host I/O — SDIO
- `sdio_transfer` — performs SDIO data transfer to the host
- `sdio_buffer_prepare`, `sdio_buffer_prepare_n*`, `sdio_buffer_prepare_n_*` (many variants: `n76`, `n188`, `n198`, `n25c`, `n286`, `n2xx`, `n1cb`, `n1cb2`, `n388`, `n3c6`, `n38`, `n41e`, `n48`, `na2`, `n_8a`, `n_100`, `n_1ac`, `n_1be`, `n_378`, `n_398`, `n_3ae`, `n_41c`, `n_434`, `n_4e6`) — DMA buffer descriptor preparation for SDIO host transfers
- `sdio_buffer_prepare_tx`, `sdio_buffer_prepare_rx` — direction-specific variants
- `sdio_buf_prepare_68`, `sdio_buf_prepare_ac` — BT-path / special-purpose variants

### Host I/O — USB
- `usb_init` — initializes the USB host/device interface (prints "usb init done" on success)

### MAC / HW messaging
- `mac_msg_post_4ff` — builds a message via the KE helper and posts opcode `0x4FF` to MAC HW register `REG_4032_00a0`
- `rf_state_check_n300` — checks RF state and updates status / MAC mailbox registers

### Interrupt / vector setup
- `lmac_interrupt_init` — installs LMAC interrupt and exception handlers into the vector table and enables their NVIC lines

### Boot / patching
- `patch_apply_n116` — installs handler function pointers into a function-pointer table and clears boot-status bits (early-boot patch)

## Key Data Flow
1. **Boot**: `patch_apply_n116` runs early to install handler pointers and clear boot status bits. `lmac_interrupt_init` wires the LMAC IRQ/exception vectors and enables NVIC lines.
2. **Host attach**: Depending on the bus variant, `usb_init` or the SDIO bring-up code runs once, then `fmac_main_loop` begins its steady-state loop.
3. **Host → firmware**: A host message arrives (SDIO/USB), `msg_dispatch_handler` parses the header and routes to one of the `message_dispatch_n*` paths or to the indexed sub-handlers (`fmac_subhandler_n_05b4`, `fmac_misc_handler`).
4. **LMAC → firmware**: `fmac_irq_handler_n0b7c` services LMAC interrupts, then re-enters the same dispatch fabric for LMAC-originated messages. `mac_msg_post_4ff` is the companion TX path that posts a message to the MAC HW mailbox.
5. **RX data plane**: LMAC delivers aggregated frames; `mac_agg_process` / `mac_ampdu_agg` handle A-MPDU parsing, and `mac_rx_reorder` reorders subframes per TID before handing them up.
6. **AP / DFS control**: Host requests targeting BSS or DFS CAC reach `apm_bss_config_init` (init) and `apm_start_cac_req_handler` / `apm_stop_cac_req_handler` (runtime).
7. **Host I/O DMA**: Whenever data is handed to the host bus, the appropriate `sdio_buffer_prepare*` variant validates a descriptor's state byte and primes the scatter-gather register block (e.g., the `n25c` variant primes `0x2007ff0c`–`0x2007ff74`); `sdio_transfer` then triggers the actual DMA.
8. **Status polling**: `rf_state_check_n300` periodically reads RF state and writes status / MAC mailbox registers so the host can poll for changes.

## Notable Patterns
- **Heavy duplication of `sdio_buffer_prepare`**: ~30+ near-identical variants differ only in address/size shift constants, descriptor-state byte, or DMA-controller register block. This is typical of code generated from a macro/template per (controller, direction, alignment) tuple.
- **Multiple message dispatchers**: Four distinct `message_dispatch_n*` functions split the message table by opcode range (e.g., one indexes by `0xC5` offset, another loads a field from the msg struct) — a common pattern when the firmware supports several host protocol revisions.
- **Handler-table patching**: `patch_apply_n116` writes function pointers into a table and clears boot status — a tell-tale sign of a base image that is patched in-field for product variants.
- **Direction-suffixed helpers**: `sdio_buffer_prepare_tx` / `_rx` and `sdio_buf_prepare_68` (BT) suggest the SDIO path is shared between Wi-Fi TX, Wi-Fi RX, and Bluetooth coexistence.
- **Mailbox/HW register coupling**: `mac_msg_post_4ff` posts directly to a named MAC HW register (`REG_4032_00a0`) using a KE (kernel-event) helper to build the message, showing the standard "build in RAM, then poke HW register to trigger" idiom.
- **CAC handlers are symmetric**: `apm_start_cac_req_handler` and `apm_stop_cac_req_handler` form the standard start/stop pair for DFS radar-detection channel availability checks, with `apm_bss_config_init` providing the per-BSS state they read/modify.
- **Interrupt wiring is centralized**: `lmac_interrupt_init` is the only place that touches the vector table and NVIC, keeping the rest of the MAC code ISR-agnostic.
```
