#!/usr/bin/env python3
"""char_validate_forward.py — restore machine-proven character inputs.

The byte-cloned packet-character scan loops execute `ldrb r0,[r4,#1]`
immediately before the validation helper. r4 is the cursor Hex-Rays calls v8.
Restore the exact v8[1] argument. Exact, idempotent, --check-able.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={'fmacfw_h_u02':'cmd_char_validate','fmacfw_u02':'wlan_rate_code_to_index'}
def apply_image(short,check=False):
 name=SPECS[short];total=0
 root=REPO/'src'/short
 repl=[(f'((int (*)()){name})();',f'{name}(v8[1]);')]
 if name=='wlan_rate_code_to_index':
  repl.append(('((int (*)())is_valid_rate_code)();','is_valid_rate_code(v8[1]);'))
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
  n=apply_image(s,check);print(f'[char_validate_forward] {s}: {n} rewrite(s)')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
