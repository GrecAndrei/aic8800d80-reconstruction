// v23 annotated: sdio_buffer_prepare_n_16c @ 0x12dfb0
// Original: 12dfb0_sdio_buffer_prepare_n_16c.c
// Primary struct: <unclustered>
//
// sdio_buffer_prepare_n_16c @ 0x12dfb0, size 30 bytes
// Doc: sdio_buf_align_or_mask [mac]: Align SDIO buffer address and check magic constant 0xfac12
// sdio_buf_align_or_mask [mac]: Align SDIO buffer address and check magic constant 0xfac12
int __fastcall sdio_buffer_prepare_n_16c(int a1, __int16 a2)
{
  return rf_bus_reset_n_32
       & ((((32 * (*(unsigned __int8 *)(a1 + 5) ^ (*(unsigned __int8 *)(a1 + 5) >> 4))) & 0x1E0) + (a2 & 0x1FF)) << 22)
       | 0x3F0000;
}

