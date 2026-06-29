// irq_enable @ 0x10db58, size 16 bytes
// Doc: irq_enable [util]: Enables IRQ handling for the firmware core
// irq_enable [util]: Enables IRQ handling for the firmware core
int  irq_enable(char a1)
{
  int result; // r0

  result = (1 << a1) | *(uint32_t *)off_10DB68;
  *(uint32_t *)off_10DB68 = result;
  return result;
}

