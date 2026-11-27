#!/usr/bin/env python3
"""signed_halfword_assert.py — restore machine-proven signed halfword assert loads.

Hex-Rays typed the band-check guard as an unsigned volatile uint16_t load:
``**(volatile uint16_t **)off_X < 0``. In C that condition is always false,
so GCC correctly deletes it. The original machine in all four calibration
clones instead executes ``ldrsh.w`` (sign-extending halfword), compares the
result with zero, and branches to the assertion path when negative.

Machine evidence immediately after the radio-status call:
  fmacfw_h   0x121fbc  ldrsh.w r3, [r3]
  fmacfw     0x12206c  ldrsh.w r3, [r3]
  fmacfwbt   0x121ee4  ldrsh.w r3, [r3]
  lmacfw_rf  0x121f12  ldrsh.w r3, [r3]

The minimal type repair is an explicit int16_t conversion of the loaded
halfword, preserving the volatile 16-bit access while restoring the machine's
signed interpretation. Address-keyed and idempotent.
"""
import argparse,re,sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
TARGETS={
 'fmacfw_h_u02':0x101EC0,
 'fmacfw_u02':0x101F70,
 'fmacfwbt_u02':0x101DE8,
 'lmacfw_rf_u02':0x101E18,
}
PAT=re.compile(r'if \( \*\*\(volatile uint16_t \*\*\)(off_[0-9A-Fa-f]+) < 0 && a1 > 1 \)')

def transform_body(body):
 if re.search(r'\(int16_t\)\*\*\(volatile uint16_t \*\*\)\s*off_', body):
  return body,0,None
 out,n=PAT.subn(lambda m:f'if ( (int16_t)**(volatile uint16_t **) {m.group(1)} < 0 && a1 > 1 )',body,count=1)
 if n:return out,n,None
 return body,0,'machine-shaped unsigned halfword assert not found'

def transform(text,addr):
 marker=re.search(rf'(?m)^// \w+ @ 0x{addr:x}\s*$',text)
 if not marker:return text,0,'marker not found'
 end=text.find('\n// ',marker.end());end=len(text) if end<0 else end
 body=text[marker.start():end];out,n,err=transform_body(body)
 if n:text=text[:marker.start()]+out+text[end:]
 return text,n,err

def apply_one(root,short,addr,check):
 for path in [root/short/'main.c']+sorted((root/short/'modules').glob('mod*.c')):
  if not path.exists():continue
  text=path.read_text(errors='replace')
  if f'@ 0x{addr:x}' not in text:continue
  out,n,err=transform(text,addr)
  if n and not check:path.write_text(out)
  return n,err
 return 0,'function not found'

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--check',action='store_true');ap.add_argument('--src',default='');a=ap.parse_args();root=Path(a.src) if a.src else REPO/'src';rc=0
 for short,addr in TARGETS.items():
  n,err=apply_one(root,short,addr,a.check)
  print(f'[signed_halfword_assert] {short}: {n} rewrite(s)'+(' pending' if a.check else ' applied/fixed-point'))
  if err and not (err.endswith('not found') and n==0 and '(int16_t)**' in ''):print(f'[signed_halfword_assert] ERROR {short}: {err}',file=sys.stderr);rc=1
  elif n and a.check:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
