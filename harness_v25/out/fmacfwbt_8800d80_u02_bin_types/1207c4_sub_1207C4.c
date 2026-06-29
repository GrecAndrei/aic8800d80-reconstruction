// sub_1207C4 @ 0x1207c4, size 26 bytes
int  sub_1207C4(int a1)
{
  uint32_t *v2; // r0

  v2 = (uint32_t *)rf_bus_setup_n3a8(143, 0, 255, 4);
  *v2 = a1;
  return sub_12CBB4(v2);
}

