// sub_126F10 @ 0x126f10, size 110 bytes
int __fastcall sub_126F10(int a1)
{
  signed int v1; // r0
  int v2; // r3
  int result; // r0

  if ( a1 > 29 )
    v1 = (unsigned int)(((unsigned int)dword_126F8C * (unsigned __int64)(unsigned int)(a1 - 30)) >> 32) >> 3;
  else
    v1 = ((int)((unsigned __int64)(dword_126F80 * (__int64)(a1 - 40)) >> 32) >> 2) - ((a1 - 40) >> 31);
  if ( v1 >= 8 )
    v1 = 8;
  if ( v1 < -7 )
    v1 = -7;
  v2 = *((unsigned __int8 *)off_126F84 + 4)
     + (char)(*(_BYTE *)(dword_126F88 + v1 + 7) - *(_BYTE *)(dword_126F88 + *((char *)off_126F84 + 2) + 7));
  if ( v2 >= 31 )
    v2 = 31;
  if ( v2 < 1 )
    LOBYTE(v2) = 1;
  *((_BYTE *)off_126F84 + 5) = v2;
  sub_126DD8(v1);
  result = sub_11F4D8(9u, 4u);
  if ( result )
    return sub_126E80();
  return result;
}

