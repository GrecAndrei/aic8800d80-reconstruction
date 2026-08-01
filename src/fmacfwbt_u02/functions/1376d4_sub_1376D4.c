// dma_rx_reset @ 0x1376d4, size 26 bytes
int *dma_rx_reset()
{
  hci_cmd_send(4u, 0);
  return memset_byte((int *)dword_1376F0, 0, 0xFC0u);
}

