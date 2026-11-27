#!/usr/bin/env python3
"""bsscfg_lookup_forward.py — restore machine-proven BSS lookup arguments.

In the three byte-cloned control-block allocation functions the original
machine reaches both lookup-helper calls with r0 still holding the zero-extended
byte loaded from a1+0x6b (the channel/connection index written into the message)
and r1 still holding the zero-extended stack byte v10[0] produced by the slot
search. The callees immediately consume both r0 and r1 as table indices.
Hex-Rays dropped both values through zero-argument casts. Restore the exact
arguments. Exact, idempotent, --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={'fmacfw_h_u02':'bsscfg_index','fmacfw_u02':'sta_lookup_by_bss','fmacfwbt_u02':'update_entries_from_config'}
def apply_image(short,check=False):
 name=SPECS[short];total=0;root=REPO/'src'/short
 old=f'((int (*)()){name})();'
 new=f'{name}(*(volatile uint8_t *)(a1 + 107), (uint8_t)v6);'
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  if not p.exists():continue
  t=p.read_text(errors='replace');n=t.count(old);total+=n
  if n and not check:p.write_text(t.replace(old,new))
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[bsscfg_lookup_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
