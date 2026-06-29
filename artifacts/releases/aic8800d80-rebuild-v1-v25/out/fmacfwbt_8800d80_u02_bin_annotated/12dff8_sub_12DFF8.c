// fwstruct annotate: 12dff8_sub_12DFF8.c
// sub_12DFF8 @ 0x12dff8, size 64 bytes
// Doc: sdio_buffer_prepare_n_334 [tx]: Prepares SDIO buffer by comparing descriptor indices
// sdio_buffer_prepare_n_334 [tx]: Prepares SDIO buffer by comparing descriptor indices
_BYTE *__fastcall sub_12DFF8(_BYTE *result, int a2)
{
  unsigned int v2; // r1
  _BYTE *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[(unsigned __int8)result[1] + 2];
    if ( *result == 83 )
      break;
    result += (unsigned __int8)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v3 )
    return nullptr;
  if ( result )
  {
    if ( result[1] != 2 )
      return nullptr;
  }
  return result;
}

