// v23 annotated: bt_reg_write_doorbell @ 0x122ef8
// Original: 122ef8_bt_reg_write_doorbell.c
// Primary struct: <unclustered>
//
// bt_reg_write_doorbell @ 0x122ef8, size 20 bytes
// Doc: bt_reg_write_doorbell [bt]: Write BT doorbell MMIO at 0x40320034 and send IPC msg 0x72
// bt_reg_write_doorbell [bt]: Write BT doorbell MMIO at 0x40320034 and send IPC msg 0x72
int __fastcall bt_reg_write_doorbell(int a1, _DWORD *a2, int a3, int a4)
{
  *(_DWORD *)off_122F0C = *a2;
  message_dispatch_n84(114, a4, a3, a4);
  return 0;
}

