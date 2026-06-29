// fwstruct annotate: 12e160_sub_12E160.c
// sub_12E160 @ 0x12e160, size 40 bytes
// Doc: sdio_buffer_prepare_n_1c8 [util]: Prepares SDIO buffer descriptor, returns status byte
// sdio_buffer_prepare_n_1c8 [util]: Prepares SDIO buffer descriptor, returns status byte
unsigned __int8 *__fastcall sub_12E160(unsigned __int8 *a1, int a2, _BYTE *a3)
{
  unsigned __int8 *result; // r0
  unsigned __int16 v5; // [sp+6h] [bp-2h] BYREF

  result = sub_12DA54(a1, a2, 36, &v5);
  if ( result )
  {
    if ( (unsigned int)v5 - 9 > 9 )
      return nullptr;
    else
      *a3 = v5 - 3;
  }
  return result;
}

