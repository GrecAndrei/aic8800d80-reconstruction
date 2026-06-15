// v23 annotated: sub_12DF30 @ 0x12df30
// Original: 12df30_sub_12DF30.c
// Primary struct: <unclustered>
//
// sub_12DF30 @ 0x12df30, size 64 bytes
// Doc: sdio_buffer_prepare_df58 [mac]: Validates SDIO buffer size against 0x1c limit
// sdio_buffer_prepare_df58 [mac]: Validates SDIO buffer size against 0x1c limit
_BYTE *__fastcall sub_12DF30(_BYTE *result, int a2)
{
  unsigned int v2; // r1
  _BYTE *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[(unsigned __int8)result[1] + 2];
    if ( *result == 45 )
      break;
    result += (unsigned __int8)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v3 )
    return nullptr;
  if ( result )
  {
    if ( result[1] != 26 )
      return nullptr;
  }
  return result;
}

