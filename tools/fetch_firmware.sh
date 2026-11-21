#!/bin/bash
# Fetch the raw AIC8800D80 firmware blobs (gitignored) into inputs/firmware/
# from the Orange Pi firmware repo, pinned and md5-checked.
#
# Usage: tools/fetch_firmware.sh
set -euo pipefail

REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DEST=$REPO/inputs/firmware
SRC=https://raw.githubusercontent.com/orangepi-xunlong/firmware/dc163b0ed2e0272d9ee31977a0e0a04884f0ae61/aic8800d80

FILES="
e9c5cf5f3488aa8ad4e4da87daf95c47 fmacfw_8800d80_h_u02.bin
b39016c6531b5a0f6f5012eca50bc258 fmacfw_8800d80_u02.bin
0e019570d669891fafe9d98cf1849519 fmacfwbt_8800d80_u02.bin
cb7ca12626e9628e2cda80cd1cb6b403 lmacfw_rf_8800d80_u02.bin
313babc74ae8b1d44dc0e0a4c4c73686 fw_patch_table_8800d80_u02.bin
8e83d7b94620c2a5444b2aaaab1a510d fw_patch_8800d80_u02.bin
f546881a81b960d89a672578eb45a809 fw_adid_8800d80_u02.bin
"

mkdir -p "$DEST"
echo "$FILES" | while read -r md5 name; do
    [ -z "$name" ] && continue
    out=$DEST/$name
    if [ ! -f "$out" ] || [ "$(md5sum "$out" | cut -d' ' -f1)" != "$md5" ]; then
        curl -sSfL -o "$out.tmp" "$SRC/$name"
        mv "$out.tmp" "$out"
    fi
    got=$(md5sum "$out" | cut -d' ' -f1)
    if [ "$got" != "$md5" ]; then
        echo "md5 mismatch for $name: got $got, want $md5" >&2
        exit 1
    fi
    echo "ok $name"
done
