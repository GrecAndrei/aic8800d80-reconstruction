# Linked-run comparison over every composed function

`tools/linked_recon_run.py --corpus` runs every function composed into
`src/<image>/main.c` (4,720 across the four images) twice on the same Unicorn
platform and MMIO model: once in the original binary, once in the fully linked
reconstruction (`tools/full_link.py`, callees real), and compares the ordered
peripheral writes with their values. The 25 truth-lane targets
(`docs/TRUTH_LANE_REVIEW_VERDICTS.md`) are a subset: **25 PASS / 0 REVIEW / 0 FAIL**.

A MATCH is an identical peripheral write sequence on one default-state path
(zeroed RAM, zero arguments, boot callbacks stubbed). It is not behavioral
equivalence. 547 of the 4,393 matches end at the firmware's assert trap
in both runs (`identical_peripheral_writes_up_to_assert_trap`), and 3,846 return
with identical peripheral writes (`identical_peripheral_writes`).

## Counts

| | first run | after the two call-site/register rules | after the six further rules | `_hw.i64` + libmatch + fnptr reloc | **current (64-bit pools + post-compose rules)** |
|---|---|---|---|---|---|
| MATCH | 3,581 | 3,743 | 4,228 | 4,346 | **4,393** |
| DIFFER | 433 | 271 | 230 | 55 | **0** |
| NOT_RUN (no comparison exists) | 700 | 700 | 256 | 319 | **327** |

Per image MATCH / total, now: fmacfw_h `1,197 / 1,284`, fmacfw `1,199 / 1,285`,
fmacfwbt `1,204 / 1,285`, lmacfw_rf `793 / 866`.
`metadata/linked_corpus_summary.json` records the current run's exact summary
(`205` `original_does_not_return_standalone` + `122` `not_in_linked_image` for
`NOT_RUN`, with the 8 additional `not_in_linked_image` rows being unreferenced
interior fragments dropped inside matched `libmatch` library routines; `0` `DIFFER`).

Row by row, from the second column to the third:

| was | now | rows |
|---|---|---|
| MATCH | MATCH | 3,738 |
| DIFFER | MATCH | 75 |
| NOT_RUN | MATCH (both runs end at the assert trap) | 415 |
| DIFFER | DIFFER | 196 |
| NOT_RUN | DIFFER | 29 |
| MATCH | DIFFER | 5 |
| NOT_RUN | NOT_RUN | 256 |

DIFFER did not fall by 75 because 29 functions that could not be compared
before now can, and differ, and 5 earlier matches were not matches (below).

NOT_RUN, now:

| count | why |
|---|---|
| 187 | the original itself neither returns nor asserts within 200,000 instructions when entered standalone (OS waits, event loops) |
| 69 | the function is one of those that `tools/libmatch.py` bound to the byte-identical toolchain routine; its name is an asm label of the library member, not a symbol of the linked image |

## What changed in the comparison itself

Three harness changes, none of which touches `src/`:

- **The assert trap ends a run.** The firmware's assert is `udf #255`, which
  never returns on hardware. The emulator used to skip it, so the original ran
  on into whatever followed and usually never returned. With
  `run(assert_stops=True)` a run that reaches the trap ends as `asserted`, and
  the two runs are compared up to it. That is 415 of the 444 rows that left
  NOT_RUN. `__und` in `src/include/aic8800d80_types.h` emitted the wrong
  instruction and now emits the same `udf #255`. A run that asserts while the
  other returns is a DIFFER (`assert_trap_only_in_original`).
- **Tick counters advance per read, not per instruction.** `rf_tick_counter`
  and `timer_value` returned `instructions / rate`, so the original and the
  reconstruction, which spend different instruction counts on the same logic,
  read different times and took different branches. In the linked run both
  now read `100 * (number of counter reads)`. 6 rows moved to MATCH, 22 left
  NOT_RUN (their original now returns), 1 match was lost (`ke_enter_critical`,
  below). Boot, `verify` and the corpus sweep keep the instruction-count clock.
- **Stale IT state.** Unicorn reported valid Thumb instructions after an IT
  block as invalid; the emulator clears the stale IT bits and retries once.

## Why functions differ

Counts below are for the 230-row run; in the regenerated source the
"original asserts" group is 6 (228 rows in all).

