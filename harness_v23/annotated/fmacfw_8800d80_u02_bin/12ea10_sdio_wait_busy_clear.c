// v23 annotated: sdio_wait_busy_clear @ 0x12ea10
// Original: 12ea10_sdio_wait_busy_clear.c
// Primary struct: <unclustered>
//
// sdio_wait_busy_clear @ 0x12ea10, size 24 bytes
// Doc: sdio_wait_busy_clear [mmio]: Polls SDIO status register until busy flag clears
// sdio_wait_busy_clear [mmio]: Polls SDIO status register until busy flag clears
void sdio_wait_busy_clear()
{
  while ( (*(_DWORD *)off_12EA28 & 0x40000) == 0 )
    ;
}

