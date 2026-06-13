# ke Subsystem

<think>
The user wants me to stop using tools and output my final answer. They asked for a markdown document. Let me write it based on what I've gathered.
</think>
```markdown
# ke Subsystem

## Overview
The `ke` (kernel environment) subsystem provides the firmware's core inter-task messaging and dispatch infrastructure, supplemented by small auxiliary utilities covering cryptographic table bootstrap, LMAC inter-core command/ACK synchronization, log buffer recycling, and diagnostic state dumps. The two `ke_msg_dispatch*` functions form the heart of the subsystem: they pop pending messages from a kernel queue and route them to the appropriate task or node handler, while the remaining helpers supply supporting glue (crypto init, debug dumps) and a synchronous mailbox path to the LMAC core. Together they implement the message-passing backbone that lets tasks in the FullMAC firmware communicate asynchronously and across the HMAC↔LMAC boundary.

## Major Function Groups

**Kernel message dispatch (core)**
- `ke_msg_dispatch` — generic per-iteration pop: reads the next pending message from the kernel environment queue, decrements the pending counter, parses the message header, and dispatches to the registered handler.
- `ke_msg_dispatch_nd8` — node/task 8 specialization of the same logic, additionally clearing status flags and snapshotting a debug trace before dispatching.

**Crypto support (auxiliary)**
- `crypto_table_init` — one-shot initialization of the cryptographic algorithm lookup table (invoked at boot from the synth init path).
- `crypto_iq_calculate` — I/Q sample/coefficient helper used by crypto / signal-processing paths.
- `crypto_state_dump` — debug-only dump of crypto + kernel-environment state (called from the `behavioral_crypto_state_dump` harness).

**LMAC inter-core bridge**
- `patch_send_cmd_to_lmac_sync` — synchronous command submission to the LMAC: writes a command into a shared mailbox, triggers the NVIC software interrupt on the LMAC core, then busy-waits/poll-loops for the ACK to return over the same shared mailbox.

**Log infrastructure**
- `log_free_pool_dispatch2_n3f0` — returns freed log-pool buffers to the consumer side, completing the producer/consumer handshake for the logging ring.

## Key Data Flow
1. Producers (HW events, peer tasks, LMAC) enqueue a message + handler descriptor into the kernel environment queue and bump the pending count.
2. On each scheduling tick, `ke_msg_dispatch` (or its `nd8` variant for node 8) reads the head entry, validates the header, decrements the pending count, clears per-task status, and invokes the registered handler — for `nd8` it also captures a debug snapshot before the call.
3. Cross-core traffic destined for LMAC goes through `patch_send_cmd_to_lmac_sync`: the message is staged into a shared mailbox, an NVIC sw-IRQ wakes LMAC, and the caller spins until the ACK echoes back through the mailbox.
4. Auxiliary flows run in parallel: `crypto_table_init` seeds the algorithm table at boot; `log_free_pool_dispatch2_n3f0` re-injects freed log buffers so the logger never starves; `crypto_iq_calculate` and `crypto_state_dump` serve the crypto path and post-mortem diagnostics respectively.

## Notable Patterns
- **Specialized dispatchers per node**: rather than a fully generic dispatcher with an indirect node index, the firmware open-codes `ke_msg_dispatch_nd8` for hot-path node 8, trading code size for fewer indirections and the ability to inline debug snapshotting.
- **Snapshot-before-handler pattern**: `ke_msg_dispatch_nd8` clears state flags and captures a debug trace prior to invoking the handler, ensuring the trace reflects pre-handler state even if the handler mutates shared variables.
- **Synchronous mailbox + NVIC sw-IRQ handshake**: `patch_send_cmd_to_lmac_sync` is the canonical cross-core sync primitive — write mailbox, fire sw-IRQ, spin on ACK — used wherever HMAC must block on an LMAC reply.
- **Boot-time table seeding**: `crypto_table_init` is called directly from a synth-init C wrapper (`255_crypto_table_init.synth.c`), signaling a static, one-time table populated from constant data.
- **Test/diagnostic hooks**: `crypto_state_dump` is wired into a `behavioral_*` test harness, indicating it is used for validation/debug builds rather than production runtime.
```

The system reminder about the current date doesn't apply to the documentation task and shouldn't be acknowledged.
