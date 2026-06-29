// fwstruct annotate: 1400c4_sub_1400C4.c
// sub_1400C4 @ 0x1400c4, size 284 bytes
int __fastcall sub_1400C4(int result)
{
  unsigned int v1; // r6
  int v2; // r4
  int v3; // r7
  int v4; // r5
  char v5; // r3
  char v6; // r3
  _DWORD *v7; // r8
  int v8; // r1
  __int16 v9; // r2
  bool v10; // nf
  unsigned int v11; // r6
  char v12; // r3
  char v13; // r3
  int v14; // r0
  char v15; // r3

  v1 = *(unsigned __int8 *)(result + 29);
  v2 = result;
  if ( v1 > 0x1F )
  {
    *(_BYTE *)(result + 54) = 0;
  }
  else
  {
    v3 = dword_1401E4;
    v4 = *(_DWORD *)(dword_1401E4 + 696 * v1 + 340);
    if ( **(__int16 **)off_1401E0 < 0 && !v4 )
      sub_12F32C(dword_1401F0, dword_1401EC, 2758);
    v5 = *(_BYTE *)(v4 + 166);
    if ( (*(_DWORD *)(v2 + 36) & 0x200000) != 0 && (*(_BYTE *)(v4 + 166) & 4) != 0 )
      v6 = v5 | 2;
    else
      v6 = v5 & 0xFD;
    v7 = off_1401F4;
    *(_BYTE *)(v4 + 166) = v6;
    if ( v7[4] - *(_DWORD *)v4 > (unsigned int)dword_1401E8 )
    {
      v14 = sub_13F490(v4, 0);
      v15 = (*(_BYTE *)(v4 + 167) + 1) & 3;
      *(_BYTE *)(v4 + 167) = v15;
      *(_BYTE *)(v4 + 154) = 0;
      *(_BYTE *)(v4 + 168) = 0;
      *(_DWORD *)v4 = v7[4];
      *(_BYTE *)(v2 + 54) = 4 * v15;
      if ( v14 )
      {
        if ( !sub_13D33C(v4) )
          *(_DWORD *)(v2 + 36) &= ~0x200000u;
        *(_BYTE *)(v3 + 696 * v1 + 350) |= 0x11u;
      }
    }
    else
    {
      *(_BYTE *)(v2 + 54) = *(_BYTE *)(v4 + 168) | (4 * *(_BYTE *)(v4 + 167));
    }
    result = sub_13EB30(v4);
    if ( result )
    {
      v8 = *(_DWORD *)(v2 + 36);
      v9 = *(_WORD *)(v2 + 30);
      *(_BYTE *)(v2 + 54) &= 0xFCu;
      v10 = (v8 & 0x200000) != 0;
      v11 = v3 + 696 * v1;
      v12 = *(_BYTE *)(v11 + 350);
      *(_WORD *)(v2 + 30) = v9 | 0x2000;
      if ( (v8 & 0x200000) != 0 )
        v8 |= 0x280000u;
      v13 = v12 | 0x20;
      if ( v10 )
        *(_DWORD *)(v2 + 36) = v8;
      *(_BYTE *)(v11 + 350) = v13;
    }
  }
  return result;
}

