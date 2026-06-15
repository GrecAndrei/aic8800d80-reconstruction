// v23 annotated: lmac_init_wait_flag @ 0x1188c4
// Original: 1188c4_lmac_init_wait_flag.c
// Primary struct: group_11 (cluster 11)
//
// lmac_init_wait_flag @ 0x1188c4, size 42 bytes
// Doc: lmac_init_wait_flag [mac]: Polls a flag register and waits for it to become 1
// lmac_init_wait_flag [mac]: Polls a flag register and waits for it to become 1
int lmac_init_wait_flag()
{
  if ( sub_11E34C(0) == 1 )
    *(_DWORD *)off_1188F0 = 48;
  return sub_11E1E4(0);
}

