// sub_1141B8 @ 0x1141b8, size 24 bytes
int  sub_1141B8(int a1)
{
  uint32_t *v1; // r2
  uint16_t *v2; // r1

  v1 = off_1141D0;
  v2 = off_1141D4;
  *((uint32_t *)off_1141D0 + 2) = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v1 = 0;
  v1[1] = 0;
  v2[6] = 0;
  return 1;
}

