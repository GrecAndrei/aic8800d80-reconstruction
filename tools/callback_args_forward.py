#!/usr/bin/env python3
"""callback_args_forward.py — restore machine-proven callback arguments.

The three byte-cloned frame builders reach the callback helper with r0 set to
the table object just stored in _frame.v55, r1 loaded from the sequence-counter
stack field _frame.v60, and r2 set to the constant 2. The callee consumes all
three registers. Hex-Rays dropped every argument. Restore them exactly. Exact,
idempotent, --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={'fmacfw_h_u02':'call_callback','fmacfw_u02':'event_timer_callback','fmacfwbt_u02':'rx_invoke_cb'}
def apply_image(short,check=False):
 name=SPECS[short];total=0;root=REPO/'src'/short
 old=f'((int (*)()){name})();'
 new=f'{name}(_frame.v55, _frame.v60, 2);'
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  if not p.exists():continue
  t=p.read_text(errors='replace');n=t.count(old);total+=n
  if n and not check:p.write_text(t.replace(old,new))
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[callback_args_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
