// sub_103C6C @ 0x103c6c, size 50 bytes
int sub_103C6C()
{
  uint32_t *v0; // r4
  int result; // r0

  v0 = off_103CA0;
  *(uint32_t *)off_103CA0 &= ~0x400000u;
  *v0 &= ~0x200000u;
  sub_100644(2);
  *v0 |= 0x200000u;
  result = sub_100644(2);
  *v0 |= 0x400000u;
  return result;
}

