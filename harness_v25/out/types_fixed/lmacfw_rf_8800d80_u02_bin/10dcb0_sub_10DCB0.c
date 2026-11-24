// sub_10DCB0 @ 0x10dcb0, size 48 bytes
int sub_10DCB0()
{
  int result; // r0
  _DWORD *v1; // r3

  result = sub_10EFB4(dword_10DCE0, 0x2000, 15360);
  v1 = off_10DCE4;
  *((_DWORD *)off_10DCE4 + 2) |= 0xFu;
  *(_DWORD *)(v1 + 0x8) |= 0x10000000u;
  *(_DWORD *)(v1 + 0xc) &= 0xFFFFF7FE;
  return result;
}

