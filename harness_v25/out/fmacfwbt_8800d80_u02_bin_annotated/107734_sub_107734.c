// fwstruct annotate: 107734_sub_107734.c
// sub_107734 @ 0x107734, size 212 bytes
int __fastcall sub_107734(int a1, _DWORD *a2, int a3)
{
  _DWORD *v3; // r5
  _DWORD *v4; // r4
  int *v5; // r6
  int v6; // r8
  int v7; // r7
  __int64 v8; // kr00_8
  int v9; // r3
  int *v10; // r0
  int v11; // r0
  int result; // r0

  v3 = off_107808;
  v4 = off_10780C;
  v5 = (int *)off_107810;
  v6 = dword_107820;
  v7 = dword_107814;
  v8 = *(_QWORD *)(a1 + 8);
  sub_107370();
  *v3 &= ~1u;
  delay_us(20);
  v9 = dword_107818;
  *v3 |= 4u;
  *v3 |= 8u;
  *v4 |= 0x100000u;
  *v4 |= 0x200000u;
  *v5 = v9 & (HIDWORD(v8) << 16) | *v5 & v6;
  *v5 = *v5 & v7 | v8 & 0xFFF;
  delay_us(40);
  v10 = (int *)off_10781C;
  *v4 |= 0x4000000u;
  v11 = *v10;
  *v4 &= ~0x4000000u;
  *v4 &= ~0x100000u;
  *v4 &= ~0x200000u;
  result = rf_level_apply_n_1f8(v11 & 0x7FFF, a2, a3);
  *v3 &= ~4u;
  *v3 &= ~8u;
  *v5 &= v6;
  *v5 &= v7;
  *v4 &= ~0x1000000u;
  *v4 &= ~0x2000000u;
  return result;
}

