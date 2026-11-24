// irq23_enable_d628 @ 0x10d628, size 20 bytes
// Doc: irq23_enable_d628 [mmio]: Set pending bit 0x200000 in NVIC ISER to enable IRQ23
// irq23_enable_d628 [mmio]: Set pending bit 0x200000 in NVIC ISER to enable IRQ23
void irq23_enable_d628()
{
  _DWORD *v0; // r3

  v0 = off_10D640;
  *(_DWORD *)(*((_DWORD *)off_10D63C + 2) + 148) = dword_10D644;
  *v0 = 0x200000;
}

