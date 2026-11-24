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
  v5 = *(_DWORD *)(v4 + 0x1c4);
  *(_DWORD *)(v4 + 0x1cc) = a2;
  *(_DWORD *)(v4 + 0x1c8) = 1;
  sub_125CD8(v5, 3);
  return sub_129804((unsigned __int8 *)(v2 + 140 * v3));
}

