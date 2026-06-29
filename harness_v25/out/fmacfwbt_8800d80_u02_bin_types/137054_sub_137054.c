// sub_137054 @ 0x137054, size 48 bytes
int  sub_137054(int a1, int a2, int a3, __int16 a4)
{
  uint8_t *v5; // r4

  v5 = (uint8_t *)rf_bus_setup_n3a8(4104, a4, 4, 2u);
  feature_guard_sdio(8, dword_137084);
  *v5 = 1;
  v5[1] = *(uint8_t *)(a2 + 2);
  sub_12CBB4((int)v5);
  return 0;
}

