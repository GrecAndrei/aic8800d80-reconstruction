// fwstruct annotate: 131144_sub_131144.c
// sub_131144 @ 0x131144, size 40 bytes
unsigned __int8 *__fastcall sub_131144(_BYTE *a1, int a2, int a3)
{
  unsigned __int8 *result; // r0

  result = sub_12DEC8(a1, a2);
  if ( result )
  {
    *(_WORD *)(a3 + 228) = result[2] | (result[3] << 8);
    *(_BYTE *)(a3 + 230) = result[4];
  }
  else
  {
    *(_BYTE *)(a3 + 230) = 0;
    *(_WORD *)(a3 + 228) = 0;
  }
  return result;
}

