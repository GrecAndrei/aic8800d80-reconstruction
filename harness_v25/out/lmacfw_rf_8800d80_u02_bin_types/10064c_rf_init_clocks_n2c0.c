// rf_init_clocks_n2c0 @ 0x10064c, size 46 bytes
// Doc: rf_init_clocks_n2c0 [mmio]: Initialize RF clock/regulator MMIO region
// rf_init_clocks_n2c0 [mmio]: Initialize RF clock/regulator MMIO region
uint32_t *rf_init_clocks_n2c0()
{
  uint32_t *result; // r0
  int *v1; // r2

  result = off_100680;
  v1 = (int *)off_100684;
  *(uint32_t *)off_10067C |= 0x10000u;
  *result = 0;
  *v1 = *v1 & 0x1FFFFFFE | 0x20000001;
  return result;
}

