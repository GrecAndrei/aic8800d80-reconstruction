# AIC8800D80 Automated Firmware Reconstruction

This repository contains an automated reverse-engineering pipeline that reconstructs vendor firmware blobs into readable, auditable C-like outputs.

This is a reconstruction system, not leaked vendor source.

## What This Is For

This project is intended for:

1. Firmware research and reverse-engineering acceleration
2. Security analysis and behavior auditing
3. Building reproducible RE workflows with measurable quality gates
4. Creating a structured, explainable reconstruction baseline before manual deep-dive work

This project is not intended to claim exact vendor-source recovery.

## Release Snapshot

Published rebuild artifacts are tracked under:

- `artifacts/releases/aic8800d80-rebuild-v1/final/`
- `artifacts/releases/aic8800d80-rebuild-v1/synth/`
- `artifacts/releases/aic8800d80-rebuild-v1/meta/`

The `final/` folder contains reconstructed firmware sources for all target images plus conformance/quality reports.

## Recovered Snapshot

The newest organized recovery pass lives under:

- `extraction_out/reconstruction/mega7/focus_leftover/`
- `extraction_out/reconstruction/mega7/synth_deps/`
- `extraction_out/reconstruction/mega7/synth_leftover_behaviors/`
- `extraction_out/reconstruction/mega7/applied_recovered/`
- `extraction_out/reconstruction/mega7/final_recovered/`

This snapshot captures the leftover message, SDIO, RF, and fallback/state work that was mined after the original release bundle.

## Verified Results

Latest validated run:

- `function_count`: **61566**
- `implemented_count`: **61566**
- `strong_count`: **61566**
- `fallback_count`: **0**
- `semantic_completion_pct`: **100.000**
- `avg_conformance_pct`: **100.000**
- `evaluable_count`: **56601**
- `nonperfect_functions`: **0**
- `unevidenced_functions`: **0**

These values are for the current validated reconstruction state in this workspace and should be treated as the source-of-truth over older snapshots.

## Why This Is Significant

The pipeline does not just generate text stubs. It:

1. Mines evidence from firmware analysis artifacts.
2. Synthesizes function behavior deterministically.
3. Merges and finalizes per-image reconstructed sources.
4. Enforces strict hardening and conformance gates.
5. Publishes reproducible artifacts with manifests and checksums.

Outcome: a repeatable automated RE workflow that can be rerun on the same corpus and extended to new blobs.

## What "Perfect" Means Here

"Perfect" in this repository means:

1. All pipeline hardening gates pass
2. No fallback/placeholder functions remain
3. Semantic completion reaches 100%
4. Conformance validation reaches 100% across the evaluable set
5. The evaluable set covers all reconstructed functions for the release snapshot

It does not mean byte-identical original vendor source, and it does not prove perfect semantic equivalence for every path without additional runtime/vendor evidence.

## Straight Limit

The pipeline is now fully green on its own gates, but there is a hard information ceiling with stripped firmware blobs:

1. Static reconstruction can prove consistency, structure, and strong evidence alignment.
2. It cannot always prove exact original intent for every function without extra artifacts (debug symbols, runtime traces, emulator/hardware observations, or vendor metadata).

So "finished" here means "best evidence-backed automated reconstruction currently achievable from available blobs," not mathematically perfect source recovery.

## Pipeline Stages

1. `fwrebuild`: build reconstruction workset and per-image baselines
2. `fwimplsynth`: synthesize implementations from call/data evidence
3. `fwapplysynth`: merge synthesized bodies into composed outputs
4. `fwfinalize`: publish final reconstructed C and quality metrics
5. `fwvalidatecalls`: validate call-level conformance against evidence layers
6. `fwqualityfocus`: generate focused triage backlog
7. `fwharden`: enforce hard fail gates (quality + conformance)

## Emulator Smoke Tests

You can sanity-check a recovered function with the local Unicorn harness in `tools/unicorn_smoke.py`. It compiles one recovered C file to a linked ARM Thumb ELF, merges overlapping `PT_LOAD` ranges, maps a stack, seeds MMIO words, and runs only a bounded number of instructions.

For call-heavy paths, the harness now links a tiny ELF so internal calls resolve normally. If a helper is still missing, pass `--stub-fn NAME` to synthesize a temporary no-op no-arg stub before linking.

Example: clear-bit behavior in the crypto path.

