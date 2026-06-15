// v23 annotated: sub_1180B8 @ 0x1180b8
// Original: 1180b8_sub_1180B8.c
// Primary struct: <unclustered>
//
// sub_1180B8 @ 0x1180b8, size 470 bytes
int __fastcall sub_1180B8(int a1)
{
  int v2; // r8
  int v3; // r9
  int v4; // r0
  int v5; // r3
  int v6; // r5
  unsigned __int8 *v7; // r6
  int v8; // r2
  int v9; // r3
  int v10; // r4
  int v11; // r5
  int v12; // r3
  int v13; // r1
  int v14; // r2
  __int16 **v16; // r11
  _DWORD *v17; // r10
  int v18; // r1
  unsigned int v19; // r3
  int v20; // r2
  unsigned int v21; // r3
  int v22; // r3
  int v23; // r2

  v2 = dword_1182BC;
  v3 = dword_1182BC + 224 * a1;
  v4 = list_remove_node(dword_118290, v3);
  v5 = *(unsigned __int8 *)(v3 + 94);
  v6 = 224 * a1;
  if ( v5 == 2 )
  {
    v7 = (unsigned __int8 *)off_118294;
    v8 = (unsigned __int8)(*((_BYTE *)off_118294 + 18) - 1);
    *((_BYTE *)off_118294 + 18) = v8;
    if ( v8 )
    {
      if ( v7[17] + v8 != 1 )
        goto LABEL_7;
      goto LABEL_12;
    }
    rf_gpio_clear_bit_n_e20(v4);
LABEL_4:
    v8 = v7[18];
    v9 = v7[17] + v8;
    if ( v9 != 1 )
      goto LABEL_5;
    goto LABEL_12;
  }
  if ( v5 == 4 )
  {
    if ( rf_chip_ready_check() )
      sub_101A50(0);
    v7 = (unsigned __int8 *)off_118294;
    v8 = *((unsigned __int8 *)off_118294 + 18);
    v9 = *((unsigned __int8 *)off_118294 + 17) + v8;
    *((_BYTE *)off_118294 + 16) = -1;
    if ( v9 != 1 )
      goto LABEL_5;
    goto LABEL_12;
  }
  v7 = (unsigned __int8 *)off_118294;
  if ( *(_BYTE *)(v3 + 94) )
    goto LABEL_4;
  v8 = *((unsigned __int8 *)off_118294 + 18);
  v22 = (unsigned __int8)(*((_BYTE *)off_118294 + 17) - 1);
  *((_BYTE *)off_118294 + 17) = v22;
  v9 = v22 + v8;
  if ( v9 != 1 )
    goto LABEL_5;
LABEL_12:
  v16 = (__int16 **)off_1182C0;
  v17 = off_1182C4;
  v18 = **(__int16 **)off_1182C0;
  v19 = *((_DWORD *)off_1182C4 + 1) & 0xFFFFFFEF;
  *((_DWORD *)off_1182C4 + 1) = v19;
  if ( v18 < 0 && *(_DWORD *)off_1182B0 << 28 )
  {
    sub_1219F4(dword_1182B8, dword_1182B4, 472);
    v23 = v7[18];
    v9 = v7[17] + v23;
    *(_DWORD *)off_1182AC = *v17 | v17[1];
    if ( v9 != 1 )
      goto LABEL_5;
    if ( v23 )
      goto LABEL_7;
  }
  else
  {
    *(_DWORD *)off_1182AC = v19 | *v17;
    if ( v8 )
      goto LABEL_7;
  }
  v20 = **v16;
  v21 = v17[1] & 0xFFFFFEFF;
  v17[1] = v21;
  if ( v20 >= 0 )
  {
    *(_DWORD *)off_1182AC = v21 | *v17;
    goto LABEL_7;
  }
  if ( !(*(_DWORD *)off_1182B0 << 28) )
  {
    *(_DWORD *)off_1182AC = v21 | *v17;
    goto LABEL_7;
  }
  sub_1219F4(dword_1182B8, dword_1182B4, 472);
  v9 = v7[17] + v7[18];
  *(_DWORD *)off_1182AC = *v17 | v17[1];
LABEL_5:
  if ( !v9 )
    *(_DWORD *)off_118298 = 0;
LABEL_7:
  timestamp_remove(v6 + 24 + v2);
  timestamp_remove(v6 + 48 + v2);
  sub_11C7DC(*(unsigned __int8 *)(v2 + 224 * a1 + 95));
  *(_DWORD *)off_11829C = 0;
  if ( v7[18] + v7[17] <= 1 )
    rf_status_check_n_1c0();
  sub_100200((int *)v3, 0, 0xE0u);
  v10 = v2 + 224 * a1;
  v11 = dword_1182A0;
  v12 = v7[18] + v7[17];
  v13 = dword_1182A4;
  v14 = dword_1182A8;
  *(_DWORD *)(v10 + 56) = v3;
  *(_BYTE *)(v10 + 94) = 5;
  *(_BYTE *)(v10 + 97) = 127;
  *(_DWORD *)(v10 + 52) = v11;
  sub_11F74C(256, v13, v14, v12);
  return list_push_tail(off_118294);
}

