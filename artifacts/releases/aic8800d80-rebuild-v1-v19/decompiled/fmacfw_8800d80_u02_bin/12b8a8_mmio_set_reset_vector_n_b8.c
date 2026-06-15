// mmio_set_reset_vector_n_b8 @ 0x12b8a8, size 16 bytes
// Doc: mmio_set_reset_vector_n_b8 [mmio]: Write 0x40328050 to MMIO control register and return
// mmio_set_reset_vector_n_b8 [mmio]: Write 0x40328050 to MMIO control register and return
void mmio_set_reset_vector_n_b8()
{
  _DWORD *v0; // r2

  v0 = off_12B8B8;
  *(_DWORD *)off_12B8B8 = 1;
  while ( (unsigned __int8)*v0 )
    ;
}

