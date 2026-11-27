#!/usr/bin/env python3
"""validator_result_assign.py — keep machine-proven validator return values.

Hex-Rays dropped the assignment from two rate-validator helper calls even
though their result register is tested immediately after the call. In the
original machine, the helper result remains in r0 and is compared with 0xb;
in the reconstruction the dead call leaves v10 uninitialized, so invalid rate
bytes are accepted instead of producing an empty mask/assert.

Machine evidence:
  fmacfw_h 0x15267a bl validator; 0x15268e cmp r0,#0xb
  fmacfw   0x1527ba bl validator; 0x1527ce cmp r0,#0xb

Address-keyed and idempotent.
"""
import argparse,sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
TARGETS={
 'fmacfw_h_u02':(0x132654,'cmd_char_validate'),
 'fmacfw_u02':(0x132794,'wlan_rate_code_to_index'),
}
def transform_body(body,helper):
 old=f'{helper}(v8[1]);'
 if f'v10 = {helper}(v8[1]);' in body:return body,0,None
 if old not in body:return body,0,'dead validator call not found'
 return body.replace(old,f'v10 = {helper}(v8[1]);',1),1,None

def transform(text,addr,helper):
 import re
 m=re.search(rf'(?m)^// \w+ @ 0x{addr:x}\s*$',text)
 if not m:return text,0,'marker not found'
 end=text.find('\n// ',m.end());end=len(text) if end<0 else end
 body=text[m.start():end];out,n,err=transform_body(body,helper)
 if n:text=text[:m.start()]+out+text[end:]
 return text,n,err

def apply_one(root,short,addr,helper,check):
 for path in [root/short/'main.c']+sorted((root/short/'modules').glob('mod*.c')):
  if not path.exists():continue
  text=path.read_text(errors='replace')
  if f'@ 0x{addr:x}' not in text:continue
  out,n,err=transform(text,addr,helper)
  if n and not check:path.write_text(out)
  return n,err
 return 0,'function not found'

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--check',action='store_true');ap.add_argument('--src',default='');a=ap.parse_args();root=Path(a.src) if a.src else REPO/'src';rc=0
 for short,(addr,helper) in TARGETS.items():
  n,err=apply_one(root,short,addr,helper,a.check)
  print(f'[validator_result_assign] {short}: {n} rewrite(s)'+(' pending' if a.check else ' applied/fixed-point'))
  if err:print(f'[validator_result_assign] ERROR {short}: {err}',file=sys.stderr);rc=1
  elif n and a.check:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
