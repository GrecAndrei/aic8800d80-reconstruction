// mmio_bit_toggle_0189c @ 0x10189c, size 20 bytes
// Doc: mmio_bit_toggle_0189c [mmio]: Toggle a single bit in MMIO control register
// mmio_bit_toggle_0189c [mmio]: Toggle a single bit in MMIO control register
unsigned int __fastcall mmio_bit_toggle_0189c(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(_DWORD *)off_1018B0 & 0xFFFFFFF7;
  *(_DWORD *)off_1018B0 = result;
  return result;
}

