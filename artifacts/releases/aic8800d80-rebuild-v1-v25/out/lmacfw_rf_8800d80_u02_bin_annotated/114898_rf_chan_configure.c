// fwstruct annotate: 114898_rf_chan_configure.c
// rf_chan_configure @ 0x114898, size 96 bytes
// Doc: rf_chan_configure [rf]: Configure RF channel/parameters from global state
// rf_chan_configure [rf]: Configure RF channel/parameters from global state
int __fastcall rf_chan_configure(int a1, int a2, unsigned int a3)
{
  int v6; // r4
  _DWORD v8[4]; // [sp+0h] [bp-50h] BYREF
  _BYTE v9[64]; // [sp+10h] [bp-40h] BYREF

  if ( !*(_DWORD *)off_1148F8 )
    lmac_state_get_n_e0();
  MEMORY[0x1D8](*(_DWORD *)off_1148FC, 80, v8);
  if ( v8[0] != dword_114900 )
    return -1;
  v6 = a1 & v8[1];
  if ( !v6 )
    return 1;
  if ( (v6 & 1) != 0 )
  {
    sub_1282E8(a2, v9, 64);
    if ( a3 <= 0x3F )
      return -2;
  }
  return 0;
}