```bash
python3 tools/unicorn_smoke.py \
  extraction_out/reconstruction/mega7/final_recovered/crypto_recovered.c \
  sub_1073d8 \
  --seed 0x403420CC=0xffffffff \
  --seed 0x403420D0=0x12345679 \
  --seed 0x403420D4=0xabcdef01 \
  --expect-eq 0x403420CC=0xfffffffe \
  --expect-eq 0x403420D0=0x12345678 \
  --expect-eq 0x403420D4=0xabcdef00
```

Example: register-init behavior in the startup path.

```bash
python3 tools/unicorn_smoke.py \
  extraction_out/reconstruction/mega7/final_recovered/init_recovered.c \
  sub_10d068 \
  --seed 0x40035018=0x3 \
  --seed 0x40035008=0x0 \
  --seed 0x4003500C=0x0 \
  --expect-eq 0x40035018=0x0 \
  --expect-eq 0x40035008=0x8000000 \
  --expect-eq 0x4003500C=0x8000000
```

This is a function-level smoke test, not a full firmware emulator. It is best for self-contained functions or paths with simple seeded state, and it is meant to confirm that recovered control flow and observable side effects still line up with the evidence we mined.

You can also print selected post-state words with `--dump ADDR` when you want to inspect what a path touched without turning those values into hard assertions yet. The harness places the stack above the linked image automatically and starts the stack pointer near the top of that window, which helps with larger handlers that need more room than the early smoke tests.

To continuously feed smoke outcomes back into mining priority, append machine-readable results:

```bash
python3 tools/unicorn_smoke.py \
  extraction_out/reconstruction/mega7/final/fmacfw_8800d80_u02_bin.reconstructed.c \
  main_loop \
  --seed 0x4000006c=0 \
  --record-outcome extraction_out/reconstruction/mega7/smoke_observations.jsonl
```

`fwextract` now ingests these outcomes (plus the checkpoint list) and writes `learning_signals.json` per run; those signals are applied directly to mining queue scoring.
When a symbol is not present in the compiled reconstruction unit, the harness records `status=missing_symbol` instead of silently losing that attempt, so queue learning still gets the negative signal.

For batch automation, use:

```bash
python3 tools/smoke_learn_loop.py \
  --source extraction_out/reconstruction/mega7/final/fmacfw_8800d80_u02_bin.reconstructed.c \
  --source-glob 'extraction_out/reconstruction/mega7/final_recovered/*.c' \
  --source-glob 'extraction_out/reconstruction/mega7/final/*.c' \
  --queue extraction_out/reconstruction/mega7/runs/<run_tag>/mining_queue_top300.jsonl \
  --outcomes extraction_out/reconstruction/mega7/smoke_observations.jsonl \
  --limit 12 \
  --seed 0x40000000=0
```
The selector favors under-tested, high-priority functions and enforces prefix diversity, so cycles keep exploring instead of repeatedly re-probing already-stable paths.
It also supports `--missing-cooldown` to temporarily skip repeatedly unresolved symbol names and keep cycle throughput high.

For a full unattended cycle (probe -> extract -> report):

```bash
python3 tools/recon_cycle.py \
  --run-root extraction_out/reconstruction/mega7 \
  --primary-source extraction_out/reconstruction/mega7/final/fmacfw_8800d80_u02_bin.reconstructed.c \
  --source-glob 'extraction_out/reconstruction/mega7/final_recovered/*.c' \
  --source-glob 'extraction_out/reconstruction/mega7/final/*.c' \
  --limit 10 \
  --missing-cooldown 2 \
  --retry-fault-once \
  --tag cycle_demo
```

Each cycle writes `runs/<tag>/cycle_report.json` with summary and learning growth counters.
Global trend history is appended to `extraction_out/reconstruction/mega7/cycle_history.jsonl`, including delta counters for learned function/prefix coverage and smoke-success growth.
`smoke_learn_loop.py` also learns supplemental MMIO seeds from historical fault addresses (per-prefix) to improve autonomous recovery on harder targets.

Native command wrapper:

```bash
go run ./cmd/fwcycle -tag cycle_demo -limit 10 -retry-fault-once=true
```

## Quick Run

