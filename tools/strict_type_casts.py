#!/usr/bin/env python3
"""strict_type_casts.py — type-only casts for machine-proven integer values.

These sites pass the exact machine value but Hex-Rays types the source as int
while the callee prototype expects a pointer. The custom firmware memset also
has a volatile-int-first-parameter prototype even when the machine passes a
byte-frame pointer. The casts are value-preserving and semantically neutral.
Exact, idempotent, --check-able; scans both monolithic main.c and module
slices so fresh compose and the tracked demonolithized tree share one rule.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={
 'fmacfw_h_u02':[('memset(_frame.a2, 0, 20);','memset((volatile int *)(uintptr_t)_frame.a2, 0, 20);')],
 'fmacfwbt_u02':[('memset(_frame.a2, 0, 20);','memset((volatile int *)(uintptr_t)_frame.a2, 0, 20);')],
 'lmacfw_rf_u02':[
  ('memset(_frame.v95, 0, 20);','memset((volatile int *)(uintptr_t)_frame.v95, 0, 20);'),
  ('patch_trampoline(a1 - 12)','patch_trampoline((volatile uint16_t *)(uintptr_t)(a1 - 12))'),
 ],
}
def apply_image(short,check=False):
 total=0;root=REPO/'src'/short
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  if not p.exists():continue
  t=p.read_text(errors='replace');n=0
  for old,new in SPECS[short]:
   c=t.count(old);n+=c;t=t.replace(old,new)
  total+=n
  if n and not check:p.write_text(t)
 return total
def main():
 check='--check'in sys.argv;rc=0
 for s in SPECS:
  n=apply_image(s,check);print(f'[strict_type_casts] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
