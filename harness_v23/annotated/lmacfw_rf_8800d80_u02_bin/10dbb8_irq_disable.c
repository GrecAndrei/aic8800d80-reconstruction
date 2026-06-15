// v23 annotated: irq_disable @ 0x10dbb8
// Original: 10dbb8_irq_disable.c
// Primary struct: rf_subsys (cluster 9, 12 funcs)
// Fields: base=0x8, cfg=0xc
//
// irq_disable @ 0x10dbb8, size 18 bytes
// Doc: irq_disable [util]: Clear interrupt bit in NVIC/IRQ mask register
// irq_disable [util]: Clear interrupt bit in NVIC/IRQ mask register
int __fastcall irq_disable(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(_DWORD *)off_10DBCC &= ~result;
  return result;
}

