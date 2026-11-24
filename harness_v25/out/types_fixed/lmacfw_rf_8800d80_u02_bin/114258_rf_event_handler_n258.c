// rf_event_handler_n258 @ 0x114258, size 54 bytes
// Doc: rf_event_handler_n258 [rf]: RF event/IRQ dispatch handler, lmacfw rf context
// rf_event_handler_n258 [rf]: RF event/IRQ dispatch handler, lmacfw rf context
int rf_event_handler_n258()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_114290 = 1;
  }
  v0 = (int *)off_114294;
  ++*(_DWORD *)off_114294;
  result = MEMORY[0x1D0]();
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(_DWORD *)off_114290;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}

