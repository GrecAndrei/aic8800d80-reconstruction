#!/usr/bin/env python3
"""triple_arg_forward.py — restore machine-proven three-argument forwarding.

The byte-cloned TX completion/setup functions establish the same register
contract before calling their packet-processing helper:

  ldr r5,[r0,#0xc0]   ; v3
  ldrh r1,[r1,#4]     ; v4
  ldr  r8,[r5,#0x1c]  ; v6
  mov r2,r8
  mov r4,r0           ; r0 itself remains a1
  bl helper

Hex-Rays retained all three values in v3/v4/v6 but emitted the helper through
a zero-argument cast. Restore the exact arguments (a1, v4, v6). The rewrite
is exact, idempotent, and --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={
 'fmacfw_h_u02':('ble_ll_conn_process','src/fmacfw_h_u02/modules/mod037.c'),
 'fmacfw_u02':('rx_process_packet_1','src/fmacfw_u02/modules/mod037.c'),
 'fmacfwbt_u02':('rf_calibrate_init','src/fmacfwbt_u02/modules/mod034.c'),
}
def apply_image(short,check=False):
 name,rel=SPECS[short];p=REPO/rel
 # Module numbering is not stable across regeneration; scan all modules.
 root=REPO/'src'/short
 paths=[root/'main.c']+sorted((root/'modules').glob('mod*.c'))
 total=0
 old=f'((int (*)()){name})();';new=f'{name}(a1, v4, v6);'
 for p in paths:
  t=p.read_text(errors='replace');n=t.count(old);total+=n
  if n and not check:p.write_text(t.replace(old,new))
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[triple_arg_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
