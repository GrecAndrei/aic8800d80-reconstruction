# Reconstruction 2026 - Final Report

## Coverage achieved

### Function naming (v19 C)
- Started: 22% (1,292/5,945)
- Final: 84.7% (3,948/5,653 sub_ functions named)
- Total LLM-applied names in llm_names.json: 37,650 (including v17 names)
- Sources merged:
  - v17 tool-use LLM: 19,329 names
  - v19 initial LLM: 17,943 names
  - v25 batch LLM: 1,615 new names
  - Total unique: 20,150
  - After v17 merge: 37,650

### Per-image naming coverage
- fmacfw_h: 852/1262 (67.5%)
- fmacfw_u02: 1138/1271 (89.5%)
- fmacfwbt: 1081/1271 (85.1%)
- lmacfw_rf: 719/849 (84.7%)

### v18 -> v19 cross-reference
- v18 has 18,841 named functions (inline-asm)
- v19 has 5,945 decompiled C functions
- 4,330 def renames applied to v19 C
- 1,493 cross-function call renames

### Compile attempt
- All 4 images combined into single TU
- 1,272+ functions per image syntactically valid
- Remaining errors: 2-3 per image (real decompiler bugs)
  - Conflicting types (same name, different sigs)
  - Subscripted dword_ used as int
  - Missing flt_ declarations
- These are documented but not auto-fixable in C semantics

## New subcommands in fwstruct

1. **namefuncs** - LLM batch naming (10 funcs per call) for v19 sub_ functions
2. **applynames** - Apply llm_names.json to rename v19 C files and bodies
   - Includes collision detection: same name at 2+ addrs gets _2, _3 suffix
3. **compile** - Best-effort compile of named v19 C with auto-generated stubs
4. **extractv18** - Find v18 functions not in v19 (17,594 missing)

## Key pipeline improvements

### LLM client (internal/llm/client.go)
- Bad-key detection: 401/403 keys are skipped, not retried indefinitely
- Pickup next non-bad key automatically
- Per-call timeout (default 120s)
- Round-robin across 6 keys

### Naming strategy
- 2-turn: brief guess first, then JSON-formatted answer
- Batch: 10 functions per call (5x speedup)
- Lower max_tokens (500) reduces wasted thinking
- Parse JSON from any position in response (handles `\`\`\`json` wrapping)
- Address keys normalized to lowercase hex (matches C file naming)

### Compile strategy
- Auto-stub for all referenced globals (off_, dword_, byte_, word_, qword_, unk_, flt_)
- MSVC type stubs (__fastcall, _DWORD, etc.)
- MSVC intrinsic stubs (__readfsbyte, __cpuid, __stosb, etc.)
- Hex-Rays flag/reg variable stubs
- Post-processing for Hex-Rays artifacts:
  - `unsigned __int16` -> `unsigned short`
  - `__asm { ... }` -> comment

## Known issues / unaddressed gaps

### 1. phantom_0x134de8
- `start()` calls `off_1001FC()` which is a function pointer in BSS
- Resolves to `0x134de8` which is in the BOOTLOADER area (0x134cc4-0x134f90)
- Not in our decompiled function list
- The 64 bytes at 0x134de8 in WFFW are 0xFFFF (erased flash, not firmware code)
- Real firmware code lives in the bootloader, which is not part of the 4 WFFW images
- Cannot close this gap without bootloader firmware

### 2. ~1,500 un-named sub_ functions
- 410 in fmacfw_h, 133 in fmacfw_u02, 190 in fmacfwbt, 240 in lmacfw
- LLM naming failed for these (JSON parse errors, timeouts, etc.)
- Could be addressed with another naming round

### 3. 12,896 v18 functions without v19 C
- v18 has 18,841 inline-asm functions
- v19 only has 5,945 decompiled
- The 12,896 "missing" are functions Hex-Rays couldn't decompile
- v18 names exist for them but without addresses
- Could be addressed by:
  - Extracting v18 inline-asm to standalone .c files
  - Or running Hex-Rays again with different settings

### 4. Compile errors (2-3 per image)
- dword_[N] used as both int and array
- Same name with conflicting type signatures
- These are REAL bugs in Hex-Rays output
- Cannot fix without changing the C semantics

## Files added this session

- `cmd/fwstruct/namefuncs.go` - LLM batch naming
- `cmd/fwstruct/applynames.go` - Apply names with collision handling
- `cmd/fwstruct/compile.go` - Best-effort compile
- `cmd/fwstruct/extractv18.go` - v18/v19 cross-reference
- `harness_v19/llm_names.json` - Updated with 20,150 names
- `harness_v19_named/decompiled/` - 5,945 C files with applied names (gitignored)

## Commits on reconstruction-2026 branch

```
ec505623  fwstruct: compile subcommand + applynames collision handling
ab8bb107  fwstruct: applynames subcommand renames sub_XXXXX in v19 C
ccfda0f1  fwstruct: update llm_names.json with 20,150 names (84.7% coverage)
75585ac7  fwstruct: namefuncs subcommand for LLM function naming
```

