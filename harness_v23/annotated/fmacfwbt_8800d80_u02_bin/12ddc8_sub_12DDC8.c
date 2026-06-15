// v23 annotated: sub_12DDC8 @ 0x12ddc8
// Original: 12ddc8_sub_12DDC8.c
// Primary struct: <unclustered>
//
// sub_12DDC8 @ 0x12ddc8, size 64 bytes
_BYTE *__fastcall sub_12DDC8(_BYTE *result, int a2)
{
  unsigned int v2; // r1
  _BYTE *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[(unsigned __int8)result[1] + 2];
    if ( *result == 76 )
      break;
    result += (unsigned __int8)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v3 )
    return nullptr;
  if ( result )
  {
    if ( result[1] != 16 )
      return nullptr;
  }
  return result;
}

