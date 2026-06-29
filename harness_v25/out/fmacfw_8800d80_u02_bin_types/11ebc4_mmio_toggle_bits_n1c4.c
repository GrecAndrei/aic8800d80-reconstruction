// mmio_toggle_bits_n1c4 @ 0x11ebc4, size 44 bytes
// Doc: mmio_toggle_bits_n1c4 [mmio]: Toggle MMIO register bits via 0x403280xx control block
// mmio_toggle_bits_n1c4 [mmio]: Toggle MMIO register bits via 0x403280xx control block
int mmio_toggle_bits_n1c4()
{
  uint32_t *v0; // r2
  int result; // r0

  v0 = off_11EBF4;
  *(uint32_t *)off_11EBF0 = 0x10000;
  *v0 &= ~0x10000u;
  result = irq_nesting_or_d104(0x80000);
  if ( *(uint8_t *)off_11EBF8 )
    return sub_1222C0(result);
  return result;
}

