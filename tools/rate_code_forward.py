#!/usr/bin/env python3
"""rate_code_forward.py — restore machine-proven rate-code inputs.

In the byte-cloned frame-header builders the original machine loads the halfword
at config+0x50 into r0, stores it into the output frame, and never overwrites
r0 before the rate-code helper call. Hex-Rays emitted a zero-argument cast.
Restore the exact halfword argument. Exact, idempotent, --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={'fmacfw_h_u02':'phy_get_rate_code','fmacfw_u02':'util_extract_bits','fmacfwbt_u02':'rf_get_chan_index'}
def apply_image(short,check=False):
 name=SPECS[short];total=0
 old=f'((int (*)()){name})();';new=f'{name}(*(volatile uint16_t *)(v8 + 0x50));'
 for p in sorted((REPO/'src'/short/'modules').glob('mod*.c')):
  t=p.read_text(errors='replace');n=t.count(old);total+=n
  if n and not check:p.write_text(t.replace(old,new))
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[rate_code_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
