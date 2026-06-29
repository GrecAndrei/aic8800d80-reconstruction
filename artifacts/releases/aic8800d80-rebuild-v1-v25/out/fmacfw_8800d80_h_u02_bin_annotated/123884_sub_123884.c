// fwstruct annotate: 123884_sub_123884.c
// sub_123884 @ 0x123884, size 192 bytes
int __fastcall sub_123884(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  _DWORD *v5; // r5
  _DWORD *v6; // r3
  int v7; // r4
  BOOL v8; // r0
  int v9; // r3

  v4 = sub_12C7EC(5, a4, a3, 28);
  v5 = off_123944;
  *(_DWORD *)v4 = dword_123948;
  v6 = off_12394C;
  *(_DWORD *)(v4 + 4) = *v5;
  *(_DWORD *)(v4 + 8) = *v6;
  *(_BYTE *)(v4 + 26) = 4;
  *(_WORD *)(v4 + 24) = 32;
  v7 = v4;
  sub_1018D8((_DWORD *)(v4 + 12), (_DWORD *)(v4 + 16));
  *(_DWORD *)(v7 + 20) = dword_123950;
  if ( (*v5 & 0x20000) != 0 && sub_10199C() )
  {
    *(_DWORD *)(v7 + 20) |= 0x400u;
    if ( (*(_DWORD *)off_123944 & 0x20000) == 0 )
      goto LABEL_3;
  }
  else if ( (*(_DWORD *)off_123944 & 0x20000) == 0 )
  {
    goto LABEL_3;
  }
  if ( sub_1019AC() )
    *(_DWORD *)(v7 + 20) |= 0x4000u;
LABEL_3:
  if ( (*(_DWORD *)off_123944 & 0x2000) != 0 )
    *(_DWORD *)(v7 + 20) |= 0x1000u;
  if ( sub_10194C() )
    *(_DWORD *)(v7 + 20) |= 0x200u;
  if ( (*(_DWORD *)off_123944 & 0x8000) != 0 && sub_101950() )
    *(_DWORD *)(v7 + 20) |= 0x800000u;
  v8 = sub_101960();
  v9 = *(_DWORD *)(v7 + 20);
  if ( v8 )
    v9 |= 0x80000u;
  *(_DWORD *)(v7 + 20) = v9 | 0x600000;
  sub_12C84C(v7);
  return 0;
}

