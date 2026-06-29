// sub_12F754 @ 0x12f754, size 18 bytes
int sub_12F754()
{
  int result; // r0

  if ( **(uint8_t **)off_12F768 != 3 )
    return 1;
  result = *(uint32_t *)(*(uint32_t *)off_10CA30 + 548);
  *(uint32_t *)off_10CA34 = 32;
  if ( result )
    return 1;
  *(uint32_t *)off_10CA38 = 32;
  return result;
}

