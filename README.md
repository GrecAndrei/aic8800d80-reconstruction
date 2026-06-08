# AIC8800D80 Firmware Reconstruction

This repository is an automated reverse-engineering and firmware reconstruction workspace for the AIC8800D80 firmware family.

It is not leaked vendor source. It is a deterministic reconstruction pipeline that combines:

- grounded facts exported from IDA Pro,
- embedder-driven retrieval and clustering,
- staged body synthesis and merge/finalize passes,
- strict conformance and hardening gates,
- autonomous probe and rebuild cycles.

## Status

- Active reconstruction workspace: `extraction_out/reconstruction/mega7/`
- Published tracked release: `artifacts/releases/aic8800d80-rebuild-v1/`
- Canonical long-term plan: `plan.md`
- End-to-end pipeline reference: `PIPELINE.md`
- Repo navigation and operator docs: `docs/README.md`

### v13 — Behavioral Fingerprint Reconstruction (current)

The current build compiles cleanly across all 4 final files and the
truth-lane scorecard reports 19 PASS / 6 REVIEW / 0 FAIL with behavioral
bodies verified against the original binary's MMIO traces:

- `fmacfw_h`: 906 functions, 0 errors
- `fmacfw`: 74441 functions, 0 errors
- `fmacfwbt`: 52052 functions, 0 errors
- `lmacfw_rf`: 57378 functions, 0 errors
- **Truth Lane Unicorn Smoke**: 21 PASS / 4 REVIEW / 0 FAIL
- **Completion**: `implemented_count`: 59383, `completion_pct`: 96.450
- **Behavioral bodies**: 2689+ deployed across all 4 images, composed-file sourced
- **Cross-image contamination fixed**: per-image filtering via `image=` tags

The breakthrough is the **behavioral fingerprint pipeline** that runs the
original firmware through Unicorn, captures the exact MMIO read/write
sequence, and emits C bodies that touch the same addresses. See
`docs/REBUILD_MILESTONE.md` for the full v13 entry.

### v1 Tracked Release Snapshot (curated)

The tracked release snapshot records:

- `function_count`: `356`
- `implemented_count`: `356`
- `strong_count`: `356`
- `fallback_count`: `0`
- `semantic_completion_pct`: `100.000`
- `evaluable_count`: `352`
- `avg_conformance_pct`: `100.000`

These values come from the curated release bundle under
`artifacts/releases/aic8800d80-rebuild-v1/`. The live workspace under
`extraction_out/` (v12 and later) is significantly larger and reflects the
real pseudocode transpiler path.

## Repo Map

- `cmd/`: Go entry points for extraction, reconstruction, validation, dashboards, and autonomous cycle control
- `internal/`: shared extraction, pipeline, reconstruction, file I/O, and stats packages
- `tools/`: Python helpers for IDA export, probing, smoke learning, autonomous cycles, and embedder integration
- `docs/`: repo map, runbook, milestone notes, and research notes
- `artifacts/`: tracked published release snapshots only
- `metadata/`: stable input metadata and per-image reconstruction descriptors
- `inputs/`: source firmware blobs and related inputs
- `extracted_kernel/`: historical kernel-focused extraction notes and slices
- `extraction_out/`: generated working outputs for current runs; ignored from git
- `analysis/`: local scratch, wrapper state, and ad hoc analysis output; ignored from git

Detailed layout rules live in `docs/REPO_LAYOUT.md`.

## Canonical Docs

- `docs/README.md`: documentation index
- `docs/RUNBOOK.md`: operator runbook and common commands
- `docs/REPO_LAYOUT.md`: what each top-level directory is for, and what should or should not be committed
- `docs/REBUILD_MILESTONE.md`: current high-level milestone summary
- `PIPELINE.md`: extraction + reconstruction + validation pipeline reference
- `plan.md`: long-term autonomous architecture and progress log

## Core Workflow

Typical rebuild path:

```bash
RUN_ROOT=extraction_out/reconstruction/mega7

go run ./cmd/fwcompose
go run ./cmd/fwdescriptors -run-root "$RUN_ROOT"
go run ./cmd/fwimplqueue -max-tasks 128
go run ./cmd/fwimplsynth -max-tasks 128
go run ./cmd/fwapplysynth
go run ./cmd/fwfinalize
go run ./cmd/fwvalidatecalls
go run ./cmd/fwharden
```

Autonomous cycle entry point:

```bash
go run ./cmd/fwcycle -run-root extraction_out/reconstruction/mega7 -tag cycle_demo
```

### Truth-Lane Scoring

Score the top 25 critical functions with original-binary trace validation:

```bash
python3 tools/truth_lane_smoke.py \
  --final-dir extraction_out/reconstruction/mega7/final \
  --out /tmp/opencode/truth_lane_smoke

python3 tools/behavioral_fingerprint.py \
  --bin inputs/firmware/lmacfw_rf_8800d80_u02.bin \
  --targets /tmp/opencode/targets.jsonl --out /tmp/opencode/fingerprints.jsonl

python3 tools/find_mmio_functions.py \
  --bin inputs/firmware/lmacfw_rf_8800d80_u02.bin --base 0x1200000 \
  --functions extraction_out/ida_export_live/lmacfw_rf_8800d80_u02.bin.functions.jsonl \
  --out /tmp/opencode/mmio_fns.jsonl
```

The current v13 build reports **19 PASS / 6 REVIEW / 0 FAIL** — all behavioral
bodies pass, all REVIEW are motif bodies (stochastic XOR) with zero MMIO writes.

See `docs/RUNBOOK.md` and `PIPELINE.md` for the full staged workflow.

## Artifact Policy

