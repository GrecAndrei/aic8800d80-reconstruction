#!/usr/bin/env python3
"""power_status_forward.py — restore machine-proven packet-object arguments.

In the byte-cloned packet-status helpers, the branch that reaches the PHY/PLL
status helper is on the path where r0 still holds the original packet object
a1 (r4 was only a preserved copy). Hex-Rays emitted a zero-argument cast.
Restore `callee(a1)`. Exact, idempotent, --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={'fmacfw_h_u02':'phy_get_txpower','fmacfw_u02':'ll_conn_rx_packet_get','fmacfwbt_u02':'rf_get_pll_setting'}
def apply_image(short,check=False):
 name=SPECS[short];total=0;old=f'((int (*)()){name})();';new=f'{name}(a1);'
 root=REPO/'src'/short
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  t=p.read_text(errors='replace');n=t.count(old);total+=n
  if n and not check:p.write_text(t.replace(old,new))
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[power_status_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
