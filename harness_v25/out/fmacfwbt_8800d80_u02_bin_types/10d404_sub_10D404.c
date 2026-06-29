// sub_10D404 @ 0x10d404, size 36 bytes
int sub_10D404()
{
  int v0; // r3
  int result; // r0

  v0 = *((uint32_t *)off_10D428 + 3);
  if ( (v0 & 0x8000) != 0 )
    *((uint32_t *)off_10D428 + 2) = 0x800000;
  if ( (v0 & 0x400) != 0 )
  {
    *((uint32_t *)off_10D428 + 2) = 0x40000;
    return irq_nesting_or(0x20000000);
  }
  return result;
}

