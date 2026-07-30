# Runbook

Common commands and operator workflow for the AIC8800D80 firmware
reconstruction project.

## Quick reference

| Task | Command |
|------|---------|
| **Cross-compile C source tree** | `make -C src check` |
| **Run Go structure analyzer** | `bin/fwstruct all` |
| **Run Go hybrid ledger & verification** | `bin/fwhybrid all` |
| **Run ARM QEMU emulator tests** | `arm-none-eabi-gcc --specs=nosys.specs -marm scratch/run_comprehensive_tests.c -o scratch/run_comprehensive_tests_arm && qemu-arm-static scratch/run_comprehensive_tests_arm` |
| Reproduce v19 release | `python3 harness_v19/scripts/make_elf.py` + `harness_v19/scripts/run_v19.sh <img>` |
| Run v18 inline-asm | `python3 harness_v17/disasm_to_asm.py` |
| Build release tarballs | `tar -czf artifacts/releases/aic8800d80-rebuild-v1-src.tar.gz src/` |

## Environment

Required tools:
- **IDA Pro 9.3** at `$IDAT (or default $HOME/ida-pro-9.3/idat)`
- **r2** (radare2) for disasm
- **arm-linux-gnueabihf-gcc** for cross-compile
- **Python 3.10+** with `idat` Python extensions
- 8 GB disk for IDA databases (2 GB each × 4 binaries)

Environment variables:
- `V19_ROOT`: path to `harness_v19/` (default: `harness_v19`)

## v19 decompilation pipeline (latest)

### One-time setup

```bash
# Wrap raw .bin files as ARM ELF (one-time per firmware revision)
python3 harness_v19/scripts/make_elf.py
```

This produces `harness_v19/elf/fmacfw_8800d80_h_u02.elf` etc.

### Per-binary decompilation

```bash
# Setup IDB + decompile
harness_v19/scripts/run_v19.sh fmacfw_8800d80_h_u02_bin both

# Or separate steps
harness_v19/scripts/run_v19.sh fmacfw_8800d80_h_u02_bin setup      # IDB only
harness_v19/scripts/run_v19.sh fmacfw_8800d80_h_u02_bin decompile  # decompile only
```

Output:
- IDB: `harness_v19/idb/fmacfw_8800d80_h_u02.i64` (2.1 GB, gitignored)
- Decompiled: `harness_v19/decompiled/fmacfw_8800d80_h_u02_bin/*.c` (one per function)

### Post-processing

```bash
# Combine per-function .c into single .c per binary
python3 harness_v19/scripts/post_process.py

# Output:
# harness_v19/composed/fmacfw_8800d80_h_u02_bin.c
# harness_v19/composed/fmacfw_8800d80_u02_bin.c
# harness_v19/composed/fmacfwbt_8800d80_u02_bin.c
# harness_v19/composed/lmacfw_rf_8800d80_u02_bin.c
```

### Build release

```bash
# Copy outputs to release dir
mkdir -p artifacts/releases/aic8800d80-rebuild-v1-v19/composed_v19
mkdir -p artifacts/releases/aic8800d80-rebuild-v1-v19/decompiled
mkdir -p artifacts/releases/aic8800d80-rebuild-v1-v19/named_samples
mkdir -p artifacts/releases/aic8800d80-rebuild-v1-v19/elf

cp harness_v19/decompiled/* artifacts/releases/aic8800d80-rebuild-v1-v19/decompiled/
cp harness_v19/composed/* artifacts/releases/aic8800d80-rebuild-v1-v19/composed_v19/
cp harness_v19/elf/* artifacts/releases/aic8800d80-rebuild-v1-v19/elf/

# Tar
tar -czf artifacts/releases/aic8800d80-rebuild-v1-v19.tar.gz \
  -C artifacts/releases/ aic8800d80-rebuild-v1-v19
```

## v18 byte-faithful pipeline

```bash
# Generate inline-asm C for each named function
python3 harness_v17/disasm_to_asm.py

# Output:
# artifacts/releases/aic8800d80-rebuild-v1/composed_v18/*.reconstructed_v18.c
```

## v17 LLM tool-use pipeline

```bash
# 1. Generate naming for new functions (5 fns/sec)
python3 harness_v17/naming_batch.py

# 2. Disambiguate variant names
python3 harness_v17/disambiguate.py

# 3. Integrate names into v15 composed
python3 harness_v17/integrate.py

# 4. Run compile-oracle
python3 harness_v17/compile_oracle_run.py
```

## IDA Pro 9.3 setup details

### ELF wrapper trick

The raw `.bin` files load at chip address 0x100000. To get IDA to:

1. **load as ARM (not x86 metapc)**: wrap in ELF
2. **default to 32-bit (not 64-bit AArch64)**: use ARM ELF
3. **start at 0x100000**: ELF with `p_vaddr = 0x100000`
4. **treat as Thumb code**: IDA auto-detects from entry point LSB

See `harness_v19/scripts/make_elf.py` for the wrapper generator.

### IDB configuration

Run `harness_v19/scripts/ida_setup_v19.py` on the ELF. The script:
1. Sets LOAD segment perm to RWX (default is RX, blocks data naming)
2. Extends LOAD to 0x200000 with SEGMOD_SPARSE (covers BSS without 1GB allocation)
3. Adds MMIO phantom segment at 0x40000000-0x60000000
4. Applies 25,815 MMIO register names
5. Seeds function boundaries from `boundaries.json`
6. Applies LLM-generated function names

### Hex-Rays quirks

- Output is **cached** — changes to symbols require re-decompile
- Use `idaapi.decompile(ea, flags=idaapi.DECOMP_NO_CACHE)` for fresh
- Output uses MSVC types (`__int64`, `_DWORD`, etc.) — needs post-processing
- `set_name` returns False for addresses outside any segment — add
  phantom segments first
- For BSS addresses, call `create_data()` BEFORE `set_name()`

## Disk space management

```bash
# Clean up IDBs to free 8GB
rm -rf harness_v19/idb/*.i64

# Rerun to regenerate
harness_v19/scripts/run_v19.sh <img> setup
```

The /tmp partition is 7.5GB tmpfs — keep IDB usage low.

## Common issues

### "idaapi.get_inf_structure() doesn't exist"
Use `ida_ida.get_inf_structure()` instead. Or just don't call it
— the structure_t has a `perm` field directly.

### "set_name returns False"
The address is outside any defined segment. Add a phantom segment
covering the address range first.

### "Autoanalysis subsystem has been initialized" hangs
The setup script needs `idaapi.auto_wait()` to wait for analysis
to complete. Make sure it's called early in the script.

### Disk full on IDB
IDBs are 2.1 GB each. Use `harness_v19/idb/` and clean up old ones.
Don't put IDBs in /tmp.

## Verification

To verify a v19 decompile is correct:
1. Find a named function in `named_samples/`
2. Open the original binary in IDA
3. Navigate to the function
4. Press F5 to decompile
5. Compare with the saved output

To verify byte-faithfulness (v18):
```bash
python3 harness_v17/compile_oracle_run.py
# Should show ~89% at 100% match
```

## Publishing

When a new release is ready:
1. Update `docs/REBUILD_MILESTONE.md` with new metrics
2. Create release dir under `artifacts/releases/`
3. Update top-level `README.md` and `AGENTS.md`
4. Build tarball, force-add with `git add -f`
5. Commit with descriptive message
6. Push to origin

## Cloud upload (Drive)

```bash
# Requires gcloud SDK and valid Drive auth
bash tools/upload_to_drive.sh
```

Currently blocked — gws token expired. Manual browser login needed.
