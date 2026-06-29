// crypto_hw_clk_toggle_3c6c @ 0x103c6c, size 50 bytes
// Doc: crypto_hw_clk_toggle_3c6c [mmio]: Toggle crypto hardware clock bits in MMIO register
// crypto_hw_clk_toggle_3c6c [mmio]: Toggle crypto hardware clock bits in MMIO register
int crypto_hw_clk_toggle_3c6c()
{
  uint32_t *v0; // r4
  int result; // r0

  v0 = off_103CA0;
  *(uint32_t *)off_103CA0 &= ~0x400000u;
  *v0 &= ~0x200000u;
  delay_us_0644(2);
  *v0 |= 0x200000u;
  result = delay_us_0644(2);
  *v0 |= 0x400000u;
  return result;
}

