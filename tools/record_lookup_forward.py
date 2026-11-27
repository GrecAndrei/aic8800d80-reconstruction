#!/usr/bin/env python3
"""record_lookup_forward.py — restore machine-proven lookup object pointers.

In the three byte-cloned address/record lookup callers the fallback path forms
r0 as object+0x22, stores that same pointer in the first output, and calls the
record-search helper. The callee immediately reads halfwords through r0.
Hex-Rays dropped the argument. Restore object+34 (0x22). Exact, idempotent,
--check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={'fmacfw_h_u02':'rf_check_status','fmacfw_u02':'find_record_by_id','fmacfwbt_u02':'lookup_handle_entry'}
def apply_image(short,check=False):
 name=SPECS[short];total=0;root=REPO/'src'/short
 old=f'((int (*)()){name})();'
 new=f'{name}((volatile uint16_t *)(uintptr_t)(v2 + 34));'
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  if not p.exists():continue
  t=p.read_text(errors='replace');n=t.count(old);total+=n
  if n and not check:p.write_text(t.replace(old,new))
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[record_lookup_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
