// rf_state_check_21d4 @ 0x1121d4, size 66 bytes
// Doc: rf_bus_setup_n30a [rf]: Setup RF bus and return status flag
// rf_bus_setup_n30a [rf]: Setup RF bus and return status flag
int rf_state_check_21d4()
{
  uint8_t *v0; // r4
  int v1; // r0
  int ( *v3)(uint32_t); // r3

  v0 = rf_bus_init_n460;
  v1 = *((unsigned __int16 *)rf_bus_init_n460 + 7);
  *(uint16_t *)rf_bus_setup_n320_221c = v1;
  if ( v1 )
  {
    v3 = *((int ( **)(uint32_t))off_112224 + 5);
    if ( v3 && v3((unsigned __int8)v1) )
    {
      *(uint8_t *)off_112220 = 4;
      *v0 = 7;
      if ( !rf_msg_process_body_n_1bc() )
        sub_114168(0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(uint8_t *)off_112220 = 3;
    return 1;
  }
}

