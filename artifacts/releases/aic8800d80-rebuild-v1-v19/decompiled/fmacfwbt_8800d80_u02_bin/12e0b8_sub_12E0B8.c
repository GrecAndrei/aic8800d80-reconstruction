// sub_12E0B8 @ 0x12e0b8, size 40 bytes
// Doc: sdio_buffer_prepare_280 [mmio]: Prepares SDIO buffer state via internal helper
// sdio_buffer_prepare_280 [mmio]: Prepares SDIO buffer state via internal helper
unsigned __int8 *__fastcall sub_12E0B8(unsigned __int8 *a1, int a2, _BYTE *a3)
{
  unsigned __int8 *result; // r0
  unsigned __int16 v5; // [sp+6h] [bp-2h] BYREF

  result = sub_12DA54(a1, a2, 35, &v5);
  if ( result )
  {
    if ( (unsigned int)v5 - 24 > 0x21 )
      return nullptr;
    else
      *a3 = v5 - 3;
  }
  return result;
}

