// fwstruct annotate: 123920_fmac_send_command_n3920.c
// fmac_send_command_n3920 @ 0x123920, size 40 bytes
// Doc: fmac_send_command_n3920 [mac]: Prepare and send FMAC command, returns status
// fmac_send_command_n3920 [mac]: Prepare and send FMAC command, returns status
int __fastcall fmac_send_command_n3920(int a1, int a2, int a3, int a4)
{
  mem_block_free_n_490(a2);
  feature_guard_check(256, dword_123948);
  sub_12CA10(108, a4, a3);
  return 0;
}

