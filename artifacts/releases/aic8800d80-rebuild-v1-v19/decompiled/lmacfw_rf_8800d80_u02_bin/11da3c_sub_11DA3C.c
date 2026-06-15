// sub_11DA3C @ 0x11da3c, size 26 bytes
int __fastcall sub_11DA3C(int a1, _BYTE *a2, _BYTE *a3)
{
  int v3; // r3
  int result; // r0

  v3 = *(char *)(a1 + 97);
  if ( v3 == 127 )
    result = *(_DWORD *)off_11DA58;
  else
    result = (unsigned __int8)v3;
  if ( v3 == 127 )
    result = (unsigned __int8)result;
  if ( a2 )
    *a2 = v3;
  if ( a3 )
    *a3 = result;
  return result;
}

