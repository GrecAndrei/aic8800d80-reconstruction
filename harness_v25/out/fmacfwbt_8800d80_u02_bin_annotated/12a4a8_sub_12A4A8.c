// fwstruct annotate: 12a4a8_sub_12A4A8.c
// sub_12A4A8 @ 0x12a4a8, size 144 bytes
unsigned __int8 *__fastcall sub_12A4A8(unsigned __int8 *result, int a2)
{
  int v2; // r2
  int v3; // r7
  int v4; // r6
  int v5; // r12
  unsigned int v6; // r4
  int v7; // lr
  unsigned __int8 *v8; // r5
  int v9; // r3
  int v10; // r1

  if ( result[1224] )
  {
    v2 = result[1225];
    v3 = dword_12A538;
    v4 = dword_12A538 + 140 * v2;
    v5 = *(unsigned __int8 *)(v4 + 115);
    v6 = *((_DWORD *)result + 1) & 0xFFFFFFBF;
    *(_BYTE *)(v4 + 134) = 1;
    v7 = 140 * v2;
    v8 = (unsigned __int8 *)(v3 + 140 * v2);
    *((_DWORD *)result + 1) = v6;
    if ( !v5 )
      return sub_129A28(v8);
    v9 = a2 + (v5 << 10);
    if ( *(_BYTE *)(v4 + 112) || (v10 = a2 + 300, *((_DWORD *)off_12A53C + 4) - v10 + 50 >= 0) )
    {
      *(_BYTE *)(v3 + 140 * v2 + 114) = 1;
      timestamp_update_4f60(v7 + 96 + v3, v9);
      return sub_129A28(v8);
    }
    *(_DWORD *)(v4 + 116) = v9;
    *(_BYTE *)(v4 + 114) = 2;
    return (unsigned __int8 *)timestamp_update_4f60(v7 + 96 + v3, v10);
  }
  return result;
}

