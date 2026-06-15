// v23 annotated: sub_12DCA0 @ 0x12dca0
// Original: 12dca0_sub_12DCA0.c
// Primary struct: <unclustered>
//
// sub_12DCA0 @ 0x12dca0, size 64 bytes
// Doc: sdio_buffer_prepare_n_45e [ipc]: Prepare SDIO buffer descriptor compare
// sdio_buffer_prepare_n_45e [ipc]: Prepare SDIO buffer descriptor compare
_BYTE *__fastcall sub_12DCA0(_BYTE *result, int a2)
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

