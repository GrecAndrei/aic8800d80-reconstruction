// fwstruct annotate: 12dd50_sub_12DD50.c
// sub_12DD50 @ 0x12dd50, size 40 bytes
unsigned __int8 *__fastcall sub_12DD50(unsigned __int8 *a1, int a2, _BYTE *a3)
{
  unsigned __int8 *result; // r0
  unsigned __int16 v5; // [sp+6h] [bp-2h] BYREF

  result = sub_12D6EC(a1, a2, 35, &v5);
  if ( result )
  {
    if ( (unsigned int)v5 - 24 > 0x21 )
      return nullptr;
    else
      *a3 = v5 - 3;
  }
  return result;
}

