// sub_124BE4 @ 0x124be4, size 10 bytes
unsigned int  sub_124BE4(int a1, int a2)
{
  return (unsigned int)(*(uint32_t *)(a1 + 12) - *(uint32_t *)(a2 + 12)) >> 31;
}

