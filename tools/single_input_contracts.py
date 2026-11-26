#!/usr/bin/env python3
"""single_input_contracts.py — correct machine-proven one-input contracts.

The byte-cloned list-processing helpers deref_and_check (fmacfw_h 0x12f414),
load_and_process_r0 (fmacfw 0x12f554), and process_pending_queue (fmacfwbt
0x12f770) begin with `ldr r4,[r0]` and preserve r0 in r5. Incoming r1 is
never read, copied, or forwarded before being clobbered; the second Hex-Rays
parameter is behaviorally nonexistent. Make the prototypes one-input and
remove ignored second arguments at call sites. Exact/idempotent.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={
 'fmacfw_h_u02':('deref_and_check',[
  ('volatile int * deref_and_check(volatile int *result, int a2)','volatile int * deref_and_check(volatile int *result)'),
  ('deref_and_check((volatile int *)(v1 - 32), v3)','deref_and_check((volatile int *)(v1 - 32))'),
  ('deref_and_check((volatile int *)dword_13A100, v6)','deref_and_check((volatile int *)dword_13A100)'),
 ]),
 'fmacfw_u02':('load_and_process_r0',[
  ('volatile int * load_and_process_r0(volatile int *result, int a2)','volatile int * load_and_process_r0(volatile int *result)'),
  ('load_and_process_r0((volatile int *)(v1 - 32), v3)','load_and_process_r0((volatile int *)(v1 - 32))'),
  ('load_and_process_r0((volatile int *)dword_13A240, v6)','load_and_process_r0((volatile int *)dword_13A240)'),
 ]),
 'fmacfwbt_u02':('process_pending_queue',[
  ('volatile int * process_pending_queue(volatile int *result, int a2)','volatile int * process_pending_queue(volatile int *result)'),
  ('process_pending_queue((volatile int *)(v1 - 32), v3)','process_pending_queue((volatile int *)(v1 - 32))'),
  ('process_pending_queue((volatile int *)dword_13A2DC, v6)','process_pending_queue((volatile int *)dword_13A2DC)'),
 ]),
}
def apply_image(short,check=False):
 root=REPO/'src'/short;total=0
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  if not p.exists():continue
  t=p.read_text(errors='replace');n=0
  for old,new in SPECS[short][1]:
   c=t.count(old);n+=c;t=t.replace(old,new)
  if n and not check:p.write_text(t)
  total+=n
 return total
def main():
 check='--check'in sys.argv;rc=0
 for short in SPECS:
  n=apply_image(short,check);print(f'[single_input_contracts] {short}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
