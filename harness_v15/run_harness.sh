#!/usr/bin/env bash
# Launch the harness orchestrator under nohup with unbuffered output.
#
# Usage:
#   harness_v15/run_harness.sh [filter] [max_workers]
#
# Examples:
#   harness_v15/run_harness.sh                  # all 20 tasks, 10 workers
#   harness_v15/run_harness.sh fail_            # only 12 FAILs, 10 workers
#   harness_v15/run_harness.sh fail_ 5          # only FAILs, 5 workers
#
# Output:
#   - PID:   harness_v15/orchestrator.pid
#   - Log:   harness_v15/orchestrator.log
#   - Per-worker logs: harness_v15/out/<task_id>/worker.log
#
# Monitor:  tail -f harness_v15/orchestrator.log
#           tail -f harness_v15/out/<task_id>/worker.log
# Status:   ps -p $(cat harness_v15/orchestrator.pid)
# Stop:     kill $(cat harness_v15/orchestrator.pid)
#           kill -9 $(cat harness_v15/orchestrator.pid)  # force

set -e

REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
HARNESS_DIR="$REPO/harness_v15"
FILTER="${1:-}"
MAX_WORKERS="${2:-10}"

cd "$REPO"

LOG="$HARNESS_DIR/orchestrator.log"
PID_FILE="$HARNESS_DIR/orchestrator.pid"
TS=$(date +%Y%m%d_%H%M%S)

# Build command
CMD=(python3 -u "$HARNESS_DIR/orchestrator.py"
     --tasks "$HARNESS_DIR/tasks/"
     --out "$HARNESS_DIR/out/"
     --config "$HARNESS_DIR/keys/keys.json"
     --max-workers "$MAX_WORKERS")
if [ -n "$FILTER" ]; then
    CMD+=(--filter "$FILTER")
fi

# Stop existing if PID file present
if [ -f "$PID_FILE" ]; then
    OLD_PID=$(cat "$PID_FILE")
    if kill -0 "$OLD_PID" 2>/dev/null; then
        echo "Stopping existing orchestrator (PID $OLD_PID)..."
        kill "$OLD_PID" 2>/dev/null || true
        sleep 2
        kill -9 "$OLD_PID" 2>/dev/null || true
    fi
    rm -f "$PID_FILE"
fi

echo "Launching orchestrator:"
printf '  %q ' "${CMD[@]}"
echo
echo "Log:     $LOG"
echo "PID:     $PID_FILE"
echo "Workers: $MAX_WORKERS"
echo "Filter:  ${FILTER:-<none>}"
echo

# Run under nohup, detached, with unbuffered output
nohup "${CMD[@]}" >"$LOG" 2>&1 &
echo $! >"$PID_FILE"

# Give it a moment to start
sleep 1
PID=$(cat "$PID_FILE")
if kill -0 "$PID" 2>/dev/null; then
    echo "Started: PID $PID"
    echo "Monitor: tail -f $LOG"
else
    echo "FAILED to start. Check $LOG for details."
    cat "$LOG"
    exit 1
fi
