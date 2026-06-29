// sub_101A20 @ 0x101a20, size 20 bytes
unsigned int  sub_101A20(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(uint32_t *)off_101A34 & 0xFFFFFFF7;
  *(uint32_t *)off_101A34 = result;
  return result;
}

