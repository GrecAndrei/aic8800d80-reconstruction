// clear_tx_buf @ 0x140c5c, size 36 bytes
int *clear_tx_buf()
{
  int *v0; // r4
  int *result; // r0

  v0 = (int *)dword_140C80;
  hci_cmd_preprocess(0xBu, 0);
  result = sub_100200(v0, 0, 0x1960u);
  v0[1620] = -1;
  return result;
}

