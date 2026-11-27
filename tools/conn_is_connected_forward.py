#!/usr/bin/env python3
"""conn_is_connected_forward.py — restore machine-proven fourth arguments.

The four-input connection helpers genuinely consume r0-r3: r0 selects the
connection object, r1/r2 form the output pointer, and r3 is an optional
alternate output base. In the three byte-cloned first call sites r3 is the
flag byte just tested for equality with zero, so the machine passes trailing
zero. In the three byte-cloned second call sites the machine explicitly moves
the connection index variable (v2/r8) into r3. Hex-Rays dropped both trailing
arguments. Restore them exactly. Exact, idempotent, --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={'fmacfw_h_u02':'bt_conn_is_connected','fmacfw_u02':'is_conn_active','fmacfwbt_u02':'bt_check_conn_active'}
def apply_image(short,check=False):
 name=SPECS[short];total=0;root=REPO/'src'/short
 repl=[
  (f'((int (*)()){name})(a2, v10, *(volatile uint16_t *)(a2 + 4));',
   f'((int (*)()){name})(a2, v10, *(volatile uint16_t *)(a2 + 4), 0);'),
  (f'((int (*)()){name})(v5, v14, v15 + 24);',
   f'((int (*)()){name})(v5, v14, v15 + 24, v2);'),
 ]
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  if not p.exists():continue
  t=p.read_text(errors='replace');n=0
  for old,new in repl:
   c=t.count(old);n+=c;t=t.replace(old,new)
  total+=n
  if n and not check:p.write_text(t)
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[conn_is_connected_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
