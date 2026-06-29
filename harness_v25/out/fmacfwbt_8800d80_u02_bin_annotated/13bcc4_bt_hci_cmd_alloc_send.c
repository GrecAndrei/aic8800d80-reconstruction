// fwstruct annotate: 13bcc4_bt_hci_cmd_alloc_send.c
// bt_hci_cmd_alloc_send @ 0x13bcc4, size 168 bytes
// Doc: bt_hci_cmd_alloc_send [bt]: Allocates and sends HCI command with opcode from r0
// bt_hci_cmd_alloc_send [bt]: Allocates and sends HCI command with opcode from r0
_DWORD *__fastcall bt_hci_cmd_alloc_send(unsigned int a1)
{
  int v1; // r5
  int v3; // r1
  unsigned __int8 *v4; // r3
  int v5; // r2
  int v6; // r0
  int v7; // r3
  _DWORD *v8; // r1
  _DWORD *v10; // [sp+4h] [bp-8h]

  v1 = (a1 << 8) | 8;
  sub_12C964(0x2000, v1);
  sub_12C964(8194, v1);
  v3 = dword_13BD6C;
  v4 = (unsigned __int8 *)(dword_13BD6C + 32 * a1);
  v5 = v4[17];
  v6 = v4[16];
  v7 = v4[22];
  if ( v5 )
  {
    if ( v5 == 1 )
      *(_BYTE *)(696 * v6 + 12 * v7 + dword_13BD70 + 453) = 33;
    v8 = (_DWORD *)(v3 + 32 * a1);
    v10 = v8;
    if ( a1 <= 0xF )
      goto LABEL_5;
LABEL_7:
    list_remove_node_d510(dword_13BD7C, v8);
    list_push_tail(dword_13BD80, v10);
    return rf_bus_mark_n_3b7(v1, 0);
  }
  v8 = (_DWORD *)(dword_13BD6C + 32 * a1);
  *(_BYTE *)(696 * v6 + 12 * v7 + dword_13BD70 + 452) = 33;
  v10 = v8;
  if ( a1 > 0xF )
    goto LABEL_7;
LABEL_5:
  list_remove_node_d510(dword_13BD74, v8);
  list_push_tail(dword_13BD78, v10);
  return rf_bus_mark_n_3b7(v1, 0);
}

