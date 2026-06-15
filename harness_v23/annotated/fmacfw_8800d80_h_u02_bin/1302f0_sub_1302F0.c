// v23 annotated: sub_1302F0 @ 0x1302f0
// Original: 1302f0_sub_1302F0.c
// Primary struct: <unclustered>
//
// sub_1302F0 @ 0x1302f0, size 110 bytes
int __fastcall sub_1302F0(int a1)
{
  signed int v1; // r0
  int v2; // r3
  int result; // r0

  if ( a1 > 29 )
    v1 = (unsigned int)(((unsigned int)dword_13036C * (unsigned __int64)(unsigned int)(a1 - 30)) >> 32) >> 3;
  else
    v1 = ((int)((unsigned __int64)(dword_130360 * (__int64)(a1 - 40)) >> 32) >> 2) - ((a1 - 40) >> 31);
  if ( v1 >= 8 )
    v1 = 8;
  if ( v1 < -7 )
    v1 = -7;
  v2 = *((unsigned __int8 *)off_130364 + 4)
     + (char)(*(_BYTE *)(dword_130368 + v1 + 7) - *(_BYTE *)(dword_130368 + *((char *)off_130364 + 2) + 7));
  if ( v2 >= 31 )
    v2 = 31;
  if ( v2 < 1 )
    LOBYTE(v2) = 1;
  *((_BYTE *)off_130364 + 5) = v2;
  sub_1301B8(v1);
  result = sub_12E91C(9u, 4u);
  if ( result )
    return sub_130260();
  return result;
}

