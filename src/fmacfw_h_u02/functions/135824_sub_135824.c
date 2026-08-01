// is_phy_ver_6 @ 0x135824, size 20 bytes
BOOL is_phy_ver_6()
{
  return hci_cmd_handler(6u) == 6;
}

