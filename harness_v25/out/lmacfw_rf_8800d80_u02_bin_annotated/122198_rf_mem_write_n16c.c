// fwstruct annotate: 122198_rf_mem_write_n16c.c
// rf_mem_write_n16c @ 0x122198, size 144 bytes
// Doc: rf_cmd_dispatch_n2ca [rf]: Dispatch RF command to handler
// rf_cmd_dispatch_n2ca [rf]: Dispatch RF command to handler
int __fastcall rf_mem_write_n16c(int a1, int a2)
{
  int v4; // r0
  unsigned __int16 v6; // r0
  int f4c0; // r0
  int v8; // r4

  v4 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = parse_int(*(unsigned __int8 **)(a2 + 8), nullptr, 0x10u);
      **(_WORD **)off_12222C = v6;
      msg_parse(dword_122230, v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        msg_parse(dword_122228);
        return 0;
      }
      v8 = parse_int(*(unsigned __int8 **)(a2 + 8), nullptr, 0x10u);
      msg_parse(dword_122240, v8);
      rf_mem_read_n_ec(v8);
      return 0;
    }
    else
    {
      msg_parse(dword_12223C, v4);
      return 0;
    }
  }
  else
  {
    msg_parse(dword_122234, **(unsigned __int16 **)off_12222C);
    f4c0 = rf_mem_read_f4c0();
    msg_parse(dword_122238, f4c0);
    return 0;
  }
}

