// fwstruct annotate: 12e038_sub_12E038.c
// sub_12E038 @ 0x12e038, size 64 bytes
// Doc: sdio_buffer_prepare_n_304_e040 [mmio]: Prepares SDIO buffer (push r4 prologue)
// sdio_buffer_prepare_n_304_e040 [mmio]: Prepares SDIO buffer (push r4 prologue)
_BYTE *__fastcall sub_12E038(_BYTE *result, int a2)
{
  unsigned int v2; // r1
  _BYTE *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[(unsigned __int8)result[1] + 2];
    if ( *result == 85 )
      break;
    result += (unsigned __int8)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v3 )
    return nullptr;
  if ( result )
  {
    if ( !result[1] )
      return nullptr;
  }
  return result;
}

