// mmio_reg_poll_ready @ 0x11eaf8, size 52 bytes
// Doc: mmio_reg_poll_ready [mmio]: Polls MMIO register until expected value appears
// mmio_reg_poll_ready [mmio]: Polls MMIO register until expected value appears
unsigned int mmio_reg_poll_ready()
{
  int v0; // r3
  unsigned int result; // r0
  unsigned int v2; // r3
  int v3; // r3

  v0 = *((uint32_t *)off_11EB2C + 2);
  if ( v0 == *(uint32_t *)off_11EB30 )
    return 0;
  result = v0 & 0x7FFFFFFF;
  if ( *((uint32_t *)off_11EB2C + 1) - (v0 & 0x7FFFFFFFu) <= 0x9F )
  {
    v2 = v0 & 0x80000000;
    if ( result > *(uint32_t *)off_11EB2C )
      v2 += 0x80000000;
    v3 = v2 | *(uint32_t *)off_11EB2C;
    *((uint32_t *)off_11EB2C + 2) = v3;
    return v3 & 0x7FFFFFFF;
  }
  return result;
}

