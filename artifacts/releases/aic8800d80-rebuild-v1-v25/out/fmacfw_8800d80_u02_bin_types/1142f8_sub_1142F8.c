// sub_1142F8 @ 0x1142f8, size 24 bytes
int  sub_1142F8(int a1)
{
  uint32_t *v1; // r2
  uint16_t *v2; // r1

  v1 = off_114310;
  v2 = off_114314;
  *((uint32_t *)off_114310 + 2) = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v1 = 0;
  v1[1] = 0;
  v2[6] = 0;
  return 1;
}

