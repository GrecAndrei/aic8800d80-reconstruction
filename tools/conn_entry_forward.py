#!/usr/bin/env python3
"""conn_entry_forward.py — restore machine-proven connection-entry arguments.

In the byte-cloned message-building helpers the original machine computes the
connection-table entry in r0 with `mla r0,#1320,index,base`, tests its byte at
+1224, and leaves that same pointer in r0 at both helper calls. r1 holds the
message byte a2[1] on the nonzero path and zero on the zero path. Hex-Rays
dropped the r0 dataflow through zero-argument casts. Restore the exact
arguments. Exact, idempotent, --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={
 'fmacfw_h_u02':('lll_conn_phy_get','lll_conn_phy_ld_get','dword_12348C'),
 'fmacfw_u02':('llc_get_conn_state','llc_get_conn_role','dword_1235CC'),
 'fmacfwbt_u02':('bt_conn_set_flag','bt_conn_get_flag','dword_123800'),
}
def apply_image(short,check=False):
 two,one,base=SPECS[short];total=0
 repl=[
  (f'((int (*)()){two})();',f'{two}({base} + 1320 * v5, a2[1]);'),
  (f'((int (*)()){one})();',f'{one}({base} + 1320 * v5);'),
 ]
 root=REPO/'src'/short
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  t=p.read_text(errors='replace');n=0
  for old,new in repl:c=t.count(old);n+=c;t=t.replace(old,new)
  total+=n
  if n and not check:p.write_text(t)
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[conn_entry_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
