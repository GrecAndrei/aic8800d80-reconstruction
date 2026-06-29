// chip_info_is_fpga_or_emu @ 0x101a0c, size 14 bytes
// Doc: chip_info_is_fpga_or_emu [util]: Returns 0 if chip type at 0x40341424 <= 1 else 1, distinguishing FPGA/emulator from ASIC
// chip_info_is_fpga_or_emu [util]: Returns 0 if chip type at 0x40341424 <= 1 else 1, distinguishing FPGA/emulator from ASIC
BOOL chip_info_is_fpga_or_emu()
{
  return *(uint32_t *)off_101A1C > 1u;
}

