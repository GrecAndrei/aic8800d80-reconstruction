// sub_124F48 @ 0x124f48, size 10 bytes
unsigned int  sub_124F48(int a1, int a2)
{
  return (unsigned int)(*(uint32_t *)(a1 + 12) - *(uint32_t *)(a2 + 12)) >> 31;
}

