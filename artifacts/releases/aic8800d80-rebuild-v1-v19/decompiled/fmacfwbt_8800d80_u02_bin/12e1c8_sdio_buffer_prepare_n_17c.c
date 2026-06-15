// sdio_buffer_prepare_n_17c @ 0x12e1c8, size 14 bytes
// Doc: sdio_buffer_prepare_n_17c [mac]: SDIO buffer prep extracting flags from word at offset 4-5
// sdio_buffer_prepare_n_17c [mac]: SDIO buffer prep extracting flags from word at offset 4-5
int __fastcall sdio_buffer_prepare_n_17c(int a1)
{
  return ((2 * *(unsigned __int8 *)(a1 + 5)) | (*(unsigned __int8 *)(a1 + 4) >> 7)) << 22;
}

