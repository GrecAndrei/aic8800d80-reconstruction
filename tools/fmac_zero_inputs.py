#!/usr/bin/env python3
"""fmac_zero_inputs.py — correct machine-proven zero-input fmac contracts.

Two byte-cloned scheduler families are zero-input in the original machine code:

* rf_is_idle / rf_calib_init overwrite r0 before their first call. Incoming
  r1 is incidentally preserved into list_length, but that callee consumes only
  r0, so no incoming register can affect behavior. The a2 argument visible in
  Hex-Rays is a pass-through artifact.
* rf_get_flag / read_state_flag / bt_ctrl_main_task are the main event
  dispatcher clone. Every dispatch input is loaded from global memory or a
  function table after the incoming argument registers have been overwritten;
  the machine code never consumes r0-r2.

The rewrite also removes the call-site casts that Hex-Rays emitted because of
those invented parameters. Exact, idempotent, and checkable.
"""
import argparse,sys
from pathlib import Path
REPO=Path(__file__).resolve().parent.parent
SPECS={
 'fmacfw_h_u02':[
  ('int rf_is_idle(int a1, int a2) {','int rf_is_idle() {'),
  ('int rf_is_idle(int a1, int a2);','int rf_is_idle();'),
  ('((int (*)())list_length)((void *)(uintptr_t)(off_11340C), a2);','list_length((volatile uint32_t **)(uintptr_t)off_11340C);'),
  ('((int (*)())rf_is_idle)()','rf_is_idle()'),
  ('void rf_get_flag(int a1, int a2, int a3, int a4) {','void rf_get_flag() {'),
  ('void rf_get_flag(int a1, int a2, int a3, int a4);','void rf_get_flag();'),
  ('rf_get_flag(result, v10, v11, *(volatile uint8_t *)off_113884);','rf_get_flag();'),
  ('((int (*)())rf_get_flag)()','rf_get_flag()'),
  ('int fault_status_read(int a1, int a2) {','int fault_status_read() {'),
  ('int fault_status_read(int a1, int a2);','int fault_status_read();'),
  ('((int (*)())fault_status_read)()','fault_status_read()'),
  ('int test_command_queue_process(int a1, int a2) {','int test_command_queue_process() {'),
  ('int test_command_queue_process(int a1, int a2);','int test_command_queue_process();'),
  ('((int (*)())test_command_queue_process)()','test_command_queue_process()'),
 ],
 'fmacfw_u02':[
  ('void read_state_flag(int a1, int a2, int a3, int a4) {','void read_state_flag() {'),
  ('void read_state_flag(int a1, int a2, int a3, int a4);','void read_state_flag();'),
  ('read_state_flag(result, v10, v11, *(volatile uint8_t *)off_1139C4);','read_state_flag();'),
  ('((int (*)())read_state_flag)()','read_state_flag()'),
  ('int check_nvic_irq_status(int a1, int a2) {','int check_nvic_irq_status() {'),
  ('int check_nvic_irq_status(int a1, int a2);','int check_nvic_irq_status();'),
  ('((int (*)())check_nvic_irq_status)()','check_nvic_irq_status()'),
  ('int parse_large_ioctl(int a1, int a2) {','int parse_large_ioctl() {'),
  ('int parse_large_ioctl(int a1, int a2);','int parse_large_ioctl();'),
  ('((int (*)())parse_large_ioctl)()','parse_large_ioctl()'),
 ],
 'fmacfwbt_u02':[
  ('int rf_calib_init(int a1, int a2) {','int rf_calib_init() {'),
  ('int rf_calib_init(int a1, int a2);','int rf_calib_init();'),
  ('((int (*)())list_length)((void *)(uintptr_t)(off_1133A8), a2);','list_length((volatile uint32_t **)(uintptr_t)off_1133A8);'),
  ('((int (*)())rf_calib_init)()','rf_calib_init()'),
  ('void bt_ctrl_main_task(int a1, int a2, int a3, int a4) {','void bt_ctrl_main_task() {'),
  ('void bt_ctrl_main_task(int a1, int a2, int a3, int a4);','void bt_ctrl_main_task();'),
  ('bt_ctrl_main_task(result, v10, v11, *(volatile uint8_t *)off_113820);','bt_ctrl_main_task();'),
  ('((int (*)())bt_ctrl_main_task)()','bt_ctrl_main_task()'),
  ('int check_nvic_irq(int a1, int a2) {','int check_nvic_irq() {'),
  ('int check_nvic_irq(int a1, int a2);','int check_nvic_irq();'),
  ('((int (*)())check_nvic_irq)()','check_nvic_irq()'),
  ('int ke_event_send_1(int a1, int a2) {','int ke_event_send_1() {'),
  ('int ke_event_send_1(int a1, int a2);','int ke_event_send_1();'),
  ('((int (*)())ke_event_send_1)()','ke_event_send_1()'),
 ],
}

def apply_image(short,check=False):
 root=REPO/'src'/short;total=0
 paths=[root/'main.c']+sorted((root/'modules').glob('mod*.c'))
 for p in paths:
  if not p.exists():continue
  t=p.read_text(errors='replace');n=0
  for old,new in SPECS[short]:
   c=t.count(old);n+=c;t=t.replace(old,new)
  if n and not check:p.write_text(t)
  total+=n
 return total

def main():
 check='--check'in sys.argv;rc=0
 for short in SPECS:
  n=apply_image(short,check)
  print(f'[fmac_zero_inputs] {short}: {n} rewrite(s) {"pending" if check else "applied/fixed-point"}')
  if check and n:rc=1
 return rc
if __name__=='__main__':sys.exit(main())
