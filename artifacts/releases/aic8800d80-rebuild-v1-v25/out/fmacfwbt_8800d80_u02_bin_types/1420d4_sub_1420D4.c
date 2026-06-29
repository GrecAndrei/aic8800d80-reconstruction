// sub_1420D4 @ 0x1420d4, size 30 bytes
// Doc: sub_12420D4 [util]: Initialize firmware state register
// sub_12420D4 [util]: Initialize firmware state register
int  sub_1420D4(int a1)
{
  int result; // r0
  uint8_t *v3; // r2
  char v4; // r3

  result = sub_141F70(a1);
  v3 = off_1420F4;
  *(uint16_t *)a1 &= ~1u;
  v4 = *v3 - 1;
  *(uint8_t *)(a1 + 2) = 0;
  *v3 = v4;
  return result;
}

