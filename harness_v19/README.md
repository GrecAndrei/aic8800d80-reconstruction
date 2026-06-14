# harness_v19 — Hex-Rays Decompilation Pipeline

This harness produces **human-readable C** from the AIC8800D80 WiFi/BT
firmware binaries using **IDA Pro 9.3's Hex-Rays decompiler**.

The output complements v18's byte-faithful inline-asm layer: v18
preserves the original bytes exactly but is unreadable to humans;
v19 is the same firmware rendered as proper C with control flow,
parameters, and local variables.

## Scripts

| Script | Purpose |
|--------|---------|
| `make_elf.py` | Wrap raw `.bin` as ARM ELF (loads at 0x100000) |
| `ida_setup_v19.py` | Configure IDB, apply names, prepare for decompile |
| `ida_decompile_v19.py` | Run Hex-Rays on every function, save pseudo-C |
| `post_process.py` | Combine per-function .c into single .c per binary |
| `run_v19.sh` | Run setup + decompile for one binary |

## Data files

| File | Purpose | Source |
|------|---------|--------|
| `mmio_registers.json` | 25,815 MMIO register names | `harness_v17/tools.py` |
| `llm_names.json` | 17,943 LLM-generated function names | `harness_v17/names/` |
| `boundaries.json` | Function boundaries from v15 lift | `harness_v16/all_fns.json` |
| `structs.json` | 6 struct field definitions | `harness_v17/tools.py` |

## Generated files (gitignored)

| File | Purpose |
|------|---------|
| `idb/*.i64` | IDA Pro databases (2.1 GB each) |
| `decompiled/<img>/` | Per-function .c files (~1,272 per binary) |
| `log/*.log` | Run logs |
| `composed/*.c` | All functions concatenated per binary |

## Pipeline

```
inputs/firmware/<img>.bin
   |
   v
make_elf.py → harness_v19/elf/<img>.elf
   |
   v
idat -A -B -S ida_setup_v19.py elf/<img>.elf
   ↓
   ├─ LOAD perm RWX (was RX, blocks data naming)
   ├─ Extend LOAD to 0x200000 (sparse, covers BSS)
   ├─ Add MMIO phantom segment 0x40000000-0x60000000
   ├─ Apply 25,815 MMIO register names
   ├─ Apply LLM function names (5,741 across binaries)
   ├─ Apply docstrings as comments
   └─ Save IDB → harness_v19/idb/<img>.i64
   |
   v
idat -S ida_decompile_v19.py idb/<img>.i64
   ↓
   For each function:
     cfunc = idaapi.decompile(ea)
     save to decompiled/<img>/<addr>_<name>.c
   |
   v
post_process.py
   ↓
   harness_v19/composed/<img>.c (all functions concatenated)
   |
   v
artifacts/releases/aic8800d80-rebuild-v1-v19/
   ↓
   aic8800d80-rebuild-v1-v19.tar.gz (4.7 MB)
```

## Key IDA Pro 9.3 tricks

These were discovered during v19 development:

### 1. Raw binary → ARM ELF

IDA's raw binary loader prompts for 32/64-bit and defaults to 64-bit
AArch64. To force 32-bit ARM:
- Wrap the binary in a minimal ARM ELF with one LOAD segment at 0x100000
- Set entry point with Thumb bit set (`+1`)

### 2. Data symbol naming requires RWX segment

By default, ELF loader marks LOAD as RX. `set_name()` at data
addresses returns False on RX segments. Fix:
```python
seg.perm = ida_segment.SEGPERM_READ | ida_segment.SEGPERM_WRITE | ida_segment.SEGPERM_EXEC
```

### 3. BSS/data addresses need `create_data()` first

For addresses in BSS (uninitialized RAM), `set_name()` returns False
because there's no data item. Create one first:
```python
ida_bytes.create_data(addr, 3, 4, idaapi.BADADDR)  # FF_DWORD
ida_name.set_name(addr, name, ida_name.SN_FORCE)
```

### 4. MMIO addresses need a phantom segment

For 0x40000000-0x60000000 addresses, add a phantom segment first:
```python
ida_segment.add_segm(0, 0x40000000, 0x60000000, "MMIO", "DATA")
```

### 5. Hex-Rays output is cached

Re-running the setup script doesn't re-decompile. Use:
```python
cfunc = idaapi.decompile(ea, flags=idaapi.DECOMP_NO_CACHE)
```

## Statistics (achieved)

| Binary | Total | Decompiled | LLM-named | Time |
|--------|-------|------------|-----------|------|
| fmacfw_8800d80_h_u02 | 1,285 | 1,272 (99.0%) | 2 | 51s |
| fmacfw_8800d80_u02 | 1,286 | 1,273 (99.0%) | 462 | 83s |
| fmacfwbt_8800d80_u02 | 1,286 | 1,274 (99.1%) | 468 | 77s |
| lmacfw_rf_8800d80_u02 | 866 | 856 (98.8%) | 324 | 36s |
| **Total** | **4,723** | **4,675 (98.9%)** | **1,256** | **~4 min** |

## Sample output

`log_queue_push2` (LLM-named, ~30 lines):

```c
// log_queue_push2 @ 0x110edc, size 238 bytes
// Doc: log_queue_push2 [util]: Push a log entry onto the log queue with 3 parameters
int __fastcall log_queue_push2(int a1, int a2, int a3)
{
  int v6; // r5
  int result; // r0
  char v8; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_110FCC = 1;
  }
  v6 = ++*(_DWORD *)off_110FF8;
  result = (unsigned __int8)**(_BYTE **)off_110FD0;
  ...
  REG_4024_0148 = 256;
  while ( (REG_4024_0148 & 0x200) != 0 ) ;
  ...
}
```

## Caveats

- **Pseudo-C, not directly compilable.** Hex-Rays output uses MSVC
  types and has type-inference bugs. The post-processor in
  `post_process.py` handles most issues but not all.
- **`algn_15350C`** is a fallback for RAM addresses that have no
  semantic label. Replace with real names manually.
- **`sub_XXXXXX`** are functions IDA couldn't auto-name. Most exist
  in v18; cross-reference with `harness_v17/names/`.
- **MMIO names** are mechanically generated; real names require
  the AIC8800D80 register manual.
- **Some functions decompile to wrong output** (Hex-Rays mis-handles
  IVT/padding, recursive functions, etc.). 4 of 4,723 fail outright;
  more have partial issues.

## Reproduction

```bash
# Setup (one-time)
python3 harness_v19/scripts/make_elf.py

# Per-binary decompile (~1 minute each)
harness_v19/scripts/run_v19.sh fmacfw_8800d80_h_u02_bin both
harness_v19/scripts/run_v19.sh fmacfw_8800d80_u02_bin both
harness_v19/scripts/run_v19.sh fmacfwbt_8800d80_u02_bin both
harness_v19/scripts/run_v19.sh lmacfw_rf_8800d80_u02_bin both

# Combine into single .c per binary
python3 harness_v19/scripts/post_process.py
```

Requires IDA Pro 9.3 (`/home/grec-alexander/ida-pro-9.3/idat`).
Total runtime: ~4 minutes for all 4 binaries (decompile only).
Total runtime: ~10 minutes including setup and IDB save.
