// is_pll_freq_6 @ 0x135b80, size 20 bytes
// Doc: is_pll_freq_6 [util]: Read register and return bit status via clz
// is_pll_freq_6 [util]: Read register and return bit status via clz
BOOL is_pll_freq_6()
{
  return hci_cmd_send_short(6u) == 6;
}

