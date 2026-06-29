// sub_107518 @ 0x107518, size 96 bytes
uint32_t *sub_107518()
{
  unsigned int *v0; // r2
  uint32_t *v1; // r3
  uint32_t *result; // r0

  v0 = (unsigned int *)off_107578;
  v1 = off_10757C;
  result = off_107580;
  *(uint32_t *)off_107578 = *(uint32_t *)off_107578 & 0xC0FFFFFF | 0x3000000;
  *v0 = *v0 & 0xFFC0FFFF | 0x30000;
  *v0 = *v0 & 0xFFFFC0FF | 0x300;
  *v0 = *v0 & 0xFFFFFFC0 | 3;
  *v1 &= 0xC0FFFFFF;
  *v1 &= 0xFFC0FFFF;
  *v1 &= 0xFFFFC0FF;
  *v1 &= 0xFFFFFFC0;
  *result &= 0xFFFFFFC0;
  return result;
}

