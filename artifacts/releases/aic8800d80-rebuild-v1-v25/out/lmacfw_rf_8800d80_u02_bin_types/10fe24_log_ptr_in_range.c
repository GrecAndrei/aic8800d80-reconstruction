// log_ptr_in_range @ 0x10fe24, size 46 bytes
// Doc: log_ptr_in_range [util]: Check if a pointer falls within the log buffer range
// log_ptr_in_range [util]: Check if a pointer falls within the log buffer range
BOOL  log_ptr_in_range(unsigned int a1)
{
  if ( *(uint32_t *)off_10FE54 <= a1 && a1 <= *(uint32_t *)off_10FE54 + *((uint32_t *)off_10FE54 + 1) )
    return 1;
  if ( a1 < *(uint32_t *)off_10FE58 )
    return 0;
  return a1 <= *(uint32_t *)off_10FE58 + *((uint32_t *)off_10FE58 + 1);
}

