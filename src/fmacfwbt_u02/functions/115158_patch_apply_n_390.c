// get_hw_info_field1 @ 0x115158, size 18 bytes
// Doc: patch_apply_n_38e [patch]: Apply firmware patch and extract 3-bit field from result
// patch_apply_n_38e [patch]: Apply firmware patch and extract 3-bit field from result
unsigned int get_hw_info_field1()
{
  return ((unsigned int)MEMD(508)(17) >> 3) & 7;
}

