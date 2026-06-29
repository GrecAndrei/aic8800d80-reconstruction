// lmac_init_wait_flag @ 0x1188c4, size 42 bytes
// Doc: lmac_init_wait_flag [mac]: Polls a flag register and waits for it to become 1
// lmac_init_wait_flag [mac]: Polls a flag register and waits for it to become 1
int lmac_init_wait_flag()
{
  if ( sub_11E34C(0) == 1 )
    *(uint32_t *)off_1188F0 = 48;
  return sub_11E1E4(0);
}

