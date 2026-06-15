// v23 annotated: log_free_dispatch_n49e @ 0x10fe14
// Original: 10fe14_log_free_dispatch_n49e.c
// Primary struct: <unclustered>
//
// log_free_dispatch_n49e @ 0x10fe14, size 62 bytes
// Doc: log_free_dispatch_n49e [util]: Dispatches log free events for variant 49e
// log_free_dispatch_n49e [util]: Dispatches log free events for variant 49e
_DWORD *__fastcall log_free_dispatch_n49e(char a1)
{
  _DWORD *v2; // r4

  if ( **(_BYTE **)off_10FE54 == 1 )
    v2 = (_DWORD *)log_free_dispatch_n478();
  else
    v2 = log_pool_alloc2(dword_10FE58, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( log_ptr_in_range((unsigned int)v2) )
  {
    *((_BYTE *)v2 - 1) = a1;
    return v2;
  }
  log_printf(dword_10FE5C, v2);
  return v2;
}

