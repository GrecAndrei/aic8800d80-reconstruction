# tx Subsystem

<think>
The user wants me to stop using tools and output the markdown document based on the function names and descriptions provided. I have enough information from the function list to create a useful document.
</think>
# TX Subsystem

## Overview
The TX subsystem manages the transmission path of the wireless MAC/firmware, including SDIO buffer descriptor preparation, aggregation descriptor building (including HE TB), rate configuration, queue management, RF stream initiation, and completion handling. It bridges upper-layer (FMAC) and lower-layer (LMAC/RF) transmit concerns by dispatching frames, programming DMA descriptors for TX rings, and reacting to TX-completion events. The subsystem also includes authentication frame transmission and queue/descriptor reset logic for VIFs.

## Major Function Groups

- **TX Dispatch / Queueing**: `fmac_tx_dispatch` (FMAC TX path dispatcher), `txq_queue_skb` (programs a TX DMA descriptor and submits an skb to the hardware transmit queue).
- **TX Completion**: `mac_tx_completion_n234` (handles TX frame completion events).
- **Aggregation (TXL)**: `txl_agg_he_tb_prep` (builds HE TB aggregation descriptor), `txl_agg_set_uph` (sets aggregation UPH parameter).
- **SDIO Buffer Preparation**: `sdio_buf_prepare_size6`, `sdio_buffer_prepare_n1b4`, `sdio_buffer_prepare_nb2`, `sdio_buffer_prepare_n_43a` (variants for building SDIO buffer descriptors for host I/O).
- **Queue / VIF Management**: `txq_queue_skb`, `txq_vif_reset` (reinitialize TX descriptor ring and queue state for a VIF), `tx_queue_flush_n_xxx` (TX queue flush/management utility).
- **Rate / PHY Configuration**: `tx_rate_config` (configure TX PHY rate parameters).
- **RF Stream Control**: `rf_stream_start2_n3dc` (start secondary RF data stream), `rf_stream_start2_ne6` (start an RF TX/RX stream variant 0xe6).
- **Auth Frame TX**: `sm_auth_send` (state machine transmit auth frame).

## Key Data Flow
Upper-layer frames enter via `fmac_tx_dispatch`, which routes them to per-VIF TX queues. For each queued skb, `txq_queue_skb` programs a DMA descriptor in the hardware TX ring. Before pushing to the host bus, SDIO buffer preparation variants (`sdio_buf_prepare_*`) build the buffer descriptors needed for the transfer. Aggregation is handled in the TXL layer, with `txl_agg_he_tb_prep` constructing the HE TB aggregation descriptor and `txl_agg_set_uph` configuring the UPH (units per hour, or per-tx) parameter. The TX path's lower edge interacts with the radio via `rf_stream_start2_*` to begin data streams. Once frames are transmitted, `mac_tx_completion_n234` consumes the TX-completion event from the hardware to release buffers and update queue state. VIF lifecycle operations (channel change, reset) trigger `txq_vif_reset` to drain and reinitialize ring state, while `tx_queue_flush_n_xxx` provides a utility for forced flushes. `sm_auth_send` is a state-machine-driven side path for emitting authentication frames. `tx_rate_config` adjusts PHY rate parameters applied to subsequent transmissions.

## Notable Patterns
- **Variant-suffixed helpers**: Many SDIO and RF helpers carry numeric suffixes (`_n1b4`, `_nb2`, `_n_43a`, `_n3dc`, `_ne6`, `_n_xxx`, `_n234`), suggesting a code-generation or templating scheme producing specialized copies for size/alignment/stream-type variations.
- **TXL aggregation pattern**: Dedicated prep + parameter-set pairing (`txl_agg_he_tb_prep` + `txl_agg_set_uph`) is a common firmware idiom: one function builds the descriptor, another sets a tuning parameter.
- **Strict layered separation**: FMAC (`fmac_tx_dispatch`, `txq_*`) → TXL/SDIO (`txl_agg_*`, `sdio_buffer_prepare_*`) → RF (`rf_stream_start2_*`) → completion (`mac_tx_completion_n234`) — clear handoff at each layer.
- **Per-VIF state ownership**: `txq_vif_reset` keyed on VIF index indicates the firmware maintains a separate TX descriptor ring/queue per virtual interface.
- **State machine coupling for control frames**: `sm_auth_send` (state machine transmitter) shows auth frames are emitted via a dedicated SM path rather than the general TX dispatch, typical of pre-association control frame handling.
