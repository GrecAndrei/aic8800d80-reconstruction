#!/usr/bin/env python3
"""busy_zero_contracts.py — correct machine-proven zero-input busy helpers.

The three byte-cloned busy-flag wrappers forward incoming r0 into their inner
interrupt-status helpers, but those helpers overwrite r0 before any read; the
same is true of their tail targets. Incoming r0 is therefore behaviorally
nonexistent. Correct the wrappers to zero-input contracts, stop forwarding the
artifact into the already zero-input inner helpers, and call them directly.
Exact, idempotent, --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={
 'fmacfw_h_u02':('run_with_busy_flag','check_hw_fw_status'),
 'fmacfw_u02':('enable_radio_clock','rf_irq_status_check'),
 'fmacfwbt_u02':('global_flag_set','mac_irq_handler_1'),
}
def apply_image(short,check=False):
 outer,inner=SPECS[short];total=0;root=REPO/'src'/short
 repl=[
  (f'void {outer}(int a1)',f'void {outer}()'),
  (f'{inner}(a1);',f'{inner}();'),
  (f'((int (*)()){outer})();',f'{outer}();'),
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
  n=apply_image(s,check);print(f'[busy_zero_contracts] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
