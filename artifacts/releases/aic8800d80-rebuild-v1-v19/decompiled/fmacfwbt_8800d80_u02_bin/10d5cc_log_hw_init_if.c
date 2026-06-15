// log_hw_init_if @ 0x10d5cc, size 12 bytes
// Doc: log_hw_init_if [util]: Initialize logging hardware (NVIC IRQ enable)
// log_hw_init_if [util]: Initialize logging hardware (NVIC IRQ enable)
void log_hw_init_if()
{
  if ( !*(_DWORD *)off_10D5D8 )
    log_hw_init();
}

