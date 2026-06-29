// fwstruct annotate: 13f244_sub_13F244.c
// sub_13F244 @ 0x13f244, size 354 bytes
int __fastcall sub_13F244(int a1, int a2)
{
  int result; // r0
  unsigned int v4; // r11
  char v6; // r3
  unsigned __int16 v7; // r6
  unsigned int v8; // lr
  int v9; // r10
  unsigned int v10; // r5
  int v11; // r4
  unsigned int v12; // r0
  int v13; // r2
  unsigned int v14; // r3
  unsigned int v15; // r3
  int v16; // r2
  int v17; // r12
  unsigned int v18; // r3
  unsigned int v19; // r4
  _DWORD v20[11]; // [sp+0h] [bp-2Ch] BYREF

  result = dword_13F3AC;
  v4 = *(_DWORD *)(dword_13F3AC + 696 * a1 + 340);
  if ( **(__int16 **)off_13F3A8 < 0 && !v4 )
    result = sub_12F46C(dword_13F3B4, dword_13F3B0, 3356);
  if ( *(unsigned __int8 *)(v4 + 182) == a2 )
    return result;
  *(_BYTE *)(v4 + 182) = a2;
  if ( !a2 )
    return result;
  v6 = *(_BYTE *)(v4 + 166);
  v7 = v6 & 0x20;
  if ( (v6 & 0x20) != 0 )
  {
    *(_BYTE *)(v4 + 166) = v6 | 0x80;
    return result;
  }
  v8 = sub_13D34C(v4);
  *(_WORD *)(v4 + 184) = v8;
  if ( !v8 )
    goto LABEL_18;
  while ( 1 )
  {
    v9 = v7;
    v10 = v4 + 12 * v7;
    v11 = 2 * v7;
    v12 = *(unsigned __int16 *)(v10 + 10);
    v13 = (v12 >> 11) & 6;
    if ( (v12 & 0x2000) == 0 )
      break;
    v14 = v12 & 0xF;
    if ( !v13 )
      goto LABEL_10;
LABEL_21:
    ++v7;
    v19 = v4 + 4 * (v11 + v9);
    *(_BYTE *)(v19 + 14) = 1;
    *(_WORD *)(v10 + 10) = v12;
    *(_WORD *)(v10 + 8) = 0;
    *(_BYTE *)(v19 + 13) = 0;
    v20[v9] = 0;
    if ( v7 >= v8 )
      goto LABEL_18;
  }
  if ( ((v12 >> 11) & 6) != 0 )
    v14 = v12 & 7;
  else
    v14 = v12 & 0x7F;
  if ( v13 )
    goto LABEL_21;
LABEL_10:
  if ( v14 > 3 || (v12 & 0x400) != 0 )
    goto LABEL_21;
  v12 = (unsigned __int16)v12 | 0x400;
  if ( v8 )
  {
    do
    {
      v15 = v4;
      v16 = 0;
      while ( 1 )
      {
        v17 = *(unsigned __int16 *)(v15 + 10);
        ++v16;
        v15 += 12;
        if ( v17 == v12 )
          break;
        if ( v16 == v8 )
          goto LABEL_21;
      }
      v12 = sub_13D694(v4);
      v8 = *(unsigned __int16 *)(v4 + 184);
    }
    while ( *(_WORD *)(v4 + 184) );
  }
  v18 = v4 + 12 * v7;
  *(_BYTE *)(v18 + 14) = 1;
  *(_WORD *)(v10 + 10) = v12;
  *(_WORD *)(v10 + 8) = v8;
  *(_BYTE *)(v18 + 13) = v8;
  v20[v7] = v8;
LABEL_18:
  sub_13E1D0(v4, (int)v20);
  result = sub_13CFF0(v4, v20);
  *(_BYTE *)(dword_13F3AC + 696 * a1 + 350) |= 1u;
  return result;
}

