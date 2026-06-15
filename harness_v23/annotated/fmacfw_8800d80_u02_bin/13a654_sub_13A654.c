// v23 annotated: sub_13A654 @ 0x13a654
// Original: 13a654_sub_13A654.c
// Primary struct: <unclustered>
//
// sub_13A654 @ 0x13a654, size 168 bytes
int __fastcall sub_13A654(int a1)
{
  __int16 v1; // r2
  int result; // r0
  int v4; // r1
  int v5; // r5
  int v6; // r3
  char v7; // r5
  __int16 v8; // r7
  int v9; // r1
  unsigned int v10; // r3
  char v11; // r5
  char v12; // r1
  int v13; // [sp+4h] [bp-8h] BYREF

  v1 = *(_WORD *)(a1 + 30);
  result = *(unsigned __int8 *)(a1 + 29);
  v4 = *(unsigned __int8 *)(a1 + 28);
  *(_DWORD *)(a1 + 36) = 0;
  *(_DWORD *)(a1 + 40) = 0;
  if ( (v1 & 1) == 0 )
  {
    v5 = *(unsigned __int8 *)(a1 + 27);
    if ( v5 == 255 )
    {
      v7 = 24;
    }
    else
    {
      v6 = dword_13A6FC + 2 * (v5 + 348 * result + 156);
      v7 = 26;
      v8 = *(_WORD *)(v6 + 4);
      *(_WORD *)(v6 + 4) = (v8 + 1) & 0xFFF;
      *(_WORD *)(a1 + 32) = v8;
    }
    v9 = dword_13A700 + 1320 * v4;
    if ( (v1 & 0x100) != 0 )
      v7 += 6;
    if ( !*(_BYTE *)(v9 + 106) && (*(_DWORD *)(dword_13A6FC + 696 * result + 4) & 0x20) != 0 )
      v7 += 4;
    *(_BYTE *)(a1 + 50) = v7;
    result = sub_13A528(a1, &v13);
    v10 = *(unsigned __int16 *)(a1 + 24);
    *(_WORD *)(a1 + 48) = *(_WORD *)(a1 + 4);
    v11 = v7 + result;
    *(_BYTE *)(a1 + 53) = v13;
    if ( (unsigned __int16)__rev16(v10) <= 0x600u )
    {
      v12 = 0;
    }
    else
    {
      v11 += 8;
      v12 = 8;
    }
    *(_BYTE *)(a1 + 51) = v11;
    *(_BYTE *)(a1 + 66) = v11;
    *(_BYTE *)(a1 + 52) = v12;
  }
  return result;
}

