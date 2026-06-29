// sub_12D8BC @ 0x12d8bc, size 60 bytes
uint8_t * sub_12D8BC(uint8_t *result, int a2, uint8_t *a3)
{
  unsigned int v3; // r1
  int v4; // r4
  uint8_t *v5; // r5

  v3 = (unsigned int)&result[a2];
  if ( v3 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v4 = (unsigned __int8)result[1];
    v5 = &result[v4 + 2];
    if ( *result == 68 )
      break;
    result += v4 + 2;
    if ( v3 <= (unsigned int)(v5 + 1) )
      return nullptr;
  }
  if ( v3 >= (unsigned int)v5 )
  {
    if ( !result )
      return result;
    if ( (unsigned int)(v4 + 2) > 0x15 )
    {
      *a3 = v4;
      return result;
    }
  }
  return nullptr;
}

