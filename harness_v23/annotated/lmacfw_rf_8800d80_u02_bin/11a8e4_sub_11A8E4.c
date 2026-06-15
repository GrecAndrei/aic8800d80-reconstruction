// v23 annotated: sub_11A8E4 @ 0x11a8e4
// Original: 11a8e4_sub_11A8E4.c
// Primary struct: <unclustered>
//
// sub_11A8E4 @ 0x11a8e4, size 192 bytes
int __fastcall sub_11A8E4(unsigned __int8 *a1)
{
  int v1; // r1
  int v3; // r3
  unsigned int *v4; // r0
  int v5; // r1
  unsigned int *v6; // r0
  unsigned int v7; // r1
  unsigned int *v8; // r0

  v1 = *a1;
  v3 = (unsigned __int8)*(_DWORD *)off_11A9A4;
  if ( *a1 )
  {
    v4 = (unsigned int *)off_11A9A8;
    *(_DWORD *)off_11A9A8 = *(_DWORD *)off_11A9A8 & 0xFFFFFF00 | v1;
    *v4 = *v4 & 0xFF0000FF | ((v3 * v1) << 8);
  }
  v5 = a1[1];
  if ( a1[1] )
  {
    v6 = (unsigned int *)off_11A9AC;
    *(_DWORD *)off_11A9AC = *(_DWORD *)off_11A9AC & 0xFFFFFF00 | v5;
    *v6 = *v6 & 0xFF0000FF | ((v3 * v5) << 8);
  }
  v7 = a1[2];
  if ( a1[2] )
  {
    v8 = (unsigned int *)off_11A9B0;
    *(_DWORD *)off_11A9B0 = *(_DWORD *)off_11A9B0 & 0xFFFFFF00 | v7;
    *v8 = *v8 & 0xFF0000FF | ((v3 * v7) << 8);
  }
  if ( a1[3] )
  {
    v7 = (unsigned int)off_11A9B4;
    *(_DWORD *)off_11A9B4 = *(_DWORD *)off_11A9B4 & 0xFFFFFF00 | a1[3];
  }
  if ( a1[4] )
  {
    v7 = (unsigned int)off_11A9B4;
    *(_DWORD *)off_11A9B4 = *(_DWORD *)off_11A9B4 & 0xFFFF00FF | (a1[4] << 8);
  }
  if ( a1[5] )
  {
    v7 = (unsigned int)off_11A9B4;
    *(_DWORD *)off_11A9B4 = *(_DWORD *)off_11A9B4 & 0xFF00FFFF | (a1[5] << 16);
  }
  sub_11F504(dword_11A9B8, v7);
  return sub_11F594(a1, 6, 1, 0);
}

