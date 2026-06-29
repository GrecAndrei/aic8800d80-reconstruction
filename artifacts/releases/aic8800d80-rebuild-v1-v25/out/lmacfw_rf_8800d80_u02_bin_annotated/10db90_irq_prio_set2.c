// fwstruct annotate: 10db90_irq_prio_set2.c
// irq_prio_set2 @ 0x10db90, size 16 bytes
// Doc: irq_prio_set2 [util]: Set IRQ priority bit in NVIC at 0x40505000+8
// irq_prio_set2 [util]: Set IRQ priority bit in NVIC at 0x40505000+8
int __fastcall irq_prio_set2(char a1)
{
  int result; // r0

  result = (1 << a1) | *((_DWORD *)off_10DBA0 + 2);
  *((_DWORD *)off_10DBA0 + 2) = result;
  return result;
}

