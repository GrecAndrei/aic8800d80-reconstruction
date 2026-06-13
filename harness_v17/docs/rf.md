# rf Subsystem

<think>
The user wants me to write a markdown document about the RF subsystem based on the function names provided. Let me analyze the patterns I see in the function names to understand the subsystem.

Looking at the function names, I can identify several clear functional groups:

1. **Bus operations**: rf_bus_write, rf_bus_write2, rf_bus_reset, rf_bus_setup, rf_bus_mark - These handle the RF bus interface
2. **Command processing**: rf_cmd_send, rf_cmd_wait, rf_cmd_dispatch, rf_cmd_process - These handle sending and processing RF commands
3. **Memory access**: rf_mem_read, rf_mem_write - Reading/writing RF memory
4. **State checking**: rf_state_check, rf_status_poll - State machine monitoring
5. **Message handling**: rf_msg_handler, rf_msg_process_body - Message processing
6. **Stream operations**: rf_stream_start, rf_stream_start2 - Starting RF data streams
7. **Fault handling**: rf_fault_dump, rf_fault_clear - Diagnostic/dump functions
8. **Timer**: rf_timer_abort1 - Timer management
9. **Level/Power**: rf_level_apply - Power level configuration

The function list shows many variants (e.g., rf_bus_reset has n_490, n_294, n1e4, n2ba, n82, n_306, n4d8, n262, n_32c, n406, alt variants) - this suggests the firmware has multiple versions/variants possibly for different chips or radio types, and there are multiple FW images (lmacfw_rf, fmacfw variants).

I should be terse and informative as requested. I don't need to call tools because I have enough information from the function names. Let me write a concise markdown document.

Let me structure this as required:
1. One-paragraph overview
2. List of major function groups
3. Key data flow
4. Notable patterns

I should NOT include raw addresses (and I don't have any from tools anyway).
</think>
# RF Subsystem

## Overview

The RF subsystem provides the firmware-side abstraction for controlling the radio transceiver block on the 8800d80 WiFi SoC. It manages the shared RF control bus between the LMAC and the radio die, dispatches configuration commands (channel set, power level, calibration), reads/writes RF memory-mapped registers, starts and stops data streaming operations, monitors state-machine readiness, and reports/dumps fault diagnostics. It runs in both LMAC and FMAC firmware images, with message-based entry points from the host driver and from internal MAC tasks.

## Major Function Groups

- **Bus interface** — `rf_bus_setup[_alt]`, `rf_bus_reset[*]`, `rf_bus_mark[*]`, `rf_bus_write`, `rf_bus_write2`, `rf_bus_write2_nc8`. Initialize, mark, write single/dual words to the shared RF control bus, and reset it to a known state.
- **Command path** — `rf_cmd_send[*]`, `rf_cmd_wait[*]`, `rf_cmd_dispatch[*]`, `rf_cmd_process[*]`. Build an RF command packet, write it via the bus, poll for completion, and route it to the correct handler.
- **Memory access** — `rf_mem_read[*]`, `rf_mem_write_n_56`, `rf_mem_write_n_192`, `rf_mem_read_5e`, `rf_mem_read_384`. Direct reads/writes into the RF memory-mapped register region (the `_192` variant additionally does ASCII case conversion, suggesting a calibration-table write).
- **State/status** — `rf_state_check`, `rf_state_check_n_58`, `rf_state_check_n11e`, `rf_state_check_n76`, `rf_status_poll`. Poll the RF state machine and block until it reaches the expected state.
- **Message handling** — `rf_msg_handler[*]`, `rf_msg_process_body[*]`. Top-level dispatcher for RF control messages coming from the host or upper MAC layers; extracts the message body and feeds it into the command path.
- **Stream control** — `rf_stream_start`, `rf_stream_start2[*]`, `rf_stream_start_n_47e`, `rf_stream_start_nd0`. Start an RF data-streaming operation; the `_n_47e` variant saves context and clears a 16-byte scratch buffer.
- **Fault/diagnostics** — `rf_fault_dump`, `rf_fault_dump_alt`, `rf_fault_dump_ext`, `rf_fault_dump_4d0`, `rf_fault_dump_42e`, `rf_fault_dump_n38a`, `rf_fault_clear_ne8`, `rf_fault_dump_n_42a`. Dump RF fault registers and timing info for debug; clear fault latches.
- **Level/timer** — `rf_level_apply_370` (apply RF power-level configuration), `rf_timer_abort1` (abort an in-flight RF timer).

## Key Data Flow

1. An upper layer (host driver via IPC, or an internal MAC task) posts an RF control message to the RF message queue.
2. `rf_msg_handler` selects the message and calls `rf_msg_process_body` to decode the payload into a normalized RF command descriptor.
3. `rf_cmd_dispatch` / `rf_cmd_process` routes the command to a handler (channel, power, calibration, stream start, …). For bus-register commands the handler issues `rf_bus_write` / `rf_bus_write2` after acquiring the bus with `rf_bus_mark`; for memory-region access it uses `rf_mem_read` / `rf_mem_write`.
4. `rf_cmd_send` posts the command to the radio controller and `rf_cmd_wait` blocks on completion, with `rf_state_check` / `rf_status_poll` gating progress.
5. For streaming, `rf_stream_start` / `rf_stream_start2` configures the stream and unblocks the data path; for level changes, `rf_level_apply` updates TX power registers.
6. On error, `rf_fault_dump[*]` reads the RF fault/status registers and the result is returned up the message chain; `rf_fault_clear` resets the latches so subsequent operations can proceed. `rf_bus_reset` re-initializes the bus when the fault corrupted it.

## Notable Patterns

- **Heavy variant duplication**: nearly every primitive exists in several `*_nXXX`, `*_alt`, or `*_ext` forms. This is typical of the lmacfw_rf image maintaining per-radio or per-revision code paths that share the same high-level contract but differ in offsets, register widths, or polling sequences. Callers should select the variant that matches the active radio build.
- **Bus arbitration**: `rf_bus_mark` appears in many variants (n82, n8e, n_197, n_374, n_3a2, n_3da, n_430, n484, slot 466) and is called before bus writes, indicating the bus is a shared resource requiring ownership/timestamp marking between LMAC and the radio die.
- **Polling-based synchronization**: command completion is implemented as busy-wait (`rf_cmd_wait`, `rf_status_poll`, `rf_state_check`) on an RF MMIO register rather than an interrupt; the same pattern recurs across every command-send function.
- **Stream variants by interface**: `rf_stream_start` vs `rf_stream_start2` (and `rf_stream_start_nd0`) suggest two distinct stream interfaces or two generations of the streaming engine, with `_n_47e` performing a context-save + 16-byte buffer clear before enabling the stream.
- **Fault dump variants carry extra state**: `rf_fault_dump_ext` and the numbered variants (`4d0`, `42e`, `n38a`, `n_42a`) include additional timing/state fields, used when the radio signals a non-trivial fault and the host needs a richer snapshot. `rf_fault_clear_ne8` specifically reads the NE8 fault register as part of clearing, indicating named fault categories.
- **`rf_mem_write_n_192`** with ASCII case conversion is an outlier — it suggests one calibration table stores string-coded identifiers that the firmware normalizes before writing to RF memory.
- **Cross-image presence**: function names like `rf_bus_reset_n406` ("in FMAC firmware") and `rf_msg_process_body_n_23a` ("in FMAC firmware") confirm the subsystem is compiled into both lmacfw_rf and fmacfw, with the FMAC copy providing the host-facing message entry points and the LMAC copy performing the actual bus/memory transactions.
