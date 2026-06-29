// sub_12DCE0 @ 0x12dce0, size 66 bytes
uint8_t * sub_12DCE0(uint8_t *result, int a2, bool *a3)
{
  unsigned int v3; // r1
  uint8_t *v4; // r4

  v3 = (unsigned int)&result[a2];
  if ( v3 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v4 = &result[(unsigned __int8)result[1] + 2];
    if ( *result == 62 )
      break;
    result += (unsigned __int8)result[1] + 2;
    if ( v3 <= (unsigned int)(v4 + 1) )
      return nullptr;
  }
  if ( v3 < (unsigned int)v4 )
    return nullptr;
  if ( result )
    *a3 = result[1] == 1;
  return result;
}

