// sub_12DBBC @ 0x12dbbc, size 60 bytes
_BYTE *__fastcall sub_12DBBC(_BYTE *result, int a2, _BYTE *a3)
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
    if ( *result == 48 )
      break;
    result += v4 + 2;
    if ( v3 <= (unsigned int)(v5 + 1) )
      return nullptr;
  }
  if ( v3 >= (unsigned int)v5 )
  {
    if ( !result )
      return result;
    if ( (unsigned int)(v4 + 2) > 0x13 )
    {
      *a3 = v4;
      return result;
    }
  }
  return nullptr;
}

