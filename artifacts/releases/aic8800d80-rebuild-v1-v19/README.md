# AIC8800D80 Firmware v19 — Hex-Rays Decompilation

This is a **human-readable C reconstruction** of the AIC8800D80 WiFi/BT
firmware images, produced by IDA Pro's Hex-Rays decompiler.

## What's in this release

| Path | Description |
|------|-------------|
| `decompiled/<image>/` | One `.c` file per function, plus a `_decompile_log.json` summary |
| `composed_v19/<image>.c` | All functions concatenated into one file per image |
| `elf/<image>.elf` | ARM Thumb ELF wrappers around the raw `.bin` firmware |
| `docs/ORACLE_RESULTS.md` | Decompilation quality report |
| `docs/README.md` | This file |

## Statistics

| Image | Total funcs | Decompiled | LLM-named | Time |
|-------|-------------|------------|-----------|------|
| fmacfw_8800d80_h_u02 | 1,285 | 1,272 | 2 | 51s |
| fmacfw_8800d80_u02 | 1,286 | 1,273 | 462 | 83s |
| fmacfwbt_8800d80_u02 | 1,286 | 1,274 | 468 | 77s |
| lmacfw_rf_8800d80_u02 | 866 | 856 | 324 | 36s |
| **Total** | **4,723** | **4,675 (98.9%)** | **1,256** | **~4 min** |

## Approach

1. **Wrap raw firmware as ARM ELF** — Each `.bin` is wrapped in a minimal ELF
   with a single LOAD segment at 0x100000 (the chip runtime address). This
   makes IDA auto-detect ARM Thumb mode.

2. **Configure IDB** — LOAD segment permissions set to RWX; MMIO phantom
   segment added at 0x40000000-0x60000000; LOAD extended to 0x200000
   (sparse) to cover BSS.

3. **Apply metadata** — 25,815 MMIO register names applied automatically;
   17,943 LLM-generated function names applied at valid code addresses.

4. **Hex-Rays decompile** — Per-function pseudo-C extracted and saved.

## v19 vs v18

| | v18 (inline-asm) | v19 (Hex-Rays) |
|---|---|---|
| Output format | `.byte 0xXX\n` directives | Real C control flow |
| Compilable | Yes (byte-faithful) | No (pseudo-C) |
| Human-readable | **No** | **Yes** |
| Variable names | None | v11, v12, etc. |
| Function signatures | `void f(void)` | Real `int f(int, int)` |
| LLM names | 1,256 of 18,841 (in selected binaries) | 1,256 of 4,675 IDA-discovered |
| MMIO names | None | REG_4024_0148 etc. |
| Total size | 6.7MB (compiled inline-asm) | 22MB (readable C) |

## Sample output

`log_queue_push2` (LLM-named) — IPC log queue:

```c
int __fastcall log_queue_push2(int a1, int a2, int a3)
{
  int v6; // r5
  int result; // r0
  char v8; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)&algn_15350C[215680] = 1;
  }
  v6 = ++*(_DWORD *)&algn_15350C[192596];
  result = (unsigned __int8)**(_BYTE **)&algn_15350C[194192];
  ...
  REG_4024_0148 = 256;
  while ( (REG_4024_0148 & 0x200) != 0 )
    ;
  ...
}
```

`msg_parse` (LLM-named) — IPC message dispatcher:

```c
int msg_parse(int result, ...)
{
  ...
  va_start(varg_r1, result);
  varg_r0 = result;
  if ( *(_DWORD *)&algn_15350C[193092] )
  {
    v1 = (unsigned __int8 *)result;
    do {
      result = (int)v1;
      v3 = *v1++;
      v2 = v3;
      ...
      if ( v2 > 0x89 ) {
        if ( (__int16)**(_WORD **)&algn_15350C[194132] < 0 && ... )
          result = sub_12F32C(1485428, 1485568, 812);
        ...
      }
      return sub_10D6C8(result, (int)varg_r1);
    }
    ...
  }
}
```

## Caveats

- **Pseudo-C, not directly compilable.** Hex-Rays output uses MSVC types
  (`_DWORD`, `__int64`) and has type-inference bugs. The post-processor in
  `harness_v19/scripts/post_process.py` handles most issues but not all.
- **`algn_15350C`** is a fallback symbol for RAM addresses that have no
  semantic label. Replace with real variable names manually.
- **`sub_XXXXXX`** are functions IDA couldn't auto-name. Most of these
  exist in v18's inline-asm; cross-reference with `harness_v17/names/`
  for LLM-proposed names.
- **MMIO names** (`REG_4032_2000`) are mechanically generated from page
  numbers. Real register names require the AIC8800D80 register manual.

## Reproducing

```bash
# Wrap firmware as ARM ELF
python3 harness_v19/scripts/make_elf.py

# Setup IDB + apply names + decompile (per binary)
harness_v19/scripts/run_v19.sh fmacfw_8800d80_h_u02_bin both
harness_v19/scripts/run_v19.sh fmacfw_8800d80_u02_bin both
harness_v19/scripts/run_v19.sh fmacfwbt_8800d80_u02_bin both
harness_v19/scripts/run_v19.sh lmacfw_rf_8800d80_u02_bin both

# Combine into single .c files per image
python3 harness_v19/scripts/post_process.py
```

Requires IDA Pro 9.x (`$IDAT (or default $HOME/ida-pro-9.3/idat)`).
