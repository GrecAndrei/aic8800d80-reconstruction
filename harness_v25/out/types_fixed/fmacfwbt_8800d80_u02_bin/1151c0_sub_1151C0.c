// sub_1151C0 @ 0x1151c0, size 18 bytes
// Doc: patch_apply_n_317 [patch]: Applies firmware patch entry n317
// patch_apply_n_317 [patch]: Applies firmware patch entry n317
unsigned int sub_1151C0()
{
  return ((unsigned int)MEMORY[0x1FC](15) >> 19) & 1;
}

