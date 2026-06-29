// sub_11AB00 @ 0x11ab00, size 10 bytes
unsigned int  sub_11AB00(int a1, int a2)
{
  return (unsigned int)(*(uint32_t *)(a1 + 12) - *(uint32_t *)(a2 + 12)) >> 31;
}

