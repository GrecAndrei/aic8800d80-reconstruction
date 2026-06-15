// v23 annotated: sub_12DD08 @ 0x12dd08
// Original: 12dd08_sub_12DD08.c
// Primary struct: bt_hci_cmd (cluster 5, 21 funcs)
// Fields: ogf=0x0, ocf=0x1
//
// sub_12DD08 @ 0x12dd08, size 64 bytes
// Doc: sdio_buffer_prepare_dd16 [mmio]: Prepare SDIO DMA buffer for transfer
// sdio_buffer_prepare_dd16 [mmio]: Prepare SDIO DMA buffer for transfer
_BYTE *__fastcall sub_12DD08(_BYTE *result, int a2)
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

