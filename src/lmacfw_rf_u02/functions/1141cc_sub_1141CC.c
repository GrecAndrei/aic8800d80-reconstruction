// rf_get_reg0xf_bit18 @ 0x1141cc, size 14 bytes
unsigned int rf_get_reg0xf_bit18()
{
  return ((unsigned int)mmio_read32(0xFu) >> 18) & 1;
}

