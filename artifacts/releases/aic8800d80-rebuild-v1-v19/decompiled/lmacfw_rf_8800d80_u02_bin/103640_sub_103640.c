// sub_103640 @ 0x103640, size 50 bytes
int sub_103640()
{
  _DWORD *v0; // r4
  int result; // r0

  v0 = off_103674;
  *(_DWORD *)off_103674 &= ~0x400000u;
  *v0 &= ~0x200000u;
  delay_us(2);
  *v0 |= 0x200000u;
  result = delay_us(2);
  *v0 |= 0x400000u;
  return result;
}

