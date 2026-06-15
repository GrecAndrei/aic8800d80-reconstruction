// v23 annotated: bt_hci_cmd_dispatch_0 @ 0x123390
// Original: 123390_bt_hci_cmd_dispatch_0.c
// Primary struct: <unclustered>
//
// bt_hci_cmd_dispatch_0 @ 0x123390, size 50 bytes
// Doc: bt_hci_cmd_dispatch [bt]: Dispatch BT HCI command with op 0x81/0x40
// bt_hci_cmd_dispatch [bt]: Dispatch BT HCI command with op 0x81/0x40
int __fastcall bt_hci_cmd_dispatch_0(int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // r4
  int v5; // r1
  int v6; // r3

  v4 = (_BYTE *)rf_bus_setup_n3a8(129, a4, a3, 64);
  v5 = dword_1233C4;
  *v4 = 0;
  sub_14380C(v4 + 1, v5, 36);
  v6 = (unsigned __int8)(*v4 + 36);
  *v4 = v6;
  v4[v6 + 1] = 0;
  sub_12CBB4(v4);
  return 0;
}

