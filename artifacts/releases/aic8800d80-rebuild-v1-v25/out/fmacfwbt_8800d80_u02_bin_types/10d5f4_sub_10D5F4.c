// sub_10D5F4 @ 0x10d5f4, size 14 bytes
int  sub_10D5F4(int result)
{
  while ( (*(uint32_t *)off_10D604 & 0x80000) != 0 )
    ;
  *(uint32_t *)off_10D608 = result;
  return result;
}

