// v23 annotated: chip_info_is_fpga_or_emu @ 0x101a0c
// Original: 101a0c_chip_info_is_fpga_or_emu.c
// Primary struct: vif_set_state_req (cluster 3, 10 funcs)
// Fields: vif_idx=0x0, vif=0x0, flags=0x4, mac=0x8, mac_hi=0xa, bssid_lo=0xc, bssid_hi=0xe, op=0x18, state=0x1c
//
// chip_info_is_fpga_or_emu @ 0x101a0c, size 14 bytes
// Doc: chip_info_is_fpga_or_emu [util]: Returns 0 if chip type at 0x40341424 <= 1 else 1, distinguishing FPGA/emulator from ASIC
// chip_info_is_fpga_or_emu [util]: Returns 0 if chip type at 0x40341424 <= 1 else 1, distinguishing FPGA/emulator from ASIC
BOOL chip_info_is_fpga_or_emu()
{
  return *(_DWORD *)off_101A1C > 1u;
}

