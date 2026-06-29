// sdio_wait_busy @ 0x12ec38, size 24 bytes
// Doc: sdio_wait_busy [mmio]: Polls SDIO host controller busy flag until clear
// sdio_wait_busy [mmio]: Polls SDIO host controller busy flag until clear
void sdio_wait_busy()
{
  while ( (*(uint32_t *)off_12EC50 & 0x40000) == 0 )
    ;
}

