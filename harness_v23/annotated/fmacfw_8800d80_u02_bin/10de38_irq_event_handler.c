// v23 annotated: irq_event_handler @ 0x10de38
// Original: 10de38_irq_event_handler.c
// Primary struct: <unclustered>
//
// irq_event_handler @ 0x10de38, size 78 bytes
// Doc: irq_event_handler [util]: IRQ event handler extracting source bits and dispatching to ISR
// irq_event_handler [util]: IRQ event handler extracting source bits and dispatching to ISR
int __fastcall irq_event_handler(int a1)
{
  int v1; // r4
  int result; // r0
  BOOL v3; // r4
  int v4; // r5

  v1 = BYTE2(a1);
  result = sub_10DC24(dword_10DE88, BYTE2(a1));
  if ( v1 == 3 )
  {
    v3 = sub_10DD2C(3);
    if ( v3 )
    {
      v4 = 1;
    }
    else
    {
      if ( *((_BYTE *)off_10DE8C + 369) )
        rf_mem_read_n47e(2);
      else
        sub_10DD14(2);
      v4 = 2;
    }
    sub_10DC24(dword_10DE90, v3);
    return irq_event_set(v4);
  }
  return result;
}