```bash
RUN_ROOT=extraction_out/reconstruction/mega7
go run ./cmd/fwrebuild
go run ./cmd/fwimplsynth -max-tasks 0
go run ./cmd/fwapplysynth --synth-dir "$RUN_ROOT/synth" --composed-dir "$RUN_ROOT/composed" --out "$RUN_ROOT/applied"
go run ./cmd/fwfinalize
go run ./cmd/fwvalidatecalls
go run ./cmd/fwqualityfocus
go run ./cmd/fwharden
```

## How To Adapt To New Firmware

Use this repo as a template pipeline for another blob family:

1. Add/point input firmware artifacts under `inputs/firmware/`
2. Regenerate extraction outputs (`fwextract`, `fwsweep`, or your existing extraction flow)
3. Build reconstruction baseline (`fwrebuild`)
4. Run synthesis/merge/finalize (`fwimplsynth`, `fwapplysynth`, `fwfinalize`)
5. Run quality and conformance checks (`fwvalidatecalls`, `fwqualityfocus`, `fwharden`)
6. Iterate heuristics in `cmd/fwimplsynth` and `cmd/fwvalidatecalls` until gates close
7. Publish a versioned artifact snapshot under `artifacts/releases/<release-name>/`

Practical adaptation advice:

- Keep evidence layering conservative (stronger evidence first, softer evidence only as fallback)
- Preserve deterministic gate checks so regressions are obvious
- Keep dynamic learning enabled: smoke outcomes and checkpointed greens should continuously steer target priority
- Version each published snapshot (`-v1`, `-v2`, etc.) with manifests and checksums

## Limitations and Downsides

Important caveats:

1. Reconstruction quality is only as good as available evidence (call graph, names, profile coverage, hints)
2. A 100% internal score does not guarantee perfect semantic equivalence to unknown vendor internals
3. Heuristic synthesis can bias behavior toward observed patterns and miss rare paths
4. Some outputs are intentionally C-like reconstructions, not build-ready firmware source trees
5. Pipeline tuning that helps one firmware family may not transfer cleanly to another without retuning

Use reconstructed output as high-confidence RE working material, not as unquestionable ground truth.

## Responsible Use

- Respect applicable laws, licenses, and contractual constraints in your jurisdiction
- Use only on firmware you are authorized to analyze
- Prefer disclosure/defensive research workflows for security findings

## Human Writeup

Plain-language milestone explanation:

- `docs/REBUILD_MILESTONE.md`

## Repository Layout

- `cmd/`: pipeline commands
- `internal/`: shared pipeline logic/helpers
- `artifacts/releases/`: published reconstruction snapshots
- `docs/`: milestone and analyst documentation
- `inputs/firmware/`: raw firmware artifacts used for analysis
- `analysis/ida/`: local IDA artifacts (not the source of truth)
- `tools/local-bin/ida-idat`: headless IDA wrapper used by `fwrecon`; it prefers the analyzed `analysis/ida_headless/*.i64` database when available and falls back to the raw firmware input
- `tools/unicorn_smoke.py`: targeted ARM Thumb smoke harness; it now reports the first unmapped memory access so seed tuning is faster

## Smoke Checkpoints

These firmware paths currently smoke cleanly under the targeted Unicorn harness:

