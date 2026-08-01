// rf_set_reg0xf_bit19 @ 0x1141ec, size 10 bytes
int rf_set_reg0xf_bit19()
{
  return mmio_write32(0xFu, 0x80000);
}

