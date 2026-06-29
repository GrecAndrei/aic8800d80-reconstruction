// rf_mem_read_n_c8 @ 0x11f4cc, size 6 bytes
// Doc: rf_mem_read_n_c8 [rf]: Read RF control field from memory-mapped register
// rf_mem_read_n_c8 [rf]: Read RF control field from memory-mapped register
int rf_mem_read_n_c8()
{
  return *((uint32_t *)rf_mem_read_f4d4 + 1);
}

