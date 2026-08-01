// sdio_set_blocksize @ 0x137274, size 40 bytes
int sdio_set_blocksize()
{
  int v0; // r0
  int value; // r0

  v0 = bt_buf_alloc(2051, 2, 4, 1u);
  hci_evt_send(v0);
  value = hci_cmd_send_short(4u);
  state_check_feature(8, dword_13729C, value);
  return 0;
}

