// sub_11E8B4 @ 0x11e8b4, size 40 bytes
// Doc: sdio_buffer_prepare_n_2f4_e8c0 [mmio]: Tail/epilogue of SDIO buffer prepare helper
// sdio_buffer_prepare_n_2f4_e8c0 [mmio]: Tail/epilogue of SDIO buffer prepare helper
unsigned int  sub_11E8B4(unsigned __int8 *a1, int a2, unsigned int a3)
{
  unsigned __int8 *v3; // r1
  int v4; // t1

  if ( !a2 )
    return a3;
  v3 = &a1[a2];
  do
  {
    v4 = *a1++;
    a3 = *(uint32_t *)(dword_11E8DC + 4 * (v4 ^ HIBYTE(a3))) ^ (a3 << 8);
  }
  while ( v3 != a1 );
  return a3;
}

