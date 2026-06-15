// v23 annotated: sub_1426B8 @ 0x1426b8
// Original: 1426b8_sub_1426B8.c
// Primary struct: <unclustered>
//
// sub_1426B8 @ 0x1426b8, size 142 bytes
__int64 __fastcall sub_1426B8(__int64 a1)
{
  int v1; // r7
  int v2; // r4
  int v3; // r5
  __int64 v4; // r2
  int v5; // r3
  unsigned int v6; // r7
  int v7; // r3
  bool v8; // cf
  int v9; // r3

  v1 = (HIDWORD(a1) >> 20) & 0x7FF;
  v2 = v1 - 1023;
  v3 = HIDWORD(a1);
  v4 = a1;
  if ( v1 - 1023 > 19 )
  {
    if ( v2 <= 51 )
    {
      v6 = 0xFFFFFFFF >> ((HIDWORD(a1) >> 20) - 19);
      if ( ((unsigned int)a1 & v6) != 0 )
      {
        v7 = 1 << (51 - v2);
        v8 = __CFADD__((_DWORD)a1, v7);
        v9 = a1 + v7;
        if ( v8 )
          v3 = HIDWORD(a1) + 1;
        v5 = v9 & ~v6;
        return __PAIR64__(v3, v5);
      }
    }
    else if ( v1 == 2047 )
    {
      return sub_1427D8(a1, HIDWORD(a1), a1, HIDWORD(a1));
    }
  }
  else
  {
    if ( v2 < 0 )
    {
      v3 = HIDWORD(a1) & 0x80000000;
      if ( v1 == 1022 )
        v3 |= 0x3FF00000u;
      v5 = 0;
      return __PAIR64__(v3, v5);
    }
    if ( HIDWORD(a1) & (dword_142748 >> ((HIDWORD(a1) >> 20) + 1)) | (unsigned int)a1 )
    {
      v3 = (HIDWORD(a1) + (0x80000 >> ((HIDWORD(a1) >> 20) + 1))) & ~(dword_142748 >> ((HIDWORD(a1) >> 20) + 1));
      v5 = 0;
      return __PAIR64__(v3, v5);
    }
  }
  return v4;
}

