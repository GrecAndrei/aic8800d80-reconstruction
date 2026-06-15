// v23 annotated: sub_1074D0 @ 0x1074d0
// Original: 1074d0_sub_1074D0.c
// Primary struct: <unclustered>
//
// sub_1074D0 @ 0x1074d0, size 212 bytes
int __fastcall sub_1074D0(int a1, int a2)
{
  _DWORD *v2; // r5
  unsigned int *v3; // r4
  _DWORD *v5; // r2
  int v6; // r1
  int v7; // r2
  int result; // r0

  v2 = off_1075A4;
  v3 = (unsigned int *)off_1075A8;
  *(_DWORD *)off_1075A4 |= 4u;
  *v2 |= 8u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  sub_107370();
  *v2 &= ~1u;
  sub_100644(100);
  v5 = off_1075AC;
  v6 = dword_1075B0;
  *v3 |= 0x4000000u;
  v7 = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(_DWORD *)(a1 + 44) = v7;
  sub_12EEF8(1, v6);
  sub_100644(5);
  result = sub_12EEF8(1, dword_1075B4);
  *v3 &= ~0x1000000u;
  *v3 &= ~0x2000000u;
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x800000u;
  *v3 &= ~0x200000u;
  *v3 &= ~0x100000u;
  return result;
}

