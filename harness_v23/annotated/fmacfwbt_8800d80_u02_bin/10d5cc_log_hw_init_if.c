// v23 annotated: log_hw_init_if @ 0x10d5cc
// Original: 10d5cc_log_hw_init_if.c
// Primary struct: <unclustered>
//
// log_hw_init_if @ 0x10d5cc, size 12 bytes
// Doc: log_hw_init_if [util]: Initialize logging hardware (NVIC IRQ enable)
// log_hw_init_if [util]: Initialize logging hardware (NVIC IRQ enable)
void log_hw_init_if()
{
  if ( !*(_DWORD *)off_10D5D8 )
    log_hw_init();
}

