// v23 annotated: rf_chip_ready_check @ 0x101a3c
// Original: 101a3c_rf_chip_ready_check.c
// Primary struct: mmio_clock_gate (cluster 3, 10 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// rf_chip_ready_check @ 0x101a3c, size 14 bytes
// Doc: rf_chip_ready_check [rf]: Check RF chip ready flag at 0x40341424, return 1 if > 1
// rf_chip_ready_check [rf]: Check RF chip ready flag at 0x40341424, return 1 if > 1
BOOL rf_chip_ready_check()
{
  return *(_DWORD *)off_101A4C > 1u;
}

