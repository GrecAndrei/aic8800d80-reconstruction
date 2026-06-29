// sub_142038 @ 0x142038, size 30 bytes
int  sub_142038(int a1)
{
  int result; // r0
  uint8_t *v3; // r2
  char v4; // r3

  result = msg_parse_top_nibble(a1);
  v3 = off_142058;
  *(uint16_t *)a1 &= ~1u;
  v4 = *v3 - 1;
  *(uint8_t *)(a1 + 2) = 0;
  *v3 = v4;
  return result;
}

