// v23 annotated: sdio_buffer_prepare_n_43c @ 0x12dce0
// Original: 12dce0_sdio_buffer_prepare_n_43c.c
// Primary struct: <unclustered>
//
// sdio_buffer_prepare_n_43c @ 0x12dce0, size 36 bytes
// Doc: sdio_buffer_prepare_n_430_dcec [util]: SDIO buffer prepare entry with channel arg 5
// sdio_buffer_prepare_n_430_dcec [util]: SDIO buffer prepare entry with channel arg 5
unsigned __int8 *__fastcall sdio_buffer_prepare_n_43c(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *result; // r0
  _WORD v3[3]; // [sp+Eh] [bp-6h] BYREF

  result = sub_12D788(a1, a2, (unsigned __int8 *)dword_12DD04, 5, v3);
  if ( result )
  {
    if ( v3[0] != 26 )
      return nullptr;
  }
  return result;
}

