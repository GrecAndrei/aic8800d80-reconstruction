// sub_12064C @ 0x12064c, size 210 bytes
int __fastcall sub_12064C(int a1)
{
  _BYTE *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r0
  int v6; // r1
  int v7; // r6
  int v8; // r0
  int v9; // r3
  int v10; // r7
  char *(_DWORD *)(v12 + 0x14); // [sp+7h] [bp-5h] BYREF

  v2 = (_BYTE *)rf_bus_setup_n3a8(88, 13, 0, 3u);
  v3 = *(unsigned __int8 *)(a1 + 107);
  *(_DWORD *)(v12 + 0x0) = -1;
  sub_1287E0(v3);
  v4 = *(_DWORD *)(a1 + 1216);
  *(_DWORD *)(a1 + 412) = *(_DWORD *)(a1 + 1212);
  *(_DWORD *)(a1 + 416) = v4;
  *(_WORD *)(a1 + 420) = *(_WORD *)(a1 + 1220);
  *(_BYTE *)(a1 + 464) = 0;
  message_dispatch_c7ac(a1);
  v5 = sub_127F58((unsigned __int8 *)(a1 + 1212), v12);
  v6 = (unsigned __int8)*(_DWORD *)(v12 + 0x0);
  *(_DWORD *)(v2 + 0x4) = v5;
  *(_DWORD *)(v2 + 0x8) = v6;
  v7 = v5;
  v8 = *(unsigned __int8 *)(a1 + 107);
  *v2 = v8;
  v9 = *(unsigned __int8 *)(a1 + 106);
  if ( *(_BYTE *)(a1 + 106) )
  {
    if ( v9 == 2 )
    {
      *(_BYTE *)(a1 + 231) = 0;
      if ( !v7 )
      {
        sub_128AAC(v8, v6);
        *((_BYTE *)off_120728 + 9) = 1;
      }
    }
    return sub_12CBB4((int)v2);
  }
  *(_BYTE *)(a1 + 146) = v9;
  if ( !v7 )
  {
    v10 = *(unsigned __int8 *)(a1 + 116);
    sub_128AAC(v8, v6);
    timestamp_remove_058(a1 + 48);
    timestamp_update_4f60(a1 + 24, *((_DWORD *)off_120724 + 4) + *(_DWORD *)(dword_120720 + 696 * v10 + 8));
    *(_BYTE *)(a1 + 128) = 0;
    *(_BYTE *)(a1 + 147) = 1;
    return sub_12CBB4((int)v2);
  }
  mac_cmd_send_status_query(a1);
  return sub_12CBB4((int)v2);
}
