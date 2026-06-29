// fwstruct annotate: 11324c_sub_11324C.c
// sub_11324C @ 0x11324c, size 164 bytes
int __fastcall sub_11324C(int a1, unsigned int a2)
{
  _BYTE *v2; // r4
  _BYTE *v3; // r5
  int v4; // r3
  _DWORD *v5; // r2
  int v6; // r0
  int v7; // r2

  v2 = off_1132F0;
  if ( *(_BYTE *)off_1132F0 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = off_1132F4;
  if ( *(_BYTE *)off_1132F4 )
  {
    sub_10DA7C(dword_113308, dword_113304, *(unsigned __int8 *)off_1132F4);
    return -3;
  }
  else
  {
    v4 = *(char *)off_1132F8;
    *(_BYTE *)off_1132F4 = 1;
    v5 = off_1132FC;
    if ( v4 )
    {
      *((_DWORD *)off_1132FC + 716) &= 0xE007FFFF;
      v5[512] |= 0x2000u;
    }
    else
    {
      *((_DWORD *)off_1132FC + 713) |= 1u;
    }
    v6 = sub_111F78(1, a1, a2);
    v7 = v6;
    if ( v6 )
    {
      sub_10DA7C(dword_11330C, dword_113304, v6);
      return -1;
    }
    else
    {
      *(_BYTE *)off_113300 = 1;
      if ( *v2 )
      {
        sub_111C10(nullptr, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v7;
}

