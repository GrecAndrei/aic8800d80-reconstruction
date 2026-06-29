// sub_13B7BC @ 0x13b7bc, size 14 bytes
unsigned int  sub_13B7BC(int a1)
{
  return ((unsigned int)(a1 - (*((uint32_t *)off_13B7CC + 4) >> 10)) >> 15) & 1;
}

