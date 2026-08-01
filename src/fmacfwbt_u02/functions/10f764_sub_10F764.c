// send_cmd_040d @ 0x10f764, size 24 bytes
int send_cmd_040d()
{
  int v0; // r0

  v0 = bt_buf_alloc(1037, 1, 13, 8);
  return hci_evt_send(v0);
}

