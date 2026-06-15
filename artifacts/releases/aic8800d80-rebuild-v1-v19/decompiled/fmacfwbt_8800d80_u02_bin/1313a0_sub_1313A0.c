// sub_1313A0 @ 0x1313a0, size 170 bytes
int __fastcall sub_1313A0(unsigned __int8 *a1, int a2, int a3)
{
  unsigned __int8 *v4; // r0
  unsigned int v5; // r6
  unsigned __int8 *v6; // r4
  int v7; // r3
  int v8; // r1
  __int16 v9; // r3
  int v10; // r2
  unsigned __int8 *v11; // r3
  unsigned __int8 *v12; // r1
  __int16 v13; // r4
  __int16 v14; // r0
  __int16 v15; // r1
  __int16 v16; // r3
  _BYTE v18[5]; // [sp+7h] [bp-5h] BYREF

  v4 = sub_12E0B8(a1, a2, v18);
  if ( !v4 )
    return 0;
  v5 = (unsigned int)&v4[v18[0] + 3];
  v6 = &v4[4 - a3];
  v7 = a3 - 1;
  do
  {
    *(_BYTE *)(v7 + 1) = v6[v7];
    ++v7;
  }
  while ( v7 != a3 + 5 );
  do
  {
    *(_BYTE *)(v7 + 1) = v6[v7];
    ++v7;
  }
  while ( v7 != a3 + 16 );
  v8 = *(unsigned __int8 *)(a3 + 6);
  v9 = v4[22] | (v4[23] << 8);
  *(_WORD *)(a3 + 18) = v4[20] | (v4[21] << 8);
  v10 = v8 >> 1;
  *(_WORD *)(a3 + 20) = v9;
  v11 = v4 + 24;
  if ( (v8 & 8) != 0 )
  {
    v12 = v4 + 28;
    if ( (unsigned int)(v4 + 28) <= v5 )
    {
      v13 = v4[24] | (v4[25] << 8);
      v14 = v4[26] | (v4[27] << 8);
      *(_WORD *)(a3 + 22) = v13;
      v11 = v12;
      *(_WORD *)(a3 + 24) = v14;
      goto LABEL_8;
    }
    return 0;
  }
LABEL_8:
  if ( (v10 & 8) != 0 )
  {
    if ( (unsigned int)(v11 + 4) <= v5 )
    {
      v15 = *v11 | (v11[1] << 8);
      v16 = v11[2] | (v11[3] << 8);
      *(_WORD *)(a3 + 26) = v15;
      *(_WORD *)(a3 + 28) = v16;
      return 1;
    }
    return 0;
  }
  return 1;
}

