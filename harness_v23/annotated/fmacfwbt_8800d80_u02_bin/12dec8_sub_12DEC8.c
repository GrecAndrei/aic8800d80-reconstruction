// v23 annotated: sub_12DEC8 @ 0x12dec8
// Original: 12dec8_sub_12DEC8.c
// Primary struct: bt_hci_cmd (cluster 4, 22 funcs)
// Fields: ogf=0x0, ocf=0x1
//
// sub_12DEC8 @ 0x12dec8, size 64 bytes
// Doc: sdio_buffer_prepare_n_468 [util]: Alternate SDIO buffer preparation path comparing length fields
// sdio_buffer_prepare_n_468 [util]: Alternate SDIO buffer preparation path comparing length fields
_BYTE *__fastcall sub_12DEC8(_BYTE *result, int a2)
{
  unsigned int v2; // r1
  _BYTE *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[(unsigned __int8)result[1] + 2];
    if ( *result == 54 )
      break;
    result += (unsigned __int8)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v3 )
    return nullptr;
  if ( result )
  {
    if ( result[1] != 3 )
      return nullptr;
  }
  return result;
}

