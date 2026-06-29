// fwstruct annotate: 10fd8c_log_ptr_in_range.c
// log_ptr_in_range @ 0x10fd8c, size 46 bytes
// Doc: log_ptr_in_range [util]: Validate pointer is within log buffer range
// log_ptr_in_range [util]: Validate pointer is within log buffer range
BOOL __fastcall log_ptr_in_range(unsigned int a1)
{
  if ( *(_DWORD *)off_10FDBC <= a1 && a1 <= *(_DWORD *)off_10FDBC + *((_DWORD *)off_10FDBC + 1) )
    return 1;
  if ( a1 < *(_DWORD *)off_10FDC0 )
    return 0;
  return a1 <= *(_DWORD *)off_10FDC0 + *((_DWORD *)off_10FDC0 + 1);
}

