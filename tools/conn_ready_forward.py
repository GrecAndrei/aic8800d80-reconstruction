#!/usr/bin/env python3
"""conn_ready_forward.py — restore machine-proven ready-check arguments.

The three-input connection-ready helpers genuinely consume r0 (connection
object), r1 (slot index), and r2 (paired-state flag). In the byte-cloned
lookup helpers the first call is reached only when the slot-0 paired byte is
zero, so the machine passes (object, 0, 0); the second is reached only when
the slot-1 paired byte is zero, so it passes (object, 1, 0). In the
byte-cloned subframe parsers r0 is the computed connection object v6, r1 is
message byte a2[1], and r2 remains 1 from the message initialization store.
Hex-Rays dropped those arguments. Restore them exactly. Exact, idempotent,
--check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={'fmacfw_h_u02':'lll_conn_ready_check','fmacfw_u02':'rf_calib_required','fmacfwbt_u02':'bt_conn_get_state'}
def apply_image(short,check=False):
 name=SPECS[short];total=0;root=REPO/'src'/short
 repl=[
  (f'result = ((int (*)(void)){name})();',f'result = {name}(v4, 0, 0);'),
  (f'result = ((int (*)()){name})(v4, 1);',f'result = {name}(v4, 1, 0);'),
  (f'*v4 = ((int (*)()){name})();',f'*v4 = {name}(v6, a2[1], 1);'),
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
  n=apply_image(s,check);print(f'[conn_ready_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
