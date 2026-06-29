// fwstruct annotate: 106dbc_sub_106DBC.c
// sub_106DBC @ 0x106dbc, size 298 bytes
_DWORD *sub_106DBC()
{
  _DWORD *result; // r0
  unsigned int *v1; // r2
  _DWORD *v2; // r3
  unsigned int *v3; // r4
  _DWORD *v4; // r5
  _DWORD *v5; // r6
  _DWORD *v6; // r1
  _DWORD *v7; // r2

  result = off_106EE8;
  v1 = (unsigned int *)off_106EEC;
  v2 = off_106EF0;
  *(_DWORD *)off_106EE8 &= ~0x80000000;
  v3 = (unsigned int *)off_106EF4;
  v4 = off_106EF8;
  v5 = off_106EFC;
  *v1 = *v1 & 0xFFFF0FFF | 0xA000;
  *v2 &= 0xCFFFFFFF;
  *v2 &= ~0x40000000u;
  *v3 = *v3 & 0xF8FFFFFF | 0x5000000;
  *v3 = *v3 & 0xFFFFFF8F | 0x50;
  *v1 &= ~0x80000u;
  *v1 &= ~0x40000u;
  *v1 &= ~0x20000u;
  *v1 &= ~0x10000u;
  v6 = off_106F00;
  *v4 &= ~0x10000000u;
  *v2 |= 0x400000u;
  *v2 |= 0x800000u;
  *v2 |= 0x200000u;
  *v2 |= 0x100000u;
  *v2 &= ~0x40u;
  *v5 &= ~0x1000000u;
  *v6 &= ~0x2000000u;
  *(unsigned int *)((char *)v3 + 0xFFFFFF5C) &= ~0x20000000u;
  v7 = off_106F04;
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

