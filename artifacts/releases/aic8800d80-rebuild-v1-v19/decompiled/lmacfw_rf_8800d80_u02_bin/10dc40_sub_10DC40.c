// sub_10DC40 @ 0x10dc40, size 48 bytes
int sub_10DC40()
{
  int result; // r0
  _DWORD *v1; // r3

  result = sub_10EFB4(dword_10DC70, 2048, 15360);
  v1 = off_10DC74;
  *((_DWORD *)off_10DC74 + 2) |= 0xFu;
  v1[2] |= 0x10000000u;
  v1[3] &= 0xFFFFF7FE;
  return result;
}

