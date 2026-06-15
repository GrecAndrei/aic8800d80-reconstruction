// rf_misc_init_n_xxx @ 0x12141c, size 14 bytes
// Doc: rf_misc_init_n_xxx [rf]: Initialize RF misc control register at 0x40320038 with value 0x30
// rf_misc_init_n_xxx [rf]: Initialize RF misc control register at 0x40320038 with value 0x30
int rf_misc_init_n_xxx()
{
  *(_DWORD *)off_12142C = 48;
  return rf_bus_mark_n_3b7(0);
}

