// patch_apply_n422 @ 0x1100d4, size 52 bytes
// Doc: patch_apply_n422 [patch]: Applies a firmware patch table entry
// patch_apply_n422 [patch]: Applies a firmware patch table entry
int patch_apply_n422()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_110108;
  result = sub_11E71C(dword_11010C);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 2) )
  {
    v2 = dword_110110;
    v3 = dword_11010C;
    v4 = 0;
    do
    {
      log_pool_alloc2_a18(v2, 0xCu);
      result = list_push_tail(v3);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(uint32_t *)v0 + 2) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

