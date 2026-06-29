// patch_apply_n_16c @ 0x114d40, size 10 bytes
// Doc: patch_apply_n_16c [patch]: Apply N NOP-aligned patch entries (count=0x14)
// patch_apply_n_16c [patch]: Apply N NOP-aligned patch entries (count=0x14)
int  patch_apply_n_16c(int a1)
{
  return rf_fault_dump_n4e8(2, a1, 0xCu);
}

