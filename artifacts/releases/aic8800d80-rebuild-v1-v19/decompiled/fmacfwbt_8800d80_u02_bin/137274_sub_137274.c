// sub_137274 @ 0x137274, size 40 bytes
int sub_137274()
{
  int v0; // r0
  int value; // r0

  v0 = rf_bus_setup_n3a8(2051, 2, 4, 1u);
  sub_12CBB4(v0);
  value = msg_get_value(4u);
  feature_guard_sdio(8, dword_13729C, value);
  return 0;
}

