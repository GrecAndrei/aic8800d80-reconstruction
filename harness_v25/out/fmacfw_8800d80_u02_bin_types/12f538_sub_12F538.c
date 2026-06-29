// sub_12F538 @ 0x12f538, size 18 bytes
int sub_12F538()
{
  int result; // r0

  if ( **(uint8_t **)off_12F54C != 3 )
    return 1;
  result = *(uint32_t *)(*(uint32_t *)off_10CBD8 + 612);
  *(uint32_t *)off_10CBDC = 32;
  if ( result )
    return 1;
  *(uint32_t *)off_10CBE0 = 32;
  return result;
}

