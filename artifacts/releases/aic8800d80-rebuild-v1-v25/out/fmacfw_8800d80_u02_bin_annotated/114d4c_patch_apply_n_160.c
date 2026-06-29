// fwstruct annotate: 114d4c_patch_apply_n_160.c
// patch_apply_n_160 @ 0x114d4c, size 10 bytes
// Doc: patch_apply_n_160 [patch]: Apply firmware patch entry (variant n_160)
// patch_apply_n_160 [patch]: Apply firmware patch entry (variant n_160)
int __fastcall patch_apply_n_160(int a1)
{
  return rf_fault_dump_n4e8(4, a1, 0x14u);
}

