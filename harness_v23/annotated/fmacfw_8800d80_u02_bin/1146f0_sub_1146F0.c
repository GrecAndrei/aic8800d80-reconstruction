// v23 annotated: sub_1146F0 @ 0x1146f0
// Original: 1146f0_sub_1146F0.c
// Primary struct: rf_state (cluster 8, 4 funcs)
// Fields: flags=0x0, sub_flag0=0x6, sub_flag1=0x9, sub_flag2=0xb, value=0xc, cfg=0x58
//
// sub_1146F0 @ 0x1146f0, size 68 bytes
int sub_1146F0()
{
  int v0; // r2
  int v1; // r1
  _DWORD *v2; // r3

  if ( *(_DWORD *)off_114738 )
    v0 = 2048;
  else
    v0 = 4096;
  if ( *(_DWORD *)off_114738 )
    v1 = 1;
  else
    v1 = 2;
  if ( *(_BYTE *)(*(_DWORD *)off_114734 + 6) == 1 )
    *((_DWORD *)off_11473C + 83) &= ~v1;
  v2 = off_114744;
  *(_DWORD *)(*(_DWORD *)off_114740 + 8) = 0;
  v2[34] = v0;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}

