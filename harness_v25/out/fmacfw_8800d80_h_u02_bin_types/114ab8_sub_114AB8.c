// sub_114AB8 @ 0x114ab8, size 42 bytes
void sub_114AB8()
{
  int *v0; // r4

  v0 = (int *)off_114AE4;
  if ( !*(uint32_t *)off_114AE4 )
    *v0 = sub_114A78();
  if ( !*(uint32_t *)off_114AE8 )
    *(uint32_t *)off_114AE8 = *v0 + 67092480;
  *(uint32_t *)off_114AEC = 1;
}

