// sub_12A6E8 @ 0x12a6e8, size 90 bytes
unsigned __int8 *__fastcall sub_12A6E8(int a1, int a2)
{
  unsigned __int8 *result; // r0
  int v3; // r3
  int v4; // r4
  unsigned __int8 *v5; // r2
  int v6; // r5
  unsigned __int8 *v7; // r4

  result = (unsigned __int8 *)(dword_12A744 + 1320 * a1);
  if ( result[1224] && result[106] == 2 )
  {
    v3 = result[1225];
    v4 = dword_12A748;
    v5 = (unsigned __int8 *)(dword_12A748 + 140 * v3);
    v6 = v5[132];
    v5[135] = a2 != 0;
    v7 = (unsigned __int8 *)(v4 + 140 * v3);
    if ( v6 )
      sub_125EFC(v5[113], 3);
    return sub_129A28(v7);
  }
  return result;
}

