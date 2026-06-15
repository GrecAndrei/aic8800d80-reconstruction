// v23 annotated: mmio_regs_poll_1200ee8 @ 0x100ee8
// Original: 100ee8_mmio_regs_poll_1200ee8.c
// Primary struct: <unclustered>
//
// mmio_regs_poll_1200ee8 @ 0x100ee8, size 172 bytes
// Doc: mmio_regs_poll_1200ee8 [mmio]: Poll MMIO registers and dispatch on byte flag
// mmio_regs_poll_1200ee8 [mmio]: Poll MMIO registers and dispatch on byte flag
_DWORD *mmio_regs_poll_1200ee8()
{
  unsigned int *v0; // r3
  _DWORD *v1; // r1
  unsigned int v2; // r4
  _DWORD *result; // r0
  _DWORD *v4; // r3

  v0 = (unsigned int *)off_100F98;
  v1 = off_100F9C;
  v2 = *(_DWORD *)off_100F98;
  result = off_100FA0;
  *(_DWORD *)off_100F9C = (*((unsigned __int8 *)off_100F94 + 1) << 10) & 0x1FC00 | *(_DWORD *)off_100F9C & 0xFFFE03FF;
  *v0 = *v0 & 0xFFFFFFE7 | 8;
  *v0 |= 7u;
  *v1 &= ~0x80000u;
  *v1 &= ~0x40000u;
  *v0 = *v0 & 0xFFFFFC1F | 0x80;
  *result |= 2u;
  *result &= ~1u;
  if ( ((v2 >> 5) & 0x1F) != 4 )
  {
    v4 = off_100FA4;
    *(_DWORD *)off_100FA4 |= 0x80u;
    *v4 &= ~0x40u;
    *v4 |= 0x40u;
    *v4 &= ~0x80u;
  }
  return result;
}

