// sub_101DA4 @ 0x101da4, size 58 bytes
int  sub_101DA4(int result)
{
  uint32_t *v1; // r2
  unsigned int v2; // r3
  int v3; // r3

  v1 = off_101DE4;
  *(uint32_t *)off_101DE0 = *(uint32_t *)off_101DE0 & 0xFFFFFF | ((unsigned __int8)(result / 2) << 24);
  v2 = *v1 & 0xFFFFF0FF;
  if ( (result & 1) != 0 )
  {
    if ( result >= 0 )
      v3 = v2 | 0xB00;
    else
      v3 = v2 | 0x500;
    *v1 = v3;
  }
  else
  {
    *v1 = v2 | 0x800;
  }
  return result;
}

