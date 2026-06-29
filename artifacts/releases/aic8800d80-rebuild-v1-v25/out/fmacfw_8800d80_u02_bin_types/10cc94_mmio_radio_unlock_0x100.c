// mmio_radio_unlock_0x100 @ 0x10cc94, size 10 bytes
// Doc: mmio_radio_unlock_0x100 [mmio]: Write magic 0x100 to radio MMIO 0x40035100 to unlock/unblock
// mmio_radio_unlock_0x100 [mmio]: Write magic 0x100 to radio MMIO 0x40035100 to unlock/unblock
void mmio_radio_unlock_0x100()
{
  *(uint32_t *)off_10CCA0 = 256;
}

