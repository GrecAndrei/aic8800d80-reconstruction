// radio_reg_config @ 0x137030, size 40 bytes
int radio_reg_config()
{
  int v0; // r0
  int v1; // r0

  v0 = tx_send_pdu(2051, 2, 4, 1u);
  rx_process_packet(v0);
  v1 = hci_cmd_handler(4u);
  check_feature_flag(8, dword_137058, v1);
  return 0;
}

