// fwstruct annotate: 103ac4_crypto_hw_clk_toggle.c
// crypto_hw_clk_toggle @ 0x103ac4, size 50 bytes
// Doc: crypto_hw_clk_toggle [mmio]: Toggle crypto HW clock via bit clear on 0x40344088
// crypto_hw_clk_toggle [mmio]: Toggle crypto HW clock via bit clear on 0x40344088
int crypto_hw_clk_toggle()
{
  _DWORD *v0; // r4
  int result; // r0

  v0 = off_103AF8;
  *(_DWORD *)off_103AF8 &= ~0x400000u;
  *v0 &= ~0x200000u;
  delay_us(2);
  *v0 |= 0x200000u;
  result = delay_us(2);
  *v0 |= 0x400000u;
  return result;
}

