// sub_136890 @ 0x136890, size 222 bytes
_DWORD *__fastcall sub_136890(int a1)
{
  _DWORD *v1; // r8
  int v3; // r6
  _BYTE *v4; // r4
  char v5; // r3
  int v7; // r7
  int v8; // r0
  int v9; // r9
  __int16 v10; // r2
  int v11; // r3
  int v12; // r12
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r7
  char v17; // r3

  v1 = off_136974;
  v3 = *(_DWORD *)off_136974;
  v4 = (_BYTE *)rf_bus_setup_n3a8(7169, 13, 7, 4u);
  if ( a1 )
  {
    v5 = *(_BYTE *)(v3 + 51);
  }
  else
  {
    v7 = *(unsigned __int8 *)(v3 + 51);
    v8 = rf_bus_setup_n3a8(30, 0, 7, 4u);
    v9 = dword_136970 + 1320 * v7;
    *(_BYTE *)(v8 + 2) = 1;
    *(_BYTE *)(v8 + 3) = *(_BYTE *)(v9 + 107);
    sub_12CBB4(v8);
    v10 = *(_WORD *)(v3 + 48);
    v11 = *(_DWORD *)(v9 + 72);
    *(_DWORD *)(v9 + 1208) = *(_DWORD *)(v3 + 44);
    *(_WORD *)(v9 + 236) = v10;
    *(_BYTE *)(v9 + 234) = 0;
    v4[2] = *(_BYTE *)(v11 + 24);
    v12 = dword_136978;
    v4[3] = *(_BYTE *)(v3 + 51) + 32;
    v13 = *(_DWORD *)(v3 + 4);
    v14 = *(_DWORD *)(v3 + 8);
    v15 = *(_DWORD *)(v3 + 12);
    v16 = v12 + 696 * (v7 + 32);
    *(_DWORD *)(v16 + 192) = *(_DWORD *)v3;
    *(_DWORD *)(v16 + 196) = v13;
    *(_DWORD *)(v16 + 200) = v14;
    *(_BYTE *)(v16 + 52) = 2;
    *(_BYTE *)(v16 + 204) = v15;
    bt_link_state_check(v16);
    v17 = *(_BYTE *)(v16 + 350);
    *(_WORD *)(v16 + 38) = 1;
    *(_BYTE *)(v16 + 350) = v17 | 0x10;
    v5 = *(_BYTE *)(v3 + 51);
    *(_BYTE *)(v16 + 37) = 1;
    *(_BYTE *)(v16 + 35) = v5 + 32;
  }
  v4[1] = v5;
  *v4 = a1;
  sub_12CBB4((int)v4);
  j_buffer_pool_get(v3 - 12);
  *v1 = 0;
  return rf_bus_mark_n_3b7(7u, 0);
}

