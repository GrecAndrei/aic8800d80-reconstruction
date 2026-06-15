// v23 annotated: sub_11C364 @ 0x11c364
// Original: 11c364_sub_11C364.c
// Primary struct: <unclustered>
//
// sub_11C364 @ 0x11c364, size 44 bytes
int __fastcall sub_11C364(int a1, int a2)
{
  int v2; // r3

  v2 = *(_DWORD *)(a1 + 68);
  if ( v2 && (*(_WORD *)(v2 + 8) & 0x200) != 0 )
    return *((_DWORD *)off_11C390 + 43);
  if ( *(int *)(*(_DWORD *)(a1 + 44) + 60) >= 0 )
    return *(_DWORD *)(a2 + 580);
  return (*(unsigned __int8 *)(a2 + 309) << 9) | 0x8007;
}

