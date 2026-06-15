// v23 annotated: sub_1239C4 @ 0x1239c4
// Original: 1239c4_sub_1239C4.c
// Primary struct: <unclustered>
//
// sub_1239C4 @ 0x1239c4, size 192 bytes
int __fastcall sub_1239C4(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  _DWORD *v5; // r5
  _DWORD *v6; // r3
  int v7; // r4
  BOOL v8; // r0
  int v9; // r3

  v4 = sub_12C92C(5, a4, a3, 28);
  v5 = off_123A84;
  *(_DWORD *)v4 = dword_123A88;
  v6 = off_123A8C;
  *(_DWORD *)(v4 + 4) = *v5;
  *(_DWORD *)(v4 + 8) = *v6;
  *(_BYTE *)(v4 + 26) = 4;
  *(_WORD *)(v4 + 24) = 32;
  v7 = v4;
  sub_101984((_DWORD *)(v4 + 12), (_DWORD *)(v4 + 16));
  *(_DWORD *)(v7 + 20) = dword_123A90;
  if ( (*v5 & 0x20000) != 0 && sub_101A48() )
  {
    *(_DWORD *)(v7 + 20) |= 0x400u;
    if ( (*(_DWORD *)off_123A84 & 0x20000) == 0 )
      goto LABEL_3;
  }
  else if ( (*(_DWORD *)off_123A84 & 0x20000) == 0 )
  {
    goto LABEL_3;
  }
  if ( sub_101A58() )
    *(_DWORD *)(v7 + 20) |= 0x4000u;
LABEL_3:
  if ( (*(_DWORD *)off_123A84 & 0x2000) != 0 )
    *(_DWORD *)(v7 + 20) |= 0x1000u;
  if ( sub_1019F8() )
    *(_DWORD *)(v7 + 20) |= 0x200u;
  if ( (*(_DWORD *)off_123A84 & 0x8000) != 0 && sub_1019FC() )
    *(_DWORD *)(v7 + 20) |= 0x800000u;
  v8 = sub_101A0C();
  v9 = *(_DWORD *)(v7 + 20);
  if ( v8 )
    v9 |= 0x80000u;
  *(_DWORD *)(v7 + 20) = v9 | 0x600000;
  sub_12C98C(v7);
  return 0;
}

