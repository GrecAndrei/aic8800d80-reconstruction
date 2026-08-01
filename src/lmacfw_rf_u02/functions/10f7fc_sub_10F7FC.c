// ipc_send_0x40d @ 0x10f7fc, size 24 bytes
// Doc: ipc_send_0x40d [unknown]: Unknown helper in lmacfw RF image
// ipc_send_0x40d [unknown]: Unknown helper in lmacfw RF image
int ipc_send_0x40d()
{
  int v0; // r0

  v0 = ke_msg_send(1037, 1, 4, 8);
  return rx_irq_handler(v0);
}

