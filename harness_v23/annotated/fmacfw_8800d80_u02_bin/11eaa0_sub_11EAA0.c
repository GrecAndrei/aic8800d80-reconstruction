// v23 annotated: sub_11EAA0 @ 0x11eaa0
// Original: 11eaa0_sub_11EAA0.c
// Primary struct: <unclustered>
//
// sub_11EAA0 @ 0x11eaa0, size 78 bytes
int __fastcall sub_11EAA0(int a1)
{
  char *v2; // r0
  void *v3; // r0
  char v4; // r2

  sub_11DF7C(a1, *(_DWORD *)(a1 + 28));
  v2 = (char *)off_11EAF0;
  if ( *((_DWORD *)off_11EAF0 + 14) )
  {
    *(_BYTE *)(a1 + 16) |= 1u;
    *(_DWORD *)(a1 + 4) = 0;
    v3 = v2 + 56;
    return sub_12D248(v3);
  }
  v3 = off_11EAF4;
  if ( *(_DWORD *)off_11EAF4 )
  {
    v4 = *(_BYTE *)(a1 + 16);
    *(_DWORD *)(a1 + 4) = 0;
    *(_BYTE *)(a1 + 16) = v4 | 1;
    return sub_12D248(v3);
  }
  return sub_11E0B4(a1);
}

