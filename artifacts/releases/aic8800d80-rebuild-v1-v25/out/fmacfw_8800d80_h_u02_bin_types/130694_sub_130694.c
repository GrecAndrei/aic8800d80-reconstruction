// sub_130694 @ 0x130694, size 46 bytes
int  sub_130694(int a1)
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

