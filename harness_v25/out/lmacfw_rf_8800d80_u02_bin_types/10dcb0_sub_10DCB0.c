// sub_10DCB0 @ 0x10dcb0, size 48 bytes
int sub_10DCB0()
{
  int result; // r0
  uint32_t *v1; // r3

  result = sub_10EFB4(dword_10DCE0, 0x2000, 15360);
  v1 = off_10DCE4;
  *((uint32_t *)off_10DCE4 + 2) |= 0xFu;
  v1[2] |= 0x10000000u;
  v1[3] &= 0xFFFFF7FE;
  return result;
}

