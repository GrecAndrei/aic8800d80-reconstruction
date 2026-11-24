// sub_11C224 @ 0x11c224, size 44 bytes
int __fastcall sub_11C224(int a1, int a2)
{
  int v2; // r3

  v2 = *(_DWORD *)(a1 + 68);
  if ( v2 && (*(_WORD *)(v2 + 8) & 0x200) != 0 )
    return *((_DWORD *)off_11C250 + 43);
  if ( *(int *)(*(_DWORD *)(a1 + 44) + 60) >= 0 )
    return *(_DWORD *)(a2 + 580);
  return (*(unsigned __int8 *)(a2 + 309) << 9) | 0x8007;
}

