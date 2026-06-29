// sub_112F58 @ 0x112f58, size 14 bytes
int  sub_112F58(unsigned int a1)
{
  if ( a1 > 7 )
    return 0;
  else
    return *(uint32_t *)(dword_112F68 + 4 * a1);
}

