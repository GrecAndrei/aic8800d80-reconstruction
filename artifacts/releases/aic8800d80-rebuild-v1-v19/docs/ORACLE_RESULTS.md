# v19 Decompilation Quality Report

## Method

For each function found by IDA's auto-analysis, we:
1. Set up IDB with LOAD=RWX, BSS extended to 0x200000, MMIO phantom segment
2. Apply LLM-generated function name (where available)
3. Apply docstring as function comment
4. Apply MMIO register names (25,815 entries)
5. Apply in-file pointer data names (where manually set)
6. Run `idaapi.decompile()` to get Hex-Rays pseudo-C
7. Save per-function as `<addr>_<name>.c`

## Coverage by binary

| Binary | Total | Decompiled | % | LLM-named | Time (s) | Rate |
|--------|-------|------------|---|-----------|----------|------|
| fmacfw_8800d80_h_u02 | 1,285 | 1,272 | 99.0% | 2 | 51 | 25/s |
| fmacfw_8800d80_u02 | 1,286 | 1,273 | 99.0% | 462 | 83 | 15/s |
| fmacfwbt_8800d80_u02 | 1,286 | 1,274 | 99.1% | 468 | 77 | 17/s |
| lmacfw_rf_8800d80_u02 | 866 | 856 | 98.8% | 324 | 36 | 24/s |
| **Total** | **4,723** | **4,675** | **98.9%** | **1,256** | **247** | **~19/s** |

## Top LLM-named functions (by decompiled size)

| Function | Size (chars) | Subsystem | Description |
|----------|--------------|-----------|-------------|
| phy_rx_process_bulk | 23,819 | rx | PHY RX bulk processing with SIMD register save/restore |
| crypto_mac_core_8280 | 20,522 | mac | Crypto MAC core routine |
| ipc_msgq_lookup_nc78 | 13,572 | ipc | IPC message queue slot lookup |
| fmac_crypto_or_xfer_proc | 10,666 | mac | FMAC crypto/xfer dispatch |
| message_dispatch_n_16e | 9,326 | ipc | IPC message dispatch |
| fmac_frame_parse_or_rx_handler | 9,138 | mac | Frame parse / RX handler |
| phy_rf_init | 8,960 | rf | PHY RF initialization |
| sdio_transfer_808 | 8,161 | mmio | SDIO transfer helper |
| tx_queue_dispatch | 7,579 | tx | TX queue dispatcher |
| rx_agg_status_update | 6,956 | rx | RX A-MPDU aggregation status |
| ipc_msgq_lookup_nc78 | 13,572 | ipc | IPC message queue lookup |
| crypto_mac_core | 20,558 | mac | Crypto MAC core (BT) |
| bt_tx_queue_process | 14,982 | bt | BT TX queue processing |
| crypto_or_phy_init | — | mac | Crypto/PHY init dispatch |
| phy_rf_init_2d0 | 9,033 | rf | PHY RF init (variant) |
| lmac_interrupt_init | 987 | mac | LMAC interrupt setup |
| log_queue_push2 | 2,012 | util | Log queue push with 3 params |
| msg_parse | 1,178 | ipc | IPC message parser |
| log_tick | 1,130 | util | Log tick handler |
| log_free_pool_f | 1,082 | util | Log pool free (variant f) |
| start (entry) | 841 | boot | Firmware entry point |
| timer_set_relative | — | util | Set relative timer |
| rf_state_check | 15,399 | rf | RF state check (BT) |

## Failure modes

- **Fail-decompile (10 of 4,723, 0.21%)**: Hex-Rays assertion failures
  on complex functions (typically recursive, with unusual control
  flow, or with invalid register states)
- **Too-small (36 of 4,723, 0.76%)**: Functions smaller than 4 bytes;
  usually alignment padding or stub trampolines

## Quality indicators

### Strengths
- ✅ All 4,675 decompiled functions have real C syntax
- ✅ 1,256 of 4,675 (26.9%) have LLM-applied function names
- ✅ 25,815 MMIO register addresses named automatically
- ✅ Function signatures inferred (parameters, return type)
- ✅ Local variables inferred (types, register binding)
- ✅ Control flow recovered (if/else/while/do-while/switch)
- ✅ ARM intrinsics preserved (`__get_CPSR`, `__disable_irq`, etc.)

### Known weaknesses
- ⚠️  RAM/BSS variables still use `algn_15350C[OFFSET]` fallbacks
- ⚠️  Hex-Rays type inference sometimes wrong (e.g., int* vs struct*)
- ⚠️  Some `sub_XXXXXX` calls (functions not yet named)
- ⚠️  Pseudo-C may not be directly compilable without manual fixes
- ⚠️  4,723 - 4,675 = 48 functions (1.1%) failed to decompile

## Per-binary details

### fmacfw_8800d80_h_u02_bin (1,285 functions, 99.0% decompiled)
- 2 LLM-named: `start`, `j_nullsub_6`
- Smallest binary (~341 KB)
- v18 has only 25 functions for this binary
- Most functions: sub_XXXXXX (IDA auto-names)

### fmacfw_8800d80_u02_bin (1,286 functions, 99.0% decompiled)
- **462 LLM-named** (35.9% of all decompiled)
- 4,419 with MMIO names
- Largest binary content (~341 KB, 4 MB of composed C)

### fmacfwbt_8800d80_u02_bin (1,286 functions, 99.1% decompiled)
- **468 LLM-named** (36.4%)
- BT-specific functions: `bt_hci_cmd_handler`, `bt_tx_queue_process`

### lmacfw_rf_8800d80_u02_bin (866 functions, 98.8% decompiled)
- **324 LLM-named** (37.4%)
- Smallest binary (~254 KB)
- RF-specific: `rf_bus_init`, `rf_cmd_send`, `phy_rf_init`

## Function naming breakdown

| Source | Count |
|--------|-------|
| LLM-named (harness_v17/names) | 1,256 (26.9%) |
| IDA auto-named (sub_XXXXXX) | 3,419 (73.1%) |
| Total decompiled | 4,675 (100%) |

Of the 1,256 LLM-named:
- fmacfw_h: 2 (most named addresses point to ASCII strings, not code)
- fmacfw_u02: 462
- fmacfwbt: 468
- lmacfw_rf: 324

## MMIO register naming

- 25,815 unique MMIO addresses in 0x40000000-0x60000000 range
- 1,042 distinct 64KB pages
- Format: `REG_<PAGE>_<OFFSET>` (e.g., `REG_4024_0148` = 0x40240148)
- Top pages by address count:
  - 0x4620: 569 addresses
  - 0x4604: 317
  - 0x4628: 260
  - 0x4621: 218
  - 0x4770: 218
  - 0x4630: 199
  - 0x4601: 163
  - 0x4032: 162
  - 0x4602: 156
  - 0x4631: 155

## How to verify

```bash
# Find a function in the release
ls artifacts/releases/aic8800d80-rebuild-v1-v19/named_samples/

# Open in IDA Pro
# 1. Load original binary: File > Open > inputs/firmware/fmacfw_8800d80_u02.bin
# 2. Navigate to function: G 0x10b430
# 3. Press F5 to decompile
# 4. Compare with named_samples/fmacfw_8800d80_u02_bin__phy_rx_process_bulk.c
```

The output should match. Differences are usually in:
- Variable names (`v11` vs auto-generated)
- Code structure (Hex-Rays may pick different loop representation)
- Type inference (e.g., int* vs struct*)
