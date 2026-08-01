// rf_get_reg0x11_bits3_5 @ 0x11414c, size 14 bytes
unsigned int rf_get_reg0x11_bits3_5()
{
  return ((unsigned int)mmio_read32(0x11u) >> 3) & 7;
}

