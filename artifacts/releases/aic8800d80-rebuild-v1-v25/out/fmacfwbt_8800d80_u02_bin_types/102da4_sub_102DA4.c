// sub_102DA4 @ 0x102da4, size 48 bytes
// Doc: phy_rf_init [rf]: Initialize PHY/RF subsystem parameters
// phy_rf_init [rf]: Initialize PHY/RF subsystem parameters
int sub_102DA4()
{
  uint64_t v0; // kr00_8
  int v1; // r4

  v0 = *(QWORD *)((char *)phy_rf_init_2dd4 + 4);
  v1 = *(uint32_t *)phy_rf_init_2dd4;
  sub_102D10(0, 32, 0x10u, SHIDWORD(v0));
  sub_102D10(0, 48, 0x10u, v0);
  return sub_102D10(0, 64, 0x10u, v1);
}

