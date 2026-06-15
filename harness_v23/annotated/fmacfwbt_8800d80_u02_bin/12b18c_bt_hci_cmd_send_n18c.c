// v23 annotated: bt_hci_cmd_send_n18c @ 0x12b18c
// Original: 12b18c_bt_hci_cmd_send_n18c.c
// Primary struct: <unclustered>
//
// bt_hci_cmd_send_n18c @ 0x12b18c, size 138 bytes
// Doc: bt_hci_cmd_send_n18c [bt]: Sends HCI command (opcode 2) via bluetooth mailbox interface
// bt_hci_cmd_send_n18c [bt]: Sends HCI command (opcode 2) via bluetooth mailbox interface
int bt_hci_cmd_send_n18c()
{
  int value; // r0
  int v1; // r2
  _BYTE *v2; // r4
  int v3; // r0
  unsigned int v4; // r2
  unsigned int v5; // r3
  int v6; // r1

  if ( msg_get_value(2) != 3 )
  {
    value = msg_get_value(2);
    sub_12ECB0(dword_12B218, value, v1);
  }
  if ( **(__int16 **)off_12B21C < 0 && msg_get_value(2) != 3 )
    sub_12F694(dword_12B228, dword_12B224, 201);
  v2 = off_12B220;
  v3 = *(_DWORD *)off_12B220;
  v4 = *(unsigned __int8 *)(*(_DWORD *)off_12B220 + 367);
  v5 = (unsigned __int8)(*((_BYTE *)off_12B220 + 10) + 1);
  *((_BYTE *)off_12B220 + 10) = v5;
  if ( v4 <= v5 || v2[11] )
  {
    j_buffer_pool_get(v3 - 12);
    v6 = *((unsigned __int16 *)v2 + 4);
    if ( v2[11] )
    {
      sub_12B708(0, v6);
      v2[11] = 0;
    }
    else
    {
      message_dispatch_n84(2050, v6, 2, (unsigned __int8)v2[11]);
    }
    rf_bus_mark_n_3b7(2);
    return 0;
  }
  else
  {
    sub_12B3C8();
    return 0;
  }
}

