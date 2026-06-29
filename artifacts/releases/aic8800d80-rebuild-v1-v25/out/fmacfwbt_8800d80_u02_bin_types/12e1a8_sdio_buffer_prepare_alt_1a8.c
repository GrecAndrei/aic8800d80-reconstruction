// sdio_buffer_prepare_alt_1a8 @ 0x12e1a8, size 32 bytes
// Doc: sdio_buffer_prepare_n_19a [mmio]: Prepare SDIO buffer for transfer (variant 0x19a)
// sdio_buffer_prepare_n_19a [mmio]: Prepare SDIO buffer for transfer (variant 0x19a)
unsigned __int8 * sdio_buffer_prepare_alt_1a8(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *result; // r0
  uint16_t v3[3]; // [sp+6h] [bp-6h] BYREF

  result = sub_12DA54(a1, a2, 37, v3);
  if ( result )
  {
    if ( v3[0] != 4 )
      return nullptr;
  }
  return result;
}

