#!/usr/bin/env python3
"""init_period_forward.py — restore machine-proven init period arguments.

The two byte-cloned link-active helpers load r0 from the caller object's
halfword at +0x1a0 immediately before calling the pmu/bt initializer. The
zero-input casts dropped that machine argument. Restore the exact halfword.
Exact, idempotent, --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={'fmacfw_h_u02':'pmu_init','fmacfw_u02':'bt_init'}
def apply_image(short,check=False):
 name=SPECS[short];total=0;root=REPO/'src'/short
 old=f'((int (*)()){name})();'
 new=f'{name}(*(volatile uint16_t *)((volatile uint8_t *)result + 416));'
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  if not p.exists():continue
  t=p.read_text(errors='replace');n=t.count(old);total+=n
  if n and not check:p.write_text(t.replace(old,new))
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[init_period_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
