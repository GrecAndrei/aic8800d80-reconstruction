// sub_123E28 @ 0x123e28, size 130 bytes
// Doc: sub_1223E28 [unknown]: Unknown helper at 0x1223E28
// sub_1223E28 [unknown]: Unknown helper at 0x1223E28
int __fastcall sub_123E28(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v7; // r2
  _WORD *v8; // r5
  int v9; // r3
  int result; // r0

  if ( msg_get_value(a3) == 3 || msg_get_value(a3) == 4 )
    return 2;
  v7 = *a2;
  v8 = off_123EAC;
  *((_BYTE *)off_123EAC + 31) = v7;
  if ( !v7 )
  {
    if ( msg_get_value(a3) != 2 )
    {
      rf_misc_init_n_xxx();
LABEL_6:
      message_dispatch_n84(35, a4, a3, v9);
      return 0;
    }
    return 2;
  }
  result = msg_get_value(a3);
  if ( !result )
  {
    if ( **(__int16 **)off_123EB0 < 0 )
    {
      if ( *(_DWORD *)off_123EB4 << 28 )
        sub_12F694(dword_123EBC, dword_123EB8, 1522);
    }
    v9 = 0;
    v8[9] = 0;
    goto LABEL_6;
  }
  if ( result != 2 )
  {
    sub_12BA2C(result);
    rf_bus_mark_n_3b7(a3);
    return 2;
  }
  return result;
}