- Track curated release outputs under `artifacts/releases/`
- Keep active run products under `extraction_out/`
- Keep local wrapper state and scratch under `analysis/`
- Do not commit local caches, root-level built binaries, or Python bytecode

This policy is enforced by `.gitignore` and documented in `artifacts/README.md`.

## Adaptation

To adapt this repository to another firmware family:

1. Place new blobs under `inputs/firmware/`
2. Re-run extraction into `extraction_out/`
3. Build a reconstruction baseline
4. Run descriptor, synthesis, finalize, and validation stages
5. Publish only curated release outputs under `artifacts/releases/<name>/`

## Smoke Checkpoints

Auto-promoted stable smoke successes:

- `log_free_pool_b`
- `log_free_pool_c`
- `log_free_pool_d`
- `log_pool_init_e`
- `log_free_pool_a`
- `log_pool_init_c`
- `log_pool_init_d`
- `rf_init_blockc`
- `log_free_pool_e`
- `log_free_pool_f`
- `log_pool_alloc_b`
- `rf_init_blockb`
- `log_pool_init_a`
- `log_pool_init_b`
- `mac_phy_init`
- `rf_init_blocka`
- `fp_convert_uint`
- `fw_config_copy`
- `rf_bus_init`
- `rf_bus_reset`
- `rf_cmd_process`
- `rf_cmd_wait`
- `rf_msg_log_rate`
- `rf_reg_write_core`
- `firmware_init`
- `fw_config_apply`
- `log_free_dispatch`
- `panic_entry`
- `patch_apply`
- `phy_rf_init`
- `irq_vector_init`
- `rf_bus_reset2`
- `rf_bus_setup`
- `rf_bus_write`
- `rf_cmd_queue_next`
- `rf_cmd_send`
- `rf_fault_dump`
- `rf_hw_timer_read`
- `rf_level_dump`
- `rf_reg_write_cb`
- `rf_timer_toggle`
- `sdio_buffer_prepare`
- `sdio_dma_config`
- `sdio_status_check`
- `get_cached_1828f8`
- `get_variant_cached`
- `log_system_init`
- `log_system_init_mode2`
- `memcpy_fast`
- `memset_thunk`
- `parse_int`
- `parse_width_suffix`
- `rf_timer_abort_common`
- `rx_queue_head_init`
- `timestamp_list_contains`
- `timestamp_remove`
- `apm_sta_connect_past_timer_handle`
- `apm_start_cac_req_handler`
- `apm_start_req_handler`
- `apm_stop_cac_req_handler`
- `buffer_pool_get`
- `clear_sdio_state`
- `crypto_channel_calc`
- `crypto_hw_write32_core`
- `crypto_mac_core`
- `crypto_mac_dispatch`
- `debug_if_40320038`
- `delay_us`
- `emb_kmsg_hdlr`
- `error_handler`
- `event_queue_push`
- `fallback_handler`
- `feature_always_on`
- `feature_flags_init`
- `fp_convert_int`
- `hw_event_flag`
- `hal_dma_evt`
- `hal_machw_abs_timer_handler`
- `hw_config_init`
- `hw_reg_set_40035000`
- `intc_spurious`
- `ipc_emb_hostrxbuf_get`
- `ke_evt_schedule`
- `ke_msg_alloc`
- `ke_timer_clear`
- `ke_timer_set`
- `list_count`
- `list_pop`
- `log_hw_init_if`
- `log_hw_regs_init`
- `timestamp_update`
- `log_pool_config`
- `log_pool_default_config`
- `log_queue_refill`
- `lpm_host_notify_bt`
- `main_loop`
- `math_fastpath`
- `math_helper`
- `math_helper_big`
- `math_helper_big2`
- `math_helper_int`
- `math_round`
- `me_config_monitor_req_handler`
- `me_data_path_flushed_ind_handler`
- `me_set_active_cfm_handler`
- `me_set_ps_disable_cfm_handler`
- `mm_ba_add_cfm_handler`
- `mm_back_to_host_idle`
- `mm_bcn_transmit`
- `mm_bcn_transmitted`
- `mm_bcn_update_p2p_noa`
- `mm_bss_param_setting_handler`
- `mm_chan_ctxt_unlink_cfm_handler`
- `mm_force_idle_req`
- `mm_hw_config_handler`
- `mm_set_idle_cfm_handler`
- `mm_set_ps_mode_cfm_handler`
- `mm_set_ps_options_req_handler`
- `mm_sta_add_cfm_handler`
- `msg_parse_thunk`
- `idle_processing`
- `log_queue_alloc`
- `timer_set_relative`
- `feature_guard_sdio`
- `msg_register_handler`
- `ps_disable_cfm`
- `ps_enable_cfm`
- `ps_upm_exit`
- `queue_pending_check`
- `sm_connect_req_handler`
- `system_init_chain`
- `thunk`
- `tx_phy_config`
- `txl_cfm_evt`
- `usb_rx_evt`
- `log_alloc`
- `log_pool_alloc`
- `log_pool_alloc2`
- `log_pool_init_queue`
- `log_queue_push2`
- `msg_parse`
- `rx_queue_init`
- `variant_update_cache`
- `list_find_remove`
- `list_remove_node`
- `msg_handler_tx`
- `msg_parse_short`
- `list_insert_sorted`
- `log_free_wrapper`
- `log_global_init`
- `log_ptr_in_range`
- `uart_putc`
- `uart_puts`
- `msg_get_value`
- `log_flush`
- `log_printf`
- `clear_flags`
## Notes

- The live workspace is intentionally richer than the published release snapshot.
- The repo is organized around a clean split between source, generated workspaces, and tracked release artifacts.
- When in doubt, start with `docs/README.md`.
