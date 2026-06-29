// sub_12B9E0 @ 0x12b9e0, size 32 bytes
void *sub_12B9E0()
{
  void *result; // r0
  uint32_t *v1; // r1
  uint32_t *v2; // r2

  result = off_12BA00;
  v1 = off_12BA04;
  v2 = off_12BA08;
  *(uint32_t *)off_12BA00 &= ~0x80000000;
  *v1 &= ~0x80000000;
  *v2 &= ~0x80000000;
  return result;
}

