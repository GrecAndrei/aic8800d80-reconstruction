// v23 annotated: rf_init_handler_0 @ 0x122fa4
// Original: 122fa4_rf_init_handler_0.c
// Primary struct: <unclustered>
//
// rf_init_handler_0 @ 0x122fa4, size 104 bytes
// Doc: rf_init_handler [rf]: RF initialization handler calling chip setup routine
// rf_init_handler [rf]: RF initialization handler calling chip setup routine
unsigned int __fastcall rf_init_handler_0(int a1, int a2)
{
  unsigned int v4; // r0
  unsigned int v5; // r4

  v4 = sub_113B30();
  v5 = v4;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( v4 )
      {
        msg_parse(dword_123010);
      }
      else
      {
        msg_parse(dword_12301C, a2);
        rf_fault_dump_n_b2(__ROR4__(a2, 16));
        rf_cmd_status_get_n1c0();
      }
      return __ROR4__(rf_helper_sub_n_3b78(), 16);
    }
    else
    {
      msg_parse(dword_123018);
      return 0;
    }
  }
  else
  {
    if ( v4 )
    {
      v5 = __ROR4__(rf_helper_sub_n_3b78(), 16);
      msg_parse(dword_123014, v5);
    }
    else
    {
      msg_parse(dword_12300C);
    }
    return v5;
  }
}

