// sub_117E5C @ 0x117e5c, size 520 bytes
int __fastcall sub_117E5C(int a1, int a2, int a3, _BYTE *a4)
{
  unsigned __int8 *v4; // r5
  int v8; // r7
  int v9; // r0
  int v10; // r4
  char v11; // r1
  int v12; // r3
  unsigned __int8 v13; // r1
  int v14; // r2
  int v15; // r3
  _DWORD *v16; // r7
  int v17; // r1
  int v18; // r2
  int v19; // r3
  _DWORD *v20; // r3
  bool v21; // zf
  int result; // r0
  unsigned __int8 v23; // r2
  unsigned __int8 v24; // r3
  int v25; // r3
  int v26; // r3

  v4 = (unsigned __int8 *)off_118064;
  if ( !*(_DWORD *)off_118064 )
    return 1;
  if ( !*((_DWORD *)off_118064 + 2) )
    rf_state_check_nec();
  v8 = dword_11806C;
  v9 = sub_11E7AC(off_118064);
  *(_BYTE *)(v9 + 94) = a2;
  v10 = v9;
  *(_DWORD *)(v9 + 88) = *(_DWORD *)a1;
  v11 = dword_118070;
  *(_WORD *)(v9 + 92) = *(_WORD *)(a1 + 4);
  *(_DWORD *)(v9 + 8) = 2631;
  *(_DWORD *)(v9 + 12) = 2627;
  v12 = dword_118078;
  *(_DWORD *)(v9 + 16) = dword_118074;
  v13 = v11 * ((v9 - v8) >> 5);
  *(_DWORD *)(v9 + 20) = v12;
  *(_BYTE *)(v9 + 97) = 127;
  *(_DWORD *)(v9 + 72) = 0;
  *(_BYTE *)(v9 + 95) = v13;
  *(_BYTE *)(v9 + 84) = v13;
  if ( a2 == 2 )
  {
    v23 = v4[18];
    if ( !v23 )
    {
      sub_118DEC();
      v23 = v4[18];
    }
    v14 = (unsigned __int8)(v23 + 1);
    v15 = v4[17] + v14;
    v4[18] = v14;
    if ( v15 > 1 )
      goto LABEL_8;
    goto LABEL_19;
  }
  if ( a2 != 4 )
  {
    if ( a2 )
    {
      v14 = v4[18];
      v15 = v4[17] + v14;
      if ( v15 > 1 )
        goto LABEL_8;
    }
    else
    {
      v24 = v4[17];
      *(_DWORD *)(v9 + 28) = dword_1180B0;
      *(_WORD *)(v9 + 100) = 100;
      *(_DWORD *)(v9 + 128) = dword_1180B4;
      v14 = v4[18];
      *(_DWORD *)(v9 + 32) = v9;
      v25 = (unsigned __int8)(v24 + 1);
      v4[17] = v25;
      v15 = v25 + v14;
      *(_DWORD *)(v9 + 132) = v9;
      *(_BYTE *)(v9 + 102) = -1;
      if ( v15 > 1 )
        goto LABEL_8;
    }
    goto LABEL_19;
  }
  if ( v4[16] != 255 )
    return 1;
  v14 = v4[18];
  v26 = v4[17];
  v4[16] = v13;
  v15 = v26 + v14;
  if ( v15 > 1 )
    goto LABEL_8;
LABEL_19:
  if ( v14 )
  {
LABEL_8:
    v16 = off_118080;
    v17 = **(__int16 **)off_11807C;
    v18 = *((_DWORD *)off_118080 + 1) | 0x100;
    *((_DWORD *)off_118080 + 1) = v18;
    if ( v17 < 0 && *(_DWORD *)off_1180A0 << 28 )
    {
      sub_1219F4(dword_1180A8, dword_1180A4, 472);
      v18 = v16[1];
      v15 = v4[17] + v4[18];
    }
    *(_DWORD *)off_118084 = v18 | *v16;
  }
  if ( v15 == 1 )
    *(_DWORD *)off_11809C |= 1u;
  *a4 = *(_BYTE *)(v10 + 95);
  list_push_tail(dword_118088);
  sub_11E71C(v10 + 148);
  sub_11E71C(v10 + 180);
  sub_11E71C(v10 + 156);
  sub_11E71C(v10 + 188);
  sub_11E71C(v10 + 164);
  sub_11E71C(v10 + 196);
  sub_11E71C(v10 + 172);
  sub_11E71C(v10 + 204);
  sub_11E71C(v10 + 212);
  v19 = v4[17] + v4[18];
  *(_DWORD *)off_11808C = 0;
  if ( v19 <= 1 )
  {
    rf_status_check_n_1c0();
    v19 = v4[17] + v4[18];
  }
  sub_11F74C(256, dword_118090, dword_118094, v19);
  v20 = (_DWORD *)(v4[18] + v4[17]);
  v21 = v20 == (_DWORD *)1;
  if ( v20 == (_DWORD *)1 )
    v20 = off_118098;
  result = 0;
  if ( v21 )
    *v20 = 0;
  return result;
}