The tool groups a DIFFER row by where the two runs part (`group` in
`corpus_outcomes.jsonl`). The causes below come from reading every group that
is not console text; the functions are listed so the reading can be checked.
Image names are short for `<name>_8800d80_u02`.

| cause | rows | fixable by a pipeline rule |
|---|---|---|
| Console text: first differing write is the UART data register | 122 | no, needs IDA |
| Formatter never finishes | 27 | no, needs IDA (same formatter) |
| Delay loop whose exit Hex-Rays dropped | 35 | no, needs IDA |
| Code after a loop decompiled as `while ( 1 ) ;` | 7 | no, needs IDA |
| Original asserts, reconstruction returns | 8 | no, needs IDA |
| Soft-float value chain | 14 | part done (`call_cast_returns`, `double_args`, `float_bits`); the rest needs IDA |
| Soft-float routine with `JUMPOUT` | 4 | no, needs IDA |
| List walk over a local Hex-Rays left uninitialized | 3 | no, needs IDA |
| Callee argument the decompile does not pass | 3 | no, needs IDA |
| Boot entry `start` | 2 | no: not a standalone-comparable function |
| Code pointer that still holds an original-image address | 2 | not safely: see below |
| Data read from outside the reconstructed image | 1 | no: not a source defect |
| Single functions (`rf_reg_update`, `llm_pdu_tx_cfg`) | 2 | no, needs IDA |

**Console text, 122.** The formatter defects recorded for the truth lane: the
decompiled formatter (`main_loop_dispatch` / `rf_parse_cal_cmd` and their
per-image counterparts) prints `%d`-style conversions wrongly because Hex-Rays
left switch arms as `JUMPOUT` and the lmacfw_rf state-table stride is in an
IDA type that is not in the tree. Every caller that logs inherits it. One of
the 122 is `ke_enter_critical` (lmacfw_rf), a MATCH before the per-read clock:
with it the original takes the path that logs (38 writes), the reconstruction
does not.

**Formatter never finishes, 27.** The same formatter, entered with a format
string on which the decompiled state machine does not advance. The run is
capped inside it: `prepare_debug_buffer` (12 rows: fmacfw `init_radio_hw`,
`dispatch_cmd`, `ble_phy_decode`, `rf_event_handler_alt`, `rf_copy_stats`,
`rx_packet_handler_1`, `is_hci_initialized`, `rf_pll_program`, `rf_bb_config`,
`event_queue_init`, `mutex_lock`, `read_periph_status`), `rf_init_regs`
(5, lmacfw_rf: `init_buffer_list`, `rf_init_regs`, `configure_dma_engine`,
`mem_get_stats`, `get_free_heap_size`), `rx_process_packet_2` (4, fmacfw_h:
`mac_event_handler`, `mac_state_init`, `is_patch_loaded`, `apply_patch_table`),
`rf_cal_init` (3, fmacfw: `ke_event_handler`, `queue_init`,
`patch_check_region`), `main_loop_dispatch` (3, fmacfwbt: `ke_evt_handler`,
`ke_task_init`, `ring_buf_used`).

**Delay loop, 35.** 31 stop in the microsecond delay at 0x1006d8 / 0x1005f4
(`send_command` 7 in fmacfw, `mmio_write_cmd` 7 in fmacfw_h, `clock_start` 7
in fmacfwbt, `periph_write_read` 10 in lmacfw_rf: the routine itself and its callers). The binary re-reads the tick counter
and leaves the loop; the Hex-Rays body is
`while ( 1 ) { v1 = 32; while ( v1-- ) ; }` with the exit gone, whatever the
clock reads. The other 4 are polls of the same shape in `rx_packet_pending`,
`check_event_flag`, `mac_status_check` and `mmio_wait_flag` (the original
writes 16 to 21 registers, the reconstruction stops after 13).

**Code after a loop lost, 7.** `crypto_start_operation` (fmacfw_h, with its
callers `crypto_init`, `rx_copy_stats`), `enable_radio_controller` (fmacfw),
`hw_init` (fmacfwbt, with `hw_enable`, `copy_stats`): the same routine in three
images. The original writes 1,567 registers and returns; the decompiled body
ends in `while ( 1 ) ;` after the fifth write. These were NOT_RUN before the
per-read clock.

