// v23 annotated: sub_139340 @ 0x139340
// Original: 139340_sub_139340.c
// Primary struct: <unclustered>
//
// sub_139340 @ 0x139340, size 546 bytes
int __fastcall sub_139340(int a1, int a2)
{
  _WORD *v2; // r6
  int v3; // r7
  int v5; // r4
  int v7; // r12
  int v8; // r9
  int v9; // r1
  int v10; // r7
  int v11; // r3
  __int16 v12; // r3
  unsigned int v13; // r1
  int v14; // r2
  int v16; // r4
  int v17; // r0
  _DWORD *v18; // r2
  int v19; // r3
  int v20; // r2
  __int16 v21; // r2
  __int16 v22; // r3
  int v23; // r9
  __int16 *v24; // r2
  unsigned int v25; // r3
  __int16 v26; // r3
  __int16 v27; // r3

  v2 = off_139564;
  v3 = dword_139568 + 1320 * *((unsigned __int8 *)off_139564 + 10);
  v5 = *(unsigned __int8 *)(v3 + 1227);
  if ( !*(_BYTE *)(v3 + 1227) )
  {
    v7 = *((unsigned __int8 *)off_139564 + 7);
    v8 = dword_139580;
    v9 = *((unsigned __int16 *)off_139564 + 2);
    v10 = *(_DWORD *)(dword_139580 + 4 * (v7 + 174 * a2 + 102));
    v11 = *(unsigned __int16 *)(v10 + 8);
    if ( v11 != v9 )
      goto LABEL_3;
    goto LABEL_28;
  }
  v8 = dword_139580;
  v17 = rf_msg_process_body_n422(
          (unsigned __int8 *)(v3 + 107),
          (_DWORD *)(v3 + 1228),
          *(char **)(*(_DWORD *)(a1 + 28) + 8),
          1);
  v7 = *((unsigned __int8 *)v2 + 7);
  v9 = (unsigned __int16)v2[2];
  v10 = *(_DWORD *)(v8 + 4 * (v7 + 174 * a2 + 102));
  v11 = *(unsigned __int16 *)(v10 + 8);
  v5 = v17 == 1;
  if ( v9 == v11 )
  {
LABEL_15:
    if ( v5 )
    {
      v16 = 0;
LABEL_17:
      v18 = off_13956C;
      *(_BYTE *)(v10 + 288) = 1;
      v19 = *(unsigned __int8 *)(v10 + 10);
      *(_DWORD *)(v10 + 4) = v18[4];
      v20 = v10 + 4 * v19;
      if ( *(_DWORD *)(v20 + 16) )
      {
        *(_DWORD *)(v20 + 16) = 0;
        --*(_BYTE *)(v10 + 11);
      }
      v21 = (*(_WORD *)(v10 + 8) + 1) & 0xFFF;
      *(_BYTE *)(v10 + 10) = (v19 + 1) & 0x3F;
      *(_WORD *)(v10 + 8) = v21;
      idx_table_lookup_n3958(v10);
      tx_rate_idx_lookup_n2b8(a2, *((unsigned __int8 *)v2 + 7));
      return v16;
    }
LABEL_28:
    v26 = *(_WORD *)(a1 + 50) & 0xFF00;
    *(_DWORD *)(a1 + 96) |= 0x20u;
    *(_WORD *)(a1 + 50) = v26;
    sub_138CB4(a1, 3);
    v16 = 1;
    goto LABEL_17;
  }
LABEL_3:
  while ( 1 )
  {
    v12 = v9 - v11;
    v13 = v12 & 0xFFF;
    if ( (v12 & 0xFC0) == 0 )
      break;
    if ( v13 > 0x7FE )
    {
      if ( !*(_BYTE *)(v10 + 288) )
      {
        if ( (*v2 & 0x800) == 0 )
        {
          LOWORD(v14) = v2[1];
LABEL_8:
          *(_WORD *)(v8 + 2 * (v7 + 348 * a2) + 554) = v14;
          if ( !v5 )
          {
            v22 = *(_WORD *)(a1 + 50) & 0xFF00;
            *(_DWORD *)(a1 + 96) |= 0x20u;
            *(_WORD *)(a1 + 50) = v22;
            sub_138CB4(a1, 3);
          }
LABEL_10:
          tx_rate_idx_lookup_n2b8(a2, *((unsigned __int8 *)v2 + 7));
          return (unsigned __int8)(1 - v5);
        }
        v14 = (unsigned __int16)v2[1];
        if ( *(unsigned __int16 *)(v8 + 2 * (v7 + 348 * a2) + 554) != v14 )
          goto LABEL_8;
      }
      return 0;
    }
    sub_1392A8(v10, (unsigned __int16)(v13 - 63));
    v7 = *((unsigned __int8 *)v2 + 7);
    v9 = (unsigned __int16)v2[2];
    v10 = *(_DWORD *)(v8 + 4 * (174 * a2 + v7 + 102));
    v11 = *(unsigned __int16 *)(v10 + 8);
    if ( v9 == v11 )
      goto LABEL_15;
  }
  v23 = v10 + 4 * ((*(_BYTE *)(v10 + 10) + (_BYTE)v12) & 0x3F);
  *(_BYTE *)(v10 + 288) = 1;
  if ( !*(_DWORD *)(v23 + 16) )
  {
    if ( !v5 )
    {
      v27 = *(_WORD *)(a1 + 50) & 0xFF00;
      *(_DWORD *)(a1 + 96) |= 0x20u;
      *(_WORD *)(a1 + 50) = v27;
      sub_138CB4(a1, 3);
    }
    *(_DWORD *)(v23 + 16) = dword_139570;
    v24 = *(__int16 **)off_139574;
    v25 = (unsigned __int8)(*(_BYTE *)(v10 + 11) + 1);
    *(_BYTE *)(v10 + 11) = v25;
    if ( *v24 < 0 && v25 > 0x40 )
    {
      sub_12F46C(dword_13957C, dword_139578, 1860);
      v25 = *(unsigned __int8 *)(v10 + 11);
    }
    if ( v25 == 1 )
      timestamp_update(v10 + 272, *((_DWORD *)off_13956C + 4) + 50000);
    goto LABEL_10;
  }
  return 0;
}

