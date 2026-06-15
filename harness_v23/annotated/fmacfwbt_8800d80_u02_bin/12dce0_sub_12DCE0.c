// v23 annotated: sub_12DCE0 @ 0x12dce0
// Original: 12dce0_sub_12DCE0.c
// Primary struct: bt_hci_cmd (cluster 4, 22 funcs)
// Fields: ogf=0x0, ocf=0x1
//
// sub_12DCE0 @ 0x12dce0, size 66 bytes
_BYTE *__fastcall sub_12DCE0(_BYTE *result, int a2, bool *a3)
{
  unsigned int v3; // r1
  _BYTE *v4; // r4

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

