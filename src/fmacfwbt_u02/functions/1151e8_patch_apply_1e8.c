// get_hw_info_1b @ 0x1151e8, size 10 bytes
// Doc: patch_apply_1ec [patch]: Apply firmware patch via indirect branch through table
// patch_apply_1ec [patch]: Apply firmware patch via indirect branch through table
int get_hw_info_1b()
{
  return MEMD(508)(27);
}

