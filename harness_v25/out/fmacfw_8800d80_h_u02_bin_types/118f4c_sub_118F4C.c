// sub_118F4C @ 0x118f4c, size 36 bytes
int  sub_118F4C(int a1, int a2, int a3)
{
  if ( (*(uint32_t *)(dword_118F70 + 696 * a1 + 4) & 0x20) != 0 )
    return sub_118E08(a1, 7, a2, a3);
  else
    return sub_118C84(a1, a2, a3);
}

