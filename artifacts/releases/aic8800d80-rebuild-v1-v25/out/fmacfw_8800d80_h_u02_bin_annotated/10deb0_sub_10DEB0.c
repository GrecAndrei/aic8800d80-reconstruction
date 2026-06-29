// fwstruct annotate: 10deb0_sub_10DEB0.c
// sub_10DEB0 @ 0x10deb0, size 72 bytes
int sub_10DEB0()
{
  _DWORD *v0; // r3
  _DWORD *v1; // r0
  int v2; // r1
  int v3; // r2
  int result; // r0

  v0 = off_10DEF8;
  v1 = off_10DEFC;
  v2 = dword_10DF00;
  v3 = dword_10DF04;
  *(_DWORD *)off_10DEF8 = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  result = v0[3];
  v0[3] = v2 & result | 0xA06A000;
  v0[3] = v3 & v0[3] | 0x100230;
  v0[1] = 1;
  return result;
}

