// fwstruct annotate: 10db58_irq_enable.c
// irq_enable @ 0x10db58, size 16 bytes
// Doc: irq_enable [util]: Enables IRQ handling for the firmware core
// irq_enable [util]: Enables IRQ handling for the firmware core
int __fastcall irq_enable(char a1)
{
  int result; // r0

  result = (1 << a1) | *(_DWORD *)off_10DB68;
  *(_DWORD *)off_10DB68 = result;
  return result;
}

