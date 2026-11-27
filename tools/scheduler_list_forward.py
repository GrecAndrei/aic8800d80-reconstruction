#!/usr/bin/env python3
"""scheduler_list_forward.py — restore machine-proven list-node forwarding.

In the three byte-cloned scheduler loops the original machine keeps the current
list node in r0 across both helper calls. At the first backward-branch call the
node was copied to r0 before the cursor advanced; Hex-Rays preserves that value
as v10. On the second call the same node is reloaded from the stack spill after
the allocation helper and is available as v17. The callee prologue immediately
moves r0 to r1 and passes it to the list insertion helper, so r0 is a genuine
input. Restore the exact arguments. Exact, idempotent, --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={'fmacfw_h_u02':'mmio_write_0','fmacfw_u02':'is_inquiry_enabled','fmacfwbt_u02':'critical_enter_1'}
def apply_image(short,check=False):
 name=SPECS[short];total=0;root=REPO/'src'/short
 repl=[
  (f'            if ( v9 == v8 )\n              break;\n            ((int (*)()){name})();',
   f'            if ( v9 == v8 )\n              break;\n            {name}((volatile uint32_t *)(uintptr_t)v10);'),
  (f'          ((int (*)()){name})();\n          v9 = v7;\n          v8 = (uint16_t)v8;',
   f'          {name}((volatile uint32_t *)(uintptr_t)v17);\n          v9 = v7;\n          v8 = (uint16_t)v8;'),
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
  n=apply_image(s,check);print(f'[scheduler_list_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
