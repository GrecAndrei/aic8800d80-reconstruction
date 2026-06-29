// fwstruct annotate: 10dce8_rf_pll_ldo_init.c
// rf_pll_ldo_init @ 0x10dce8, size 48 bytes
// Doc: rf_pll_ldo_init [rf]: Initialize PLL/LDO with 0x3c00/0x1000 timing and trim 0xf
// rf_pll_ldo_init [rf]: Initialize PLL/LDO with 0x3c00/0x1000 timing and trim 0xf
int rf_pll_ldo_init()
{
  int result; // r0
  _DWORD *v1; // r3

  result = rf_reg_write_cb(dword_10DD18, 4096, 15360);
  v1 = off_10DD1C;
  *((_DWORD *)off_10DD1C + 2) |= 0xFu;
  v1[2] |= 0x10000000u;
  v1[3] &= 0xFFFFF7FE;
  return result;
}

