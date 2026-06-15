// v23 annotated: irq_enable @ 0x10dba4
// Original: 10dba4_irq_enable.c
// Primary struct: <unclustered>
//
// irq_enable @ 0x10dba4, size 16 bytes
// Doc: irq_enable [util]: Enables an interrupt by setting the corresponding bit in the IRQ enable register
// irq_enable [util]: Enables an interrupt by setting the corresponding bit in the IRQ enable register
int __fastcall irq_enable(char a1)
{
  int result; // r0

  result = (1 << a1) | *(_DWORD *)off_10DBB4;
  *(_DWORD *)off_10DBB4 = result;
  return result;
}

