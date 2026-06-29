// fwstruct annotate: 11597c_sub_11597C.c
// sub_11597C @ 0x11597c, size 300 bytes
_BYTE *sub_11597C()
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

  v0 = off_115AA8;
  v1 = off_115AAC;
  v2 = dword_115AB0;
  *(_BYTE *)off_115AAC = *(_BYTE *)off_115AA8 & 0xF;
  sub_12ECD0(2, v2);
  if ( *v0 << 28 )
  {
    v3 = off_115AB8;
    *(_DWORD *)off_115AB4 &= ~0x80000000;
    *v0 = 0;
    while ( (*v3 & 4) == 0 )
      ;
    v4 = off_115AB4;
    v5 = (unsigned __int8 *)off_115AC0;
    *(_DWORD *)off_115ABC = 4;
    v6 = v5[189];
    *v4 |= 0x80000000;
    if ( v6 )
      *(_DWORD *)((char *)v4 + 0xFFFFFFD4) |= 0x8000000u;
  }
  else
  {
    *(_DWORD *)off_115AD0 &= ~0x8000000u;
  }
  v7 = off_115AC4;
  v8 = off_115AA8;
  *(_DWORD *)off_115AC4 |= 0x111u;
  v1[1] = 1;
  *v8 = 32;
  v9 = (unsigned __int8 **)off_115AC8;
  *v7 &= 0xFFFFFEEE;
  v10 = **v9;
  if ( v10 == 3 )
  {
    v14 = off_115AD4;
    *(_DWORD *)off_115AD4 |= 1u;
    if ( (*v14 & 4) != 0 )
      *(_DWORD *)off_115AD8 = 512;
  }
  else if ( v10 == 1 )
  {
    sub_12EA10();
    v15 = off_115AE0;
    *(_DWORD *)off_115ADC |= 0x20u;
    v15[20] |= 0x20000u;
    v15[20] |= 0x8000u;
    v15[20] |= 0x10000u;
    v15[20] = v15[20] & 0xFFFFFFC0 | 0x37;
    v15[23] = v15[23] & 0x7FFFFFFC | 0x80000001;
  }
  result = off_115ACC;
  v12 = 0;
  *(_BYTE *)off_115ACC = 0;
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

