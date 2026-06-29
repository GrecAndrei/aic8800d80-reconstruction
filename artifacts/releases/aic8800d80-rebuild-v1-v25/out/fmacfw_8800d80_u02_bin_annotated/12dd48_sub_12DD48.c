// fwstruct annotate: 12dd48_sub_12DD48.c
// sub_12DD48 @ 0x12dd48, size 64 bytes
// Doc: sdio_buffer_prepare_n_3ac [mmio]: Validate channel/type against 6 and return status
// sdio_buffer_prepare_n_3ac [mmio]: Validate channel/type against 6 and return status
_BYTE *__fastcall sub_12DD48(_BYTE *result, int a2)
{
  unsigned int v2; // r1
  unsigned int v3; // r3
  _BYTE *v4; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = (unsigned __int8)result[1] + 2;
    v4 = &result[v3];
    if ( *result == 71 )
      break;
    result += v3;
    if ( v2 <= (unsigned int)(v4 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v4 )
    return nullptr;
  if ( result )
  {
    if ( v3 < 6 )
      return nullptr;
  }
  return result;
}

