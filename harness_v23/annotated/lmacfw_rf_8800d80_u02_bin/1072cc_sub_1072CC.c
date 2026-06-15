// v23 annotated: sub_1072CC @ 0x1072cc
// Original: 1072cc_sub_1072CC.c
// Primary struct: <unclustered>
//
// sub_1072CC @ 0x1072cc, size 212 bytes
int __fastcall sub_1072CC(int a1, _DWORD *a2, int a3)
{
  _DWORD *v3; // r5
  unsigned int *v4; // r4
  int *v5; // r6
  int v6; // r8
  int v7; // r7
  __int64 v8; // kr00_8
  int v9; // r3
  int *v10; // r0
  int v11; // r0
  unsigned int v12; // r3
  int result; // r0

  v3 = off_1073A0;
  v4 = (unsigned int *)off_1073A4;
  v5 = (int *)off_1073A8;
  v6 = dword_1073B8;
  v7 = dword_1073AC;
  v8 = *(_QWORD *)(a1 + 8);
  crypto_hw_clear_regs();
  *v3 &= ~1u;
  delay_us(20);
  v9 = dword_1073B0;
  *v3 |= 4u;
  *v3 |= 8u;
  *v4 |= 0x100000u;
  *v4 |= 0x200000u;
  *v5 = v9 & (HIDWORD(v8) << 16) | *v5 & v6;
  *v5 = *v5 & v7 | v8 & 0xFFF;
  delay_us(40);
  v10 = (int *)off_1073B4;
  *v4 |= 0x4000000u;
  v11 = *v10;
  *v4 &= ~0x4000000u;
  *v4 &= ~0x100000u;
  v12 = *v4 & 0xFFDFFFFF;
  *v4 = v12;
  result = sub_107214(v11 & 0x7FFF, a2, a3, v12);
  *v3 &= ~4u;
  *v3 &= ~8u;
  *v5 &= v6;
  *v5 &= v7;
  *v4 &= ~0x1000000u;
  *v4 &= ~0x2000000u;
  return result;
}

