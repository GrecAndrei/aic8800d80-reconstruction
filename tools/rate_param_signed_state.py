#!/usr/bin/env python3
"""rate_param_signed_state.py — restore signed rate-control state halfwords.

The rate-parameter validator keeps a global signed 16-bit rate-control state
behind v13. Hex-Rays emitted that object as uint16_t, so C zero-extends it and
every ``v14 >= 0`` / ``**v13 < 0`` assertion guard is optimized the wrong way.
The original machine in all three fmac clones repeatedly uses ``ldrsh.w`` for
the same object, proving a signed int16_t access.

Machine evidence includes:
  fmacfw_h   0x15d996/0x15d9c2/0x15da26
  fmacfw     0x15dad6/0x15db02/0x15db66
  fmacfwbt   0x15db72/0x15db9e/0x15dc02

Address-keyed, body-local, and idempotent.
"""
import argparse,re,sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
TARGETS={
 'fmacfw_h_u02':0x13D950,
 'fmacfw_u02':0x13DA90,
 'fmacfwbt_u02':0x13DB2C,
}
def transform_body(body):
 if 'volatile int16_t **v13' in body:
  return body,0,None
 if 'volatile uint16_t **v13' not in body:
  return body,0,'v13 declaration not found'
 out=body.replace('volatile uint16_t **v13','volatile int16_t **v13',1)
 out,n=re.subn(r'\(volatile uint16_t \*\*\)(off_[0-9A-Fa-f]+)',r'(volatile int16_t **)\1',out)
 if not n:
  return body,0,'state-object casts not found'
 return out,1,None

def transform(text,addr):
 m=re.search(rf'(?m)^// \w+ @ 0x{addr:x}\s*$',text)
 if not m:return text,0,'marker not found'
 end=text.find('\n// ',m.end());end=len(text) if end<0 else end
 body=text[m.start():end];out,n,err=transform_body(body)
 if n:text=text[:m.start()]+out+text[end:]
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
  print(f'[rate_param_signed_state] {short}: {n} rewrite(s)'+(' pending' if a.check else ' applied/fixed-point'))
  if err:print(f'[rate_param_signed_state] ERROR {short}: {err}',file=sys.stderr);rc=1
  elif n and a.check:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
