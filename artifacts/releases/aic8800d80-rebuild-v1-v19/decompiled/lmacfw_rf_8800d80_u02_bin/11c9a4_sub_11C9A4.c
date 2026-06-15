// sub_11C9A4 @ 0x11c9a4, size 124 bytes
int __fastcall sub_11C9A4(int a1, int a2, int a3, int a4)
{
  __int16 v4; // r6
  _BYTE *v6; // r4
  int v7; // r0
  _BYTE *v8; // r2

  v4 = a4;
  v6 = (_BYTE *)rf_setup_dispatch(2049, a4, a3, 1);
  v7 = sub_11E34C(2);
  sub_11F74C(4, dword_11CA24, dword_11CA20, v7);
  if ( sub_11E34C(2) )
  {
    *v6 = 8;
    sub_11DE50(v6);
    return 0;
  }
  else
  {
    if ( **(__int16 **)off_11CA28 < 0 && !*(_BYTE *)(a2 + 367) )
      rf_cmd_send_n264(dword_11CA34, dword_11CA30, 73);
    v8 = off_11CA2C;
    *v6 = 0;
    *(_DWORD *)v8 = a2;
    v8[10] = 0;
    *((_WORD *)v8 + 4) = v4;
    rf_pwr_tbl_init_n0c8(a2);
    sub_11DE50(v6);
    return 1;
  }
}

