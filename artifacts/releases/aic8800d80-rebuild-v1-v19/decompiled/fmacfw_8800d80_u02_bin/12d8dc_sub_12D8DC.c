// sub_12D8DC @ 0x12d8dc, size 60 bytes
_BYTE *__fastcall sub_12D8DC(_BYTE *result, int a2, _BYTE *a3)
{
  unsigned int v3; // r1
  int v4; // r4
  _BYTE *v5; // r5

  v3 = (unsigned int)&result[a2];
  if ( v3 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v4 = (unsigned __int8)result[1];
    v5 = &result[v4 + 2];
    if ( *result == 50 )
      break;
    result += v4 + 2;
    if ( v3 <= (unsigned int)(v5 + 1) )
      return nullptr;
  }
  if ( v3 >= (unsigned int)v5 )
  {
    if ( !result )
      return result;
    if ( result[1] )
    {
      *a3 = v4;
      return result;
    }
  }
  return nullptr;
}

