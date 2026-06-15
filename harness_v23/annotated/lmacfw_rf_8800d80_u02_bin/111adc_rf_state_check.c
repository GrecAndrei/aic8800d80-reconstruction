// v23 annotated: rf_state_check @ 0x111adc
// Original: 111adc_rf_state_check.c
// Primary struct: group_13 (cluster 13)
//
// rf_state_check @ 0x111adc, size 66 bytes
// Doc: rf_bus_setup_n30e [rf]: RF bus register setup for N30E
// rf_bus_setup_n30e [rf]: RF bus register setup for N30E
int rf_state_check()
{
  _BYTE *v0; // r4
  int v1; // r0
  int (__fastcall *v3)(_DWORD); // r3

  v0 = off_111B20;
  v1 = *((unsigned __int16 *)off_111B20 + 7);
  *(_WORD *)rf_bus_setup_n320 = v1;
  if ( v1 )
  {
    v3 = *((int (__fastcall **)(_DWORD))rf_bus_setup_n328 + 5);
    if ( v3 && v3((unsigned __int8)v1) )
    {
      *(_BYTE *)rf_bus_setup_n324 = 4;
      *v0 = 7;
      if ( !fw_flag_is_set() )
        rf_chan_set_mask(0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(_BYTE *)rf_bus_setup_n324 = 3;
    return 1;
  }
}

