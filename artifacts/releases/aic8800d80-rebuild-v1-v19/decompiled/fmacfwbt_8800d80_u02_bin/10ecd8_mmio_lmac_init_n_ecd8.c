// mmio_lmac_init_n_ecd8 @ 0x10ecd8, size 66 bytes
// Doc: mmio_lmac_init_n_ecd8 [mmio]: Initialize LMAC MMIO control registers and doorbell
// mmio_lmac_init_n_ecd8 [mmio]: Initialize LMAC MMIO control registers and doorbell
int __fastcall mmio_lmac_init_n_ecd8(int a1, int a2, int a3)
{
  sub_12ECB0(dword_10ED1C, a1, a3);
  rf_reg_write_guard(dword_10ED24, 196608, dword_10ED20, 1);
  rf_reg_write_guard(1879048192, 1, 1, 1);
  sub_10EC30(dword_10ED28, a1, 1);
  return rf_reg_write_guard(dword_10ED2C, 2, 2, 1);
}

