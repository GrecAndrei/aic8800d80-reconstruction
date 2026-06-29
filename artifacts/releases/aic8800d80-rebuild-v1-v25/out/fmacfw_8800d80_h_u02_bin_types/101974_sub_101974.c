// sub_101974 @ 0x101974, size 20 bytes
unsigned int  sub_101974(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(uint32_t *)off_101988 & 0xFFFFFFF7;
  *(uint32_t *)off_101988 = result;
  return result;
}

