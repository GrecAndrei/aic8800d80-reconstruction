// v23 annotated: log_ptr_in_range @ 0x10fe24
// Original: 10fe24_log_ptr_in_range.c
// Primary struct: <unclustered>
//
// log_ptr_in_range @ 0x10fe24, size 46 bytes
// Doc: log_ptr_in_range [util]: Check if a pointer falls within the log buffer range
// log_ptr_in_range [util]: Check if a pointer falls within the log buffer range
BOOL __fastcall log_ptr_in_range(unsigned int a1)
{
  if ( *(_DWORD *)off_10FE54 <= a1 && a1 <= *(_DWORD *)off_10FE54 + *((_DWORD *)off_10FE54 + 1) )
    return 1;
  if ( a1 < *(_DWORD *)off_10FE58 )
    return 0;
  return a1 <= *(_DWORD *)off_10FE58 + *((_DWORD *)off_10FE58 + 1);
}

