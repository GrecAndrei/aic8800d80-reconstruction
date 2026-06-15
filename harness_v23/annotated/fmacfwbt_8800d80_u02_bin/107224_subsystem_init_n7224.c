// v23 annotated: subsystem_init_n7224 @ 0x107224
// Original: 107224_subsystem_init_n7224.c
// Primary struct: <unclustered>
//
// subsystem_init_n7224 @ 0x107224, size 298 bytes
// Doc: subsystem_init_n7224 [mmio]: Initialize peripheral subsystem by clearing reset bits
// subsystem_init_n7224 [mmio]: Initialize peripheral subsystem by clearing reset bits
_DWORD *subsystem_init_n7224()
{
  _DWORD *result; // r0
  unsigned int *v1; // r2
  _DWORD *v2; // r3
  unsigned int *v3; // r4
  _DWORD *v4; // r5
  _DWORD *v5; // r6
  _DWORD *v6; // r1
  _DWORD *v7; // r2

  result = off_107350;
  v1 = (unsigned int *)off_107354;
  v2 = off_107358;
  *(_DWORD *)off_107350 &= ~0x80000000;
  v3 = (unsigned int *)off_10735C;
  v4 = off_107360;
  v5 = off_107364;
  *v1 = *v1 & 0xFFFF0FFF | 0xA000;
  *v2 &= 0xCFFFFFFF;
  *v2 &= ~0x40000000u;
  *v3 = *v3 & 0xF8FFFFFF | 0x5000000;
  *v3 = *v3 & 0xFFFFFF8F | 0x50;
  *v1 &= ~0x80000u;
  *v1 &= ~0x40000u;
  *v1 &= ~0x20000u;
  *v1 &= ~0x10000u;
  v6 = off_107368;
  *v4 &= ~0x10000000u;
  *v2 |= 0x400000u;
  *v2 |= 0x800000u;
  *v2 |= 0x200000u;
  *v2 |= 0x100000u;
  *v2 &= ~0x40u;
  *v5 &= ~0x1000000u;
  *v6 &= ~0x2000000u;
  *(unsigned int *)((char *)v3 + 0xFFFFFF5C) &= ~0x20000000u;
  v7 = off_10736C;
  v4[128] &= ~0x200u;
  v6[49] &= 0xC0FFFFFF;
  v6[49] &= 0xFFC0FFFF;
  v6[49] &= 0xFFFFC0FF;
  v6[49] &= 0xFFFFFFC0;
  *v7 &= 0xC0FFFFFF;
  *v7 &= 0xFFC0FFFF;
  *v7 &= 0xFFFFC0FF;
  *v7 &= 0xFFFFFFC0;
  *v2 &= 0xFFFFFFC0;
  *result |= 0x4000u;
  return result;
}

