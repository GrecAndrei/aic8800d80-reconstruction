// sdio_buffer_prepare_e188 @ 0x12e188, size 32 bytes
// Doc: sdio_buffer_prepare_n_1a2 [tx]: Prepare SDIO buffer descriptor
// sdio_buffer_prepare_n_1a2 [tx]: Prepare SDIO buffer descriptor
unsigned __int8 *__fastcall sdio_buffer_prepare_e188(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *result; // r0
  _WORD v3[3]; // [sp+6h] [bp-6h] BYREF

  result = sub_12DA54(a1, a2, 38, v3);
  if ( result )
  {
    if ( v3[0] != 16 )
      return nullptr;
  }
  return result;
}

