// sub_117D08 @ 0x117d08, size 76 bytes
unsigned int sub_117D08()
{
  int v0; // r4
  unsigned int result; // r0

  v0 = dword_117D58 & *(uint32_t *)off_117D54;
  if ( (*(uint32_t *)off_117D54 & 0x10) != 0 )
  {
    if ( (*(uint32_t *)off_117D54 & 0x1000) != 0 )
    {
      v0 |= 0x1000u;
      *((uint32_t *)off_117D60 + 52) |= 4u;
    }
    sub_11C734();
  }
  result = v0 & 0xF00000;
  if ( (v0 & 0xF00000) != 0 )
    result = sub_11B0B4((unsigned __int8)(11 - __clz(result)));
  *(uint32_t *)off_117D5C = v0;
  return result;
}

