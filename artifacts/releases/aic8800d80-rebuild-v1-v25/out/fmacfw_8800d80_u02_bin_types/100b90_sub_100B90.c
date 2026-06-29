// sub_100B90 @ 0x100b90, size 60 bytes
uint32_t *sub_100B90()
{
  uint32_t *v0; // r3
  uint32_t *result; // r0
  uint32_t *v2; // r1
  uint8_t *v3; // r4

  v0 = off_100BD0;
  result = off_100BD4;
  v2 = off_100BD8;
  v3 = off_100BDC;
  *(uint32_t *)off_100BCC &= 0xFFFFF9FF;
  *v0 &= ~0x40000000u;
  *v0 &= ~0x80000000;
  *result &= ~0x1000u;
  *v2 &= 0xCFFFFFFF;
  *v3 = 0;
  return result;
}

