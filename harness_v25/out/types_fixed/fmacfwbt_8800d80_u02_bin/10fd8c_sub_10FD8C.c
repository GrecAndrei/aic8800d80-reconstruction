// sub_10FD8C @ 0x10fd8c, size 46 bytes
BOOL __fastcall sub_10FD8C(unsigned int a1)
{
  if ( *(_DWORD *)off_10FDBC <= a1 && a1 <= *(_DWORD *)off_10FDBC + *((_DWORD *)off_10FDBC + 1) )
    return 1;
  if ( a1 < *(_DWORD *)off_10FDC0 )
    return 0;
  return a1 <= *(_DWORD *)off_10FDC0 + *((_DWORD *)off_10FDC0 + 1);
}

