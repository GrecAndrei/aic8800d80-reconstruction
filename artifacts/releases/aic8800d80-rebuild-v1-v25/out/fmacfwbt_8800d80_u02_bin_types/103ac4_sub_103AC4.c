// sub_103AC4 @ 0x103ac4, size 50 bytes
int sub_103AC4()
{
  uint32_t *v0; // r4
  int result; // r0

  v0 = off_103AF8;
  *(uint32_t *)off_103AF8 &= ~0x400000u;
  *v0 &= ~0x200000u;
  sub_100644(2);
  *v0 |= 0x200000u;
  result = sub_100644(2);
  *v0 |= 0x400000u;
  return result;
}

