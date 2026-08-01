// rf_get_reg0xf_bit20 @ 0x1141f8, size 14 bytes
unsigned int rf_get_reg0xf_bit20()
{
  return ((unsigned int)mmio_read32(0xFu) >> 20) & 1;
}

