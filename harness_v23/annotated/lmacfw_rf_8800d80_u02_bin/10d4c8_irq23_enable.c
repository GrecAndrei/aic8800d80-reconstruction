// v23 annotated: irq23_enable @ 0x10d4c8
// Original: 10d4c8_irq23_enable.c
// Primary struct: <unclustered>
//
// irq23_enable @ 0x10d4c8, size 20 bytes
// Doc: irq23_enable [mmio]: Enable IRQ line 23 in interrupt controller
// irq23_enable [mmio]: Enable IRQ line 23 in interrupt controller
void irq23_enable()
{
  _DWORD *v0; // r3

  v0 = off_10D4E0;
  *(_DWORD *)(*((_DWORD *)off_10D4DC + 2) + 148) = off_10D4E4;
  *v0 = 0x200000;
}

