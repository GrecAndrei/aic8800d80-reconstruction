// sub_11EB48 @ 0x11eb48, size 38 bytes
// Doc: sdio_buffer_prepare_n_66 [mmio]: Prepares SDIO DMA buffer for host transfer
// sdio_buffer_prepare_n_66 [mmio]: Prepares SDIO DMA buffer for host transfer
unsigned int  sub_11EB48(unsigned __int8 *a1, int a2, unsigned int a3)
{
  unsigned __int8 *v3; // r4
  int v4; // t1

  if ( !a2 )
    return a3;
  v3 = &a1[a2];
  do
  {
    v4 = *a1++;
    a3 = *(uint32_t *)(dword_11EB70 + 4 * ((unsigned __int8)a3 ^ v4)) ^ (a3 >> 8);
  }
  while ( a1 != v3 );
  return a3;
}

