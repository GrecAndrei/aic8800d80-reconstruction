// fwstruct annotate: 12e0e0_sub_12E0E0.c
// sub_12E0E0 @ 0x12e0e0, size 64 bytes
// Doc: sdio_buffer_prepare_n_25c [util]: Prepare SDIO buffer (leaf wrapper)
// sdio_buffer_prepare_n_25c [util]: Prepare SDIO buffer (leaf wrapper)
_BYTE *__fastcall sub_12E0E0(_BYTE *result, int a2)
{
  unsigned int v2; // r1
  _BYTE *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[(unsigned __int8)result[1] + 2];
    if ( *result == 61 )
      break;
    result += (unsigned __int8)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v3 )
    return nullptr;
  if ( result )
  {
    if ( result[1] != 22 )
      return nullptr;
  }
  return result;
}