**Original asserts, reconstruction returns, 8.** `util_read_u8`,
`mfp_key_update` (fmacfw_h), `debug_byte_cb`, `wlc_band_set`, `main_loop_init`,
`adv_state_handler` (fmacfw), `ipc_msg_send_byte`, `ipc_msg_send` (fmacfwbt).
No peripheral write on either side; the original reaches `udf #255`, the
decompiled body has no assert on that path. 4 of them were counted MATCH
before the trap was an endpoint.

**Soft-float value chain, 14.** The firmware is soft-float; Hex-Rays types the
temporaries by the first register it sees, so a double is carried in an `int`
and a float's bit pattern is converted numerically. Three rules below repair
the shapes that are unambiguous in the text. What is left computes a different
value from the same registers: `load_const_table` (fmacfw_h `init_callbacks`,
`phy_read_table`), `memcpy_from_rodata` (fmacfw `runtime_helper_div`,
`rf_phy_regs_read_cal`), `rf_load_calib_data` (fmacfwbt `log_message`,
`rf_calibrate`), `load_device_desc` (lmacfw_rf `malloc_wrapper`, `prcm_start`):
first write 0x4034404c = 0x38 in the original, 0 in the reconstruction;
`gpio_mode_set` (fmacfw_h), `rf_analog_ctrl_set` (fmacfw),
`gpio_set_pin_mode` (fmacfwbt) (1,432 writes
against 179: the calibration loop ends early); `scan_enable`,
`mac_irq_enable`, `mac_tx_enable` (9 writes against 305: a copy loop the
original does not enter). The remaining shapes (a float assigned from an
uncast `int` call, halves of a double in two separate locals) need the
Hex-Rays types.

**Soft-float routine with `JUMPOUT`, 4.** `double_compare_ord` (fmacfw_h),
`double_divide` (fmacfw), `__aeabi_ddiv_nan` (fmacfwbt), `double_unordered`
(lmacfw_rf): not byte-identical to a library routine, so libmatch cannot bind
them, and their bodies contain `JUMPOUT`.

**Uninitialized list walk, 3.** `ble_ll_conn_get` (fmacfw_h),
`bt_get_conn_entry` (fmacfw), `rf_config_chan_table` (fmacfwbt): the same
routine. The loop variable is read before any assignment in the decompiled
body, so the walk does not end.

**Callee argument not passed, 3.** `alloc_shared_ctx` (fmacfw_h),
`mem_pool_init` (fmacfw), `controller_init` (fmacfwbt): the same routine. A
callee (`cmd_handler_a` in fmacfw) takes its error branch because its second
argument is 0; the original passes a pointer in a register the decompiled call
does not carry. The reconstruction writes 4 registers starting with
0x40000000, the original one (0x40320630).

**Boot entry `start`, 2** (fmacfw_h, fmacfwbt). The original runs the reset
path (about 4,600 writes, starting with CPACR); the decompiled body is the
ROM-patch dispatch that precedes it and returns at once. NOT_RUN before the
per-read clock.

**Code pointer, 2.** `osal_int_enter`, `osal_int_exit` (lmacfw_rf) call
through a data word that holds an original-image Thumb address, which is not
code in the linked image. A rule binding such words to the linked symbol was
tried (77 words per fmac image, 35 in lmacfw_rf): it did not change any
corpus row and whether a word is a code pointer cannot be told from its value
alone, so it is not in the tree.

**Data from outside the image, 1.** `copy_config_struct` (fmacfwbt): 267
writes on both sides, the fifth is 0xf1e35022 in the original and 0 in the
reconstruction. The source of the copy is outside the reconstructed data
segment (the original run reads the bytes that follow in the mapped image).

**Single functions, 2.** `rf_reg_update` (lmacfw_rf): 22 writes in the
original, none in the reconstruction. `llm_pdu_tx_cfg` (lmacfw_rf): two writes
the original does not make. Both are branch conditions on values the
decompiled body computes differently; no text pattern identifies them.

## Rules added after the first two

Each runs on the composed `src/<image>/main.c`, adds no body, renames nothing,
is idempotent, has `--check`, and has a fixed-point test in
`tools/test_pipeline_rules.py`. Order: `callsite_targets`, `periph_symbols`,
`asm_returns`, `call_cast_returns`, `double_args`, `float_bits`,
`stack_frames`, `dword_compares`, `arm_shifts`, `float_compares`.

