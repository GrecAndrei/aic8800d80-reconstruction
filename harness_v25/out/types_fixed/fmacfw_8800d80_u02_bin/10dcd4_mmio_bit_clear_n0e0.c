// mmio_bit_clear_n0e0 @ 0x10dcd4, size 18 bytes
// Doc: mmio_bit_clear_n0e0 [mmio]: Clear a single bit in MMIO register at 0x40505000+8 indexed by r0
// mmio_bit_clear_n0e0 [mmio]: Clear a single bit in MMIO register at 0x40505000+8 indexed by r0
int __fastcall mmio_bit_clear_n0e0(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((_DWORD *)off_10DCE8 + 2) &= ~result;
  return result;
}

