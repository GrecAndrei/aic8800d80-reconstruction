// mmio_pair_read_n1800 @ 0x101800, size 14 bytes
// Doc: mmio_pair_read_n1800 [mmio]: Reads paired 32-bit MMIO regs from 0x40330000/0x4033003c into r0/r1
// mmio_pair_read_n1800 [mmio]: Reads paired 32-bit MMIO regs from 0x40330000/0x4033003c into r0/r1
_DWORD *__fastcall mmio_pair_read_n1800(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r3

  v2 = off_101814;
  *result = *(_DWORD *)off_101810;
  *a2 = *v2;
  return result;
}

