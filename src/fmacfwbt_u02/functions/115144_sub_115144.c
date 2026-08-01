// get_hw_info_field0 @ 0x115144, size 18 bytes
// Doc: patch_apply_n_39c [patch]: Apply firmware patch entry
// patch_apply_n_39c [patch]: Apply firmware patch entry
int get_hw_info_field0()
{
  return MEMD(508)(17) & 7;
}

