// sub_11BB18 @ 0x11bb18, size 118 bytes
int __fastcall sub_11BB18(__int16 *a1, int a2, char a3)
{
  _BYTE *v3; // r4
  __int16 v7; // r3
  _BYTE *v8; // r2

  v3 = off_11BB94;
  if ( **(__int16 **)off_11BB90 < 0 && *((unsigned __int8 *)off_11BB94 + 108) != 255 )
    rf_cmd_send_n264(dword_11BBA0, dword_11BB9C, 2838);
  v3[108] = 3;
  *((_WORD *)v3 + 49) = 255;
  v3[88] = *((_BYTE *)a1 + 2);
  v7 = *a1;
  *((_WORD *)v3 + 46) = *a1;
  *((_WORD *)v3 + 45) = v7;
  v8 = off_11BB98;
  v3[96] = *((_BYTE *)a1 + 4);
  LOBYTE(v7) = v8[88];
  v3[97] = *((_BYTE *)a1 + 3);
  v8[88] = v7 | 2;
  v3[110] = a3;
  *((_DWORD *)v3 + 26) = a2;
  v3[100] = 1;
  return phy_flag_check_or_set();
}

