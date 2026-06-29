// mmio_bit_modify @ 0x101a20, size 20 bytes
// Doc: mmio_bit_modify [mmio]: Read-modify-write MMIO register at 0x403410a0 clearing/setting bit 3 based on arg
// mmio_bit_modify [mmio]: Read-modify-write MMIO register at 0x403410a0 clearing/setting bit 3 based on arg
unsigned int  mmio_bit_modify(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(uint32_t *)off_101A34 & 0xFFFFFFF7;
  *(uint32_t *)off_101A34 = result;
  return result;
}

