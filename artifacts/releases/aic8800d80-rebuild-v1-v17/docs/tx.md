# tx Subsystem

<think>
The user wants me to stop using tools and provide the final markdown document based on what I've gathered. Let me write a concise markdown document about the tx subsystem.
</think>
```markdown
# TX Subsystem

## Overview
The TX subsystem manages the firmware transmit path for an 802.11 MAC, encompassing descriptor preparation, DMA queue submission, rate control, completion handling, aggregation setup, and the underlying SDIO buffer plumbing used to ferry TX frames to the host/HW. It bridges the host-side SKB lifecycle to on-chip TX descriptor rings, handles per-VIF queue state, configures PHY rate parameters, and dispatches TX frames through the FMAC. It also includes RF stream start helpers used when opening TX-capable paths and auth-frame state-machine transmission.

## Major Function Groups

### TX Completion / Lifecycle
- `mac_tx_completion_n234` — Handles TX frame completion event (frees descriptors, reports status back up the stack).

### TX Dispatch & Queueing
- `fmac_tx_dispatch` — FMAC transmit path dispatcher; routes frames into the appropriate queue/AC.
- `txq_queue_skb` — Programs a TX DMA descriptor and submits an `skb` to the hardware transmit queue.
- `txq_vif_reset` — Resets/reinitializes the TX descriptor ring and queue state for a given VIF index.
- `tx_queue_flush_n_xxx` — TX queue flush/management utility (drain pending frames).

### Aggregation (TX Layer)
- `txl_agg_he_tb_prep` — Prepares HE TB (Trigger-Based) aggregation descriptor for the TX list.
- `txl_agg_set_uph` — Sets aggregation UPH (user priority / per-head?) parameter in the TX layer.

### Rate / PHY Configuration
- `tx_rate_config` — Configures TX PHY rate parameters (modulation, MCS, NSS, BW, SGI, etc.).

### SDIO Buffer Preparation
- `sdio_buf_prepare_size6` — Prepares an SDIO buffer descriptor of size 6.
- `sdio_buffer_prepare_n1b4` — Prepares SDIO buffer for I/O (variant 0x1b4).
- `sdio_buffer_prepare_nb2` — Prepares SDIO buffer for transmission (variant 0xb2).
- `sdio_buffer_prepare_n_43a` — Prepares SDIO buffer for transfer (variant 0x43a).

### RF Stream Bring-up
- `rf_stream_start2_n3dc` — Start secondary RF data stream (variant 0x3dc).
- `rf_stream_start2_ne6` — Starts an RF TX/RX stream (variant 0xe6).

### Management / Auth
- `sm_auth_send` — State-machine driven transmit of an authentication frame.

## Key Data Flow
1. Host delivers an `skb` (or internal mgmt frame) to the firmware's MAC TX entry point.
2. `fmac_tx_dispatch` classifies the frame (data vs. mgmt, VIF, AC) and selects the right TX queue.
3. For data frames, `txq_queue_skb` allocates/claims a DMA descriptor and programs it with the frame buffer; SDIO buffer-prep helpers build the host-side scatter/gather descriptors needed to DMA the payload across the SDIO bus.
4. Aggregation traffic flows through `txl_agg_he_tb_prep` / `txl_agg_set_uph` to construct AMPDU/HE-TB descriptors before reaching the queue.
5. PHY parameters are applied via `tx_rate_config` prior to submission.
6. RF stream helpers (`rf_stream_start2_*`) are invoked to bring up the radio path when TX is enabled on a channel/band.
7. Mgmt path: `sm_auth_send` constructs and submits auth frames directly.
8. After HW transmission, `mac_tx_completion_n234` processes the completion interrupt, recycles descriptors, and frees `skb`s; `tx_queue_flush_n_xxx` and `txq_vif_reset` provide recovery on teardown or error.

## Notable Patterns
- **Heavy use of SDIO variants**: Multiple `sdio_buffer_prepare_*` functions (with hex-suffix identifiers) suggest a parameterized prep routine dispatched by buffer size / alignment class — a common pattern to minimize per-transfer branching.
- **Function-name address suffixes**: Many names carry trailing hex/decimal tags (`_n234`, `_n1b4`, `_ne6`, `_n_43a`), indicating auto-generated names keyed by their offset/ID rather than semantic role.
- **Clear per-VIF queue isolation**: `txq_vif_reset` plus `txq_queue_skb` show a per-VIF descriptor-ring model, with explicit teardown support.
- **Separation of dispatch, prep, and submit**: `fmac_tx_dispatch` is purely a router, while buffer/descriptor prep is factored out — clean SoC for adding new aggregations or buffer classes.
- **Aggregation layer abstracted as `txl_*`**: Suggests an internal "TX list" abstraction over raw descriptor rings, with HE-TB support layered on top of legacy AMPDU handling.
- **State-machine driven mgmt TX**: `sm_auth_send` indicates a SM-controlled mgmt transmit pipeline, typical of MLME-style auth/assoc sequencing.
```
