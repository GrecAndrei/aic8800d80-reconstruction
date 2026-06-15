// v23 annotated: patch_apply_n_390 @ 0x115158
// Original: 115158_patch_apply_n_390.c
// Primary struct: <unclustered>
//
// patch_apply_n_390 @ 0x115158, size 18 bytes
// Doc: patch_apply_n_38e [patch]: Apply firmware patch and extract 3-bit field from result
// patch_apply_n_38e [patch]: Apply firmware patch and extract 3-bit field from result
unsigned int patch_apply_n_390()
{
  return ((unsigned int)MEMORY[0x1FC](17) >> 3) & 7;
}

