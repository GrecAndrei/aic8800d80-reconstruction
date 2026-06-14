#!/bin/bash
# Run v19 setup + decompile for one binary
# Usage: run_v19.sh <image> [mode: setup|decompile|both]
set -e
IMG="$1"
MODE="${2:-both}"

# Resolve repo from this script's location (works regardless of cwd)
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO="$(cd "$SCRIPT_DIR/../.." && pwd)"
V19="$REPO/harness_v19"
IDB="$V19/idb/${IMG%_bin}"
ELF="$V19/elf/${IMG%_bin}_bin.elf"
LOG="$V19/log/${IMG}_$(date +%s).log"

# IDA Pro 9.x: override with $IDAT or $IDA_DIR
IDAT="${IDAT:-${IDA_DIR:-$HOME/ida-pro-9.3}/idat}"
if [ ! -x "$IDAT" ]; then
    echo "ERROR: idat not found at $IDAT"
    echo "Set IDAT env var (e.g., export IDAT=/path/to/idat)"
    exit 1
fi

if [ ! -f "$ELF" ]; then
    ELF="$V19/elf/${IMG%_bin}.elf"
fi

mkdir -p "$(dirname "$LOG")"

export V19_ROOT="$V19"

if [ "$MODE" = "setup" ] || [ "$MODE" = "both" ]; then
    echo "=== Setup $IMG ==="
    rm -f "${IDB}".*
    "$IDAT" \
        -A -B \
        -L"$LOG.setup" \
        -S"$V19/scripts/ida_setup_v19.py" \
        -o"$IDB" \
        "$ELF" >/dev/null 2>&1
    echo "  Done. Log: $LOG.setup"
fi

if [ "$MODE" = "decompile" ] || [ "$MODE" = "both" ]; then
    echo "=== Decompile $IMG ==="
    "$IDAT" \
        -L"$LOG.dec" \
        -S"$V19/scripts/ida_decompile_v19.py" \
        "$IDB.i64" >/dev/null 2>&1
    echo "  Done. Log: $LOG.dec"
    if [ -f "$V19/decompiled/$IMG/_decompile_log.json" ]; then
        python3 -c "
import json
d = json.load(open('$V19/decompiled/$IMG/_decompile_log.json'))
print(f'  Total: {d[\"total\"]}, OK: {d[\"stats\"][\"ok\"]}, fail: {d[\"stats\"][\"fail_decompile\"]}, too_small: {d[\"stats\"][\"fail_too_small\"]}, {d[\"elapsed_s\"]:.1f}s')
"
    fi
fi
