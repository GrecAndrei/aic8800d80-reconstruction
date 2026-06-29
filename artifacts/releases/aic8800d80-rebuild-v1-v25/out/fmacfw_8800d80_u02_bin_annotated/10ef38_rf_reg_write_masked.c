// fwstruct annotate: 10ef38_rf_reg_write_masked.c
// rf_reg_write_masked @ 0x10ef38, size 18 bytes
// Doc: rf_reg_write_masked [rf]: Masked RF register write utility (stub/leaf)
// rf_reg_write_masked [rf]: Masked RF register write utility (stub/leaf)
int __fastcall rf_reg_write_masked(int a1)
{
  return sub_10EE2C(dword_10EF4C, (a1 << 11) & 0xF800, 63488, 1);
}

