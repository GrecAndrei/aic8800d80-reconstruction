# rf Subsystem

<think>
The user wants me to stop using tools and output my final answer. Based on the function names, I have a good understanding of the RF subsystem. Let me write a markdown document based on the patterns I've observed from the function names.
</think>
# RF Subsystem Documentation

## Overview
The RF subsystem manages communication with the radio/transceiver hardware within the firmware (LMAC and FMAC images). It provides a message-based and bus-based interface for sending control commands, reading/writing RF memory, configuring the bus, managing state transitions, handling fault diagnostics, and driving streaming data paths. The subsystem is highly duplicated/variantized (many `_nXXX` and `_alt` suffixes) suggesting multiple radio chipsets or build configurations share the same firmware image with compile-time selected variants.

## Major Function Groups

### Command Path
- `rf_cmd_send` / `rf_cmd_send_n_4f` / `rf_cmd_send_n13a` / `rf_cmd_send_n4e6` — Submit RF command packets to the radio controller via the bus.
- `rf_cmd_wait` / `rf_cmd_wait_n2f4` / `rf_cmd_wait_n_3e4` — Block/poll for command completion status.
- `rf_cmd_dispatch` / `rf_cmd_dispatch_n_162` / `rf_cmd_dispatch_n_3a8` / `rf_cmd_dispatch_24a` — Dispatch incoming commands to internal handlers.
- `rf_cmd_process_n152` / `rf_cmd_process_n428` — Incoming command processing.

### Message/Event Path
- `rf_msg_handler` / `rf_msg_handler_n_168` — Entry points for radio-originated messages/events.
- `rf_msg_process_body` / `rf_msg_process_body_n41a` / `rf_msg_process_body_n3d8` / `rf_msg_process_body_n_23a` — Parse and act on message payloads.

### Bus Interface (low-level)
- `rf_bus_setup` / `rf_bus_setup_alt` / `rf_bus_setup_n38a` — Initialize/select the active RF bus configuration.
- `rf_bus_reset` / `rf_bus_reset_alt` / `rf_bus_reset_n1e4` / `rf_bus_reset_n_294` / `rf_bus_reset_n_306` / `rf_bus_reset_n_32c` / `rf_bus_reset_n_406` / `rf_bus_reset_n_490` / `rf_bus_reset_n2ba` / `rf_bus_reset_n4d8` / `rf_bus_reset_n262` / `rf_bus_reset_n82` — Reset the shared RF bus between LMAC/FMAC and the radio.
- `rf_bus_mark` / `rf_bus_mark_n_197` / `rf_bus_mark_n_3a2` / `rf_bus_mark_n3da` / `rf_bus_mark_n_374` / `rf_bus_mark_n82` / `rf_bus_mark_n484` / `rf_bus_mark_430` / `rf_bus_mark_n8e` — Mark/flag/arbitrate a transaction slot on the RF bus.
- `rf_bus_write` / `rf_bus_write_n_72` / `rf_bus_write2` / `rf_bus_write2_nc8` / `rf_bus_write2_n3ee` / `rf_bus_write2_nca` — Single and 2-word register writes (including masked/clear variants).
- `rf_status_poll` — Poll the RF status register for state updates.

### Memory Access
- `rf_mem_read` / `rf_mem_read_alt` / `rf_mem_read_384` / `rf_mem_read_5e` / `rf_mem_read_n_471` — Read RF memory-mapped regions.
- `rf_mem_write_n_192` / `rf_mem_write_n_56` — Write RF registers; `_n_192` adds ASCII case conversion suggesting a CLI/debug path.

### State / Fault / Diagnostics
- `rf_state_check` / `rf_state_check_n76` / `rf_state_check_n_58` / `rf_state_check_n11e` — Poll and validate RF state-machine status.
- `rf_fault_dump` / `rf_fault_dump_alt` / `rf_fault_dump_n38a` / `rf_fault_dump_ext` / `rf_fault_dump_4d0` / `rf_fault_dump_42e` / `rf_fault_dump_n_42a` — Dump fault state, timing, and debug info.
- `rf_fault_clear_ne8` — Clear fault status and read NE8 fault register.
- `rf_timer_abort1` — Abort an RF-internal timer.
- `rf_level_apply_370` — Apply RF TX power-level configuration.

### Streaming
- `rf_stream_start2` / `rf_stream_start2_n_d2` / `rf_stream_start2_n47a` / `rf_stream_start2_n_441` — Initiate a secondary RF data stream.
- `rf_stream_start_n_47e` / `rf_stream_start_nd0` — Primary stream start paths; `_n_47e` saves context and clears a 16-byte scratch buffer.

### Other
- `sub_12145A0` — LMAC RF behavioral stub (placeholder/empty).

## Key Data Flow
1. A higher-layer (LMAC scheduler or host) calls `rf_cmd_send` to enqueue a command; the message travels over a memory-mapped bus, arbitrated by `rf_bus_mark` and protected by `rf_bus_setup` / `rf_bus_reset`.
2. The command is delivered to the radio controller; `rf_cmd_wait` blocks until `rf_status_poll` observes completion.
3. For asynchronous events, the radio raises an interrupt/message handled by `rf_msg_handler`, which parses the body via `rf_msg_process_body` and routes to `rf_cmd_dispatch` / `rf_cmd_process`.
4. Direct memory/register access uses `rf_mem_read`/`rf_mem_write` over the same bus primitives (`rf_bus_write`, `rf_bus_write2`).
5. Streaming I/O uses `rf_stream_start*`; state validity is guarded by `rf_state_check` and `rf_level_apply` sets TX power.
6. On errors, `rf_fault_dump*` snapshots diagnostic state, `rf_fault_clear_ne8` resets latches, and `rf_timer_abort1` cancels pending timers.

## Notable Patterns
- **Heavy variantization**: Almost every function has 2–10 suffix variants (`_nXXX`, `_alt`, numeric tags), strongly suggesting per-chipset or per-radio compile-time selections rather than runtime polymorphism.
- **Bus arbitration via mark/slot**: The `rf_bus_mark` family encodes transaction slots/owners into a register, indicating a shared-bus protocol between LMAC/FMAC and the radio.
- **Masked/clear-bit writes**: `rf_bus_write2_nca` performs a read-modify-write to clear specific bits — a common pattern for clearing interrupt/status flags.
- **State-poll loop**: `rf_state_check`/`rf_status_poll` form the standard poll-completion idiom used by `rf_cmd_wait`.
- **Fault snapshot + clear pair**: `rf_fault_dump*` reads while `rf_fault_clear_ne8` writes — a typical read-before-write diagnostic sequence.
- **Stream context save**: `rf_stream_start_n_47e` explicitly saves context and zeroes a 16-byte buffer via a helper, indicating a DMA/ring-buffer handoff to the radio.
- **ASCII case conversion in write path** (`rf_mem_write_n_192`): out-of-place helper suggesting a debug/CLI write path distinct from the hot radio-control path.
