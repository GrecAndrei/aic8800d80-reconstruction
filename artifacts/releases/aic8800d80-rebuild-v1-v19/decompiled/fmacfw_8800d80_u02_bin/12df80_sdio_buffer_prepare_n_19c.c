// sdio_buffer_prepare_n_19c @ 0x12df80, size 32 bytes
// Doc: sdio_buffer_prepare_n_196 [mmio]: Prepares SDIO buffer for transfer (size mask 0x1000, cmd 0x25)
// sdio_buffer_prepare_n_196 [mmio]: Prepares SDIO buffer for transfer (size mask 0x1000, cmd 0x25)
unsigned __int8 *__fastcall sdio_buffer_prepare_n_19c(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *result; // r0
  _WORD v3[3]; // [sp+6h] [bp-6h] BYREF

  result = sub_12D82C(a1, a2, 37, v3);
  if ( result )
  {
    if ( v3[0] != 4 )
      return nullptr;
  }
  return result;
}

