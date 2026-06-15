// v23 annotated: sub_143338 @ 0x143338
// Original: 143338_sub_143338.c
// Primary struct: <unclustered>
//
// sub_143338 @ 0x143338, size 140 bytes
int __fastcall sub_143338(__int64 a1)
{
  bool v1; // zf
  unsigned int v2; // r12
  int v3; // r3
  signed int v4; // r2
  bool v5; // cc
  int v6; // r2
  int v7; // r3
  int v8; // r12
  char v9; // r2

  if ( a1 )
  {
    v2 = HIDWORD(a1);
    v1 = HIDWORD(a1) == 0;
    if ( !HIDWORD(a1) )
    {
      v2 = a1;
      HIDWORD(a1) = a1;
      LODWORD(a1) = 0;
    }
    v3 = 1526726656;
    if ( v1 )
      v3 = 1258291200;
    v4 = __clz(v2);
    v5 = v4 < 8;
    v6 = v4 - 8;
    v7 = v3 - 0x800000 - (v6 << 23);
    if ( v5 )
    {
      v9 = v6 + 32;
      v1 = ((unsigned int)a1 | (2 * (HIDWORD(a1) << v9))) == 0;
      LODWORD(a1) = (HIDWORD(a1) >> (32 - v9)) + __CFSHL__(HIDWORD(a1) << v9, 1) + v7;
      if ( v1 )
        LODWORD(a1) = a1 & ~(HIDWORD(a1) << v9 >> 31);
    }
    else
    {
      v8 = (_DWORD)a1 << v6;
      LODWORD(a1) = ((unsigned int)a1 >> (32 - v6)) + ((_DWORD)a1 << v6 >= 0x80000000) + v7 + (HIDWORD(a1) << v6);
      if ( v8 == 0x80000000 )
        LODWORD(a1) = a1 & 0xFFFFFFFE;
    }
  }
  return a1;
}

