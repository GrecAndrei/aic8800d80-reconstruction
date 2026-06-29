// sub_1136A4 @ 0x1136a4, size 14 bytes
int  sub_1136A4(unsigned int a1)
{
  if ( a1 > 7 )
    return 0;
  else
    return *(uint32_t *)(dword_1136B4 + 4 * a1);
}

