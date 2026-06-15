// is_flag_set_n645c @ 0x12645c, size 12 bytes
// Doc: is_flag_set_n645c [util]: Check flag byte at 0x180834 returns 0 or 1
// is_flag_set_n645c [util]: Check flag byte at 0x180834 returns 0 or 1
int is_flag_set_n645c()
{
  int result; // r0

  result = *(unsigned __int8 *)off_126468;
  if ( *(_BYTE *)off_126468 )
    return 1;
  return result;
}

