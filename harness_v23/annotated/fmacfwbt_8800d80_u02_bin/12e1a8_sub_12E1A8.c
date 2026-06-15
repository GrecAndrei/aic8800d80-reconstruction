// v23 annotated: sub_12E1A8 @ 0x12e1a8
// Original: 12e1a8_sub_12E1A8.c
// Primary struct: <unclustered>
//
// sub_12E1A8 @ 0x12e1a8, size 32 bytes
unsigned __int8 *__fastcall sub_12E1A8(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *result; // r0
  _WORD v3[3]; // [sp+6h] [bp-6h] BYREF

  result = sub_12DA54(a1, a2, 37, v3);
  if ( result )
  {
    if ( v3[0] != 4 )
      return nullptr;
  }
  return result;
}

