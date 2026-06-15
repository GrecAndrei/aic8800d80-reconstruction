// v23 annotated: sub_11583C @ 0x11583c
// Original: 11583c_sub_11583C.c
// Primary struct: <unclustered>
//
// sub_11583C @ 0x11583c, size 300 bytes
_BYTE *sub_11583C()
{
  _DWORD *v0; // r4
  _BYTE *v1; // r5
  int v2; // r1
  _DWORD *v3; // r2
  _DWORD *v4; // r2
  unsigned __int8 *v5; // r1
  int v6; // r1
  _DWORD *v7; // r2
  _DWORD *v8; // r1
  unsigned __int8 **v9; // r1
  int v10; // r3
  _BYTE *result; // r0
  int v12; // r2
  _DWORD *v13; // r3
  _DWORD *v14; // r3
  _DWORD *v15; // r3

  v0 = off_115968;
  v1 = off_11596C;
  v2 = dword_115970;
  *(_BYTE *)off_11596C = *(_BYTE *)off_115968 & 0xF;
  sub_12EB90(2, v2);
  if ( *v0 << 28 )
  {
    v3 = off_115978;
    *(_DWORD *)off_115974 &= ~0x80000000;
    *v0 = 0;
    while ( (*v3 & 4) == 0 )
      ;
    v4 = off_115974;
    v5 = (unsigned __int8 *)off_115980;
    *(_DWORD *)off_11597C = 4;
    v6 = v5[189];
    *v4 |= 0x80000000;
    if ( v6 )
      *(_DWORD *)((char *)v4 + 0xFFFFFFD4) |= 0x8000000u;
  }
  else
  {
    *(_DWORD *)off_115990 &= ~0x8000000u;
  }
  v7 = off_115984;
  v8 = off_115968;
  *(_DWORD *)off_115984 |= 0x111u;
  v1[1] = 1;
  *v8 = 32;
  v9 = (unsigned __int8 **)off_115988;
  *v7 &= 0xFFFFFEEE;
  v10 = **v9;
  if ( v10 == 3 )
  {
    v14 = off_115994;
    *(_DWORD *)off_115994 |= 1u;
    if ( (*v14 & 4) != 0 )
      *(_DWORD *)off_115998 = 512;
  }
  else if ( v10 == 1 )
  {
    sub_12E8D0();
    v15 = off_1159A0;
    *(_DWORD *)off_11599C |= 0x20u;
    v15[20] |= 0x20000u;
    v15[20] |= 0x8000u;
    v15[20] |= 0x10000u;
    v15[20] = v15[20] & 0xFFFFFFC0 | 0x37;
    v15[23] = v15[23] & 0x7FFFFFFC | 0x80000001;
  }
  result = off_11598C;
  v12 = 0;
  *(_BYTE *)off_11598C = 0;
  while ( 1 )
  {
    v13 = (_DWORD *)(4 * v12++ - 536813312);
    if ( (v13[64] & *v13) != 0 )
      break;
    if ( v12 == 3 )
      return result;
  }
  *result = 1;
  return result;
}

