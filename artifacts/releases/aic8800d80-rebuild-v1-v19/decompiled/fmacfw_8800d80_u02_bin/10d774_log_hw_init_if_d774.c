// log_hw_init_if_d774 @ 0x10d774, size 12 bytes
// Doc: log_hw_init_if_d774 [util]: Initializes hardware log interface via NVIC (0xe000e100)
// log_hw_init_if_d774 [util]: Initializes hardware log interface via NVIC (0xe000e100)
void log_hw_init_if_d774()
{
  if ( !*(_DWORD *)off_10D780 )
    log_hw_init_d648();
}

