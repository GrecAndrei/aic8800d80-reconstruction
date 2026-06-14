# v19 Decompilation Quality Report

## Method

For each function found by IDA's auto-analysis, we:
1. Apply LLM-generated function name (if available)
2. Apply docstring as comment
3. Apply MMIO register names (25,815 entries)
4. Apply BSS variable names (where LLM provided)
5. Run `idaapi.decompile()` to get Hex-Rays pseudo-C
6. Save to per-function `.c` file

## Coverage by binary

| Binary | Total | Decompiled | % | LLM-named | Time (s) |
|--------|-------|------------|---|-----------|----------|
| fmacfw_8800d80_h_u02 | 1,285 | 1,272 | 99.0% | 2 | 51 |
| fmacfw_8800d80_u02 | 1,286 | 1,273 | 99.0% | 462 | 83 |
| fmacfwbt_8800d80_u02 | 1,286 | 1,274 | 99.1% | 468 | 77 |
| lmacfw_rf_8800d80_u02 | 866 | 856 | 98.8% | 324 | 36 |
| **Total** | **4,723** | **4,675** | **98.9%** | **1,256** | **247** |

## Top LLM-named functions (by decompiled size)

| Function | Size (chars) | Subsystem |
|----------|--------------|-----------|
| phy_rx_process_bulk | 23,819 | rx |
| crypto_mac_core_8280 | 20,522 | mac |
| ipc_msgq_lookup_nc78 | 13,572 | ipc |
| fmac_crypto_or_xfer_proc | 10,666 | mac |
| message_dispatch_n_16e | 9,326 | ipc |
| fmac_frame_parse_or_rx_handler | 9,138 | mac |
| phy_rf_init | 8,960 | rf |
| sdio_transfer_808 | 8,161 | mmio |
| tx_queue_dispatch | 7,579 | tx |
| rx_agg_status_update | 6,956 | rx |
| log_queue_push2 | 2,012 | util |
| msg_parse | 1,178 | ipc |
| log_tick | 1,130 | util |
| log_free_pool_f | 1,082 | util |
| start (entry) | 841 | boot |
| lmac_interrupt_init | 987 | mac |

## Failure modes

- **Fail-decompile (10 of 4,723, 0.21%)**: Hex-Rays assertion failures on
  complex functions (typically recursive or with unusual control flow).
- **Too-small (36 of 4,723, 0.76%)**: Functions smaller than 4 bytes; usually
  alignment padding or stub trampolines.

## Quality indicators

- ✅ All 4,675 decompiled functions have real C syntax
- ✅ 1,256 of 4,675 (26.9%) have LLM-applied function names
- ✅ 25,815 MMIO register addresses named automatically
- ✅ Function signatures inferred (parameters, return type)
- ✅ Local variables inferred (types, register binding)
- ✅ Control flow recovered (if/else/while/do-while/switch)
- ⚠️  RAM/BSS variables still use `algn_15350C[OFFSET]` fallbacks
- ⚠️  Hex-Rays type inference sometimes wrong (e.g., int* vs struct*)
- ⚠️  Some sub_XXXXXX calls (functions not yet named)
- ⚠️  Pseudo-C may not be directly compilable without manual fixes
