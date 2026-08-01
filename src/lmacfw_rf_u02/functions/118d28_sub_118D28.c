// enable_irq_2000000 @ 0x118d28, size 22 bytes
int enable_irq_2000000()
{
  enter_critical_section(0x2000000);
  return flash_erase_sector(0);
}

