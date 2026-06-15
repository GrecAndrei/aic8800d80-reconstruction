// sub_129F50 @ 0x129f50, size 152 bytes
unsigned __int8 *__fastcall sub_129F50(unsigned __int8 *result, int a2)
{
  int v2; // r5
  int v3; // r7
  unsigned __int8 *v4; // r8
  int v5; // r9
  int v6; // r4
  unsigned __int8 *v7; // r5
  int v8; // r3

  if ( result[1224] && !(result[106] | a2) )
  {
    v2 = result[1225];
    v3 = dword_129FE8;
    v4 = (unsigned __int8 *)(dword_129FE8 + 140 * v2);
    v5 = 140 * v2;
    if ( v4[16] )
    {
      sub_124CF4(dword_129FE8 + 140 * v2);
      v4[16] = 0;
    }
    v6 = v3 + 140 * v2;
    if ( *(_BYTE *)(v6 + 64) )
    {
      sub_124CF4(v5 + 48 + v3);
      *(_BYTE *)(v6 + 64) = 0;
    }
    v7 = (unsigned __int8 *)(v3 + 140 * v2);
    v8 = v7[114];
    v7[115] = 0;
    v7[120] = 0;
    v7[132] = 0;
    if ( v8 )
    {
      sub_124CF4(v5 + 96 + v3);
      v7[114] = 0;
    }
    return sub_1296C4(v4);
  }
  return result;
}

