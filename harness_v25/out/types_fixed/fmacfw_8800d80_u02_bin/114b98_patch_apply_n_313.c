// patch_apply_n_313 @ 0x114b98, size 18 bytes
// Doc: patch_apply_4b9e [patch]: Apply firmware patch with id 0x1b/0x1fc
// patch_apply_4b9e [patch]: Apply firmware patch with id 0x1b/0x1fc
unsigned int patch_apply_n_313()
{
  return ((unsigned int)MEMORY[0x1FC](15) >> 20) & 1;
}

