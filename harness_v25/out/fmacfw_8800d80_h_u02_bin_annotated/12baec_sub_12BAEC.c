// fwstruct annotate: 12baec_sub_12BAEC.c
// sub_12BAEC @ 0x12baec, size 110 bytes
unsigned int sub_12BAEC()
{
  _DWORD *v0; // r2
  _DWORD *v1; // r0
  __int16 **v2; // r5
  int *v3; // r4
  int v4; // r3
  __int16 *v5; // r2
  unsigned int result; // r0
  _DWORD *v7; // r2

  v0 = off_12BB5C;
  v1 = off_12BB60;
  *(_DWORD *)off_12BB5C &= ~1u;
  v2 = (__int16 **)off_12BB64;
  v3 = (int *)off_12BB68;
  v4 = dword_12BB6C;
  *v0 &= ~2u;
  *v1 |= 0x700u;
  v5 = *v2;
  *v3 = v4;
  if ( *v5 < 0 && *(_DWORD *)off_12BB74 << 28 )
  {
    sub_12F35C(dword_12BB7C, dword_12BB78, 472);
    v4 = *v3;
  }
  *(_DWORD *)off_12BB70 = v4 | v3[1];
  result = sub_11DF40(1);
  v7 = off_12BB60;
  *(_DWORD *)off_12BB60 = *(_DWORD *)off_12BB60 & 0xFFFE3FFF | 0x10000;
  *v7 |= 0x2000u;
  return result;
}

