// sub_11E0B4 @ 0x11e0b4, size 66 bytes
int  sub_11E0B4(int result)
{
  unsigned int v1; // r3
  unsigned int v2; // r2
  unsigned int v3; // r2

  v1 = *(uint32_t *)(result + 152);
  if ( *(uint8_t *)(result + 156) )
  {
    v3 = *(uint32_t *)off_11E0FC & 0x80000000;
    if ( v1 < (*(uint32_t *)off_11E0FC & 0x7FFFFFFFu) )
      v3 += 0x80000000;
    *(uint32_t *)off_11E0FC = v1 | v3;
  }
  else
  {
    v2 = *(uint32_t *)off_11E0F8 & 0x80000000;
    if ( v1 < (*(uint32_t *)off_11E0F8 & 0x7FFFFFFFu) )
      v2 += 0x80000000;
    *(uint32_t *)off_11E0F8 = v1 | v2;
  }
  return result;
}

