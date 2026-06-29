// fwstruct annotate: 12d918_sub_12D918.c
// sub_12D918 @ 0x12d918, size 64 bytes
unsigned __int8 *__fastcall sub_12D918(unsigned __int8 *result, int a2, _BYTE *a3)
{
  unsigned int v3; // r1
  int v4; // r5
  unsigned __int8 *v5; // r6

  v3 = (unsigned int)&result[a2];
  if ( v3 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v4 = result[1];
    v5 = &result[v4 + 2];
    if ( !*result )
      break;
    result += v4 + 2;
    if ( v3 <= (unsigned int)(v5 + 1) )
      return nullptr;
  }
  if ( v3 < (unsigned int)v5 )
    return (unsigned __int8 *)*result;
  if ( !result )
    return result;
  if ( (unsigned int)(v4 + 2) > 0x22 )
    return (unsigned __int8 *)*result;
  *a3 = v4;
  return result;
}

