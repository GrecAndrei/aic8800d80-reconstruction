// fw_init_post_handler @ 0x140d9c, size 36 bytes
// Doc: fw_init_post_handler [patch]: Posts init command 0xB to subsystem via mailbox call
// fw_init_post_handler [patch]: Posts init command 0xB to subsystem via mailbox call
int *fw_init_post_handler()
{
  int *v0; // r4
  int *result; // r0

  v0 = (int *)dword_140DC0;
  sub_12CD34(0xBu, 0);
  result = memset_thunk(v0, 0, 0x1960u);
  v0[1620] = -1;
  return result;
}

