#!/usr/bin/env python3
"""ops_object_forward.py — restore machine-proven ops object arguments.

The three byte-cloned lock/type predicates preserve their incoming object in
r4 and invoke the ops helper with that same object still in r0. The helper's
inner machine body reads fields through r0. Hex-Rays dropped the argument.
Restore the exact object. Exact, idempotent, --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={'fmacfw_h_u02':'cfm_call_ops','fmacfw_u02':'wlc_ops_wrapper','fmacfwbt_u02':'bt_link_type'}
def apply_image(short,check=False):
 name=SPECS[short];total=0;root=REPO/'src'/short
 old=f'if ( !((int (*)()){name})() ) return 0;'
 new=f'if ( !{name}(a1) ) return 0;'
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  if not p.exists():continue
  t=p.read_text(errors='replace');n=t.count(old);total+=n
  if n and not check:p.write_text(t.replace(old,new))
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[ops_object_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
