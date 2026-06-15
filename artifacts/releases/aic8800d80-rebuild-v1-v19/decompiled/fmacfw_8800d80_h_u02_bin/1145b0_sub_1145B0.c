// sub_1145B0 @ 0x1145b0, size 68 bytes
int sub_1145B0()
{
  int v0; // r2
  int v1; // r1
  _DWORD *v2; // r3

  if ( *(_DWORD *)off_1145F8 )
    v0 = 2048;
  else
    v0 = 4096;
  if ( *(_DWORD *)off_1145F8 )
    v1 = 1;
  else
    v1 = 2;
  if ( *(_BYTE *)(*(_DWORD *)off_1145F4 + 6) == 1 )
    *((_DWORD *)off_1145FC + 83) &= ~v1;
  v2 = off_114604;
  *(_DWORD *)(*(_DWORD *)off_114600 + 8) = 0;
  v2[34] = v0;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}

