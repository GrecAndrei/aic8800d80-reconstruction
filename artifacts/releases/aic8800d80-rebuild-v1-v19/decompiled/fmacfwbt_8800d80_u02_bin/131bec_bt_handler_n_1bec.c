// bt_handler_n_1bec @ 0x131bec, size 138 bytes
// Doc: bt_handler_n_1bec [bt]: Bluetooth firmware handler (reconstructed)
// bt_handler_n_1bec [bt]: Bluetooth firmware handler (reconstructed)
int __fastcall bt_handler_n_1bec(int a1, _BYTE *a2, unsigned int a3, __int16 a4)
{
  _DWORD *v5; // r5
  int v6; // r7
  int v8; // r0
  int v9; // r0
  int v10; // r3
  _BYTE *v12; // r0
  int v13; // r3
  char v14; // r3
  unsigned int v15; // [sp+4h] [bp-8h]

  v5 = off_131C78;
  v6 = *((_DWORD *)off_131C78 + 1);
  v8 = 1 << a2[1];
  if ( *a2 )
    v9 = v8 | v6;
  else
    v9 = v6 & ~v8;
  v10 = *((unsigned __int8 *)off_131C78 + 375);
  *((_DWORD *)off_131C78 + 1) = v9;
  if ( !v10 )
    goto LABEL_7;
  v15 = a3;
  if ( msg_get_value(5u) == 1 )
    return 2;
  LOWORD(a3) = v15;
  if ( (_BYTE)v6 )
  {
    if ( *a2 )
    {
LABEL_7:
      message_dispatch_n84(5146, a4, a3);
      return 0;
    }
  }
  else if ( !*a2 )
  {
    goto LABEL_7;
  }
  v12 = (_BYTE *)rf_bus_setup_n3a8(49, 0, v15, 1u);
  v13 = v5[1];
  *((_WORD *)v5 + 4) = a4;
  if ( v13 )
    v14 = 0;
  else
    v14 = *((_BYTE *)v5 + 376);
  *v12 = v14;
  sub_12CBB4((int)v12);
  rf_bus_mark_n_3b7(v15, 1);
  return 0;
}

