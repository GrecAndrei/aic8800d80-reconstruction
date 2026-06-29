// sub_13AFC0 @ 0x13afc0, size 24 bytes
int  sub_13AFC0(int a1, int a2)
{
  __int16 v2; // r2

  v2 = *(uint16_t *)(a1 + 30) | 1;
  *(uint32_t *)(a1 + 68) = 0;
  *(uint32_t *)(a1 + 80) = 0;
  *(uint16_t *)(a1 + 30) = v2;
  return sub_13AC44(a1, a2);
}

