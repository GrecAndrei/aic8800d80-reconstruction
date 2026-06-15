// patch_apply_n_108_51d4 @ 0x1151d4, size 18 bytes
// Doc: patch_apply_n_30f [patch]: Apply patch and read MMIO status bit 20
// patch_apply_n_30f [patch]: Apply patch and read MMIO status bit 20
unsigned int patch_apply_n_108_51d4()
{
  return ((unsigned int)MEMORY[0x1FC](15) >> 20) & 1;
}

