// sub_10D65C @ 0x10d65c, size 14 bytes
int  sub_10D65C(int result)
{
  while ( (*(uint32_t *)off_10D66C & 0x80000) != 0 )
    ;
  *(uint32_t *)off_10D670 = result;
  return result;
}

