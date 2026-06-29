// sub_10D068 @ 0x10d068, size 70 bytes
int sub_10D068()
{
  uint32_t *v0; // r1
  uint32_t *v1; // r4
  uint32_t *v2; // r3

  v0 = off_10D0B0;
  v1 = off_10D0B4;
  v2 = off_10D0B8;
  *(uint32_t *)off_10D0B4 = 13369344;
  *v0 = 13369344;
  *v2 &= 0xFFFFFFCF;
  *v2 &= 0xFFFFFF3F;
  *v2 &= 0xFFFFCFFF;
  *v2 &= 0xFFFF3FFF;
  *v1 = 0x8000000;
  *v0 = 0x8000000;
  *v2 &= 0xFF3FFFFF;
  return 0x8000000;
}

