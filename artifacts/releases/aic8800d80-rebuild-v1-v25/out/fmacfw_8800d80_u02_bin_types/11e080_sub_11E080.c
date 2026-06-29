// sub_11E080 @ 0x11e080, size 44 bytes
unsigned int  sub_11E080(int a1)
{
  unsigned int *v1; // r1
  unsigned int result; // r0

  v1 = (unsigned int *)off_11E0B0;
  *(uint32_t *)off_11E0AC = (a1 << 10) & 0x400 | *(uint32_t *)off_11E0AC & 0xFFFFFBFF;
  result = (a1 << 19) & 0x80000 | *v1 & 0xFFF7FFFF;
  *v1 = result;
  return result;
}

