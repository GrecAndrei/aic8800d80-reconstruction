// sdio_buffer_prepare_n_16c_e1d8 @ 0x12e1d8, size 30 bytes
// Doc: sdio_buffer_prepare_n_16c_e1d8 [mmio]: Prepare SDIO transfer buffer address with channel offset
// sdio_buffer_prepare_n_16c_e1d8 [mmio]: Prepare SDIO transfer buffer address with channel offset
int __fastcall sdio_buffer_prepare_n_16c_e1d8(int a1, __int16 a2)
{
  return sdio_buffer_prepare_n_14c
       & ((((32 * (*(unsigned __int8 *)(a1 + 5) ^ (*(unsigned __int8 *)(a1 + 5) >> 4))) & 0x1E0) + (a2 & 0x1FF)) << 22)
       | 0x3F0000;
}

