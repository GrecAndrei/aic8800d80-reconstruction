// sub_126D60 @ 0x126d60, size 52 bytes
int  sub_126D60(int a1)
{
  void *v1; // r1
  unsigned int *v2; // r2
  int v3; // r3
  int v4; // r0
  unsigned int v5; // r3

  v1 = off_126D94;
  v2 = (unsigned int *)off_126D98;
  v3 = *(uint32_t *)off_126D94;
  if ( a1 )
  {
    *(uint32_t *)off_126D94 = v3 | 0x10000;
    v4 = dword_126D9C;
    v5 = *v2 & 0xFF87FFFF | 0x700000;
  }
  else
  {
    *(uint32_t *)off_126D94 = v3 & 0xFFFEFFFF;
    v4 = dword_126DA0;
    v5 = *v2 & 0xFF87FFFF;
  }
  *v2 = v5;
  return sub_11F504(v4, v1, v2, v5);
}

