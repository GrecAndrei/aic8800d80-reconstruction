// fwstruct annotate: 13baa8_rf_bus_reset_nac_baa8.c
// rf_bus_reset_nac_baa8 @ 0x13baa8, size 22 bytes
// Doc: rf_bus_reset_nac_baa8 [rf]: Reset RF bus control registers (0x40200900 region)
// rf_bus_reset_nac_baa8 [rf]: Reset RF bus control registers (0x40200900 region)
int __fastcall rf_bus_reset_nac_baa8(__int16 a1)
{
  return rf_level_apply_80c(8194, (unsigned __int16)(a1 << 8) | 8, 0x1F4000u);
}

