// sub_12A3E8 @ 0x12a3e8, size 54 bytes
unsigned __int8 *__fastcall sub_12A3E8(int a1, unsigned __int8 a2)
{
  int v2; // r5
  int v3; // r4
  unsigned __int8 *v4; // r3
  int v5; // r0

  v2 = dword_12A420;
  v3 = *(unsigned __int8 *)(a1 + 1225);
  v4 = (unsigned __int8 *)(dword_12A420 + 140 * v3);
  v5 = *(_DWORD *)(v4 + 0x1c4);
  *(_DWORD *)(v4 + 0x1cc) = a2;
  *(_DWORD *)(v4 + 0x1c8) = 1;
  sub_125B98(v5, 3);
  return sub_1296C4((unsigned __int8 *)(v2 + 140 * v3));
}

