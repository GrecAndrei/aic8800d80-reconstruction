// sub_127AEC @ 0x127aec, size 38 bytes
int  sub_127AEC(int a1)
{
  int v2; // r0
  int result; // r0

  v2 = sub_121BE4(*(uint32_t *)(a1 + 88));
  *(uint32_t *)(a1 + 88) = v2;
  result = sub_12ACF8(a1, v2);
  *(uint8_t *)(a1 + 85) = *(uint8_t *)(a1 + 85) & 0x9F | 0x20;
  return result;
}

