// v23 annotated: sub_107538 @ 0x107538
// Original: 107538_sub_107538.c
// Primary struct: <unclustered>
//
// sub_107538 @ 0x107538, size 212 bytes
int __fastcall sub_107538(int a1, int a2)
{
  _DWORD *v2; // r5
  unsigned int *v3; // r4
  _DWORD *v5; // r2
  int v6; // r1
  int v7; // r2
  int result; // r0

  v2 = off_10760C;
  v3 = (unsigned int *)off_107610;
  *(_DWORD *)off_10760C |= 4u;
  *v2 |= 8u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  sub_1073D8();
  *v2 &= ~1u;
  sub_100644(100);
  v5 = off_107614;
  v6 = dword_107618;
  *v3 |= 0x4000000u;
  v7 = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(_DWORD *)(a1 + 44) = v7;
  sub_12EB90(1, v6);
  sub_100644(5);
  result = sub_12EB90(1, dword_10761C);
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

