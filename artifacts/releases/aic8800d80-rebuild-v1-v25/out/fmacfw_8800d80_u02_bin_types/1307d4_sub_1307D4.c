// sub_1307D4 @ 0x1307d4, size 46 bytes
// Doc: sub_12307D4 [util]: Initialize descriptor header with magic bytes F/5/p
// sub_12307D4 [util]: Initialize descriptor header with magic bytes F/5/p
int  sub_1307D4(int a1)
{
  **(uint8_t **)a1 = 70;
  *(uint8_t *)(*(uint32_t *)a1 + 1) = 5;
  *(uint8_t *)(*(uint32_t *)a1 + 2) = 112;
  *(uint8_t *)(*(uint32_t *)a1 + 3) = 0;
  *(uint8_t *)(*(uint32_t *)a1 + 4) = 0;
  *(uint8_t *)(*(uint32_t *)a1 + 5) = 0;
  *(uint8_t *)(*(uint32_t *)a1 + 6) = 0;
  *(uint32_t *)a1 += 7;
  return 7;
}

