#!/bin/bash
# Robust tier-based Drive upload. Persists state to a file in the truth-lane
# state dir (which we upload first, so the state survives if we crash).
#
# Usage: tools/upload_to_drive.sh [--state-file PATH]
set -u
set -o pipefail

REPO=/home/grec-alexander/Downloads/aic8800d80
RECON=$REPO/extraction_out/reconstruction
TRUTH_STATE=$RECON/truth_lane_state
STATE=$TRUTH_STATE/drive_upload_state.txt
LOG=$RECON/drive_upload.log
FOLDER_ID="15Eed1elahUOUPbILjO35ClBurzykKLDl"
STAGING=/tmp/opencode/upload_staging
mkdir -p "$STAGING"

# Args
while [[ $# -gt 0 ]]; do
    case "$1" in
        --state-file) STATE="$2"; shift 2 ;;
        *) echo "unknown arg: $1" >&2; exit 2 ;;
    esac
done

log() {
    local msg="[$(date +%H:%M:%S)] $*"
    echo "$msg" | tee -a "$LOG"
}

# ----- State helpers -----
# State file format: tier_name|status|tarball|file_id
# status: PENDING | UPLOADED | FAILED
declare -A SEEN
if [[ -f "$STATE" ]]; then
    while IFS='|' read -r tier status tarball fid; do
        [[ -z "$tier" || "$tier" == "#"* ]] && continue
        SEEN[$tier]="$status|$tarball|$fid"
    done < "$STATE"
fi

is_uploaded() {
    [[ "${SEEN[$1]:-}" == UPLOADED* ]]
}

# ----- Tier definitions -----
# Format: tier_name|archive_path|description
TIERS=(
    "truth_lane_state|$TRUTH_STATE|truth_lane state and scorecards (small, upload first so state persists)"
    "truth_lane_eval|$RECON/truth_lane_eval|truth_lane eval outputs (per-version scorecards)"
    "recon_top|$RECON/recon_manifest.json $RECON/recon_strict.jsonl $RECON/recon_union.jsonl $RECON/recon_workset.jsonl $RECON/ida_jobs.json|recon top-level + ida_jobs"
    "mega_embed|$RECON/mega_embed|reconstruction mega_embed cache"
    "mega7|$RECON/mega7|reconstruction mega7 (3.0G raw)"
    "mega7_p1|$RECON/mega7_p1|reconstruction mega7_p1 (3.0G raw)"
    "mega7_p2|$RECON/mega7_p2|reconstruction mega7_p2 (2.7G raw)"
    "ida_jobs|$RECON/ida_jobs|ida jobs dir"
)

# Fleets are split per subdirectory to keep each archive small.
FLEET_DIR=$RECON/fleets
if [[ -d "$FLEET_DIR" ]]; then
    while IFS= read -r d; do
        name=$(basename "$d")
        size=$(du -sm "$d" 2>/dev/null | awk '{print $1}')
        log "fleet subdir: $name ($size MB)"
        TIERS+=("fleet_$name|$d|fleet subdir $name")
    done < <(find "$FLEET_DIR" -mindepth 1 -maxdepth 1 -type d | sort)
fi

# ----- Upload function -----
upload_archive() {
    local tarball="$1"
    local tier="$2"
    local desc="$3"
    local base=$(basename "$tarball")
    log "UPLOAD: $base ($desc)"

    # Check existing file_id and skip if already on Drive.
    local meta
    meta=$(gws drive files list --json '{"parent": "'"$FOLDER_ID"'"}' --query "name = '$base'" 2>&1 | head -200)
    if echo "$meta" | grep -q '"id"'; then
        local existing_id
        existing_id=$(echo "$meta" | python3 -c "import sys, json
try:
    data = json.loads(sys.stdin.read())
    if isinstance(data, dict) and 'files' in data:
        for f in data['files']:
            if f.get('name') == '$base':
                print(f.get('id', ''))
                break
    elif isinstance(data, list):
        for f in data:
            if isinstance(f, dict) and f.get('name') == '$base':
                print(f.get('id', ''))
                break
except Exception as e:
    pass
")
        if [[ -n "$existing_id" ]]; then
            log "  -> already on Drive as $existing_id, skipping"
            echo "$tier|UPLOADED|$tarball|$existing_id" >> "$STATE"
            return 0
        fi
    fi

    # Upload with timeout (30 min max per file).
    local up_out
    cd /tmp/opencode  # gws --upload needs the file in CWD
    up_out=$(timeout 1800 gws drive files create --json '{"name": "'"$base"'", "parents": ["'"$FOLDER_ID"'"]}' --upload "$tarball" 2>&1)
    local rc=$?
    cd - >/dev/null

    if [[ $rc -ne 0 ]]; then
        log "  -> FAILED rc=$rc"
        echo "$tier|FAILED|$tarball|" >> "$STATE"
        return 1
    fi

    # Extract the first JSON object from up_out (gws prefixes output with
    # a keyring banner line that isn't JSON).
    local fid
    fid=$(echo "$up_out" | python3 -c "
import sys, json, re
text = sys.stdin.read()
# Find the first top-level JSON object or array.
m = re.search(r'[\{\[]', text)
if not m:
    sys.exit(1)
chunk = text[m.start():]
try:
    data = json.loads(chunk)
except Exception:
    sys.exit(1)
if isinstance(data, dict):
    print(data.get('id', ''))
elif isinstance(data, list) and data:
    print(data[0].get('id', '') if isinstance(data[0], dict) else '')
")
    if [[ -z "$fid" ]]; then
        log "  -> no file id in response: $up_out" | head -5
        echo "$tier|FAILED|$tarball|" >> "$STATE"
        return 1
    fi
    log "  -> uploaded as $fid"
    echo "$tier|UPLOADED|$tarball|$fid" >> "$STATE"
    return 0
}

# ----- Tier execution -----
log "Starting upload session. State file: $STATE"

for tier_def in "${TIERS[@]}"; do
    IFS='|' read -r tier path desc <<< "$tier_def"
    if is_uploaded "$tier"; then
        log "SKIP $tier (already uploaded)"
        continue
    fi

    log "TIER: $tier | $desc"
    log "  path: $path"

    # Build the archive. We support either a single dir or a space-separated
    # list of files.
    archive="$STAGING/${tier}.tar.gz"
    rm -f "$archive"

    if [[ -d "$path" ]]; then
        log "  archiving $path -> $archive"
        # Use single-threaded gzip for predictability and to avoid OOM.
        tar -C "$(dirname "$path")" -cf - "$(basename "$path")" 2>/dev/null \
            | gzip -1 > "$archive"
    else
        # Space-separated list of files
        log "  archiving files -> $archive"
        tar -C / -cf - $path 2>/dev/null | gzip -1 > "$archive"
    fi

    if [[ ! -s "$archive" ]]; then
        log "  archive empty or missing: $archive"
        echo "$tier|FAILED|$archive|" >> "$STATE"
        continue
    fi
    local_size=$(du -h "$archive" | awk '{print $1}')
    log "  archive size: $local_size"

    if ! upload_archive "$archive" "$tier" "$desc"; then
        log "  tier $tier failed; will resume on next run"
    fi

    # Always clean up the local archive to save disk.
    rm -f "$archive"
done

log "Upload session complete."
log "Final state:"
cat "$STATE" | tee -a "$LOG"
