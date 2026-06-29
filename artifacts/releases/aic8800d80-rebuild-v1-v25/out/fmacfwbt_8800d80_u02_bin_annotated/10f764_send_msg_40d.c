// fwstruct annotate: 10f764_send_msg_40d.c
// send_msg_40d @ 0x10f764, size 24 bytes
// Doc: send_msg_40d [ipc]: Send IPC message id 0x40d with params to task
// send_msg_40d [ipc]: Send IPC message id 0x40d with params to task
int send_msg_40d()
{
  int v0; // r0

  v0 = rf_bus_setup_n3a8(1037, 1, 13, 8);
  return sub_12CBB4(v0);
}

