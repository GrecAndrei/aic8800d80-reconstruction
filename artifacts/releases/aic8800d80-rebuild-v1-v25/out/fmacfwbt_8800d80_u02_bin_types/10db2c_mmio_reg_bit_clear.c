// mmio_reg_bit_clear @ 0x10db2c, size 18 bytes
// Doc: mmio_reg_bit_clear [mmio]: Clear a single bit in MMIO register at 0x40505000
// mmio_reg_bit_clear [mmio]: Clear a single bit in MMIO register at 0x40505000
int  mmio_reg_bit_clear(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((uint32_t *)off_10DB40 + 2) &= ~result;
  return result;
}

