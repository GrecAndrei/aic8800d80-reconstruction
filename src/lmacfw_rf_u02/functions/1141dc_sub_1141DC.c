// rf_get_reg0xf_bit19 @ 0x1141dc, size 14 bytes
unsigned int rf_get_reg0xf_bit19()
{
  return ((unsigned int)mmio_read32(0xFu) >> 19) & 1;
}

