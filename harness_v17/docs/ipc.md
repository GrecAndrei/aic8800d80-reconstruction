# ipc Subsystem

<think>
The user wants me to stop using tools and output the final markdown document based on what I've gathered. Let me write a markdown document explaining the IPC subsystem based on the function names and patterns I've observed.
</think>
# IPC Subsystem

## Overview

The IPC (Inter-Processor Communication) subsystem provides the firmware-side interface for receiving and dispatching messages from the host processor to firmware modules (FMAC, BT, RF, LMAC). It manages a doorbell-based interrupt mechanism where the host signals the firmware by writing to a shared register, and the firmware reads incoming messages from shared mailbox/ring buffers before dispatching them to registered per-message-id handlers. The subsystem also includes SDIO DMA buffer preparation to support the host transport, with several message dispatch variants tailored to specific firmware images (fmacfw, fmacfwbt, fmacbt, lmacfw) and execution contexts (NVIC-driven ISRs vs. polled/thread-mode dispatch).

## Major Function Groups

- **Doorbell / Interrupt Handlers** — `ipc_doorbell_handler` and its many suffixed variants (`_n_15`, `_n_64`, `_n3ec`, `_n424`, `_n_341`, `_n_3e2`, `_n_486`, `_n_d0`, `_n43e`, `_n3c6`, `_n4a6`, `_n2ca`, `_n1f4`, `_n_33f`, `_n_5e`, `_n_3ca`, `_n41e`, `_n4a6`, `_alt`, variant `2ea`, etc.). These run on the IPC interrupt, acknowledge the host doorbell, and trigger message processing.

- **Message Dispatchers** — `message_dispatch` and its large family (`_n2da`, `_n_4e4`, `_nea`, `_n_3c0`, `_408`, `_n41c`, `_n178`, `_n3ba`, `_n1d0`, `_n_4cc`, `_n1da`, `_n2b0`, `_n_1ee`, `_n_272`, `_nd4`, `_n_4eb`, `_n_4df`, `_n_16e`, `_n252`, `_38e`, `_n480`, `_n466`, `_n4f6`, `_n3f4`, `_n1b4`, `_n4e3`, `_n3d0`, `_n462`, `_n334`, `_n2dc`, `_n1ca`, `_nd8`, `_n_370`, `_n4c`, `_n_50`, `_n264`, `_n2b6`, `_n_420`, `_n_466`, `_n_2f6`, `_n29e`, `_n485`, `_n_296`, `_n60`, `_n_416`, `_n180`, `_n4c3`, `_secondary`, `_alt`, `_helper`). These perform type/opcode decoding and route messages to handler functions, often via a jump table or index lookup.

- **Module-Specific Message Handlers** — `fmac_msg_handler` (FMAC), `rf_msg_handler` / `rf_msg_handler_n290` (RF control), `rf_msg_process_body_nd8` (RF body parser), `message_dispatch_bt` (Bluetooth), `ipc_msg_dispatch` (generic IPC).

- **Host Transport / DMA** — `sdio_buffer_prepare` (and its variant `_n388`, `_n97`) prepare SDIO DMA buffers for host-firmware data transfer.

- **Central / Critical-Path Dispatchers** — `message_dispatch_n480` and `message_dispatch_n60` are flagged as critical-path / critical-priority entry points. `message_dispatch_helper` supports inner-loop dispatch.

## Key Data Flow

The host writes a doorbell value to a shared MMIO register, which raises an IPC interrupt on the firmware. The doorbell handler enters first, reads/clears the pending status, and then invokes a message dispatcher. The dispatcher reads the next message descriptor from a shared mailbox or ring buffer in host-accessible memory, extracting an opcode/message-id and (in some variants) a length/offset field. A header-sanity check (e.g., signed-header validation) may gate the dispatch. The opcode is used to index a handler table, and the message body is forwarded to the selected per-module handler (FMAC, BT, RF, LMAC). The RF handler may further parse the body and re-dispatch internally. Outbound paths use `sdio_buffer_prepare` to stage DMA buffers for the host transport, and ack/status writes are written back to the host doorbell/status register (e.g., the `_n_486` variant writes a status byte). Multiple dispatcher variants exist for the different images because the message-id spaces, ring-buffer layouts, and handler tables differ between fmacfw, fmacfwbt, fmacbt, and lmacfw.

## Notable Patterns

- **Heavy variant proliferation** — nearly every public function in the subsystem has multiple offset-suffixed copies across firmware images; this strongly suggests the same dispatch logic is re-instantiated per build configuration (fmac/fmacbt/fmacbt-lmac/etc.), likely with different opcode tables, ring layouts, or interrupt routing.

- **Doorbell-driven entry** — the IPC interrupt is the single entry point; the doorbell handler is the only caller of the dispatcher in the ISR path. Several variants differ only in how they read the doorbell (direct MMIO read vs. NVIC pending register), and one variant (`_n_5e`) explicitly compares the host doorbell value against `0x60` to decide on routing.

- **Index/opcode-table dispatch** — dispatchers use opcode or index lookup (sometimes via subtraction of a base offset, as in `_n_16e`) to jump to the correct handler, a classic jump-table pattern.

- **Header/format validation** — variants such as `message_dispatch_n1b4` perform a signed-header check before dispatching, indicating messages carry a validity marker.

- **Split between ISR context and polled context** — the `message_dispatch` / `_central` / `_n480` / `_n60` entries suggest both interrupt-context dispatch and a central polled loop share the same dispatch core via `message_dispatch_helper`.

- **Ack/status handshake** — the `ipc_doorbell_handler_n_486` variant writes a status byte back to the host as part of the handshake, completing the request/response cycle.

- **SDIO coupling** — the presence of `sdio_buffer_prepare` inside the IPC group indicates that, on this transport, buffer staging is part of the IPC receive path.
