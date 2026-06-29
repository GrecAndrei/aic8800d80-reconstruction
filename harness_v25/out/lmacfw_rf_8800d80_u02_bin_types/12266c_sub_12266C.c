// sub_12266C @ 0x12266c, size 22 bytes
int  sub_12266C(int a1)
{
  int result; // r0

  result = *(uint32_t *)off_122684 + 1000 * a1;
  while ( *(uint32_t *)off_122684 - result < 0 )
    ;
  return result;
}

