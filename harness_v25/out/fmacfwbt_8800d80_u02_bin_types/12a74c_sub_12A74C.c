// sub_12A74C @ 0x12a74c, size 54 bytes
unsigned __int8 * sub_12A74C(int a1, unsigned __int8 a2)
{
  int v2; // r5
  int v3; // r4
  unsigned __int8 *v4; // r3
  int v5; // r0

  v2 = dword_12A784;
  v3 = *(unsigned __int8 *)(a1 + 1225);
  v4 = (unsigned __int8 *)(dword_12A784 + 140 * v3);
  v5 = v4[113];
  v4[115] = a2;
  v4[114] = 1;
  sub_125EFC(v5, 3);
  return sub_129A28((unsigned __int8 *)(v2 + 140 * v3));
}

