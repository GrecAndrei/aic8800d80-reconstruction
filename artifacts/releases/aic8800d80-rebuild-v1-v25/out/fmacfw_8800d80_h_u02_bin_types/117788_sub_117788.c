// sub_117788 @ 0x117788, size 76 bytes
unsigned int sub_117788()
{
  int v0; // r4
  unsigned int result; // r0

  v0 = dword_1177D8 & *(uint32_t *)off_1177D4;
  if ( (*(uint32_t *)off_1177D4 & 0x10) != 0 )
  {
    if ( (*(uint32_t *)off_1177D4 & 0x1000) != 0 )
    {
      v0 |= 0x1000u;
      *((uint32_t *)off_1177E0 + 52) |= 4u;
    }
    sub_11C1B4();
  }
  result = v0 & 0xF00000;
  if ( (v0 & 0xF00000) != 0 )
    result = sub_11AB34((unsigned __int8)(11 - __clz(result)));
  *(uint32_t *)off_1177DC = v0;
  return result;
}

