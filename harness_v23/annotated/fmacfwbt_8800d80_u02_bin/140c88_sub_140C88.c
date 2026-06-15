// v23 annotated: sub_140C88 @ 0x140c88
// Original: 140c88_sub_140C88.c
// Primary struct: <unclustered>
//
// sub_140C88 @ 0x140c88, size 408 bytes
int __fastcall sub_140C88(int a1, int a2)
{
  int v3; // r5
  int v4; // r7
  int *v5; // r0
  __int64 v6; // r0
  int v7; // r8
  int v8; // r7
  int v9; // r5
  int v10; // r9
  _DWORD *v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r3
  int v15; // r2
  char *v16; // r0
  char *v17; // r5
  int v18; // r6
  int v19; // r2

  if ( a2 )
  {
    v3 = dword_140E24;
    bt_xtal_init_check((_DWORD *)dword_140E20);
    v4 = v3 + 6336;
    do
    {
      *(_WORD *)(v3 - 2) = 0;
      v5 = (int *)v3;
      v3 += 528;
      memset_thunk(v5, 0, 6u);
    }
    while ( v4 != v3 );
    LODWORD(v6) = sub_12C068();
    *(_QWORD *)(a1 + 40) = v6;
    *(_DWORD *)(a1 + 96) = 0;
  }
  v7 = dword_140E28;
  v8 = dword_140E20;
LABEL_6:
  while ( msg_get_value(0xBu) == 1 )
  {
    v9 = dword_140E28;
    v10 = dword_140E28 + 6336;
    do
    {
      while ( *(_WORD *)(v9 + 4) != 1 || !sub_140C14((unsigned __int16 *)(v9 + 6), v9 + 28, a1) )
      {
        v9 += 528;
        if ( v9 == v10 )
          goto LABEL_12;
      }
      v11 = (_DWORD *)v9;
      *(_WORD *)(v9 + 24) = 0;
      *(_BYTE *)(v9 + 22) = 0;
      *(_WORD *)(v9 + 4) = 2;
      v9 += 528;
      list_push_tail(v8, v11);
    }
    while ( v9 != v10 );
LABEL_12:
    v12 = *(unsigned __int8 *)(a1 + 101);
    v13 = *(_DWORD *)(a1 + 96) + 1;
    *(_DWORD *)(a1 + 96) = v13;
    if ( v13 >= v12 )
    {
      if ( **(__int16 **)off_140E2C < 0 && sub_1405AC() )
      {
        if ( *(_DWORD *)(a1 + 92) )
          sub_12F694(dword_140E34, dword_140E30, 1585);
      }
      rf_bus_mark_n_3b7(0xBu, 2);
      return bt_chan_state_check_n_4b80(a1, 0);
    }
    rf_bus_mark_n_3b7(0xBu, 3);
    if ( !sub_1405AC() )
      return bt_chan_state_check_n_4b80(a1, 0);
  }
  rf_bus_mark_n_3b7(0xBu, 1);
  v14 = *(_DWORD *)(a1 + 96);
  while ( 1 )
  {
    v16 = sub_132460((char *)*(unsigned __int8 *)(a1 + 100), *(unsigned __int8 *)(v14 + a1 + 102));
    v17 = v16;
    if ( v16 )
    {
      if ( (v16[3] & 2) == 0 )
        break;
    }
    v15 = *(unsigned __int8 *)(a1 + 101);
    v14 = *(_DWORD *)(a1 + 96) + 1;
    *(_DWORD *)(a1 + 96) = v14;
    if ( v14 >= v15 )
      goto LABEL_6;
  }
  v18 = rf_bus_setup_n3a8(4096, 4, 11, 0x178u);
  *(_DWORD *)v18 = *(_DWORD *)v17;
  *(_WORD *)(v18 + 4) = *((_WORD *)v17 + 2);
  if ( !*(_BYTE *)(a1 + 3) )
    *(_BYTE *)(v18 + 3) |= 1u;
  *(_BYTE *)(v18 + 367) = 1;
  v19 = *(unsigned __int8 *)(a1 + 58);
  *(_BYTE *)(v18 + 252) = v19;
  sub_14380C(v18 + 253, a1 + 59, v19);
  *(_BYTE *)(v18 + 368) = 1;
  *(_WORD *)(v18 + 352) = *(_WORD *)(a1 + 52);
  *(_WORD *)(v18 + 354) = *(_WORD *)(a1 + 54);
  *(_WORD *)(v18 + 356) = *(_WORD *)(a1 + 56);
  *(_BYTE *)(v18 + 366) = *(_BYTE *)(v7 + 6489);
  *(_DWORD *)(v18 + 372) = *(unsigned __int16 *)(a1 + 48) << 10;
  return sub_12CBB4(v18);
}

