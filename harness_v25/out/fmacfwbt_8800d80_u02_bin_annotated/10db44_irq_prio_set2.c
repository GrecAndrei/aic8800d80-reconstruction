// fwstruct annotate: 10db44_irq_prio_set2.c
// irq_prio_set2 @ 0x10db44, size 16 bytes
// Doc: irq_prio_set2 [mmio]: Set NVIC IRQ enable bit in 0x40505000 ISER/ISPR register
// irq_prio_set2 [mmio]: Set NVIC IRQ enable bit in 0x40505000 ISER/ISPR register
int __fastcall irq_prio_set2(char a1)
{
  int result; // r0

  result = (1 << a1) | *((_DWORD *)off_10DB54 + 2);
  *((_DWORD *)off_10DB54 + 2) = result;
  return result;
}

