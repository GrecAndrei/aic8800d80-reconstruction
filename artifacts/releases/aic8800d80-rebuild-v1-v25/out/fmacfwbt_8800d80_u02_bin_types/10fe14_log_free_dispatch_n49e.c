// log_free_dispatch_n49e @ 0x10fe14, size 62 bytes
// Doc: log_free_dispatch_n49e [util]: Dispatches log free events for variant 49e
// log_free_dispatch_n49e [util]: Dispatches log free events for variant 49e
uint32_t * log_free_dispatch_n49e(char a1)
{
  uint32_t *v2; // r4

  if ( **(uint8_t **)off_10FE54 == 1 )
    v2 = (uint32_t *)log_free_dispatch_n478();
  else
    v2 = log_pool_alloc2(dword_10FE58, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( log_ptr_in_range((unsigned int)v2) )
  {
    *((uint8_t *)v2 - 1) = a1;
    return v2;
  }
  log_printf(dword_10FE5C, v2);
  return v2;
}

