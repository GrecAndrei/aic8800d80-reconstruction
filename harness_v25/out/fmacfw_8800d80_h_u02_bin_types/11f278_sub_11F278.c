// sub_11F278 @ 0x11f278, size 18 bytes
int  sub_11F278(int result)
{
  *(uint8_t *)(result + 52) = 1;
  *(uint8_t *)(result + 163) = 0;
  *(uint32_t *)(result + 184) = 0;
  return result;
}

