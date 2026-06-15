// v23 annotated: irq_event_handler @ 0x10dc90
// Original: 10dc90_irq_event_handler.c
// Primary struct: <unclustered>
//
// irq_event_handler @ 0x10dc90, size 78 bytes
// Doc: irq_event_handler [util]: IRQ event dispatch by sub-index
// irq_event_handler [util]: IRQ event dispatch by sub-index
int __fastcall irq_event_handler(int a1)
{
  int v1; // r4
  int result; // r0
  BOOL v3; // r4
  int v4; // r5

  v1 = BYTE2(a1);
  result = log_printf(dword_10DCE0, BYTE2(a1));
  if ( v1 == 3 )
  {
    v3 = sub_10DB84(3);
    if ( v3 )
    {
      v4 = 1;
    }
    else
    {
      if ( *((_BYTE *)off_10DCE4 + 369) )
        irq_enable(2);
      else
        sub_10DB6C(2);
      v4 = 2;
    }
    log_printf(dword_10DCE8, v3);
    return sub_10D204(v4);
  }
  return result;
}

