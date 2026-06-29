// fwstruct annotate: 118e20_rf_gpio_clear_bit_n_e20.c
// rf_gpio_clear_bit_n_e20 @ 0x118e20, size 40 bytes
// Doc: rf_gpio_clear_bit_n_e20 [mmio]: Clear bit in GPIO/peripheral MMIO register 0x4032004c
// rf_gpio_clear_bit_n_e20 [mmio]: Clear bit in GPIO/peripheral MMIO register 0x4032004c
unsigned int rf_gpio_clear_bit_n_e20()
{
  unsigned int result; // r0
  _DWORD *v1; // r2

  *(_DWORD *)off_118E48 &= ~2u;
  result = sub_1174B8(0);
  v1 = off_118E50;
  *(_DWORD *)off_118E4C = dword_118E54;
  *v1 &= 0xFFFBFFFE;
  return result;
}

