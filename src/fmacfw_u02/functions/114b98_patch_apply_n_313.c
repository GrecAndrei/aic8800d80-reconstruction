// get_hook_bit_20 @ 0x114b98, size 18 bytes
// Doc: patch_apply_4b9e [patch]: Apply firmware patch with id 0x1b/0x1fc
// patch_apply_4b9e [patch]: Apply firmware patch with id 0x1b/0x1fc
unsigned int get_hook_bit_20()
{
  return ((unsigned int)MEMD(508)(15) >> 20) & 1;
}

