// fwstruct annotate: 106f74_sub_106F74.c
// sub_106F74 @ 0x106f74, size 222 bytes
int __fastcall sub_106F74(int a1, int a2)
{
  unsigned int *v2; // r5
  unsigned int *v3; // r4
  _DWORD *v5; // r2
  int v6; // r3
  int v7; // r3
  int v8; // r2
  int v9; // r3
  int result; // r0

  v2 = (unsigned int *)off_107054;
  v3 = (unsigned int *)off_107058;
  *(_DWORD *)off_107054 = *(_DWORD *)off_107054 & 0xFFFFFF8F | 0x50;
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  crypto_hw_clear_regs();
  *v2 &= ~1u;
  delay_us(140);
  v5 = off_10705C;
  *v3 |= 0x4000000u;
  v6 = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(_DWORD *)(a1 + 44) = v6;
  delay_us(5);
  sub_11F74C(1, dword_107060, *(_DWORD *)(a1 + 44), v7);
  result = sub_11F74C(1, dword_107064, v8, v9);
  *v3 &= ~0x1000000u;
  *v3 &= ~0x2000000u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x800000u;
  *v3 &= ~0x200000u;
  *v3 &= ~0x100000u;
  *v2 = *v2 & 0xFFFFFF8F | 0x40;
  return result;
}

