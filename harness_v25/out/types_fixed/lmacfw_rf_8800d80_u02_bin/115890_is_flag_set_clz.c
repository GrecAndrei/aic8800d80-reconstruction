// is_flag_set_clz @ 0x115890, size 14 bytes
// Doc: is_flag_set_clz [util]: Check if flag byte is set using clz, returns 0/1
// is_flag_set_clz [util]: Check if flag byte is set using clz, returns 0/1
BOOL is_flag_set_clz()
{
  return *((unsigned __int8 *)off_1158A0 + 142) == 0;
}

