// fwstruct annotate: 11454c_sub_11454C.c
// sub_11454C @ 0x11454c, size 68 bytes
int sub_11454C()
{
  int v0; // r2
  int v1; // r1
  _DWORD *v2; // r3

  if ( *(_DWORD *)off_114594 )
    v0 = 2048;
  else
    v0 = 4096;
  if ( *(_DWORD *)off_114594 )
    v1 = 1;
  else
    v1 = 2;
  if ( *(_BYTE *)(*(_DWORD *)off_114590 + 6) == 1 )
    *((_DWORD *)off_114598 + 83) &= ~v1;
  v2 = off_1145A0;
  *(_DWORD *)(*(_DWORD *)off_11459C + 8) = 0;
  v2[34] = v0;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}

