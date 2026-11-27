#!/usr/bin/env python3
"""first_arg_forward.py — restore machine-proven first arguments.

In the three byte-cloned DMA completion paths the original machine executes
`ldr r0,[r4,#0xc]; cbz r0,skip; bl callee`. Hex-Rays kept that value in
`result` but emitted the callee through a zero-argument cast. Restore the
explicit forwarding. Exact/idempotent; --check reports pending rewrites.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={
 'fmacfw_h_u02':('phy_rate_get','src/fmacfw_h_u02/modules/mod024_dma.c'),
 'fmacfw_u02':('radio_get_status','src/fmacfw_u02/modules/mod024_mac.c'),
 'fmacfwbt_u02':('rf_tx_timestamp_check','src/fmacfwbt_u02/modules/mod024_rf.c'),
}
def apply_image(short,check=False):
 name=SPECS[short][0];total=0
 root=REPO/'src'/short
 old=f'result = ((int (*)()){name})();';new=f'result = {name}(result);'
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  if not p.exists():continue
  t=p.read_text(errors='replace');n=t.count(old);total+=n
  if n and not check:p.write_text(t.replace(old,new))
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[first_arg_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
