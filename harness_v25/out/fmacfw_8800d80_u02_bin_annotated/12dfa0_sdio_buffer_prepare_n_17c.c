// fwstruct annotate: 12dfa0_sdio_buffer_prepare_n_17c.c
// sdio_buffer_prepare_n_17c @ 0x12dfa0, size 14 bytes
// Doc: sdio_buffer_prepare_n_17c [mmio]: Compute SDIO buffer pointer by combining two byte fields with bit-or and shift
// sdio_buffer_prepare_n_17c [mmio]: Compute SDIO buffer pointer by combining two byte fields with bit-or and shift
int __fastcall sdio_buffer_prepare_n_17c(int a1)
{
  return ((2 * *(unsigned __int8 *)(a1 + 5)) | (*(unsigned __int8 *)(a1 + 4) >> 7)) << 22;
}

