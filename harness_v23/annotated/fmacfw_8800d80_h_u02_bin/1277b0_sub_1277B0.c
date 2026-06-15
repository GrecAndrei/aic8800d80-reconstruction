// v23 annotated: sub_1277B0 @ 0x1277b0
// Original: 1277b0_sub_1277B0.c
// Primary struct: <unclustered>
//
// sub_1277B0 @ 0x1277b0, size 94 bytes
int __fastcall sub_1277B0(int a1)
{
  int result; // r0
  char v3; // r3
  int v4; // r3

  result = sub_124BFC(a1 + 24, *(_DWORD *)(a1 + 36) + *(_DWORD *)(a1 + 88));
  v3 = *(_BYTE *)(a1 + 85);
  *(_BYTE *)(a1 + 85) = v3 & 0xDF;
  if ( (v3 & 1) != 0 )
  {
    v4 = *((_DWORD *)off_127810 + 9);
    if ( v4 && *(_DWORD *)(v4 + 12) == a1 + 76 )
    {
      sub_1266A0();
      sub_126444(a1, *(_DWORD *)(a1 + 36), 0);
      return sub_1266E4(a1, *((_DWORD *)off_127814 + 4), 0);
    }
    else
    {
      return sub_126444(a1, *(_DWORD *)(a1 + 36), 0);
    }
  }
  return result;
}

