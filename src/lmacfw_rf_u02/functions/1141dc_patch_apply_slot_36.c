// rf_get_reg0xf_bit19 @ 0x1141dc, size 14 bytes
// Doc: rf_get_reg0xf_bit19 [patch]: Applies a firmware patch entry referenced via table at 0x182610
// rf_get_reg0xf_bit19 [patch]: Applies a firmware patch entry referenced via table at 0x182610
unsigned int rf_get_reg0xf_bit19()
{
  return ((unsigned int)mmio_read32(0xFu) >> 19) & 1;
}

