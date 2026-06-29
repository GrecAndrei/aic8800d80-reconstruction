// irq_disable @ 0x10dbb8, size 18 bytes
// Doc: irq_disable [util]: Clear interrupt bit in NVIC/IRQ mask register
// irq_disable [util]: Clear interrupt bit in NVIC/IRQ mask register
int  irq_disable(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(uint32_t *)off_10DBCC &= ~result;
  return result;
}

