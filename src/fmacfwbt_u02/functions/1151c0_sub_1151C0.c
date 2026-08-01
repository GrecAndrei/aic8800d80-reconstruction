// get_hw_info_bit19 @ 0x1151c0, size 18 bytes
// Doc: patch_apply_n_317 [patch]: Applies firmware patch entry n317
// patch_apply_n_317 [patch]: Applies firmware patch entry n317
unsigned int get_hw_info_bit19()
{
  return ((unsigned int)MEMD(508)(15) >> 19) & 1;
}

