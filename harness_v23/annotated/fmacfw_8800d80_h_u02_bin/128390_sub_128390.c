// v23 annotated: sub_128390 @ 0x128390
// Original: 128390_sub_128390.c
// Primary struct: <unclustered>
//
// sub_128390 @ 0x128390, size 74 bytes
BOOL __fastcall sub_128390(int a1)
{
  int v1; // r3
  unsigned int v2; // r1

  v1 = *((_DWORD *)off_1283DC + 10);
  if ( !v1 )
    return 0;
  v2 = *(unsigned __int8 *)(v1 + 24);
  if ( v2 <= 2 )
    return *(_DWORD *)(a1 + 72) == v1;
  if ( *(_DWORD *)(a1 + 72) && !*(_BYTE *)(a1 + 1224) && v2 == 4 )
    return sub_128350(a1);
  return *(unsigned __int8 *)(v1 + 26) == *(unsigned __int8 *)(a1 + 107);
}

