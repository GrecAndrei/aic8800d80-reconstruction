// fwstruct annotate: 118324_rf_chan_init_or_reset_n_324.c
// rf_chan_init_or_reset_n_324 @ 0x118324, size 26 bytes
// Doc: rf_chan_init_or_reset_n_324 [rf]: Initializes/resets an RF channel context structure
// rf_chan_init_or_reset_n_324 [rf]: Initializes/resets an RF channel context structure
int __fastcall rf_chan_init_or_reset_n_324(int a1)
{
  int result; // r0

  result = timestamp_remove(a1 + 48);
  if ( *(_DWORD *)(a1 + 72) )
    return rf_bus_reset2_c158(a1);
  return result;
}

