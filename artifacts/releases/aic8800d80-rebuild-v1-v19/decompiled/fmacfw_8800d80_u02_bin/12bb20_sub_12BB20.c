// sub_12BB20 @ 0x12bb20, size 32 bytes
// Doc: sub_122BB20 [mmio]: MMIO clear of MSB bit on 0x40328074/0x40328080/0x40328068 register banks
// sub_122BB20 [mmio]: MMIO clear of MSB bit on 0x40328074/0x40328080/0x40328068 register banks
void *sub_12BB20()
{
  void *result; // r0
  _DWORD *v1; // r1
  _DWORD *v2; // r2

  result = off_12BB40;
  v1 = off_12BB44;
  v2 = off_12BB48;
  *(_DWORD *)off_12BB40 &= ~0x80000000;
  *v1 &= ~0x80000000;
  *v2 &= ~0x80000000;
  return result;
}

