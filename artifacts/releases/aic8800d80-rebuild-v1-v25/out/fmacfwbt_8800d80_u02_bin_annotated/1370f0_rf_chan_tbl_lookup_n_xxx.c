// fwstruct annotate: 1370f0_rf_chan_tbl_lookup_n_xxx.c
// rf_chan_tbl_lookup_n_xxx @ 0x1370f0, size 202 bytes
// Doc: rf_chan_tbl_lookup_n_xxx [rf]: Channel table lookup: index into RF params table by sta index
// rf_chan_tbl_lookup_n_xxx [rf]: Channel table lookup: index into RF params table by sta index
int __fastcall rf_chan_tbl_lookup_n_xxx(int a1, int a2, int a3, __int16 a4)
{
  int v4; // r2
  _WORD *v5; // r4
  int v7; // r1
  int *v8; // r7
  int v9; // r1
  int inited; // r0
  __int16 v11; // r1
  int v12; // r3
  int v13; // r0
  int v14; // r1
  __int16 **v15; // r3
  __int16 *v16; // r3
  char v18; // r7
  int v19; // r2
  __int16 v20; // r6
  __int16 v21; // r1
  __int16 *v22; // r3
  int v23; // r0

  v4 = dword_1371BC;
  v5 = off_1371C0;
  v7 = *(unsigned __int8 *)(a2 + 366);
  *((_WORD *)off_1371C0 + 1924) = a4;
  v8 = (int *)(a2 + 352);
  *(_DWORD *)(v4 + 1320 * v7 + 472) = 0;
  v5[1925] = 1;
  v9 = *(_DWORD *)(a2 + 356);
  *((_DWORD *)v5 + 963) = *(_DWORD *)(a2 + 352);
  v5[1928] = v9;
  *(_DWORD *)v5 = a2;
  *((_BYTE *)v5 + 3899) = 0;
  inited = fmac_init_context(a2 + 352, 0);
  if ( inited && (v11 = *(unsigned __int8 *)(inited + 57), v12 = inited, *(_BYTE *)(inited + 57)) )
  {
    v18 = *(_BYTE *)(inited + 58);
    v19 = inited + 2;
    v13 = *(_DWORD *)(inited + 2);
    *((_DWORD *)v5 + 973) = v13;
    v5[1948] = *(_WORD *)(v19 + 4);
    v20 = ((1 << v18) - 1) << 8;
    LOWORD(v19) = v5[1948] & ~v20;
    v5[1948] = v19;
    v21 = *(_WORD *)(v12 + 6) - (v11 << 8);
    v22 = *(__int16 **)off_1371C4;
    v5[1948] = v20 & v21 | v19;
    if ( *v22 >= 0 )
      goto LABEL_4;
  }
  else
  {
    v13 = *v8;
    v14 = *(_DWORD *)(a2 + 356);
    v15 = (__int16 **)off_1371C4;
    *((_DWORD *)v5 + 973) = *v8;
    v16 = *v15;
    v5[1948] = v14;
    if ( *v16 >= 0 )
    {
LABEL_4:
      sub_13876C(v13);
      return 1;
    }
  }
  if ( (*(_BYTE *)(a2 + 352) & 1) == 0 )
    goto LABEL_4;
  v23 = sub_12F694(dword_1371CC, dword_1371C8, 178);
  sub_13876C(v23);
  return 1;
}