| rule | what it restores | sites | rows it moved to MATCH |
|---|---|---|---|
| `tools/asm_returns.py` | the `return` Hex-Rays printed as `__asm { POP {...,PC} }` and the v19 strip deleted, taken from the tracked pre-strip text in `harness_v25/out/` | | with the next three: 23 |
| `tools/callsite_targets.py` (extended) | a call to an interior label `loc_...` that the binary reaches by a direct `bl` within 32 bytes of a function start, at a `push`, is a call of that function's second entry | 3 labels | |
| `src/Makefile` `DIALECT` | `-fsigned-char -fwrapv -fno-delete-null-pointer-checks -fno-strict-aliasing`: the compiler reads decompiler output with the machine's semantics | | |
| `src/include/aic8800d80_types.h` | `HIBYTE`/`HIWORD`/`BYTEn`/`WORDn` at the bit positions the disassembly shows, `__usat` clamps, `__OFADD__`/`__OFSUB__`, `__und`, `vcvts_n_s32_f32`/`vcvts_n_f32_u32` fixed-point scaling | | |
| `cmd/fwstruct/datasgen.go` (`dataWide64Re`) | emit 64-bit `uint64_t` literal-pool definitions for `*(volatile uint64_t *)&dword_*` reads so upper IEEE-754 double words are preserved | 46 symbols / 75 sites per image | 39 (24 `console_text` + 15 float diffs, incl. `rf_timer_toggle_update`) |
| `tools/stack_frames.py` | stack locals at their printed `sp` offsets in one packed struct (grouping same-offset spill locals into anonymous `union`s), for functions that reach one local through the address of another | 73 / 73 / 71 / 59 functions | 8 initially + 7 from spill-union extension |
| `tools/call_cast_returns.py` | a call through `((int (*)())F)` keeps F's 64-bit result when F returns r0:r1 | | 0 by itself |
| `tools/double_args.py` | a double handed to a one-double RTABI helper keeps both words | 23 / 23 / 19 / 27 calls | 0 by itself |
| `tools/float_bits.py` | a float local assigned from an `int`-cast helper call and read as `LODWORD(v)` is a bit copy (`COERCE_FLOAT`, `COERCE_UNSIGNED_INT`), not a numeric conversion | 14 / 14 / 14 / 20 | 3 |
| `tools/dword_compares.py` | `*(_DWORD *)p < v` with `int v` is a signed compare (`cmp; bge` in the binary) | 11 / 11 / 11 / 8 compares | 4 |
| `tools/arm_shifts.py` | mask mod-256 ARM exponent shift counts (`& 0xFF`) in `round()` (`double_exp_check`) so GCC `-O2` does not drop shifts >= 32 as UB | 4 / 4 / 4 / 4 shifts | (verified with spill unions) |
| `tools/float_compares.py` | rewrite float loop-exit `if ( a < b ) break/goto` to `if ( !(a >= b) )` to preserve ARM VFP `bge` NaN exit semantics (`mem_swap_fields` and siblings) | 2 / 2 / 2 / 2 compares | 4 (`mmio_set_bit10`, `mac_irq_enable`, `mac_tx_enable`, `bb_reset`) |
| `tools/libmatch.py` (interior drop) | after binding exact matched routines, iteratively drop unreferenced interior fragments split by IDA inside a matched routine | 2 / 2 / 2 / 2 fragments | 4 moved from `DIFFER` to `NOT_RUN` (`not_in_linked_image`) |

Sites are per image in the order fmacfw, fmacfw_h, fmacfwbt, lmacfw_rf. The
first four rows were measured together (3,743 to 3,766 MATCH, before the
harness changes). The three soft-float rules are one fix in three steps:
`call_cast_returns` and `double_args` alone turned three matches
(`gpio_pad_ctrl_set`, `rf_control_field_set`, `gpio_set_alternate`) into
differences, because the full double then reached a `float` local that
rounded it; `float_bits` makes all three match again, now with the value the
original computes rather than a truncated one that happened to take the same
branch. `tools/truth_lane_smoke.py` no longer stubs `__attribute__` /
`__asm__` as if they were callees.

## The first two rules

Both run on the composed `src/<image>/main.c`, after `fwstruct compose`, with
the three rules of `docs/TRUTH_LANE_REVIEW_VERDICTS.md`. Neither adds a body or
renames anything; each is idempotent, has `--check`, and
`tools/test_pipeline_rules.py` asserts the tracked sources are at the fixed
point.

