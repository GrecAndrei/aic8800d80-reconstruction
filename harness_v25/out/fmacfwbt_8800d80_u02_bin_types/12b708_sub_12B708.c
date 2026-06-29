// sub_12B708 @ 0x12b708, size 40 bytes
int  sub_12B708(char a1, int a2)
{
  uint8_t *v3; // r4

  v3 = (uint8_t *)rf_bus_setup_n3a8(2052, a2, 2, 1);
  feature_guard_sdio(4, dword_12B734);
  *v3 = a1;
  return sub_12CBB4(v3);
}

