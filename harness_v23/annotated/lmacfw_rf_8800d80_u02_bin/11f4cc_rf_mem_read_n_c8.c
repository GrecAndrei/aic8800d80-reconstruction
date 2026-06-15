// v23 annotated: rf_mem_read_n_c8 @ 0x11f4cc
// Original: 11f4cc_rf_mem_read_n_c8.c
// Primary struct: delay_timer (cluster 0, 19 funcs)
// Fields: us=0x0, ticks=0x4
//
// rf_mem_read_n_c8 @ 0x11f4cc, size 6 bytes
// Doc: rf_mem_read_n_c8 [rf]: Read RF control field from memory-mapped register
// rf_mem_read_n_c8 [rf]: Read RF control field from memory-mapped register
int rf_mem_read_n_c8()
{
  return *((_DWORD *)rf_mem_read_f4d4 + 1);
}

