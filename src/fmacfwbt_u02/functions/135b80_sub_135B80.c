// is_pll_freq_6 @ 0x135b80, size 20 bytes
BOOL is_pll_freq_6()
{
  return hci_cmd_send_short(6u) == 6;
}

