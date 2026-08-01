// rf_get_reg1_bit9 @ 0x113b30, size 14 bytes
unsigned int rf_get_reg1_bit9()
{
  return ((unsigned int)mmio_read32(1u) >> 9) & 1;
}

