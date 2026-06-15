// v23 annotated: rf_check_bit @ 0x10db30
// Original: 10db30_rf_check_bit.c
// Primary struct: bitmask_state (cluster 5, 7 funcs)
// Fields: prev_base=0x-c, mask0=0x0, mask1=0x4, mask2=0x8
//
// rf_check_bit @ 0x10db30, size 20 bytes
// Doc: rf_check_bit [rf]: Tests a single bit in MMIO register and returns 1/0
// rf_check_bit [rf]: Tests a single bit in MMIO register and returns 1/0
BOOL __fastcall rf_check_bit(char a1)
{
  return ((1 << a1) & *(_DWORD *)off_10DB44) != 0;
}

