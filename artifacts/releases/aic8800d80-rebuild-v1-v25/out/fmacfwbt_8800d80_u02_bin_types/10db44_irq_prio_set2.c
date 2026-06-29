// irq_prio_set2 @ 0x10db44, size 16 bytes
// Doc: irq_prio_set2 [mmio]: Set NVIC IRQ enable bit in 0x40505000 ISER/ISPR register
// irq_prio_set2 [mmio]: Set NVIC IRQ enable bit in 0x40505000 ISER/ISPR register
int  irq_prio_set2(char a1)
{
  int result; // r0

  result = (1 << a1) | *((uint32_t *)off_10DB54 + 2);
  *((uint32_t *)off_10DB54 + 2) = result;
  return result;
}

