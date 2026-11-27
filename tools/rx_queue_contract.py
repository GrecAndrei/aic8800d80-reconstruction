#!/usr/bin/env python3
"""rx_queue_contract.py — correct the machine-proven rx_queue_init arity.

Machine truth (lmacfw_rf): rx_queue_init consumes only r0/r1. On its a2==0
path it tail-calls rf_state_process with registers preserved, but
rf_state_process (hardware 0x138ec8) is itself zero-input on every path: it
overwrites r0 before use and never consumes input r1/r2. Therefore the third
rx_queue_init parameter is behaviorally nonexistent. Address-keyed,
idempotent; --check reports pending rewrites.
"""
import argparse,re,sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
ADDR=0x11B3A4
REPL=[
("int rx_queue_init(int result, int a2, int a3) {","int rx_queue_init(int result, int a2) {"),
("int rx_queue_init(int result, int a2, int a3);","int rx_queue_init(int result, int a2);"),
("rf_state_process(result, 0, a3);","rf_state_process();"),
]
MARKER_RE=re.compile(r"(?m)^// (\w+) @ 0x([0-9a-fA-F]+)\s*$")
def span(text):
 s=[(int(m.group(2),16),m.start()) for m in MARKER_RE.finditer(text)];s.sort()
 for i,(a,p) in enumerate(s):
  if a==ADDR:return p,s[i+1][1] if i+1<len(s) else len(text)
def apply(check=False):
 root=REPO/'src/lmacfw_rf_u02';total=0;seen=False
 for p in [root/'main.c']+sorted((root/'modules').glob('mod*.c')):
  if not p.exists():continue
  t=p.read_text(errors='replace');sp=span(t)
  n=0
  if sp is None:
   body=""
  else:
   seen=True;body=t[sp[0]:sp[1]]
  for old,new in REPL:
   c=body.count(old);n+=c;body=body.replace(old,new)
  out=t
  if sp is not None:
   out=t[:sp[0]]+body+t[sp[1]:]
  # The prototype lives in main.c outside the function body.
  if p.name=='main.c':
   c=out.count(REPL[1][0]);n+=c;out=out.replace(REPL[1][0],REPL[1][1])
  total+=n
  if n and not check:p.write_text(out)
 return total,seen
def main():
 check='--check'in sys.argv;n,seen=apply(check);print(f'[rx_queue_contract] {n} rewrite(s)');return 1 if (not seen or (check and n)) else 0
if __name__=='__main__':sys.exit(main())
