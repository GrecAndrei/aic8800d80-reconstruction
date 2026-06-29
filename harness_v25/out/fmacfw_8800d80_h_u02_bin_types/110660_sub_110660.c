// sub_110660 @ 0x110660, size 52 bytes
int  sub_110660(int a1)
{
  uint32_t *v1; // r2
  uint32_t *v2; // r1

  v1 = off_110694;
  v2 = off_110698;
  *(uint32_t *)off_110694 = 0;
  v1[1] = 0;
  v1[2] = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v2 = 0;
  v2[1] = 0;
  v2[4] = 0;
  v2[5] = 0;
  *((uint16_t *)v2 + 6) = 0;
  v2[2] = 0;
  *((uint8_t *)v2 + 14) = 0;
  *((uint16_t *)v2 + 14) = 0;
  v2[6] = 0;
  *((uint8_t *)v2 + 30) = 0;
  sub_1104FC((int)v1, (int)v2);
  return 1;
}

