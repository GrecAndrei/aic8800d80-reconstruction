// sub_10D79C @ 0x10d79c, size 14 bytes
int  sub_10D79C(int result)
{
  while ( (*(uint32_t *)off_10D7AC & 0x80000) != 0 )
    ;
  *(uint32_t *)off_10D7B0 = result;
  return result;
}

