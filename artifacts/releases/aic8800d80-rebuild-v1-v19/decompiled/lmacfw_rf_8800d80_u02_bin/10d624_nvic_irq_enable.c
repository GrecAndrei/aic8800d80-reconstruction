// nvic_irq_enable @ 0x10d624, size 20 bytes
// Doc: nvic_irq_enable [util]: Enable NVIC interrupt 15 via ISER/ICER at 0xE000E100
// nvic_irq_enable [util]: Enable NVIC interrupt 15 via ISER/ICER at 0xE000E100
void nvic_irq_enable()
{
  *((_DWORD *)off_10D638 + 32) = 0x8000;
  __dsb(0xFu);
  __isb(0xFu);
}

