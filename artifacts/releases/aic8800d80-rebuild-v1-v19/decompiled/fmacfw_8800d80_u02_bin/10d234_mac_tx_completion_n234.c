// mac_tx_completion_n234 @ 0x10d234, size 10 bytes
// Doc: mac_tx_completion_n234 [tx]: Handle TX frame completion event
// mac_tx_completion_n234 [tx]: Handle TX frame completion event
void mac_tx_completion_n234()
{
  *(_DWORD *)off_10D240 = 0x4000000;
}

