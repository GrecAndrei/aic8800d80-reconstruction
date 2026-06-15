// v23 annotated: sub_12DF80 @ 0x12df80
// Original: 12df80_sub_12DF80.c
// Primary struct: <unclustered>
//
// sub_12DF80 @ 0x12df80, size 32 bytes
unsigned __int8 *__fastcall sub_12DF80(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *result; // r0
  _WORD v3[3]; // [sp+6h] [bp-6h] BYREF

  result = sub_12D82C(a1, a2, 37, v3);
  if ( result )
  {
    if ( v3[0] != 4 )
      return nullptr;
  }
  return result;
}

