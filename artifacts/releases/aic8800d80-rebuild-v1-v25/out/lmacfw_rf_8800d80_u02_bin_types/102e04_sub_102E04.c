// sub_102E04 @ 0x102e04, size 60 bytes
int  sub_102E04(int a1)
{
  uint64_t v1; // kr00_8
  int v2; // r4

  if ( a1 )
  {
    v1 = *(QWORD *)((char *)off_102E40 + 4);
    v2 = *(uint32_t *)off_102E40;
  }
  else
  {
    v2 = *(uint32_t *)off_102E44;
    v1 = *(QWORD *)((char *)off_102E44 + 4);
  }
  sub_102D4C(0, 32, 0x10u, SHIDWORD(v1));
  sub_102D4C(0, 48, 0x10u, v1);
  return sub_102D4C(0, 64, 0x10u, v2);
}

