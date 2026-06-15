// v23 annotated: sub_12A528 @ 0x12a528
// Original: 12a528_sub_12A528.c
// Primary struct: group_16 (cluster 16)
//
// sub_12A528 @ 0x12a528, size 54 bytes
unsigned __int8 *__fastcall sub_12A528(int a1, unsigned __int8 a2)
{
  int v2; // r5
  int v3; // r4
  unsigned __int8 *v4; // r3
  int v5; // r0

  v2 = dword_12A560;
  v3 = *(unsigned __int8 *)(a1 + 1225);
  v4 = (unsigned __int8 *)(dword_12A560 + 140 * v3);
  v5 = v4[113];
  v4[115] = a2;
  v4[114] = 1;
  sub_125CD8(v5, 3);
  return sub_129804((unsigned __int8 *)(v2 + 140 * v3));
}

