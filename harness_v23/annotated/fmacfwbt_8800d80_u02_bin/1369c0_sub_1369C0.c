// v23 annotated: sub_1369C0 @ 0x1369c0
// Original: 1369c0_sub_1369C0.c
// Primary struct: <unclustered>
//
// sub_1369C0 @ 0x1369c0, size 280 bytes
_DWORD *sub_1369C0()
{
  int v0; // r11
  int v1; // r4
  int v2; // r9
  int v3; // r6
  int v4; // r5
  int v5; // r8
  int v6; // r10
  _BYTE *v7; // r7
  int v8; // r9
  int v9; // r0
  int v10; // r0
  _BYTE *v12; // r0

  v0 = dword_136AE4;
  v1 = *(_DWORD *)off_136AD8;
  v2 = *(unsigned __int8 *)(*(_DWORD *)off_136AD8 + 51);
  v3 = rf_bus_setup_n3a8(24, 0, 7, 8u);
  v4 = rf_bus_setup_n3a8(22, 0, 7, 8u);
  v5 = rf_bus_setup_n3a8(20, 0, 7, 4u);
  v6 = v0 + 1320 * v2;
  v7 = (_BYTE *)rf_bus_setup_n3a8(5143, 5, 7, 2u);
  sub_136828();
  if ( *(_BYTE *)(v6 + 1224) )
  {
    *(_DWORD *)off_136ADC &= ~4u;
    *(_DWORD *)(v6 + 4) |= 0x20u;
  }
  else
  {
    v12 = (_BYTE *)rf_bus_setup_n3a8(5145, 5, 7, 2u);
    *v12 = 1;
    v12[1] = *(_BYTE *)(v6 + 107);
    list_push_tail((int)off_136AD8 + 4, (_DWORD *)v12 - 3);
  }
  v8 = v0 + 1320 * v2;
  v9 = *(_DWORD *)(v8 + 100);
  *(_WORD *)(v3 + 4) = *(_WORD *)(v8 + 104);
  *(_DWORD *)v3 = v9;
  *(_BYTE *)(v3 + 6) = *(_BYTE *)(v1 + 51);
  list_push_tail(dword_136AE0, (_DWORD *)(v3 - 12));
  *(_BYTE *)(v4 + 5) = *(_BYTE *)(v1 + 16);
  *(_DWORD *)v4 = sub_1329B0((unsigned __int8 *)v1, 1);
  *(_BYTE *)(v4 + 4) = *(_BYTE *)(v1 + 51);
  list_push_tail(dword_136AE0, (_DWORD *)(v4 - 12));
  *(_WORD *)v5 = *(_WORD *)(v1 + 40);
  *(_BYTE *)(v5 + 2) = *(_BYTE *)(v1 + 51);
  list_push_tail(dword_136AE0, (_DWORD *)(v5 - 12));
  *v7 = 1;
  v10 = dword_136AE0;
  v7[1] = *(_BYTE *)(v1 + 51);
  list_push_tail(v10, (_DWORD *)v7 - 3);
  sub_13697C();
  return rf_bus_mark_n_3b7(7u, 1);
}

