// fwstruct annotate: 11ae24_sub_11AE24.c
// sub_11AE24 @ 0x11ae24, size 322 bytes
int __fastcall sub_11AE24(int a1, int a2, int a3)
{
  int v3; // r8
  _DWORD *v4; // r9
  int v5; // r11
  int v8; // r10
  int v9; // r7
  int v10; // r3
  int v11; // r0
  int v12; // r4
  int v13; // r7
  int v14; // r2
  int result; // r0
  int v16; // r4
  int v17; // r4
  int v18; // r3
  int v19; // r7
  _DWORD *v20; // [sp+4h] [bp-8h]

  v3 = a3;
  v4 = off_11AF70;
  v5 = dword_11AF74;
  v8 = a1 + 76;
  if ( !a3 )
    goto LABEL_21;
  while ( 1 )
  {
    v9 = *(_DWORD *)(a1 + 72);
    if ( v4[8] )
      break;
    v10 = v4[20];
    if ( !v10 )
      goto LABEL_5;
    if ( v9 == v10 )
      goto LABEL_5;
    v19 = v4[21];
    if ( a2 - v19 - 4000 - sub_101A20() >= 0 )
      goto LABEL_5;
LABEL_18:
    if ( *(_BYTE *)(a1 + 94) )
      v18 = 102400;
    else
      v18 = *(_DWORD *)(dword_11AF6C + 152 * *(unsigned __int8 *)(a1 + 102) + 8);
    ++v3;
    a2 += v18;
    if ( !v3 )
    {
LABEL_21:
      if ( (*(_BYTE *)(a1 + 85) & 1) != 0 )
      {
        sub_11E7C4(dword_11AF68, v8);
        *(_BYTE *)(a1 + 85) &= ~1u;
      }
    }
  }
  v20 = (_DWORD *)v4[9];
  v16 = v20[1];
  v17 = v16 + 4000 + sub_101A20();
  if ( v9 != v20[2] )
  {
    v17 += 4000 + sub_101A20();
    if ( v20[3] )
      v17 += 10000;
  }
  if ( a2 - v17 < 0 )
    goto LABEL_18;
LABEL_5:
  *(_DWORD *)(a1 + 80) = a2;
  v11 = sub_101A20();
  v12 = v4[4];
  v13 = a2 + 13999 + v11;
  if ( v12 )
  {
    while ( 1 )
    {
      v14 = *(_DWORD *)(v12 + 4);
      if ( v13 - v14 < 0 )
        break;
      if ( *(_DWORD *)(v5 + 224 * *(unsigned __int8 *)(a1 + 84) + 72) != *(_DWORD *)(v5
                                                                                   + 224 * *(unsigned __int8 *)(v12 + 8)
                                                                                   + 72) )
      {
        if ( sub_11AD88(v8, v12) )
          goto LABEL_18;
        v14 = *(_DWORD *)(v12 + 4);
      }
      if ( a2 - v14 < 0 )
        break;
      v12 = *(_DWORD *)v12;
      if ( !v12 )
        goto LABEL_24;
    }
  }
  else
  {
LABEL_24:
    v12 = 0;
  }
  result = sub_11E888(dword_11AF68, v12, v8);
  *(_BYTE *)(a1 + 85) |= 1u;
  return result;
}

