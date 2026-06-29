// sub_101A50 @ 0x101a50, size 20 bytes
unsigned int  sub_101A50(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(uint32_t *)off_101A64 & 0xFFFFFFF7;
  *(uint32_t *)off_101A64 = result;
  return result;
}

