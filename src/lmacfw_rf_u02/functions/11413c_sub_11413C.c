// rf_get_reg0x11_bits0_2 @ 0x11413c, size 14 bytes
int rf_get_reg0x11_bits0_2()
{
  return mmio_read32(0x11u) & 7;
}

