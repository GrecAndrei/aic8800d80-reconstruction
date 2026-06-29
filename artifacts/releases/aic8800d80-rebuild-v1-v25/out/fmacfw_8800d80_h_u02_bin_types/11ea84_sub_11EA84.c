// sub_11EA84 @ 0x11ea84, size 44 bytes
int sub_11EA84()
{
  uint32_t *v0; // r2
  int result; // r0

  v0 = off_11EAB4;
  *(uint32_t *)off_11EAB0 = 0x10000;
  *v0 &= ~0x10000u;
  result = sub_12CFC4(0x80000);
  if ( *(uint8_t *)off_11EAB8 )
    return sub_122180(result);
  return result;
}

