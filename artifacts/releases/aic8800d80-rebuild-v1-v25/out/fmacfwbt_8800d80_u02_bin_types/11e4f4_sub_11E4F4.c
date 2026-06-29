// sub_11E4F4 @ 0x11e4f4, size 66 bytes
int  sub_11E4F4(int result)
{
  unsigned int v1; // r3
  unsigned int v2; // r2
  unsigned int v3; // r2

  v1 = *(uint32_t *)(result + 152);
  if ( *(uint8_t *)(result + 156) )
  {
    v3 = *(uint32_t *)off_11E53C & 0x80000000;
    if ( v1 < (*(uint32_t *)off_11E53C & 0x7FFFFFFFu) )
      v3 += 0x80000000;
    *(uint32_t *)off_11E53C = v1 | v3;
  }
  else
  {
    v2 = *(uint32_t *)off_11E538 & 0x80000000;
    if ( v1 < (*(uint32_t *)off_11E538 & 0x7FFFFFFFu) )
      v2 += 0x80000000;
    *(uint32_t *)off_11E538 = v1 | v2;
  }
  return result;
}

