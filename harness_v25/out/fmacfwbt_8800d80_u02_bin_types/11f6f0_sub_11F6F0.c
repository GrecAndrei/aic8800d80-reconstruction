// sub_11F6F0 @ 0x11f6f0, size 18 bytes
int  sub_11F6F0(int result)
{
  *(uint8_t *)(result + 52) = 1;
  *(uint8_t *)(result + 163) = 0;
  *(uint32_t *)(result + 184) = 0;
  return result;
}

