// ipc_msg_alloc @ 0x12064c, size 210 bytes
// Doc: ipc_msg_alloc [ipc]: Allocate IPC message buffer (id 0xd, size 0x58)
// ipc_msg_alloc [ipc]: Allocate IPC message buffer (id 0xd, size 0x58)
int __fastcall ipc_msg_alloc(int a1)
{
  _BYTE *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r0
  char v6; // r1
  int v7; // r3
  int v8; // r7
  char v10[5]; // [sp+7h] [bp-5h] BYREF

  v2 = (_BYTE *)rf_bus_setup_n3a8(88, 13, 0, 3);
  v3 = *(unsigned __int8 *)(a1 + 107);
  v10[0] = -1;
  sub_1287E0(v3);
  v4 = *(_DWORD *)(a1 + 1216);
  *(_DWORD *)(a1 + 412) = *(_DWORD *)(a1 + 1212);
  *(_DWORD *)(a1 + 416) = v4;
  *(_WORD *)(a1 + 420) = *(_WORD *)(a1 + 1220);
  *(_BYTE *)(a1 + 464) = 0;
  message_dispatch_c7ac(a1);
  v5 = sub_127F58(a1 + 1212, v10);
  v6 = v10[0];
  v2[1] = v5;
  v2[2] = v6;
  *v2 = *(_BYTE *)(a1 + 107);
  v7 = *(unsigned __int8 *)(a1 + 106);
  if ( *(_BYTE *)(a1 + 106) )
  {
    if ( v7 == 2 )
    {
      *(_BYTE *)(a1 + 231) = 0;
      if ( !v5 )
      {
        sub_128AAC();
        *((_BYTE *)off_120728 + 9) = 1;
      }
    }
    return sub_12CBB4(v2);
  }
  *(_BYTE *)(a1 + 146) = v7;
  if ( !v5 )
  {
    v8 = *(unsigned __int8 *)(a1 + 116);
    sub_128AAC();
    timestamp_remove_058(a1 + 48);
    timestamp_update_4f60(a1 + 24, *((_DWORD *)off_120724 + 4) + *(_DWORD *)(dword_120720 + 696 * v8 + 8));
    *(_BYTE *)(a1 + 128) = 0;
    *(_BYTE *)(a1 + 147) = 1;
    return sub_12CBB4(v2);
  }
  mac_cmd_send_status_query(a1);
  return sub_12CBB4(v2);
}

