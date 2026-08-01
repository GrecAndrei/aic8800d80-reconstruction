// reset_hci_scratch @ 0x12f730, size 16 bytes
// Doc: reset_hci_scratch [util]: Initialize/zero a 8-byte buffer then return 0
// reset_hci_scratch [util]: Initialize/zero a 8-byte buffer then return 0
int reset_hci_scratch()
{
  memset_byte((int *)dword_12F740, 0, 8u);
  return 0;
}

