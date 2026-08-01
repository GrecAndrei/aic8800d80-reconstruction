// rf_get_reg1_bits13_16 @ 0x113b4c, size 14 bytes
// Doc: rf_get_reg1_bits13_16 [util]: Calls helper and returns a 4-bit field extracted at bit 13 (ubfx r0,r0,0xd,4)
// rf_get_reg1_bits13_16 [util]: Calls helper and returns a 4-bit field extracted at bit 13 (ubfx r0,r0,0xd,4)
unsigned int rf_get_reg1_bits13_16()
{
  return ((unsigned int)mmio_read32(1u) >> 13) & 0xF;
}

