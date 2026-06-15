// v23 annotated: sub_12DD10 @ 0x12dd10
// Original: 12dd10_sub_12DD10.c
// Primary struct: <unclustered>
//
// sub_12DD10 @ 0x12dd10, size 64 bytes
unsigned __int8 *__fastcall sub_12DD10(unsigned __int8 *result, int a2)
{
  unsigned int v2; // r1
  unsigned __int8 *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[result[1] + 2];
    if ( *result == 191 )
      break;
    result += result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v3 )
    return nullptr;
  if ( result )
  {
    if ( result[1] != 12 )
      return nullptr;
  }
  return result;
}

