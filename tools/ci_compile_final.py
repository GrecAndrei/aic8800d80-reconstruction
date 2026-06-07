#!/usr/bin/env python3
"""CI-style compile check for the finalized reconstructed C.

For each `*.reconstructed.c` file in the given directory, bundle it with
forward decls for any undefined callees and compile with the target
cross-compiler. Returns non-zero if any file fails to compile.

Usage:
    python3 tools/ci_compile_final.py --final-dir extraction_out/reconstruction/mega7/final
"""
import argparse
import re
import subprocess
import sys
import tempfile
from pathlib import Path


def collect_callees(text: str) -> set[str]:
    """Find all `name(...);` style call sites in a C file (definitions excluded)."""
    callees = set()
    # Match forward decls: `void <name>(...);` at the start of a line
    for m in re.finditer(r"^void\s+([A-Za-z_][A-Za-z0-9_]*)\s*\([^)]*\)\s*;\s*$", text, re.MULTILINE):
        callees.add(m.group(1))
    # Also match simple calls inside bodies: `<name>();` (not at start of line,
    # not preceded by `void`, not followed by `{`).
    for m in re.finditer(r"(?<!void )([A-Za-z_][A-Za-z0-9_]*)\s*\(\s*\)\s*;", text):
        callees.add(m.group(1))
    return callees


def bundle(c_path: Path) -> tuple[str, set[str]]:
    """Read a C file and extract (bundle_text, defined_function_names)."""
    text = c_path.read_text(errors="replace")
    defined = set()
    for m in re.finditer(r"^void\s+([A-Za-z_][A-Za-z0-9_]*)\s*\([^)]*\)\s*\{", text, re.MULTILINE):
        defined.add(m.group(1))
    callees = collect_callees(text)
    needed_stubs = sorted(callees - defined - {"main", "unknown"})
    parts = [
        f"/* ci_compile_final: {c_path.name} ({len(defined)} fns, {len(needed_stubs)} stubs) */",
        "#include <stdint.h>",
        "",
    ]
    for n in needed_stubs:
        parts.append(f"void {n}(void) {{}}")
    parts.append("")
    # Strip C comments and existing #include lines to avoid collisions
    for line in text.split("\n"):
        if line.startswith("/*"):
            continue
        if line.startswith("#include"):
            continue
        parts.append(line)
    return "\n".join(parts), defined


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--final-dir", required=True, type=Path,
                    help="Directory containing the finalized *.reconstructed.c files")
    ap.add_argument("--compiler", default="aarch64-linux-gnu-gcc")
    ap.add_argument("--cflags", default="-Wall -Wno-unused-variable -Wno-unused-but-set-variable -c")
    ap.add_argument("--keep-bundle", action="store_true",
                    help="Keep the bundle file (named after the source C file)")
    args = ap.parse_args()

    if not args.final_dir.exists():
        print(f"[ci_compile_final] final dir not found: {args.final_dir}", file=sys.stderr)
        return 2
    if not args.compiler or subprocess.call(["which", args.compiler], stdout=subprocess.DEVNULL) != 0:
        print(f"[ci_compile_final] compiler not found: {args.compiler}", file=sys.stderr)
        return 2

    c_files = sorted(args.final_dir.glob("*.reconstructed.c"))
    if not c_files:
        print(f"[ci_compile_final] no .reconstructed.c files in {args.final_dir}", file=sys.stderr)
        return 2

    failed = []
    for c in c_files:
        bundle_text, defined = bundle(c)
        with tempfile.NamedTemporaryFile(suffix=".c", delete=False, mode="w",
                                         prefix=c.stem + "_", dir="/tmp") as tmp:
            tmp.write(bundle_text)
            tmp_path = Path(tmp.name)
        obj_path = tmp_path.with_suffix(".o")
        cmd = [args.compiler, *args.cflags.split(), str(tmp_path), "-o", str(obj_path)]
        rc = subprocess.call(cmd, stdout=subprocess.DEVNULL, stderr=subprocess.PIPE)
        if args.keep_bundle:
            kept = c.with_suffix(".bundle.c")
            kept.write_text(bundle_text)
            print(f"[ci_compile_final] kept bundle: {kept}")
        tmp_path.unlink(missing_ok=True)
        obj_path.unlink(missing_ok=True)
        if rc == 0:
            print(f"[ci_compile_final] OK   {c.name} ({len(defined)} fns)")
        else:
            failed.append(c.name)
            print(f"[ci_compile_final] FAIL {c.name} (gcc exit {rc})")

    if failed:
        print(f"\n[ci_compile_final] {len(failed)}/{len(c_files)} files FAILED: {failed}", file=sys.stderr)
        return 1
    print(f"\n[ci_compile_final] all {len(c_files)} files compile cleanly")
    return 0


if __name__ == "__main__":
    sys.exit(main())
