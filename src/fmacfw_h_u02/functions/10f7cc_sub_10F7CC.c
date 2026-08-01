// ipc_send_command @ 0x10f7cc, size 24 bytes
int ipc_send_command()
{
  int v0; // r0

  v0 = tx_send_pdu(1037, 1, 13, 8);
  return rx_process_packet(v0);
}