- `main_loop`
- `rf_bus_init`
- `sdio_dma_config`
- `message_dispatch`
- `tx_submit`
- `firmware_init`
- `irq_config`
- `rf_cmd_send`
- `sdio_status_check`
- `feature_guard_sdio`
- `queue_check`
- `idle_processing`
- `log_queue_push`
- `log_free_pool_a`
- `log_free_wrapper`
- `crypto_hw_clear_regs`
- `crypto_iq_calculate`
- `irq_mask_init`
- `hw_event_flag`
- `state_flag_check`
- `rf_bus_setup`
- `rf_bus_mark`
- `rf_msg_process_body`
- `rf_msg_handler`
- `rf_bus_reset`
- `tx_timeout_check`
- `log_system_init`
- `list_push_tail`
- `rf_timer_abort1`
- `rf_timer_abort2`
- `emb_kmsg_hdlr`
- `usb_rx_evt`
- `rwnxl_reset_evt`
- `subsystems_init`
- `intc_spurious`
- `lpm_host_notify_bt`
- `usb_wlan_recv`
- `usb_wlan_recv_fc_on`
- `usb_wlan_rx_pkt_free_list_init`
- `usb_trans_error_handler`
- `wlan_epbulk_recv_compl_handler`
- `wlan_epbulk_send_compl_handler`
- `rwnxl_wakeup`
- `ps_enable_cfm`
- `ps_disable_cfm`
- `ps_upm_enter`
- `ps_upm_exit`
- `log_pool_alloc_b`
- `log_hw_init_if`
- `msg_parse_thunk`
- `log_hw_regs_init`
- `error_handler`
- `math_helper`
- `math_helper_big`
- `thunk`
- `list_count`
- `log_tick`
- `log_free_pool_b`
- `log_free_pool_c`
- `list_pop`
- `fallback_handler`
- `hw_config_init`
- `variant_update_cache`
- `delay_us`
- `fp_convert_int`
- `event_queue_push`
- `log_free_pool_d`
- `log_free_pool_e`
- `log_free_pool_f`
- `crypto_mac_dispatch`
- `sdio_replenish_rx_msgqueue`
- `sdio_rx_evt`
- `chip_feature_check`
- `feature_always_on`
- `hw_reg_set_40035000`
- `system_init_chain`
- `log_free_dispatch`
- `patch_apply`
- `fw_config_apply`
- `log_printf`
- `log_ptr_in_range`
- `msg_get_value`
- `msg_parse`
- `log_alloc`
- `rx_queue_init`
- `log_pool_init_e`
- `timestamp_update`
- `clear_flags`
- `log_global_init`
- `log_pool_alloc`
- `log_pool_alloc2`
- `log_pool_alloc_b`
- `log_queue_push2`
- `list_remove_node`
- `queue_pending_check`
- `log_pool_init_queue`
- `log_pool_init_a`
- `log_pool_init_b`
- `log_pool_init_c`
- `log_pool_init_d`
- `log_free_pool_a`
- `log_free_wrapper`
- `log_free_dispatch`
- `log_system_init`
- `log_list_init`
- `log_queue_alloc`
- `log_flush`
- `log_enqueue`
- `log_hw_init`
- `rf_bus_write`
- `rf_cmd_process`
- `rf_cmd_wait`
- `rf_reg_write_core`
- `rf_state_check`
- `rf_cmd_dispatch`
- `rf_level_apply`
- `rf_level_dump`
- `rf_mem_read`
- `rf_fault_dump`
- `rf_cmd_queue_next`
- `sdio_buffer_prepare`
- `phy_rf_init`
- `sdio_transfer`
- `uart_puts`
- `uart_putc`
- `irq_disable`
- `irq23_enable`
- `irq_vector_init`
- `rf_init_blocka`
- `rf_init_blockb`
- `rf_init_blockc`
- `rf_power_set`
- `rf_timer_toggle`
- `rf_level_compute`
- `rf_reg_write_cb`
- `rf_hw_timer_init`
- `rf_reg_write_wait`
- `rf_msg_log_rate`
- `rf_bus_write2`
- `rf_bus_reset2`
- `rf_mem_write`
- `rf_reg_write_masked`
- `rf_reg_write_guard`
- `rf_timer_stop`
- `rf_hw_timer_read`
- `timer_set_relative`
- `timer_init`
- `crypto_key_load`
- `crypto_power_calc`
- `crypto_power_apply`
- `crypto_state_dump`
- `crypto_hw_enable`
- `state_check`
- `clock_calc`
- `buffer_pool_get`
- `list_insert_sorted`
- `list_find_remove`
- `msg_register_handler`
- `msg_handler_tx`
- `msg_parse_short`
- `panic_entry`
- `panic_loop`
- `feature_guard_sdio`

- `mac_phy_init`
- `fp_convert_uint`
- `fw_config_copy`
- `log_system_init_mode2`
- `crypto_channel_calc`
- `crypto_mac_core`
- `ipc_doorbell_handler`
- `log_pool_config`
- `log_pool_default_config`
- `log_queue_refill`
- `sdio_wait_busy`
- `crypto_hw_disable`
- `crypto_hw_mode_select`
- `crypto_hw_power_up`
- `log_free_pool_dispatch2`
- `memset_impl`
- `rf_stream_start`
- `rf_stream_start2`
- `rf_stream_start_once`
- `tx_phy_config`
- `tx_rate_config`
- `crypto_hw_write32_core`
- `crypto_table_init`
- `rf_timer_toggle_update`
## License Status

This repository is licensed under **Apache License 2.0**.

- See `LICENSE` for full terms.
- Copyright: **2026 Grec Alexander**.
