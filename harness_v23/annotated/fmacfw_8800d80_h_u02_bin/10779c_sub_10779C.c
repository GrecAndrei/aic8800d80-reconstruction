// v23 annotated: sub_10779C @ 0x10779c
// Original: 10779c_sub_10779C.c
// Primary struct: <unclustered>
//
// sub_10779C @ 0x10779c, size 212 bytes
int __fastcall sub_10779C(int a1, _DWORD *a2, int a3)
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

  v3 = off_107870;
  v4 = off_107874;
  v5 = (int *)off_107878;
  v6 = dword_107888;
  v7 = dword_10787C;
  v8 = *(_QWORD *)(a1 + 8);
  sub_1073D8();
  *v3 &= ~1u;
  sub_100644(20);
  v9 = dword_107880;
  *v3 |= 4u;
  *v3 |= 8u;
  *v4 |= 0x100000u;
  *v4 |= 0x200000u;
  *v5 = v9 & (HIDWORD(v8) << 16) | *v5 & v6;
  *v5 = *v5 & v7 | v8 & 0xFFF;
  sub_100644(40);
  v10 = (int *)off_107884;
  *v4 |= 0x4000000u;
  v11 = *v10;
  *v4 &= ~0x4000000u;
  *v4 &= ~0x100000u;
  *v4 &= ~0x200000u;
  result = sub_1076E4(v11 & 0x7FFF, a2, a3);
  *v3 &= ~4u;
  *v3 &= ~8u;
  *v5 &= v6;
  *v5 &= v7;
  *v4 &= ~0x1000000u;
  *v4 &= ~0x2000000u;
  return result;
}

