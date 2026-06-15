// v23 annotated: sub_12D75C @ 0x12d75c
// Original: 12d75c_sub_12D75C.c
// Primary struct: bt_hci_cmd (cluster 4, 21 funcs)
// Fields: ogf=0x0, ocf=0x1
//
// sub_12D75C @ 0x12d75c, size 64 bytes
_BYTE *__fastcall sub_12D75C(_BYTE *result, int a2, _BYTE *a3)
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
    if ( *result == 1 )
      break;
    result += v4 + 2;
    if ( v3 <= (unsigned int)(v5 + 1) )
      return nullptr;
  }
  if ( v3 >= (unsigned int)v5 )
  {
    if ( !result )
      return result;
    if ( (unsigned int)(v4 + 2) <= 0xE && result[1] )
    {
      *a3 = v4;
      return result;
    }
  }
  return nullptr;
}

