// dma_tx_reset @ 0x140e38, size 36 bytes
// Doc: dma_tx_reset [bt]: Init BT subsystem: load 0x198000, call 0x12cf5c with id 0xb, init 0x1960 region
// dma_tx_reset [bt]: Init BT subsystem: load 0x198000, call 0x12cf5c with id 0xb, init 0x1960 region
int *dma_tx_reset()
{
  int *v0; // r4
  int *result; // r0

  v0 = (int *)dword_140E5C;
  hci_cmd_send(0xBu, 0);
  result = memset_byte(v0, 0, 0x1960u);
  v0[1620] = -1;
  return result;
}

