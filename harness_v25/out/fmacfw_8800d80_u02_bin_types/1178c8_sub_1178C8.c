// sub_1178C8 @ 0x1178c8, size 76 bytes
unsigned int sub_1178C8()
{
  int v0; // r4
  unsigned int result; // r0

  v0 = dword_117918 & *(uint32_t *)off_117914;
  if ( (*(uint32_t *)off_117914 & 0x10) != 0 )
  {
    if ( (*(uint32_t *)off_117914 & 0x1000) != 0 )
    {
      v0 |= 0x1000u;
      *((uint32_t *)off_117920 + 52) |= 4u;
    }
    sub_11C2F4();
  }
  result = v0 & 0xF00000;
  if ( (v0 & 0xF00000) != 0 )
    result = sub_11AC74((unsigned __int8)(11 - __clz(result)));
  *(uint32_t *)off_11791C = v0;
  return result;
}

