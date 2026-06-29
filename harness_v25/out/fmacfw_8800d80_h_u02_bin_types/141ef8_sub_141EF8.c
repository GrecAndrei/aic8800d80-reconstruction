// sub_141EF8 @ 0x141ef8, size 30 bytes
int  sub_141EF8(int a1)
{
  int result; // r0
  uint8_t *v3; // r2
  char v4; // r3

  result = sub_141D94(a1);
  v3 = off_141F18;
  *(uint16_t *)a1 &= ~1u;
  v4 = *v3 - 1;
  *(uint8_t *)(a1 + 2) = 0;
  *v3 = v4;
  return result;
}

