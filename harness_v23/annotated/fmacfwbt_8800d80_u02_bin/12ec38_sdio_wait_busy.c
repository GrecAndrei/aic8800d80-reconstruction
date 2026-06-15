// v23 annotated: sdio_wait_busy @ 0x12ec38
// Original: 12ec38_sdio_wait_busy.c
// Primary struct: delay_timer (cluster 0, 25 funcs)
// Fields: us=0x0, ticks=0x4
//
// sdio_wait_busy @ 0x12ec38, size 24 bytes
// Doc: sdio_wait_busy [mmio]: Polls SDIO host controller busy flag until clear
// sdio_wait_busy [mmio]: Polls SDIO host controller busy flag until clear
void sdio_wait_busy()
{
  while ( (*(_DWORD *)off_12EC50 & 0x40000) == 0 )
    ;
}

