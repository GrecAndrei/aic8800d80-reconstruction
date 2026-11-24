// sdio_buffer_prepare_n_1e4 @ 0x12df38, size 40 bytes
// Doc: sdio_buffer_prepare_n_1d2 [util]: Prepare SDIO transfer buffer
// sdio_buffer_prepare_n_1d2 [util]: Prepare SDIO transfer buffer
unsigned __int8 *__fastcall sdio_buffer_prepare_n_1e4(unsigned __int8 *a1, int a2, _BYTE *a3)
{
  unsigned __int8 *result; // r0
  unsigned __int16 v5; // [sp+6h] [bp-2h] BYREF

  result = sub_12D82C(a1, a2, 36, &v5);
  if ( result )
  {
    if ( (unsigned int)v5 - 9 > 9 )
      return nullptr;
    else
      *a3 = v5 - 3;
  }
  return result;
}

