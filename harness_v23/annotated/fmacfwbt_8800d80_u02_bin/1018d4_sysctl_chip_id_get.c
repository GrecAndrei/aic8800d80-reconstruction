// v23 annotated: sysctl_chip_id_get @ 0x1018d4
// Original: 1018d4_sysctl_chip_id_get.c
// Primary struct: vif_set_state_req (cluster 3, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// sysctl_chip_id_get @ 0x1018d4, size 10 bytes
// Doc: sysctl_chip_id_get [mmio]: Returns bit 30 of chip ID register at 0x40330000
// sysctl_chip_id_get [mmio]: Returns bit 30 of chip ID register at 0x40330000
int sysctl_chip_id_get()
{
  return (*(_DWORD *)off_1018E0 >> 30) & 1;
}

