// sub_1178B4 @ 0x1178b4, size 38 bytes
int sub_1178B4()
{
  unsigned int v0; // r4
  int result; // r0

  v0 = *(uint32_t *)off_1178DC & 0xF00000;
  if ( v0 )
  {
    result = sub_11AB34((unsigned __int8)(11 - __clz(v0)));
    *(uint32_t *)off_1178E0 = v0;
  }
  else
  {
    *(uint32_t *)off_1178E0 = 0;
  }
  return result;
}

