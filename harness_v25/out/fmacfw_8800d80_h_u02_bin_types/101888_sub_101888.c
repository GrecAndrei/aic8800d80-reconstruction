// sub_101888 @ 0x101888, size 24 bytes
int  sub_101888(int result, int a2, int a3)
{
  if ( (*(uint32_t *)off_1018A0 & 8) != 0 )
  {
    result = sub_11EC18(result, a2, a3, *(uint32_t *)off_1018A0 << 28);
    *(uint32_t *)off_1018A4 = 8;
  }
  return result;
}