`tools/callsite_targets.py`. The naming dataset gave one name to several
functions; compose keeps the definitions apart as `name`, `name_1`, ... but a
call site keeps the bare name. Compose corrects that from the IDA call-edge
export (`extraction_out/ida_export_live/*.call_edges.jsonl`), which is not in
the tree, so the step is a no-op here. The rule takes the edges from the
firmware bytes: each direct `bl` / `b` in a function's extent
whose target is the start of a composed function. A call site is rebound only
when its name is not a target of the caller in the binary and exactly one
function of the same `_N` family is a target the body does not otherwise name.
Run after heal on the old source it rebound 503 call-site names in 425
functions and left 9 whose callee prototype did not fit; run before heal in
the pipeline it rebinds 1,000 names in 818 functions (fmacfw 197, fmacfw_h 223,
fmacfwbt 252, lmacfw_rf 328) and leaves none.
Example: `store_three_halfwords_tail @ 0x12ca20` branches to 0x12c98c
(`ke_msg_send_2`); the source called `ke_msg_send @ 0x1259e0`.

`tools/periph_symbols.py`. Hex-Rays names a global after its address;
datasgen materializes `dword_40504080` as a zero-initialized variable, so
`((volatile uint32_t *)(uintptr_t)&dword_40504080)[i]` wrote a RAM word. The
address-of a `dword_/word_/byte_/unk_` symbol whose address is in
0x40000000-0x5FFFFFFF becomes that address. 87 sites (28 in each fmac image,
3 in lmacfw_rf), three symbols: `dword_40021000`, `dword_40021008`,
`dword_40504080`.

## One command produces `src/`

`bin/fwstruct compose` now writes the four `main.c` and then runs
`tools/post_compose.py`, which applies, in order: `callsite_targets.py
--before-heal`, `heal_composed.py`, `heal_two_d_subscript.py`, `libmatch.py
scan` and `apply`, `volatile_pointees.py`, `callsite_targets.py`,
`periph_symbols.py`, `asm_returns.py`, `call_cast_returns.py`,
`double_args.py`, `float_bits.py`, `stack_frames.py`, `dword_compares.py`,
`arm_shifts.py`, `float_compares.py`.
`fwstruct compose -raw` stops before that; `post_compose.py --check` runs every
step's check. `make -C src reproduce` rebuilds `fwstruct`, composes and fails
if `src/` or `metadata/libmatch.json` then differ from the tracked files.

Making that true needed three changes, because the previously tracked
`main.c` was not what the tracked tools produce from the tracked inputs:

- `heal_composed.py` only converged under GCC 14, where int/pointer
  conversions and implicit declarations are errors and the argument-count
  message has a suffix. It now names those diagnostics as errors and accepts
  both message forms, so GCC 10.3 heals to a clean compile too (it stopped at
  403-657 errors per image before). It also exits non-zero when it does not
  converge and has `--check`.
- The old `main.c` was composed with the IDA call-edge export in place, which
  is not in the tree, so duplicate-name call sites were rebound before heal
  and heal cast the ones whose prototype differs. `callsite_targets.py
  --before-heal` does that from the firmware bytes without consulting the
  prototype; nothing is left unbound now (was 9 with a non-fitting prototype).
- One body (`prepare_and_dispatch`, lmacfw_rf) calls two members of a name
  family under one name. In a body without control flow the mentions are in
  the binary's branch order, so `callsite_targets.py` binds them in that order.

The regenerated files differ from the old ones in about 450 lines per
direction: the same call written with or without a heal cast, `__usat` used as
the header macro instead of through a function cast, and the newly bound call
sites. No function body is added or dropped.

## Reproduce

```
tools/fetch_firmware.sh                      # the images are not tracked
make -C src reproduce                        # compose + rules == tracked src/
python3 tools/post_compose.py --check
make -C src check
python3 tools/full_link.py --text-base 0x800000 --out build/full_link_run
python3 tools/linked_recon_run.py --corpus --out /tmp/linked_corpus   # ~4 min on 8 cores
```

Needs the firmware images in `inputs/firmware/`, Unicorn, pyelftools and
Capstone. Output: `corpus_outcomes.jsonl` (one row per function with the first
differing write) and `corpus_summary.json`.
