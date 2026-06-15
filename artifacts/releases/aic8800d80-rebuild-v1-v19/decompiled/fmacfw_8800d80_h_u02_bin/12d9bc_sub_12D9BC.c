// sub_12D9BC @ 0x12d9bc, size 100 bytes
unsigned __int8 *__fastcall sub_12D9BC(unsigned __int8 *result, int a2, bool *a3)
{
  unsigned int v3; // r1
  int v4; // r4
  unsigned __int8 *v5; // r3
  unsigned int v6; // r4
  int v7; // r3

  v3 = (unsigned int)&result[a2];
  if ( v3 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v4 = result[1];
    v5 = &result[v4 + 2];
    if ( *result == 196 )
      break;
    result += v4 + 2;
    if ( v3 <= (unsigned int)(v5 + 1) )
      return nullptr;
  }
  if ( v3 >= (unsigned int)v5 )
  {
    if ( !result )
      return result;
    result += 2;
    v6 = (unsigned int)&result[v4];
    while ( v6 > (unsigned int)(result + 1) )
    {
      v7 = result[1] + 2;
      if ( *result == 194 )
      {
        if ( v6 < (unsigned int)&result[v7] )
          return nullptr;
        if ( result )
          *a3 = result[1] == 3;
        return result;
      }
      result += v7;
    }
  }
  return nullptr;
}

