// sub_12C5B0 @ 0x12c5b0, size 18 bytes
BOOL  sub_12C5B0(int a1, int a2)
{
  return *(uint32_t *)(a1 + 8) - *(uint32_t *)(a2 + 8) > (unsigned int)dword_12C5C4;
}

