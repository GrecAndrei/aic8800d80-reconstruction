// fwstruct annotate: 13ba24_sub_13BA24.c
// sub_13BA24 @ 0x13ba24, size 76 bytes
unsigned __int8 *__fastcall sub_13BA24(int a1)
{
  unsigned __int8 *result; // r0
  int v2; // r1
  int v3; // r3

  result = (unsigned __int8 *)(dword_13BA70 + 32 * a1);
  v2 = result[16];
  v3 = result[22];
  if ( result[17] )
  {
    if ( result[17] == 1 )
      *(_BYTE *)(696 * v2 + 12 * v3 + dword_13BA74 + 453) = 33;
  }
  else
  {
    *(_BYTE *)(696 * v2 + 12 * v3 + dword_13BA74 + 452) = 33;
  }
  return result;
}

