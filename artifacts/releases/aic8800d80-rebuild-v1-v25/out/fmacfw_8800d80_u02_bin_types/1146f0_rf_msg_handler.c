// rf_msg_handler @ 0x1146f0, size 68 bytes
// Doc: nvic_irq_disable_n_2a [util]: Write to NVIC ISER/ICER (0xE000E100) to disable an interrupt
// nvic_irq_disable_n_2a [util]: Write to NVIC ISER/ICER (0xE000E100) to disable an interrupt
int rf_msg_handler()
{
  int v0; // r2
  int v1; // r1
  uint32_t *v2; // r3

  if ( *(uint32_t *)rf_fault_dump_loop_n_10 )
    v0 = 2048;
  else
    v0 = 4096;
  if ( *(uint32_t *)rf_fault_dump_loop_n_10 )
    v1 = 1;
  else
    v1 = 2;
  if ( *(uint8_t *)(*(uint32_t *)off_114734 + 6) == 1 )
    *((uint32_t *)off_11473C + 83) &= ~v1;
  v2 = off_114744;
  *(uint32_t *)(*(uint32_t *)rf_fault_dump_n_8 + 8) = 0;
  v2[34] = v0;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}

