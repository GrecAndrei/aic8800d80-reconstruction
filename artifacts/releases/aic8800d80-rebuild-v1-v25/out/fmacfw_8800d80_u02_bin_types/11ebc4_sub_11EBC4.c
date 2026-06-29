// sub_11EBC4 @ 0x11ebc4, size 44 bytes
int sub_11EBC4()
{
  uint32_t *v0; // r2
  int result; // r0

  v0 = off_11EBF4;
  *(uint32_t *)off_11EBF0 = 0x10000;
  *v0 &= ~0x10000u;
  result = sub_12D104(0x80000);
  if ( *(uint8_t *)off_11EBF8 )
    return sub_1222C0(result);
  return result;
}

