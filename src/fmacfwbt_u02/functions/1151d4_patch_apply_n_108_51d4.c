// get_hw_info_bit20 @ 0x1151d4, size 18 bytes
// Doc: patch_apply_n_30f [patch]: Apply patch and read MMIO status bit 20
// patch_apply_n_30f [patch]: Apply patch and read MMIO status bit 20
unsigned int get_hw_info_bit20()
{
  return ((unsigned int)MEMD(508)(15) >> 20) & 1;
}

