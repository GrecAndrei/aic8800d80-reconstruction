// rf_xo_pll_init @ 0x119698, size 20 bytes
// Doc: rf_xo_pll_init [rf]: Initializes RF XO/PLL subsystem (cmd 0x76)
// rf_xo_pll_init [rf]: Initializes RF XO/PLL subsystem (cmd 0x76)
int __fastcall rf_xo_pll_init(int a1, int a2, int a3, int a4)
{
  int v4; // r0

  v4 = rf_setup_dispatch(118, a4, a3, 12);
  sub_11DE50(v4);
  return 0;
}

