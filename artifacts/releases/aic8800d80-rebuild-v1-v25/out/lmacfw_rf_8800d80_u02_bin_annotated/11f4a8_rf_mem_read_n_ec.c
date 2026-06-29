// fwstruct annotate: 11f4a8_rf_mem_read_n_ec.c
// rf_mem_read_n_ec @ 0x11f4a8, size 6 bytes
// Doc: rf_mem_read_n_ec [rf]: Read RF memory and store to shared pointer
// rf_mem_read_n_ec [rf]: Read RF memory and store to shared pointer
int __fastcall rf_mem_read_n_ec(int result)
{
  *(_DWORD *)rf_mem_read_n_e4 = result;
  return result;
}

