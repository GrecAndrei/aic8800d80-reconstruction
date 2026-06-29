// sub_1019B4 @ 0x1019b4, size 24 bytes
// Doc: sub_12019B4 [mmio]: Read MMIO status/control registers at 0x403410a8
// sub_12019B4 [mmio]: Read MMIO status/control registers at 0x403410a8
int  sub_1019B4(int result, int a2, int a3)
{
  if ( (*(uint32_t *)off_1019CC & 8) != 0 )
  {
    result = sub_117A7C(result, a2, a3, *(uint32_t *)off_1019CC << 28);
    *(uint32_t *)off_1019D0 = 8;
  }
  return result;
}

