# Linked-run comparison over every composed function

`tools/linked_recon_run.py --corpus` runs every function composed into
`src/<image>/main.c` (4,714 across the four images) twice on the same Unicorn
platform and MMIO model: once in the original binary, once in the fully linked
reconstruction (`tools/full_link.py`, callees real), and compares the ordered
peripheral writes with their values. The 25 truth-lane targets
(`docs/TRUTH_LANE_REVIEW_VERDICTS.md`) are a subset and are unchanged at
19 PASS / 0 REVIEW / 6 FAIL.

A MATCH is an identical peripheral write sequence on one default-state path
(zeroed RAM, zero arguments, boot callbacks stubbed). It is not behavioral
equivalence. 2,851 of the 3,743 matching functions write no peripheral on that path
at all in the original; for them the match says only that both runs returned without one.

## Counts

| | before | after the two rules below |
|---|---|---|
| MATCH | 3,581 | 3,743 |
| DIFFER | 433 | 271 |
| NOT_RUN (no comparison exists) | 700 | 700 |

Per image, after: fmacfw_h 1,002 / 53 / 228, fmacfw 1,087 / 59 / 136,
fmacfwbt 1,021 / 48 / 215, lmacfw_rf 633 / 111 / 121 (MATCH / DIFFER / NOT_RUN).
`metadata/linked_corpus_summary.json` is the tool's summary of the after run.

NOT_RUN, both before and after:

| count | why |
|---|---|
| 631 | the original itself does not return within 200,000 instructions when entered standalone (OS waits, event loops, asserts), so there is nothing to compare against |
| 69 | the function is one of those that `tools/libmatch.py` bound to the byte-identical toolchain routine; its name is an asm label of the library member, not a symbol of the linked image |

## Why functions differ

The tool groups a DIFFER row by where the two runs part (`group` in
`corpus_outcomes.jsonl`): the function the reconstruction is stuck in, the UART
data register, or the function executing the first differing register write.
That is a location. The causes below come from reading the groups; where a
group was not read function by function this says so.

| cause | before | after | fixable by a pipeline rule |
|---|---|---|---|
| A call site bound to the wrong one of several functions the naming gave the same name | 147 | 0 measured; 9 call sites left | yes, done (`tools/callsite_targets.py`) |
| `&dword_40504080`-style symbol materialized as a RAM variable instead of the register | 15 | 0 | yes, done (`tools/periph_symbols.py`) |
| Console text (first differing write is the UART data register 0x40032000) | 144 | 119 | no, needs IDA |
| The reconstruction does not return | 155 | 89 | no, needs IDA |
| A register write differs in value, order or presence | 134 | 63 | not by a rule found here |

The first two rows are the functions that moved from DIFFER to MATCH when
each rule was applied (147 + 15 = 162); in the before run they sat inside the
three lower rows, whose before figures therefore include them: the wrong-callee
rows were mostly "does not return" (in `pkt_buf_alloc`, `ke_msg_alloc`) and
"register write differs".

**Console text, 119.** The formatter defects already recorded for the truth
lane: the original prints `%d`-style conversions that the decompiled formatter
(`main_loop_dispatch` / `rf_parse_cal_cmd` and their per-image counterparts)
emits wrongly, because Hex-Rays left switch arms as `JUMPOUT` and the
lmacfw_rf state-table stride is in an IDA type that is not in the tree. Every
caller that logs inherits it. Needs a re-decompile at base 0x120000.

**Does not return, 89.**
- 31 stop in the microsecond delay (`send_command`, `mmio_write_cmd`,
  `clock_start`, `periph_write_read`: the same routine in the four images).
  The binary re-reads the tick counter and leaves the loop; the Hex-Rays body
  is `while ( 1 ) { v1 = 32; while ( v1-- ) ; }` with the exit gone. Needs IDA.
- 8 stop in soft-float routines that are not byte-identical to a library
  routine and whose bodies contain `JUMPOUT` (`double_compare_ord`,
  `double_divide`, ...). Needs IDA.
- 7 end by leaving the image (no function at the final pc).
- 43 stop in other functions (`prepare_debug_buffer` 10, `rf_scan_chan` 7,
  `phy_init` 3, `rf_get_chan_cfg` 3, the rest 1 or 2 each). Not read one by one.

**Register write differs, 63**, spread over 38 functions, at most 4 rows each.
The ones read are decompile shape, not something a text rule can repair
without the binary's semantics: `ipc_regs_init` (lmacfw_rf) builds a 64-bit
`v12` from an uninitialized half, so it writes 0 where the original writes an
image pointer; `osal_int_enter` calls through a code pointer that still holds
an original-image address. The rest were not read one by one.

## The two rules

Both run on the composed `src/<image>/main.c`, after `fwstruct compose`, with
the three rules of `docs/TRUTH_LANE_REVIEW_VERDICTS.md`. Neither adds a body or
renames anything; each is idempotent, has `--check`, and
`tools/test_pipeline_rules.py` asserts the tracked sources are at the fixed
point.

`tools/callsite_targets.py`. The naming dataset gave one name to several
functions; compose keeps the definitions apart as `name`, `name_1`, ... but a
call site keeps the bare name. Compose corrects that from the IDA call-edge
export, which is not in the tree and has no tail branches. The rule takes the
edges from the firmware bytes: each direct `bl` / `b` in a function's extent
whose target is the start of a composed function. A call site is rebound only
when its name is not a target of the caller in the binary and exactly one
function of the same `_N` family is a target the body does not otherwise name.
503 call-site names in 425 functions were rebound (fmacfw 66, fmacfw_h 219,
fmacfwbt 88, lmacfw_rf 130). 9 are left because the callee the binary targets
has a prototype that does not fit the call as decompiled (`-v` lists them).
Example: `store_three_halfwords_tail @ 0x12ca20` branches to 0x12c98c
(`ke_msg_send_2`); the source called `ke_msg_send @ 0x1259e0`.

`tools/periph_symbols.py`. Hex-Rays names a global after its address;
datasgen materializes `dword_40504080` as a zero-initialized variable, so
`((volatile uint32_t *)(uintptr_t)&dword_40504080)[i]` wrote a RAM word. The
address-of a `dword_/word_/byte_/unk_` symbol whose address is in
0x40000000-0x5FFFFFFF becomes that address. 87 sites (28 in each fmac image,
3 in lmacfw_rf), three symbols: `dword_40021000`, `dword_40021008`,
`dword_40504080`.

## Reproduce

```
python3 tools/callsite_targets.py --check && python3 tools/periph_symbols.py --check
make -C src check
python3 tools/full_link.py --text-base 0x800000 --out build/full_link_run
python3 tools/linked_recon_run.py --corpus --out /tmp/linked_corpus   # ~4 min on 8 cores
```

Needs the firmware images in `inputs/firmware/`, Unicorn, pyelftools and
Capstone. Output: `corpus_outcomes.jsonl` (one row per function with the first
differing write) and `corpus_summary.json`.
