// sub_1283E0 @ 0x1283e0, size 34 bytes
BOOL __fastcall sub_1283E0(int a1)
{
  BOOL result; // r0

  result = sub_128390(a1);
  if ( result )
    return !*((_DWORD *)off_128404 + 11) || *(unsigned __int8 *)(*((_DWORD *)off_128404 + 10) + 16) == 6;
  return result;
}

