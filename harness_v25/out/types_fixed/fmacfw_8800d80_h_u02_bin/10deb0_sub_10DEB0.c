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
  *(_DWORD *)(v1 + 0x38) = 296;
  *(_DWORD *)(v0 + 0x8) = *(_DWORD *)(v0 + 0x8) & 0xF000FFFF | 0x2000000;
  result = *(_DWORD *)(v0 + 0xc);
  *(_DWORD *)(v0 + 0xc) = v2 & result | 0xA06A000;
  *(_DWORD *)(v0 + 0xc) = v3 & *(_DWORD *)(v0 + 0xc) | 0x100230;
  *(_DWORD *)(v0 + 0x4) = 1;
  return result;
}

