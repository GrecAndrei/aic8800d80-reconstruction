// patch_helper @ 0x114e6c, size 12 bytes
// Doc: patch_helper [patch]: Patch application helper
// patch_helper [patch]: Patch application helper
int __fastcall patch_helper(int result)
{
  if ( !result )
    *(_DWORD *)off_114E78 = 0x20000;
  return result;
}

