// reset_bt_env @ 0x125958, size 58 bytes
// Doc: reset_bt_env [util]: Initialize control structure via memset then call sub-init helper
// reset_bt_env [util]: Initialize control structure via memset then call sub-init helper
int reset_bt_env()
{
  int v0; // r5
  int v1; // r4

  v0 = dword_125994;
  v1 = dword_125998;
  memset_byte((int *)dword_125994, 0, 0x18u);
  zero_struct(v0 + 12);
  bt_hci_fill_cmd(v1);
  bt_hci_fill_cmd(v1 + 38);
  bt_hci_fill_cmd(v1 + 76);
  return bt_hci_fill_cmd(v1 + 114);
}

