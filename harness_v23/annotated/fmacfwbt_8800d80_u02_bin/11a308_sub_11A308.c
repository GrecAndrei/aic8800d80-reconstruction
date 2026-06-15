// v23 annotated: sub_11A308 @ 0x11a308
// Original: 11a308_sub_11A308.c
// Primary struct: <unclustered>
//
// sub_11A308 @ 0x11a308, size 440 bytes
// Doc: sub_121A308 [unknown]: Unknown behavioral stub at 0x121a308
// sub_121A308 [unknown]: Unknown behavioral stub at 0x121a308
int __fastcall sub_11A308(int a1)
{
  int v1; // r8
  int v2; // r3
  int v3; // r5
  int v4; // r6
  __int64 v5; // kr00_8
  int v7; // r10
  __int16 v8; // r3
  _BYTE *v9; // r2
  int v11; // r4
  char v12; // r3
  int v13; // r0
  void *v14; // r11
  __int16 v15; // r2
  int v16; // r7
  unsigned int v17; // r0
  _BYTE *v18; // r3
  int v19; // r7
  int v20; // [sp+Ch] [bp-8h]

  v1 = dword_11A4C8;
  v2 = dword_11A4C8 + 84 * a1;
  v3 = *(_DWORD *)(v2 + 52);
  v4 = *(_DWORD *)(v2 + 44);
  v5 = *(_QWORD *)(v3 + 72);
  v7 = HIDWORD(v5) + 12;
  if ( *(_BYTE *)(v2 + 77) == 1 )
  {
    *(_DWORD *)(v3 + 36) = 0;
    *(_DWORD *)(HIDWORD(v5) + 20) = 0;
    *(_DWORD *)(HIDWORD(v5) + 68) = 256;
    *(_DWORD *)(v3 + 68) = 0;
    if ( (_DWORD)v5 )
      sub_116764(v3, a1);
    v8 = *(_WORD *)(v4 + 8);
    if ( (v8 & 2) != 0 )
    {
      v9 = off_11A4C0;
      *(_WORD *)(v3 + 82) |= 2u;
      if ( v9[197] )
      {
        v19 = *(_DWORD *)(HIDWORD(v5) + 48);
        if ( v19 )
          *(_BYTE *)(v19 + 36) = scan_chan_parse_n1bd4(
                                   (*(_DWORD *)(v19 + 20) >> 11) & 7,
                                   *(_DWORD *)(v19 + 20) & 0x7F,
                                   (unsigned __int8 *)(*(_DWORD *)(dword_11A4C4
                                                                 + 1320 * *(unsigned __int8 *)(v3 + 28)
                                                                 + 72)
                                                     + 4));
      }
      sub_116DE0(v7, v7, a1);
    }
    else if ( (v8 & 4) != 0 )
    {
      *(_WORD *)(v3 + 82) |= 2u;
    }
    else if ( (_DWORD)v5 )
    {
      *(_WORD *)(v3 + 82) |= 2u;
      bt_table_lookup_n_64e(a1, v5);
    }
    list_push_tail(*(_DWORD *)(v4 + 340));
  }
  else
  {
    v13 = *(_DWORD *)(v2 + 48);
    v20 = v2;
    *(_DWORD *)(v3 + 36) |= 0x380000u;
    *(_DWORD *)(v4 + 324) = v3;
    sub_11C990(v13);
    v14 = off_11A4CC;
    *(_BYTE *)(HIDWORD(v5) + 1) = *(_BYTE *)(v20 + 77);
    if ( *(_BYTE *)(*(_DWORD *)v14 + 1) )
    {
      sub_1197FC(
        v4,
        *(_WORD *)(v3 + 34),
        *(unsigned __int8 *)(v4 + 12),
        *(unsigned __int8 *)(v4 + 13),
        *(_BYTE *)(v20 + 78));
      *(_DWORD *)(HIDWORD(v5) + 20) = v4 + 84;
    }
    else
    {
      *(_DWORD *)(v4 + 20) = *(unsigned __int8 *)(*(_DWORD *)v14 + 1);
    }
    v15 = *(_WORD *)(v4 + 8);
    *(_DWORD *)(HIDWORD(v5) + 68) = *(_DWORD *)(v3 + 36) | 0x100;
    *(_WORD *)(v4 + 8) = v15 | 1;
    if ( (v15 & 2) != 0 )
    {
      if ( *(_BYTE *)(*(_DWORD *)v14 + 1) )
        v7 = v4 + 84;
      v16 = *(_DWORD *)(v4 + 52);
      v17 = *(_DWORD *)(v4 + 4);
      v18 = off_11A4C0;
      *(_DWORD *)(v16 + 20) = v17;
      if ( v18[197] && v16 )
        *(_BYTE *)(v16 + 36) = scan_chan_parse_n1bd4(
                                 (v17 >> 11) & 7,
                                 v17 & 0x7F,
                                 (unsigned __int8 *)(*(_DWORD *)(dword_11A4C4 + 1320 * *(unsigned __int8 *)(v3 + 28) + 72)
                                                   + 4));
      sub_116DE0(v4 + 16, v7, a1);
    }
    else if ( (_DWORD)v5 && (v15 & 4) == 0 )
    {
      *(_WORD *)(v4 + 8) = v15 | 5;
      bt_table_lookup_n_64e(a1, v5);
    }
    list_push_tail(v1 + 84 * a1 + 28);
  }
  v11 = v1 + 84 * a1;
  v12 = *(_BYTE *)(v11 + 80);
  *(_DWORD *)(v11 + 44) = 0;
  *(_BYTE *)(v11 + 80) = v12 + 1;
  return 84;
}

