// v23 annotated: sdio_buffer_prepare_n_1bc @ 0x12df60
// Original: 12df60_sdio_buffer_prepare_n_1bc.c
// Primary struct: <unclustered>
//
// sdio_buffer_prepare_n_1bc @ 0x12df60, size 32 bytes
// Doc: sdio_buffer_prepare_n_1b8 [mac]: Prepares SDIO transfer buffer for DMA operation
// sdio_buffer_prepare_n_1b8 [mac]: Prepares SDIO transfer buffer for DMA operation
unsigned __int8 *__fastcall sdio_buffer_prepare_n_1bc(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *result; // r0
  _WORD v3[3]; // [sp+6h] [bp-6h] BYREF

  result = sub_12D82C(a1, a2, 38, v3);
  if ( result )
  {
    if ( v3[0] != 16 )
      return nullptr;
  }
  return result;
}

