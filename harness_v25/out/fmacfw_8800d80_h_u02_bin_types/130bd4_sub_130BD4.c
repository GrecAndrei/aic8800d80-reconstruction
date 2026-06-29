// sub_130BD4 @ 0x130bd4, size 54 bytes
int  sub_130BD4(int a1, int a2)
{
  __int16 v2; // r3
  __int16 v3; // r4
  __int16 v4; // r2

  *(uint8_t *)a1 = 3;
  *(uint8_t *)(a1 + 1) = 0;
  *(uint8_t *)(a1 + 2) = *(uint8_t *)(a2 + 23);
  v2 = *(unsigned __int8 *)(a2 + 22);
  v3 = *(unsigned __int8 *)(a2 + 18);
  v4 = *(uint16_t *)(a2 + 20);
  *(uint16_t *)(a1 + 5) = *(uint16_t *)(a2 + 14);
  *(uint16_t *)(a1 + 3) = (4 * v2) | (2 * v3) | (v4 << 6);
  *(uint16_t *)(a1 + 7) = 16 * *(uint16_t *)(a2 + 12);
  return 9;
}

