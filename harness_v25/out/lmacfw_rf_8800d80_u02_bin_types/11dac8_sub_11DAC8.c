// sub_11DAC8 @ 0x11dac8, size 18 bytes
BOOL  sub_11DAC8(int a1, int a2)
{
  return *(uint32_t *)(a1 + 8) - *(uint32_t *)(a2 + 8) > (unsigned int)dword_11DADC;
}

