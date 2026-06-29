// sub_101934 @ 0x101934, size 24 bytes
int  sub_101934(int result, int a2, int a3)
{
  if ( (*(uint32_t *)off_10194C & 8) != 0 )
  {
    result = sub_11ED58(result, a2, a3, *(uint32_t *)off_10194C << 28);
    *(uint32_t *)off_101950 = 8;
  }
  return result;
}

