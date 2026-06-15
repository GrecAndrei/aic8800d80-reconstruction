// sub_10FE24 @ 0x10fe24, size 46 bytes
BOOL __fastcall sub_10FE24(unsigned int a1)
{
  if ( *(_DWORD *)off_10FE54 <= a1 && a1 <= *(_DWORD *)off_10FE54 + *((_DWORD *)off_10FE54 + 1) )
    return 1;
  if ( a1 < *(_DWORD *)off_10FE58 )
    return 0;
  return a1 <= *(_DWORD *)off_10FE58 + *((_DWORD *)off_10FE58 + 1);
}

