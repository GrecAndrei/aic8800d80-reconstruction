// v23 annotated: sub_1073DC @ 0x1073dc
// Original: 1073dc_sub_1073DC.c
// Primary struct: <unclustered>
//
// sub_1073DC @ 0x1073dc, size 222 bytes
int __fastcall sub_1073DC(int a1, int a2)
{
  unsigned int *v2; // r5
  unsigned int *v3; // r4
  _DWORD *v5; // r2
  int v6; // r3
  int result; // r0

  v2 = (unsigned int *)off_1074BC;
  v3 = (unsigned int *)off_1074C0;
  *(_DWORD *)off_1074BC = *(_DWORD *)off_1074BC & 0xFFFFFF8F | 0x50;
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  sub_107370();
  *v2 &= ~1u;
  delay_us(140);
  v5 = off_1074C4;
  *v3 |= 0x4000000u;
  v6 = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(_DWORD *)(a1 + 44) = v6;
  delay_us(5);
  feature_guard_sdio(1, dword_1074C8);
  result = feature_guard_sdio(1, dword_1074CC);
  *v3 &= ~0x1000000u;
  *v3 &= ~0x2000000u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x800000u;
  *v3 &= ~0x200000u;
  *v3 &= ~0x100000u;
  *v2 = *v2 & 0xFFFFFF8F | 0x40;
  return result;
}

