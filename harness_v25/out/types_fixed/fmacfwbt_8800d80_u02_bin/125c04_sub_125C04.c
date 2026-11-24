// sub_125C04 @ 0x125c04, size 94 bytes
int __fastcall sub_125C04(int a1, int a2, int a3, int a4)
{
  int *v4; // r5
  int v5; // r6
  int v7; // r2
  int v8; // r3
  int v9; // r6
  int v10; // r2

  v4 = (int *)off_125C64;
  v5 = *(_DWORD *)off_125C64;
  message_dispatch_n84(64, *(unsigned __int16 *)(*(_DWORD *)off_125C64 - 4), 0, a4);
  sub_125734(a1, *v4);
  v7 = *v4;
  *(_BYTE *)(a1 + 231) = 0;
  v8 = *(unsigned __int8 *)(v7 + 10);
  *(_BYTE *)(a1 + 232) = v8;
  *(_BYTE *)(a1 + 233) = *(_BYTE *)(v7 + 11);
  v9 = v5 - 12;
  if ( v8 )
    *(_BYTE *)(a1 + 231) = *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(a1 + 192) + 28) + v8) + 1;
  v10 = *((unsigned __int8 *)v4 + 8);
  *((_BYTE *)v4 + 9) = 0;
  if ( v10 )
    rf_msg_process_body_n446();
  *v4 = 0;
  return j_buffer_pool_get(v9);
}

