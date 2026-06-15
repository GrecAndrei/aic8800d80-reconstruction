// v23 annotated: sub_10ED90 @ 0x10ed90
// Original: 10ed90_sub_10ED90.c
// Primary struct: <unclustered>
//
// sub_10ED90 @ 0x10ed90, size 18 bytes
int __fastcall sub_10ED90(int a1)
{
  return rf_reg_write_guard(dword_10EDA4, (a1 << 11) & 0xF800, 63488, 1);
}

