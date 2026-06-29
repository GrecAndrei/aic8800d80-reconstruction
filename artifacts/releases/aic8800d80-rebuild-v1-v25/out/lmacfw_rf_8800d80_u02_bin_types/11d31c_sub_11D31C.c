// sub_11D31C @ 0x11d31c, size 32 bytes
void *sub_11D31C()
{
  void *result; // r0
  uint32_t *v1; // r1
  uint32_t *v2; // r2

  result = off_11D33C;
  v1 = off_11D340;
  v2 = off_11D344;
  *(uint32_t *)off_11D33C &= ~0x80000000;
  *v1 &= ~0x80000000;
  *v2 &= ~0x80000000;
  return result;
}

