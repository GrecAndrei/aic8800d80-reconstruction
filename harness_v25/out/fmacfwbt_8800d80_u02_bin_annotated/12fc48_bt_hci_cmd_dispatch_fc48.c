// fwstruct annotate: 12fc48_bt_hci_cmd_dispatch_fc48.c
// bt_hci_cmd_dispatch_fc48 @ 0x12fc48, size 50 bytes
// Doc: bt_hci_cmd_dispatch_fc48 [bt]: BT HCI command dispatch entry (returns 2 == pending)
// bt_hci_cmd_dispatch_fc48 [bt]: BT HCI command dispatch entry (returns 2 == pending)
int __fastcall bt_hci_cmd_dispatch_fc48(int a1)
{
  int v2; // r0
  int v3; // r0
  int v5; // r3

  v2 = sub_143F00(a1);
  if ( v2 <= 2 )
    return 4;
  v3 = v2 + a1;
  if ( *(_BYTE *)(v3 - 2) != 46 )
    return 4;
  v5 = *(unsigned __int8 *)(v3 - 1);
  if ( v5 == 98 )
    return 1;
  if ( v5 == 104 )
    return 2;
  return -1;
}

