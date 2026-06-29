// sub_114114 @ 0x114114, size 64 bytes
int sub_114114()
{
  int v0; // r0
  uint32_t *v1; // r4
  int result; // r0

  v0 = (*(int ( **)(uint32_t))(*((uint32_t *)off_114154 + 2) + 16))(*((uint32_t *)off_114154 + 1));
  if ( !v0 )
    return sub_10DC24(dword_114160);
  v1 = (uint32_t *)v0;
  result = sub_113350(*(uint32_t *)off_114158 + v0, *(uint32_t *)off_11415C);
  if ( result < 0 )
  {
    sub_110008(v1);
    return sub_10DC24(dword_114164);
  }
  return result;
}

