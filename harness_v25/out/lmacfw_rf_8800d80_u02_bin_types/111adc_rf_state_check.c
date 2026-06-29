// rf_state_check @ 0x111adc, size 66 bytes
// Doc: rf_bus_setup_n30e [rf]: RF bus register setup for N30E
// rf_bus_setup_n30e [rf]: RF bus register setup for N30E
int rf_state_check()
{
  uint8_t *v0; // r4
  int v1; // r0
  int ( *v3)(uint32_t); // r3

  v0 = off_111B20;
  v1 = *((unsigned __int16 *)off_111B20 + 7);
  *(uint16_t *)rf_bus_setup_n320 = v1;
  if ( v1 )
  {
    v3 = *((int ( **)(uint32_t))rf_bus_setup_n328 + 5);
    if ( v3 && v3((unsigned __int8)v1) )
    {
      *(uint8_t *)rf_bus_setup_n324 = 4;
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
    *(uint8_t *)rf_bus_setup_n324 = 3;
    return 1;
  }
}

