// v23 annotated: sub_100B14 @ 0x100b14
// Original: 100b14_sub_100B14.c
// Primary struct: mmio_clock_gate (cluster 1, 21 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_100B14 @ 0x100b14, size 94 bytes
_DWORD *sub_100B14()
{
  __int64 v0; // r0
  unsigned int *v1; // r5
  unsigned int *v2; // r4
  int v3; // r0
  int v4; // r0
  __int16 v5; // r0
  _DWORD *v6; // r2
  _DWORD *v7; // r1
  _DWORD *result; // r0
  _BYTE *v9; // r5

  v0 = sub_1429D4();
  v1 = (unsigned int *)off_100B78;
  v2 = (unsigned int *)off_100B7C;
  v3 = sub_142CFC(v0, HIDWORD(v0), 0, dword_100B74);
  v4 = math_round(v3);
  v5 = sub_14302C(v4);
  v6 = off_100B80;
  v7 = off_100B84;
  *v1 = (unsigned __int16)(v5 << 8) | *v1 & 0xFFFF00FF;
  result = off_100B88;
  v9 = off_100B8C;
  *v2 = *v2 & 0xFFFFF9FF | 0x200;
  *v6 |= 0x40000000u;
  *v6 |= 0x80000000;
  *v7 = 4096;
  *result |= 0x1000u;
  *v9 = 1;
  return result;
}

