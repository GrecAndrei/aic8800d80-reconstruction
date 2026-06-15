// v23 annotated: sub_1138F4 @ 0x1138f4
// Original: 1138f4_sub_1138F4.c
// Primary struct: group_14 (cluster 14)
//
// sub_1138F4 @ 0x1138f4, size 68 bytes
int sub_1138F4()
{
  int v0; // r2
  int v1; // r1
  _DWORD *v2; // r3

  if ( *(_DWORD *)off_11393C )
    v0 = 2048;
  else
    v0 = 4096;
  if ( *(_DWORD *)off_11393C )
    v1 = 1;
  else
    v1 = 2;
  if ( *(_BYTE *)(*(_DWORD *)off_113938 + 6) == 1 )
    *((_DWORD *)off_113940 + 83) &= ~v1;
  v2 = off_113948;
  *(_DWORD *)(*(_DWORD *)off_113944 + 8) = 0;
  v2[34] = v0;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}

