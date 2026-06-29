// fwstruct annotate: 11e080_mmio_reg_bit_modify.c
// mmio_reg_bit_modify @ 0x11e080, size 44 bytes
// Doc: mmio_reg_bit_modify [mmio]: Reads/modifies MMIO register at 0x40320xxx by setting/clearing a bit field from index
// mmio_reg_bit_modify [mmio]: Reads/modifies MMIO register at 0x40320xxx by setting/clearing a bit field from index
unsigned int __fastcall mmio_reg_bit_modify(int a1)
{
  unsigned int *v1; // r1
  unsigned int result; // r0

  v1 = (unsigned int *)off_11E0B0;
  *(_DWORD *)off_11E0AC = (a1 << 10) & 0x400 | *(_DWORD *)off_11E0AC & 0xFFFFFBFF;
  result = (a1 << 19) & 0x80000 | *v1 & 0xFFF7FFFF;
  *v1 = result;
  return result;
}

