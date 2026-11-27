#!/usr/bin/env python3
"""formatter_integer_codegen.py — keep integer-only formatter clones out of VFP.

The four embedded printf-style formatter clones have no floating-point source
semantics, but GCC reuses a VFP double register as a convenient 64-bit zero
store in their prologue. That instruction sets CONTROL.FPCA on Cortex-M4.
The original formatter path uses integer stores, so the exception dump clone
later reads CONTROL=0 in the original and CONTROL=4 in the reconstruction.

Measured machine evidence (lmacfw_rf_u02, boot_zero probe at 0x11394c):
  original: no FP instruction before MRS CONTROL; CONTROL=0
  recon:    vldr d7 at rf_parse_cal_cmd+0x30 before MRS; CONTROL=4

``general-regs-only`` is semantics-preserving here because these formatter
bodies contain no floating-point operations; it merely prevents an
implementation-only register-class choice. Address-keyed, idempotent.
"""
import argparse,re,sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
TARGETS={
 'fmacfw_h_u02':(0x12DFDC,'rx_process_packet_2'),
 'fmacfw_u02':(0x12E11C,'rf_cal_init'),
 'fmacfwbt_u02':(0x12E344,'main_loop_dispatch'),
 'lmacfw_rf_u02':(0x11EBB4,'rf_parse_cal_cmd'),
}
ATTR='__attribute__((target("general-regs-only"))) '
def transform(text,addr,name):
 marker=f'// {name} @ 0x{addr:x}'
 if marker not in text:marker=f'// {name} @ 0x{addr:X}'
 if marker not in text:return text,0,'marker not found'
 pos=text.index(marker);end=text.find('\n// ',pos+1);end=len(text) if end<0 else end
 body=text[pos:end]
 sig=f'unsigned int {name}(volatile char *a1, int a2, unsigned int a3, volatile uint8_t *a4, volatile unsigned int *a5) {{'
 if ATTR+sig in body:return text,0,None
 if sig not in body:return text,0,'formatter signature not found'
 body=body.replace(sig,ATTR+sig,1)
 return text[:pos]+body+text[end:],1,None
def apply_file(path,addr,name,check):
 text=path.read_text(errors='replace');out,n,err=transform(text,addr,name)
 if n and not check:path.write_text(out)
 return n,err
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--check',action='store_true');ap.add_argument('--src',default='');a=ap.parse_args();root=Path(a.src) if a.src else REPO/'src';rc=0
 for short,(addr,name) in TARGETS.items():
  done=False
  for path in [root/short/'main.c']+sorted((root/short/'modules').glob('mod*.c')):
   if not path.exists():continue
   text=path.read_text(errors='replace')
   if name not in text or (f'@ 0x{addr:x}' not in text and f'@ 0x{addr:X}' not in text):continue
   n,err=apply_file(path,addr,name,a.check);done=True;break
  if not done:n,err=0,'function not found'
  print(f'[formatter_integer_codegen] {short}: {n} rewrite(s)'+(' pending' if a.check else ' applied/fixed-point'))
  if err:print(f'[formatter_integer_codegen] ERROR {short}: {err}',file=sys.stderr);rc=1
  elif n and a.check:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
