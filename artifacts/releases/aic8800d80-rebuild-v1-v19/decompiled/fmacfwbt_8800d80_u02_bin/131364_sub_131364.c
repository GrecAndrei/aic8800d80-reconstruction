// sub_131364 @ 0x131364, size 60 bytes
unsigned __int8 *__fastcall sub_131364(unsigned __int8 *a1, int a2, int a3)
{
  unsigned __int8 *result; // r0
  __int16 v5; // r1
  __int16 v6; // r6
  __int16 v7; // r5
  __int16 v8; // r2
  int v9; // r7
  __int16 v10; // r3
  __int16 v11; // r0

  result = sub_12E078(a1, a2);
  if ( result )
  {
    v5 = result[10];
    v6 = result[11];
    v7 = result[6] | (result[7] << 8);
    v8 = result[8] | (result[9] << 8);
    v9 = *(_DWORD *)(result + 2);
    v10 = result[12];
    v11 = result[13];
    *(_DWORD *)a3 = v9;
    *(_WORD *)(a3 + 4) = v7;
    *(_WORD *)(a3 + 8) = v5 | (v6 << 8);
    *(_WORD *)(a3 + 6) = v8;
    *(_WORD *)(a3 + 10) = v10 | (v11 << 8);
    return (unsigned __int8 *)1;
  }
  return result;
}

