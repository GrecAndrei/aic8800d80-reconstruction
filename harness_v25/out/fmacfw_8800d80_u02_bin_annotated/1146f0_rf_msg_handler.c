// fwstruct annotate: 1146f0_rf_msg_handler.c
// rf_msg_handler @ 0x1146f0, size 68 bytes
// Doc: nvic_irq_disable_n_2a [util]: Write to NVIC ISER/ICER (0xE000E100) to disable an interrupt
// nvic_irq_disable_n_2a [util]: Write to NVIC ISER/ICER (0xE000E100) to disable an interrupt
int rf_msg_handler()
{
  int v0; // r2
  int v1; // r1
  _DWORD *v2; // r3

  if ( *(_DWORD *)rf_fault_dump_loop_n_10 )
    v0 = 2048;
  else
    v0 = 4096;
  if ( *(_DWORD *)rf_fault_dump_loop_n_10 )
    v1 = 1;
  else
    v1 = 2;
  if ( *(_BYTE *)(*(_DWORD *)off_114734 + 6) == 1 )
    *((_DWORD *)off_11473C + 83) &= ~v1;
  v2 = off_114744;
  *(_DWORD *)(*(_DWORD *)rf_fault_dump_n_8 + 8) = 0;
  v2[34] = v0;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}

