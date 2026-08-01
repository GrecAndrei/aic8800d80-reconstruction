// rf_get_reg0x11_bits6_8 @ 0x11415c, size 14 bytes
unsigned int rf_get_reg0x11_bits6_8()
{
  return ((unsigned int)mmio_read32(0x11u) >> 6) & 7;
}

