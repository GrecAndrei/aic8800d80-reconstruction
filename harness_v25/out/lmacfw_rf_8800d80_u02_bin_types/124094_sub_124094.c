// sub_124094 @ 0x124094, size 18 bytes
int  sub_124094(int a1)
{
  *(uint32_t *)off_1240A8 = *(uint32_t *)off_1240A8 & 0xFFFFFDFF | (a1 << 9);
  return 0;
}

