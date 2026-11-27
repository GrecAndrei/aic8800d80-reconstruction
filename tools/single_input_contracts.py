#!/usr/bin/env python3
"""single_input_contracts.py — correct machine-proven one-input contracts.

The byte-cloned list-processing helpers deref_and_check (fmacfw_h 0x12f414),
load_and_process_r0 (fmacfw 0x12f554), and process_pending_queue (fmacfwbt
0x12f770) begin with `ldr r4,[r0]` and preserve r0 in r5. Incoming r1 is
never read, copied, or forwarded before being clobbered; the second Hex-Rays
parameter is behaviorally nonexistent. Make the prototypes one-input and
remove ignored second arguments at call sites.

The same one-input correction applies to the byte-cloned packet helpers
tx_pending_check (fmacfw_h 0x1161e4), process_tx_packet (fmacfw 0x116324),
and process_rx_status (fmacfwbt 0x116764). A CFG scan shows incoming r1 never
survives to an explicit read, call, or return; the decompiler only reused r1
as scratch after overwriting it, so the body keeps a local a2 declaration
while the prototype takes one input. Exact/idempotent.

The byte-cloned ll_parse_pdu / rx_packet_parse_header / rx_handle_frame key
helpers are likewise one-input: r0 is read immediately, while r1-r3 are first
overwritten before any read in the original machine code. Their a2-a4
parameters are register-scratch artifacts.
"""
import sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={
 'fmacfw_h_u02':('deref_and_check',[
  ('volatile int * deref_and_check(volatile int *result, int a2)','volatile int * deref_and_check(volatile int *result)'),
  ('deref_and_check((volatile int *)(v1 - 32), v3)','deref_and_check((volatile int *)(v1 - 32))'),
  ('deref_and_check((volatile int *)dword_13A100, v6)','deref_and_check((volatile int *)dword_13A100)'),
  ('int tx_pending_check(int a1, int a2)','int tx_pending_check(int a1)'),
  ('int tx_pending_check(int a1) {\n  int v2; // r3','int tx_pending_check(int a1) {\n  int a2;\n  int v2; // r3'),
  ('tx_pending_check(a2, a4)','tx_pending_check(a2)'),
  ('int ll_parse_pdu(volatile char *a1, int a2, int a3, int a4)','int ll_parse_pdu(volatile char *a1)'),
  ('((int (*)())ll_parse_pdu)(a2)','ll_parse_pdu(a2)'),
 ]),
 'fmacfw_u02':('load_and_process_r0',[
  ('volatile int * load_and_process_r0(volatile int *result, int a2)','volatile int * load_and_process_r0(volatile int *result)'),
  ('load_and_process_r0((volatile int *)(v1 - 32), v3)','load_and_process_r0((volatile int *)(v1 - 32))'),
  ('load_and_process_r0((volatile int *)dword_13A240, v6)','load_and_process_r0((volatile int *)dword_13A240)'),
  ('int process_tx_packet(int a1, int a2)','int process_tx_packet(int a1)'),
  ('int process_tx_packet(int a1) {\n  int v2; // r3','int process_tx_packet(int a1) {\n  int a2;\n  int v2; // r3'),
  ('process_tx_packet(a2, a4)','process_tx_packet(a2)'),
  ('int rx_packet_parse_header(volatile char *a1, int a2, int a3, int a4)','int rx_packet_parse_header(volatile char *a1)'),
  ('((int (*)())rx_packet_parse_header)(a2)','rx_packet_parse_header(a2)'),
 ]),
 'fmacfwbt_u02':('process_pending_queue',[
  ('volatile int * process_pending_queue(volatile int *result, int a2)','volatile int * process_pending_queue(volatile int *result)'),
  ('process_pending_queue((volatile int *)(v1 - 32), v3)','process_pending_queue((volatile int *)(v1 - 32))'),
  ('process_pending_queue((volatile int *)dword_13A2DC, v6)','process_pending_queue((volatile int *)dword_13A2DC)'),
  ('int process_rx_status(int a1, int a2)','int process_rx_status(int a1)'),
  ('int process_rx_status(int a1) {\n  int v2; // r3','int process_rx_status(int a1) {\n  int a2;\n  int v2; // r3'),
  ('process_rx_status(a2, a4)','process_rx_status(a2)'),
  ('int rx_handle_frame(volatile char *a1, int a2, int a3, int a4)','int rx_handle_frame(volatile char *a1)'),
  ('((int (*)())rx_handle_frame)(a2)','rx_handle_frame(a2)'),
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
