// sub_10064C @ 0x10064c, size 46 bytes
uint32_t *sub_10064C()
{
  uint32_t *result; // r0
  int *v1; // r2

  result = off_100680;
  v1 = (int *)off_100684;
  *(uint32_t *)off_10067C |= 0x10000u;
  *result = 0;
  *v1 = *v1 & 0x1FFFFFFE | 0x20000001;
  return result;
}

