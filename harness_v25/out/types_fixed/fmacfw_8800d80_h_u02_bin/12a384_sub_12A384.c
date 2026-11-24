// sub_12A384 @ 0x12a384, size 90 bytes
unsigned __int8 *__fastcall sub_12A384(int a1, int a2)
{
  unsigned __int8 *result; // r0
  int v3; // r3
  int v4; // r4
  unsigned __int8 *v5; // r2
  int v6; // r5
  unsigned __int8 *v7; // r4

  result = (unsigned __int8 *)(dword_12A3E0 + 1320 * a1);
  if ( *(_DWORD *)(result + 0x1320) && *(_DWORD *)(result + 0x1a8) == 2 )
  {
    v3 = *(_DWORD *)(result + 0x1324);
    v4 = dword_12A3E4;
    v5 = (unsigned __int8 *)(dword_12A3E4 + 140 * v3);
    v6 = *(_DWORD *)(v5 + 0x210);
    *(_DWORD *)(v5 + 0x21c) = a2 != 0;
    v7 = (unsigned __int8 *)(v4 + 140 * v3);
    if ( v6 )
      sub_125B98(*(_DWORD *)(v5 + 0x1c4), 3);
    return sub_1296C4(v7);
  }
  return result;
}

