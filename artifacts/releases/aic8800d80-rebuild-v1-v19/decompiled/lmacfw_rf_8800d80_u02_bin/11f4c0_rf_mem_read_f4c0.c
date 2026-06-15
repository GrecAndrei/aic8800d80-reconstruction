// rf_mem_read_f4c0 @ 0x11f4c0, size 6 bytes
// Doc: rf_mem_read_n_d2 [rf]: Reads value from RF memory region
// rf_mem_read_n_d2 [rf]: Reads value from RF memory region
int rf_mem_read_f4c0()
{
  return *(_DWORD *)rf_mem_write_short;
}

