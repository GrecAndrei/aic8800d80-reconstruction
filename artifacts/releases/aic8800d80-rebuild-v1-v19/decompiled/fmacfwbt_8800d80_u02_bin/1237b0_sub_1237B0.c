// sub_1237B0 @ 0x1237b0, size 80 bytes
int __fastcall sub_1237B0(int a1, unsigned __int8 *a2)
{
  _BYTE *v3; // r0
  _BYTE *v4; // r4
  unsigned int v5; // r0

  v3 = (_BYTE *)rf_bus_setup_n3a8(84, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 || !*(_BYTE *)(dword_123800 + 1320 * v5 + 1224) )
    goto LABEL_5;
  *v4 = 0;
  if ( a2[1] )
  {
    sub_12A74C();
LABEL_5:
    sub_12CBB4(v4);
    return 0;
  }
  rf_table_lookup_n788();
  sub_12CBB4(v4);
  return 0;
}

