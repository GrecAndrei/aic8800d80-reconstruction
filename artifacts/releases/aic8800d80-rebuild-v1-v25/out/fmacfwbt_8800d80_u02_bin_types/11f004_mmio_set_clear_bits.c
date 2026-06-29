// mmio_set_clear_bits @ 0x11f004, size 44 bytes
// Doc: mmio_set_clear_bits [mmio]: Set bit 0x10000 in reg, then clear same bit in another reg
// mmio_set_clear_bits [mmio]: Set bit 0x10000 in reg, then clear same bit in another reg
int mmio_set_clear_bits()
{
  uint32_t *v0; // r2
  int result; // r0

  v0 = off_11F034;
  *(uint32_t *)off_11F030 = 0x10000;
  *v0 &= ~0x10000u;
  result = irq_nesting_or(0x80000);
  if ( *(uint8_t *)off_11F038 )
    return sub_1224F4(result);
  return result;
}

