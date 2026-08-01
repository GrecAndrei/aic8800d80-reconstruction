// wifi_set_channel @ 0x1028b8, size 66 bytes
void __noreturn wifi_set_channel()
{
  rf_band_config();
  rf_ctrl_set(0, 0x96Cu);
  pmu_write_ctrl();
}

