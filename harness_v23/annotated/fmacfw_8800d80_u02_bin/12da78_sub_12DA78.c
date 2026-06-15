// v23 annotated: sub_12DA78 @ 0x12da78
// Original: 12da78_sub_12DA78.c
// Primary struct: bt_hci_cmd (cluster 5, 21 funcs)
// Fields: ogf=0x0, ocf=0x1
//
// sub_12DA78 @ 0x12da78, size 64 bytes
_BYTE *__fastcall sub_12DA78(_BYTE *result, int a2)
{
  unsigned int v2; // r1
  _BYTE *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[(unsigned __int8)result[1] + 2];
    if ( *result == 60 )
      break;
    result += (unsigned __int8)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v3 )
    return nullptr;
  if ( result )
  {
    if ( result[1] != 4 )
      return nullptr;
  }
  return result;
}

