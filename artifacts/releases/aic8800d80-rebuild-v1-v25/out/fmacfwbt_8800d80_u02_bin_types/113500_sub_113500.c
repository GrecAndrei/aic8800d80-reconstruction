// sub_113500 @ 0x113500, size 14 bytes
int  sub_113500(unsigned int a1)
{
  if ( a1 > 7 )
    return 0;
  else
    return *(uint32_t *)(dword_113510 + 4 * a1);
}

