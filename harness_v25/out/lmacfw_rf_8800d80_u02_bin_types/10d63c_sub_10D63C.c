// sub_10D63C @ 0x10d63c, size 14 bytes
int  sub_10D63C(int result)
{
  while ( (*(uint32_t *)off_10D64C & 0x80000) != 0 )
    ;
  *(uint32_t *)off_10D650 = result;
  return result;
}

