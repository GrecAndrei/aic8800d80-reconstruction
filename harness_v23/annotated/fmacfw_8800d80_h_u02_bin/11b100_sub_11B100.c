// v23 annotated: sub_11B100 @ 0x11b100
// Original: 11b100_sub_11B100.c
// Primary struct: <unclustered>
//
// sub_11B100 @ 0x11b100, size 272 bytes
int __fastcall sub_11B100(int *a1)
{
  unsigned __int16 *v1; // r6
  int v2; // r3
  int v3; // r9
  int v5; // r4
  int v6; // r10
  int v7; // r3
  int v8; // r2
  int *v9; // r5
  int v10; // r10
  int v11; // r3
  int v12; // r2
  int v13; // r11
  int v15; // r0
  int v16; // r4
  __int16 v17; // r3

  v1 = (unsigned __int16 *)off_11B210;
  if ( *((unsigned __int8 *)off_11B210 + 197) > 3u )
    return 0;
  v2 = 3;
  v3 = dword_11B224;
  LOBYTE(v5) = 3;
  while ( 1 )
  {
    v7 = v3 + 84 * v2;
    v8 = *(unsigned __int8 *)(v7 + 26);
    *((_BYTE *)v1 + 190) = v5;
    if ( v8 == 1 )
      break;
    v9 = *(int **)(v7 + 12);
    if ( v9 )
    {
      v10 = v7;
      v11 = v9[9] & 0x200000;
      if ( v11 )
      {
LABEL_13:
        v13 = (int)v9;
        v9 = nullptr;
      }
      else
      {
        while ( 1 )
        {
          v12 = v9[19];
          if ( *(int *)(v12 + 72) >= 0 )
            break;
          if ( *(_DWORD *)(v12 + 16) )
          {
            v13 = *v9;
            if ( *(int *)(*(_DWORD *)(*v9 + 76) + 72) >= 0 )
              goto LABEL_3;
          }
          sub_11B068((int)v9, (unsigned __int8)v5);
          v9 = *(int **)(v10 + 12);
          if ( !v9 )
            goto LABEL_4;
          v11 = v9[9] & 0x200000;
          if ( v11 )
            goto LABEL_13;
        }
        v13 = (int)v9;
        v9 = (int *)v11;
      }
LABEL_3:
      v6 = sub_11ACF0(v13, a1, *((_DWORD *)v1 + 44), v1[93], *((_BYTE *)v1 + 190));
      if ( v6 )
      {
        if ( v9 )
          sub_11B068((int)v9, (unsigned __int8)v5);
        v16 = *(_DWORD *)(v13 + 68);
        if ( **(__int16 **)off_11B218 < 0 && !v16 )
          sub_12F32C(dword_11B220, dword_11B21C, 1383);
        v17 = *(_WORD *)(v16 + 8);
        *((_DWORD *)v1 + 51) = v16;
        *(_WORD *)(v16 + 8) = v17 | 0x200;
        return v6;
      }
    }
LABEL_4:
    v5 = (char)(v5 - 1);
    v2 = v5;
    if ( v5 < *((unsigned __int8 *)v1 + 197) )
      return 0;
  }
  if ( !*(_BYTE *)(*(_DWORD *)off_11B214 + 1) )
    return 0;
  v15 = *(_DWORD *)(v7 + 36);
  *a1 = *(_DWORD *)(v7 + 12);
  return v15 + 84;
}

