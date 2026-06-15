// v23 annotated: sub_12DB60 @ 0x12db60
// Original: 12db60_sub_12DB60.c
// Primary struct: bt_hci_cmd (cluster 5, 21 funcs)
// Fields: ogf=0x0, ocf=0x1
//
// sub_12DB60 @ 0x12db60, size 64 bytes
_BYTE *__fastcall sub_12DB60(_BYTE *result, int a2)
{
  unsigned int v2; // r1
  _BYTE *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[(unsigned __int8)result[1] + 2];
    if ( *result == 3 )
      break;
    result += (unsigned __int8)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v3 )
    return nullptr;
  if ( result )
  {
    if ( result[1] != 1 )
      return nullptr;
  }
  return result;
}

