// fwstruct annotate: 107678_sub_107678.c
// sub_107678 @ 0x107678, size 212 bytes
int __fastcall sub_107678(int a1, int a2)
{
  _DWORD *v2; // r5
  unsigned int *v3; // r4
  _DWORD *v5; // r2
  int v6; // r1
  int v7; // r2
  int result; // r0

  v2 = off_10774C;
  v3 = (unsigned int *)off_107750;
  *(_DWORD *)off_10774C |= 4u;
  *v2 |= 8u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  crypto_engine_clear_sram_regs();
  *v2 &= ~1u;
  delay_us_0644(100);
  v5 = off_107754;
  v6 = dword_107758;
  *v3 |= 0x4000000u;
  v7 = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(_DWORD *)(a1 + 44) = v7;
  feature_guard_check(1, v6);
  delay_us_0644(5);
  result = feature_guard_check(1, dword_10775C);
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

