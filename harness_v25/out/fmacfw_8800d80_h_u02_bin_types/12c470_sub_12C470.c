// sub_12C470 @ 0x12c470, size 18 bytes
BOOL  sub_12C470(int a1, int a2)
{
  return *(uint32_t *)(a1 + 8) - *(uint32_t *)(a2 + 8) > (unsigned int)dword_12C484;
}

