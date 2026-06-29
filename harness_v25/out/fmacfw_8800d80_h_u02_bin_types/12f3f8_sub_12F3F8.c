// sub_12F3F8 @ 0x12f3f8, size 18 bytes
int sub_12F3F8()
{
  int result; // r0

  if ( **(uint8_t **)off_12F40C != 3 )
    return 1;
  result = *(uint32_t *)(*(uint32_t *)off_10CA98 + 612);
  *(uint32_t *)off_10CA9C = 32;
  if ( result )
    return 1;
  *(uint32_t *)off_10CAA0 = 32;
  return result;
}

