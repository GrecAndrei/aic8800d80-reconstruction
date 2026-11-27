#!/usr/bin/env python3
"""softfp_double_formal.py — join a machine-proven r2:r3 double formal.

Four calibration clones use the incoming r2:r3 register pair directly as a
softfp double at their first helper call. Hex-Rays split that pair into two
32-bit formals and then reconstituted it as ``*(volatile uint64_t *)&a3``;
the compiled reconstruction instead reads unrelated compiler spill slots.
The correct ABI source is one uint64_t formal occupying r2:r3, with the
pointer argument remaining the first stack argument. Address-keyed and
idempotent.
"""
import argparse,re,sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
TARGETS={
 'fmacfw_h_u02':(0x104CC8,'float_interp'),
 'fmacfw_u02':(0x104DE0,'rf_calibrate_power'),
 'fmacfwbt_u02':(0x104C38,'bt_encrypt_wrap'),
 'lmacfw_rf_u02':(0x1047B8,'heap_calloc'),
}
OLDPROTO='volatile int *a1, int a2, unsigned int a3, int a4, volatile uint64_t *a5'
NEWPROTO='volatile int *a1, int a2, uint64_t a3, volatile uint64_t *a5'

def transform(text,name):
 n=0
 # Canonicalize the helper call even when the prototype was already repaired.
 # The raw composed body can carry either width in the dead Hex-Rays cast;
 # the machine contract is the softfp double input in r2:r3 and the integer
 # conversion result consumed as a 32-bit print argument.
 text,c=re.subn(r'\(\(uint64_t \(\*\)\(uint64_t\)\)(\w+)\)\(a3\)',lambda m:f'((int (*)(uint64_t)){m.group(1)})(a3)',text);n+=c
 if NEWPROTO in text and '*(volatile uint64_t *)&a3' not in text:
  return text,n
 text,c=re.subn(rf'\b{name}\('+re.escape(OLDPROTO)+r'\)',name+'('+NEWPROTO+')',text);n+=c
 text,c=re.subn(r'\(\((?:int|uint64_t) \(\*\)\(\)\)(\w+)\)\(\*\(volatile uint64_t \*\)&a3\)',lambda m:f'((int (*)(uint64_t)){m.group(1)})(a3)',text);n+=c
 # Callers pass the two ABI words separately; join low word then high word.
 text,c=re.subn(rf'\b{name}\((a2, v24, a9, a10, \(volatile uint64_t \*\)a11)\)',lambda m:f'{name}(a2, v24, (((uint64_t)(uint32_t)a10 << 32) | (uint32_t)a9), (volatile uint64_t *)a11)',text);n+=c
 return text,n

def apply_image(root,short,name,check):
 paths=[root/short/'main.c']+sorted((root/short/'modules').glob('mod*.c'))
 total=0
 for path in paths:
  if not path.exists():continue
  text=path.read_text(errors='replace')
  if name not in text:continue
  out,n=transform(text,name)
  if n and not check:path.write_text(out)
  total+=n
 return total

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--check',action='store_true');ap.add_argument('--src',default='');a=ap.parse_args();root=Path(a.src) if a.src else REPO/'src';rc=0
 for short,(addr,name) in TARGETS.items():
  n=apply_image(root,short,name,a.check)
  print(f'[softfp_double_formal] {short}: {n} rewrite(s)'+(' pending' if a.check else ' applied/fixed-point'))
  if n and a.check:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
