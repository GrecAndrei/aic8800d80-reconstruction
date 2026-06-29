// fwstruct annotate: 12de20_sub_12DE20.c
// sub_12DE20 @ 0x12de20, size 32 bytes
unsigned __int8 *__fastcall sub_12DE20(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *result; // r0
  _WORD v3[3]; // [sp+6h] [bp-6h] BYREF

  result = sub_12D6EC(a1, a2, 38, v3);
  if ( result )
  {
    if ( v3[0] != 16 )
      return nullptr;
  }
  return result;
}

