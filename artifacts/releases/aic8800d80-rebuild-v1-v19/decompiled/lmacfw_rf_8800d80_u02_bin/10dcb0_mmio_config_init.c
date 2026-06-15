// mmio_config_init @ 0x10dcb0, size 48 bytes
// Doc: mmio_config_init [mmio]: Initialize MMIO region with 0x3c00/0x2000 and OR-mask 0xf
// mmio_config_init [mmio]: Initialize MMIO region with 0x3c00/0x2000 and OR-mask 0xf
int mmio_config_init()
{
  int result; // r0
  _DWORD *v1; // r3

  result = rf_reg_write_cb(dword_10DCE0, 0x2000, 15360);
  v1 = off_10DCE4;
  *((_DWORD *)off_10DCE4 + 2) |= 0xFu;
  v1[2] |= 0x10000000u;
  v1[3] &= 0xFFFFF7FE;
  return result;
}

