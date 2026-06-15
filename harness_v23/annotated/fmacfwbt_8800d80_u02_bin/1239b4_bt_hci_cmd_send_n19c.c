// v23 annotated: bt_hci_cmd_send_n19c @ 0x1239b4
// Original: 1239b4_bt_hci_cmd_send_n19c.c
// Primary struct: <unclustered>
//
// bt_hci_cmd_send_n19c @ 0x1239b4, size 32 bytes
// Doc: bt_hci_cmd_send_n19c [bt]: Send BT HCI command opcode 0x0d
// bt_hci_cmd_send_n19c [bt]: Send BT HCI command opcode 0x0d
int __fastcall bt_hci_cmd_send_n19c(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r3

  rf_chan_param_lookup_n1f0(*a2);
  message_dispatch_n84(13, a4, a3, v4);
  return 0;
}

