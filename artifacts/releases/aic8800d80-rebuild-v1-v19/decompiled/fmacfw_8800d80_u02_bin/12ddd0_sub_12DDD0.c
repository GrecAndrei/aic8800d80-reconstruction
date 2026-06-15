// sub_12DDD0 @ 0x12ddd0, size 64 bytes
// Doc: sdio_buffer_prepare_n_32a_ddf2 [mmio]: Compare SDIO buffer indices for transfer readiness
// sdio_buffer_prepare_n_32a_ddf2 [mmio]: Compare SDIO buffer indices for transfer readiness
_BYTE *__fastcall sub_12DDD0(_BYTE *result, int a2)
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

