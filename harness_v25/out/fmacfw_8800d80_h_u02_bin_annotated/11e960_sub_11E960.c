// fwstruct annotate: 11e960_sub_11E960.c
// sub_11E960 @ 0x11e960, size 78 bytes
int __fastcall sub_11E960(int a1)
{
  char *v2; // r0
  void *v3; // r0
  char v4; // r2

  sub_11DE3C(a1, *(_DWORD *)(a1 + 28));
  v2 = (char *)off_11E9B0;
  if ( *((_DWORD *)off_11E9B0 + 14) )
  {
    *(_BYTE *)(a1 + 16) |= 1u;
    *(_DWORD *)(a1 + 4) = 0;
    v3 = v2 + 56;
    return sub_12D108(v3);
  }
  v3 = off_11E9B4;
  if ( *(_DWORD *)off_11E9B4 )
  {
    v4 = *(_BYTE *)(a1 + 16);
    *(_DWORD *)(a1 + 4) = 0;
    *(_BYTE *)(a1 + 16) = v4 | 1;
    return sub_12D108(v3);
  }
  return sub_11DF74(a1);
}

