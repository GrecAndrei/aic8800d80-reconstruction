// sub_10ED30 @ 0x10ed30, size 46 bytes
int  sub_10ED30(int a1)
{
  rf_reg_write_guard(dword_10ED64, 196608, dword_10ED60, 1);
  sub_10EC30(dword_10ED68, a1 << 15, 1);
  return rf_reg_write_guard(1879048192, 1, 1, 1);
}

