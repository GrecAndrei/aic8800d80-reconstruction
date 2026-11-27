#!/usr/bin/env python3
"""channel_data_forward.py — restore machine-proven channel-data arguments.

The three byte-cloned connection-table helpers reach the channel-data helper
with r0 holding the byte at connection+0x23 (v18), r1 holding the clamped byte
just stored to connection+0x135 (the final v19 value), and r2 equal to zero:
the only fallthrough path to the call is the bit-pair scan exhausting its
seven iterations, which leaves the r2 counter at zero. The callee consumes all
three registers. Hex-Rays kept only r0. Restore the exact arguments. Exact,
idempotent, --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={'fmacfw_h_u02':'phy_get_channel_data','fmacfw_u02':'ble_ll_conn_sm_get_by_handle','fmacfwbt_u02':'get_connection_state'}
def apply_image(short,check=False):
 name=SPECS[short];total=0;root=REPO/'src'/short
 old=f'((int (*)()){name})(v18);'
 new=f'((int (*)()){name})(v18, (uint8_t)v19, 0);'
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  if not p.exists():continue
  t=p.read_text(errors='replace');n=t.count(old);total+=n
  if n and not check:p.write_text(t.replace(old,new))
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[channel_data_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
