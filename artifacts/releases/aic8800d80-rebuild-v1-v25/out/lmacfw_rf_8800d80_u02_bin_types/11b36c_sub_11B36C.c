// sub_11B36C @ 0x11b36c, size 48 bytes
int sub_11B36C()
{
  void *v0; // r2
  int v1; // r0
  int result; // r0

  v0 = off_11B39C;
  if ( (*((uint8_t *)off_11B39C + 88) & 0x10) == 0 )
  {
    v1 = *((unsigned __int8 *)off_11B39C + 90);
    *((uint8_t *)off_11B39C + 88) |= 0x10u;
    if ( v1 )
      return sub_11AB18((int)v0 + 48, *((uint32_t *)off_11B3A0 + 4) + 30000);
    else
      return sub_11B2C8();
  }
  return result;
}

