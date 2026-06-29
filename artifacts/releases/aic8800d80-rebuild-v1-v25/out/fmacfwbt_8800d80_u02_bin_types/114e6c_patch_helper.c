// patch_helper @ 0x114e6c, size 12 bytes
// Doc: patch_helper [patch]: Patch application helper
// patch_helper [patch]: Patch application helper
int  patch_helper(int result)
{
  if ( !result )
    *(uint32_t *)off_114E78 = 0x20000;
  return result;
}

