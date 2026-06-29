// sub_11F004 @ 0x11f004, size 44 bytes
int sub_11F004()
{
  uint32_t *v0; // r2
  int result; // r0

  v0 = off_11F034;
  *(uint32_t *)off_11F030 = 0x10000;
  *v0 &= ~0x10000u;
  result = sub_12D32C(0x80000);
  if ( *(uint8_t *)off_11F038 )
    return sub_1224F4(result);
  return result;
}

