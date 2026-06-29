// fwstruct annotate: 1121d4_rf_state_check_21d4.c
// rf_state_check_21d4 @ 0x1121d4, size 66 bytes
// Doc: rf_bus_setup_n30a [rf]: Setup RF bus and return status flag
// rf_bus_setup_n30a [rf]: Setup RF bus and return status flag
int rf_state_check_21d4()
{
  _BYTE *v0; // r4
  int v1; // r0
  int (__fastcall *v3)(_DWORD); // r3

  v0 = rf_bus_init_n460;
  v1 = *((unsigned __int16 *)rf_bus_init_n460 + 7);
  *(_WORD *)rf_bus_setup_n320_221c = v1;
  if ( v1 )
  {
    v3 = *((int (__fastcall **)(_DWORD))off_112224 + 5);
    if ( v3 && v3((unsigned __int8)v1) )
    {
      *(_BYTE *)off_112220 = 4;
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
    *(_BYTE *)off_112220 = 3;
    return 1;
  }
}

