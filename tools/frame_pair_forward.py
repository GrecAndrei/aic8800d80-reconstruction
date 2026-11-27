#!/usr/bin/env python3
"""frame_pair_forward.py — restore machine-proven frame-pair forwarding.

The byte-cloned event-dispatch wrappers populate two stack out-parameters,
load them back into r0/r1, explicitly zero r2, and only then call their
packet/security helper. Hex-Rays retained the out-parameters as _frame.v2 and
_frame.v3 but emitted a zero-argument cast. Restore the exact machine contract
(_frame.v2, _frame.v3, 0). Exact, idempotent, --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={
 'fmacfw_h_u02':'ble_parse_event',
 'fmacfw_u02':'rx_packet_handler_3',
 'fmacfwbt_u02':'rx_security_check',
}
def apply_image(short,check=False):
 name=SPECS[short];total=0
 old=f'((int (*)()){name})();';new=f'{name}(_frame.v2, _frame.v3, 0);'
 root=REPO/'src'/short
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  t=p.read_text(errors='replace');n=t.count(old);total+=n
  if n and not check:p.write_text(t.replace(old,new))
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[frame_pair_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
