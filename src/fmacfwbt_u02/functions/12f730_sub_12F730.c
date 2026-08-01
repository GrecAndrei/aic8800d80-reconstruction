// reset_hci_scratch @ 0x12f730, size 16 bytes
int reset_hci_scratch()
{
  memset_byte((int *)dword_12F740, 0, 8u);
  return 0;
}

