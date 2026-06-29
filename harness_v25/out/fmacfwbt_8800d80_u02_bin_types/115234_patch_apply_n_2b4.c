// patch_apply_n_2b4 @ 0x115234, size 42 bytes
// Doc: patch_apply_n_2a2 [patch]: Write patch entry to MMIO base and flag completion
// patch_apply_n_2a2 [patch]: Write patch entry to MMIO base and flag completion
void patch_apply_n_2b4()
{
  int *v0; // r4

  v0 = (int *)patch_apply_n_288;
  if ( !*(uint32_t *)patch_apply_n_288 )
    *v0 = patch_apply_n_2f4();
  if ( !*(uint32_t *)off_115264 )
    *(uint32_t *)off_115264 = *v0 + 67092480;
  *(uint32_t *)off_115268 = 1;
}

