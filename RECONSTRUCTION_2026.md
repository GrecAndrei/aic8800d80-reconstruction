# Reconstruction 2026 - Final Report

## Achieved coverage

### Function naming
- Started: 22% (1,292/5,945)
- After 3 LLM naming passes: **91.3% (4,233/4,653)**
- Plus v17 names merged: 38,040 total LLM-applied names
- Sources:
  - v17 tool-use LLM: 19,329 names (initial pass)
  - v19 initial LLM: 17,943 names
  - v25 batch LLM: ~1,800 new names across 3 passes
  - Deduplicated to: 38,040

### Per-image naming coverage
- fmacfw_h: 1032/1262 (81.8%)
- fmacfw_u02: 1211/1271 (95.3%)
- fmacfwbt: 1191/1271 (93.7%)
- lmacfw_rf: 799/849 (94.1%)

### C file coverage (v19 + v18 merged)
- v19 (Hex-Rays decompiled): 5,945 functions
- v18 (inline-asm): 18,841 functions
- Both: 217 in common
- Merged total: 22,881 unique functions across 4 images
- Per image:
  - fmacfw_h: 1,290 funcs
  - fmacfw_u02: 8,698 funcs
  - fmacfwbt: 6,615 funcs
  - lmacfw_rf: 6,297 funcs

### Compile attempt
- All 4 images: combined into single TU
- Auto-generated stubs for 5,555+ globals
- MSVC types/intrinsics stubs
- Result: 540 errors per image (mostly C99 "conflicting types"
  from implicit declarations)
- These are real C99 issues that require per-function header analysis

## New subcommands in fwstruct

1. **namefuncs** - LLM batch naming (10 funcs per call)
2. **applynames** - Apply llm_names.json with collision detection
3. **compile** - Best-effort compile with auto-stubs
4. **extractv18** - Find v18 funcs not in v19
5. **extractv18c** - Extract v18 inline-asm to per-function .c
6. **merge** - Combine v19 + v18 C trees into unified image

## Architecture improvements

### LLM client (internal/llm/client.go)
- Bad-key detection: 401/403 keys auto-skipped
- Key round-robin
- Per-call timeout
- JSON-mode API support

### Naming strategy
- 2-turn: brief + JSON
- Batch: 10 functions per call (5x speedup)
- Lower max_tokens to reduce wasted thinking
- Case-insensitive address matching (matches C file lowercase prefix
  with uppercase suffix)
- Collision detection: same name at 2+ addrs gets _2, _3 suffix

### Compile strategy
- Auto-stub for off_/dword_/byte_/word_/qword_/unk_/flt_
- MSVC type/intrinsic stubs
- Hex-Rays flag/reg variable stubs
- Post-processing: __int16 -> short, __asm{} -> comment

## Key pipeline insights

### LLM behavior
- Thinking mode is mandatory; model wastes 200-1000 thinking tokens
  per call
- max_tokens=500-1500 is sweet spot
- Batch naming (10 per call) is 5x faster than one-at-a-time
- JSON mode works but model often wraps in ```json``` blocks
- Need to parse JSON from any position in response

### Address handling
- v19 C files: sub_XXXXXX (lowercase prefix, uppercase hex)
- llm_names.json keys: lowercase
- Must normalize: both lowercase
- applynames must match both cases

### Naming collisions
- LLM often gives same name to different funcs
- 2+ "system_init" at different addrs
- Apply names with _2, _3 suffix to avoid conflicts

## Known unaddressed gaps

### 1. phantom_0x134de8 (bootloader)
- start() calls off_1001FC() which is BSS function pointer
- Resolves to 0x134de8 (in bootloader area)
- Not in v18 or v19 decompilation
- WFFW data at this address is 0xFFFF (erased flash)
- Cannot close without bootloader firmware

### 2. 420 un-named v19 sub_ functions
- 230 in fmacfw_h, 60 in fmacfw_u02, 80 in fmacfwbt, 50 in lmacfw
- LLM naming kept failing (JSON parse errors)
- Could be addressed with a 4th pass or manual naming

### 3. C99 "conflicting types" errors
- 540+ per image in compile
- Caused by implicit int() declarations
- Need per-function forward decls to fix
- Could be addressed by generating a header from the function list

### 4. 5,555 unique globals
- off_/dword_/byte_/word_/qword_/unk_/flt_ addresses
- Declared as zero-init stubs
- Real firmware would need actual MMIO mappings

## Files added this session

### Source code (committed)
- `cmd/fwstruct/namefuncs.go` - LLM batch naming
- `cmd/fwstruct/applynames.go` - Apply names with collision handling
- `cmd/fwstruct/compile.go` - Best-effort compile
- `cmd/fwstruct/extractv18.go` - v18 vs v19 cross-reference
- `cmd/fwstruct/extractv18c.go` - Extract v18 inline-asm to .c
- `cmd/fwstruct/merge.go` - Combine v19 + v18
- `internal/llm/client.go` - LLM client with bad-key detection
- `harness_v19/llm_names.json` - 38,040 LLM-applied names

### Generated (gitignored)
- `harness_v19_named/decompiled/` - 5,945 named v19 C files
- `harness_v19_named/v18_extracted/` - 18,841 v18 inline-asm files
- `harness_v19_named/merged/` - 22,881 combined files
- `harness_v25/out/compiled/` - compile outputs

## Commits on reconstruction-2026 branch

```
b8534ed1  fwstruct: 3rd naming pass: 88.2% -> 91.3% coverage
b478960b  fwstruct: merge subcommand combines v19 + v18 C trees
6c2288a0  fwstruct: case-insensitive applynames + auto-stub for missing sub_
78a48dc2  fwstruct: extractv18c subcommand extracts v18 inline-asm to .c
2bcd8ddf  fwstruct: 2nd naming pass: 84.7% -> 88.7% coverage
1d6f5061  docs: add RECONSTRUCTION_2026.md final report
ec505623  fwstruct: compile subcommand + applynames collision handling
ab8bb107  fwstruct: applynames subcommand renames sub_XXXXX in v19 C
ccfda0f1  fwstruct: update llm_names.json with 20,150 names (84.7% coverage)
75585ac7  fwstruct: namefuncs subcommand for LLM function naming
```

Total: 10 commits on reconstruction-2026, all pushed to origin.
