// sub_10FF34 @ 0x10ff34, size 46 bytes
BOOL __fastcall sub_10FF34(unsigned int a1)
{
  if ( *(_DWORD *)off_10FF64 <= a1 && a1 <= *(_DWORD *)off_10FF64 + *((_DWORD *)off_10FF64 + 1) )
    return 1;
  if ( a1 < *(_DWORD *)off_10FF68 )
    return 0;
  return a1 <= *(_DWORD *)off_10FF68 + *((_DWORD *)off_10FF68 + 1);
}

