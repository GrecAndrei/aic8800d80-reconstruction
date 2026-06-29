// sub_1247D8 @ 0x1247d8, size 168 bytes
// Doc: sub_12247D8 [unknown]: Branch on state value, push r3-r5/lr prologue
// sub_12247D8 [unknown]: Branch on state value, push r3-r5/lr prologue
int  sub_1247D8(int a1, int a2)
{
  int *v2; // r5
  int v3; // r0
  uint8_t *v4; // r3
  int *v5; // r4
  int v6; // r3
  int v7; // r2
  int v9; // r0
  uint8_t *v10; // r2

  if ( a1 > 1 )
  {
    v2 = (int *)off_124880;
    v3 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    v4 = off_124884;
    *v2 = v3;
    if ( *v4 == 1 )
    {
      v10 = off_12489C;
      *v4 = 0;
      *v10 = 0;
      event_queue_push(144, 0);
      *(uint32_t *)off_1248A0 = 0;
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_124888 = 1;
    }
    v5 = (int *)off_12488C;
    ++*(uint32_t *)off_12488C;
    message_dispatch_n2fe();
    rf_fault_dump_n_26c();
    mmio_init_clock_gate_n121();
    if ( *v5 )
    {
      v6 = *v5 - 1;
      v7 = *(uint32_t *)off_124888;
      *v5 = v6;
      if ( !v6 )
      {
        if ( v7 )
          __enable_irq();
      }
    }
    if ( *v2 )
    {
      *(uint32_t *)off_124894 = 2;
      sub_12466C();
      sub_12466C();
      v9 = *(uint32_t *)off_124890;
      if ( !*(uint32_t *)off_124890 )
        return 0;
      if ( *v2 )
      {
LABEL_15:
        rf_level_apply_n_4ec(v9);
        return 0;
      }
    }
    else if ( !*(uint32_t *)off_124890 )
    {
      return 0;
    }
    v9 = 0;
    goto LABEL_15;
  }
  msg_parse(dword_124898);
  return 1;
}

