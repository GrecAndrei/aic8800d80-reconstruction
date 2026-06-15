// mmio_clear_bit @ 0x10dad8, size 18 bytes
// Doc: mmio_clear_bit [mmio]: Clear a single bit in MMIO register at 0x4010b008
// mmio_clear_bit [mmio]: Clear a single bit in MMIO register at 0x4010b008
int __fastcall mmio_clear_bit(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((_DWORD *)off_10DAEC + 2) &= ~result;
  return result;
}

