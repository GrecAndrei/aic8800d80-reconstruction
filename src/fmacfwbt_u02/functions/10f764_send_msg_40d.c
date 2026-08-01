// send_cmd_040d @ 0x10f764, size 24 bytes
// Doc: send_cmd_040d [ipc]: Send IPC message id 0x40d with params to task
// send_cmd_040d [ipc]: Send IPC message id 0x40d with params to task
int send_cmd_040d()
{
  int v0; // r0

  v0 = bt_buf_alloc(1037, 1, 13, 8);
  return hci_evt_send(v0);
}

