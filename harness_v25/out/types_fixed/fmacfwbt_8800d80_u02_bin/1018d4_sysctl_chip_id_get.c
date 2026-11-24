// sysctl_chip_id_get @ 0x1018d4, size 10 bytes
// Doc: sysctl_chip_id_get [mmio]: Returns bit 30 of chip ID register at 0x40330000
// sysctl_chip_id_get [mmio]: Returns bit 30 of chip ID register at 0x40330000
int sysctl_chip_id_get()
{
  return (*(_DWORD *)off_1018E0 >> 30) & 1;
}

