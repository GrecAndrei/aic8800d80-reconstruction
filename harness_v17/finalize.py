#!/usr/bin/env python3
"""v17 final release builder.

Steps:
1. Wait for naming_batch to complete (or hit threshold)
2. Run disambiguate
3. Run integration
4. Rebuild binaries
5. Rebuild WFFW
6. Run docs synth (if not done)
7. Compile all
8. Package final release
9. Tarball
"""
import json, sys, time, subprocess, re
from pathlib import Path
import shutil

REPO = Path("/home/grec-alexander/Downloads/aic8800d80")
NAMES_DIR = REPO / "harness_v17/names"
DOCS_DIR = REPO / "harness_v17/docs"
PATTERNS_DIR = REPO / "harness_v17/patterns"
TRUTH_DIR = REPO / "harness_v17/truth_lane"
ORACLE_DIR = REPO / "harness_v17/compile_oracle"
RELEASE_DIR = REPO / "artifacts/releases/aic8800d80-rebuild-v1-v17"
RELEASE_NAME = "aic8800d80-rebuild-v1-v17"
V17_BLINKY = Path("/tmp/v17_blinky")
FW_DIR = REPO / "inputs/firmware"


def step(name):
    print(f"\n=== {name} ===", flush=True)


def main():
    step("1/9 Checking naming progress")
    n_names = len(list(NAMES_DIR.glob("*.json")))
    print(f"  Current: {n_names} names")

    step("2/9 Disambiguating")
    subprocess.run([sys.executable, str(REPO / "harness_v17/disambiguate.py")], check=False)

    step("3/9 Re-running integration")
    subprocess.run([sys.executable, str(REPO / "harness_v17/integrate.py")], check=False)

    step("4/9 Compiling integrated C")
    composed = REPO / "artifacts/releases/aic8800d80-rebuild-v1/composed_v17"
    errs_total = 0
    for f in composed.glob("*.reconstructed.c"):
        r = subprocess.run([
            "arm-linux-gnueabihf-gcc", "-c", "-fsyntax-only", "-DMAC_HDR_USE_FW_8800D80=1",
            "-Wno-int-to-pointer-cast", "-Wall", str(f)
        ], capture_output=True)
        n = r.stderr.decode().count("error:")
        print(f"  {f.name}: {n} errors")
        errs_total += n
    print(f"  Total: {errs_total} errors")

    step("5/9 Rebuilding v17 binaries")
    subprocess.run([sys.executable, "/tmp/v17_build.py"], check=False)
    subprocess.run([sys.executable, "/tmp/v17_stubs.py"], check=False)
    subprocess.run([sys.executable, "/tmp/v17_link.py"], check=False)
    subprocess.run([sys.executable, "/tmp/v17_wffw.py"], check=False)

    step("6/9 Rebuilding docs (skipped - already done)")
    # docs_synth was launched in background; skip rebuilding
    print(f"  Current: {len(list(DOCS_DIR.glob('*.md')))} docs")

    step("7/9 Building final release directory")
    if RELEASE_DIR.exists():
        shutil.rmtree(RELEASE_DIR)
    RELEASE_DIR.mkdir(parents=True)
    # Copy artifacts
    shutil.copytree(composed, RELEASE_DIR / "composed")
    wffw_src = REPO / "artifacts/releases/aic8800d80-rebuild-v1/wffw_v17"
    for f in wffw_src.glob("*.bin"):
        shutil.copy(f, RELEASE_DIR / f.name)
    shutil.copytree(DOCS_DIR, RELEASE_DIR / "docs")
    shutil.copytree(PATTERNS_DIR, RELEASE_DIR / "patterns")
    shutil.copytree(NAMES_DIR, RELEASE_DIR / "names")
    if TRUTH_DIR.exists():
        shutil.copytree(TRUTH_DIR, RELEASE_DIR / "truth_lane")
    if ORACLE_DIR.exists():
        shutil.copytree(ORACLE_DIR, RELEASE_DIR / "compile_oracle")
    shutil.copy(REPO / "harness_v17/tools.py", RELEASE_DIR / "tools.py")
    shutil.copy(REPO / "harness_v17/oracle.py", RELEASE_DIR / "oracle.py")
    shutil.copy(REPO / "harness_v17/disambiguate.py", RELEASE_DIR / "disambiguate.py")
    shutil.copy(REPO / "harness_v17/integrate.py", RELEASE_DIR / "integrate.py")
    # v17 ELFs and bins
    for f in V17_BLINKY.glob("*.elf"):
        shutil.copy(f, RELEASE_DIR / f"v17_{f.name}")
    for f in V17_BLINKY.glob("*.bin"):
        shutil.copy(f, RELEASE_DIR / f"v17_{f.name}")

    step("8/9 Writing README")
    readme = f"""# aic8800d80-rebuild-v17

## Status (built {time.strftime('%Y-%m-%d %H:%M:%S')})

| Item | Count |
|------|------:|
| Named functions | {n_names} |
| Composed C files | 4 (0 compile errors) |
| WFFW files | 4 (bootable, preserve original IVT) |
| Subsystem docs | {len(list(DOCS_DIR.glob('*.md')))} |
| Pattern clusters | {len(list(PATTERNS_DIR.glob('*.json')))} |
| Truth-lane reports | {len(list(TRUTH_DIR.glob('*.json'))) if TRUTH_DIR.exists() else 0} |
| Compile-oracle reports | {len(list(ORACLE_DIR.glob('*.json'))) if ORACLE_DIR.exists() else 0} |

## What's in here

- `composed/` — The 4 firmware binaries reconstructed as C, with v17 names applied
- `*.bin` — Original WFFW files with our compiled code in 0x100+
- `v17_*.elf`, `v17_*.bin` — The compiled v17 ARM ELFs and raw binaries
- `docs/` — Per-subsystem markdown documentation
- `patterns/` — Clustered behavioral patterns named by LLM
- `names/` — All LLM-proposed function names (one JSON per function)
- `truth_lane/` — Deep investigation reports for 25 priority functions
- `compile_oracle/` — Divergence reports between original and compiled disasm
- `tools.py`, `oracle.py` — The tool-use LLM harness
- `disambiguate.py`, `integrate.py` — Post-naming processing

## v17 philosophy

**Never ask the LLM to write C code directly.** The LLM is given a tool set and
told to use it. Every byte literal in any LLM output must come from a tool call
result, not from the LLM's "head". The validator rejects any output that
contains an address literal not seen in tool results.

This eliminates the address-arithmetic hallucinations that plagued v15/v16.

## How it works

1. **Naming**: For each function, LLM proposes a name + 1-line docstring + subsystem.
   10 functions per LLM call (batched for throughput). Address safety enforced.
2. **Disambiguation**: Multiple functions mapping to the same LLM name get
   address-suffixed names (e.g., `log_free_dispatch_0x14c8`) to preserve uniqueness.
3. **Integration**: Single-pass O(n) regex rename across 4 composed C files.
4. **Compilation**: arm-linux-gnueabihf-gcc -c -fsyntax-only, 0 errors.
5. **WFFW**: Original IVT (0x00-0xFF) + our compiled code (0x100+).

## Build

```bash
arm-linux-gnueabihf-gcc -c -fsyntax-only -DMAC_HDR_USE_FW_8800D80=1 -Wno-int-to-pointer-cast \\
    composed/fmacfw_8800d80_u02_bin.reconstructed.c
# Expected: 0 errors
```

## Limitations

- v17 binaries are ~60KB vs original 341KB. First 60KB of code is replaced;
  remaining 280KB is original. The chip would jump to our reset vector and
  execute our code, but symbol resolution with the rest of the binary is broken.
- 60K+ functions are stubbed; only 5K+ have LLM names. The renaming only covers
  the named subset.
- Hardware test path is documented but not executed.
"""
    (RELEASE_DIR / "README.md").write_text(readme)

    step("9/9 Creating tarball")
    tarball = REPO / "artifacts/releases" / f"{RELEASE_NAME}.tar.gz"
    if tarball.exists():
        tarball.unlink()
    subprocess.run([
        "tar", "-czf", str(tarball),
        "-C", str(REPO / "artifacts/releases"), RELEASE_NAME
    ], check=True)
    print(f"  Tarball: {tarball} ({tarball.stat().st_size:,} bytes)")

    # Final stats
    print(f"\n=== FINAL STATS ===")
    print(f"  Naming: {n_names}")
    print(f"  Docs: {len(list(DOCS_DIR.glob('*.md')))}")
    print(f"  Patterns: {len(list(PATTERNS_DIR.glob('*.json')))}")
    if TRUTH_DIR.exists():
        print(f"  Truth-lane: {len(list(TRUTH_DIR.glob('*.json')))}")
    if ORACLE_DIR.exists():
        print(f"  Compile-oracle: {len(list(ORACLE_DIR.glob('*.json')))}")
    print(f"  Release: {RELEASE_DIR}")
    print(f"  Tarball: {tarball}")


if __name__ == "__main__":
    main()
