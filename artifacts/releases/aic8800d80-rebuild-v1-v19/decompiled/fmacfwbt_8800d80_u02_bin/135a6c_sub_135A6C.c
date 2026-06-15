// sub_135A6C @ 0x135a6c, size 200 bytes
// Doc: sub_1235A6C [bt]: Bluetooth task entry: dispatch handler using table lookup
// sub_1235A6C [bt]: Bluetooth task entry: dispatch handler using table lookup
int __fastcall sub_135A6C(unsigned int a1)
{
  int v1; // r8
  int v2; // r7
  int v3; // r5
  _BYTE *v5; // r0
  _DWORD *v6; // r3
  int v7; // r1
  int *v8; // r2
  int v9; // r4
  int *v10; // r1
  int v11; // lr
  int v12; // r12
  int v13; // r0
  int v14; // r5
  int v15; // r0

  v1 = *((_DWORD *)off_135B38 + 4);
  v2 = dword_135B3C;
  v3 = *(unsigned __int8 *)(v1 + 61);
  if ( **(__int16 **)off_135B34 < 0 && *(int *)(dword_135B3C + 1320 * v3 + 472) >= 0 )
    sub_12F694(dword_135B48, dword_135B44, 1398);
  v5 = (_BYTE *)rf_bus_setup_n3a8(6150, 13, 6, 0x2Cu);
  *v5 = *(_BYTE *)(v1 + 61);
  v6 = v5 + 1;
  v7 = v2 + 1320 * v3;
  v8 = (int *)(v7 + 374);
  v9 = (int)v5;
  v10 = (int *)(v7 + 406);
  do
  {
    v11 = *v8;
    v12 = v8[1];
    v13 = v8[2];
    v6[3] = v8[3];
    v8 += 4;
    *v6 = v11;
    v6[1] = v12;
    v6[2] = v13;
    v6 += 4;
  }
  while ( v8 != v10 );
  *(_BYTE *)v6 = *(_BYTE *)v8;
  v14 = v2 + 1320 * v3;
  v15 = *(_DWORD *)(v14 + 368);
  *(_WORD *)(v9 + 38) = *(_WORD *)(v14 + 372);
  *(_DWORD *)(v9 + 34) = v15;
  *(_DWORD *)(v9 + 40) = bswap32(a1);
  rf_bus_mark_n_3b7(6u, 6);
  rf_level_apply_80c(6154, 6, dword_135B40);
  return sub_12CBB4(v9);
}

