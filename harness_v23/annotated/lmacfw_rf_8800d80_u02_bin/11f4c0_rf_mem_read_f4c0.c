// v23 annotated: rf_mem_read_f4c0 @ 0x11f4c0
// Original: 11f4c0_rf_mem_read_f4c0.c
// Primary struct: delay_timer (cluster 0, 19 funcs)
// Fields: us=0x0, ticks=0x4
//
// rf_mem_read_f4c0 @ 0x11f4c0, size 6 bytes
// Doc: rf_mem_read_n_d2 [rf]: Reads value from RF memory region
// rf_mem_read_n_d2 [rf]: Reads value from RF memory region
int rf_mem_read_f4c0()
{
  return *(_DWORD *)rf_mem_write_short;
}

