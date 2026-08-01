// clear_shared_mem @ 0x137490, size 26 bytes
int *clear_shared_mem()
{
  hci_cmd_preprocess(4u, 0);
  return sub_100200((int *)dword_1374AC, 0, 0xFC0u);
}

