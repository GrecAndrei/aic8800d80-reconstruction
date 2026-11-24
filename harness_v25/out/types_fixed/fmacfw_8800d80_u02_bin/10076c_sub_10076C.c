// sub_10076C @ 0x10076c, size 42 bytes
_DWORD *sub_10076C()
{
  _DWORD *result; // r0
  unsigned int *v1; // r2

  result = off_10079C;
  v1 = (unsigned int *)off_1007A0;
  *(_DWORD *)off_100798 &= ~0x10000u;
  *result = 1;
  *v1 = *v1 & 0x1FFFFFFE | 0xC0000000;
  return result;
}

