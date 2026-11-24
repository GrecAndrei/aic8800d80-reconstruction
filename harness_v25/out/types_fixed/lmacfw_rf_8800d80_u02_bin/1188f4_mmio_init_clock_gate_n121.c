// mmio_init_clock_gate_n121 @ 0x1188f4, size 14 bytes
// Doc: mmio_init_clock_gate_n121 [mmio]: Writes 0x30 to MMIO 0x40320038 to configure clock gate/control
// mmio_init_clock_gate_n121 [mmio]: Writes 0x30 to MMIO 0x40320038 to configure clock gate/control
int mmio_init_clock_gate_n121()
{
  *(_DWORD *)off_118904 = 48;
  return sub_11E1E4(0);
}

