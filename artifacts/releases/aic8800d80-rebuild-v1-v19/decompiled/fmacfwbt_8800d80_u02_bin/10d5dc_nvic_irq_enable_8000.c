// nvic_irq_enable_8000 @ 0x10d5dc, size 20 bytes
// Doc: nvic_irq_enable_8000 [util]: Set NVIC pending bit 0x8000 via ICSR write
// nvic_irq_enable_8000 [util]: Set NVIC pending bit 0x8000 via ICSR write
void nvic_irq_enable_8000()
{
  *((_DWORD *)off_10D5F0 + 32) = 0x8000;
  __dsb(0xFu);
  __isb(0xFu);
}

