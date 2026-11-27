#!/usr/bin/env python3
"""wrapper_arg_forward.py — restore machine-proven wrapper first arguments.

The three byte-cloned wrapper functions preserve their incoming object in r4,
call the state-machine helper with r0 still holding that same object, then
restore r0 for the tail call. The helper immediately dereferences r0. Hex-Rays
dropped the argument through a zero-input cast. Restore the exact object.
Exact, idempotent, --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={'fmacfw_h_u02':'l2c_ccb_run','fmacfw_u02':'ble_ll_adv_scan_req','fmacfwbt_u02':'update_connection_stats'}
def apply_image(short,check=False):
 name=SPECS[short];total=0;root=REPO/'src'/short
 old=f'((int (*)()){name})();'
 new=f'{name}(a1);'
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  if not p.exists():continue
  t=p.read_text(errors='replace');n=t.count(old);total+=n
  if n and not check:p.write_text(t.replace(old,new))
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[wrapper_arg_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
