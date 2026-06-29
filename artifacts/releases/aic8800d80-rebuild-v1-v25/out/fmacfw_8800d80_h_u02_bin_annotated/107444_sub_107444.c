// fwstruct annotate: 107444_sub_107444.c
// sub_107444 @ 0x107444, size 222 bytes
int __fastcall sub_107444(int a1, int a2)
{
  unsigned int *v2; // r5
  unsigned int *v3; // r4
  _DWORD *v5; // r2
  int v6; // r3
  int result; // r0

  v2 = (unsigned int *)off_107524;
  v3 = (unsigned int *)off_107528;
  *(_DWORD *)off_107524 = *(_DWORD *)off_107524 & 0xFFFFFF8F | 0x50;
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  sub_1073D8();
  *v2 &= ~1u;
  sub_100644(140);
  v5 = off_10752C;
  *v3 |= 0x4000000u;
  v6 = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(_DWORD *)(a1 + 44) = v6;
  sub_100644(5);
  sub_12EB90(1, dword_107530);
  result = sub_12EB90(1, dword_107534);
  *v3 &= ~0x1000000u;
  *v3 &= ~0x2000000u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x800000u;
  *v3 &= ~0x200000u;
  *v3 &= ~0x100000u;
  *v2 = *v2 & 0xFFFFFF8F | 0x40;
  return result;
}

